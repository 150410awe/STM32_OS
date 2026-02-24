#pragma once

#include "work_mode.h"
#include "output_speed_config.h"
#include "reuse_function_id.h"
#include "register_config.h"
#include <type_traits>

// 这个傻逼不支持c++20, 所以我用宏了. 我操你奶.
#define __operator_AF__(AF)  \
    inline pin& operator=(AF af) { \
            volatile u32* afr_ptr; \
            u32 bit_offset; \
\
            if (pin_id < 8) {\
                afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL)); \
                bit_offset = pin_id * 4; \
            } else { \
                afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH)); \
                bit_offset = (pin_id - 8) * 4; \
            } \
 \
            u32 mask = 0b1111 << bit_offset; \
 \
            *afr_ptr &= ~mask; \
            *afr_ptr |= (static_cast<u32>(af) << bit_offset); \
 \
            return *this; \
        }

namespace kernel::device::GPIO {
    struct pin {
        work_mode mode : 2;     //  引脚工作模式	决定引脚的基本身份
        output_type type : 1;       // 输出类型	决定输出的电气特性
        pull_up_down pull : 2;      // 上拉/下拉电阻	决定引脚的输入状态
        output_speed speed : 2;     // 输出速度	决定引脚的输出速率
        register_type ODR;     // 输出数据寄存器	控制引脚的输出状态
        register_type IDR;     // 输入数据寄存器	读取引脚的输入状态
        union {
            struct {
                AF0 af0 : 4;
                AF1 af1 : 4;
                AF2 af2 : 4;
                AF3 af3 : 4;
                AF4 af4 : 4;
                AF5 af5 : 4;
                AF6 af6 : 4;
                AF7 af7 : 4;
                AF8 af8 : 4;
                AF9 af9 : 4;
                AF10 af10 : 4;
                AF11 af11 : 4;
                AF12 af12 : 4;
                AF13 af13 : 4;
                AF14 af14 : 4;
                AF15 af15 : 4;
            } AF;   // 复用功能选择寄存器
        };
        u32 BSRR;   // 位设置/重置寄存器 原子操作	安全快速控制

        peripheral_address GPIO_address;    // GPIO端口地址
        u8 pin_id;                         // 引脚编号
        pin() = default;
        pin(external_device_type GPIO_id, u8 pin_id) : GPIO_address(GPIO_id), pin_id(pin_id) {}
        ~pin() = default;

        pin& operator=(work_mode mode);
        pin& operator=(output_type type);
        pin& operator=(pull_up_down pull);
        pin& operator=(output_speed speed);
        pin& operator=(output_level ODR);
        pin& operator=(u32 BSRR);
        __operator_AF__(AF0)
        __operator_AF__(AF1)
        __operator_AF__(AF2)
        __operator_AF__(AF3)
        __operator_AF__(AF4)
        __operator_AF__(AF5)
        __operator_AF__(AF6)
        __operator_AF__(AF7)
        __operator_AF__(AF8)
        __operator_AF__(AF9)
        __operator_AF__(AF10)
        __operator_AF__(AF11)
        __operator_AF__(AF12)
        __operator_AF__(AF13)
        __operator_AF__(AF14)
        __operator_AF__(AF15)
    };
}
