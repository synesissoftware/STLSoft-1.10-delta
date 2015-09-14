/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.conversion.string_to_integer.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.conversion.string_to_integer project.
 *
 * Created:     18th November 2008
 * Updated:     30th August 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define STLSOFT_MINIMUM_SAS_INCLUDES
#include <stlsoft/conversion/string_to_integer.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xCover Header Files */
#ifdef STLSOFT_USE_XCOVER
# include <xcover/xcover.h>
#endif /* STLSOFT_USE_XCOVER */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 */

#ifdef STLSOFT_COMPILER_IS_BORLAND
# undef NULL
# define NULL   0
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_specialisations_1(void);
    static void test_specialisations_2(void);
    static void test_0(void);
    static void test_positives_implicit(void);
    static void test_positives_explicit(void);
    static void test_negatives(void);
    static void test_bad(void);
    static void test_spaces(void);
    static void test_len_spaces(void);
    static void test_trailing(void);
    static void test_len_trailing(void);
    static void test_len_truncated(void);
    static void test_increasing_length(void);
    static void test_1_10(void);
    static void test_decimal_leading_plus(void);
    static void test_1_12(void);
    static void test_endptr(void);
    static void test_1_14(void);
    static void test_hexadecimal_1(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);

    static void test_try_1_int(void);
    static void test_try_2_int(void);
    static void test_try_3_int(void);
    static void test_try_4_int(void);
    static void test_try_5_int(void);
    static void test_try_6_int(void);
    static void test_try_7_int(void);
    static void test_try_8_int(void);
    static void test_try_9_int(void);
    static void test_try_10_int(void);

    static void test_try_1_uint64(void);
    static void test_try_2_uint64(void);
    static void test_try_3_uint64(void);
    static void test_try_4_uint64(void);
    static void test_try_5_uint64(void);
    static void test_try_6_uint64(void);
    static void test_try_7_uint64(void);
    static void test_try_8_uint64(void);
    static void test_try_9_uint64(void);
    static void test_try_10_uint64(void);

    static void test_try_hex_1_int(void);
    static void test_try_hex_2_int(void);
    static void test_try_hex_3_int(void);
    static void test_try_hex_4_int(void);
    static void test_try_hex_5_int(void);
    static void test_try_hex_6_int(void);
    static void test_try_hex_7_int(void);
    static void test_try_hex_8_int(void);
    static void test_try_hex_9_int(void);
    static void test_try_hex_10_int(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.conversion.string_to_integer", verbosity))
    {
        XTESTS_RUN_CASE(test_specialisations_1);
        XTESTS_RUN_CASE(test_specialisations_2);
        XTESTS_RUN_CASE(test_0);
        XTESTS_RUN_CASE(test_positives_implicit);
        XTESTS_RUN_CASE(test_positives_explicit);
        XTESTS_RUN_CASE(test_negatives);
        XTESTS_RUN_CASE(test_bad);
        XTESTS_RUN_CASE(test_spaces);
        XTESTS_RUN_CASE(test_len_spaces);
        XTESTS_RUN_CASE(test_trailing);
        XTESTS_RUN_CASE(test_len_trailing);
        XTESTS_RUN_CASE(test_len_truncated);
        XTESTS_RUN_CASE(test_increasing_length);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_decimal_leading_plus);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_endptr);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_hexadecimal_1);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

        XTESTS_RUN_CASE(test_try_1_int);
        XTESTS_RUN_CASE(test_try_2_int);
        XTESTS_RUN_CASE(test_try_3_int);
        XTESTS_RUN_CASE(test_try_4_int);
        XTESTS_RUN_CASE(test_try_5_int);
        XTESTS_RUN_CASE(test_try_6_int);
        XTESTS_RUN_CASE(test_try_7_int);
        XTESTS_RUN_CASE(test_try_8_int);
        XTESTS_RUN_CASE(test_try_9_int);
        XTESTS_RUN_CASE(test_try_10_int);

        XTESTS_RUN_CASE(test_try_1_uint64);
        XTESTS_RUN_CASE(test_try_2_uint64);
        XTESTS_RUN_CASE(test_try_3_uint64);
        XTESTS_RUN_CASE(test_try_4_uint64);
        XTESTS_RUN_CASE(test_try_5_uint64);
        XTESTS_RUN_CASE(test_try_6_uint64);
        XTESTS_RUN_CASE(test_try_7_uint64);
        XTESTS_RUN_CASE(test_try_8_uint64);
        XTESTS_RUN_CASE(test_try_9_uint64);
        XTESTS_RUN_CASE(test_try_10_uint64);

        XTESTS_RUN_CASE(test_try_hex_1_int);
        XTESTS_RUN_CASE(test_try_hex_2_int);
        XTESTS_RUN_CASE(test_try_hex_3_int);
        XTESTS_RUN_CASE(test_try_hex_4_int);
        XTESTS_RUN_CASE(test_try_hex_5_int);
        XTESTS_RUN_CASE(test_try_hex_6_int);
        XTESTS_RUN_CASE(test_try_hex_7_int);
        XTESTS_RUN_CASE(test_try_hex_8_int);
        XTESTS_RUN_CASE(test_try_hex_9_int);
        XTESTS_RUN_CASE(test_try_hex_10_int);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/string_to_integer.hpp", NULL);
