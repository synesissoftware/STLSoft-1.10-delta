/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.unixstl.system.system_traits.2.cpp
 *
 * Purpose:     Implementation file for the test.unit.unixstl.system.system_traits.2 project.
 *
 * Created:     31st December 2008
 * Updated:     12th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 */

#if defined(_MSC_VER) && \
    _MSC_VER >= 1400
# pragma warning(disable : 4996)
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <unixstl/system/system_traits.hpp>

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
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/error/error_desc.hpp>
#include <platformstl/system/environment_variable_traits.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* UNIX headers */
#include <dlfcn.h>

/* /////////////////////////////////////////////////////////////////////////
 * Platform compatibility
 */

#if defined(_WIN32)

int open_dev_null_();
int open_for_win32_(char const* s, int oflags, int pmode = 0)
{
    if(0 == ::strcmp(s, "/dev/null"))
    {
        return open_dev_null_();
    }

    return open(s, oflags, pmode);
}

# define open       open_for_win32_

#endif /* _WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_dl(void);
    static void test_close_handle(void);
    static void test_last_error(void);
    static void test_get_environment_variable(void);
    static void test_expand_environment_strings(void);
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

    if(XTESTS_START_RUNNER("test.unit.unixstl.system.system_traits.2", verbosity))
    {
        XTESTS_RUN_CASE(test_dl);
        XTESTS_RUN_CASE(test_close_handle);
        XTESTS_RUN_CASE(test_last_error);
        XTESTS_RUN_CASE(test_get_environment_variable);
        XTESTS_RUN_CASE(test_expand_environment_strings);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*unixstl/*/system_traits.hpp", NULL);
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

    typedef unixstl::system_traits<char>        system_traits_m_t;
    typedef unixstl::system_traits<wchar_t>     system_traits_w_t;

    typedef std::basic_string<char>             string_m_t;
    typedef std::basic_string<wchar_t>          string_w_t;




static void test_dl()
{
#ifdef _WIN32
    char const* so_name     =   "KERNEL32.dll";
    char const* sym_name    =   "CloseHandle";
#else /* ? _WIN32 */
    char const* so_name     =   "libm.so";
    char const* sym_name    =   "fabs";
#endif /* _WIN32 */

    {
        // 1. Load

        void*                           h1      =   ::dlopen(so_name, RTLD_NOW);
        system_traits_m_t::module_type  h2      =   system_traits_m_t::load_library(so_name);

        XTESTS_TEST_POINTER_EQUAL(h1, h2);

        // 2. Get Proc
        void*                           pfn1    =   ::dlsym(h1, sym_name);
        void*                           pfn2    =   system_traits_m_t::find_symbol(h2, sym_name);

        XTESTS_TEST_POINTER_EQUAL(pfn1, pfn2);

        // 3. Free

        if(NULL != h1)
        {
            ::dlclose(h1);
        }
        if(NULL != h2)
        {
            XTESTS_TEST_BOOLEAN_TRUE(system_traits_m_t::free_library(h2));
        }
    }
}

static void test_close_handle()
{
    {
        int h = ::open("/dev/null", 0);

        if(-1 == h)
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not create file to use to test close_handle()", stlsoft::error_desc_a());
        }
        else
        {
            XTESTS_TEST_BOOLEAN_TRUE(system_traits_m_t::close_handle(h));
        }
    }

    {
        int h = ::open("/dev/null", 0);

        if(-1 == h)
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not create file to use to test close_handle()", stlsoft::error_desc_a());
        }
        else
        {
            XTESTS_TEST_BOOLEAN_TRUE(system_traits_w_t::close_handle(h));
        }
    }
}

static void test_last_error()
{
    { for(long i = 1; i != 10000; ++i)
    {
        system_traits_m_t::error_type code(i);

        system_traits_m_t::set_last_error(code);

        XTESTS_TEST_INTEGER_EQUAL(code, system_traits_m_t::get_last_error());

        system_traits_m_t::set_last_error(0);

        XTESTS_TEST_INTEGER_EQUAL(system_traits_m_t::error_type(0), system_traits_m_t::get_last_error());
    }}

    { for(long i = 1; i != 10000; ++i)
    {
        system_traits_w_t::error_type code(i);

        system_traits_w_t::set_last_error(code);

        XTESTS_TEST_INTEGER_EQUAL(code, system_traits_w_t::get_last_error());

        system_traits_w_t::set_last_error(0);

        XTESTS_TEST_INTEGER_EQUAL(system_traits_w_t::error_type(0), system_traits_w_t::get_last_error());
    }}
}

static void test_get_environment_variable()
{
    // Multibyte string
    {
        XTESTS_TEST_INTEGER_EQUAL(0u, system_traits_m_t::get_environment_variable("", NULL, 0));

        // (i) one that exists

        static const char variable[] = "test.unit.unixstl.system.system_traits.2";

        if(0 != platformstl::environment_variable_traits::set_variable(variable, variable))
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not set environment variable for test", variable);
        }
        else
        {
            // When NULL is passed for result, return value is the required number of parameters
            XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(variable) - 1u, system_traits_m_t::get_environment_variable(variable, NULL, 0));

            char results[STLSOFT_NUM_ELEMENTS(variable) * 2];

            { for(size_t i = 1u; i != STLSOFT_NUM_ELEMENTS(results); ++i)
            {
                std::fill_n(results, STLSOFT_NUM_ELEMENTS(results), '~');

                size_t  n = system_traits_m_t::get_environment_variable(variable, results, i);

                if(i < STLSOFT_NUM_ELEMENTS(variable))
                {
                    XTESTS_TEST_INTEGER_EQUAL(i, n);
                    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(variable, results, i);
                    XTESTS_TEST_CHARACTER_EQUAL('~', results[i]);
                }
                else
                {
                    XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(variable) - 1, n);
                    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(variable, results);
                    XTESTS_TEST_CHARACTER_EQUAL('~', results[n + 1]);
                }
            }}
        }

        // (i) one that does not exist
        if(0 != platformstl::environment_variable_traits::erase_variable(variable))
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not erase environment variable for test", variable);
        }
        else
        {
            // When NULL is passed for result, return value is the required number of parameters
            XTESTS_TEST_INTEGER_EQUAL(0u, system_traits_m_t::get_environment_variable(variable, NULL, 0));

            char results[STLSOFT_NUM_ELEMENTS(variable) * 2];

            { for(size_t i = 1u; i != STLSOFT_NUM_ELEMENTS(results); ++i)
            {
                std::fill_n(results, STLSOFT_NUM_ELEMENTS(results), '~');

                size_t  n = system_traits_m_t::get_environment_variable(variable, results, i);

                XTESTS_TEST_INTEGER_EQUAL(0u, n);
                XTESTS_TEST_CHARACTER_EQUAL('~', results[0u]);
            }}
        }
    }
}

static void test_expand_environment_strings()
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

/* ////////////////////////////////////////////////////////////////////// */

#if defined(_WIN32)

# include <windows.h>

int open_dev_null_()
{
    HANDLE  h = ::CreateFile(".dev.null", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN | FILE_FLAG_DELETE_ON_CLOSE, NULL);

    if(INVALID_HANDLE_VALUE == h)
    {
        return -1;
    }
    else
    {
        return _open_osfhandle((long)h, _O_RDONLY);
    }
}

#endif /* _WIN32 */

/* ///////////////////////////// end of file //////////////////////////// */
