#pragma once

#include "register_config.h"
#include "work_mode.h"
#include "../../../general/type.h"
#include "memory_layout.h"
#include "pin.h"

namespace kernel::device::GPIO {
    struct GPIO {
        constexpr GPIO(external_device_type GPIO_id) : pins{
            pin { GPIO_id, 0 },
            pin { GPIO_id, 1 },
            pin { GPIO_id, 2 },
            pin { GPIO_id, 3 },
            pin { GPIO_id, 4 },
            pin { GPIO_id, 5 },
            pin { GPIO_id, 6 },
            pin { GPIO_id, 7 },
            pin { GPIO_id, 8 },
            pin { GPIO_id, 9 },
            pin { GPIO_id, 10 },
            pin { GPIO_id, 11 },
            pin { GPIO_id, 12 },
            pin { GPIO_id, 13 },
            pin { GPIO_id, 14 },
            pin { GPIO_id, 15 },
        } { }

        const general::array<pin, 16> pins;

        const pin& operator[](size_t index) const {
            return pins[index];
        }
    };
    static constexpr general::array<GPIO, 9> __GPIO__ {
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

inline constexpr general::array<kernel::device::GPIO::GPIO, 9> GPIO = kernel::device::GPIO::__GPIO__;
inline constexpr kernel::device::GPIO::GPIO GPIOA = GPIO[0];
inline constexpr kernel::device::GPIO::GPIO GPIOB = GPIO[1];
inline constexpr kernel::device::GPIO::GPIO GPIOC = GPIO[2];
inline constexpr kernel::device::GPIO::GPIO GPIOD = GPIO[3];
inline constexpr kernel::device::GPIO::GPIO GPIOE = GPIO[4];
inline constexpr kernel::device::GPIO::GPIO GPIOF = GPIO[5];
inline constexpr kernel::device::GPIO::GPIO GPIOG = GPIO[6];
inline constexpr kernel::device::GPIO::GPIO GPIOH = GPIO[7];
inline constexpr kernel::device::GPIO::GPIO GPIOI = GPIO[8];