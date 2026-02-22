#pragma once

/**
 * reserved_address.h - 保留地址, 用于表示保留地址
 */

#include "address_struct.h"

namespace general::memory {
    using namespace distribution;
    

struct reserved_address : address<reserved_address, block::reserved_area> {
    using address<reserved_address, block::reserved_area>::address;
    using address<reserved_address, block::reserved_area>::operator=;
    using address<reserved_address, block::reserved_area>::operator+;
    using address<reserved_address, block::reserved_area>::operator+=;
    
    constexpr bool check_address() const {
        if (!block_reserved_snippet.contains(address_value))
            return false;

        if (reserved_snippet::reserved_area1.contains(address_value) ||
            reserved_snippet::reserved_area2.contains(address_value) )
            return false;
        return true;
    }
    constexpr bool update() {
        return block_reserved_snippet.contains(address_value);
    }
};
}
