#pragma once

/**
 * code_address.h - 代码地址, 用于表示代码地址
 */

#include "address_struct.h"

namespace general::memory {
    using namespace distribution;

struct code_address : address<code_address, block::code> {
    using address<code_address, block::code>::address;
    using address<code_address, block::code>::operator=;
    using address<code_address, block::code>::operator+;
    using address<code_address, block::code>::operator+=;

    constexpr bool check_address() const {
        if (!block_code_snippet.contains(address_value))
            return false;

        if (code_snippet::reserved_area1.contains(address_value) ||
            code_snippet::reserved_area2.contains(address_value) ||
            code_snippet::reserved_area3.contains(address_value) ||
            code_snippet::reserved_area4.contains(address_value) )
            return false;
        return true;
    }
    constexpr bool update() {
        return block_code_snippet.contains(address_value);
    }
};
}