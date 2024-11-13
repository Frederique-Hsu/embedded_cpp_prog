/*!
 *  \file       mcal.cpp
 *  \brief      
 *  
 */


#include "mcal.hpp"

#include "avr/mcal_cpu.hpp"
#include "avr/mcal_irq.hpp"

void mcal::init()
{
    mcal::irq::init(nullptr);
    mcal::gpt::init(nullptr);
    mcal::cpu::post_init();
}