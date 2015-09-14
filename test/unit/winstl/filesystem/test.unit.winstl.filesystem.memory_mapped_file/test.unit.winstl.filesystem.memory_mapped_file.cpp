/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.filesystem.memory_mapped_file.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.filesystem.memory_mapped_file project.
 *
 * Created:     23rd January 2009
 * Updated:     5th June 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/stlsoft.h>
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
# include <xlocale>
# include <xlocnum>
# pragma warning(3 : 4018)
# pragma warning(3 : 4135)
# pragma warning(3 : 4244)
#endif
#include <winstl/filesystem/memory_mapped_file.hpp>

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
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <winstl/filesystem/file_creation_functions.h>
#include <winstl/filesystem/file_size_functions.h>
#ifdef _DEBUG
# include <winstl/filesystem/memory_map_functions.h>
#endif /* _DEBUG */
#include <winstl/system/system_info.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_2_01(void);
    static void test_2_02(void);
    static void test_2_03(void);
    static void test_2_07_500B(void);
    static void test_2_07_5kB(void);
    static void test_2_07_5MB(void);
    static void test_2_07_5GB(void);
    static void test_2_08(void);
    static void test_2_09(void);
    static void test_2_13(void);
    static void test_2_14(void);
    static void test_2_15(void);
    static void test_2_16_bad_offset(void);
    static void test_2_17(void);
    static void test_2_18(void);
    static void test_2_19(void);
    static void test_2_20(void);
    static void test_2_21(void);
    static void test_2_22(void);
    static void test_2_23(void);
    static void test_2_24(void);
    static void test_2_25(void);
    static void test_2_26(void);
    static void test_2_27(void);
    static void test_2_28(void);
    static void test_2_29(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Statics
 */

namespace
{

    static char s_arg0[_MAX_PATH + 1];

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    ::lstrcpyA(s_arg0, argv[0]);

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.filesystem.memory_mapped_file", verbosity))
    {
        XTESTS_RUN_CASE(test_2_01);
        XTESTS_RUN_CASE(test_2_02);
        XTESTS_RUN_CASE(test_2_03);
        XTESTS_RUN_CASE(test_2_07_500B);
        XTESTS_RUN_CASE(test_2_07_5kB);
        XTESTS_RUN_CASE(test_2_07_5MB);
        XTESTS_RUN_CASE(test_2_07_5GB);
#ifdef WINSTL_MMF_DONT_TRIM_REQUEST_SIZE
        XTESTS_RUN_CASE_THAT_THROWS(test_2_08, winstl::windows_exception);
#else
        XTESTS_RUN_CASE(test_2_08);
#endif
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        XTESTS_RUN_CASE_THAT_THROWS(test_2_09, winstl::windows_exception);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        XTESTS_RUN_CASE(test_2_09);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        XTESTS_RUN_CASE(test_2_13);
        XTESTS_RUN_CASE(test_2_14);
        XTESTS_RUN_CASE(test_2_15);
        XTESTS_RUN_CASE(test_2_16_bad_offset);
        XTESTS_RUN_CASE(test_2_17);
        XTESTS_RUN_CASE(test_2_18);
        XTESTS_RUN_CASE(test_2_19);
        XTESTS_RUN_CASE(test_2_20);
        XTESTS_RUN_CASE(test_2_21);
        XTESTS_RUN_CASE(test_2_22);
        XTESTS_RUN_CASE(test_2_23);
        XTESTS_RUN_CASE(test_2_24);
        XTESTS_RUN_CASE(test_2_25);
        XTESTS_RUN_CASE(test_2_26);
        XTESTS_RUN_CASE(test_2_27);
        XTESTS_RUN_CASE(test_2_28);
        XTESTS_RUN_CASE(test_2_29);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/memory_mapped_file.hpp", NULL);
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
    using winstl::ws_uint32_t;
    using winstl::ws_uint64_t;
    using winstl::ws_uintptr_t;

    void read_block(
        void const*     pcv
    , ws_uintptr_t  size
    )
    {
        using stlsoft::byte_t;

        byte_t const* pcb = stlsoft_static_cast(byte_t const*, pcv);
        byte_t          r = 0;

        { for(ws_uintptr_t i = 0; i != size; ++i, ++pcb)
        {
            r = static_cast<byte_t>(r + *pcb);

            STLSOFT_SUPPRESS_UNUSED(r);
        }}
    }


static void test_2_01()
{
    // Open an uneven sized file

    winstl::memory_mapped_file  mmf(s_arg0);

    XTESTS_TEST_PASSED();
}

static void test_2_02()
{
    // Open an even part of an uneven sized file, and do a swap()

    winstl::memory_mapped_file  mmf1(s_arg0);

    size_t      size1 = size_t(mmf1.size());
    void const* memory1 = mmf1.memory();

    winstl::memory_mapped_file  mmf2(s_arg0, 0, 4096);

    std::swap(mmf1, mmf2);

    XTESTS_TEST_INTEGER_EQUAL(size1, mmf2.size());
    XTESTS_TEST_POINTER_EQUAL(memory1, mmf2.memory());
}

static void test_2_03()
{
    // Open an uneven part of an uneven sized file, and do a swap()

    winstl::memory_mapped_file  mmf1(s_arg0);

    size_t      size1 = size_t(mmf1.size());
    void const* memory1 = mmf1.memory();

    winstl::memory_mapped_file  mmf2(s_arg0, 0, 999);

    std::swap(mmf1, mmf2);

    XTESTS_TEST_INTEGER_EQUAL(size1, mmf2.size());
    XTESTS_TEST_POINTER_EQUAL(memory1, mmf2.memory());
}

static void test_2_07_500B()
{
    // Create a 500 byte file

    char const                  TEST_FILE_NAME[]    = "test-500B";
    ws_uintptr_t const  TEST_FILE_SIZE      = 500;

    HANDLE h = winstl::file_create_always(TEST_FILE_NAME, GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("could not create test file", TEST_FILE_NAME);
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1(TEST_FILE_NAME, ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h, ::CloseHandle, INVALID_HANDLE_VALUE);

            winstl::file_set_size_by_handle_64(h, TEST_FILE_SIZE);
        }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, TEST_FILE_SIZE);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 333);

            XTESTS_TEST_INTEGER_EQUAL(333u, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 1024);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 10 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

static void test_2_07_5kB()
{
    // Create a 5kB byte file

    char const                  TEST_FILE_NAME[]    = "test-5kB";
    ws_uintptr_t const  TEST_FILE_SIZE      = 5120;

    HANDLE h = winstl::file_create_always(TEST_FILE_NAME, GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("could not create test file", TEST_FILE_NAME);
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1(TEST_FILE_NAME, ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h, ::CloseHandle, INVALID_HANDLE_VALUE);

            winstl::file_set_size_by_handle_64(h, TEST_FILE_SIZE);
        }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, TEST_FILE_SIZE);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 333);

            XTESTS_TEST_INTEGER_EQUAL(333u, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 1024);

            XTESTS_TEST_INTEGER_EQUAL(1024u, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 10 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

static void test_2_07_5MB()
{
    // Create a 5MB byte file

    char const                  TEST_FILE_NAME[]    = "test-5MB";
    ws_uintptr_t const  TEST_FILE_SIZE      = 5u * 1024 * 1024;

    HANDLE h = winstl::file_create_always(TEST_FILE_NAME, GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("could not create test file", TEST_FILE_NAME);
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1(TEST_FILE_NAME, ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h, ::CloseHandle, INVALID_HANDLE_VALUE);

            winstl::file_set_size_by_handle_64(h, TEST_FILE_SIZE);
        }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, TEST_FILE_SIZE);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 333);

            XTESTS_TEST_INTEGER_EQUAL(333u, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 1024);

            XTESTS_TEST_INTEGER_EQUAL(1024u, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 10 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(10u * 1024, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 10u * 1024 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        size_t const allocGran = winstl::system_info::allocation_granularity();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, allocGran, 0);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE - allocGran, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 10 * allocGran, 0);

            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE - (10 * allocGran), mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 10 * allocGran, 333);

            XTESTS_TEST_INTEGER_EQUAL(333u, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

static void test_2_07_5GB()
{
    // Create a 5GB byte file

    char const                  TEST_FILE_NAME[]    = "test-5GB";
    ws_uint64_t const   TEST_FILE_SIZE      = ws_uint64_t(5u) * 1024 * 1024 * 1024;
    ws_uintptr_t const  VIEW_SIZE               = ws_uintptr_t(5u) * 1024 * 1024;

    HANDLE h = winstl::file_create_always(TEST_FILE_NAME, GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("could not create test file", TEST_FILE_NAME);
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1(TEST_FILE_NAME, ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h, ::CloseHandle, INVALID_HANDLE_VALUE);

            if(!winstl::file_set_size_by_handle_64(h, TEST_FILE_SIZE))
            {
                return;
            }
        }

        // (i) load the view size (5MiB)

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, VIEW_SIZE);

            XTESTS_TEST_INTEGER_EQUAL(VIEW_SIZE, mmf.size());
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
            XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, long(mmf.lastStatusCode()));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (ii) load the whole file (5GiB) explicitly

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0);

# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_FAIL("should not get here");
# endif /* WINSTL_OS_IS_WIN64 */
        }
        catch(winstl::windows_exception& x)
        {
# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_FAIL("should not get here");
            STLSOFT_SUPPRESS_UNUSED(x);
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(x.get_error_code()));
# endif /* WINSTL_OS_IS_WIN64 */
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0);

# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_INTEGER_EQUAL(0u, mmf.size());
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(mmf.lastStatusCode()));
# endif /* WINSTL_OS_IS_WIN64 */
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */



        // (iii) load the whole file (5GiB) implicitly

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME);

# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_FAIL("should not get here");
# endif /* WINSTL_OS_IS_WIN64 */
        }
        catch(winstl::windows_exception& x)
        {
# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_FAIL("should not get here");
            STLSOFT_SUPPRESS_UNUSED(x);
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(x.get_error_code()));
# endif /* WINSTL_OS_IS_WIN64 */
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME);

# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE, mmf.size());
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_INTEGER_EQUAL(0u, mmf.size());
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(mmf.lastStatusCode()));
# endif /* WINSTL_OS_IS_WIN64 */
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (iv) load less than a page size (333B)

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 333);

            XTESTS_TEST_INTEGER_EQUAL(333u, mmf.size());
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
            XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, long(mmf.lastStatusCode()));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (v) load less than a page size (1KiB)

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 1024);

            XTESTS_TEST_INTEGER_EQUAL(1024u, mmf.size());
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
            XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, long(mmf.lastStatusCode()));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (vi) load a smallish size (16KiB)

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 10 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(10u * 1024, mmf.size());
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
            XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, long(mmf.lastStatusCode()));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (vii) load a largish size (10MiB)

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 10u * 1024 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(10u * 1024 * 1024, mmf.size());
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
            XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, long(mmf.lastStatusCode()));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (vii) load all from offset of 1x alloc-gran size

        size_t const allocGran = winstl::system_info::allocation_granularity();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, allocGran, 0);

# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE - allocGran, mmf.size());
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_FAIL("should not get here");
# endif /* WINSTL_OS_IS_WIN64 */
        }
        catch(winstl::windows_exception& x)
        {
# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_FAIL("should not get here");
            STLSOFT_SUPPRESS_UNUSED(x);
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(x.get_error_code()));
# endif /* WINSTL_OS_IS_WIN64 */
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, allocGran, 0);

# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE - allocGran, mmf.size());
            XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, long(mmf.lastStatusCode()));
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_INTEGER_EQUAL(0u, mmf.size());
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(mmf.lastStatusCode()));
# endif /* WINSTL_OS_IS_WIN64 */
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (viii) load all from offset of 10x alloc-gran size

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 10 * allocGran, 0);

# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE - (10 * allocGran), mmf.size());
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_FAIL("should not get here");
# endif /* WINSTL_OS_IS_WIN64 */
        }
        catch(winstl::windows_exception& x)
        {
# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_FAIL("should not get here");
            STLSOFT_SUPPRESS_UNUSED(x);
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(x.get_error_code()));
# endif /* WINSTL_OS_IS_WIN64 */
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 10 * allocGran, 0);

# ifdef WINSTL_OS_IS_WIN64
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE - (10 * allocGran), mmf.size());
            XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, long(mmf.lastStatusCode()));
