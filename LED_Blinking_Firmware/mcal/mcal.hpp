/*!
 *  \file       mcal.hpp
 *  \brief      
 *  
 */


#pragma  once


#include <limits>

#include "avr/mcal_gpt.hpp"

static_assert((std::numeric_limits<mcal::gpt::value_type>::digits >= 32) &&
              (std::numeric_limits<mcal::gpt::value_type>::is_integer == true) &&
              (std::numeric_limits<mcal::gpt::value_type>::is_signed == false), 
              "The gpt value type must be an unsigned integer type, having at least 32 bits.");

namespace mcal
{
    void init();
}