#include "pin.h"
#include "register_config.h"
#include "memory_layout.h"

using namespace kernel::device::GPIO;

pin& pin::operator=(work_mode mode) {
    this->mode = mode;
    
    // MODER寄存器地址
    volatile u32* moder_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::MODER)) };
    
    u32 bit_offset{ static_cast<u32>(pin_id) * 2 };
    u32 mask{ static_cast<u32>(0b11) << bit_offset };
    
    *moder_ptr &= ~mask;
    *moder_ptr |= (static_cast<u32>(mode) << bit_offset);
    
    return *this;
}

pin& pin::operator=(output_type type) {
    this->type = type;
    
    // OTYPER寄存器地址
    volatile u32* otyper_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::OTYPER)) };
    
    u32 mask{ 1u << pin_id };
    
    if (type == output_type::push_pull) 
        *otyper_ptr &= ~mask;
    else 
        *otyper_ptr |= mask;
    
    return *this;
}

pin& pin::operator=(pull_up_down pull) {
    this->pull = pull;
    
    // PUPDR寄存器地址
    volatile u32* pupdr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::PUPDR)) };
    
    u32 bit_offset{ static_cast<u32>(pin_id) * 2 };
    u32 mask{ static_cast<u32>(0b11) << bit_offset };
    
    *pupdr_ptr &= ~mask;
    *pupdr_ptr |= (static_cast<u32>(pull) << bit_offset);
    
    return *this;
}

pin& pin::operator=(output_speed speed) {
    this->speed = speed;
    
    // OSPEEDR寄存器地址
    volatile u32* ospeedr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::OSPEEDR)) };
    
    u32 bit_offset{ static_cast<u32>(pin_id) * 2 };
    u32 mask{ static_cast<u32>(0b11) << bit_offset };
    
    *ospeedr_ptr &= ~mask;
    *ospeedr_ptr |= (static_cast<u32>(speed) << bit_offset);
    
    return *this;
}

pin& pin::operator=(output_level ODR) {
    this->ODR = ODR;
    
    // ODR寄存器地址
    volatile u32* odr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::ODR)) };
    
    u32 mask{ 1u << pin_id };
    
    if (ODR == output_level::high) 
        *odr_ptr |= mask;
    else 
        *odr_ptr &= ~mask;
    
    return *this;
}

pin& pin::operator=(u32 BSRR) {
    this->BSRR = BSRR;
    
    // BSRR寄存器地址
    volatile u32* bsr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::BSRR)) };
    
    *bsr_ptr = BSRR;
    
    return *this;
}
