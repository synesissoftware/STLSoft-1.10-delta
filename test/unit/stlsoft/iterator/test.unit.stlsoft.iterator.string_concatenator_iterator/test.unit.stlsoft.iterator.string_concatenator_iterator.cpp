/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.iterator.string_concatenator_iterator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.iterator.string_concatenator_iterator project.
 *
 * Created:     17th June 2010
 * Updated:     31st July 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define _SCL_SECURE_NO_WARNINGS

#include <stlsoft/iterator/string_concatenator_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2(void);
    static void test_1_3(void);
    static void test_1_4(void);
    static void test_1_5(void);
    static void test_1_6(void);
    static void test_1_7(void);
    static void test_1_8(void);
    static void test_1_9(void);

    static void test_1_10(void);
    static void test_1_11(void);
    static void test_1_12(void);
    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.iterator.string_concatenator_iterator", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);

        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{
    typedef char                            char_t;
    typedef std::basic_string<char_t>       string_t;


static void test_1_0(void)
{
    char const* const strings[] =
    {
            ""
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|"));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", r);
}

static void test_1_1(void)
{
    char const* const strings[] =
    {
            "a"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|"));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", r);
}

static void test_1_2(void)
{
    char const* const strings[] =
    {
            "a"
        ,   "b"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|"));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b", r);
}

static void test_1_3(void)
{
    char const* const strings[] =
    {
            "a"
        ,   "b"
        ,   "c"
        ,   "d"
        ,   "e"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|"));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c|d|e", r);
}

static void test_1_4(void)
{
    char const* const strings[] =
    {
            "a"
        ,   "b"
        ,   ""
        ,   ""
        ,   "e"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|"));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|e", r);
}

static void test_1_5(void)
{
    char const* const strings[] =
    {
            ""
        ,   ""
        ,   "c"
        ,   "d"
        ,   "e"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|"));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("c|d|e", r);
}

static void test_1_6(void)
{
    char const* const strings[] =
    {
            "a"
        ,   "b"
        ,   "c"
        ,   ""
        ,   ""
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|"));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c", r);
}

static void test_1_7(void)
{
    char const* const strings[] =
    {
            ""
        ,   "b"
        ,   "c"
        ,   "d"
        ,   ""
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|"));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("b|c|d", r);
}

static void test_1_8(void)
{
}

static void test_1_9(void)
{
}


static void test_1_10(void)
{
    char const* const strings[] =
    {
            ""
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|", 1));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", r);
}

static void test_1_11(void)
{
    char const* const strings[] =
    {
            "a"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|", 1));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", r);
}

static void test_1_12(void)
{
    char const* const strings[] =
    {
            "a"
        ,   "b"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|", 1));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b", r);
}

static void test_1_13(void)
{
    char const* const strings[] =
    {
            "a"
        ,   "b"
        ,   "c"
        ,   "d"
        ,   "e"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|", 1));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c|d|e", r);
}

static void test_1_14(void)
{
    char const* const strings[] =
    {
            "a"
        ,   "b"
        ,   ""
        ,   ""
        ,   "e"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|", 1));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|||e", r);
}

static void test_1_15(void)
{
    char const* const strings[] =
    {
            ""
        ,   ""
        ,   "c"
        ,   "d"
        ,   "e"
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|", 1));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("||c|d|e", r);
}

static void test_1_16(void)
{
    char const* const strings[] =
    {
            "a"
        ,   "b"
        ,   "c"
        ,   ""
        ,   ""
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|", 1));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c||", r);
}

static void test_1_17(void)
{
    char const* const strings[] =
    {
            ""
        ,   "b"
        ,   "c"
        ,   "d"
        ,   ""
    };

    string_t r;

    std::copy(  &strings[0], &strings[0] + STLSOFT_NUM_ELEMENTS(strings)
                        ,   stlsoft::string_concatenator(r, "|", 1));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|b|c|d|", r);
}

static void test_1_18(void)
{
}

static void test_1_19(void)
{
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
