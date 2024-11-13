/*!
 *  \file       mcal_irq.hpp
 *  \brief      
 *  
 */


#pragma once

namespace mcal
{
    namespace irq
    {
        using config_type = void;

        void init(const config_type*);

        void enable_all();
        void disable_all();
    }
}