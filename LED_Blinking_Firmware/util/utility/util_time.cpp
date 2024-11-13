/*!
 *  \file       util_time.cpp
 *  \brief      
 *  
 */


#include "util_time.hpp"

#include "../../mcal/avr/mcal_cpu.hpp"

namespace util
{
    template<typename unsigned_tick_type>
    const unsigned_tick_type timer<unsigned_tick_type>::timer_mask = static_cast<unsigned_tick_type>(
        (UINTMAX_C(1) << (std::numeric_limits<unsigned_tick_type>::digits - 1)) - UINTMAX_C(1)
    );

    template<typename unsigned_tick_type>
    typename timer<unsigned_tick_type>::tick_type timer<unsigned_tick_type>::my_now()
    {
        return static_cast<tick_type>(mcal::gpt::secure::get_time_elapsed());
    }

    template<typename unsinged_tick_type>
    timer<unsinged_tick_type>::timer() : my_tick{0U}
    {
    }

    template<typename unsigned_tick_type>
    timer<unsigned_tick_type>::timer(const typename timer<unsigned_tick_type>::tick_type& tick_value) 
        : my_tick(my_now() + tick_value)
    {
    }

    template<typename unsigned_tick_type>
    timer<unsigned_tick_type>::timer(const timer& rhs) : my_tick{rhs.my_tick}
    {
    }

    template<typename unsigned_tick_type>
    timer<unsigned_tick_type>& timer<unsigned_tick_type>::operator=(const timer& rhs)
    {
        if (this != &rhs)
        {
            my_tick = rhs.my_tick;
        }
        return *this;
    }

    template<typename unsigned_tick_type>
    bool timer<unsigned_tick_type>::timeout() const
    {
        const tick_type delta = my_now() - my_tick;
        return (delta <= timer_mask);
    }

    template<typename unsigned_tick_type>
    void timer<unsigned_tick_type>::blocking_delay(const tick_type& delay)
    {
        const timer<unsigned_tick_type> t_delay(delay);
        while (false == t_delay.timeout())
        {
            mcal::cpu::nop();
        }
    }

    template<typename unsigned_tick_type> template<typename other_tick_type>
    typename timer<unsigned_tick_type>::tick_type timer<unsigned_tick_type>::microseconds(
        const other_tick_type value_microseconds)
    {
        return static_cast<tick_type>(value_microseconds);
    }

    template<typename unsigned_tick_type> template<typename other_tick_type>
    typename timer<unsigned_tick_type>::tick_type timer<unsigned_tick_type>::milliseconds(
        const other_tick_type value_milliseconds)
    {
        return (1000UL) * microseconds(value_milliseconds);
    }

    template<typename unsigned_tick_type> template<typename other_tick_type>
    typename timer<unsigned_tick_type>::tick_type timer<unsigned_tick_type>::seconds(
        const other_tick_type value_seconds)
    {
        return (1000UL) * milliseconds(value_seconds);
    }

    template<typename unsigned_tick_type> template<typename other_tick_type>
    typename timer<unsigned_tick_type>::tick_type timer<unsigned_tick_type>::minutes(
        const other_tick_type value_minutes)
    {
        return (60UL) * seconds(value_minutes);
    }

    template<typename unsigned_tick_type> template<typename other_tick_type>
    typename timer<unsigned_tick_type>::tick_type timer<unsigned_tick_type>::hours(
        const other_tick_type value_hours)
    {
        return (60UL) * minutes(value_hours);
    }

    template<typename unsigned_tick_type> template<typename other_tick_type>
    typename timer<unsigned_tick_type>::tick_type timer<unsigned_tick_type>::days(
        const other_tick_type value_days)
    {
        return (24UL) * hours(value_days);
    }

    template<typename unsigned_tick_type> template<typename other_tick_type>
    typename timer<unsigned_tick_type>::tick_type timer<unsigned_tick_type>::weeks(
        const other_tick_type value_weeks)
    {
        return (7UL) * days(value_weeks);
    }
}