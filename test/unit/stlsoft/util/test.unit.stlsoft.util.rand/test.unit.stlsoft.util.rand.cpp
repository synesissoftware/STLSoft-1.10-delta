/* /////////////////////////////////////////////////////////////////////////
 * File:		test.unit.stlsoft.util.rand.cpp
 *
 * Purpose: 	Implementation file for the test.unit.stlsoft.util.rand project.
 *
 * Created: 	19th March 2010
 * Updated: 	13th October 2010
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

#include <stlsoft/util/rand.hpp>

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
#include <set>

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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.util.rand", verbosity))
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
		XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/rand.hpp", NULL);
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
	using stlsoft::sint8_t;
	using stlsoft::uint8_t;
	using stlsoft::sint16_t;
	using stlsoft::uint16_t;
	using stlsoft::sint32_t;
	using stlsoft::uint32_t;
	using stlsoft::sint64_t;
	using stlsoft::uint64_t;

static void test_1_0()
{
	{ for(unsigned i = 0; i != 10000; ++i)
	{
		stlsoft::rand<sint8_t>();
	}}
}

static void test_1_1()
{
	typedef std::set<int> ints_t;

	unsigned /* const "stupid Borland!" */ NUM_ITERATIONS = 1000000/* 0 */;

	ints_t ints;

	{ for(unsigned i = 0; i != NUM_ITERATIONS; ++i)
	{
		ints.insert(stlsoft::rand<int>());
	}}

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(NUM_ITERATIONS / 4, ints.size());

	STLSOFT_SUPPRESS_UNUSED(NUM_ITERATIONS);
}

static void test_1_2()
{
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
