#pragma once

/**
 *  LCKR - 配置锁定寄存器
 *  注意, 你会发现这个定义和标准库很不一样.  GPIO_LCKR_LCK GPIO锁定位 呢?
 *  不应该用 enum class ? 不. 在 struct pin 中有 pin_id. 表示是哪个引脚. 之后把引脚变成下标 给 __lock_bit_set 
 *  这样可能节省空间. 就算不是, 也就这样了.
 **/

#include "../../../general/type.h"

namespace kernel::device::GPIO {
    constexpr u16 __lock_bit_set[16] = {
        0x00000001, 0x00000002, 0x00000004, 0x00000008,
        0x00000010, 0x00000020, 0x00000040, 0x00000080,
        0x00000100, 0x00000200, 0x00000400, 0x00000800,
        0x00001000, 0x00002000, 0x00004000, 0x00008000,
    };
    constexpr u32 LCKK = 0x00010000;
}