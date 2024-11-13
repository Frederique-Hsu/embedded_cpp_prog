/*!
 *  \file       mcal_memory_progmem.hpp
 *  \brief      
 *  
 */


#pragma once


#include <cstdint>


#if defined(__cplusplus)
extern "C"
{
#endif

    using mcal_progmem_uintptr_t = std::uintptr_t;
    // using mcal_progmem_ptrdiff_t = std::ptrdiff_t;

    #define MCAL_PROGMEM_ADDRESSOF(x)   (mcal_progmem_uintptr_t)(&(x))

    std::uint8_t  mcal_memory_progmem_read_byte (const mcal_progmem_uintptr_t src);
    std::uint16_t mcal_memory_progmem_read_word (const mcal_progmem_uintptr_t src);
    std::uint32_t mcal_memory_progmem_read_dword(const mcal_progmem_uintptr_t src);
    std::uint64_t mcal_memory_progmem_read_qword(const mcal_progmem_uintptr_t src);

#if defined (__cplusplus)
}
#endif
