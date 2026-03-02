#pragma once

#include "../../general/type.h"

namespace kernel::file {
    enum class file_inspection : u8 {
        file_is_exist, // 检查文件是否存在
        execution_authority, // 检查执行权限
        write_authority, // 检查写权限
        read_authority, // 检查读权限
        null,
    };
}