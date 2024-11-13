/*!
 *  \file       util_time.hpp
 *  \brief      
 *  
 */


#pragma once

#include <limits>

#include "../../mcal/avr/mcal_gpt.hpp"

namespace util
{
    template<typename unsigned_tick_type>
    class timer
    {
    public:
        using tick_type = unsigned_tick_type;

        static_assert(std::numeric_limits<tick_type>::is_signed == false, 
                      "the timer tick_type must be unsigned");
        static_assert(std::numeric_limits<tick_type>::digits <= std::numeric_limits<mcal::gpt::value_type>::digits,
                      "The width of the timer tick_type cannot exceed the width of mcal::gpt::value_type");
    private:
        static const tick_type timer_mask;
    public:
        timer();
        timer(const tick_type& tick_value);
        timer(const timer& rhs);
        timer& operator=(const timer& rhs);
    private:
        tick_type my_tick;
    public:
        bool timeout() const;

        static void blocking_delay(const tick_type& delay);

        template<typename other_tick_type> static tick_type microseconds(const other_tick_type value_microseconds);     // 微妙
        template<typename other_tick_type> static tick_type milliseconds(const other_tick_type value_milliseconds);     // 毫秒
        template<typename other_tick_type> static tick_type seconds(const other_tick_type value_seconds);
        template<typename other_tick_type> static tick_type minutes(const other_tick_type value_minutes);
        template<typename other_tick_type> static tick_type hours(const other_tick_type value_hours);
        template<typename other_tick_type> static tick_type days (const other_tick_type value_days);
        template<typename other_tick_type> static tick_type weeks(const other_tick_type value_weeks);
    private:
        static tick_type my_now();
    };
}