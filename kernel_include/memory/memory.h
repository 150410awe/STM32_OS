#pragma once

#include "../../general/type.h"
#include "../../general/internal/memory_distribution.h"



namespace kernel::memory {
    constexpr size_t SRAM_size = 196608;
    constexpr size_t use_max_size = 384;
    constexpr size_t stack_size = 2048;
    constexpr size_t kernel_memory_size = 15000;
    using namespace general::memory::distribution;
    constexpr uint_interval kernel_memory_interval{ block_SRAM_snippet.start, block_SRAM_snippet.start + kernel_memory_size + stack_size }; // 注意这里 kernel_memory_size 是按大来算的, stack_size表面是2048, 实际比2048大, 因为 kernel_memory_size 比真实的 内核大小 大
    constexpr uint_interval user_memory_interval{ kernel_memory_interval.end + 1, block_SRAM_snippet.end };
    /**
     * memory - 内存块
     * @param address_interval 内存地址区间
     * @note 内存地址区间是闭区间, size 一般自己会计算
     */
    struct memory {
        uint_interval address_interval;
        memory(uint_interval address_interval) : address_interval{ address_interval } { }
        memory() = default;
        size_t size() const { return address_interval.end - address_interval.start; }
    };
    // general::memory::block_SRAM_snippet 只是临时. 因为内核内存不算
    inline static general::array_list<memory, use_max_size> empty_memory_queue{ []() {
        general::array_list<memory, use_max_size> result;
        result.push_back(memory{ user_memory_interval });
        return result;
    }() };
    
    inline static general::array_unordered_map<size_t, use_max_size> use_memory;    // size_t 内存大小, memory 内存块大小
}

