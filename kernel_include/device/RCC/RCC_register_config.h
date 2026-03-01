#pragma once

#include "../../../general/type.h"

namespace kernel::device::RCC {
    enum class RCC_register_type : u8 {
        CR = 0x00,           // 时钟控制 - 控制HSI、HSE、CSS、PLL使能
        PLLCFGR = 0x04,      // PLL配置 - 配置主PLL参数
        CFGR = 0x08,         // 时钟配置 - 系统时钟选择、分频器配置
        CIR = 0x0C,          // 时钟中断 - 时钟中断控制
        AHB1RSTR = 0x10,    // AHB1复位 - AHB1外设复位
        AHB2RSTR = 0x14,    // AHB2复位 - AHB2外设复位
        AHB3RSTR = 0x18,    // AHB3复位 - AHB3外设复位
        APB1RSTR = 0x20,    // APB1复位 - APB1外设复位
        APB2RSTR = 0x24,    // APB2复位 - APB2外设复位
        AHB1ENR = 0x30,     // AHB1使能 - AHB1外设时钟使能
        AHB2ENR = 0x34,     // AHB2使能 - AHB2外设时钟使能
        AHB3ENR = 0x38,     // AHB3使能 - AHB3外设时钟使能
        APB1ENR = 0x40,     // APB1使能 - APB1外设时钟使能
        APB2ENR = 0x44,     // APB2使能 - APB2外设时钟使能
        AHB1LPENR = 0x50,   // AHB1低功耗 - 睡眠模式AHB1时钟使能
        AHB2LPENR = 0x54,   // AHB2低功耗 - 睡眠模式AHB2时钟使能
        AHB3LPENR = 0x58,   // AHB3低功耗 - 睡眠模式AHB3时钟使能
        APB1LPENR = 0x60,   // APB1低功耗 - 睡眠模式APB1时钟使能
        APB2LPENR = 0x64,   // APB2低功耗 - 睡眠模式APB2时钟使能
        BDCR = 0x70,        // 备份域控制 - LSE、RTC时钟控制
        CSR = 0x74,         // 时钟状态 - 复位标志、LSI控制
        /* 
        RCC_RESERVED1 = 0x1C  // 保留
        RCC_RESERVED2 = 0x28  // 保留
        RCC_RESERVED3 = 0x2C  // 保留
        RCC_RESERVED4 = 0x3C  // 保留
        RCC_RESERVED5 = 0x48  // 保留
        RCC_RESERVED6 = 0x4C  // 保留
        RCC_RESERVED7 = 0x5C  // 保留
        RCC_RESERVED8 = 0x68  // 保留
        RCC_RESERVED9 = 0x6C  // 保留
        RCC_RESERVED10 = 0x78  // 保留
        RCC_RESERVED11 = 0x7C  // 保留
        不应访问
        */
        //RCC_SSCGR = 0x80,  // 扩频时钟生成寄存器（STM32F42x/43x） 不支持
        RCC_PLLI2SCFGR = 0x84,  // PLLI2S配置寄存器
        //RCC_DCKCFGR = 0x8C,  // 专用时钟配置寄存器（STM32F42x/43x）不支持
    };
    namespace address {
        namespace {
            constexpr peripheral_address RCC_register_address(RCC_register_type type) {
                peripheral_address ret{ external_device_type::RCC };
                ret.add(static_cast<u32>(type));
                return ret;
            }
        }
        static constexpr peripheral_address AHB1ENR = RCC_register_address(RCC_register_type::AHB1ENR);
        static constexpr peripheral_address AHB2ENR = RCC_register_address(RCC_register_type::AHB2ENR);
        static constexpr peripheral_address AHB3ENR = RCC_register_address(RCC_register_type::AHB3ENR);
        static constexpr peripheral_address APB1ENR = RCC_register_address(RCC_register_type::APB1ENR);
        static constexpr peripheral_address APB2ENR = RCC_register_address(RCC_register_type::APB2ENR);
    };
}