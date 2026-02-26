#pragma once

/**
 * external_device_memory_distribution.h - 外部设备内存分布
 * @note 外部设备内存分布, 用于区分不同的外部设备内存分布
 */

#include "external_device_type.h"
#include "../interval.h"
#include "array.h"
#include "memory_distribution.h"

namespace general::device {
    namespace {
        using external_device_array_t = general::array<uint_interval, static_cast<size_t>(external_device_type::MAX_VAL)>;
        struct external_device_array : external_device_array_t {
    
            constexpr uint_interval& operator[](external_device_type device_type) {
                return external_device_array_t::operator[](static_cast<size_t>(device_type));
            }
            
            constexpr const uint_interval& operator[](external_device_type device_type) const {
                return external_device_array_t::operator[](static_cast<size_t>(device_type));
            }
        };
        using FSMC_device_array_t = general::array<uint_interval, static_cast<size_t>(FSMC_device_type::MAX_VAL)>;
        struct FSMC_device_array : FSMC_device_array_t {
    
            constexpr uint_interval& operator[](FSMC_device_type device_type) {
                return FSMC_device_array_t::operator[](static_cast<size_t>(device_type));
            }
            constexpr const uint_interval& operator[](FSMC_device_type device_type) const {
                return FSMC_device_array_t::operator[](static_cast<size_t>(device_type));
            }
        };
    }

