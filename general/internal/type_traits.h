#pragma once

#include "foundation_type.h"

namespace general {
    /**
     * @brief 类型特性：移除引用
     */
    template <typename T>
    struct remove_reference {
        using type = T;
    };
    
    template <typename T>
    struct remove_reference<T&> {
        using type = T;
    };
    
    template <typename T>
    struct remove_reference<T&&> {
        using type = T;
    };
    
    template <typename T>
    using remove_reference_t = typename remove_reference<T>::type;
    
    /**
     * @brief 类型特性：判断是否为左值引用
     */
    template <typename T>
    struct is_lvalue_reference {
        static constexpr bool value = false;
    };
    
    template <typename T>
    struct is_lvalue_reference<T&> {
        static constexpr bool value = true;
    };
    
    /**
     * @brief 类型特性：判断是否为数组
     */
    template <typename T>
    struct is_array {
        static constexpr bool value = false;
    };
    
    template <typename T, size_t N>
    struct is_array<T[N]> {
        static constexpr bool value = true;
    };
    
    template <typename T>
    struct is_array<T[]> {
        static constexpr bool value = true;
    };
    
    template <typename T>
    constexpr bool is_array_v = is_array<T>::value;
    
    /**
     * @brief 类型特性：获取数组维度
     */
    template <typename T>
    struct extent {
        static constexpr size_t value = 0;
    };
    
    template <typename T, size_t N>
    struct extent<T[N]> {
        static constexpr size_t value = N;
    };
    
    template <typename T>
    struct extent<T[]> {
        static constexpr size_t value = 0;
    };
    
    template <typename T>
    constexpr size_t extent_v = extent<T>::value;
    
    /**
     * @brief 类型特性：移除数组维度
     */
    template <typename T>
    struct remove_extent {
        using type = T;
    };
    
    template <typename T, size_t N>
    struct remove_extent<T[N]> {
        using type = T;
    };
    
    template <typename T>
    struct remove_extent<T[]> {
        using type = T;
    };
    
    template <typename T>
    using remove_extent_t = typename remove_extent<T>::type;
    
    /**
     * @brief 类型特性：条件启用模板
     */
    template <bool B, typename T = void>
    struct enable_if {
    };
    
    template <typename T>
    struct enable_if<true, T> {
        using type = T;
    };
    
    template <bool B, typename T = void>
    using enable_if_t = typename enable_if<B, T>::type;
    

    
    /**
     * @brief 实现 move 功能，将左值转换为右值引用
     * @tparam T 类型
     * @param t 要转换的值
     * @return 右值引用
     */
    template <typename T>
    constexpr typename remove_reference<T>::type&& move(T&& t) noexcept {
        return static_cast<typename remove_reference<T>::type&&>(t);
    }
    
    /**
     * @brief 实现 forward 功能，保持值的类别
     * @tparam T 类型
     * @param t 要转发的值
     * @return 保持原始值类别的引用
     */
    template <typename T>
    constexpr T&& forward(typename remove_reference<T>::type& t) noexcept {
        return static_cast<T&&>(t);
    }
    
    /**
     * @brief 实现 forward 功能，保持值的类别（右值版本）
     * @tparam T 类型
     * @param t 要转发的值
     * @return 保持原始值类别的引用
     */
    template <typename T>
    constexpr T&& forward(typename remove_reference<T>::type&& t) noexcept {
        static_assert(!is_lvalue_reference<T>::value, "Cannot forward an rvalue as an lvalue");
        return static_cast<T&&>(t);
    }
    
    /**
     * @brief 实现 swap 功能，交换两个值
     * @tparam T 类型
     * @param a 第一个值
     * @param b 第二个值
     */
    template <typename T>
    void swap(T& a, T& b) noexcept {
        T temp = move(a);
        a = move(b);
        b = move(temp);
    }
}