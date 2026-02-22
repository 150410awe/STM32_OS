#pragma once

/**
 * external_device_type.h - 外部设备类型
 * @note 外部设备类型, 用于区分不同的外部设备
 * 专为stm32f407设计 因为我这是OS, 所以功能要全 这就要用 LQFP176/BGA176了
 */

#include "foundation_type.h"

namespace general::device {
    /**
     * external_device_type - 外部设备类型
     * @note 外部设备类型, 用于区分不同的外部设备
     */
    enum class external_device_type : u8 {
        // 定时器
        // 高级定时器
        // 16位，带互补输出
        TIM1,//;
        TIM8,//;
        //通用定时器
        //TIM2-5 (32位)
        TIM2,//;
        TIM5,//;
        //TIM3-4 (16位)
        TIM3,//;
        TIM4,//;
        //TIM9-11 (16位)
        TIM9,//;
        TIM10,//;
        TIM11,//;
        // TIM6、TIM7 (16位)
        TIM6,       // 基本定时器1;
        TIM7,       // 基本定时器2;

        TIM12,              // 基本定时器3;
        TIM13,              // 基本定时器4;
        TIM14,              // 基本定时器5;

        IWDG,    // 独立看门狗定时器;
        WWDG,               // 窗口看门狗定时器;

        // 通信接口
        USART1,             // 通用异步收发传输器1;
        USART2,             // 通用异步收发传输器2;
        USART3,             // 通用异步收发传输器3;
        USART6,             // 通用异步收发传输器6 和手册对应;
        UART4,              // 通用异步收发传输器4 和手册对应;
        UART5,              // 通用异步收发传输器5 和手册对应;
        I2C1,               // 集成电路总线1;
        I2C2,               // 集成电路总线2;
        I2C3,               // 集成电路总线3;
        SPI1,               // 串行外设接口1 可配置为I2S;
        SPI2,               // 串行外设接口2 可配置为I2S;
        SPI3,               // 串行外设接口3 可配置为I2S;
        SPI4,               // 串行外设接口4 可配置为I2S;
        SPI5,               // 串行外设接口5 可配置为I2S;
        SPI6,               // 串行外设接口6 可配置为I2S;
        CAN1,               // 控制器区域网络1 支持2.0B协议;
        CAN2,               // 控制器区域网络2 支持2.0B协议;
        SDIO,               // 多媒体卡接口(SD/MMC);
        USB_OTG_FS,         // USB On-The-Go 全速接口（带PHY）;
        USB_OTG_HS,         // USB On-The-Go 高速接口（需外部PHY）;
        ethernet_MAC,                // 以太网MAC 10/100Mbps;
        ethernet_DMA,                // 以太网DMA;

        // 模拟外设
        // ADC - 12位，16通道，2.4MSPS
        ADC1,               // 模拟-to-数字转换器1;
        ADC2,               // 模拟-to-数字转换器2;
        ADC3,               // 模拟-to-数字转换器3;
        DAC,               // 数字-to-模拟转换器 12位，支持三角波/噪声生成;

        //DMA控制器  - 8个数据流，每个最多8个通道
        //总计	16个数据流	支持存储器到存储器、外设到存储器传输
        DMA1,               // DMA控制器1;
        DMA2,               // DMA控制器2;

        //其他外设 
        // 通用输入/输出端口
        GPIOA,              // 通用输入/输出端口A;
        GPIOB,              // 通用输入/输出端口B;
        GPIOC,              // 通用输入/输出端口C;
        GPIOD,              // 通用输入/输出端口D;
        GPIOE,              // 通用输入/输出端口E;
        GPIOF,              // 通用输入/输出端口F;
        GPIOG,              // 通用输入/输出端口G;
        GPIOH,              // 通用输入/输出端口H;
        GPIOI,              // 通用输入/输出端口I;
        // 外部中断/事件控制器
        EXTI,              // 外部中断/事件控制器;
        RTC,                // 实时时钟（带日历、闹钟）;
        CRC,                // 循环冗余校验;
        RNG,                // 随机数生成器 （真随机数）;
        CRYP,               // 加密处理器 CRYP（DES、TDES、AES）;
        HASH,               // 哈希处理器 HASH（MD5、SHA-1）;
        DCMI,                   // 数字摄像头接口（DCMI）;
        RCC,                // 复位和时钟控制;
        flash_interface,   // Flash控制寄存器;
        BKPSRAM,            // 备份SRAM;

        //内核外设
        NVIC,               // 嵌套向量中断控制器;
        SCB,                // 系统控制块;
        sys_tick,           // 系统定时器;
        MPU,                // 内存保护单元;
        FPU,                // 浮点运算单元;
        ITM,                // 指令跟踪宏单元;
        DWT,                // 数据观察点和跟踪单元;
        TPIU,               // 跟踪端口接口单元;
        PWR,                // 电源控制单元;
        SYSCFG,             // 系统配置控制器;
        null,               // 无设备

        MAX_VAL,
    };
    enum class FSMC_device_type : u8{
        //FSMC 区
        FSMC_NORSRAM1,      // FSMC NOR/SRAM 区域1 NE1片选;
        FSMC_NORSRAM2,      // FSMC NOR/SRAM 区域2 NE2片选;
        FSMC_NORSRAM3,      // FSMC NOR/SRAM 区域3 NE3片选;
        FSMC_NORSRAM4,      // FSMC NOR/SRAM 区域4 NE4片选 ;
        FSMC_NAND1,         // FSMC NAND 区域1 NCE2片选 同手册;
        FSMC_NAND2,         // FSMC NAND 区域2 NCE3片选;
        FSMC_PCCARD,        // FSMC PC卡区域 NCE4_1/NCE4_2;
        FSMC_register,      // FSMC 寄存器区域 FSMC控制寄存器;
        null,
        MAX_VAL,
    };
}