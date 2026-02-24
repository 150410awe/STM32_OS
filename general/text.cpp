#include "internal/code_address.h"
#include "internal/external_device_type.h"
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
    SRAM_address a8{reinterpret_cast<u32*>(a7)};
    auto aa = a2 + code_address{100};
    auto bb = a2 + aa;
    auto cc = a2 += code_address{10};
    auto dd = aa = code_address{10};
    u32 aa_value = 100;
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
    FSMC_address f1{};
    FSMC_address f2{f1};
    //FSMC_address f3{100}; error
    FSMC_address f4{general::device::FSMC_device_type::FSMC_NAND2};
    FSMC_address f5{general::device::FSMC_device_type::null};

    //f2 = FSMC_address{1000}; error
    //f2 = &aa_value; error
    // 因为general::device::FSMC_device_type 不是 constexpr 所以不可以, 这是编绎器的问题, 不星我的问题
    constexpr FSMC_address f6{general::device::FSMC_device_type::FSMC_NAND2}; //现在可以了

    //f1 += f2; error
    f1 = f2;
    // f1 + f2; error

    peripheral_address p1{};
    peripheral_address p2 = p1;
    // peripheral_address p3{general::device::FSMC_device_type::FSMC_NAND1} error
    peripheral_address p4{general::device::external_device_type::ADC1};
    peripheral_address p5{general::device::external_device_type::null};
    //...
    //const auto c1cc = general::device::external_device_memory[10]; //error
    const auto c1cc = general::device::external_device_memory[general::device::external_device_type::null];
}