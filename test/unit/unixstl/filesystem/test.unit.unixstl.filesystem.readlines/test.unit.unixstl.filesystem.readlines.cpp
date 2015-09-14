/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.unixstl.filesystem.readlines.cpp
 *
 * Purpose:     Implementation file for the test.unit.unixstl.filesystem.readlines project.
 *
 * Created:     23rd January 2009
 * Updated:     12th August 2010
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
 * Compiler compatibility
 */

#if defined(_MSC_VER) && \
	_MSC_VER >= 1400
# pragma warning(disable : 4996)
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

//#include <unixstl/filesystem/file_functions.hpp>

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
#include <vector>

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
	static void test_2_04(void);
	static void test_2_05(void);
	static void test_2_06(void);
	static void test_2_07(void);
	static void test_2_08(void);
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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.unixstl.filesystem.readlines", verbosity))
	{
		XTESTS_RUN_CASE(test_2_01);
		XTESTS_RUN_CASE(test_2_02);
		XTESTS_RUN_CASE(test_2_03);
		XTESTS_RUN_CASE(test_2_04);
		XTESTS_RUN_CASE(test_2_05);
		XTESTS_RUN_CASE(test_2_06);
		XTESTS_RUN_CASE(test_2_07);
		XTESTS_RUN_CASE(test_2_08);
		XTESTS_RUN_CASE(test_2_09);
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
		XCOVER_REPORT_FILE_COVERAGE("*unixstl/*/readlines.hpp", NULL);
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

	typedef std::string				string_m_t;
	typedef std::vector<string_m_t>	strings_m_t;

static void test_2_01()
{
	string_m_t	name;
	strings_m_t	contents;

	if(0)
	{
//		unixstl::readlines(name, contents);
	}

	XTESTS_TEST_PASSED();
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

static void test_2_05()
{
}

static void test_2_06()
{
}

static void test_2_07()
{
}

static void test_2_08()
{
}

static void test_2_09()
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
