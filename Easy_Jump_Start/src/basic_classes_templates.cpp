/*!
 *  \file       basic_classes_templates.cpp
 *  \brief      
 *  
 */


#include "basic_classes_templates.hpp"

#include <array>
#include <limits>

point::point(const std::uint8_t x, const std::uint8_t y) : x_coord{x}, y_coord{y}
{
}

std::uint16_t point::squared_euclidean_distance() const
{
    const std::uint16_t square_x = std::uint16_t(x_coord) * x_coord;
    const std::uint16_t square_y = std::uint16_t(y_coord) * y_coord;

    return square_x + square_y;
}

/*!
 *  \section    Generalized constant expressions with constexpr
 */

constexpr unsigned int version = 3U;
constexpr float pi = 3.1415926'5358'9793'2384F;

constexpr int three()   // A compile-time constant function of low complexity
{
    return 3;
}

static constexpr std::array<int, 3U> my_array{{1, 2, 3}};   // a constant array of integers

static_assert(version >= 2U, "Version is too low!");

bool checkIntDigits()
{
    constexpr int n_dig = std::numeric_limits<int>::digits;
    return (n_dig == 31);
}

bool checkIntMax()
{
    static_assert(std::numeric_limits<float>::is_iec559,
                  "float is not IEEE-754 conforming!");
    constexpr int n_max = std::numeric_limits<int>::max();
    return n_max == 0x7FFF'FFFF;
}