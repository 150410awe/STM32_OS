#pragma once

/**
 * address_struct.h - 地址结构体头文件
 * @note 包含地址结构体相关的定义和函数声明
 */

#include "memory_distribution.h"

namespace general::memory {
    using namespace distribution;
/**
 * address - 地址结构体
 * @tparam block_type 内存块类型
 * @param address_value 地址值
 * @note 地址值必须在指定的内存块类型范围内，否则会被设置为0
 * 必须显式写 block 类型 , 才可以转换为对应类型的地址
 */
template <class address_t, block block_type> struct address {
    max_int_t address_value = null_address_value;

    // 注... block::null 在 一些函数中被看做错误,
    // 因为你好像指向了一个不存在的,超过4gb的内存...
    // 还有check_address(), 也有错误处理
    // 我还没实现 error 的类型.

    address& operator=(address&& address) noexcept = default;
    address(address&& address) noexcept = default;
    constexpr address& operator=(const address& address) = default;
    constexpr address(const address& address) = default;
    constexpr address_t operator+(const address_t set_address) const {
        return address_t{ address_value + set_address.address_value };
    }
    constexpr address_t& operator+=(const address_t set_address) {
        address_value += set_address.address_value;
        // 检查地址是否在指定的内存块类型范围内
        if (!update() || !check_address()) {
            address_value = null_address_value;
            // error...
        }
        return *(static_cast<address_t*>(this));
    }
    address_t& operator=(max_int_t* set_address) {
        address_value = *set_address;
        if (!update() || !check_address()) {
            address_value = null_address_value;
            // error...
        }
        return *(static_cast<address_t*>(this));
    }
    address_t& operator=(max_int_t set_address) = delete;

    /**
     * 统一的初始化构造函数
     * @param value 地址值
     * @note
     * 模板参数已经指定了block_type，需要检查地址值是否在指定的内存块类型范围内
     */
    explicit address(max_int_t* address) : address_value(*address) {
        if (!update() || !check_address()) {
            address_value = null_address_value;
            // error...
        }
    }
    constexpr explicit address(max_int_t value) : address_value(value) {
        // 检查地址是否在指定的内存块类型范围内
        if (!update() || !check_address()) {
            address_value = null_address_value;
            // error...
        }
    }
    constexpr address() = default;

    /**
     * 显式转换构造函数，只允许从其他block类型显式转换
     * @param other 其他地址结构体
     * @note 转换后的地址值必须在指定的内存块类型范围内，否则会被设置为0
     * 不可以update_block_type. 因为很明显other不是block_type. 你 update 必出错.
     * 我还转换个屁.
     */
    template <typename other_address_t, block other_block_type>   
    constexpr explicit address(const address<other_address_t, other_block_type>& other) : address_value(other.address_value) {
        // 检查地址是否在指定的内存块类型范围内
        if (!update() || !check_address()) {
            address_value = null_address_value;
            // error...
        }
    }

    /**
     * check_address - 检查地址是否在指定的内存块类型范围内, 是否和法
     * @return 合法 true 不合法 false
     * @note 有地址块类型检查和该块类型的地址范围检查, 保证地址的合法性,
     * 可以防止地址指向越界和保留区域
     */
    constexpr bool check_address() const {
        return static_cast<const address_t*>(this)->check_address();
    }
    constexpr bool update() {
        return static_cast<address_t*>(this)->update();
    }
};
}