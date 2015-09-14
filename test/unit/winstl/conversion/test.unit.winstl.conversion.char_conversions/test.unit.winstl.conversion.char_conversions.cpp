/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.conversion.char_conversions.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.conversion.char_conversions project.
 *
 * Created:     29th January 2011
 * Updated:     29th January 2011
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

#include <winstl/conversion/char_conversions.hpp>

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
#include <stlsoft/algorithms/std/alt.hpp>
#include <stlsoft/iterators/null_output_iterator.hpp>
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <algorithm>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_01(void);
    static void test_1_02(void);
    static void test_1_03(void);
    static void test_1_04(void);
    static void test_1_05(void);
    static void test_1_06(void);
    static void test_1_07(void);
    static void test_1_08(void);
    static void test_1_09(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.conversion.char_conversions", verbosity))
    {
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);
        XTESTS_RUN_CASE(test_1_06);
        XTESTS_RUN_CASE(test_1_07);
        XTESTS_RUN_CASE(test_1_08);
        XTESTS_RUN_CASE(test_1_09);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/char_conversions.hpp", NULL);
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

static void test_1_01()
{
	winstl::a2w		v("");

	XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"", v);

	XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len(v));
}

static void test_1_02()
{
	winstl::a2w		v("a");

	XTESTS_TEST_INTEGER_EQUAL(1u, v.size());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"a", v);

	XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::c_str_len(v));
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

static void test_1_07()
{
}

static void test_1_08()
{
}

static void test_1_09()
{
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
