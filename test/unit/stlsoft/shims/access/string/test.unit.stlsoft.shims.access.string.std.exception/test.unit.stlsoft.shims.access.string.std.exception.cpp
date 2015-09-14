/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.shims.access.string.std.exception.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.shims.access.string.std.exception project.
 *
 * Created:     8th November 2010
 * Updated:     8th November 2010
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

#include <stlsoft/shims/access/string/std/exception.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <exception>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_c_str_len(void);
    static void test_c_str_data(void);
    static void test_c_str_ptr(void);
    static void test_c_str_ptr_null(void);
    static void test_all_with_varying_lengths(void);
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.shims.access.string.std.exception", verbosity))
    {
        XTESTS_RUN_CASE(test_c_str_len);
        XTESTS_RUN_CASE(test_c_str_data);
        XTESTS_RUN_CASE(test_c_str_ptr);
        XTESTS_RUN_CASE(test_c_str_ptr_null);
        XTESTS_RUN_CASE(test_all_with_varying_lengths);
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
# define X_MSG          "Something has happened"
# define X_ALPHABET_M   "abcdefghijklmnopqrstuvwxyz"
# define X_ALPHABET_W  L"abcdefghijklmnopqrstuvwxyz"


static void test_c_str_len()
{
    std::runtime_error x(X_MSG);

    XTESTS_TEST_INTEGER_EQUAL(::strlen(X_MSG), stlsoft::c_str_len(x));
    XTESTS_TEST_INTEGER_EQUAL(::strlen(X_MSG), stlsoft::c_str_len_a(x));
    XTESTS_TEST_INTEGER_EQUAL(::strlen(X_MSG), stlsoft::c_str_len_w(x));
}

static void test_c_str_data()
{
    std::runtime_error x(X_MSG);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(X_MSG, stlsoft::c_str_data_a(x));
    XTESTS_TEST_WIDE_STRING_EQUAL(X_MSG, stlsoft::c_str_data_w(x));
}

static void test_c_str_ptr()
{
    std::runtime_error x(X_MSG);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(X_MSG, stlsoft::c_str_ptr_a(x));
    XTESTS_TEST_WIDE_STRING_EQUAL(X_MSG, stlsoft::c_str_ptr_w(x));
}

static void test_c_str_ptr_null()
{
    std::runtime_error x(X_MSG);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(X_MSG, stlsoft::c_str_ptr_null_a(x));
    XTESTS_TEST_WIDE_STRING_EQUAL(X_MSG, stlsoft::c_str_ptr_null_w(x));
}

static void test_all_with_varying_lengths()
{
    STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS(X_ALPHABET_M) == STLSOFT_NUM_ELEMENTS(X_ALPHABET_W));

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(X_ALPHABET_M); ++i)
    {
        std::runtime_error x(std::string(X_ALPHABET_M, i));

        XTESTS_TEST_INTEGER_EQUAL(i, stlsoft::c_str_len(x));
        XTESTS_TEST_INTEGER_EQUAL(i, stlsoft::c_str_len_a(x));
        XTESTS_TEST_INTEGER_EQUAL(i, stlsoft::c_str_len_w(x));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(std::string(X_ALPHABET_M, i), stlsoft::c_str_ptr_a(x));
        XTESTS_TEST_WIDE_STRING_EQUAL(std::wstring(X_ALPHABET_W, i), stlsoft::c_str_ptr_w(x));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(std::string(X_ALPHABET_M, i), stlsoft::c_str_data_a(x));
        XTESTS_TEST_WIDE_STRING_EQUAL(std::wstring(X_ALPHABET_W, i), stlsoft::c_str_data_w(x));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(std::string(X_ALPHABET_M, i), stlsoft::c_str_ptr_null_a(x));
        XTESTS_TEST_WIDE_STRING_EQUAL(std::wstring(X_ALPHABET_W, i), stlsoft::c_str_ptr_null_w(x));
    }}
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
