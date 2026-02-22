#pragma once

/**
 * null_address.h - 空地址, 用于表示无效地址
 */

#include "address_struct.h"

namespace general::memory {
    using namespace distribution;
    
struct null_address : address<null_address, block::null> {
    using address<null_address, block::null>::address;
    // NULL 不可以修改
    constexpr null_address& operator=(max_int_t set_address) = delete;
    constexpr null_address& operator+=(const max_int_t set_address) = delete;
    constexpr null_address operator+(const max_int_t set_address) const = delete;
    constexpr null_address operator+(const null_address set_address) const = delete;

    // 我去你妈, 不可以乱改
    constexpr bool check_address() const {
        if (address_value != null_address_value)
            return false;
        
        return true;

    }
    constexpr bool update() {
        return address_value == null_address_value;
    }
};
}