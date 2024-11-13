/*!
 *  \file       led.cpp
 *  \brief      Implement the class led
 *  
 */


#include "led.hpp"

#if (LED_DEFINITION == STANDALONE_LED_CLASS)
    led::led(const port_type p, const bval_type b) : port{p}, bval{b}
    {
        // Set the port pin value to low
        *reinterpret_cast<volatile bval_type*>(port) &= static_cast<bval_type>(~bval);

        /* Set the port pin direction to output.
        * 
        * Note that the address of the port direction register is one less than 
        * the address of the port value register.
        *
        */
        const auto pdir = static_cast<port_type>(port - 1U);
        *reinterpret_cast<volatile bval_type*>(pdir) |= bval;
    }

    void led::toggle() const
    {
        // Toggle the LED via direct memory access
        *reinterpret_cast<volatile bval_type*>(port) ^= bval;
    }
#endif