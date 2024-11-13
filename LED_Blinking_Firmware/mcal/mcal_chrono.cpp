/*!
 *  \file       mcal_chrono.cpp
 *  \brief      
 *  
 */


#include <chrono>

#include "avr/mcal_gpt.hpp"

/*!
 *  \note   Implement the std::chrono::high_resolution_clock::now() utility
 *          for the standard library's high-resolution clock.
 */
namespace std
{
    namespace chrono
    {
        high_resolution_clock::time_point high_resolution_clock::now() noexcept
        {
            // The source of the high-resolution clock is microseconds
            using microsecond_time_point_type = std::chrono::time_point<high_resolution_clock,
                                                                        std::chrono::microseconds>;
            
            // Get the consistent system tick (having microsecond resolution)
            const mcal::gpt::value_type microsecond_tick = mcal::gpt::secure::get_time_elapsed();
            // Obtain a time-point with microsecond resolution
            const auto time_point_in_microseconds = 
                microsecond_time_point_type(std::chrono::microseconds(microsecond_tick));
            // return the corresponding duration with microsecond resolution.
            return time_point_cast<duration>(time_point_in_microseconds);
        }
    }
}