/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.unixstl.filesystem.memory_map_functions.cpp
 *
 * Purpose:     Implementation file for the test.component.unixstl.filesystem.memory_map_functions project.
 *
 * Created:     26th August 2010
 * Updated:     11th September 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2011, Synesis Software Pty Ltd.
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
//# undef STLSOFT_CF_64BIT_INT_SUPPORT
#endif
#ifdef STLSOFT_COMPILER_IS_MSVC
# include <xlocale>
//# pragma warning(3 : 4018)
# pragma warning(3 : 4135)
# pragma warning(3 : 4244)
#endif /* VC++ */

#include <unixstl/filesystem/memory_map_functions.h>

#ifdef STLSOFT_COMPILER_IS_MSVC
# include <fcntl.h>
# include <io.h>
# include <sys/stat.h>
# include <sys/types.h>
# define O_CREAT  _O_CREAT
# define close    _close
# define open     _open
# define write    _write
#endif /* VC++ */

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

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2(void);
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

    static int setup(void* param);
    static int teardown(void* param);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.unixstl.filesystem.memory_map_functions", verbosity, setup, teardown, NULL))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
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

    using stlsoft::ss_uint8_t;
    using xtests::c::xtests_abend;

static char const   TEST_FILE_NAME[]    =   "test.component.unixstl.filesystem.memory_map_functions.C.DATAFILE";
#ifdef __cplusplus
static size_t const TEST_BUFFER_SIZE    =   0x1000;
static size_t const TEST_NUM_BUFFERS    =   0x100;
static size_t const TEST_FILE_SIZE      =   TEST_BUFFER_SIZE * TEST_NUM_BUFFERS;
#else /* ? __cplusplus */
# define TEST_BUFFER_SIZE                   (0x1000)
# define TEST_NUM_BUFFERS                   (0x100)
# define TEST_FILE_SIZE                     stlsoft_c_cast(size_t, TEST_BUFFER_SIZE * TEST_NUM_BUFFERS)
#endif /* __cplusplus */

static int setup(void* param)
{
    int h = open(
            TEST_FILE_NAME
        ,   O_CREAT | O_TRUNC | O_RDWR | O_BINARY
        ,   S_IREAD | S_IWRITE
        );

    if(-1 == h)
    {
        xtests_abend("could not create test file\n");

        return 1;
    }
    else
    {
        ss_uint8_t  buffer[TEST_BUFFER_SIZE];
        int         i;

        for(i = 0; i != TEST_NUM_BUFFERS; ++i)
        {
            memset(buffer, i, sizeof(buffer));

            if(sizeof(buffer) != write(h, buffer, sizeof(buffer)))
            {
                xtests_abend("could not write to test file");

                return 1;
            }

#if 0
            flush(h);
#endif /* 0 */
        }

        close(h);

        return 0;
    }
}

static int teardown(void* param)
{
    if(0 != remove(TEST_FILE_NAME))
    {
        xtests_abend("could not delete test file\n");

        return 1;
    }

    return 0;
}

static void test_1_0()
{
    size_t  viewSize;
    void*   view = unixstl::map_readonly_view_of_file_by_name(TEST_FILE_NAME, O_RDONLY, 0, 0, 0, &viewSize);

    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, view);

    if(NULL != view)
    {
        ss_uint8_t    buffer[TEST_BUFFER_SIZE];
        int           i;
        size_t        base;

        for(i = 0, base = 0; base < viewSize; base += TEST_BUFFER_SIZE, ++i)
        {
            memset(buffer, i, sizeof(buffer));

            { size_t j; for(j = 0; j != STLSOFT_NUM_ELEMENTS(buffer); ++j)
            {
                ss_uint8_t const* v = stlsoft_static_cast(ss_uint8_t const*, view) + base;

                XTESTS_TEST_INTEGER_EQUAL((int)buffer[j], (int)*v);
            }}
        }

        unixstl::unmap_view_of_file(view, viewSize);
    }
}

