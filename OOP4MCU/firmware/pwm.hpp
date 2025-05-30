/*!
 *  \file       pwm.hpp
 *  \brief      
 *  
 */


#pragma once


#include <cstdint>

class pwm;

class pwm
{
public:
    explicit pwm(const int channel);
    ~pwm();
public:
    void set_duty(const std::uint8_t duty);
    std::uint8_t get_duty() const;
private:
    std::uint8_t duty_cycle;
};