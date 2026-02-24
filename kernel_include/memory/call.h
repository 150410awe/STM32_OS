#pragma once

#include "memory.h"

namespace kernel::call {
    using namespace memory;
    inline void* malloc(size_t size) {
        if (size == 0)
            return nullptr;
        
        for (auto it = empty_memory_queue.begin(); it != empty_memory_queue.end(); ++it) 
            if (it->size >= size) {
                void* result = reinterpret_cast<void*>(it->base_address.address_value);
                size_t allocated_size = size;
                
                use_memory.emplace(std::pair{ it->base_address.address_value , allocated_size });
                if (it->size == size) 
                    // 完全匹配，从空闲队列中删除
                    empty_memory_queue.erase(it);
                else {
                    // 分割块，更新剩余部分, 让base_address向高地址方向
                    it->base_address.offset(it->base_address.address_value + size);
                    it->size -= size;
                }

                return result;
            }
        
        return nullptr;
    }
    inline void free(void* free_address) {
        if (free_address == nullptr)
            return;
        
        auto it = use_memory.find(reinterpret_cast<u32>(free_address));
        if (it == use_memory.end())
            return;
        
        size_t freed_size = it->second;
        use_memory.erase(it);

        empty_memory_queue.push_back(kernel::memory::memory{SRAM_address{reinterpret_cast<u32>(free_address)}, freed_size});
    }
}