# else /* ? WINSTL_OS_IS_WIN64 */
            XTESTS_TEST_INTEGER_EQUAL(0u, mmf.size());
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(mmf.lastStatusCode()));
# endif /* WINSTL_OS_IS_WIN64 */
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (ix) load less than a page size (333B) from offset of 10x alloc-gran size

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 10 * allocGran, 333);

            XTESTS_TEST_INTEGER_EQUAL(333u, mmf.size());
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception&)
        {
            XTESTS_TEST_FAIL("should not get here");
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (x) load a largish size (1GiB)
        //
        // may fail to load, in which case we want to see ERROR_NOT_ENOUGH_MEMORY

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 1u * 1024 * 1024 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(1u * 1024 * 1024 * 1024, mmf.size());
        }
        catch(winstl::windows_exception& x)
        {
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(x.get_error_code()));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 1u * 1024 * 1024 * 1024);

            if(0 == mmf.size())
            {
                XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(mmf.lastStatusCode()));
            }
            else
            {
                XTESTS_TEST_INTEGER_EQUAL(1u * 1024 * 1024 * 1024, mmf.size());
            }
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */



        // (xi-a) load a largish size (0x7FFDFFFF)
        //
        // may fail to load, in which case we want to see ERROR_NOT_ENOUGH_MEMORY

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0x7FFDFFFF);

            XTESTS_TEST_INTEGER_EQUAL(0x7FFDFFFFu, mmf.size());
        }
        catch(winstl::windows_exception& x)
        {
            XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(x.get_error_code()));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0x7FFDFFFF);

            if(0 == mmf.size())
            {
                XTESTS_TEST_INTEGER_EQUAL(ERROR_NOT_ENOUGH_MEMORY, long(mmf.lastStatusCode()));
            }
            else
            {
                XTESTS_TEST_INTEGER_EQUAL(0x7FFDFFFFu, mmf.size());
            }
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */



        // (xi-b) load a largish size (0x7FFE0000)
        //
        // may fail to load, in which case we want to see ERROR_NOT_ENOUGH_MEMORY

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0x7FFE0000);

      XTESTS_TEST_INTEGER_EQUAL(0x7FFE0000u, mmf.size());
    }
    catch(winstl::windows_exception& x)
    {
        XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(ERROR_NOT_ENOUGH_MEMORY, ERROR_INVALID_PARAMETER, long(x.get_error_code()));
    }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 0x7FFE0000);

        if(0 == mmf.size())
        {
            XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(ERROR_NOT_ENOUGH_MEMORY, ERROR_INVALID_PARAMETER, mmf.lastStatusCode());
        }
        else
        {
            XTESTS_TEST_INTEGER_EQUAL(0x7FFE0000u, mmf.size());
        }
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */



        // (xii) load a largish size (2GiB)
        //
        // may fail to load, in which case we want to see ERROR_NOT_ENOUGH_MEMORY

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 2u * 1024 * 1024 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(2u * 1024 * 1024 * 1024, mmf.size());
        }
        catch(winstl::windows_exception& x)
        {
            XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(ERROR_NOT_ENOUGH_MEMORY, ERROR_INVALID_PARAMETER, long(x.get_error_code()));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 2u * 1024 * 1024 * 1024);

            if(0 == mmf.size())
            {
                XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(ERROR_NOT_ENOUGH_MEMORY, ERROR_INVALID_PARAMETER, mmf.lastStatusCode());
            }
            else
            {
                XTESTS_TEST_INTEGER_EQUAL(2u * 1024 * 1024 * 1024, mmf.size());
            }
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


        // (xiii) load a largish size (3GiB)
        //
        // will fail to load on Win32, in which case we want to see ERROR_INVALID_PARAMETER
        // may fail to load on Win64, in which case we want to see ERROR_NOT_ENOUGH_MEMORY

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 3u * 1024 * 1024 * 1024);

            XTESTS_TEST_INTEGER_EQUAL(3u * 1024 * 1024 * 1024, mmf.size());
        }
        catch(winstl::windows_exception& x)
        {
            XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(ERROR_NOT_ENOUGH_MEMORY, ERROR_INVALID_PARAMETER, long(x.get_error_code()));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf(TEST_FILE_NAME, 0, 3u * 1024 * 1024 * 1024);

            if(0 == mmf.size())
            {
                XTESTS_TEST_INTEGER_EQUAL_ANY_OF2(ERROR_NOT_ENOUGH_MEMORY, ERROR_INVALID_PARAMETER, mmf.lastStatusCode());
            }
            else
            {
                XTESTS_TEST_INTEGER_EQUAL(3u * 1024 * 1024 * 1024, mmf.size());
            }
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
}

