#pragma once

#include "../../general/type.h"
#include "data.h"

namespace kernel::file {
    struct block {
        u16 id;
        code_address get_address() const {
            return code_address{ id * flash_block_size };
        }
    };
}