#pragma once

/**
 * clock_enable_peripheral_clock.h - 时钟使能外设时钟, 举出外设时钟使能
 */

#include "../../../general/type.h"

namespace kernel::device::RCC {
    enum class AHB1_peripheral_clock : u32 {
        GPIOA = 1 << 0,   // GPIOA时钟使能
        GPIOB = 1 << 1,   // GPIOB时钟使能
        GPIOC = 1 << 2,   // GPIOC时钟使能
        GPIOD = 1 << 3,   // GPIOD时钟使能
        GPIOE = 1 << 4,   // GPIOE时钟使能
        GPIOF = 1 << 5,   // GPIOF时钟使能
        GPIOG = 1 << 6,   // GPIOG时钟使能
        GPIOH = 1 << 7,   // GPIOH时钟使能
        GPIOI = 1 << 8,   // GPIOI时钟使能
        CRC = 1 << 12,    // CRC时钟使能
        BKPSRAM = 1 << 18, // 备份SRAM时钟使能
        CCMDATARAM = 1 << 20, // CCM数据RAM时钟使能
        DMA1 = 1 << 21,   // DMA1时钟使能
        DMA2 = 1 << 22,   // DMA2时钟使能
        ETHMAC = 1 << 25, // 以太网MAC时钟使能
        ETHMACTX = 1 << 26, // 以太网发送时钟使能
        ETHMACRX = 1 << 27, // 以太网接收时钟使能
        ETHMACPTP = 1 << 28, // 以太网PTP时钟使能
        OTGHS = 1 << 29,  // USB OTG HS时钟使能
        OTGHSULPI = 1 << 30, // USB OTG HS ULPI时钟使能
    };

    enum class AHB2_peripheral_clock : u8 {
        DCMI = 1 << 0,    // 数字摄像头接口时钟使能
        CRYP = 1 << 4,    // 加密处理器时钟使能
        HASH = 1 << 5,    // 散列处理器时钟使能
        RNG = 1 << 6,     // 随机数发生器时钟使能
        OTGFS = 1 << 7,   // USB OTG FS时钟使能
    };

    enum class AHB3_peripheral_clock : u8 {
        FSMC = 1 << 0,    // FSMC时钟使能
    };

    

    enum class APB1_peripheral_clock : u32 {
        TIM2 = 1 << 0,    // TIM2时钟使能
        TIM3 = 1 << 1,    // TIM3时钟使能
        TIM4 = 1 << 2,    // TIM4时钟使能
        TIM5 = 1 << 3,    // TIM5时钟使能
        TIM6 = 1 << 4,    // TIM6时钟使能
        TIM7 = 1 << 5,    // TIM7时钟使能
        TIM12 = 1 << 6,   // TIM12时钟使能
        TIM13 = 1 << 7,   // TIM13时钟使能
        TIM14 = 1 << 8,   // TIM14时钟使能
        WWDG = 1 << 11,   // 窗口看门狗时钟使能
        SPI2 = 1 << 14,   // SPI2时钟使能
        SPI3 = 1 << 15,   // SPI3/I2S3时钟使能
        USART2 = 1 << 17, // USART2时钟使能
        USART3 = 1 << 18, // USART3时钟使能
        UART4 = 1 << 19,  // UART4时钟使能
        UART5 = 1 << 20,  // UART5时钟使能
        I2C1 = 1 << 21,   // I2C1时钟使能
        I2C2 = 1 << 22,   // I2C2时钟使能
        I2C3 = 1 << 23,   // I2C3时钟使能
        CAN1 = 1 << 25,   // CAN1时钟使能
        CAN2 = 1 << 26,   // CAN2时钟使能
        PWR = 1 << 28,    // 电源接口时钟使能
        DAC = 1 << 29,    // DAC接口时钟使能
    };

    enum class APB2_peripheral_clock : u32 {
        TIM1 = 1 << 0,    // TIM1时钟使能
        TIM8 = 1 << 1,    // TIM8时钟使能
        USART1 = 1 << 4,  // USART1时钟使能
        USART6 = 1 << 5,  // USART6时钟使能
        ADC1 = 1 << 8,    // ADC1时钟使能
        ADC2 = 1 << 9,    // ADC2时钟使能
        ADC3 = 1 << 10,   // ADC3时钟使能
        SDIO = 1 << 11,   // SDIO时钟使能
        SPI1 = 1 << 12,   // SPI1时钟使能
        SPI4 = 1 << 13,   // SPI4时钟使能（仅F42x/43x）
        SYSCFG = 1 << 14, // 系统配置控制器时钟使能
        TIM9 = 1 << 16,   // TIM9时钟使能
        TIM10 = 1 << 17,  // TIM10时钟使能
        TIM11 = 1 << 18,  // TIM11时钟使能
        SPI5 = 1 << 20,   // SPI5时钟使能（仅F42x/43x）
        SPI6 = 1 << 21,   // SPI6时钟使能（仅F42x/43x）
    };

    basic_bit_mask_operation(AHB1_peripheral_clock)
    basic_bit_mask_operation(AHB2_peripheral_clock)
    basic_bit_mask_operation(AHB3_peripheral_clock)
    basic_bit_mask_operation(APB1_peripheral_clock)
    basic_bit_mask_operation(APB2_peripheral_clock)
}