#pragma once

#include "../../../general/type.h"

namespace kernel::device::GPIO {
    enum class pin_id : u16 {
        null = 0x0000, // 无效引脚
        pin_0 = 0x0001, // 引脚0
        pin_1 = 0x0002, // 引脚1
        pin_2 = 0x0004, // 引脚2
        pin_3 = 0x0008, // 引脚3
        pin_4 = 0x0010, // 引脚4
        pin_5 = 0x0020, // 引脚5
        pin_6 = 0x0040, // 引脚6
        pin_7 = 0x0080, // 引脚7
        pin_8 = 0x0100, // 引脚8
        pin_9 = 0x0200, // 引脚9
        pin_10 = 0x0400, // 引脚10
        pin_11 = 0x0800, // 引脚11
        pin_12 = 0x1000, // 引脚12
        pin_13 = 0x2000, // 引脚13
        pin_14 = 0x4000, // 引脚14
        pin_15 = 0x8000, // 引脚15
        pin_all = 0xFFFF, // 所有引脚
    };
    basic_bit_mask_operation(pin_id);
}
