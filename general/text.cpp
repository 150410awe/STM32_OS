#include "type.h"

void text() {
    null_address a1 { 0x08000000 };
    code_address a2 { static_cast<code_address>(a1) };
    a1 = 1000;
    code_address a3 ( a1 );
    code_address a4 { a3 };
    code_address a5 = a4;
    a5 = a3;
    SRAM_address a6 { 1545 };
    int32_t a7 = 100;
    SRAM_address a8{reinterpret_cast<max_int_t*>(a7)};
}