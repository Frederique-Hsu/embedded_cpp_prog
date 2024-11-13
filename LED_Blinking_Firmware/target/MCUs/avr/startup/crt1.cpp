/*!
 *  \file       crt1.cpp
 *  \brief      
 *  
 */



#include "crt.hpp"

#include "../../../../util/utility/util_utype_helper.hpp"
#include "../../../../mcal_memory/mcal_memory_progmem_access.hpp"

extern "C"
{
    struct constructor_function_type
    {
        using pointer = void (*)(void);     // function pointer

        using size_type = util::utype_helper<sizeof(pointer) * 8U>::exact_type;

        static constexpr size_type static_size = static_cast<size_type>(sizeof(size_type));
    };

    extern constructor_function_type::pointer _ctors_end[];
    extern constructor_function_type::pointer _ctors_begin[];
}

void crt::init_ctors()
{
    auto ctors_begin_array = reinterpret_cast<constructor_function_type::size_type>(static_cast<void*>(_ctors_begin));
    auto ctors_end_array = reinterpret_cast<constructor_function_type::size_type>(static_cast<void*>(_ctors_end));

    for (constructor_function_type::size_type rom_source = ctors_end_array; 
         rom_source > ctors_begin_array; 
         rom_source -= constructor_function_type::static_size)
    {
        /*!
         *  \note   particular care needs to be taken to read the program memory
         *          with the function mcal::cpu::read_program_memory.
         */

        const constructor_function_type::size_type pf = mcal::memory::progmem::read<constructor_function_type::size_type>(
            rom_source - constructor_function_type::static_size);       // Acquire the next constructor function's address

        (reinterpret_cast<constructor_function_type::pointer>(pf))();   // Call the constructor function
    }
}
