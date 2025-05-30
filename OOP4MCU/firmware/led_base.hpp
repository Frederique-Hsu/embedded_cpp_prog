/*!
 *  \file       led_base.hpp
 *  \brief      Design the class hierarchy for the LED objects.
 *  
 */


#pragma once


#include <cstdint>

class led_base;


class led_base
{
protected:
    // A protected default constructor
    led_base();
private:
    // Private non-implemented copy constructor
    led_base(const led_base&) = delete;
    // Private non-implemented copy assignment operator
    const led_base& operator=(const led_base&) = delete;
public:
    // virtual destructor
    virtual ~led_base();
public:
    virtual void toggle() = 0;

    bool state_is_on() const;
protected:
    bool is_on;
};