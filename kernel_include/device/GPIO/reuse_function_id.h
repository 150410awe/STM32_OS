#pragma once

#include "../../../general/type.h"

namespace kernel::device::GPIO {
    enum class AF0 : u8 {
        RTC_50Hz = 0x00,  // RTC 50Hz 复用到 AF0
        MCO = 0x00,       // MCO 时钟输出复用到 AF0
        TAMPER = 0x00,    // TAMPER 入侵检测复用到 AF0
        SWJ = 0x00,       // SWJ 调试接口复用到 AF0
        TRACE = 0x00,     // TRACE 跟踪接口复用到 AF0
    };

    enum class AF1 : u8 {
        TIM1 = 0x01,  // TIM1 复用到 AF1
        TIM2 = 0x01,  // TIM2 复用到 AF1
    };

    enum class AF2 : u8 {
        TIM3 = 0x02,  // TIM3 复用到 AF2
        TIM4 = 0x02,  // TIM4 复用到 AF2
        TIM5 = 0x02,  // TIM5 复用到 AF2
    };

    enum class AF3 : u8 {
        TIM8 = 0x03,   // TIM8 复用到 AF3
        TIM9 = 0x03,   // TIM9 复用到 AF3
        TIM10 = 0x03,  // TIM10 复用到 AF3
        TIM11 = 0x03,  // TIM11 复用到 AF3
    };

    enum class AF4 : u8 {
        I2C1 = 0x04,  // I2C1 复用到 AF4
        I2C2 = 0x04,  // I2C2 复用到 AF4
        I2C3 = 0x04,  // I2C3 复用到 AF4
    };

    enum class AF5 : u8 {
        SPI1 = 0x05,  // SPI1 复用到 AF5
        SPI2 = 0x05,  // SPI2 复用到 AF5
    };

    enum class AF6 : u8 {
        SPI3 = 0x06,  // SPI3 复用到 AF6
        I2S2 = 0x06,  // I2S2 复用到 AF6
        I2S3 = 0x06,  // I2S3 复用到 AF6
    };

    enum class AF7 : u8 {
        USART1 = 0x07,  // USART1 复用到 AF7
        USART2 = 0x07,  // USART2 复用到 AF7
        USART3 = 0x07,  // USART3 复用到 AF7
    };

    enum class AF8 : u8 {
        UART4 = 0x08,  // UART4 复用到 AF8
        UART5 = 0x08,  // UART5 复用到 AF8
        USART6 = 0x08,  // USART6 复用到 AF8
    };

    enum class AF9 : u8 {
        CAN1 = 0x09,   // CAN1 复用到 AF9
        CAN2 = 0x09,   // CAN2 复用到 AF9
        TIM12 = 0x09,  // TIM12 复用到 AF9
        TIM13 = 0x09,  // TIM13 复用到 AF9
        TIM14 = 0x09,  // TIM14 复用到 AF9
    };

    enum class AF10 : u8 {
        OTG_FS = 0x0A,  // OTG_FS 复用到 AF10
        OTG_HS = 0x0A,  // OTG_HS 复用到 AF10
    };

    enum class AF11 : u8 {
        ETH = 0x0B,  // 以太网 复用到 AF11
    };

    enum class AF12 : u8 {
        FSMC = 0x0C,     // FSMC 复用到 AF12
        SDIO = 0x0C,     // SDIO 复用到 AF12
        OTG_HS_FS = 0x0C, // OTG_HS_FS 复用到 AF12
    };

    enum class AF13 : u8 {
        DCMI = 0x0D,  // DCMI 复用到 AF13
    };

    enum class AF14 : u8 {
        reserved = 0x0E,  // 保留
    };

    enum class AF15 : u8 {
        EVENTOUT = 0x0F,  // EVENTOUT 复用到 AF15
    };
}