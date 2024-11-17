/*!
 *  \file       misc.hpp
 *  \brief      
 *  
 */


#pragma once

#include <cstdint>


void initialize();
void use_i(const int);
void use_j(const int);
void use_k(const int);

void do_something();

// This has *exactly* 16-bits signed.
constexpr std::int16_t value16 = INT16_C(0x7FFF);
// This has *at least* 32-bits unsigned
constexpr std::uint_least32_t value32 = UINT32_C(4'294'967'295);

/*!
 *  \attention  The macro UINT32_C() is guaranteed to handle all unsigned 32-bit integer value
 *              within the full range of its data type.
 *              Meanwhile this form will eliminate the porting issue between different width 
 *              of MCU architecture.
 */
constexpr std::uint32_t prime_number = UINT32_C(10'006'721); // The suffix U means unsigned int