#pragma once

#include "pin_id.h"
#include "register_config.h"
#include "work_mode.h"
#include "../../../general/type.h"
#include "memory_layout.h"
#include "pin.h"
#include <array>

namespace kernel::device::GPIO {
    struct GPIO {
        GPIO(external_device_type GPIO_id) : 
        port_base_address{ GPIO_id },
        MODER( port_base_address.address_value + memory_layout::MODER.start ),
        OTYPER( port_base_address.address_value + memory_layout::OTYPER.start ),
        OSPEEDR( port_base_address.address_value + memory_layout::OSPEEDR.start ),
        PUPDR( port_base_address.address_value + memory_layout::PUPDR.start ),
        IDR( port_base_address.address_value + memory_layout::IDR.start ),
        ODR( port_base_address.address_value + memory_layout::ODR.start ),
        BSRR( port_base_address.address_value + memory_layout::BSRR.start ),
        LCKR( port_base_address.address_value + memory_layout::LCKR.start ),
        AFR {
            static_cast<u32>(port_base_address.address_value + memory_layout::AFRL.start),
            static_cast<u32>(port_base_address.address_value + memory_layout::AFRH.start)
        } {
            for (u8 i = 0; i < 16; i++)
                pins[i] = pin(GPIO_id, i);
        }

        std::array<pin, 16> pins;

        peripheral_address port_base_address;
        u32 MODER;    // 模式寄存器
        u32 OTYPER;   // 输出类型寄存器
        u32 OSPEEDR;  // 输出速度寄存器
        u32 PUPDR;    // 上拉/下拉寄存器
        u32 IDR;      // 输入数据寄存器
        u32 ODR;      // 输出数据寄存器
        u32 BSRR;     // 位设置/重置寄存器
        u32 LCKR;     // 配置锁寄存器
        u32 AFR[2];

        pin& operator[](size_t index) {
            return pins[index];
        }
    };
    static std::array<GPIO, 9> _GPIO__ {
        GPIO(external_device_type::GPIOA),
        GPIO(external_device_type::GPIOB),
        GPIO(external_device_type::GPIOC),
        GPIO(external_device_type::GPIOD),
        GPIO(external_device_type::GPIOE),
        GPIO(external_device_type::GPIOF),
        GPIO(external_device_type::GPIOG),
        GPIO(external_device_type::GPIOH),
        GPIO(external_device_type::GPIOI),
    };
}

inline std::array<kernel::device::GPIO::GPIO, 9>& GPIO = kernel::device::GPIO::_GPIO__;
inline kernel::device::GPIO::GPIO& GPIOA = GPIO[0];
inline kernel::device::GPIO::GPIO& GPIOB = GPIO[1];
inline kernel::device::GPIO::GPIO& GPIOC = GPIO[2];
inline kernel::device::GPIO::GPIO& GPIOD = GPIO[3];
inline kernel::device::GPIO::GPIO& GPIOE = GPIO[4];
inline kernel::device::GPIO::GPIO& GPIOF = GPIO[5];
inline kernel::device::GPIO::GPIO& GPIOG = GPIO[6];
inline kernel::device::GPIO::GPIO& GPIOH = GPIO[7];
inline kernel::device::GPIO::GPIO& GPIOI = GPIO[8];