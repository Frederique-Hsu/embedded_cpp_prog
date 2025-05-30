/*!
 *  \file       led_pwm.cpp
 *  \brief      
 *  
 */


#include "led_pwm.hpp"

#include "pwm.hpp"

led_pwm::led_pwm(pwm* p) : led_base(), my_pwm{p}
{
}

led_pwm::~led_pwm()
{
}

void led_pwm::toggle()
{
    // Toggle the LED with the PWM signal
    is_on = (my_pwm->get_duty() > 0U);
    my_pwm->set_duty(is_on ? 0U : 100U);

    is_on = !is_on;
}

void led_pwm::dimming(const std::uint8_t duty)
{
    my_pwm->set_duty(duty);
    is_on = (duty != 0U);
}