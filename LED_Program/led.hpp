/*!
 *  \file   led.hpp
 *  \brief  
 *  
 */


#pragma once


#include <cstdint>


class led
{
public:
    // Use convenient class-specific typedefs
    typedef std::uint8_t    port_type;
    typedef std::uint8_t    bval_type;
public:
    led(const port_type p, const bval_type b);
private:
    const port_type port;
    const bval_type bval;
public:
    void toggle() const;
};