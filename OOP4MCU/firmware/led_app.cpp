/*!
 *  \file       led_app.cpp
 *  \brief      
 *  
 */


#include "led_app.hpp"

#include "led_port.hpp"
#include "pwm.hpp"
#include "led_pwm.hpp"

namespace
{
    // Two LEDs on port2.0 and port2.1, simulated port LEDs
    led_port led0{static_cast<led_port::port_type>(UINT8_C(0x12)), 
                  static_cast<led_port::bval_type>(UINT8_C(1))};

    led_port led1{static_cast<led_port::port_type>(UINT8_C(0x34)),
                  static_cast<led_port::bval_type>(UINT8_C(2))};

    // Two PWMs on channels timer0 and timer1, simulated PWMs
    pwm pwm0{0};
    pwm pwm1{1};

    // Two simulated PWM LEDs
    led_pwm led2{&pwm0};
    led_pwm led3{&pwm1};
}

void led_toggler(led_base* led)
{
    /*!
     *  \remark     Use dynamic polymorphism to toggle a base class pointer
     */
    led->toggle();
}

void led_toggler(led_base& led)
{
    /*!
     *  \remark     Use dynamic polymorphism to toggle a base class reference.
     */
    led.toggle();
}

void do_something()
{
#if defined (LED_HIERARCHY)
    // Toggle LED0 -- LED3
    led0.toggle();
    led1.toggle();
    led2.toggle();
    led3.toggle();
#elif defined (DYNAMIC_POLYMORPHISM_PTR)
    led_toggler(&led0);     // Toggle an led_port
    led_toggler(&led1);     // Toggle an led_port
    led_toggler(&led2);     // Toggle an led_pwm
    led_toggler(&led3);     // toggle an led_pwm
#elif defined (DYNAMIC_POLYMORPHISM_REF)
    led_toggler(led0);
    led_toggler(led1);
    led_toggler(led2);
    led_toggler(led3);
#endif
}