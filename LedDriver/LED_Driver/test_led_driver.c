/*!
 *  \file       test_led_driver.c
 *  \brief
 *
 */


#include "../../unity.test.framework/extras/fixture/unity_fixture.h"

#include "led_driver.h"
#include "../mocks/RuntimeErrorStub.h"


TEST_GROUP(UTest4LedDriver);

static uint16_t virtualLeds;

TEST_SETUP(UTest4LedDriver)
{
    LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(UTest4LedDriver)
{
}

TEST(UTest4LedDriver, LedsOffAfterCreate)
{
    uint16_t virtualLeds = 0xFFFF;
    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);
}

TEST(UTest4LedDriver, TurnOnLedOne)
{
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtualLeds);
}

TEST(UTest4LedDriver, TurnOffLedOne)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);
}

TEST(UTest4LedDriver, TurnOnMultipleLeds)
{
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);

    TEST_ASSERT_EQUAL_HEX16(0x0180, virtualLeds);
}

TEST(UTest4LedDriver, TurnOffAnyLed)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);

    TEST_ASSERT_EQUAL_HEX16(0b1111111101111111, virtualLeds);
}

TEST(UTest4LedDriver, AllOn)
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

TEST(UTest4LedDriver, LedMemeoryIsNotReadable)
{
    virtualLeds = 0xFFFF;
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x0080, virtualLeds);
}

TEST(UTest4LedDriver, UpperAndLowerBounds)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}

TEST(UTest4LedDriver, OutOfBoundsTurnOnDoesNoHarm)
{
    LedDriver_TurnOn(-1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);

    LedDriver_TurnOn(0);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
    LedDriver_TurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
    LedDriver_TurnOn(33);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);

    LedDriver_TurnOn(3141);

    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);
}

TEST(UTest4LedDriver, OutofBoundsTurnOffDoesNoHarm)
{
    LedDriver_TurnAllOn();

    LedDriver_TurnOff(-1);
    LedDriver_TurnOff(0);
    LedDriver_TurnOff(17);
    LedDriver_TurnOff(4276);

    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

TEST(UTest4LedDriver, OutOfBoundsProducesRuntimeError)
{
    LedDriver_TurnOn(-1);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
    TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

IGNORE_TEST(UTest4LedDriver, OutOfBoundsToDo)
{
    /*!
     *  \todo   what should we do during runtime?
     */
}

TEST(UTest4LedDriver, IsOn)
{
    TEST_ASSERT_FALSE(LedDriver_IsOn(11));
    LedDriver_TurnOn(11);
    TEST_ASSERT_TRUE(LedDriver_IsOn(11));
}

TEST(UTest4LedDriver, OutOfBoundsLedsAreAlwaysOff)
{
    TEST_ASSERT_FALSE(LedDriver_IsOn(0));
    TEST_ASSERT_FALSE(LedDriver_IsOn(17));
    TEST_ASSERT_TRUE(LedDriver_IsOff(0));
    TEST_ASSERT_TRUE(LedDriver_IsOff(17));
}

TEST(UTest4LedDriver, IsOff)
{
    TEST_ASSERT_TRUE(LedDriver_IsOff(12));
    LedDriver_TurnOn(12);
    TEST_ASSERT_FALSE(LedDriver_IsOff(12));
}

TEST(UTest4LedDriver, TurnOffMultipleLeds)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(9);
    LedDriver_TurnOff(8);

    TEST_ASSERT_EQUAL_HEX16((~0x0180) & 0xFFFF, virtualLeds);
}

TEST(UTest4LedDriver, AllOff)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnAllOff();
    TEST_ASSERT_EQUAL_HEX16(0x00, virtualLeds);
}

TEST_GROUP_RUNNER(UTest4LedDriver)
{
    RUN_TEST_CASE(UTest4LedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(UTest4LedDriver, TurnOnLedOne);
    RUN_TEST_CASE(UTest4LedDriver, TurnOffLedOne);
    RUN_TEST_CASE(UTest4LedDriver, TurnOnMultipleLeds);
    RUN_TEST_CASE(UTest4LedDriver, TurnOffAnyLed);
    RUN_TEST_CASE(UTest4LedDriver, AllOn);
    RUN_TEST_CASE(UTest4LedDriver, LedMemeoryIsNotReadable);
    RUN_TEST_CASE(UTest4LedDriver, UpperAndLowerBounds);
    RUN_TEST_CASE(UTest4LedDriver, OutOfBoundsTurnOnDoesNoHarm);
    RUN_TEST_CASE(UTest4LedDriver, OutofBoundsTurnOffDoesNoHarm);
    RUN_TEST_CASE(UTest4LedDriver, OutOfBoundsProducesRuntimeError);
    RUN_TEST_CASE(UTest4LedDriver, OutOfBoundsToDo);
    RUN_TEST_CASE(UTest4LedDriver, IsOn);
    RUN_TEST_CASE(UTest4LedDriver, OutOfBoundsLedsAreAlwaysOff);
    RUN_TEST_CASE(UTest4LedDriver, IsOff);
    RUN_TEST_CASE(UTest4LedDriver, TurnOffMultipleLeds);
    RUN_TEST_CASE(UTest4LedDriver, AllOff);
}
