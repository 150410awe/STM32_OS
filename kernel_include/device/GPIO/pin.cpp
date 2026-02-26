#include "pin.h"
#include "register_config.h"
#include "memory_layout.h"

using namespace kernel::device::GPIO;

pin& pin::operator=(work_mode mode) {
    // if (is_locked()) ; // error
    
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
    // if (is_locked()) ; // error
    
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
    // if (is_locked()) ; // error
    
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
    // if (is_locked()) ; // error
    
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

bool pin::lock() {
    if (is_lock())
        return true;

    volatile u32* lckr_ptr { reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::LCKR)) };
    
    // 第一步：写入要锁定的引脚和 LCKK 位
    *lckr_ptr = __lock_bit_set[pin_id] | LCKK;
    
    // 第二步：清除 LCKK 位
    *lckr_ptr = __lock_bit_set[pin_id];
    
    // 第三步：再次设置 LCKK 位
    *lckr_ptr = __lock_bit_set[pin_id] | LCKK;
    
    // 第四步：读取 LCKR 寄存器，确认 LCKK 位是否为 1
    u32 lckr_value = *lckr_ptr;
    if (!(lckr_value & LCKK)) return false;
    
    // 第五步：再次读取 LCKR 寄存器，确认 LCKK 位是否为 0
    lckr_value = *lckr_ptr;
    if (lckr_value & LCKK)
        return false;
    
    return true;
}

bool pin::is_lock() {
    volatile u32* lckr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::LCKR)) };
    
    u32 lckr_value = *lckr_ptr;
    return (lckr_value & __lock_bit_set[pin_id]) != 0;
}

bool pin::unlock() {
    if (!is_lock())
        return true;

    volatile u32* lckr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::LCKR)) };
    
    // 第一步：设置 LCKK 位
    *lckr_ptr = LCKK;
    
    // 第二步：清除 LCKK 位
    *lckr_ptr = 0;
    
    return true;
}