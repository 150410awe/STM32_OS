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
/**
 * basic_bit_mask_operation - 基础位掩码操作（Basic Bit Mask Operation）
 * @note 定义枚举类型的基础按位操作，包括按位或、按位与、按位异或、按位取反
 * @param enum_t - 枚举类型（Enum Type）, 我是懒写那些按位操作. 但是他还算清楚, 简单.
 */
#define basic_bit_mask_operation(enum_t) \
constexpr enum_t operator|(enum_t lhs, enum_t rhs) { \
        return static_cast<enum_t>(static_cast<max_int_t>(lhs) | static_cast<max_int_t>(rhs)); \
    } \
    constexpr enum_t operator&(enum_t lhs, enum_t rhs) { \
        return static_cast<enum_t>(static_cast<max_int_t>(lhs) & static_cast<max_int_t>(rhs)); \
    } \
    constexpr enum_t operator^(enum_t lhs, enum_t rhs) { \
        return static_cast<enum_t>(static_cast<max_int_t>(lhs) ^ static_cast<max_int_t>(rhs)); \
    } \
    constexpr enum_t operator~(enum_t value) { \
        return static_cast<enum_t>(~static_cast<max_int_t>(value)); \
    } \
    constexpr bool operator==(enum_t lhs, enum_t rhs) { \
        return static_cast<max_int_t>(lhs) == static_cast<max_int_t>(rhs); \
    } \
    constexpr bool operator!=(enum_t lhs, enum_t rhs) { \
        return !(lhs == rhs); \
    } \
    constexpr bool operator>(enum_t lhs, enum_t rhs) { \
        return static_cast<max_int_t>(lhs) > static_cast<max_int_t>(rhs); \
    } \
    constexpr bool operator<(enum_t lhs, enum_t rhs) { \
        return static_cast<max_int_t>(lhs) < static_cast<max_int_t>(rhs); \
    } \
    constexpr bool operator>=(enum_t lhs, enum_t rhs) { \
        return static_cast<max_int_t>(lhs) >= static_cast<max_int_t>(rhs); \
    } \
    constexpr bool operator<=(enum_t lhs, enum_t rhs) { \
        return static_cast<max_int_t>(lhs) <= static_cast<max_int_t>(rhs); \
    } \
    constexpr max_int_t operator<<(enum_t lhs, int rhs) { \
        return static_cast<max_int_t>(lhs) << rhs; \
    } \
    constexpr max_int_t operator>>(enum_t lhs, int rhs) { \
        return static_cast<max_int_t>(lhs) >> rhs; \
    }
