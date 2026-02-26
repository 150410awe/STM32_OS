#pragma once

/**
 * memory_distribution - 内存分布
 * 关于内存区间定义的详细说明
 * 你是傻逼吗, 我这代码,代码即文档. 你他妈看不出来是吗. 我写你妈.
 */


#include "foundation_type.h"
#include "../interval.h"

namespace general::memory::distribution {
    enum class block : u8 {
        null = 0, // null
        code, // 代码段
        sram, // 静态随机访问内存
        peripheral_area, // 外设区域
        FSMC, // FSMC 区域
        reserved_area,// 保留区域
    };
    namespace code_snippet {
        constexpr uint_interval alternative_names_area { 0x00000000, 0x000FFFFF };   // 别名区
        constexpr uint_interval reserved_area1 { 0x00100000, 0x07FFFFFF };   // 保留区域1
        constexpr uint_interval main_flash_memory { 0x08000000, 0x080FFFFF };     // 主Flash
        constexpr uint_interval reserved_area2 { 0x08200000, 0x1FFEFFFF };   // 保留区域2    
        constexpr uint_interval system_memory { 0x1FFF0000, 0x1FFF77FF };     // 系统存储器
        constexpr uint_interval OTP_area { 0x1FFF7800, 0x1FFF7A0F };     // OTP 区域
        constexpr uint_interval reserved_area3 { 0x1FFF7A10, 0x1FFF7BFF };    // 保留区域3
        constexpr uint_interval option_byte { 0x1FFFC000, 0x1FFFC00F };     // 选项字节
        constexpr uint_interval reserved_area4 { 0x1FFFC010, 0x1FFFFFFF };    // 保留区域4
    }
    namespace SRAM_snippet {
        constexpr uint_interval SRAM1 { 0x20000000, 0x2001BFFF };
        constexpr uint_interval SRAM2 { 0x2001C000, 0x2001FFFF };
        constexpr uint_interval SRAM3 { 0x20020000, 0x2002FFFF };
        constexpr uint_interval reserved_area1 { 0x20030000, 0x2FFFFFFF };    // 保留区域1
        constexpr uint_interval CCM_SRAM { 0x10000000, 0x1000FFFF }; //CCM SRAM
        constexpr uint_interval reserved_area2 { 0x10010000, 0x1FFFFFFF };    // 保留区域2
        constexpr uint_interval reserved_area3 { 0x30000000, 0x3FFFFFFF };    // 保留区域3
    }
    namespace peripheral_snippet {
        constexpr uint_interval APB1 { 0x40000000, 0x40007FFF }; //APB1 区域
        constexpr uint_interval reserved_area1 { 0x40078000, 0x400FFFFF };    // 保留区域1
        constexpr uint_interval peripheral_section_area { 0x40000000, 0x400FFFFF };    // 外设位段区
        constexpr uint_interval reserved_area2 { 0x40100000, 0x4FFFFFFF };    // 保留区域2
        constexpr uint_interval USB_OTG_FS { 0x50000000, 0x5003FFFF }; //USB OTG FS 区域
        constexpr uint_interval DCMI { 0x50040000, 0x5005FFFF }; //DCMI 区域
        constexpr uint_interval CRYP_HASH_RNG { 0x50060000, 0x50060FFF }; //CRYP_HASH_RNG 区域
        constexpr uint_interval reserved_area3 { 0x50061000, 0x5FFFFFFF };    // 保留区域3
        constexpr uint_interval APB2 { 0x40010000, 0x40017FFF }; //APB2 区域
        constexpr uint_interval AHB1  { 0x40020000, 0x40027FFF }; //AHB1 区域
        constexpr uint_interval AHB2  { 0x50000000, 0x50060FFF }; //AHB2 区域
    }
    namespace FSMC_snippet {
        constexpr uint_interval bank1 { 0x60000000, 0x6FFFFFFF }; //FSMC Bank1 区域
        constexpr uint_interval bank2 { 0x70000000, 0x7FFFFFFF }; //FSMC Bank2 区域
        constexpr uint_interval bank3 { 0x80000000, 0x8FFFFFFF }; //FSMC Bank3 区域
        constexpr uint_interval bank4 { 0x90000000, 0x9FFFFFFF }; //FSMC Bank4 区域

        constexpr uint_interval bank1_sub_region { 0x60000000, 0x63FFFFFF }; //FSMC Bank1 子区域 - NE1
        constexpr uint_interval bank2_sub_region { 0x64000000, 0x67FFFFFF }; //FSMC Bank2 子区域 - NE2
        constexpr uint_interval bank3_sub_region { 0x68000000, 0x6BFFFFFF }; //FSMC Bank3 子区域 - NE3
        constexpr uint_interval bank4_sub_region { 0x6C000000, 0x6FFFFFFF }; //FSMC Bank4 子区域 - NE4

        constexpr uint_interval FSMC_register_area { 0xA0000000, 0xA0000FFF }; //FSMC 寄存器区域
    }
    namespace reserved_snippet {
        constexpr uint_interval reserved_area1 { 0xC0000000, 0xDFFFFFFF };    // 保留区域1
        constexpr uint_interval internal_peripherals { 0xE0000000, 0xE00FFFFF };    // 内部外设区域
        constexpr uint_interval reserved_area2 { 0xE0100000, 0xFFFFFFFF };    // 保留区域2
    }
    namespace flash_struct {
        // 每个16kb
        constexpr uint_interval sector0 { 0x08000000, 0x08003FFF };    // 扇区 0
        constexpr uint_interval sector1 { 0x08004000, 0x08007FFF };    // 扇区 1
        constexpr uint_interval sector2 { 0x08008000, 0x0800BFFF };    // 扇区 2
        constexpr uint_interval sector3 { 0x0800C000, 0x0800FFFF };    // 扇区 3

        constexpr uint_interval sector4 { 0x08010000, 0x0801FFFF };    // 扇区 4, 64kb

        // 每个128KB 
        constexpr uint_interval sector5 { 0x08020000, 0x0803FFFF };    // 扇区 5
        constexpr uint_interval sector6 { 0x08040000, 0x0805FFFF };    // 扇区 6
        constexpr uint_interval sector7 { 0x08060000, 0x0807FFFF };    // 扇区 7
        constexpr uint_interval sector8 { 0x08080000, 0x0809FFFF };    // 扇区 8
        constexpr uint_interval sector9 { 0x080A0000, 0x080BFFFF };    // 扇区 9
        constexpr uint_interval sector10 { 0x080C0000, 0x080DFFFF };    // 扇区 10
        constexpr uint_interval sector11 { 0x080E0000, 0x080FFFFF };    // 扇区 11
    }

    constexpr uint_interval block_code_snippet { 0x00000000, 0x1FFFFFFF };    // 代码区
    constexpr uint_interval block_SRAM_snippet { 0x20000000, 0x3FFFFFFF };    // SRAM 区
    constexpr uint_interval block_peripheral_snippet { 0x40000000, 0x5FFFFFFF };    // 外设区
    constexpr uint_interval block_FSMC_snippet { 0x60000000, 0x9FFFFFFF };    // FSMC 区
    constexpr uint_interval block_reserved_snippet { 0xC0000000, 0xFFFFFFFF };    // 保留区域
    constexpr uint_interval peripheral_devices_kernel { 0xE0000000, 0xE00FFFFF };    // 内核外设区
    constexpr u32 null_address_value = 0xFFFFFFFF;// null_address_value - 默认空地址值, 为 null_address 指向的地址值, 一般改不了
    constexpr uint_interval null_address_interval {null_address_value, null_address_value};
}