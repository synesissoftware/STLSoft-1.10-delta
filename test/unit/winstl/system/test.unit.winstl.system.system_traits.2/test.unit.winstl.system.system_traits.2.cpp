/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.system.system_traits.2.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.system.system_traits.2 project.
 *
 * Created:     31st December 2008
 * Updated:     14th October 2010
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
 * Test component header file include(s)
 */

#include <winstl/system/system_traits.hpp>

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
#include <stlsoft/algorithms/std/alt.hpp>
#include <stlsoft/conversion/char_conversions.hpp>
#include <winstl/error/error_desc.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

#if 0
public:
    /// \brief Returns the locale information
#ifndef NONLS
    static int_type     get_locale_info(LCID locale, LCTYPE type, char_type* data, int_type cchData);
#endif /* !NONLS */
/// @}

/// \name Environment
/// @{
public:
    /// \brief Gets an environment variable into the given buffer
    ///
    /// \param name The name of the variable to find
    /// \param buffer The buffer in which to write the variable. If this is NULL, then the required length is returned
    /// \param cchBuffer The size of the buffer, in characters
    static size_type    get_environment_variable(char_type const* name, char_type* buffer, size_type cchBuffer);
    /// Expands environment strings in \c src into \c buffer, up to a maximum \c cchDest characters
    static size_type    expand_environment_strings(char_type const* src, char_type* buffer, size_type cchBuffer);
