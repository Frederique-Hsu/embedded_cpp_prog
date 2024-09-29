/*!
 *  \file       main.cpp
 *  \brief      
 *  
 */


#include "led.hpp"

#include "mcal_reg.h"


namespace
{
    const led led_b5{mcal::reg::portb,      // the address of portb
                     mcal::reg::bval5};     // the bit-value of portb.5 (1 << 5)
}

int main()
{
    // Toggle led_b5 in an infinite loop
    while (true)
    {
        led_b5.toggle();
    }
    return 0;
}