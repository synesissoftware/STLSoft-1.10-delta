/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.shims.access.string.SYSTEMTIME.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.shims.access.string.SYSTEMTIME project.
 *
 * Created:     28th May 2014
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

#include <winstl/shims/access/string/time/SYSTEMTIME.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <winstl/time/elicitation_functions.h>
#include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#include <stlsoft/string/simple_string.hpp>
#include <stlsoft/stlsoft.h>

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
    static void test_invalid_year(void);
    static void test_invalid_month(void);
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

    if(XTESTS_START_RUNNER("test.unit.winstl.shims.access.string.SYSTEMTIME", verbosity))
    {
        XTESTS_RUN_CASE(test_today);
        XTESTS_RUN_CASE(test_earliest_valid);
        XTESTS_RUN_CASE(test_latest_valid);
        XTESTS_RUN_CASE(test_invalid_year);
        XTESTS_RUN_CASE(test_invalid_month);
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
    typedef stlsoft::simple_string      string_t;

    template <typename T>
    inline
    string_t
    get_time_string_via_shim(
        T const& t
    )
    {
        return string_t(::stlsoft::c_str_data_a(t), ::stlsoft::c_str_len_a(t));
    }


    inline
    string_t
    get_(
        SYSTEMTIME const& st
    ,   int (WINAPI* pfn)(LCID,DWORD,CONST SYSTEMTIME*,LPCSTR,LPSTR,int)
    )
    {

        char        sz[1000];
        int const   n = (*pfn)(LOCALE_USER_DEFAULT, 0, &st, NULL, sz, STLSOFT_NUM_ELEMENTS(sz));

        if(0 == n)
        {
            DWORD const e = ::GetLastError();

            // TODO: discriminate on e and on the values of t to determine
            // which condition (of invalid value, out-of-range, etc.)

            STLSOFT_THROW_X(winstl::conversion_error("failed to convert date/time", e));
        }

        return string_t(sz, n);
    }

    inline
    string_t
    get_date(
        SYSTEMTIME const& st
    )
    {
        return get_(st, ::GetDateFormatA);
    }

    inline
    string_t
    get_time(
        SYSTEMTIME const& st
    )
    {
        return get_(st, ::GetTimeFormatA);
    }

    inline
    string_t
    get_ms(
        SYSTEMTIME const& st
    )
    {
        char                sz[21];
        size_t              n;
        char const* const   s   =   stlsoft::integer_to_decimal_string(sz, STLSOFT_NUM_ELEMENTS(sz), st.wMilliseconds, &n);

        return string_t(s, n);
    }

    inline
    string_t
    get_date(
        void (WINAPI*pfn)(SYSTEMTIME*)
    )
    {
        SYSTEMTIME st;

        (*pfn)(&st);

        return get_date(st);
    }

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

    string_t const  expectedDate    =   get_date(st);
    string_t const  expectedTime    =   get_time(st);
    string_t const  expectedMs      =   get_ms(st);
    string_t const  actual          =   get_time_string_via_shim(st);

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedDate, actual);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedTime, actual);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedMs, actual);

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedDate, ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedTime, ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedMs, ::stlsoft::c_str_ptr_a(st));
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

    string_t const  expectedDate    =   get_date(st);
    string_t const  expectedTime    =   get_time(st);
    string_t const  expectedMs      =   get_ms(st);
    string_t const  actual          =   get_time_string_via_shim(st);

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedDate, actual);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedTime, actual);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedMs, actual);

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedDate, ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedTime, ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedMs, ::stlsoft::c_str_ptr_a(st));
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

    string_t const  expectedDate    =   get_date(st);
    string_t const  expectedTime    =   get_time(st);
    string_t const  expectedMs      =   get_ms(st);
    string_t const  actual          =   get_time_string_via_shim(st);

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedDate, actual);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedTime, actual);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedMs, actual);

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedDate, ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedTime, ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(expectedMs, ::stlsoft::c_str_ptr_a(st));
}

static void test_invalid_year()
{
    SYSTEMTIME  st;

    st.wYear            =   0;
    st.wMonth           =   5;
    st.wDay             =   28;
    st.wHour            =   10;
    st.wMinute          =   46;
    st.wSecond          =   25;
    st.wMilliseconds    =   0;

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("invalid date/time", st);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("year=0", st);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("month=5", st);

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("invalid date/time", ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("year=0", ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("month=5", ::stlsoft::c_str_ptr_a(st));

    XTESTS_TEST_WIDE_STRING_CONTAIN(L"invalid date/time", ::stlsoft::c_str_ptr_w(st));
    XTESTS_TEST_WIDE_STRING_CONTAIN(L"year=0", ::stlsoft::c_str_ptr_w(st));
    XTESTS_TEST_WIDE_STRING_CONTAIN(L"month=5", ::stlsoft::c_str_ptr_w(st));
}

static void test_invalid_month()
{
    SYSTEMTIME  st;

    st.wYear            =   2014;
    st.wMonth           =   13;
    st.wDay             =   28;
    st.wHour            =   10;
    st.wMinute          =   46;
    st.wSecond          =   25;
    st.wMilliseconds    =   0;

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("invalid date/time", st);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("year=2014", st);
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("month=13", st);

    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("invalid date/time", ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("year=2014", ::stlsoft::c_str_ptr_a(st));
    XTESTS_TEST_MULTIBYTE_STRING_CONTAIN("month=13", ::stlsoft::c_str_ptr_a(st));

    XTESTS_TEST_WIDE_STRING_CONTAIN("invalid date/time", ::stlsoft::c_str_ptr_w(st));
    XTESTS_TEST_WIDE_STRING_CONTAIN("year=2014", ::stlsoft::c_str_ptr_w(st));
    XTESTS_TEST_WIDE_STRING_CONTAIN("month=13", ::stlsoft::c_str_ptr_w(st));
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
