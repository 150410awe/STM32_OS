#pragma once

#include "pin_id.h"
#include "work_mode.h"
#include "output_speed_config.h"
#include "reuse_function_id.h"
#include "register_config.h"

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

        peripheral_address GPIO_address;
        u8 pin_id;
        pin() = default;
        pin(external_device_type GPIO_id, u8 pin_id) : GPIO_address(GPIO_id), pin_id(pin_id) {}
        ~pin() = default;

        pin& operator=(work_mode mode);
        pin& operator=(output_type type);
        pin& operator=(pull_up_down pull);
        pin& operator=(output_speed speed);
        pin& operator=(bool ODR_or_IDR);
        pin& operator=(AF0 af0);
        pin& operator=(AF1 af1);
        pin& operator=(AF2 af2);
        pin& operator=(AF3 af3);
        pin& operator=(AF4 af4);
        pin& operator=(AF5 af5);
        pin& operator=(AF6 af6);
        pin& operator=(AF7 af7);
        pin& operator=(AF8 af8);
        pin& operator=(AF9 af9);
        pin& operator=(AF10 af10);
        pin& operator=(AF11 af11);
        pin& operator=(AF12 af12);
        pin& operator=(AF13 af13);
        pin& operator=(AF14 af14);
        pin& operator=(AF15 af15);
    };
}
