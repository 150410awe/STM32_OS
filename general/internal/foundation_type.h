#pragma once

/**
 * foundation_type.h - 基础类型头文件
 * @note 包含基础类型相关的定义和函数声明
*/

namespace general::type {
    using max_int_t = long;
    using max_uint_t = unsigned long;
    using int_max_t = max_int_t;
    using uint_max_t = max_uint_t;
    using max_i = max_int_t;
    using max_u = max_uint_t;
    using i8 = char;
    using u8 = unsigned char;
    using i16 = short;
    using u16 = unsigned short;
    using i32 = int;
    using u32 = unsigned int;
    using i64 = long long;
    using u64 = unsigned long long;
    using u_char = u8;
    using offset_t = max_int_t; // 偏移量
    using subscript_t = max_int_t;  // 下标
    using ptrdiff_t = max_int_t;    // 指针差
    using size_t = max_uint_t;      // 大小
    /**
    * struct_offset - 计算结构体成员的偏移量
    * @param u 指向结构体成员的指针
    * @return 结构体成员的偏移量
    */
    template<typename T, typename U>
    constexpr offset_t struct_offset(U T::* u) {
        return reinterpret_cast<offset_t>(&(reinterpret_cast<T*>(nullptr)->*u));
    }
    enum class output_level : u8 {
        low = 0,
        high = 1
    };
    using int8_t = i8;
    using uint8_t = u8;
    using int16_t = i16;
    using uint16_t = u16;
    using int32_t = i32;
    using uint32_t = u32;
    using int64_t = i64;
    using uint64_t = u64;
}

using namespace general::type;