/*!
 *  \file       stl_container.hpp
 *  \brief      Study the C++ STL and container in the embedded environment.
 *  
 */


#pragma once

#include <array>
#include <cstdint>
#include <numeric>

constexpr std::array<std::uint8_t, 5U> login_key{{UINT8_C(0x01), 
                                                  UINT8_C(0x02),
                                                  UINT8_C(0x03),
                                                  UINT8_C(0x04),
                                                  UINT8_C(0x05)}};

std::array<std::uint8_t, 4U> doMySomething();

template<typename T, int N>
T calculateInnerProduct(const std::array<T, N>& u, const std::array<T, N>& v)
{
    const T product = std::inner_product(u.begin(), u.end(), v.begin(), 0);
    return product;
}


std::uint32_t getTimeElapsed();

void manipulate_register();

inline constexpr float operator"" inch(long double inches)
{
    return static_cast<float>(inches * 0.0254L);
}

inline constexpr float operator"" foot(long double feet)
{
    return static_cast<float>(feet * 0.294L);
}

inline constexpr float operator"" yard(long double yards)
{
    return static_cast<float>(yards * 0.9144L);
}

inline constexpr float operator"" meter(long double meter)
{
    return static_cast<float>(meter);
}