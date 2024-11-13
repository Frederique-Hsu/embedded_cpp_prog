/*!
 *  \file       crt0_init_ram.cpp
 *  \brief      
 *  
 */


#include "crt.hpp"

#include <cstdint>
#include <algorithm>

#include "../../../../mcal_memory/mcal_memory_progmem_access.hpp"

extern "C"
{
    extern mcal_progmem_uintptr_t   _rom_data_begin;    // start address for the initialization values of the ROM-to-RAM section.
    extern std::uintptr_t           _data_begin;        // start address for the .data section
    extern std::uintptr_t           _data_end;          // end address for the .data section
    extern std::uintptr_t           _bss_begin;         // start address for the .bss section
    extern std::uintptr_t           _bss_end;           // end address for the .bss section
}

void crt::init_ram()
{
    using memory_aligned_type = std::uint16_t;

    /*!
     *  \note   Copy the data segment initializers from ROM to RAM.
     *          Note that all data segments are aligned by 2 bytes
     */
    [[maybe_unused]] const std::size_t size_data = std::size_t(
        static_cast<const memory_aligned_type*>(static_cast<const void*>(&_data_end)) - 
        static_cast<const memory_aligned_type*>(static_cast<const void*>(&_data_begin))
    );

    mcal_progmem_uintptr_t rom_source = 
        reinterpret_cast<mcal_progmem_uintptr_t>(static_cast<void*>(&_rom_data_begin));

    std::for_each(static_cast<memory_aligned_type*>(static_cast<void*>(&_data_begin)),
                  static_cast<memory_aligned_type*>(static_cast<void*>(&_data_end)),
                  [&rom_source](memory_aligned_type& ram_destination) 
                  {
                    /*!
                     *  \note   copy the data from the rom-source to ram-destination
                     */
                    ram_destination = mcal::memory::progmem::read<std::uint16_t>(rom_source);
                    rom_source += 2U;   // Acquire the next 16-bit address of rom-source
                  });

    /*!
     *  \note   Clear the bss segment, note that the bss segment is aligned by 2 bytes
     */
    std::fill(static_cast<memory_aligned_type*>(static_cast<void*>(&_bss_begin)),
              static_cast<memory_aligned_type*>(static_cast<void*>(&_bss_end)),
              static_cast<memory_aligned_type>(0U));
}
