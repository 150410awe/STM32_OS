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
        GPIO(external_device_type GPIO_id) {
            for (u8 i = 0; i < 16; i++)
                pins[i] = pin(GPIO_id, i);
        }

        std::array<pin, 16> pins;

        pin& operator[](size_t index) {
            return pins[index];
        }
    };
    static std::array<GPIO, 9> __GPIO__ {
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

inline std::array<kernel::device::GPIO::GPIO, 9>& GPIO = kernel::device::GPIO::__GPIO__;
inline kernel::device::GPIO::GPIO& GPIOA = GPIO[0];
inline kernel::device::GPIO::GPIO& GPIOB = GPIO[1];
inline kernel::device::GPIO::GPIO& GPIOC = GPIO[2];
inline kernel::device::GPIO::GPIO& GPIOD = GPIO[3];
inline kernel::device::GPIO::GPIO& GPIOE = GPIO[4];
inline kernel::device::GPIO::GPIO& GPIOF = GPIO[5];
inline kernel::device::GPIO::GPIO& GPIOG = GPIO[6];
inline kernel::device::GPIO::GPIO& GPIOH = GPIO[7];
inline kernel::device::GPIO::GPIO& GPIOI = GPIO[8];