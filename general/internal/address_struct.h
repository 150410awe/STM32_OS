#pragma once

/**
 * address_struct.h - 地址结构体头文件
 * @note 包含地址结构体相关的定义和函数声明
 */

#include "memory_distribution.h"

namespace general::memory::distribution {
/**
 * address - 地址结构体
 * @tparam block_type 内存块类型
 * @param address_value 地址值
 * @note 地址值必须在指定的内存块类型范围内，否则会被设置为0
 * 必须显式写 block 类型 , 才可以转换为对应类型的地址
 */
template <block block_type> struct address {
  max_int_t address_value;

  // 注... block::null 在 一些函数中被看做错误,
  // 因为你好像指向了一个不存在的,超过4gb的内存...
  // 还有check_address(), 也有错误处理
  // 我还没实现 error 的类型.

  constexpr address &operator=(address &&address) noexcept = default;
  constexpr address(address &&address) noexcept = default;
  constexpr address &operator=(const address &address) = default;
  constexpr address(const address &address) = default;
  constexpr address operator+(const address set_address) const {
    return address<block_type>{address_value + set_address.address_value};
  }
  constexpr address operator+(const max_int_t set_address) const {
    return address<block_type>{address_value + set_address};
  }
  constexpr address &operator+=(const max_int_t set_address) {
    address_value += set_address;
    return *this;
  }

  /**
   * 赋值运算符，允许将max_int_t类型的地址值赋值给address结构体
   * @param set_address 要设置的地址值
   * @return 对当前address结构体的引用
   * @note 会检查地址值是否在指定的内存块类型范围内，否则会被设置为0
   */
  constexpr address &operator=(max_int_t set_address) {
    address_value = set_address;
    if (!check_address()) {
      address_value = 0;
      // error...
    }
    return *this;
  }

  /**
   * 统一的初始化构造函数
   * @param value 地址值
   * @note
   * 模板参数已经指定了block_type，需要检查地址值是否在指定的内存块类型范围内
   */
  constexpr explicit address(max_int_t *address) : address_value(*address) {
    if (!check_address()) {
      address_value = 0;
      // error...
    }
  }
  constexpr explicit address(max_int_t value) : address_value(value) {
    if (!check_address()) {
      address_value = 0;
      // error...
    }
  }

  /**
   * 显式转换构造函数，只允许从其他block类型显式转换
   * @param other 其他地址结构体
   * @note 转换后的地址值必须在指定的内存块类型范围内，否则会被设置为0
   * 不可以update_block_type. 因为很明显other不是block_type. 你 update 必出错.
   * 我还转换个屁.
   */
  template <block other_block_type>
  constexpr explicit address(const address<other_block_type> other)
      : address_value(other.address_value) {
    // 检查地址是否在指定的内存块类型范围内
    if (!check_address()) {
      address_value = 0;
      // error...
    }
  }

  /**
   * check_address - 检查地址是否在指定的内存块类型范围内, 是否和法
   * @return 合法 true 不合法 false
   * @note 有地址块类型检查和该块类型的地址范围检查, 保证地址的合法性,
   * 可以防止地址指向越界和保留区域
   */
  constexpr bool check_address() {
    if constexpr (block_type == block::null)
      return true;
    else if constexpr (block_type == block::code)
      if (block_code_snippet.contains(address_value))
        if (code_snippet::reserved_area1.contains(address_value) ||
            code_snippet::reserved_area2.contains(address_value) ||
            code_snippet::reserved_area3.contains(address_value) ||
            code_snippet::reserved_area4.contains(address_value))
          return false;
        else
          return true;
      else
        return false;
    else if constexpr (block_type == block::sram)
      if (block_sram_snippet.contains(address_value))
        if (SRAM_snippet::reserved_area1.contains(address_value) ||
            SRAM_snippet::reserved_area2.contains(address_value) ||
            SRAM_snippet::reserved_area3.contains(address_value))
          return false;
        else
          return true;
      else
        return false;
    else if constexpr (block_type == block::peripheral_area)
      if (block_peripheral_snippet.contains(address_value))
        if (peripheral_snippet::reserved_area1.contains(address_value) ||
            peripheral_snippet::reserved_area2.contains(address_value) ||
            peripheral_snippet::reserved_area3.contains(address_value))
          return false;
        else
          return true;
      else
        return false;
    else if constexpr (block_type == block::FSMC)
      if (block_FSMC_snippet.contains(address_value))
        return true;
      else
        return false;
    else if constexpr (block_type == block::reserved_area)
      if (block_reserved_snippet.contains(address_value))
        if (reserved_snippet::reserved_area1.contains(address_value) ||
            reserved_snippet::reserved_area2.contains(address_value))
          return false;
        else
          return true;
      else
        return false;
    else
      return false;
  }
};

/**
 * 地址类型别名
 * 类型别名的使用说明
 * 我操你妈你看不出来??? 我这代码即文档. null_address这不一眼看出来了?
 * 还让我写使用说明... 因为我是个懒b,所以我代码即文档.
 * 这样就可以少写点文档,注释了.
 */

using null_address = address<block::null>;                  // null 地址
using code_address = address<block::code>;                  // 代码地址
using SRAM_address = address<block::sram>;                  // sram 地址
using peripheral_address = address<block::peripheral_area>; // 外设地址
using FSMC_address = address<block::FSMC>;                  // FSMC 地址
using reserved_address = address<block::reserved_area>;     // 保留地址
} // namespace general::memory::distribution