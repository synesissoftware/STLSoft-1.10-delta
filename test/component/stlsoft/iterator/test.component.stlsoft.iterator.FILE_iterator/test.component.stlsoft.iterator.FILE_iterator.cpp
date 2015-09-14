/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.stlsoft.iterator.FILE_iterator.cpp
 *
 * Purpose:     Implementation file for the test.component.stlsoft.iterator.FILE_iterator project.
 *
 * Created:     19th May 2009
 * Updated:     11th August 2010
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

#include <stlsoft/iterator/FILE_iterator.hpp>

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
#include <stlsoft/internal/safestr.h>
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <platformstl/filesystem/file_lines.hpp>
//#include <winstl/filesystem/current_directory.hpp>
//#include <winstl/system/windows_directory.hpp>

/* Standard C++ Header Files */
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_ints(void);
    static void test_doubles(void);
    static void test_1_03(void);
    static void test_1_04(void);
    static void test_1_05(void);
    static void test_1_06(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.stlsoft.iterator.FILE_iterator", verbosity))
    {
        XTESTS_RUN_CASE(test_ints);
        XTESTS_RUN_CASE(test_doubles);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);
        XTESTS_RUN_CASE(test_1_06);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/FILE_iterator.hpp", NULL);
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

#if defined(STLSOFT_COMPILER_IS_MWERKS)
    void remove(char const* path)
    {
        ::remove(path);
    }
#endif /* compiler */

static void test_ints()
{
    char const* fileName = "abc.txt";

# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
    FILE*   f;

    if(0 != fopen_s(&f, fileName, "w"))
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
    FILE*   f = ::fopen(fileName, "w");

    if(NULL == f)
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    {
# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
        XTESTS_FAIL("failed to open text file for writing");
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
        XTESTS_FAIL_WITH_QUALIFIER("failed to open text file for writing", ::strerror(errno));
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1(fileName, remove);

        {
            stlsoft::scoped_handle<FILE*> scoper2(f, ::fclose);

            std::vector<int> values;

            values.push_back(1);
            values.push_back(2);
            values.push_back(3);

            stlsoft::std_copy(  values.begin(), values.end()
                            ,   stlsoft::FILE_iterator<int>(f, "\t%d\n"));
        }

        platformstl::file_lines lines(fileName);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, lines.size()));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\t1", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\t2", lines[1]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\t3", lines[2]);
    }
}

static void test_doubles()
{
    char const* fileName = "abc.txt";

# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
    FILE*   f;

    if(0 != fopen_s(&f, fileName, "w"))
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
    FILE*   f = ::fopen(fileName, "w");

    if(NULL == f)
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    {
# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
        XTESTS_FAIL("failed to open text file for writing");
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
        XTESTS_FAIL_WITH_QUALIFIER("failed to open text file for writing", ::strerror(errno));
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    }
    else
    {
        stlsoft::scoped_handle<char const*> scoper1(fileName, remove);

        {
            stlsoft::scoped_handle<FILE*> scoper2(f, ::fclose);

            std::vector<double> values;

            values.push_back(0.102);
            values.push_back(123.456);
            values.push_back(-123.456);

            stlsoft::std_copy(  values.begin(), values.end()
                            ,   stlsoft::FILE_iterator<double>(f, "\t%3.3f\n"));
        }

        platformstl::file_lines lines(fileName);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, lines.size()));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\t0.102", lines[0]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\t123.456", lines[1]);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\t-123.456", lines[2]);
    }
}

static void test_1_03()
{
}

static void test_1_04()
{
}

static void test_1_05()
{
}

static void test_1_06()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
