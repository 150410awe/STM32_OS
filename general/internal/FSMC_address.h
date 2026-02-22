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
    using address<FSMC_address, block::FSMC>::address;
    using address<FSMC_address, block::FSMC>::operator=;
    using address<FSMC_address, block::FSMC>::operator+;
    using address<FSMC_address, block::FSMC>::operator+=;
    general::device::external_device_type external_device_type;

    constexpr bool check_address() const {
        if (!block_FSMC_snippet.contains(address_value))
            return false;

        // 检查外部设备内存是否包含该地址
        const auto& external_device_memory = general::device::external_device_memory[static_cast<size_t>(external_device_type)];
        if (!external_device_memory.contains(address_value))
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

        for (size_t i = 0; i < static_cast<size_t>(general::device::external_device_type::MAX_VAL); i++) {
            const auto external_device_memory = general::device::external_device_memory[i];
            if (external_device_memory.contains(address_value)) {
                external_device_type = static_cast<general::device::external_device_type>(i);
                return true;
            }
        }
        return false;
    }
};
}