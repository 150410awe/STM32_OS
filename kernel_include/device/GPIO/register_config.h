#pragma once

#include "../../../general/type.h"


namespace kernel::device::GPIO {
    enum class register_type : u8 {
        MODER = 0x00,  // GPIO端口模式寄存器 - 配置输入/输出/复用/模拟模式
        OTYPER = 0x04, // GPIO端口输出类型寄存器 - 配置推挽/开漏输出
        OSPEEDR = 0x08, // GPIO端口输出速度寄存器 - 配置输出速度
        PUPDR = 0x0C,  // GPIO端口上拉/下拉寄存器 - 配置上拉/下拉电阻
        IDR = 0x10,    // GPIO端口输入数据寄存器 - 读取引脚输入状态
        ODR = 0x14,    // GPIO端口输出数据寄存器 - 设置引脚输出状态
        BSRR = 0x18,   // GPIO端口置位/复位寄存器 - 原子操作置位/复位
        LCKR = 0x1C,   // GPIO端口配置锁定寄存器 - 锁定GPIO配置
        AFRL = 0x20,   // GPIO复用功能低位寄存器 - 引脚0-7的复用功能选择
        AFRH = 0x24,   // GPIO复用功能高位寄存器 - 引脚8-15的复用功能选择
    };
    constexpr max_int_t operator-(register_type a, max_int_t b) {
        return static_cast<max_int_t>(a) - b;
    }
}