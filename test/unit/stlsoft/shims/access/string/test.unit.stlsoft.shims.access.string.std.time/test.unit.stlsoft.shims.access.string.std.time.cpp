/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.shims.access.string.std.time.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.shims.access.string.std.time project.
 *
 * Created:     15th October 2008
 * Updated:     15th October 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/shims/access/string/std/time.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_calls_possible(void);
    static void test_c_str_len(void);
    static void test_c_str_ptr(void);
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.shims.access.string.std.time", verbosity))
    {
        XTESTS_RUN_CASE(test_calls_possible);
        XTESTS_RUN_CASE(test_c_str_len);
        XTESTS_RUN_CASE(test_c_str_ptr);
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
    char const* get_fixed_date_string()
    {
        return "Jan 01 04:03:02 2010";
    }

    struct tm get_fixed_date()
    {
        struct tm   tm;

        tm.tm_sec   =   2;
        tm.tm_min   =   3;
        tm.tm_hour  =   4;
        tm.tm_mday  =   1;
        tm.tm_mon   =   0;
        tm.tm_year  =   110;
        tm.tm_wday  =   0;
        tm.tm_yday  =   0;
        tm.tm_isdst =   0;

        return tm;
    }

static void test_calls_possible()
{
    {
        struct tm   tm = get_fixed_date();

        stlsoft::c_str_data_a(tm);
        stlsoft::c_str_data(tm);

        stlsoft::c_str_len_a(tm);
        stlsoft::c_str_len(tm);

        stlsoft::c_str_ptr_a(tm);
        stlsoft::c_str_ptr(tm);

        stlsoft::c_str_ptr_null_a(tm);
        stlsoft::c_str_ptr_null(tm);

        XTESTS_TEST_PASSED();
    }

    {
        struct tm   tm_ = get_fixed_date();
        struct tm*  tm = &tm_;

        stlsoft::c_str_data_a(tm);
        stlsoft::c_str_data(tm);

        stlsoft::c_str_len_a(tm);
        stlsoft::c_str_len(tm);

        stlsoft::c_str_ptr_a(tm);
        stlsoft::c_str_ptr(tm);

        stlsoft::c_str_ptr_null_a(tm);
        stlsoft::c_str_ptr_null(tm);

        XTESTS_TEST_PASSED();
    }
}

static void test_c_str_len()
{
    {
        struct tm   tm = get_fixed_date();

        XTESTS_TEST_INTEGER_EQUAL(20u, stlsoft::c_str_len_a(tm));
        XTESTS_TEST_INTEGER_EQUAL(20u, stlsoft::c_str_len(tm));
    }

    {
        struct tm   tm_ = get_fixed_date();
        struct tm*  tm = &tm_;

        XTESTS_TEST_INTEGER_EQUAL(20u, stlsoft::c_str_len_a(tm));
        XTESTS_TEST_INTEGER_EQUAL(20u, stlsoft::c_str_len(tm));
    }
}

static void test_c_str_ptr()
{
    {
        struct tm   tm = get_fixed_date();

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(get_fixed_date_string(), stlsoft::c_str_ptr_a(tm));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(get_fixed_date_string(), stlsoft::c_str_ptr(tm));
    }

    {
        struct tm   tm_ = get_fixed_date();
        struct tm*  tm = &tm_;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(get_fixed_date_string(), stlsoft::c_str_ptr_a(tm));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(get_fixed_date_string(), stlsoft::c_str_ptr(tm));
    }
}

static void test_1_3()
{
}

static void test_1_4()
{
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
