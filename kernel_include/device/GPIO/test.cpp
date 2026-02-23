#include "GPIO.h"
#include "output_speed_config.h"
#include "reuse_function_id.h"

void test222() {
    GPIOA[1] = true ;
    GPIO[1][2] = false;
    GPIOD[10] = kernel::device::GPIO::AF15::EVENTOUT;
    GPIOD[10] = kernel::device::GPIO::AF7::USART3;

    GPIOC[13] = kernel::device::GPIO::work_mode::alternate_function_push_pull;
    GPIOC[13] = kernel::device::GPIO::output_type::push_pull;
    GPIOC[13] = kernel::device::GPIO::output_speed::very_high_speed;
    GPIOC[13] = kernel::device::GPIO::pull_up_down::no_pull;
    GPIOC[13] = 0x0b1;
    GPIOC[13] = 0x0b0;
}