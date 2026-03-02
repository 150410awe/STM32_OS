#pragma once

#include "../../general/type.h"
#include "type.h"
#include "data.h"

namespace kernel::file {
    struct dir_entry {
        char name[max_file_name_size];
        u16 inode;
    };
}