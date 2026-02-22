#pragma once

/**
 * type.h - 类型定义头文件, 这是一个集合...
 * @note 包含类型定义相关的定义和函数声明
 */
#include "internal/address_struct.h"
#include "internal/foundation_type.h"
#include "internal/external_device_type.h"
#include "internal/lmn_enum_struct_bit_mask.h"
#include "internal/null_address.h"
#include "internal/SRAM_address.h"
#include "internal/peripheral_address.h"
#include "internal/reserved_address.h"
#include "internal/code_address.h"
#include "internal/FSMC_address.h"


using namespace general::type;
using general::memory::code_address;
using general::memory::FSMC_address;
using general::memory::null_address;
using general::memory::peripheral_address;
using general::memory::reserved_address;
using general::memory::SRAM_address;

