/*!
 *  \file       stl_container.cpp
 *  \brief      
 *  
 */


#include "stl_container.hpp"

#include <atomic>
#include <chrono>

namespace
{
    std::array<std::uint8_t, 4U> counters;
}

std::array<std::uint8_t, 4U> doMySomething()
{
    std::fill(counters.begin(), counters.end(), static_cast<std::uint8_t>(10U));
    return counters;
}

namespace
{
    volatile std::uint32_t system_tick;
}

#if false
std::uint32_t getTimeElapsed()
{
    auto value = static_cast<const volatile std::atomic<std::uint32_t>>(system_tick);
    return std::atomic_load(&value);
}
#endif


void manipulate_register()
{
    // The address of the portb register
    constexpr std::uint8_t portb = UINT8_C(0x25);

    // Switch portb.5 from low to high
    auto register_addr = reinterpret_cast<volatile std::uint8_t*>(portb);
    *register_addr |= UINT8_C(0b0010'0000);
}