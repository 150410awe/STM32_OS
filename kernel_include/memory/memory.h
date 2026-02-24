#pragma once

#include "../../general/type.h"
#include "../../general/internal/memory_distribution.h"
#include <unordered_map>
#include <list>



namespace kernel::memory {
    constexpr size_t SRAM_size = 196608;
    struct memory {
        SRAM_address base_address;
        size_t size;
        memory(SRAM_address base_address, size_t size) : base_address(base_address), size(size) { }
        memory() = default;
    };
    // general::memory::block_SRAM_snippet.start只是临时. 因为内核内存不算
    inline static std::list<memory> empty_memory_queue{memory{static_cast<SRAM_address>(general::memory::block_SRAM_snippet.start), SRAM_size}};
    
    inline static std::unordered_map<u32, size_t> use_memory;
}

