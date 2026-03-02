#pragma once

#include "../../general/type.h"

namespace kernel::file {
    enum class type : u8 {
        unknown = 0,    // 未知文件类型
        executable,
        ordinary,
        directory,
    };
}