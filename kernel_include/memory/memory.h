#pragma once

#include "../../general/type.h"
#include "../../general/internal/memory_distribution.h"
#include <unordered_map>
#include <list>



namespace kernel::memory {
    constexpr size_t SRAM_size = 196608;
    constexpr size_t use_max_size = 384;
    /**
     * memory - 内存块
     * @param address_interval 内存地址区间
     * @note 内存地址区间是闭区间, size 一般自己会计算
     */
    struct memory {
        int_interval address_interval;
        memory(int_interval address_interval) : address_interval(address_interval) { }
        memory() = default;
        size_t size() const { return address_interval.end - address_interval.start; }
    };
    // general::memory::block_SRAM_snippet 只是临时. 因为内核内存不算
    inline static general::array_list<memory, use_max_size> empty_memory_queue = []() {
        general::array_list<memory, use_max_size> result;
        result.push_back(memory{general::memory::block_SRAM_snippet});
        return result;
    }();
    
    inline static general::array_unordered_map<size_t, use_max_size> use_memory;    // size_t 内存大小, memory 内存块大小
}

