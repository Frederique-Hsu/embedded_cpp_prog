/*!
 *  \file       mcal_memory_progmem_access.hpp
 *  \brief      
 *  
 */


#pragma once

#include <type_traits>
#include <cstdint>

#include "../mcal/avr/mcal_memory_progmem.hpp"

namespace mcal
{
namespace memory
{
namespace progmem
{
    template<typename ValueType>
    ValueType read(const mcal_progmem_uintptr_t src_addr,
                   const typename std::enable_if<(sizeof(ValueType) != 1U) &&
                                                 (sizeof(ValueType) != 2U) &&
                                                 (sizeof(ValueType) != 4U) &&
                                                 (sizeof(ValueType) != 8U)>::type* = nullptr) noexcept;

    template<typename ValueType>
    ValueType read(const mcal_progmem_uintptr_t src_addr,
                   const typename std::enable_if<sizeof(ValueType) == 1U>::type* = nullptr) noexcept;

    template<typename ValueType>
    ValueType read(const mcal_progmem_uintptr_t src_addr,
                   const typename std::enable_if<sizeof(ValueType) == 2U>::type* = nullptr) noexcept;

    template<typename ValueType>
    ValueType read(const mcal_progmem_uintptr_t src_addr,
                   const typename std::enable_if<sizeof(ValueType) == 4U>::type* = nullptr) noexcept;

    template<typename ValueType>
    ValueType read(const mcal_progmem_uintptr_t src_addr,
                   const typename std::enable_if<sizeof(ValueType) == 8U>::type* = nullptr) noexcept;
}
}
}


template<typename ValueType>
ValueType mcal::memory::progmem::read(const mcal_progmem_uintptr_t src_addr,
                                      const typename std::enable_if<sizeof(ValueType) == 1U>::type*) noexcept
{
    return mcal_memory_progmem_read_byte(src_addr);
}

template<typename ValueType>
ValueType mcal::memory::progmem::read(const mcal_progmem_uintptr_t src_addr,
                                      const typename std::enable_if<sizeof(ValueType) == 2U>::type*) noexcept
{
    return mcal_memory_progmem_read_word(src_addr);
}

template<typename ValueType>
ValueType mcal::memory::progmem::read(const mcal_progmem_uintptr_t src_addr,
                                      const typename std::enable_if<sizeof(ValueType) == 4U>::type*) noexcept
{
    return mcal_memory_progmem_read_dword(src_addr);
}

template<typename ValueType>
ValueType mcal::memory::progmem::read(const mcal_progmem_uintptr_t src_addr,
                                      const typename std::enable_if<sizeof(ValueType) == 8U>::type*) noexcept
{
    return mcal_memory_progmem_read_qword(src_addr);
}

template<typename ValueType>
ValueType mcal::memory::progmem::read(const mcal_progmem_uintptr_t src_addr,
                                      const typename std::enable_if<(sizeof(ValueType) != 1U) &&
                                                                    (sizeof(ValueType) != 2U) &&
                                                                    (sizeof(ValueType) != 4U) &&
                                                                    (sizeof(ValueType) != 8U)>::type*) noexcept
{
    using local_value_type = ValueType;
    local_value_type dest;
    for (std::size_t index = 0U; index < sizeof(ValueType); ++index)
    {
        const std::uint8_t byte = mcal_memory_progmem_read_byte(mcal_progmem_uintptr_t(src_addr + index));
        *(((std::uint8_t*)MCAL_PROGMEM_ADDRESSOF(dest)) + index) = byte;
    }
    return dest;
}
