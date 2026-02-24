#pragma once

#include "clock_enable_peripheral_clock.h"
#include "RCC_register_config.h"

namespace kernel::device::RCC {
    namespace {
        template<typename type, max_int_t address_value>
        struct clock_enable_register {
            constexpr clock_enable_register& operator=(const type clock) {
                volatile u32* reg_ptr = reinterpret_cast<volatile u32*>(address_value);
                *reg_ptr |= static_cast<u32>(clock);
                return *this;
            }
        };

        struct __AHB1ENR__ : clock_enable_register<AHB1_peripheral_clock, address::AHB1ENR.address_value> {
            using clock_enable_register<AHB1_peripheral_clock, address::AHB1ENR.address_value>::operator=;
        };
        struct __AHB2ENR__ : clock_enable_register<AHB2_peripheral_clock, address::AHB2ENR.address_value> {
            using clock_enable_register<AHB2_peripheral_clock, address::AHB2ENR.address_value>::operator=;
        };
        struct __AHB3ENR__ : clock_enable_register<AHB3_peripheral_clock, address::AHB3ENR.address_value> {
            using clock_enable_register<AHB3_peripheral_clock, address::AHB3ENR.address_value>::operator=;
        };
        struct __APB1ENR__ : clock_enable_register<APB1_peripheral_clock, address::APB1ENR.address_value> {
            using clock_enable_register<APB1_peripheral_clock, address::APB1ENR.address_value>::operator=;
        };
        struct __APB2ENR__ : clock_enable_register<APB2_peripheral_clock, address::APB2ENR.address_value> {
            using clock_enable_register<APB2_peripheral_clock, address::APB2ENR.address_value>::operator=;
        };
    }
    static __AHB1ENR__ AHB1ENR {};
    static __AHB2ENR__ AHB2ENR {};
    static __AHB3ENR__ AHB3ENR {};
    static __APB1ENR__ APB1ENR {};
    static __APB2ENR__ APB2ENR {};
}