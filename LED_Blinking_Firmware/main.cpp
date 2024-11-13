/*!
 *  \file       main.cpp
 *  \brief      This file implements the main() portal function for current project.
 *  
 */


#include "led.hpp"
#include "mcal/avr/mcal_reg.hpp"
#include "mcal/mcal.hpp"
#include "util/utility/util_time.hpp"
#include "util/utility/util_time.cpp"

namespace
{
    using timer_type = util::timer<std::uint16_t>;

#if (LED_DEFINITION == STANDALONE_LED_CLASS)
    auto led_b5 = led{mcal::reg::portb, mcal::reg::bval5};
#elif (LED_DEFINITION == EFFICIENT_LED_TEMPLATE)
    const led_template<std::uint8_t, std::uint8_t, mcal::reg::portb, mcal::reg::bval5> led_b5;
#endif
}

int main(void)
{
    /* Initialize the microcontroller abstract layer. */
    mcal::init();

    // Toggle the led_b5 object in a infinite-loop
    while (true)
    {
        led_b5.toggle();

        // wait 1 second in a blocking delay
        timer_type::blocking_delay(timer_type::seconds(1U));
    }
    return 0;
}