#endif /* STLSOFT_USE_XCOVER */

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
    using stlsoft::sint64_t;
    using stlsoft::uint64_t;


static void test_specialisations_1()
{
    {
        stlsoft::string_to_integer( "0", static_cast<char const**>(0));
    }
    {
        stlsoft::string_to_integer(L"0", static_cast<wchar_t const**>(0));
    }


    {
        char const* endptr;
        stlsoft::string_to_integer( "0", &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", endptr - 1);
    }
    {
        wchar_t const* endptr;
        stlsoft::string_to_integer(L"0", &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"0", endptr - 1);
    }


    {
        char const* endptr;
        stlsoft::string_to_integer( "0", 1u, &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", endptr - 1);
    }
    {
        wchar_t const* endptr;
        stlsoft::string_to_integer(L"0", 1u, &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"0", endptr - 1);
    }


    {
        char const* endptr;
        stlsoft::string_to_integer( "0", 1, &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", endptr - 1);
    }
    {
        wchar_t const* endptr;
        stlsoft::string_to_integer(L"0", 1, &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"0", endptr - 1);
    }


    {
        char const* endptr;
        stlsoft::string_to_integer( "0", 0, &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", endptr);
    }
    {
        wchar_t const* endptr;
        stlsoft::string_to_integer(L"0", 0, &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"0", endptr);
    }


#if 0
    {
        stlsoft::string_to_integer<char>( "0", NULL);
    }
    {
        stlsoft::string_to_integer<wchar_t>(L"0", NULL);
    }


    {
        stlsoft::string_to_integer<char>( "0", 0, NULL);
    }
    {
        stlsoft::string_to_integer<wchar_t>(L"0", 0, NULL);
    }
#endif /* 0 */


    {
        stlsoft::string_to_integer( "0", NULL);
    }
    {
        stlsoft::string_to_integer(L"0", NULL);
    }

    XTESTS_TEST_PASSED();
}

static void test_specialisations_2()
{

#if 0
    {
        stlsoft::string_to_integer( std::string("0"), static_cast<char const**>(0));
    }
    {
        stlsoft::string_to_integer(L"0", static_cast<wchar_t const**>(0));
    }


    {
        char const* endptr;
        stlsoft::string_to_integer( std::string("0"), &endptr);
    }
    {
        wchar_t const* endptr;
        stlsoft::string_to_integer(L"0", &endptr);
    }


    {
        stlsoft::string_to_integer<char>( std::string("0"), NULL);
    }
    {
        stlsoft::string_to_integer<wchar_t>(L"0", NULL);
    }


    {
        stlsoft::string_to_integer( std::string("0"), NULL);
    }
    {
        stlsoft::string_to_integer(L"0", NULL);
    }
#endif /* 0 */

    XTESTS_TEST_PASSED();
}

static void test_0()
{
    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer("0", static_cast<char const**>(0)));

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer(L"0", static_cast<wchar_t const**>(0)));
}

static void test_positives_implicit()
{
    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::string_to_integer("1", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::string_to_integer("7", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::string_to_integer("10", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::string_to_integer("11", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(123456, stlsoft::string_to_integer("123456", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(654321, stlsoft::string_to_integer("654321", static_cast<char const**>(0)));

    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::string_to_integer(L"1", static_cast<wchar_t const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::string_to_integer(L"7", static_cast<wchar_t const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::string_to_integer(L"10", static_cast<wchar_t const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::string_to_integer(L"11", static_cast<wchar_t const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(123456, stlsoft::string_to_integer(L"123456", static_cast<wchar_t const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(654321, stlsoft::string_to_integer(L"654321", static_cast<wchar_t const**>(0)));
}

static void test_positives_explicit()
{
    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer("+1", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+7, stlsoft::string_to_integer("+7", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+10, stlsoft::string_to_integer("+10", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+11, stlsoft::string_to_integer("+11", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+123456, stlsoft::string_to_integer("+123456", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+654321, stlsoft::string_to_integer("+654321", static_cast<char const**>(0)));
}

static void test_negatives()
{
    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer("-1", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-7, stlsoft::string_to_integer("-7", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-10, stlsoft::string_to_integer("-10", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-11, stlsoft::string_to_integer("-11", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-123456, stlsoft::string_to_integer("-123456", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-654321, stlsoft::string_to_integer("-654321", static_cast<char const**>(0)));
}

static void test_bad()
{
    char const* endptr = NULL;

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer("--0", &endptr));
    XTESTS_TEST_CHARACTER_EQUAL('-', *endptr);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-0", endptr);

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer("++0", &endptr));
    XTESTS_TEST_CHARACTER_EQUAL('+', *endptr);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("+0", endptr);

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer("~0", &endptr));
    XTESTS_TEST_CHARACTER_EQUAL('~', *endptr);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~0", endptr);

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer("   ~0", &endptr));
    XTESTS_TEST_CHARACTER_EQUAL('~', *endptr);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~0", endptr);
}

static void test_spaces()
{
    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::string_to_integer(" \t\r\n\v\b1", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::string_to_integer(" \t\r\n\v\b7", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::string_to_integer(" \t\r\n\v\b10", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::string_to_integer(" \t\r\n\v\b11", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(123456, stlsoft::string_to_integer(" \t\r\n\v\b123456", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(654321, stlsoft::string_to_integer(" \t\r\n\v\b654321", static_cast<char const**>(0)));

    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer(" \t\r\n\v\b+1", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+7, stlsoft::string_to_integer(" \t\r\n\v\b+7", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+10, stlsoft::string_to_integer(" \t\r\n\v\b+10", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+11, stlsoft::string_to_integer(" \t\r\n\v\b+11", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+123456, stlsoft::string_to_integer(" \t\r\n\v\b+123456", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+654321, stlsoft::string_to_integer(" \t\r\n\v\b+654321", static_cast<char const**>(0)));

    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer(" \t\r\n\v\b-1", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-7, stlsoft::string_to_integer(" \t\r\n\v\b-7", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-10, stlsoft::string_to_integer(" \t\r\n\v\b-10", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-11, stlsoft::string_to_integer(" \t\r\n\v\b-11", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-123456, stlsoft::string_to_integer(" \t\r\n\v\b-123456", static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-654321, stlsoft::string_to_integer(" \t\r\n\v\b-654321", static_cast<char const**>(0)));
}

static void test_len_spaces()
{
    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::string_to_integer(" \t\r\n\v\b1", 7, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::string_to_integer(" \t\r\n\v\b7", 7, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::string_to_integer(" \t\r\n\v\b10", 8, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::string_to_integer(" \t\r\n\v\b11", 8, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(123456, stlsoft::string_to_integer(" \t\r\n\v\b123456", 12, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(654321, stlsoft::string_to_integer(" \t\r\n\v\b654321", 12, static_cast<char const**>(0)));

    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer(" \t\r\n\v\b+1", 8, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+7, stlsoft::string_to_integer(" \t\r\n\v\b+7", 8, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+10, stlsoft::string_to_integer(" \t\r\n\v\b+10", 9, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+11, stlsoft::string_to_integer(" \t\r\n\v\b+11", 9, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+123456, stlsoft::string_to_integer(" \t\r\n\v\b+123456", 13, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(+654321, stlsoft::string_to_integer(" \t\r\n\v\b+654321", 13, static_cast<char const**>(0)));

    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer(" \t\r\n\v\b-1", 8, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-7, stlsoft::string_to_integer(" \t\r\n\v\b-7", 8, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-10, stlsoft::string_to_integer(" \t\r\n\v\b-10", 9, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-11, stlsoft::string_to_integer(" \t\r\n\v\b-11", 9, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-123456, stlsoft::string_to_integer(" \t\r\n\v\b-123456", 13, static_cast<char const**>(0)));
    XTESTS_TEST_INTEGER_EQUAL(-654321, stlsoft::string_to_integer(" \t\r\n\v\b-654321", 13, static_cast<char const**>(0)));
}

static void test_trailing()
{
    char const* endptr = NULL;

    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::string_to_integer("1abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::string_to_integer("7abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::string_to_integer("10abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::string_to_integer("11abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(123456, stlsoft::string_to_integer("123456abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(654321, stlsoft::string_to_integer("654321abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);

    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer("+1abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+7, stlsoft::string_to_integer("+7abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+10, stlsoft::string_to_integer("+10abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+11, stlsoft::string_to_integer("+11abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+123456, stlsoft::string_to_integer("+123456abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+654321, stlsoft::string_to_integer("+654321abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);

    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer("-1abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-7, stlsoft::string_to_integer("-7abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-10, stlsoft::string_to_integer("-10abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-11, stlsoft::string_to_integer("-11abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-123456, stlsoft::string_to_integer("-123456abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-654321, stlsoft::string_to_integer("-654321abc", &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
}

static void test_len_trailing()
{
    char const* endptr = NULL;

    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::string_to_integer("1abc", 4, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::string_to_integer("7abc", 4, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::string_to_integer("10abc", 5, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::string_to_integer("11abc", 5, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(123456, stlsoft::string_to_integer("123456abc", 9, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(654321, stlsoft::string_to_integer("654321abc", 9, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);

    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer("+1abc", 5, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+7, stlsoft::string_to_integer("+7abc", 5, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+10, stlsoft::string_to_integer("+10abc", 6, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+11, stlsoft::string_to_integer("+11abc", 6, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+123456, stlsoft::string_to_integer("+123456abc", 10, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(+654321, stlsoft::string_to_integer("+654321abc", 10, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);

    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer("-1abc", 5, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-7, stlsoft::string_to_integer("-7abc", 5, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-10, stlsoft::string_to_integer("-10abc", 6, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-11, stlsoft::string_to_integer("-11abc", 6, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-123456, stlsoft::string_to_integer("-123456abc", 10, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(-654321, stlsoft::string_to_integer("-654321abc", 10, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
}

static void test_len_truncated()
{
    char const* endptr = NULL;

    XTESTS_TEST_INTEGER_EQUAL(1, stlsoft::string_to_integer("1abc", 2, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(7, stlsoft::string_to_integer("7abc", 2, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);
    XTESTS_TEST_INTEGER_EQUAL(10, stlsoft::string_to_integer("10abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(11, stlsoft::string_to_integer("11abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(12, stlsoft::string_to_integer("123456abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(65, stlsoft::string_to_integer("654321abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));

    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer("+1abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(+7, stlsoft::string_to_integer("+7abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer("+10abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer("+11abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(+1, stlsoft::string_to_integer("+123456abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(+6, stlsoft::string_to_integer("+654321abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));

    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer("-1abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(-7, stlsoft::string_to_integer("-7abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer("-10abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer("-11abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(-1, stlsoft::string_to_integer("-123456abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
    XTESTS_TEST_INTEGER_EQUAL(-6, stlsoft::string_to_integer("-654321abc", 2, &endptr));
    XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
}

static void test_increasing_length()
{
    {
        const char  number[]    =   "1000000000";
        int         result      =   0;

        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(number); ++i)
        {
            int n = stlsoft::string_to_integer(number, i, NULL);

            XTESTS_TEST_INTEGER_EQUAL(result, n);

            result = (0 == result) ? 1 : (result * 10);
        }}
    }

    {
        const wchar_t   number[]    =   L"1000000000";
        int             result      =   0;

        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(number); ++i)
        {
            int n = stlsoft::string_to_integer(number, i, NULL);

            XTESTS_TEST_INTEGER_EQUAL(result, n);

            result = (0 == result) ? 1 : (result * 10);
        }}
    }
}

static void test_1_10()
{
}

static void test_decimal_leading_plus()
{
    char const* endptr = NULL;

    XTESTS_TEST_INTEGER_EQUAL(123, stlsoft::string_to_integer(" +123abc", 8, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer(" +abc123", 8, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc123", endptr);

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer(" abc123", 7, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc123", endptr);
}

static void test_1_12()
{
}

static void test_endptr()
{
    {
        char const  src[]   =   "0";
        char const* endptr  =   NULL;

        XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer(src, &endptr));
        XTESTS_TEST_POINTER_EQUAL(src + 1, endptr);
    }

    {
        char const  src[]   =   "0";
        char const* endptr  =   NULL;

        XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer(src, STLSOFT_NUM_ELEMENTS(src) - 1u, &endptr));
        XTESTS_TEST_POINTER_EQUAL(src + 1, endptr);
    }

    {
        char const* endptr;
        stlsoft::string_to_integer("0", 0, &endptr);
        XTESTS_REQUIRE(XTESTS_TEST_POINTER_NOT_EQUAL(NULL, endptr));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", endptr);
    }
}

static void test_1_14()
{
}

static void test_hexadecimal_1()
{
#if 0
    char const* endptr = NULL;

    XTESTS_TEST_INTEGER_EQUAL(123, stlsoft::string_to_integer(" +123abc", 8, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", endptr);

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer(" +abc123", 8, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc123", endptr);

    XTESTS_TEST_INTEGER_EQUAL(0, stlsoft::string_to_integer(" abc123", 7, &endptr));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc123", endptr);
#endif /* 0 */
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


static void test_try_1_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10", &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_2_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("10a", &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_3_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10", 2, &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_4_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10a", 2, &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_5_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_6_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("10a", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_7_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10", 2, &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_8_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10a", 2, &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_9_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<int>("10a", &i, "a")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_10_int()
{
    int i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<int>("10a", &i, "endptr")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}


static void test_try_1_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10", &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_2_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<uint64_t>("10a", &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_3_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10", 2, &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_4_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10a", 2, &i)));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_5_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_6_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<uint64_t>("10a", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_7_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10", 2, &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_8_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10a", 2, &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_9_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("10a", &i, "a")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}

static void test_try_10_uint64()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to<uint64_t>("10a", &i, "endptr")));
    XTESTS_TEST_INTEGER_EQUAL(10, i);
}



static void test_try_hex_1_int()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("0", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(0u, i);
}

static void test_try_hex_2_int()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("0x0", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(0u, i);
}

static void test_try_hex_3_int()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("+0x0", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(0u, i);
}

static void test_try_hex_4_int()
{
    sint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<sint64_t>("-0x0", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(0, i);
}

static void test_try_hex_5_int()
{
    uint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<uint64_t>("0x10", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(16u, i);
}

static void test_try_hex_6_int()
{
    sint64_t i;

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to<sint64_t>("-0x0a", &i, "")));
    XTESTS_TEST_INTEGER_EQUAL(-10, i);
}

static void test_try_hex_7_int()
{
}

static void test_try_hex_8_int()
{
}

static void test_try_hex_9_int()
{
}

static void test_try_hex_10_int()
{
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
