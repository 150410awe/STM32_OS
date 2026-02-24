#include "RCC.h"
#include "RCC_register_config.h"
#include "clock_enable_register.h"



void test() {
    using namespace kernel::device::RCC;
    AHB1ENR = AHB1_peripheral_clock::GPIOA;
    // AHB2ENR = AHB1_peripheral_clock::DMA1; error
    AHB3ENR = AHB3_peripheral_clock::FSMC;
}