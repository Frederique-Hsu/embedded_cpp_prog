/*!
 *  \file       mcal_reg.h
 *  \brief
 *  
 */


#pragma once

#include <cstdint>

namespace mcal
{
    // Compile-time constant register addresses.
    namespace reg
    {
        // The address of portb
        constexpr std::uint8_t portb = 0x25U;
        
        // The values pf bit0 through bit7
        constexpr std::uint8_t bval0 = 0b0000'0001U << 0U;
        constexpr std::uint8_t bval1 = 0b0000'0001U << 1U;
        constexpr std::uint8_t bval2 = 0b0000'0001U << 2U;
        constexpr std::uint8_t bval3 = 0b0000'0001U << 3U;
        constexpr std::uint8_t bval4 = 0b0000'0001U << 4U;
        constexpr std::uint8_t bval5 = 0b0000'0001U << 5U;
        constexpr std::uint8_t bval6 = 0b0000'0001U << 6U;
        constexpr std::uint8_t bval7 = 0b0000'0001U << 7U;
    }
}