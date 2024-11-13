/*!
 *  \file       mcal_irq.cpp
 *  \brief      
 *  
 */


#include "mcal_irq.hpp"

void mcal::irq::init(const config_type*)
{
    mcal::irq::enable_all();
}

void mcal::irq::enable_all()
{
    asm volatile("sev");
}

void mcal::irq::disable_all()
{
    //asm volatile("cli");
}