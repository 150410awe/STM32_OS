#pragma once

/**
 * foundation_type.h - 基础类型头文件
 * @note 包含基础类型相关的定义和函数声明
*/

#include <cstdint>
#include <cstddef>

namespace general::type {
    using max_int_t = std::intmax_t;
    using max_uint_t = std::uintmax_t;
    using max_i = max_int_t;
    using max_u = max_uint_t;
    using i8 = std::int8_t;
    using u8 = std::uint8_t;
    using i16 = std::int16_t;
    using u16 = std::uint16_t;
    using i32 = std::int32_t;
    using u32 = std::uint32_t;
    using i64 = std::int64_t;
    using u64 = std::uint64_t;
    using u_char = u8;
    using offset_t = max_int_t; // 偏移量
    using subscript_t = max_int_t;  // 下标
    using ptrdiff_t = max_int_t;    // 指针差
    /**
    * struct_offset - 计算结构体成员的偏移量
    * @param u 指向结构体成员的指针
    * @return 结构体成员的偏移量
    */
    template<typename T, typename U>
    constexpr offset_t struct_offset(U T::* u) {
        return reinterpret_cast<offset_t>(&(reinterpret_cast<T*>(nullptr)->*u));
    }
}

using namespace general::type;