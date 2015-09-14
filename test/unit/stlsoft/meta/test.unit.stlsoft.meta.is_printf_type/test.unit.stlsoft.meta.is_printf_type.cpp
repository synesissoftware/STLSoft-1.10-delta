/* /////////////////////////////////////////////////////////////////////////
 * File:		test.unit.stlsoft.meta.is_printf_type.cpp
 *
 * Purpose: 	Implementation file for the test.unit.stlsoft.meta.is_printf_type project.
 *
 * Created: 	9th June 2010
 * Updated: 	9th June 2010
 *
 * Status:		Wizard-generated
 *
 * License: 	(Licensed under the Synesis Software Open License)
 *
 *				Copyright (c) 2010, Synesis Software Pty Ltd.
 *				All rights reserved.
 *
 *				www:		http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/meta/is_printf_type.hpp>

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
#include <stdexcept>
#include <string>

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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.meta.is_printf_type", verbosity))
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
		XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/is_printf_type.hpp", NULL);
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
static void test_1_0()
{
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<char>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<signed char>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<unsigned char>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<short>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<unsigned short>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<int>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<unsigned int>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<long>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<unsigned long>::value);
}

static void test_1_1()
{
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<char*>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<char const*>::value);
}

static void test_1_2()
{
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<float>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<double>::value);
	XTESTS_TEST_ENUM_NOT_EQUAL(0, stlsoft::is_printf_type<long double>::value);
}

static void test_1_3()
{
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



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
