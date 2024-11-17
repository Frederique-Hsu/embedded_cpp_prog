/*!
 *  \file       test_stl_container.cpp;
 *  \brief      
 *  
 */


#include "../src/stl_container.hpp"

#include <gtest/gtest.h>
#include <string>
#include <chrono>

TEST(UTest4STLContainer, CheckArrayContainer)
{
    EXPECT_EQ(login_key.size(), 5);
    EXPECT_EQ(login_key[0], UINT8_C(0X01));
    EXPECT_EQ(login_key[4], 0x05);
}


TEST(UTest4STLContainer, CheckStlAlgorithm)
{
    auto counters = doMySomething();

    EXPECT_TRUE(counters[0] == static_cast<std::uint8_t>(10));
    EXPECT_TRUE(counters[1] == static_cast<std::uint8_t>(10));
    EXPECT_TRUE(counters[2] == static_cast<std::uint8_t>(10));
    EXPECT_TRUE(counters[3] == static_cast<std::uint8_t>(10));
}

TEST(UTest4STLContainer, CheckInnerProduct)
{
    std::array<int, 3> u{{1, 2, 3}};
    std::array<int, 3> v{{4, 5, 6}};

    auto dot_product = calculateInnerProduct<int, 3>(u, v);
    EXPECT_EQ(dot_product, 32);
}

TEST(UTest4STLContainer, CheckDigitSeparatorsAndLiterals)
{
    [[maybe_unused]] constexpr std::uint64_t one_trillion = UINT64_C(1'0000'0000'0000);

    [[maybe_unused]] constexpr std::uint8_t one = UINT8_C(0b0001);
    [[maybe_unused]] constexpr std::uint8_t seven = UINT8_C(0b0000'0111);

    float one_foot = 12.0inch;
    EXPECT_DOUBLE_EQ(one_foot, 0.3048meter);

    constexpr float basketball_player = 7.0foot;
    EXPECT_DOUBLE_EQ(basketball_player, 2.058meter);

    constexpr float football_field = 100.0yard;
    EXPECT_DOUBLE_EQ(football_field, 91.44meter);

    std::string str = "creativity";

    // std::chrono::duration<std::chrono::milliseconds> time_span{10};
}