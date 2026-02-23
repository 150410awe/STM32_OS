#pragma once

#include "register_config.h"

namespace kernel::device::GPIO::memory_layout {
    using RT = register_type;
    
    // GPIO寄存器内存布局定义（每个寄存器占用4字节）
    constexpr int_interval MODER = { max_int_t(RT::MODER), max_int_t(RT::MODER - 1) };     // 0x00-0x03: GPIO端口模式寄存器
    constexpr int_interval OTYPER = { max_int_t(RT::OTYPER), max_int_t(RT::OTYPER - 1) };   // 0x04-0x07: GPIO端口输出类型寄存器
    constexpr int_interval OSPEEDR = { max_int_t(RT::OSPEEDR), max_int_t(RT::OSPEEDR - 1) }; // 0x08-0x0B: GPIO端口输出速度寄存器
    constexpr int_interval PUPDR = { max_int_t(RT::PUPDR), max_int_t(RT::PUPDR - 1) };     // 0x0C-0x0F: GPIO端口上拉/下拉寄存器
    constexpr int_interval IDR = { max_int_t(RT::IDR), max_int_t(RT::IDR - 1) };           // 0x10-0x13: GPIO端口输入数据寄存器
    constexpr int_interval ODR = { max_int_t(RT::ODR), max_int_t(RT::ODR - 1) };           // 0x14-0x17: GPIO端口输出数据寄存器
    constexpr int_interval BSRR = { max_int_t(RT::BSRR), max_int_t(RT::BSRR - 1) };       // 0x18-0x1B: GPIO端口置位/复位寄存器
    constexpr int_interval LCKR = { max_int_t(RT::LCKR), max_int_t(RT::LCKR - 1) };       // 0x1C-0x1F: GPIO端口配置锁定寄存器
    constexpr int_interval AFRL = { max_int_t(RT::AFRL), max_int_t(RT::AFRL - 1) };       // 0x20-0x23: GPIO复用功能低位寄存器
    constexpr int_interval AFRH = { max_int_t(RT::AFRH), max_int_t(RT::AFRH - 1) };       // 0x24-0x27: GPIO复用功能高位寄存器
}