/// @}
#endif /* 0 */


    static void test_get_locale_info(void);
    static void test_get_module_filename(void);
    static void test_get_module_directory(void);
    static void test_get_system_directory(void);
    static void test_get_windows_directory(void);
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

    if(XTESTS_START_RUNNER("test.unit.winstl.system.system_traits.2", verbosity))
    {
        XTESTS_RUN_CASE(test_get_locale_info);
        XTESTS_RUN_CASE(test_get_module_filename);
        XTESTS_RUN_CASE(test_get_module_directory);
        XTESTS_RUN_CASE(test_get_system_directory);
        XTESTS_RUN_CASE(test_get_windows_directory);
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
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/system_traits.hpp", NULL);
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

    typedef winstl::system_traits<char>         system_traits_m_t;
    typedef winstl::system_traits<wchar_t>      system_traits_w_t;

    typedef std::basic_string<char>             string_m_t;
    typedef std::basic_string<wchar_t>          string_w_t;




static void test_get_locale_info()
{
}

static void test_get_module_filename()
{
    {
        char        dir1[1 + _MAX_PATH];
        char        dir2[1 + _MAX_PATH];
        HINSTANCE   h       =   ::LoadLibraryA("KERNEL32.DLL");
        size_t      cch1    =   ::GetModuleFileNameA(h, &dir1[0], STLSOFT_NUM_ELEMENTS(dir1));
        size_t      cch2    =   system_traits_m_t::get_module_filename(h, &dir2[0], STLSOFT_NUM_ELEMENTS(dir2));

        ::FreeLibrary(h);

        XTESTS_TEST_INTEGER_EQUAL(cch1, cch2);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(dir1, dir2);
    }

    {
        wchar_t     dir1[1 + _MAX_PATH];
        wchar_t     dir2[1 + _MAX_PATH];
        HINSTANCE   h       =   ::LoadLibraryW(L"KERNEL32.DLL");
        size_t      cch1    =   ::GetModuleFileNameW(h, &dir1[0], STLSOFT_NUM_ELEMENTS(dir1));
        size_t      cch2    =   system_traits_w_t::get_module_filename(h, &dir2[0], STLSOFT_NUM_ELEMENTS(dir2));

        ::FreeLibrary(h);

        XTESTS_TEST_INTEGER_EQUAL(cch1, cch2);
        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(dir1, dir2);
    }
}

static void test_get_module_directory()
{
    {
        char        dir1[1 + _MAX_DIR];
        char        dir2[1 + _MAX_DIR];
        HINSTANCE   h       =   ::LoadLibraryA("KERNEL32.DLL");
        size_t      cch1    =   ::GetModuleFileNameA(h, &dir1[0], STLSOFT_NUM_ELEMENTS(dir1));
        size_t      cch2    =   system_traits_m_t::get_module_directory(h, &dir2[0], STLSOFT_NUM_ELEMENTS(dir2));

        char*       last    =   ::strrchr(dir1, '\\');

        cch1 -= ::strlen(last);
        *last = '\0';

        ::FreeLibrary(h);

        XTESTS_TEST_INTEGER_EQUAL(cch1, cch2);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(dir1, dir2);
    }

    {
        wchar_t     dir1[1 + _MAX_DIR];
        wchar_t     dir2[1 + _MAX_DIR];
        HINSTANCE   h       =   ::LoadLibraryW(L"KERNEL32.DLL");
        size_t      cch1    =   ::GetModuleFileNameW(h, &dir1[0], STLSOFT_NUM_ELEMENTS(dir1));
        size_t      cch2    =   system_traits_w_t::get_module_directory(h, &dir2[0], STLSOFT_NUM_ELEMENTS(dir2));

        wchar_t*    last    =   ::wcsrchr(dir1, L'\\');

        cch1 -= ::wcslen(last);
        *last = '\0';

        ::FreeLibrary(h);

        XTESTS_TEST_INTEGER_EQUAL(cch1, cch2);
        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(dir1, dir2);
    }
}

static void test_get_system_directory()
{
    {
        char                            sysDir1[1 + _MAX_PATH];
        char                            sysDir2[1 + _MAX_PATH];
        size_t                          cch1;
        system_traits_m_t::size_type    cch2;

        cch1 = ::GetSystemDirectoryA(&sysDir1[0], STLSOFT_NUM_ELEMENTS(sysDir1));
        cch2 = system_traits_m_t::get_system_directory(&sysDir2[0], STLSOFT_NUM_ELEMENTS(sysDir2));

        XTESTS_TEST_INTEGER_EQUAL(cch1, cch2);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(sysDir1, sysDir2);
    }

    {
        wchar_t                         sysDir1[1 + _MAX_PATH];
        wchar_t                         sysDir2[1 + _MAX_PATH];
        size_t                          cch1;
        system_traits_m_t::size_type    cch2;

        cch1 = ::GetSystemDirectoryW(&sysDir1[0], STLSOFT_NUM_ELEMENTS(sysDir1));
        cch2 = system_traits_w_t::get_system_directory(&sysDir2[0], STLSOFT_NUM_ELEMENTS(sysDir2));

        XTESTS_TEST_INTEGER_EQUAL(cch1, cch2);

        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(sysDir1, sysDir2);
    }
}

static void test_get_windows_directory()
{
    {
        char                            sysDir1[1 + _MAX_PATH];
        char                            sysDir2[1 + _MAX_PATH];
        size_t                          cch1;
        system_traits_m_t::size_type    cch2;

        cch1 = ::GetWindowsDirectoryA(&sysDir1[0], STLSOFT_NUM_ELEMENTS(sysDir1));
        cch2 = system_traits_m_t::get_windows_directory(&sysDir2[0], STLSOFT_NUM_ELEMENTS(sysDir2));

        XTESTS_TEST_INTEGER_EQUAL(cch1, cch2);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(sysDir1, sysDir2);
    }

    {
        wchar_t                         sysDir1[1 + _MAX_PATH];
        wchar_t                         sysDir2[1 + _MAX_PATH];
        size_t                          cch1;
        system_traits_m_t::size_type    cch2;

        cch1 = ::GetWindowsDirectoryW(&sysDir1[0], STLSOFT_NUM_ELEMENTS(sysDir1));
        cch2 = system_traits_w_t::get_windows_directory(&sysDir2[0], STLSOFT_NUM_ELEMENTS(sysDir2));

        XTESTS_TEST_INTEGER_EQUAL(cch1, cch2);

        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(sysDir1, sysDir2);
    }
}

static void test_dl()
{
    {
        // 1. Load

        HINSTANCE                       h1  =   ::LoadLibraryA("KERNEL32.DLL");
        system_traits_m_t::module_type  h2  =   system_traits_m_t::load_library("KERNEL32.DLL");

        XTESTS_TEST_POINTER_EQUAL(h1, h2);

        // 2. Get Proc
        FARPROC pfn1    =   ::GetProcAddress(h1, "CloseHandle");
        FARPROC pfn2    =   system_traits_m_t::find_symbol(h2, "CloseHandle");

        XTESTS_TEST_FUNCTION_POINTER_EQUAL(pfn1, pfn2);

        // 3. Free

        ::FreeLibrary(h1);
        XTESTS_TEST_BOOLEAN_TRUE(system_traits_m_t::free_library(h2));
    }

    {
        // 1. Load

        HINSTANCE                       h1  =   ::LoadLibraryW(L"KERNEL32.DLL");
        system_traits_w_t::module_type  h2  =   system_traits_w_t::load_library(L"KERNEL32.DLL");

        XTESTS_TEST_POINTER_EQUAL(h1, h2);

        // 2. Get Proc
        FARPROC pfn1    =   ::GetProcAddress(h1, "CloseHandle");
        FARPROC pfn2    =   system_traits_w_t::find_symbol(h2, "CloseHandle");

        XTESTS_TEST_FUNCTION_POINTER_EQUAL(pfn1, pfn2);

        // 3. Free

        ::FreeLibrary(h1);
        XTESTS_TEST_BOOLEAN_TRUE(system_traits_w_t::free_library(h2));
    }
}

static void test_close_handle()
{
    {
        HANDLE  hMX = ::CreateMutex(NULL, false, NULL);

        if(NULL == hMX)
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not create mutex to use to test close_handle()", winstl::error_desc_a().c_str());
        }
        else
        {
            XTESTS_TEST_BOOLEAN_TRUE(system_traits_m_t::close_handle(hMX));
        }
    }

    {
        HANDLE  hMX = ::CreateMutex(NULL, false, NULL);

        if(NULL == hMX)
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not create mutex to use to test close_handle()", winstl::error_desc_a().c_str());
        }
        else
        {
            XTESTS_TEST_BOOLEAN_TRUE(system_traits_w_t::close_handle(hMX));
        }
    }
}

