#pragma once

/**
 * FSMC_address.h - FSMC地址, 用于表示FSMC地址
 */

#include "address_struct.h"
#include "external_device_memory_distribution.h"
#include "external_device_type.h"

namespace general::memory {
    using namespace distribution;
    
struct FSMC_address : address<FSMC_address, block::FSMC> {
    constexpr FSMC_address()  = default;
    constexpr FSMC_address(const general::device::FSMC_device_type set_device_type) : FSMC_device_type(set_device_type) {
        address_value = general::device::FSMC_device_memory[static_cast<size_t>(FSMC_device_type)].start;
    }
    FSMC_address& operator=(const general::device::FSMC_device_type set_device_type ) {
        FSMC_device_type = set_device_type;
        address_value = general::device::FSMC_device_memory[static_cast<size_t>(FSMC_device_type)].start;
        return *this;
    }
    constexpr FSMC_address& operator+=(const FSMC_address set_address) = delete;
    constexpr FSMC_address operator+(const FSMC_address set_address) = delete;
    
    general::device::FSMC_device_type FSMC_device_type = general::device::FSMC_device_type::null;

    constexpr bool check_address() const {
        if (!block_FSMC_snippet.contains(address_value))
            return false;

        // 检查外部设备内存是否包含该地址
        if (!general::device::FSMC_device_memory[static_cast<size_t>(FSMC_device_type)].contains(address_value))
            return false;

        return true;
    }

    /**
     * update_external_device_type - 更新外部设备类型
     * @return 如果更新成功则返回true，否则返回false
     */
    constexpr bool update() {
        if (!block_sram_snippet.contains(address_value))
            return false;

        for (size_t i = 0; i < static_cast<size_t>(general::device::FSMC_device_type::MAX_VAL); i++) 
            if (general::device::external_device_memory[i].contains(address_value)) {
                FSMC_device_type = static_cast<general::device::FSMC_device_type>(i);
                return true;
            }
        
        return false;
    }
};
}