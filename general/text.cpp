#include "internal/code_address.h"
#include "type.h"

void text() {
    null_address a1 { };
    code_address a2 { static_cast<code_address>(a1) };

    code_address a3 ( a1 );
    code_address a4 { a3 };
    code_address a5 = a4;
    a5 = a3;
    SRAM_address a6 { 1545 };
    int32_t a7 = 100;
    SRAM_address a8{reinterpret_cast<max_int_t*>(a7)};
    auto aa = a2 + code_address{100};
    auto bb = a2 + aa;
    auto cc = a2 += code_address{10};
    auto dd = aa = code_address{10};
    max_int_t aa_value = 100;
    aa = &aa_value;
    constexpr code_address c1{1000};
    constexpr code_address c2{c1};
    constexpr auto c3 = c1 + c2;
    constexpr code_address c4 = c3;
    constexpr null_address c13{};
    code_address c112{100};
    //c112 = 1000; error
    c112 = code_address{1000};
    null_address ccc {c4};
}