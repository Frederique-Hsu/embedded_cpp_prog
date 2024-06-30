/*!
 *  \file       main.c
 *  \brief      Perform the unit test for embedded LED Driver.
 *
 */


#include "../unity.test.framework/extras/fixture/unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(UTest4LedDriver);
}

int main(int argc, char* argv[])
{
    return UnityMain(argc, (const char**)argv, RunAllTests);
}
