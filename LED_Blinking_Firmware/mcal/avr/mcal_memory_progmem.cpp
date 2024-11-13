/*!
 *  \file       mcal_memory_progmem.cpp
 *  \brief      
 *  
 */


#include "mcal_memory_progmem.hpp"

#include <avr/pgmspace.h>

#if defined(__cplusplus)
extern "C"
{
#endif

    std::uint8_t  mcal_memory_progmem_read_byte(const mcal_progmem_uintptr_t src)
    {
        return pgm_read_byte(src);
    }

    std::uint16_t mcal_memory_progmem_read_word(const mcal_progmem_uintptr_t src)
    {
        return pgm_read_word(src);
    }

    std::uint32_t mcal_memory_progmem_read_dword(const mcal_progmem_uintptr_t src)
    {
        return pgm_read_dword(src);
    }

    std::uint64_t mcal_memory_progmem_read_qword(const mcal_progmem_uintptr_t src)
    {
        std::uint64_t dest;
        *((std::uint8_t*)(&dest) + 0U) = pgm_read_byte(src + 0U);
        *((std::uint8_t*)(&dest) + 1U) = pgm_read_byte(src + 1U);
        *((std::uint8_t*)(&dest) + 2U) = pgm_read_byte(src + 2U);
        *((std::uint8_t*)(&dest) + 3U) = pgm_read_byte(src + 3U);
        *((std::uint8_t*)(&dest) + 4U) = pgm_read_byte(src + 4U);
        *((std::uint8_t*)(&dest) + 5U) = pgm_read_byte(src + 5U);
        *((std::uint8_t*)(&dest) + 6U) = pgm_read_byte(src + 6U);
        *((std::uint8_t*)(&dest) + 7U) = pgm_read_byte(src + 7U);
        return dest;
    }

#if defined (__cplusplus)
}
#endif
