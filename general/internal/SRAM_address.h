#pragma once

/**
 * SRAM_address.h - SRAM地址, 用于表示SRAM地址
 */

#include "address_struct.h"

namespace general::memory {
    using namespace distribution;

/**
 * SRAM_address - SRAM地址结构体
*/
struct SRAM_address : address<SRAM_address, block::sram> {
    using address<SRAM_address, block::sram>::address;
    using address<SRAM_address, block::sram>::operator=;
    using address<SRAM_address, block::sram>::operator+;
    using address<SRAM_address, block::sram>::operator+=;

    constexpr bool check_address() const {
        if (!block_sram_snippet.contains(address_value))
            return false;

        if (SRAM_snippet::reserved_area1.contains(address_value) ||
            SRAM_snippet::reserved_area2.contains(address_value) ||
            SRAM_snippet::reserved_area3.contains(address_value) )
            return false;

        return true;
    }
    constexpr bool update() {
        return block_sram_snippet.contains(address_value);
    }
};
}
