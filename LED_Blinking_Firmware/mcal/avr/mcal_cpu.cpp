/*!
 *  \file       mcal_cpu.cpp
 *  \brief      
 *  
 */


#include "mcal_cpu.hpp"

void mcal::cpu::init()
{
}

void mcal::cpu::post_init()
{
}

void mcal::cpu::nop() noexcept
{
    asm volatile("nop");
}