    constexpr external_device_array init_external_device_memory() {
        // 初始化数组, 不知道为什么必须这样干.
        external_device_array EDM{
            uint_interval{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
        };
        using EDT = external_device_type;
        //AHB1 总线外设 (0x4002 0000 - 0x4002 7FFF)
        EDM[EDT::GPIOA] = { 0x40020000, 0x400203FF };
        EDM[EDT::GPIOB] = { 0x40020400, 0x400207FF };
        EDM[EDT::GPIOC] = { 0x40020800, 0x40020BFF };
        EDM[EDT::GPIOD] = { 0x40020C00, 0x40020FFF };
        EDM[EDT::GPIOE] = { 0x40021000, 0x400213FF };
        EDM[EDT::GPIOF] = { 0x40021400, 0x400217FF };
        EDM[EDT::GPIOG] = { 0x40021800, 0x40021BFF };
        EDM[EDT::GPIOH] = { 0x40021C00, 0x40021FFF };
        EDM[EDT::GPIOI] = { 0x40022000, 0x400223FF };
        EDM[EDT::CRC]= { 0x40023000, 0x400233FF };
        EDM[EDT::RCC] = { 0x40023800, 0x40023BFF };
        EDM[EDT::flash_interface] = { 0x40023C00, 0x40023FFF };
        EDM[EDT::BKPSRAM] = { 0x40024000, 0x40024FFF };  // 4KB
        EDM[EDT::DMA1] = { 0x40026000, 0x400263FF };
        EDM[EDT::DMA2] = { 0x40026400, 0x400267FF };
        EDM[EDT::ethernet_MAC] = { 0x40028000, 0x400283FF };
        EDM[EDT::ethernet_DMA] = { 0x40028400, 0x400287FF };
        EDM[EDT::USB_OTG_HS] = { 0x40040000, 0x4007FFFF };   // 256KB
        //AHB2 总线外设 (0x5000 0000 - 0x5006 0FFF)
        EDM[EDT::USB_OTG_FS] = { 0x50000000, 0x5003FFFF };   // 256KB
        EDM[EDT::DCMI] = { 0x50050000, 0x50050FFF };   // 4KB
        EDM[EDT::CRYP] = { 0x50060000, 0x50060FFF };   // 4KB
        EDM[EDT::HASH] = { 0x50060400, 0x500607FF };
        EDM[EDT::RNG] = { 0x50060800, 0x50060BFF };
        //APB1 总线外设 (0x4000 0000 - 0x4000 7FFF)
        EDM[EDT::TIM2] = { 0x40000000, 0x400003FF };
        EDM[EDT::TIM3] = { 0x40000400, 0x400007FF };
        EDM[EDT::TIM4] = { 0x40000800, 0x40000BFF };
        EDM[EDT::TIM5] = { 0x40000C00, 0x40000FFF };
        EDM[EDT::TIM6] = { 0x40001000, 0x400013FF };
        EDM[EDT::TIM7] = { 0x40001400, 0x400017FF };
        EDM[EDT::TIM12] = { 0x40001800, 0x40001BFF };
        EDM[EDT::TIM13] = { 0x40001C00, 0x40001FFF };
        EDM[EDT::TIM14] = { 0x40002000, 0x400027FF };
        EDM[EDT::RTC] = { 0x40002800, 0x40002BFF };
        EDM[EDT::WWDG] = { 0x40002C00, 0x40002FFF };
        EDM[EDT::IWDG] = { 0x40003000, 0x400037FF };
        EDM[EDT::SPI2] = { 0x40003800, 0x40003BFF };
        EDM[EDT::SPI3] = { 0x40003C00, 0x40003FFF };
        EDM[EDT::USART2] = { 0x40004400, 0x400047FF };
        EDM[EDT::USART3] = { 0x40004800, 0x40004BFF };
        EDM[EDT::UART4] = { 0x40004C00, 0x40004FFF };
        EDM[EDT::UART5] = { 0x40005000, 0x400053FF };
        EDM[EDT::I2C1] = { 0x40005400, 0x400057FF };
        EDM[EDT::I2C2] = { 0x40005800, 0x40005BFF };
        EDM[EDT::I2C3] = { 0x40005C00, 0x400063FF };
        EDM[EDT::CAN1] = { 0x40006400, 0x400067FF };
        EDM[EDT::CAN2] = { 0x40006800, 0x40006BFF };
        EDM[EDT::PWR] = { 0x40007000, 0x400073FF };
        EDM[EDT::DAC] = { 0x40007400, 0x400077FF };
        // APB2 总线外设 (0x4001 0000 - 0x4001 7FFF)
        EDM[EDT::TIM1] = { 0x40010000, 0x400103FF };
        EDM[EDT::TIM8] = { 0x40010400, 0x400107FF };
        EDM[EDT::USART1] = { 0x40011000, 0x400113FF };
        EDM[EDT::USART6] = { 0x40011400, 0x400117FF };
        EDM[EDT::ADC1] = { 0x40012000, 0x400120FF };
        EDM[EDT::ADC2] = { 0x40012100, 0x400121FF };
        EDM[EDT::ADC3] = { 0x40012200, 0x400122FF };
        EDM[EDT::SDIO] = { 0x40012C00, 0x40012FFF };
        EDM[EDT::SPI1] = { 0x40013000, 0x400133FF };
        EDM[EDT::SPI4] = { 0x40013400, 0x400137FF };
        EDM[EDT::SYSCFG] = { 0x40013800, 0x40013BFF };
        EDM[EDT::EXTI] = { 0x40013C00, 0x40013FFF };
        EDM[EDT::TIM9] = { 0x40014000, 0x400143FF };
        EDM[EDT::TIM10] = { 0x40014400, 0x400147FF };
        EDM[EDT::TIM11] = { 0x40014800, 0x40014BFF };
        EDM[EDT::SPI5] = { 0x40015000, 0x400153FF };
        EDM[EDT::SPI6] = { 0x40015400, 0x400157FF };
        // 内核外设 (0xE000 0000 - 0xE00F FFFF)
        EDM[EDT::NVIC] = { 0xE000E100, 0xE000E1FF };
        EDM[EDT::SCB] = { 0xE000ED00, 0xE000EDFF };
        EDM[EDT::sys_tick] = { 0xE000E010, 0xE000E01F };
        EDM[EDT::MPU] = { 0xE000ED90, 0xE000ED9F };
        EDM[EDT::FPU] = { 0xE000EF30, 0xE000EF3F };
        EDM[EDT::ITM] = { 0xE0000000, 0xE0000FFF };
        EDM[EDT::DWT] = { 0xE0001000, 0xE0001FFF };
        EDM[EDT::TPIU] = { 0xE0040000, 0xE0040FFF };

        EDM[EDT::null] = memory::distribution::null_address_interval;
        return EDM;
    }
    constexpr FSMC_device_array init_FSMC_device_memory(){
        FSMC_device_array FDM{ 
            uint_interval{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}
        };
        using FDT = FSMC_device_type;
        // FSMC 区 (0x6000 0000 - 0x9FFF FFFF)
        FDM[FDT::FSMC_NORSRAM1] = { 0x60000000, 0x63FFFFFF };  //64MB
        FDM[FDT::FSMC_NORSRAM2] = { 0x64000000, 0x67FFFFFF };  //64MB
        FDM[FDT::FSMC_NORSRAM3] = { 0x68000000, 0x6BFFFFFF };  //64MB
        FDM[FDT::FSMC_NORSRAM4] = { 0x6C000000, 0x6FFFFFFF };  //64MB
        FDM[FDT::FSMC_NAND1] = { 0x70000000, 0x7FFFFFFF };  //256MB
        FDM[FDT::FSMC_NAND2] = { 0x80000000, 0x8FFFFFFF };  //256MB
        FDM[FDT::FSMC_PCCARD] = { 0x90000000, 0x9FFFFFFF };  //256MB
        FDM[FDT::FSMC_register] = { 0xA0000000, 0xA0000FFF };  //4KB

        FDM[FDT::null] = memory::distribution::null_address_interval;
        return FDM;
    }

    constexpr external_device_array external_device_memory{ init_external_device_memory() };
    constexpr FSMC_device_array FSMC_device_memory { init_FSMC_device_memory() };
}
