/*!
 *  \file       util_utype_helper.hpp
 *  \brief      
 *  
 */


#pragma once

#include <cstdint>

namespace util
{
    template<const unsigned utype_bit_count>
    struct utype_helper
    {
        static_assert(utype_bit_count <= 64, 
                      "the bit count of unsigned type cannot exceed 64-bits.");
        
        using exact_type = std::uint64_t;
    };

    template<> struct utype_helper<0U> { using exact_type = std::uint8_t; };
    template<> struct utype_helper<1U> { using exact_type = std::uint8_t; };
    template<> struct utype_helper<2U> { using exact_type = std::uint8_t; };
    template<> struct utype_helper<3U> { using exact_type = std::uint8_t; };
    template<> struct utype_helper<4U> { using exact_type = std::uint8_t; };
    template<> struct utype_helper<5U> { using exact_type = std::uint8_t; };
    template<> struct utype_helper<6U> { using exact_type = std::uint8_t; };
    template<> struct utype_helper<7U> { using exact_type = std::uint8_t; };
    template<> struct utype_helper<8U> { using exact_type = std::uint8_t; };

    template<> struct utype_helper< 9U> { using exact_type = std::uint16_t; };
    template<> struct utype_helper<10U> { using exact_type = std::uint16_t; };
    template<> struct utype_helper<11U> { using exact_type = std::uint16_t; };
    template<> struct utype_helper<12U> { using exact_type = std::uint16_t; };
    template<> struct utype_helper<13U> { using exact_type = std::uint16_t; };
    template<> struct utype_helper<14U> { using exact_type = std::uint16_t; };
    template<> struct utype_helper<15U> { using exact_type = std::uint16_t; };
    template<> struct utype_helper<16U> { using exact_type = std::uint16_t; };

    template<> struct utype_helper<17U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<18U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<19U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<20U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<21U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<22U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<23U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<24U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<25U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<26U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<27U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<28U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<29U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<30U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<31U> { using exact_type = std::uint32_t; };
    template<> struct utype_helper<32U> { using exact_type = std::uint32_t; };
}