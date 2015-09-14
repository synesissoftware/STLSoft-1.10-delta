/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.unixstl.shims.access.string.timeval.cpp
 *
 * Purpose:     Implementation file for the test.unit.unixstl.shims.access.string.timeval project.
 *
 * Created:     5th May 2014
 * Updated:     5th May 2014
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


#define STLSOFT_MINIMUM_SAS_INCLUDES

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <unixstl/shims/access/string/timeval.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <unixem/implicit_link.h>
#include <stlsoft/stlsoft.h>

/* UNIX header files */
#include <unixem/time.h>
#include <unixem/internal/util.h>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdlib.h>
#include <time.h>

#ifdef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME
# error 
#endif /* STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_HPP_TIME */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_calls_possible(void);
    static void test_c_str_len(void);
    static void test_c_str_ptr(void);
    static void test_invalid_value_conversion(void);
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

    if(XTESTS_START_RUNNER("test.unit.unixstl.shims.access.string.timeval", verbosity))
    {
        XTESTS_RUN_CASE(test_calls_possible);
        XTESTS_RUN_CASE(test_c_str_len);
        XTESTS_RUN_CASE(test_c_str_ptr);
        XTESTS_RUN_CASE(test_invalid_value_conversion);
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
        return "May 05 05:03:02.013987 2014";
    }

    struct timeval get_fixed_date()
    {
        struct tm   tm;

        tm.tm_year  =   2014 - 1900;
        tm.tm_mon   =   4;
        tm.tm_mday  =   5;
        tm.tm_hour  =   5;
        tm.tm_min   =   3;
        tm.tm_sec   =   2;

        tm.tm_wday  =   1;
        tm.tm_yday  =   0;
        tm.tm_isdst =   0;

		char const* const	s1 = ::asctime(&tm);

        struct timeval	tv;

		tv.tv_sec	=	::timegm(&tm);
		tv.tv_usec	=	13987;

		wchar_t const* const	s2 = ::_wctime(&tv.tv_sec);

        return tv;
    }

static void test_calls_possible()
{
    {
		struct timeval tv = get_fixed_date();

        stlsoft::c_str_data_a(tv);
        stlsoft::c_str_data(tv);

        stlsoft::c_str_len_a(tv);
        stlsoft::c_str_len(tv);

        stlsoft::c_str_ptr_a(tv);
        stlsoft::c_str_ptr(tv);

        stlsoft::c_str_ptr_null_a(tv);
        stlsoft::c_str_ptr_null(tv);

        XTESTS_TEST_PASSED();
    }

    {
		struct timeval	tv_	=	get_fixed_date();
        struct timeval*	tv	=	&tv_;

        stlsoft::c_str_data_a(tv);
        stlsoft::c_str_data(tv);

        stlsoft::c_str_len_a(tv);
        stlsoft::c_str_len(tv);

        stlsoft::c_str_ptr_a(tv);
        stlsoft::c_str_ptr(tv);

        stlsoft::c_str_ptr_null_a(tv);
        stlsoft::c_str_ptr_null(tv);

        XTESTS_TEST_PASSED();
    }
}

static void test_c_str_len()
{
    {
		struct timeval tv = get_fixed_date();

        XTESTS_TEST_INTEGER_EQUAL(27u, stlsoft::c_str_len_a(tv));
        XTESTS_TEST_INTEGER_EQUAL(27u, stlsoft::c_str_len(tv));
    }

    {
		struct timeval	tv_	=	get_fixed_date();
        struct timeval*	tv	=	&tv_;

        XTESTS_TEST_INTEGER_EQUAL(27u, stlsoft::c_str_len_a(tv));
        XTESTS_TEST_INTEGER_EQUAL(27u, stlsoft::c_str_len(tv));
    }
}

static void test_c_str_ptr()
{
    {
		struct timeval tv = get_fixed_date();

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(get_fixed_date_string(), stlsoft::c_str_ptr_a(tv));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(get_fixed_date_string(), stlsoft::c_str_ptr(tv));
    }

    {
		struct timeval	tv_ =	get_fixed_date();
        struct timeval*	tv	=	&tv_;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(get_fixed_date_string(), stlsoft::c_str_ptr_a(tv));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(get_fixed_date_string(), stlsoft::c_str_ptr(tv));
    }
}

static void test_invalid_value_conversion()
{
    struct timeval tv;

    tv.tv_sec   =   -1;
    tv.tv_usec  =   -1;

    XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS("(invalid time)") - 1, stlsoft::c_str_len_a(tv));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("(invalid time)", stlsoft::c_str_ptr_a(tv));
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
