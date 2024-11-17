/*!
 *  \file       basic_classes_templates.hpp
 *  \brief      
 *  
 */


#pragma  once

#include <cstdint>

class point
{
public:
    std::uint8_t x_coord;
    std::uint8_t y_coord;
public:
    point(const std::uint8_t x = UINT8_C(0), const std::uint8_t y = UINT8_C(0));
public:
    std::uint16_t squared_euclidean_distance() const;
};

struct version_information
{
    static constexpr unsigned version = 3U; // a compile-time constant member variable
};


/*!
 *  \protocol   ====================================================================================
 */

template<typename short_type, typename long_type>
class Point
{
public:
    short_type x_coord;
    short_type y_coord;
public:
    Point(const short_type& x = short_type{}, const short_type& y = short_type{});
public:
    long_type squared_euclideam_distance() const;
};



/*!
 *  \implements ====================================================================================
 */

template<typename short_type, typename long_type>
Point<short_type, long_type>::Point(const short_type& x, const short_type& y) : x_coord{x}, y_coord{y}
{
}

template<typename short_type, typename long_type>
long_type Point<short_type, long_type>::squared_euclideam_distance() const
{
    const long_type x2 = long_type(x_coord) * x_coord;
    const long_type y2 = long_type(y_coord) * y_coord;
    return x2 + y2;
}

template<typename T>
T add(const T& a, const T& b)
{
    return a + b;
}