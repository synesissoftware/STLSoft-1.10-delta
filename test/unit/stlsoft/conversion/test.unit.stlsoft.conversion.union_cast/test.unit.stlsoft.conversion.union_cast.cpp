/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.conversion.union_cast.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.conversion.union_cast project.
 *
 * Created:     17th January 2009
 * Updated:     23rd June 2010
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

#include <stlsoft/conversion/union_cast.hpp>

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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.conversion.union_cast", verbosity))
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
		XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/union_cast.hpp", NULL);
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
	struct struct1
	{
	} s1;
	struct struct2
	{
	}s2;

static void test_1_01()
{
	int f = 10;
	int t = stlsoft::union_cast<int>(f);

	XTESTS_TEST_INTEGER_EQUAL(10, t);
}

static void test_1_02()
{
	wchar_t const*	ws	=	L"0";
	char const*		mbs	=	stlsoft::union_cast<char const*>(ws);

	XTESTS_TEST_POINTER_EQUAL(static_cast<void const*>(ws), static_cast<void const*>(mbs));
}

static void test_1_03()
{
	stlsoft::sint16_t f = 10;
	stlsoft::uint16_t t = stlsoft::union_cast<stlsoft::uint16_t>(f);

	XTESTS_TEST_INTEGER_EQUAL(10u, t);
}

static void test_1_04()
{
	struct1 const* f = &s1;
	struct2 const* t = stlsoft::union_cast<struct2 const*>(f);

	XTESTS_TEST_POINTER_EQUAL(static_cast<void const*>(f), static_cast<void const*>(t));
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
