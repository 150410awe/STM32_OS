#include "pin.h"
#include "memory_layout.h"

using namespace kernel::device::GPIO;

const pin& pin::operator=(work_mode mode) const {
    // if (is_locked()) ; // error
    
    // MODER寄存器地址
    volatile u32* moder_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::MODER)) };
    
    u32 bit_offset { static_cast<u32>(pin_number) * pin_number::MODER };
    u32 mask{ mask::MODER << bit_offset };
    
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
    
    u32 bit_offset{ static_cast<u32>(pin_number) * pin_number::PUPDR };
    u32 mask{ mask::PUPDR << bit_offset };
    
    *pupdr_ptr &= ~mask;
    *pupdr_ptr |= (static_cast<u32>(pull) << bit_offset);
    
    return *this;
}

const pin& pin::operator=(output_speed speed) const {
    // if (is_locked()) ; // error
    
    // OSPEEDR寄存器地址
    volatile u32* ospeedr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::OSPEEDR)) };
    
    u32 bit_offset{ static_cast<u32>(pin_number) * pin_number::OSPEEDR };
    u32 mask{ mask::OSPEEDR << bit_offset };
    
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
    return (lckr_value & static_cast<u32>(pin_id_mask)) && (lckr_value & LCKK);
}

void pin::atomic_set_output_level(output_level level) const {
    // BSRR寄存器地址
    volatile u32* bsr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::BSRR)) };
    
    if (level == output_level::high) 
        // 设置引脚为高电平：写入低16位
        *bsr_ptr = static_cast<u32>(pin_id_mask);
    else 
        // 设置引脚为低电平：写入高16位
        *bsr_ptr = static_cast<u32>(pin_id_mask) << 16;
    
}

void pin::toggle_output_level() const {
    // ODR寄存器地址
    volatile u32* odr_ptr{ reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::ODR)) };
    
    // 读取当前ODR值
    u32 odr_value = *odr_ptr;
    
    // 检查当前引脚状态并切换
    if (odr_value & static_cast<u32>(pin_id_mask)) 
        // 当前为高电平，切换为低电平
        atomic_set_output_level(output_level::low);
    else 
        // 当前为低电平，切换为高电平
        atomic_set_output_level(output_level::high);
    
}