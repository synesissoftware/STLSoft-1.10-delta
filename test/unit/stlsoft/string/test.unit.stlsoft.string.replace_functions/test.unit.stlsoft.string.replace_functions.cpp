/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.replace_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.replace_functions project.
 *
 * Created:     12th May 2010
 * Updated:     12th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/string/replace_functions.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 */

#if defined(__BORLANDC__)
# pragma warn -8092
#endif /* compiler */

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

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_1_00(void);
	static void test_1_01(void);
	static void test_1_02(void);
	static void test_1_03(void);
	static void test_1_04(void);
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

	static void test_2_00(void);
	static void test_2_01(void);
	static void test_2_02(void);
	static void test_2_03(void);
	static void test_2_04(void);
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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.string.replace_functions", verbosity))
	{
		XTESTS_RUN_CASE(test_1_00);
		XTESTS_RUN_CASE(test_1_01);
		XTESTS_RUN_CASE(test_1_02);
		XTESTS_RUN_CASE(test_1_03);
		XTESTS_RUN_CASE(test_1_04);
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

		XTESTS_RUN_CASE(test_2_00);
		XTESTS_RUN_CASE(test_2_01);
		XTESTS_RUN_CASE(test_2_02);
		XTESTS_RUN_CASE(test_2_03);
		XTESTS_RUN_CASE(test_2_04);
		XTESTS_RUN_CASE(test_2_10);
		XTESTS_RUN_CASE(test_2_11);
		XTESTS_RUN_CASE(test_2_12);
		XTESTS_RUN_CASE(test_2_13);
		XTESTS_RUN_CASE(test_2_14);
		XTESTS_RUN_CASE(test_2_15);
		XTESTS_RUN_CASE(test_2_16);
		XTESTS_RUN_CASE(test_2_17);
		XTESTS_RUN_CASE(test_2_18);
		XTESTS_RUN_CASE(test_2_19);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_ALIAS_COVERAGE("replace_functions", NULL);
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

static void test_1_00()
{
	std::string		s	=	"abcabc";

	stlsoft::replace(s, "x", "XXXX");

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcabc", s);
}

static void test_1_01()
{
	std::string		s	=	"abcabc";

	stlsoft::replace(s, "b", "BB");

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("aBBcaBBc", s);
}

static void test_1_02()
{
	std::string		s	=	"abcabc";

	stlsoft::replace(s, "b", "");

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("acac", s);
}

static void test_1_03()
{
	std::string		s	=	"abcabc";

	stlsoft::replace(s, "b", "bb");

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abbcabbc", s);
}

static void test_1_04()
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


static void test_2_00()
{
}

static void test_2_01()
{
}

static void test_2_02()
{
}

static void test_2_03()
{
}

static void test_2_04()
{
}

static void test_2_10()
{
}

static void test_2_11()
{
}

static void test_2_12()
{
}

static void test_2_13()
{
}

static void test_2_14()
{
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



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