static void test_2_08()
{
    // Open all of a 

    HANDLE h3 = winstl::file_create_always("f3", GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h3)
    {
        XTESTS_TEST_FAIL("could not create test file f3");
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1("f3", ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h3, ::CloseHandle, INVALID_HANDLE_VALUE);

            winstl::file_set_size_by_handle_64(h3, 131072);
        }

        {
            winstl::memory_mapped_file mmf("f3", 131072, 10);

#ifdef WINSTL_MMF_DONT_TRIM_REQUEST_SIZE
            XTESTS_TEST_FAIL("should not get here");
#else
            XTESTS_TEST_INTEGER_EQUAL(0u, mmf.size());
#endif
        }
    }
}

static void test_2_09()
{
    // Open all of a 

    HANDLE h3 = winstl::file_create_always("f3", GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h3)
    {
        XTESTS_TEST_FAIL("could not create test file f3");
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1("f3", ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h3, ::CloseHandle, INVALID_HANDLE_VALUE);

            winstl::file_set_size_by_handle_64(h3, 131072);
        }

        {
            winstl::memory_mapped_file mmf("f3", 131072 + 65536, 0);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            XTESTS_TEST_FAIL("should not get here");
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            XTESTS_TEST_INTEGER_NOT_EQUAL(ERROR_SUCCESS, long(mmf.lastStatusCode()));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
    }
}

static void test_2_13()
{
    HANDLE h3 = winstl::file_create_always("f3", GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h3)
    {
        XTESTS_TEST_FAIL("could not create test file f3");
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1("f3", ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h3, ::CloseHandle, INVALID_HANDLE_VALUE);

            winstl::file_set_size_by_handle_64(h3, 65536 + 3072);
        }

        winstl::memory_mapped_file mmf("f3", 65536, 4096);
    }
}

