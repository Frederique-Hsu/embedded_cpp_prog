/*!
 *  \file       led_port.hpp
 *  \brief      
 *  
 */


#pragma once


#include "led_base.hpp"


class led_port;

class led_port : public led_base
{
public:
    typedef std::uint8_t port_type;
    using bval_type = std::uint8_t;
public:
    led_port(const port_type p, const bval_type b);
    virtual ~led_port();
public:
    virtual void toggle() override;
private:
    const port_type port;
    const bval_type bval;
};