static void test_1_1()
{
    size_t      viewSize;
    size_t      offset      =   65536;
    size_t      requestSize =   8092;
    void*       view        =   unixstl::map_readonly_view_of_file_by_name(TEST_FILE_NAME, O_RDONLY, 0, offset, requestSize, &viewSize);
    int const   err         =   errno;

    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, view);
    XTESTS_TEST_INTEGER_EQUAL(requestSize, viewSize);

    if(NULL != view)
    {
        ss_uint8_t  buffer[TEST_BUFFER_SIZE];
        int         i;
        size_t      base;

        for(i = (offset / TEST_BUFFER_SIZE), base = 0; base < viewSize; base += TEST_BUFFER_SIZE, ++i)
        {
            memset(buffer, i, sizeof(buffer));

            { size_t j; for(j = 0; j != STLSOFT_NUM_ELEMENTS(buffer); ++j)
            {
                ss_uint8_t const* v = stlsoft_static_cast(ss_uint8_t const*, view) + base;

                XTESTS_TEST_INTEGER_EQUAL((int)buffer[j], (int)*v);
            }}
        }

        unixstl::unmap_view_of_file(view, viewSize);
    }
}

static void test_1_2()
{
    size_t requestSize;

    for(requestSize = 0; requestSize <= (65536 * 1024); requestSize = (0 == requestSize) ? 0x1 : (requestSize << 1))
    {
        size_t      viewSize;
        size_t      offset      =   65536;
        void*       view        =   unixstl::map_readonly_view_of_file_by_name(TEST_FILE_NAME, O_RDONLY, 0, offset, requestSize, &viewSize);
        int const   err         =   errno;

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, view);
        if(0 == requestSize)
        {
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE - offset, viewSize);
        }
        else if(requestSize <= TEST_FILE_SIZE - offset)
        {
            XTESTS_TEST_INTEGER_EQUAL(requestSize, viewSize);
        }
        else
        {
            XTESTS_TEST_INTEGER_EQUAL(TEST_FILE_SIZE - offset, viewSize);
        }

        if(NULL != view)
        {
            ss_uint8_t  buffer[TEST_BUFFER_SIZE];
            int         i;
            size_t      base;

            for(i = (offset / TEST_BUFFER_SIZE), base = 0; base < viewSize; base += TEST_BUFFER_SIZE, ++i)
            {
                memset(buffer, i, sizeof(buffer));

                { size_t j; for(j = 0; j != STLSOFT_NUM_ELEMENTS(buffer); ++j)
                {
                    ss_uint8_t const* v = stlsoft_static_cast(ss_uint8_t const*, view) + base;

                    XTESTS_TEST_INTEGER_EQUAL((int)buffer[j], (int)*v);
                }}
            }

            unixstl::unmap_view_of_file(view, viewSize);
        }
    }
}

static void test_1_3()
{
    size_t  viewSizes[10];
    void*   views[10];
    size_t  j = 0;

    STLSOFT_STATIC_ASSERT(STLSOFT_NUM_ELEMENTS(viewSizes) == STLSOFT_NUM_ELEMENTS(views));

    { size_t i; for(i = 0; i != STLSOFT_NUM_ELEMENTS(viewSizes); ++i, ++j)
    {
        views[i] = unixstl::map_readonly_view_of_file_by_name(TEST_FILE_NAME, O_RDONLY, 0, 0, 0, &viewSizes[i]);

        if(NULL == views[i])
        {
            break;
        }
    }}

    { size_t i; for(i = 1; i < j; ++i)
    {
        XTESTS_TEST_BOOLEAN_TRUE(0 == memcmp(views[i], views[i-1], viewSizes[i]));
    }}

    { size_t i; for(i = 0; i != j; ++i)
    {
        unixstl::unmap_view_of_file(views[i], viewSizes[i]);
    }}
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
