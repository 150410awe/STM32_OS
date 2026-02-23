#pragma once

#include "../../../general/type.h"

namespace kernel::device::GPIO {
    enum class output_speed : u8 {
        low_speed = 0b00,     // 2 MHz（低速）- 普通I/O，降低功耗和EMI
        medium_speed = 0b01,  // 25 MHz（中速）- 一般通信（SPI、USART）
        high_speed = 0b10,    // 50 MHz（快速）- 高速通信
        very_high_speed = 0b11 // 100 MHz（高速）- 最高速需求，30pF负载
    };
}