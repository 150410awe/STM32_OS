#pragma once

#include "memory.h"

namespace kernel::call {
    using namespace memory;
    inline void* malloc(size_t size) {
        if (size == 0)
            return nullptr;
        if (use_memory.full())
            return nullptr;
        
            // 注意 it->size == size 因为是地址是闭区间. 所可以直接从空闲队列中删除
            // it->size > size 说明 it->size - size > 0, 还有空间, 因为是闭区间, 所以要 + 1.
        for (auto it = empty_memory_queue.begin(); it != empty_memory_queue.end(); ++it) 
            if (it->size() >= size) {
                void* result = reinterpret_cast<void*>(it->address_interval.start);
                
                use_memory.emplace(it->address_interval.start , size);
                if (it->size() == size) 
                    // 完全匹配，从空闲队列中删除
                    empty_memory_queue.erase(it.get_pos());
                else 
                    // 分割块，更新剩余部分, 让address_interval.start向高地址方向, 
                    it->address_interval.start += size + 1;

                return result;
            }
        
        return nullptr;
    }
    inline void free(void* free_address) {
        if (free_address == nullptr)
            return;
        
        auto it = use_memory.find(reinterpret_cast<max_int_t>(free_address));
        if (it == use_memory.end())
            return;
        
        size_t freed_size = it->second;
        use_memory.erase(it->first);
        kernel::memory::memory new_block{{reinterpret_cast<max_int_t>(free_address), static_cast<max_int_t>(reinterpret_cast<max_int_t>(free_address) + freed_size)}};

        // 合并空闲块
        // 注意 因为是地址是闭区间. it->address_interval.start == new_block.address_interval.end + 1 时, 只用修改 end, size 会自动更新, 因为size是函数
        // it->address_interval.end == new_block.address_interval.start - 1 时, 只用修改 start, 不修改 end. 本来就不用修改end
        for (auto it = empty_memory_queue.begin(); it != empty_memory_queue.end(); ++it) 
            if (it->address_interval.start == new_block.address_interval.end + 1) {
                new_block.address_interval.end += it->size() + 1;
                empty_memory_queue.erase(it.get_pos());
                break;
            }
            else if (it->address_interval.end == new_block.address_interval.start - 1) {
                new_block.address_interval.start = it->address_interval.start;
                empty_memory_queue.erase(it.get_pos());
                break;
            }
        empty_memory_queue.push_back(new_block);
    }
}