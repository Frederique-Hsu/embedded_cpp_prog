/*!
 *  \file       led_pwm.hpp
 *  \brief      
 *  
 */


#pragma once


#include "led_base.hpp"

class led_pwm;
class pwm;

class led_pwm : public led_base
{
public:
    explicit led_pwm(pwm* p);
    virtual ~led_pwm();
public:
    virtual void toggle() override;

    void dimming(const std::uint8_t duty);
private:
    pwm* my_pwm;
};