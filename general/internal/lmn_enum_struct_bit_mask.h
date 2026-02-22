#pragma once

#include "foundation_type.h"

/**
 * lmn_enum_struct_prototype - 枚举结构体位掩码（Enum Struct Bit Mask）
 * @note 用于表示枚举类型的位掩码，支持按位操作
 * @tparam struct_t - 枚举结构体类型（Enum Struct Type）
 * @tparam enum_t - 枚举类型（Enum Type）
 */
namespace general {
template <typename struct_t, typename enum_t> struct lmn_enum_struct_bit_mask {
    int64_t data;
    constexpr lmn_enum_struct_bit_mask() : data { 0 } {}
    constexpr lmn_enum_struct_bit_mask(enum_t value) : data { static_cast<int64_t>(value) } {}
    constexpr lmn_enum_struct_bit_mask(const lmn_enum_struct_bit_mask<struct_t, enum_t>& data) : data { data.data } {}
    constexpr lmn_enum_struct_bit_mask(lmn_enum_struct_bit_mask<struct_t, enum_t>&& data) : data { data.data } {}
    constexpr lmn_enum_struct_bit_mask& operator=(const lmn_enum_struct_bit_mask<struct_t, enum_t>& data) { this->data = data.data; return *this; }
    constexpr lmn_enum_struct_bit_mask& operator=(lmn_enum_struct_bit_mask<struct_t, enum_t>&& data) { this->data = data.data; return *this; }
    constexpr struct_t operator|= (enum_t a) { return this->data |= static_cast<int64_t>(a); }
    constexpr struct_t operator|(enum_t a) const { return struct_t { this->data | static_cast<int64_t>(a) }; }
    constexpr struct_t operator&= (enum_t a) { return this->data &= static_cast<int64_t>(a); }
    constexpr struct_t operator&(enum_t a) const { return struct_t { this->data & static_cast<int64_t>(a) }; }
    constexpr struct_t operator^(enum_t a) const { return struct_t { this->data ^ static_cast<int64_t>(a) }; }
    constexpr struct_t operator~(void) const { return struct_t { ~this->data }; }
    constexpr struct_t operator=(enum_t a) { return this->data = static_cast<int64_t>(a); }
    constexpr bool operator!(void) const { return this->data == 0; }
    constexpr bool operator==(lmn_enum_struct_bit_mask a) const { return this->data == a.data; }
    constexpr bool operator!=(lmn_enum_struct_bit_mask a) const { return !(*this == a); }
    constexpr bool operator>(lmn_enum_struct_bit_mask a) const { return this->data > a.data; }
    constexpr bool operator<(lmn_enum_struct_bit_mask a) const { return this->data < a.data; }
    constexpr bool operator>=(lmn_enum_struct_bit_mask a) const { return this->data >= a.data; }
    constexpr bool operator<=(lmn_enum_struct_bit_mask a) const { return this->data <= a.data; }
};
}