/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.shims.conversion.to_UDATE.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.shims.conversion.to_UDATE project.
 *
 * Created:     29th May 2014
 * Updated:     29th May 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/shims/conversion/to_UDATE.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <winstl/shims/conversion/to_FILETIME.hpp>
#include <winstl/shims/conversion/to_SYSTEMTIME.hpp>
#include <winstl/time/comparison_operators.hpp>
#include <winstl/time/elicitation_functions.h>
#include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#include <stlsoft/string/simple_string.hpp>
#include <stlsoft/stlsoft.h>

/* COM header files */
#include <objbase.h>
#include <oleauto.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_today(void);
    static void test_earliest_valid(void);
    static void test_latest_valid(void);
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

    if(XTESTS_START_RUNNER("test.unit.winstl.shims.conversion.to_UDATE", verbosity))
    {
        XTESTS_RUN_CASE(test_today);
        XTESTS_RUN_CASE(test_earliest_valid);
        XTESTS_RUN_CASE(test_latest_valid);
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
    using winstl::operator ==;

static void test_today()
{
    SYSTEMTIME  st;

    st.wYear            =   2014;
    st.wMonth           =   5;
    st.wDay             =   28;
    st.wHour            =   10;
    st.wMinute          =   46;
    st.wSecond          =   25;
    st.wMilliseconds    =   0;

    XTESTS_TEST_BOOLEAN_TRUE(st == winstl::to_SYSTEMTIME(winstl::to_UDATE(st)));
    XTESTS_TEST_BOOLEAN_TRUE(winstl::to_FILETIME(st) == winstl::to_FILETIME(winstl::to_UDATE(st)));
}

static void test_earliest_valid()
{
    SYSTEMTIME  st;

    st.wYear            =   1601;
    st.wMonth           =   1;
    st.wDay             =   1;
    st.wHour            =   0;
    st.wMinute          =   0;
    st.wSecond          =   0;
    st.wMilliseconds    =   0;

    XTESTS_TEST_BOOLEAN_TRUE(st == winstl::to_SYSTEMTIME(winstl::to_UDATE(st)));
    XTESTS_TEST_BOOLEAN_TRUE(winstl::to_FILETIME(st) == winstl::to_FILETIME(winstl::to_UDATE(st)));
}

static void test_latest_valid()
{
    SYSTEMTIME  st;

    st.wYear            =   30827;
    st.wMonth           =   12;
    st.wDay             =   31;
    st.wHour            =   23;
    st.wMinute          =   59;
    st.wSecond          =   59;
    st.wMilliseconds    =   999;

    XTESTS_TEST_BOOLEAN_TRUE(st == winstl::to_SYSTEMTIME(winstl::to_UDATE(st)));
    XTESTS_TEST_BOOLEAN_TRUE(winstl::to_FILETIME(st) == winstl::to_FILETIME(winstl::to_UDATE(st)));
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
