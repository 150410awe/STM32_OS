#pragma once

#include "work_mode.h"
#include "output_speed_config.h"
#include "reuse_function_id.h"
#include "register_config.h"
#include "LCKR.h"
#include "pin_id.h"
#include "register_config.h"


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
                bit_offset = pin_number * pin_number::AFR; \
            } else { \
                afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH)); \
                bit_offset = (pin_number - 8) * pin_number::AFR; \
            } \
 \
            u32 mask = mask::AFR << bit_offset; \
 \
            *afr_ptr &= ~mask; \
            *afr_ptr |= (static_cast<u32>(af) << bit_offset); \
 \
            return *this; \
        }

namespace kernel::device::GPIO {
    /**
    *  pin - 引脚结构体
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
        void atomic_set_output_level(output_level level) const; //atomic_set_output_level - 原子设置输出电平
        void toggle_output_level() const; //toggle_output_level - 切换输出电平
    };
}
