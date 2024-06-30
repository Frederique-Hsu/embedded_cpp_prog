/*!
 *  \file       UTest4SprintfFunction.cpp
 *  \brief
 *
 */


#include <CppUTest/TestHarness.h>

TEST_GROUP(UTest4SprintfFunction)
{
    char output[100];
    const char* expected;

    void setup()
    {
        memset(output, 0xAA, sizeof(output));
        expected = "";
    }

    void teardown()
    {
    }

    void expect(const char* s)
    {
        expected = s;
    }

    void given(int charsWritten)
    {
        LONGS_EQUAL(strlen(expected), charsWritten);
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xAA, output[strlen(expected) + 1]);
    }
};

TEST(UTest4SprintfFunction, NoFormatOperations)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

TEST(UTest4SprintfFunction, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "%s\n", "Hello World"));
}
