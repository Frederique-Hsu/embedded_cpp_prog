/*!
 *  \file       mcal_gpt.cpp
 *  \brief      
 *  
 */


#include "mcal_gpt.hpp"

#include "../mcal_reg_access.hpp"
#include "../mcal_reg_access.cpp"

#include "mcal_reg.hpp"

namespace
{
    static mcal::gpt::value_type system_tick;
}

extern "C" void __vector_16() __attribute__((signal, used, externally_visible));

extern "C" void __vector_16()
{
    system_tick += static_cast<std::uint8_t>(0x80U);
}


void mcal::gpt::init(const config_type*)
{
    // clear the timer0 overflow flag
    mcal::reg::reg_access_static<std::uint8_t, std::uint8_t, mcal::reg::tifr0, 0x01U>::reg_set();

    // enable the timer0 overflow interrupt
    mcal::reg::reg_access_static<std::uint8_t, std::uint8_t, mcal::reg::timsk0, 0x01U>::reg_set();

    // set the timer0 clock source to f_osc/8 = 2MHz, and start counting
    mcal::reg::reg_access_static<std::uint8_t, std::uint8_t, mcal::reg::tccr0b, 0x02U>::reg_set();
}

mcal::gpt::value_type mcal::gpt::secure::get_time_elapsed()
{
    using timer_address_type = std::uint8_t;
    using timer_register_type = std::uint8_t;

    // Do the first read of timer0 counter and the system tick
    const timer_register_type timer0_cnt1 = mcal::reg::reg_access_static<timer_address_type, 
                                                                         timer_register_type, 
                                                                         mcal::reg::tcnt0>::reg_get();
    const mcal::gpt::value_type sys_tick1 = system_tick;

    // Do the second read of timer0 counter
    const timer_register_type timer0_cnt2 = mcal::reg::reg_access_static<timer_address_type,
                                                                         timer_register_type,
                                                                         mcal::reg::tcnt0>::reg_get();
    // Perform the consistency check
    const mcal::gpt::value_type consistent_microsecond_tick = ((timer0_cnt2 >= timer0_cnt1) ?
                                                               mcal::gpt::value_type(sys_tick1 | std::uint8_t(timer0_cnt1 >> 1U)) :
                                                               mcal::gpt::value_type(system_tick | std::uint8_t(timer0_cnt2 >> 1U)));
    return consistent_microsecond_tick;
}
