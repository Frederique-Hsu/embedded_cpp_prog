/*!
 *  \file       mcal_cpu.hpp
 *  \brief      
 *  
 */


#pragma once

namespace mcal
{
    namespace cpu
    {
        void init();
        void post_init();
        void nop() noexcept;
    }
}