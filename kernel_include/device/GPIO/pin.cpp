#include "pin.h"
#include "register_config.h"


using namespace kernel::device::GPIO;

pin& pin::operator=(work_mode mode) {
    this->mode = mode;
    
    // MODER寄存器地址
    volatile u32* moder_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::MODER));
    
    u32 bit_offset = pin_id * 2;
    u32 mask = 0b11 << bit_offset;
    
    *moder_ptr &= ~mask;
    *moder_ptr |= (static_cast<u32>(mode) << bit_offset);
    
    return *this;
}

pin& pin::operator=(output_type type) {
    this->type = type;
    
    // OTYPER寄存器地址
    volatile u32* otyper_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::OTYPER));
    
    u32 mask = 1u << pin_id;
    
    if (type == output_type::push_pull) {
        *otyper_ptr &= ~mask;
    } else {
        *otyper_ptr |= mask;
    }
    
    return *this;
}

pin& pin::operator=(pull_up_down pull) {
    this->pull = pull;
    
    // PUPDR寄存器地址
    volatile u32* pupdr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::PUPDR));
    
    u32 bit_offset = pin_id * 2;
    u32 mask = 0b11 << bit_offset;
    
    *pupdr_ptr &= ~mask;
    *pupdr_ptr |= (static_cast<u32>(pull) << bit_offset);
    
    return *this;
}

pin& pin::operator=(output_speed speed) {
    this->speed = speed;
    
    // OSPEEDR寄存器地址
    volatile u32* ospeedr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::OSPEEDR));
    
    u32 bit_offset = pin_id * 2;
    u32 mask = 0b11 << bit_offset;
    
    *ospeedr_ptr &= ~mask;
    *ospeedr_ptr |= (static_cast<u32>(speed) << bit_offset);
    
    return *this;
}

pin& pin::operator=(bool ODR_or_IDR) {
    register_type reg = ODR_or_IDR ? register_type::ODR : register_type::IDR;
    
    // ODR寄存器地址
    volatile u32* odr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(reg));
    
    u32 mask = 1u << pin_id;
    
    if (reg == register_type::ODR) 
        *odr_ptr |= mask;
    else 
        *odr_ptr &= ~mask;
    
    return *this;
}

pin& pin::operator=(AF0 af0) {
    this->AF.af0 = af0;
    
    // AFRL/AFRH寄存器地址
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af0) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF1 af1) {
    this->AF.af1 = af1;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af1) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF2 af2) {
    this->AF.af2 = af2;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af2) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF3 af3) {
    this->AF.af3 = af3;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af3) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF4 af4) {
    this->AF.af4 = af4;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af4) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF5 af5) {
    this->AF.af5 = af5;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af5) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF6 af6) {
    this->AF.af6 = af6;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af6) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF7 af7) {
    this->AF.af7 = af7;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af7) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF8 af8) {
    this->AF.af8 = af8;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af8) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF9 af9) {
    this->AF.af9 = af9;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af9) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF10 af10) {
    this->AF.af10 = af10;
    
    // AFRH寄存器地址
    volatile u32* afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
    
    u32 bit_offset = (pin_id - 8) * 4;
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af10) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF11 af11) {
    this->AF.af11 = af11;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af11) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF12 af12) {
    this->AF.af12 = af12;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af12) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF13 af13) {
    this->AF.af13 = af13;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af13) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF14 af14) {
    this->AF.af14 = af14;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af14) << bit_offset);
    
    return *this;
}

pin& pin::operator=(AF15 af15) {
    this->AF.af15 = af15;
    
    volatile u32* afr_ptr;
    u32 bit_offset;
    
    if (pin_id < 8) {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRL));
        bit_offset = pin_id * 4;
    } else {
        afr_ptr = reinterpret_cast<volatile u32*>(GPIO_address.address_value + static_cast<max_int_t>(register_type::AFRH));
        bit_offset = (pin_id - 8) * 4;
    }
    
    u32 mask = 0b1111 << bit_offset;
    
    *afr_ptr &= ~mask;
    *afr_ptr |= (static_cast<u32>(af15) << bit_offset);
    
    return *this;
}
