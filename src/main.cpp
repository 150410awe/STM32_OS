#include "../include_set.h"

void setup() {
    using namespace kernel::device::RCC;

    AHB1ENR = AHB1_peripheral_clock::GPIOC;

    // 设置LED引脚为输出模式
    // pinMode(PC0, OUTPUT);  // PC0引脚
    // pinMode(PC1, OUTPUT);  // PC1引脚
    // pinMode(PC2, OUTPUT);  // PC2引脚
}

void loop() {

    GPIOC[0] = output_level::high;
    GPIOC[1] = output_level::low;
    GPIOC[2] = output_level::high;
    GPIOC[0].lock();
}

int main(void) {
    setup();
    while (1) 
        loop();
    
    return 0;
}