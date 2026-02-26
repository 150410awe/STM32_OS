#include "../kernel_include/device/GPIO/GPIO.h"
#include "../kernel_include/device/RCC/clock_enable_peripheral_clock.h"
#include "../kernel_include/device/RCC/clock_enable_register.h"
#include "../include_set.h"

void setup() {
    using namespace kernel::device::RCC;

    AHB1ENR = AHB1_peripheral_clock::GPIOC;

    GPIOC[0] = output_level::high;
    GPIOC[1] = output_level::low;
    GPIOC[2] = output_level::high;
    GPIOC[0].lock();
}

void loop() {
    // 主循环代码
}

int main(void) {
    setup();
    while (1) 
        loop();
    
    return 0;
}