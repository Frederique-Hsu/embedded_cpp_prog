/*!
 *  \file       led_port.cpp
 *  \brief      
 *  
 */


#include "led_port.hpp"


led_port::led_port(const port_type p, const bval_type b) : led_base(), port{p}, bval{b}
{
}

led_port::~led_port()
{
}

void led_port::toggle()
{
    // Toggle the LED
    *reinterpret_cast<volatile bval_type*>(port) ^= bval;
    // Toggle the is_on indication flag
    is_on = !is_on;
}