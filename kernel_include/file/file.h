#pragma once

#include "../../general/type.h"
#include "dir_entry.h"
#include "open_mode.h"
#include "permission.h"
#include "type.h"

namespace kernel::file {
    struct file {
        open_mode mode;         // 文件打开模式
        permissions permission; // 文件权限
        u8 reference_counting;  // 文件引用计数
        type type;              // 文件类型
        dir_entry entry;        // 文件目录项
    };
}