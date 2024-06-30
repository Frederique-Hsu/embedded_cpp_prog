/*!
 *  \file       main.c
 *  \brief
 *
 */


#include "unity_fixture.h"

static void RunAllTests(void)
{
    RUN_TEST_GROUP(UTest4SprintfFunction);
}

int main(int argc, char* argv[])
{
    return UnityMain(argc, (const char**)argv, RunAllTests);
}
