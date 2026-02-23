#pragma once

#include "RCC_register_config.h"

namespace kernel::device::RCC {
    constexpr peripheral_address AHB1 = [](){
        peripheral_address AHB1 = external_device_type::RCC;
        AHB1.offset(static_cast<size_t>(RCC_register_type::AHB1ENR));
        return AHB1;
    }();
    constexpr peripheral_address AHB2 = [](){
        peripheral_address AHB2 = external_device_type::RCC;
        AHB2.offset(static_cast<size_t>(RCC_register_type::AHB2ENR));
        return AHB2;
    }();
    constexpr peripheral_address AHB3 = [](){
        peripheral_address AHB3 = external_device_type::RCC;
        AHB3.offset(static_cast<size_t>(RCC_register_type::AHB3ENR));
        return AHB3;
    }();
    constexpr peripheral_address APB1 = [](){
        peripheral_address APB1 = external_device_type::RCC;
        APB1.offset(static_cast<size_t>(RCC_register_type::APB1ENR));
        return APB1;
    }();
    constexpr peripheral_address APB2 = [](){
        peripheral_address APB2 = external_device_type::RCC;
        APB2.offset(static_cast<size_t>(RCC_register_type::APB2ENR));
        return APB2;
    }();
}