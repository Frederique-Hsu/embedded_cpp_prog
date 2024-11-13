/*!
 *  \file       crt.hpp
 *  \brief      
 *  
 */


#pragma once


namespace crt
{
    void init_ram  () __attribute__((section(".startup"), used, noinline));
    void init_ctors() __attribute__((section(".startup"), used, noinline));
}