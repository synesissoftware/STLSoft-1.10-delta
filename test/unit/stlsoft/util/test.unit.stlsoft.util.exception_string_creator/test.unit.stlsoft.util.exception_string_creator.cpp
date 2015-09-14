/* /////////////////////////////////////////////////////////////////////////
 * File:		test.unit.stlsoft.util.exception_string_creator.cpp
 *
 * Purpose: 	Implementation file for the test.unit.stlsoft.util.exception_string_creator project.
 *
 * Created: 	9th June 2010
 * Updated: 	12th August 2010
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

#define _SCL_SECURE_NO_WARNINGS

#include <stlsoft/util/exception_string_creator.hpp>

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
#include <platformstl/performance/performance_counter.hpp>

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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.util.exception_string_creator", verbosity))
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
		XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/exception_string_creator.hpp", NULL);
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
	using stlsoft::exception_string_creator;

static void test_1_0()
{
	exception_string_creator	creator;

	STLSOFT_SUPPRESS_UNUSED(creator);

	XTESTS_TEST_PASSED();
}

static void test_1_1()
{
	exception_string_creator	creator;

	XTESTS_TEST_BOOLEAN_TRUE(creator.empty());
	XTESTS_TEST_INTEGER_EQUAL(0u, creator.size());
	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(creator.size(), creator.capacity());
}

static void test_1_2()
{
	exception_string_creator	creator("abc");

	XTESTS_TEST_BOOLEAN_FALSE(creator.empty());
	XTESTS_TEST_INTEGER_EQUAL(3u, creator.size());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", creator);
	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(creator.size(), creator.capacity());
}

static void test_1_3()
{
	exception_string_creator	creator("abcdefghijklmno", 13u);

	XTESTS_TEST_BOOLEAN_FALSE(creator.empty());
	XTESTS_TEST_INTEGER_EQUAL(13u, creator.size());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklm", creator);
	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(creator.size(), creator.capacity());
}

static void test_1_4()
{
	exception_string_creator	creator;

	creator
		.append("abc")
		.append("d")
		.append("efg")
		;

	XTESTS_TEST_BOOLEAN_FALSE(creator.empty());
	XTESTS_TEST_INTEGER_EQUAL(7u, creator.size());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefg", creator);
	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(creator.size(), creator.capacity());
}

static void test_1_5()
{
	exception_string_creator	creator("abc");

	creator
		.append(' ')
		.append(123)
		;

	XTESTS_TEST_BOOLEAN_FALSE(creator.empty());
	XTESTS_TEST_INTEGER_EQUAL(7u, creator.size());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc 123", creator);
	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(creator.size(), creator.capacity());
}

static void test_1_6()
{
	exception_string_creator	creator1;
	exception_string_creator	creator2(creator1);

	XTESTS_TEST_BOOLEAN_TRUE(creator1.empty());
	XTESTS_TEST_INTEGER_EQUAL(0u, creator1.size());
	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(creator1.size(), creator1.capacity());
}

static void test_1_7()
{
	exception_string_creator	creator1("abcdefghijklmno", 13u);
	exception_string_creator	creator2(creator1);

	XTESTS_TEST_BOOLEAN_FALSE(creator1.empty());
	XTESTS_TEST_INTEGER_EQUAL(13u, creator1.size());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklm", creator1);
	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(creator1.size(), creator1.capacity());
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
