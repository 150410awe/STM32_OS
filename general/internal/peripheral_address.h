#pragma once

/**
 * peripheral_address.h - 外设地址, 用于表示外设地址
 */

#include "address_struct.h"
#include "external_device_memory_distribution.h"

namespace general::memory {
    using namespace distribution;
    

struct peripheral_address : address<peripheral_address, block::peripheral_area> {
    constexpr peripheral_address() = default;
    constexpr peripheral_address(const general::device::external_device_type set_device_type) : external_device_type(set_device_type) {
        address_value = general::device::external_device_memory[static_cast<size_t>(external_device_type)].start;
    }
    peripheral_address& operator=(const general::device::external_device_type set_device_type) {
        external_device_type = set_device_type;
        address_value = general::device::external_device_memory[static_cast<size_t>(external_device_type)].start;
        return *this;
    }
    constexpr peripheral_address& operator+=(const peripheral_address set_address) = delete;
    constexpr peripheral_address operator+(const peripheral_address set_address) = delete;
    general::device::external_device_type external_device_type = general::device::external_device_type::null;
    
    constexpr bool check_address() const {
        if (!block_peripheral_snippet.contains(address_value))
            return false;

        if (peripheral_snippet::reserved_area1.contains(address_value) ||
            peripheral_snippet::reserved_area2.contains(address_value) ||
            peripheral_snippet::reserved_area3.contains(address_value) )
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