static void test_2_14()
{
    HANDLE h3 = winstl::file_create_always("f3", GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h3)
    {
        XTESTS_TEST_FAIL("could not create test file f3");
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1("f3", ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h3, ::CloseHandle, INVALID_HANDLE_VALUE);

#if 0
            ws_uint64_t size    = ws_uint64_t((4 * 1024) + 512) * 1024 * 1024;
#else /* ? 0 */
            ws_uint64_t size    = ws_uint64_t((5 * 1024) +  12) * 1024 * 1024;
#endif /* 0 */
            ws_uint32_t size32  = stlsoft_static_cast(ws_uint32_t, size);

            ws_uint32_t oneMB = 1024 * 1024;

            winstl::file_set_size_by_handle_64(h3, size);

#ifdef _DEBUG
            HANDLE  hMap    = ::CreateFileMapping(h3, NULL, PAGE_READONLY, 0, 0, NULL);
            DWORD e     = ::GetLastError();

            void* view1 = winstl::winstl_C_call_MapViewOfFile_offset_64_(hMap, FILE_MAP_READ, 0 * 65536, oneMB);
                    e   = ::GetLastError();
                    if(ERROR_SUCCESS == e)
                    {
                        read_block(view1, oneMB);
                    }
            void* view2 = winstl::winstl_C_call_MapViewOfFile_offset_64_(hMap, FILE_MAP_READ, 1 * 65536, oneMB);
                    e   = ::GetLastError();
                    if(ERROR_SUCCESS == e)
                    {
                        read_block(view2, oneMB);
                    }
            void* view3 = winstl::winstl_C_call_MapViewOfFile_offset_64_(hMap, FILE_MAP_READ, ws_uint64_t(65536) * 65536, oneMB);
                    e   = ::GetLastError();
                    if(ERROR_SUCCESS == e)
                    {
                        read_block(view3, oneMB);
                    }
            void* view4 = winstl::winstl_C_call_MapViewOfFile_offset_64_(hMap, FILE_MAP_READ, 0 * 65536, size32);
                    e   = ::GetLastError();
                    if(ERROR_SUCCESS == e)
                    {
                        read_block(view4, size32);
                    }
            void* view5 = winstl::winstl_C_call_MapViewOfFile_offset_64_(hMap, FILE_MAP_READ, size - 65536, 65536);
                    e   = ::GetLastError();
                    if(ERROR_SUCCESS == e)
                    {
                        read_block(view5, 65536);
                    }

            UnmapViewOfFile(view5);
            UnmapViewOfFile(view4);
            UnmapViewOfFile(view3);
            UnmapViewOfFile(view2);
            UnmapViewOfFile(view1);
            CloseHandle(hMap);
#else /* ? _DEBUG */
            STLSOFT_SUPPRESS_UNUSED(size32);
            STLSOFT_SUPPRESS_UNUSED(oneMB);
#endif /* _DEBUG */
        }

#ifdef WINSTL_OS_IS_WIN64
        winstl::memory_mapped_file mmf("f3");

        { for(winstl::memory_mapped_file::size_type i = 0; i < mmf.size(); i = (i + 1) * 10)
        {
            unsigned char const*    p1  = static_cast<unsigned char const*>(mmf.memory());
            unsigned char*          p2  = const_cast<unsigned char*>(p1);

            p2 += i;

            unsigned char uc = *p2;
        }}
#else
#endif
    }
}

static void test_2_15()
{
    HANDLE h3 = winstl::file_create_always("f3", GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h3)
    {
        XTESTS_TEST_FAIL("could not create test file f3");
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1("f3", ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h3, ::CloseHandle, INVALID_HANDLE_VALUE);

            if(!winstl::file_set_size_by_handle_64(h3, stlsoft::ss_uint64_t((4 * 1024) + 100) * 1024 * 1024))
            {
                return;
            }
        }

        winstl::memory_mapped_file mmf("f3", 65536, 4096);
    }
}

static void test_2_16_bad_offset()
{
    size_t const allocGran = winstl::system_info::allocation_granularity();

    HANDLE h = winstl::file_create_always("f-2-16", GENERIC_WRITE | GENERIC_READ, 0, 0);

    if(INVALID_HANDLE_VALUE == h)
    {
        XTESTS_TEST_FAIL("could not create test file f-2-16");
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1("f-2-16", ::DeleteFile);

        {
            stlsoft::scoped_handle<HANDLE>  scoper2(h, ::CloseHandle, INVALID_HANDLE_VALUE);

            if(!winstl::file_set_size_by_handle_64(h, stlsoft::ss_uint64_t((4 * 1024) + 100) * 1024 * 1024))
            {
                return;
            }
        }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        {
            winstl::memory_mapped_file mmf("f-2-16", allocGran - 1, allocGran);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            XTESTS_TEST_INTEGER_EQUAL(ERROR_MAPPED_ALIGNMENT, long(mmf.lastStatusCode()));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        catch(winstl::windows_exception& x)
        {
            XTESTS_TEST_INTEGER_EQUAL(ERROR_MAPPED_ALIGNMENT, long(x.get_error_code()));
        }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

}

static void test_2_17()
{
}

static void test_2_18()
{
}

static void test_2_19()
{
}

static void test_2_20()
{
}

static void test_2_21()
{
}

static void test_2_22()
{
}

static void test_2_23()
{
}

static void test_2_24()
{
}

static void test_2_25()
{
}

static void test_2_26()
{
}

static void test_2_27()
{
}

static void test_2_28()
{
}

static void test_2_29()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
