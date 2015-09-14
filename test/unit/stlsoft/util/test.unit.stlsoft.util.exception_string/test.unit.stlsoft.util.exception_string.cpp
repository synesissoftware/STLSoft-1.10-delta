/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.util.exception_string.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.util.exception_string project.
 *
 * Created:     3rd February 2011
 * Updated:     3rd February 2011
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

#define _SCL_SECURE_NO_WARNINGS

#include <stlsoft/util/exception_string.hpp>

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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.util.exception_string", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/exception_string.hpp", NULL);
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
    using stlsoft::exception_string;

static void test_1_0()
{
    exception_string    xs;

    STLSOFT_SUPPRESS_UNUSED(xs);

    XTESTS_TEST_PASSED();
}

static void test_1_1()
{
    exception_string    xs;

    XTESTS_TEST_BOOLEAN_TRUE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, xs.size());
}

static void test_1_2()
{
    exception_string    xs("abc");

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, xs.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", xs);
}

static void test_1_3()
{
    exception_string    xs("abcdefghijklmno", 13u);

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(13u, xs.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklm", xs);
}

static void test_1_4()
{
    exception_string    xs("abcdefghijklmno", 3u);

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, xs.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", xs);
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



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
