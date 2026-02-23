#pragma once

/**
 * reuse_function.h - 复用功能头文件
 * @note 包含GPIO复用功能相关的定义和函数声明
*/

#include "../clock_enable/RCC_config.h"

namespace kernel::device::GPIO {
    /**
     * reuse_function_type - 复用功能类型
     * @note 包含GPIO复用功能的枚举类型
     * 一定注意AF的编号对应enum值, 为了方便位移
    */
    enum class reuse_function_type : u8 {
        AF0_system_functions,  // 系统功能 	JTAG/SWD、RTC、MCO 复位后的默认功能
        AF1_timer_1_to_2,   // 定时器1-2 TIM1、TIM2	高级/通用定时器
        AF2_timer_3_to_5,   // 定时器3-5 TIM3、TIM4、TIM5	通用定时器
        AF3_timer_8_to_11,  // 定时器8-11 TIM8、TIM9、TIM10、TIM11	高级/通用定时器
        AF4_I2C,            // 	I2C1、I2C2、I2C3	I2C总线
        AF5_SPI,            // SPI总线	SPI1、SPI2、SPI3、SPI4
        AF6_SPI_I2S,        // 音频接口	SPI2/I2S2、SPI3/I2S3
        AF7_USART,          // 通用同步/异步收发器	USART1、USART2、USART3
        AF8_UART,           // 通用异步收发器	UART4、UART5、USART6
        AF9_CAN,            // 控制器局域网络	CAN1、CAN2
        AF10_USB,           // USB接口	OTG_FS、OTG_HS
        AF11_ETHERNET,      // 以太网MAC	ETH
        AF12_FSMC_SDIO,     // 外部存储器接口	FSMC、SDIO
        AF13_DCMI,          // 数字摄像头接口	DCMI
        AF14_reserved,      // 保留	-
        AF15_EVENTOUT,      // 内核事件输出	Cortex-M4事件输出
    };
}