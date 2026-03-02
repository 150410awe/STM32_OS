#pragma once

#include "../../general/type.h"

namespace kernel::file {
    constexpr size_t max_file_name_size = 6;   // 最大文件名大小，方便与 dir_entry::inode 对齐到 64 bit
    constexpr size_t flash_size = 1 * 1024 * 1024; // 1 MB 闪存大小
    constexpr size_t flash_block_size = 128; // 128 byte 闪存块大小
    constexpr size_t flash_block_count = flash_size / flash_block_size; // 闪存块数量
}