static void test_last_error()
{
    { for(long i = 1; i != 10000; ++i)
    {
        const system_traits_m_t::error_type code = system_traits_m_t::error_type(i);

        system_traits_m_t::set_last_error(code);

        XTESTS_TEST_INTEGER_EQUAL(code, system_traits_m_t::get_last_error());

        system_traits_m_t::set_last_error(0);

        XTESTS_TEST_INTEGER_EQUAL(system_traits_m_t::error_type(0), system_traits_m_t::get_last_error());
    }}

    { for(long i = 1; i != 10000; ++i)
    {
        const system_traits_w_t::error_type code = system_traits_m_t::error_type(i);

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

        static const char variable[] = "test.unit.winstl.system.system_traits.2";

        if(!SetEnvironmentVariableA(variable, variable))
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
                stlsoft::std_fill_n(results, STLSOFT_NUM_ELEMENTS(results), '~');

                size_t n = system_traits_m_t::get_environment_variable(variable, results, i);

                if(i < STLSOFT_NUM_ELEMENTS(variable))
                {
                    XTESTS_TEST_INTEGER_EQUAL(i, n);
                    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(variable, results, int(i));
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
        if(!SetEnvironmentVariableA(variable, NULL))
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
                stlsoft::std_fill_n(results, STLSOFT_NUM_ELEMENTS(results), '~');

                size_t  n = system_traits_m_t::get_environment_variable(variable, results, i);

                XTESTS_TEST_INTEGER_EQUAL(0u, n);
                XTESTS_TEST_CHARACTER_EQUAL('~', results[0u]);
            }}
        }
    }

#ifndef __BORLANDC__
    // Wide string
    {
        XTESTS_TEST_INTEGER_EQUAL(0u, system_traits_w_t::get_environment_variable(L"", NULL, 0));

        // (i) one that exists

        static const wchar_t variable[] = L"test.unit.winstl.system.system_traits.2";

        if(!SetEnvironmentVariableW(variable, variable))
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not set environment variable for test", stlsoft::w2m(variable).c_str());
        }
        else
        {
            // When NULL is passed for result, return value is the required number of parameters
            XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(variable) - 1u, system_traits_w_t::get_environment_variable(variable, NULL, 0));

            wchar_t results[STLSOFT_NUM_ELEMENTS(variable) * 2];

            { for(size_t i = 1u; i != STLSOFT_NUM_ELEMENTS(results); ++i)
            {
                stlsoft::std_fill_n(results, STLSOFT_NUM_ELEMENTS(results), '~');

                size_t n = system_traits_w_t::get_environment_variable(variable, results, i);

                if(i < STLSOFT_NUM_ELEMENTS(variable))
                {
                    XTESTS_TEST_INTEGER_EQUAL(i, n);
                    XTESTS_TEST_WIDE_STRING_EQUAL_N(variable, results, int(i));
                    XTESTS_TEST_CHARACTER_EQUAL(L'~', results[i]);
                }
                else
                {
                    XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(variable) - 1, n);
                    XTESTS_TEST_WIDE_STRING_EQUAL(variable, results);
                }
            }}
        }

        // (i) one that does not exist
        if(!SetEnvironmentVariableW(variable, NULL))
        {
            XTESTS_TEST_FAIL_WITH_QUALIFIER("could not erase environment variable for test", stlsoft::w2m(variable).c_str());
        }
        else
        {
            // When NULL is passed for result, return value is the required number of parameters
            XTESTS_TEST_INTEGER_EQUAL(0u, system_traits_w_t::get_environment_variable(variable, NULL, 0));

            wchar_t results[STLSOFT_NUM_ELEMENTS(variable) * 2];

            { for(size_t i = 1u; i != STLSOFT_NUM_ELEMENTS(results); ++i)
            {
                stlsoft::std_fill_n(results, STLSOFT_NUM_ELEMENTS(results), '~');

                size_t  n = system_traits_w_t::get_environment_variable(variable, results, i);

                XTESTS_TEST_INTEGER_EQUAL(0u, n);
                XTESTS_TEST_CHARACTER_EQUAL(L'~', results[0u]);
            }}
        }
    }
#endif /* compiler */
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

/* ///////////////////////////// end of file //////////////////////////// */
