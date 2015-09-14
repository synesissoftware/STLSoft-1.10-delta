/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.container.fixed_arrays.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.container.fixed_arrays project.
 *
 * Created:     1st December 2008
 * Updated:     9th December 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/containers/fixed_array.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C++ Header Files */
#include <numeric>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_1_9(void);
	static void test_1_10(void);
	static void test_copy_ctor(void);
	static void test_1_16(void);
	static void test_1_17(void);
	static void test_1_18(void);
	static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.container.fixed_arrays", verbosity))
	{
		XTESTS_RUN_CASE(test_1_9);
		XTESTS_RUN_CASE(test_1_10);
		XTESTS_RUN_CASE(test_copy_ctor);
		XTESTS_RUN_CASE(test_1_16);
		XTESTS_RUN_CASE(test_1_17);
		XTESTS_RUN_CASE(test_1_18);
		XTESTS_RUN_CASE(test_1_19);

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

	typedef stlsoft::fixed_array_1d<int>	int_array_1d_t;
	typedef stlsoft::fixed_array_2d<int>	int_array_2d_t;
	typedef stlsoft::fixed_array_3d<int>	int_array_3d_t;
	typedef stlsoft::fixed_array_4d<int>	int_array_4d_t;

static void test_1_9()
{
	int_array_1d_t	v(10);

	XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
	XTESTS_TEST_BOOLEAN_FALSE(v.empty());
}

static void test_1_10()
{
	int_array_1d_t			v(10, -1);
	int_array_1d_t const&	cv = v;

	XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
	XTESTS_TEST_BOOLEAN_FALSE(v.empty());
	XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(v.begin(), v.end(), 0));
	XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(cv.begin(), cv.end(), 0));
}

static void test_copy_ctor()
{
	int_array_1d_t	v1(10, -1);
	int_array_1d_t	v2(v1);

	XTESTS_TEST_INTEGER_EQUAL(10u, v2.size());
	XTESTS_TEST_BOOLEAN_FALSE(v2.empty());
	XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(v2.begin(), v2.end(), 0));
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

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
