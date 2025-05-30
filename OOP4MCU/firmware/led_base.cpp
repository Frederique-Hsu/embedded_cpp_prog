/*!
 *  \file       led.cpp
 *  \brief      
 *  
 */


#include "led_base.hpp"


led_base::led_base() : is_on{false}
{
}

led_base::~led_base()
{
}

bool led_base::state_is_on() const
{
    return is_on;
}