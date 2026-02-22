#pragma once

/**
 * external_device_memory_distribution.h - 外部设备内存分布
 * @note 外部设备内存分布, 用于区分不同的外部设备内存分布
 */

#include "external_device_type.h"
#include "../interval.h"
#include <array>
#include <cstddef>

namespace general::device {
    // 前向声明
    static const inline std::array<int_interval, static_cast<size_t>(external_device_type::MAX_VAL)>& init_external_device_memory();
    
    // 使用前向声明的函数初始化
    const inline std::array<int_interval, static_cast<size_t>(external_device_type::MAX_VAL)>& external_device_memory = init_external_device_memory();
    
    static const inline std::array<int_interval, static_cast<size_t>(external_device_type::MAX_VAL)>& init_external_device_memory() {
        // 初始化数组
        static std::array<int_interval, static_cast<size_t>(external_device_type::MAX_VAL)> external_device_memory{ };
        
        //AHB1 总线外设 (0x4002 0000 - 0x4002 7FFF)
        external_device_memory[static_cast<size_t>(external_device_type::GPIOA)] = { 0x40020000, 0x400203FF };
        external_device_memory[static_cast<size_t>(external_device_type::GPIOB)] = { 0x40020400, 0x400207FF };
        external_device_memory[static_cast<size_t>(external_device_type::GPIOC)] = { 0x40020800, 0x40020BFF };
        external_device_memory[static_cast<size_t>(external_device_type::GPIOD)] = { 0x40020C00, 0x40020FFF };
        external_device_memory[static_cast<size_t>(external_device_type::GPIOE)] = { 0x40021000, 0x400213FF };
        external_device_memory[static_cast<size_t>(external_device_type::GPIOF)] = { 0x40021400, 0x400217FF };
        external_device_memory[static_cast<size_t>(external_device_type::GPIOG)] = { 0x40021800, 0x40021BFF };
        external_device_memory[static_cast<size_t>(external_device_type::GPIOH)] = { 0x40021C00, 0x40021FFF };
        external_device_memory[static_cast<size_t>(external_device_type::GPIOI)] = { 0x40022000, 0x400223FF };
        external_device_memory[static_cast<size_t>(external_device_type::CRC)] = { 0x40023000, 0x400233FF };
        external_device_memory[static_cast<size_t>(external_device_type::RCC)] = { 0x40023800, 0x40023BFF };
        external_device_memory[static_cast<size_t>(external_device_type::flash_interface)] = { 0x40023C00, 0x40023FFF };
        external_device_memory[static_cast<size_t>(external_device_type::BKPSRAM)] = { 0x40024000, 0x40024FFF };  // 4KB
        external_device_memory[static_cast<size_t>(external_device_type::DMA1)] = { 0x40026000, 0x400263FF };
        external_device_memory[static_cast<size_t>(external_device_type::DMA2)] = { 0x40026400, 0x400267FF };
        external_device_memory[static_cast<size_t>(external_device_type::ethernet_MAC)] = { 0x40028000, 0x400283FF };
        external_device_memory[static_cast<size_t>(external_device_type::ethernet_DMA)] = { 0x40028400, 0x400287FF };
        external_device_memory[static_cast<size_t>(external_device_type::USB_OTG_HS)] = { 0x40040000, 0x4007FFFF };   // 256KB
        //AHB2 总线外设 (0x5000 0000 - 0x5006 0FFF)
        external_device_memory[static_cast<size_t>(external_device_type::USB_OTG_FS)] = { 0x50000000, 0x5003FFFF };   // 256KB
        external_device_memory[static_cast<size_t>(external_device_type::DCMI)] = { 0x50050000, 0x50050FFF };   // 4KB
        external_device_memory[static_cast<size_t>(external_device_type::CRYP)] = { 0x50060000, 0x50060FFF };   // 4KB
        external_device_memory[static_cast<size_t>(external_device_type::HASH)] = { 0x50060400, 0x500607FF };
        external_device_memory[static_cast<size_t>(external_device_type::RNG)] = { 0x50060800, 0x50060BFF };
        //APB1 总线外设 (0x4000 0000 - 0x4000 7FFF)
        external_device_memory[static_cast<size_t>(external_device_type::TIM2)] = { 0x40000000, 0x400003FF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM3)] = { 0x40000400, 0x400007FF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM4)] = { 0x40000800, 0x40000BFF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM5)] = { 0x40000C00, 0x40000FFF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM6)] = { 0x40001000, 0x400013FF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM7)] = { 0x40001400, 0x400017FF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM12)] = { 0x40001800, 0x40001BFF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM13)] = { 0x40001C00, 0x40001FFF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM14)] = { 0x40002000, 0x400027FF };
        external_device_memory[static_cast<size_t>(external_device_type::RTC)] = { 0x40002800, 0x40002BFF };
        external_device_memory[static_cast<size_t>(external_device_type::WWDG)] = { 0x40002C00, 0x40002FFF };
        external_device_memory[static_cast<size_t>(external_device_type::IWDG)] = { 0x40003000, 0x400037FF };
        external_device_memory[static_cast<size_t>(external_device_type::SPI2)] = { 0x40003800, 0x40003BFF };
        external_device_memory[static_cast<size_t>(external_device_type::SPI3)] = { 0x40003C00, 0x40003FFF };
        external_device_memory[static_cast<size_t>(external_device_type::USART2)] = { 0x40004400, 0x400047FF };
        external_device_memory[static_cast<size_t>(external_device_type::USART3)] = { 0x40004800, 0x40004BFF };
        external_device_memory[static_cast<size_t>(external_device_type::UART4)] = { 0x40004C00, 0x40004FFF };
        external_device_memory[static_cast<size_t>(external_device_type::UART5)] = { 0x40005000, 0x400053FF };
        external_device_memory[static_cast<size_t>(external_device_type::I2C1)] = { 0x40005400, 0x400057FF };
        external_device_memory[static_cast<size_t>(external_device_type::I2C2)] = { 0x40005800, 0x40005BFF };
        external_device_memory[static_cast<size_t>(external_device_type::I2C3)] = { 0x40005C00, 0x400063FF };
        external_device_memory[static_cast<size_t>(external_device_type::CAN1)] = { 0x40006400, 0x400067FF };
        external_device_memory[static_cast<size_t>(external_device_type::CAN2)] = { 0x40006800, 0x40006BFF };
        external_device_memory[static_cast<size_t>(external_device_type::PWR)] = { 0x40007000, 0x400073FF };
        external_device_memory[static_cast<size_t>(external_device_type::DAC)] = { 0x40007400, 0x400077FF };
        // APB2 总线外设 (0x4001 0000 - 0x4001 7FFF)
        external_device_memory[static_cast<size_t>(external_device_type::TIM1)] = { 0x40010000, 0x400103FF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM8)] = { 0x40010400, 0x400107FF };
        external_device_memory[static_cast<size_t>(external_device_type::USART1)] = { 0x40011000, 0x400113FF };
        external_device_memory[static_cast<size_t>(external_device_type::USART6)] = { 0x40011400, 0x400117FF };
        external_device_memory[static_cast<size_t>(external_device_type::ADC1)] = { 0x40012000, 0x400120FF };
        external_device_memory[static_cast<size_t>(external_device_type::ADC2)] = { 0x40012100, 0x400121FF };
        external_device_memory[static_cast<size_t>(external_device_type::ADC3)] = { 0x40012200, 0x400122FF };
        external_device_memory[static_cast<size_t>(external_device_type::SDIO)] = { 0x40012C00, 0x40012FFF };
        external_device_memory[static_cast<size_t>(external_device_type::SPI1)] = { 0x40013000, 0x400133FF };
        external_device_memory[static_cast<size_t>(external_device_type::SPI4)] = { 0x40013400, 0x400137FF };
        external_device_memory[static_cast<size_t>(external_device_type::SYSCFG)] = { 0x40013800, 0x40013BFF };
        external_device_memory[static_cast<size_t>(external_device_type::EXTI)] = { 0x40013C00, 0x40013FFF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM9)] = { 0x40014000, 0x400143FF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM10)] = { 0x40014400, 0x400147FF };
        external_device_memory[static_cast<size_t>(external_device_type::TIM11)] = { 0x40014800, 0x40014BFF };
        external_device_memory[static_cast<size_t>(external_device_type::SPI5)] = { 0x40015000, 0x400153FF };
        external_device_memory[static_cast<size_t>(external_device_type::SPI6)] = { 0x40015400, 0x400157FF };
        // FSMC 区 (0x6000 0000 - 0x9FFF FFFF)
        external_device_memory[static_cast<size_t>(external_device_type::FSMC_NORSRAM1)] = { 0x60000000, 0x63FFFFFF };  //64MB
        external_device_memory[static_cast<size_t>(external_device_type::FSMC_NORSRAM2)] = { 0x64000000, 0x67FFFFFF };  //64MB
        external_device_memory[static_cast<size_t>(external_device_type::FSMC_NORSRAM3)] = { 0x68000000, 0x6BFFFFFF };  //64MB
        external_device_memory[static_cast<size_t>(external_device_type::FSMC_NORSRAM4)] = { 0x6C000000, 0x6FFFFFFF };  //64MB
        external_device_memory[static_cast<size_t>(external_device_type::FSMC_NAND1)] = { 0x70000000, 0x7FFFFFFF };  //256MB
        external_device_memory[static_cast<size_t>(external_device_type::FSMC_NAND2)] = { 0x80000000, 0x8FFFFFFF };  //256MB
        external_device_memory[static_cast<size_t>(external_device_type::FSMC_PCCARD)] = { 0x90000000, 0x9FFFFFFF };  //256MB
        external_device_memory[static_cast<size_t>(external_device_type::FSMC_register)] = { 0xA0000000, 0xA0000FFF };  //4KB
        // 内核外设 (0xE000 0000 - 0xE00F FFFF)
        external_device_memory[static_cast<size_t>(external_device_type::NVIC)] = { 0xE000E100, 0xE000E1FF };
        external_device_memory[static_cast<size_t>(external_device_type::SCB)] = { 0xE000ED00, 0xE000EDFF };
        external_device_memory[static_cast<size_t>(external_device_type::sys_tick)] = { 0xE000E010, 0xE000E01F };
        external_device_memory[static_cast<size_t>(external_device_type::MPU)] = { 0xE000ED90, 0xE000ED9F };
        external_device_memory[static_cast<size_t>(external_device_type::FPU)] = { 0xE000EF30, 0xE000EF3F };
        external_device_memory[static_cast<size_t>(external_device_type::ITM)] = { 0xE0000000, 0xE0000FFF };
        external_device_memory[static_cast<size_t>(external_device_type::DWT)] = { 0xE0001000, 0xE0001FFF };
        external_device_memory[static_cast<size_t>(external_device_type::TPIU)] = { 0xE0040000, 0xE0040FFF };
        return external_device_memory;
    }
}
