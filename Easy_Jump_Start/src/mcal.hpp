/*!
 *  \file       mcal.hpp
 *  \brief      micro-controller abstraction layer
 *  
 */


#pragma once


#include <cstdint>

namespace mcal      // Namespace for the micro-controller abstraction layer.
{
    void init();    // the mcal initialization

    namespace gpt   // The general purpose timer stuff inside the mcal
    {
        void init();
        std::uint32_t get_time_elapsed();
    }

    namespace adc   // The ADC stuff inside the mcal
    {
        void init();
        std::uint16_t read_value(const unsigned);
    }
}