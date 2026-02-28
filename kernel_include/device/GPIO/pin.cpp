#include "pin.h"
#include "register_config.h"
#include "memory_layout.h"

using namespace kernel::device::GPIO;

const pin& pin::operator=(work_mode mode) const {
    // if (is_locked()) ; // error
    
    // MODER寄存器地址
    volatile u32* moder_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::MODER)) };
    
    u32 bit_offset{ static_cast<u32>(pin_number) * 2 };
    u32 mask{ static_cast<u32>(0b11) << bit_offset };
    
    *moder_ptr &= ~mask;
    *moder_ptr |= (static_cast<u32>(mode) << bit_offset);
    
    return *this;
}

const pin& pin::operator=(output_type type) const {
    // if (is_locked()) ; // error
    
    // OTYPER寄存器地址
    volatile u32* otyper_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::OTYPER)) };
    
    u32 mask{ static_cast<u32>(pin_id_mask) };
    
    if (type == output_type::push_pull) 
        *otyper_ptr &= ~mask;
    else 
        *otyper_ptr |= mask;
    
    return *this;
}

const pin& pin::operator=(pull_up_down pull) const {
    // if (is_locked()) ; // error
    
    // PUPDR寄存器地址
    volatile u32* pupdr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::PUPDR)) };
    
    u32 bit_offset{ static_cast<u32>(pin_number) * 2 };
    u32 mask{ static_cast<u32>(0b11) << bit_offset };
    
    *pupdr_ptr &= ~mask;
    *pupdr_ptr |= (static_cast<u32>(pull) << bit_offset);
    
    return *this;
}

const pin& pin::operator=(output_speed speed) const {
    // if (is_locked()) ; // error
    
    // OSPEEDR寄存器地址
    volatile u32* ospeedr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::OSPEEDR)) };
    
    u32 bit_offset{ static_cast<u32>(pin_number) * 2 };
    u32 mask{ static_cast<u32>(0b11) << bit_offset };
    
    *ospeedr_ptr &= ~mask;
    *ospeedr_ptr |= (static_cast<u32>(speed) << bit_offset);
    
    return *this;
}

const pin& pin::operator=(output_level ODR) const {
    
    // ODR寄存器地址
    volatile u32* odr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::ODR)) };
    
    u32 mask{ static_cast<u32>(pin_id_mask) };
    
    if (ODR == output_level::high) 
        *odr_ptr |= mask;
    else 
        *odr_ptr &= ~mask;
    
    return *this;
}

const pin& pin::operator=(u32 BSRR) const {
    
    // BSRR寄存器地址
    volatile u32* bsr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::BSRR)) };
    
    *bsr_ptr = BSRR;
    
    return *this;
}

bool pin::lock() const {
    if (is_lock())
        return true;

    volatile u32* lckr_ptr { reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::LCKR)) };
    
    // 第一步：写入要锁定的引脚和 LCKK 位
    *lckr_ptr = static_cast<u32>(pin_id_mask) | LCKK;
    
    // 第二步：清除 LCKK 位
    *lckr_ptr = static_cast<u32>(pin_id_mask);
    
    // 第三步：再次设置 LCKK 位
    *lckr_ptr = static_cast<u32>(pin_id_mask) | LCKK;
    
    // 第四步：读取 LCKR 寄存器，确认 LCKK 位是否为 1
    u32 lckr_value = *lckr_ptr;
    if (!(lckr_value & LCKK)) return false;
    
    // 第五步：再次读取 LCKR 寄存器，确认 LCKK 位是否为 0
    lckr_value = *lckr_ptr;
    if (lckr_value & LCKK)
        return false;
    
    return true;
}

bool pin::is_lock() const {
    volatile u32* lckr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::LCKR)) };
    
    u32 lckr_value = *lckr_ptr;
    return (lckr_value & static_cast<u32>(pin_id_mask)) != 0;
}

bool pin::unlock() const {
    if (!is_lock())
        return true;

    volatile u32* lckr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::LCKR)) };
    
    // 第一步：设置 LCKK 位
    *lckr_ptr = LCKK;
    
    // 第二步：清除 LCKK 位
    *lckr_ptr = 0;
    
    return true;
}