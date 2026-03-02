#pragma once

#include "../../general/type.h"

namespace kernel::file {
    enum class open_mode : u8 {
        read_only, // 只读模式
        write_only, // 只写模式
        read_write, // 读写模式
    };
}