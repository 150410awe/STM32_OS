#pragma once

#include "../../general/type.h"
#include "open_mode.h"

namespace kernel::file {
    struct descriptor {
        subscript_t index;

        descriptor(subscript_t index) : index(index) { }
        descriptor() = default;
        open_mode get_open_mode() const;
        void set_open_mode(open_mode mode);
    };

    /*
        标准输入文件描述符
        标准输出文件描述符
        标准错误文件描述符
        这个我还不确定放在哪, 和怎么访问. 先不写出来. 对了. 我这没有键盘和屏幕, 所以不用写.
    */
}