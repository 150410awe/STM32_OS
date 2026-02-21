#pragma once

/**
 * address_struct - 地址结构体
 */

#include "memory_distribution.h"

namespace general::memory::distribution {
    /**
     * address - 地址结构体
     * @tparam block_type 内存块类型
     * @param address_value 地址值
     * @note 地址值必须在指定的内存块类型范围内，否则会被设置为0
     * 必须显式写 block 类型 , 才可以转换为对应类型的地址
     */
    template<block block_type>
    struct address {
        max_int_t address_value;

        //注... block::null 在 constexpr address& operator=(max_int_t set_address) 中被看做错误, 因为你好像指向了一个不存在的,超过4gb的内存...
        //我还没实现 error 的类型.

        constexpr address& operator=(address&& address) noexcept = default;
        constexpr address(address&& address) noexcept = default;
        constexpr address& operator=(const address& address) = default;
        constexpr address(const address& address) = default;
        constexpr address& operator=(max_int_t set_address) {
            address_value = set_address;
            if (update_block_type(address_value) != block_type) {
                address_value = 0;
                //error...
            }
            return *this;
        }

        /**
         * 统一的初始化构造函数
         * @param value 地址值
         * @note 模板参数已经指定了block_type，需要检查地址值是否在指定的内存块类型范围内
         */
        constexpr explicit address(max_int_t value) :
            address_value(value) {
            if (update_block_type(address_value) != block_type) {
                address_value = 0;
                //error...
            }
        }

        /**
         * 显式转换构造函数，只允许从其他block类型显式转换
         * @param other 其他地址结构体
         * @note 转换后的地址值必须在指定的内存块类型范围内，否则会被设置为0
         * 不可以update_block_type. 因为很明显other不是block_type. 你 update 必出错. 我还转换个屁.
         */
        template<block other_block_type>
        constexpr explicit address(const address<other_block_type>& other) :
            address_value(other.address_value) {
        }

        /**
         * update_block_type - 更新地址所属的内存块类型
         * @param value 地址值
         * @return 内存块类型
         */
        static constexpr block update_block_type(max_int_t value) {
            if (block_code_snippet.contains(value))
                return block::code;
            else if (block_sram_snippet.contains(value))
                return block::sram;
            else if (block_peripheral_snippet.contains(value))
                return block::peripheral_area;
            else if (block_FSMC_snippet.contains(value))
                return block::FSMC;
            else if (block_reserved_snippet.contains(value))
                return block::reserved_area;
            else
                return block::null; //error...
        }
    };

    /**
     * 地址类型别名
     * 类型别名的使用说明
     * 我操你妈你看不出来??? 我这代码即文档. null_address这不一眼看出来了?
     * 还让我写使用说明... 因为我是个懒b,所以我代码即文档. 这样就可以少写点文档,注释了.
     */

    using null_address = address<block::null>;    //null 地址
    using code_address = address<block::code>;    //代码地址
    using sram_address = address<block::sram>;    //sram 地址
    using peripheral_address = address<block::peripheral_area>;    //外设地址
    using FSMC_address = address<block::FSMC>;    //FSMC 地址
    using reserved_address = address<block::reserved_area>;    //保留地址
}