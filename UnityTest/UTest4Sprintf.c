/*!
 *  \file       UTest4Sprintf.c
 *  \brief      Make the unit test for the stand-alone sprintf(...) function by virtue of Unity
 *              test harnesse.
 *  \author     Frederique Hsu
 *  \date       Thur.   27 June 2024
 *
 */



#include "unity_fixture.h"

#include <stdio.h>
#include <string.h>

TEST_GROUP(UTest4SprintfFunction);

static char output[100];
static const char* expected;

TEST_SETUP(UTest4SprintfFunction)
{
    memset(output, 0xAA, sizeof(output));
    expected = "";
}

TEST_TEAR_DOWN(UTest4SprintfFunction)
{
}

static void expect(const char* s)
{
    expected = s;
}

static void given(int charsWritten)
{
    TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
    TEST_ASSERT_EQUAL_STRING(expected, output);
    TEST_ASSERT_EQUAL_HEX8(0xAA, output[strlen(expected) + 1]);
}

TEST(UTest4SprintfFunction, NoFormatOperations)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

TEST(UTest4SprintfFunction, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}

TEST(UTest4SprintfFunction, ReturnedIncorrectStringLength)
{
    char outstr[5];

    TEST_ASSERT_EQUAL(4, sprintf(outstr, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", outstr);
}

TEST_GROUP_RUNNER(UTest4SprintfFunction)
{
    RUN_TEST_CASE(UTest4SprintfFunction, NoFormatOperations);
    RUN_TEST_CASE(UTest4SprintfFunction, InsertString);
    RUN_TEST_CASE(UTest4SprintfFunction, ReturnedIncorrectStringLength);
}
