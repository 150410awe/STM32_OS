#pragma once

#include "../../../general/type.h"

namespace kernel::device::GPIO {
    enum class work_mode : u8 {
        input = 0b00,              // 输入模式 - MODER=00
        output_push_pull = 0b01,     // 推挽输出模式 - MODER=01
        alternate_function_push_pull = 0b10,  // 复用推挽模式 - MODER=10
        analog = 0b11,               // 模拟模式 - MODER=11
    };

    enum class output_type : u8 {
        push_pull = 0,  // 推挽输出 - OTYPER=0
        open_drain = 1, // 开漏输出 - OTYPER=1
    };

    enum class pull_up_down : u8 {
        no_pull = 0b00,   // 无上拉/下拉 - PUPDR=00
        pull_up = 0b01,   // 上拉 - PUPDR=01
        pull_down = 0b10, // 下拉 - PUPDR=10
        reserved = 0b11,  // 保留 - PUPDR=11
    };

    enum class interrupt_trigger : u8 {
        rising_edge = 0b01,     // 上升沿触发
        falling_edge = 0b10,    // 下降沿触发
        rising_falling_edge = 0b11, // 双边沿触发
    };

    enum class mode_type : u8 {
        interrupt = 0b01,  // 中断模式
        event = 0b10,     // 事件模式
    };
}