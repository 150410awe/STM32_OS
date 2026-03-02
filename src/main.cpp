#include "../include_set.h"

using namespace kernel::device::RCC;
using namespace kernel::device::GPIO;

void delay(volatile unsigned int ms) {
    volatile unsigned int count;
    while (ms--) 
        for (count = 0; count < 1680; count++);  // 约1ms @ 168MHz
}

void setup() {
    // 使能GPIOC时钟
    AHB1ENR = AHB1_peripheral_clock::GPIOC;
    
    // 设置PC0, PC1, PC2为输出模式
    GPIOC[0] = work_mode::output;
    GPIOC[1] = work_mode::output;
    GPIOC[2] = work_mode::output;
    
    // 设置输出类型为推挽
    GPIOC[0] = output_type::push_pull;
    GPIOC[1] = output_type::push_pull;
    GPIOC[2] = output_type::push_pull;
    
    // 设置无上拉/下拉
    GPIOC[0] = pull_up_down::no_pull;
    GPIOC[1] = pull_up_down::no_pull;
    GPIOC[2] = pull_up_down::no_pull;
    
    // 设置输出速度为低速
    GPIOC[0] = output_speed::low_speed;
    GPIOC[1] = output_speed::low_speed;
    GPIOC[2] = output_speed::low_speed;
}

void loop() {
    // 点亮LED（输出高电平）
    GPIOC[0] = output_level::high;
    GPIOC[1] = output_level::high;
    GPIOC[2] = output_level::high;
    delay(1000);
    
    // 熄灭LED（输出低电平）
    GPIOC[0] = output_level::low;
    GPIOC[1] = output_level::low;
    GPIOC[2] = output_level::low;
    delay(1000);
}

int main(void) {
    setup();

    while (1) 
        loop();
    

    return 0;
}
