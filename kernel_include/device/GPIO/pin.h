#pragma once

#include "work_mode.h"
#include "output_speed_config.h"
#include "reuse_function_id.h"
#include "register_config.h"
#include "LCKR.h"
#include "pin_id.h"


// 这个傻逼不支持c++20, 所以我用宏了. 我操你奶.
#define __operator_AF__(AF)  \
    inline const pin& operator=(AF af) const { \
            /* if (is_locked()) ; error*/ \
\
            volatile u32* afr_ptr; \
            u32 bit_offset; \
\
            if (pin_number < 8) {\
                afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL)); \
                bit_offset = pin_number * 4; \
            } else { \
                afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH)); \
                bit_offset = (pin_number - 8) * 4; \
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
    /**
    *  pin - 引脚结构体
    *  @param GPIO_address GPIO端口地址
    *  @param pin_id 引脚编号
    *  @param mode 引脚工作模式	决定引脚的基本身份
    *  @param type 输出类型	决定输出的电气特性
    *  @param pull 上拉/下拉电阻	决定引脚的输入状态
    *  @param speed 输出速度	决定引脚的输出速率
    *  @param ODR 输出数据寄存器	控制引脚的输出状态
    *  @param IDR 输入数据寄存器	读取引脚的输入状态
    *  @param BSRR 位设置/重置寄存器	原子操作	安全快速控制
    *  @param LCKR 配置锁定寄存器	锁定引脚配置	防止意外修改
    **/
    struct pin {
        const peripheral_address GPIO_address;    // GPIO端口地址
        const pin_id pin_id_mask;                         // 引脚编号 (bitmask)
        const u8 pin_number;                        // 引脚编号 (0-15)
        constexpr pin(external_device_type GPIO_id, u8 pin_id) : GPIO_address(GPIO_id), pin_id_mask(pin_id_set[pin_id]), pin_number(pin_id) { }
        ~pin() = default;

        const pin& operator=(work_mode mode) const;
        const pin& operator=(output_type type) const;
        const pin& operator=(pull_up_down pull) const;
        const pin& operator=(output_speed speed) const;
        const pin& operator=(output_level ODR) const;
        const pin& operator=(u32 BSRR) const;
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
        
        bool is_lock() const; //is_locked - 检查引脚是否被锁定
        bool lock() const;    //lock - 锁定引脚配置
        bool unlock() const;  //unlock - 解锁引脚配置
    };
}
