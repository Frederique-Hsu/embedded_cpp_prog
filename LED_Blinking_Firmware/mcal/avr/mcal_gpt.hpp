/*!
 *  \file       mcal_gpt.hpp
 *  \brief      
 *  
 */


#pragma once

#include <cstdint>
#include <chrono>

namespace util
{
    template<typename unsigned_tick_type> class timer;
}

namespace mcal
{
    namespace gpt
    {
        using config_type = void;
        using value_type = std::uint32_t;

        void init(const config_type*);

        class secure final
        {
        public:
            static value_type get_time_elapsed();
        private:
            friend std::chrono::high_resolution_clock::time_point std::chrono::high_resolution_clock::now() noexcept;

            template<typename unsigned_tick_type> friend class util::timer;
        };
    }
}