/*!
 *  \file       pwm.cpp
 *  \brief      
 *  
 */


#include "pwm.hpp"

#include <algorithm>

pwm::pwm(const int channel) : duty_cycle{0U}
{
    (void)channel;
}

pwm::~pwm()
{
}

void pwm::set_duty(const std::uint8_t duty)
{
    // Limit the duty cycle 0 ... 100
    duty_cycle = std::min<std::uint8_t>(duty, 100U);

    /*!
     *  \todo   Set the duty cycle in the PWM hardware,
     *          implement it in the future...
     */
}

std::uint8_t pwm::get_duty() const
{
    return duty_cycle;
}