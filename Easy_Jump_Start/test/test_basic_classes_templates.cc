/*!
 *  \file       test_basic_classes_templates.cc
 *  \brief      Make the unit test for basic classes and templates in the embeeded C++ environment.
 *  
 */


#include "../src/basic_classes_templates.hpp"

#include <gtest/gtest.h>

#include <limits>


TEST(UTest4BasicClassesTemplates, CheckThePointClass)
{
    point p1;
    point p2{UINT8_C(31), UINT8_C(47)};

    std::uint16_t d1 = p1.squared_euclidean_distance();
    EXPECT_EQ(d1, 0);

    std::uint16_t d2 = p2.squared_euclidean_distance();
    EXPECT_EQ(d2, 3170);

    Point<std::int16_t, std::int32_t> pt{INT16_C(-2129), INT32_C(+5471)};
    std::int32_t distance = pt.squared_euclideam_distance();
    EXPECT_EQ(distance, 3446'4482);
}

TEST(UTest4BasicClassesTemplates, CheckLimits)
{
    // n_dig should be 31 on a system with 4 byte int.
    // the sign bit is not included in digits.
    constexpr int n_dig = std::numeric_limits<int>::digits;
    EXPECT_EQ(n_dig, 31);

    constexpr int n_max = std::numeric_limits<int>::max();
    EXPECT_EQ(n_max, 0b0111'1111'1111'1111'1111'1111'1111'1111);

    // Compile-time check whether float conforms to IEEE-754 standard.
    static_assert(std::numeric_limits<float>::is_iec559, "float is not IEEE-754 conforming");
}