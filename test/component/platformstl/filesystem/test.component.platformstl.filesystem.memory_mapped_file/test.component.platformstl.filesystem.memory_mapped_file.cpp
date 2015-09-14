/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.platformstl.filesystem.memory_mapped_file.cpp
 *
 * Purpose:     Implementation file for the test.component.platformstl.filesystem.memory_mapped_file project.
 *
 * Created:     21st January 2011
 * Updated:     21st January 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/stlsoft.h>
#if defined(STLSOFT_COMPILER_IS_GCC)
# include <platformstl/filesystem/path.hpp>
#endif

#include <platformstl/filesystem/memory_mapped_file.hpp>

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
#ifdef _STLSOFT_1_10_VER
# include <stlsoft/filesystem/FILE_stream.hpp>
#endif
#include <stlsoft/string/simple_string.hpp>
#include <stlsoft/string/string_view.hpp>
#include <platformstl/filesystem/current_directory.hpp>
#include <platformstl/filesystem/path.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_construct_1(void);
    static void test_construct_2(void);
    static void test_equal(void);
    static void test_swap_1(void);
    static void test_swap_2(void);
    static void test_swap_3(void);
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

    static char const*  argv0;

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    argv0 = argv[0];

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.platformstl.filesystem.memory_mapped_file", verbosity, NULL, NULL, NULL))
    {

        XTESTS_RUN_CASE(test_construct_1);
        XTESTS_RUN_CASE(test_construct_2);
        XTESTS_RUN_CASE(test_equal);
        XTESTS_RUN_CASE(test_swap_1);
        XTESTS_RUN_CASE(test_swap_2);
        XTESTS_RUN_CASE(test_swap_3);
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

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*platformstl/*/file_lines.hpp", NULL);
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

static void test_construct_1()
{
    platformstl::memory_mapped_file mmf(argv0);

    XTESTS_TEST_PASSED();
}

static void test_construct_2()
{
    platformstl::memory_mapped_file mmf(argv0, 0, 1024);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, mmf.size());
}

static void test_equal()
{
    platformstl::memory_mapped_file mmf1(argv0);
    platformstl::memory_mapped_file mmf2(argv0);

    XTESTS_TEST_BOOLEAN_TRUE(mmf1 == mmf2);
}

static void test_swap_1()
{
    platformstl::memory_mapped_file mmf1(argv0, 0, 1024);
    platformstl::memory_mapped_file mmf2(argv0, 0, 2048);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, mmf1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2048u, mmf2.size());

    mmf1.swap(mmf2);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2048u, mmf1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, mmf2.size());
}

static void test_swap_2()
{
    platformstl::memory_mapped_file mmf1(argv0, 0, 1024);
    platformstl::memory_mapped_file mmf2(argv0, 0, 2048);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, mmf1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2048u, mmf2.size());

    std::swap(mmf1, mmf2);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2048u, mmf1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, mmf2.size());
}

static void test_swap_3()
{
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1310

    platformstl::memory_mapped_file mmf1(argv0, 0, 1024);
    platformstl::memory_mapped_file mmf2(argv0, 0, 2048);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, mmf1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2048u, mmf2.size());

    swap(mmf1, mmf2);

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2048u, mmf1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, mmf2.size());

#endif
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


}// anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
