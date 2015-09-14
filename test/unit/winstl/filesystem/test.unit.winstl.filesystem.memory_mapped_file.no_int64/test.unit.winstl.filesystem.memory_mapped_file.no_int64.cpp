/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.filesystem.memory_mapped_file.no_int64.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.filesystem.memory_mapped_file.no_int64 project.
 *
 * Created:     23rd January 2009
 * Updated:     29th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/stlsoft.h>
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
# undef STLSOFT_CF_64BIT_INT_SUPPORT
#endif
#ifdef STLSOFT_COMPILER_IS_MSVC
# include <xlocale>
//# pragma warning(3 : 4018)
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

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_2_09(void);
    static void test_2_10(void);
    static void test_2_11(void);
    static void test_2_12(void);
    static void test_2_13(void);
    static void test_2_14(void);
    static void test_2_15(void);
    static void test_2_16(void);
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
    static int setup(void* param);
    static int teardown(void* param);

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

    if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.unit.winstl.filesystem.memory_mapped_file.no_int64", verbosity, setup, teardown, NULL))
    {
        XTESTS_RUN_CASE(test_2_09);
        XTESTS_RUN_CASE(test_2_10);
        XTESTS_RUN_CASE(test_2_11);
        XTESTS_RUN_CASE(test_2_12);
        XTESTS_RUN_CASE_THAT_THROWS(test_2_13, winstl::windows_exception);
#ifdef WINSTL_OS_IS_WIN64
        XTESTS_RUN_CASE(test_2_14);
#else
        XTESTS_RUN_CASE_THAT_THROWS(test_2_14, winstl::windows_exception);
#endif
        XTESTS_RUN_CASE(test_2_15);
        XTESTS_RUN_CASE(test_2_16);
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
    using ::xtests::c::xtests_abend;


    static char const   TEST_FILE_NAME[]    =   "test.unit.winstl.filesystem.memory_mapped_file.no_int64.DATAFILE";

static int setup(void* param)
{
    // Make a data file that is just slightly more than 4GB

    HANDLE h = ::CreateFile(TEST_FILE_NAME, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);

    if(INVALID_HANDLE_VALUE == h)
    {
        xtests_abend("could not create data file\n");

        return +1;
    }
    else
    {
        int res = 0;

        if(0 == res)
        {
            LONG    distanceToMoveLo    =   +1 * 1024 * 1024;
            LONG    distanceToMoveHigh  =   +1;

            if(!::SetFilePointer(h, distanceToMoveLo, &distanceToMoveHigh, FILE_BEGIN))
            {
                xtests_abend("could not create set file pointer for data file\n");
            }
        }
        if(0 == res)
        {
            if(!::SetEndOfFile(h))
            {
                xtests_abend("could not create set end of file for data file\n");
            }
        }

        ::CloseHandle(h);

        return res;
    }
}

static int teardown(void* param)
{
    if(!::DeleteFile(TEST_FILE_NAME))
    {
        xtests_abend("could not delete data file\n");

        return +1;
    }

    return 0;
}


static void test_2_09()
{
    winstl::memory_mapped_file  mmf(s_arg0);

    XTESTS_TEST_PASSED();
}

static void test_2_10()
{
    winstl::memory_mapped_file  mmf1(s_arg0);

    size_t      size1   =   size_t(mmf1.size());
    void const* memory1 =   mmf1.memory();

    winstl::memory_mapped_file  mmf2(s_arg0, 0, 4096);

    std::swap(mmf1, mmf2);

    XTESTS_TEST_INTEGER_EQUAL(size1, mmf2.size());
    XTESTS_TEST_POINTER_EQUAL(memory1, mmf2.memory());

    XTESTS_TEST_INTEGER_EQUAL(4u, sizeof(mmf2.size()));
}

static void test_2_11()
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

            winstl::set_file_size_by_handle_32(h3, 131072, 0);
        }

        winstl::memory_mapped_file mmf("f3", 65536, 4096);
    }
}

static void test_2_12()
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

            winstl::set_file_size_by_handle_32(h3, 65536 + 3072, 0);
        }

        winstl::memory_mapped_file mmf("f3", 65536, 4096);
    }
}

static void test_2_13()
{
    winstl::memory_mapped_file  mmf(TEST_FILE_NAME);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_2_14()
{
    winstl::memory_mapped_file  mmf(TEST_FILE_NAME, 0, 1024);

    XTESTS_TEST_PASSED();
}

static void test_2_15()
{
}

static void test_2_16()
{
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
