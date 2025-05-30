/*!
 *  \file       main.cpp
 *  \brief      
 *  
 */


#include "led_app.hpp"

#include <cstdint>

int main(void)
{
    /*!
     *  \remark     Toggle all 4 LEDs in a loop 4 times.
     */
    for (auto i = static_cast<unsigned>(UINT8_C(0)); i < static_cast<unsigned>(UINT8_C(4)); ++i)
    {
        do_something();
    }
    return 0;
}