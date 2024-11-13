/*!
 *  \file       led.cpp
 *  \brief      
 *  
 */


#include "led.hpp"

led::led(const port_type p, const bval_type b) : port(p), bval(b)
{
    // Set the port pin value to low level
    *reinterpret_cast<volatile bval_type*>(port) &= static_cast<bval_type>(~bval);
    
    // Set the port pin direction to output
    *reinterpret_cast<volatile bval_type*>(port - 1U) |= bval;
}

void led::toggle() const
{
    // Toggle the LED
    *reinterpret_cast<volatile bval_type*>(port) ^= bval;   // C++ register access
    // *((volatile bval_type*)port) ^= bval;   // equivalent C-style register access
}