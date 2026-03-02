#pragma once

#include "../../general/type.h"

namespace kernel::file {
    enum class permissions : u8 {
        none = 0,
        read_write_execute,  // 用户读、写、执行权限
        read,  // 用户读权限
        write,  // 用户写权
        execute,  // 用户执行权限
    };
}