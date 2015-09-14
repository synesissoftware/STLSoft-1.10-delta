/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.shims.conversion.to_signed.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.shims.conversion.to_signed project.
 *
 * Created:     7th July 2012
 * Updated:     7th July 2012
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2012, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/shims/conversion/to_signed.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/meta/is_same_type.hpp>
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
	static void test_1_8(void);
	static void test_1_9(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.shims.conversion.to_signed", verbosity))
	{
		XTESTS_RUN_CASE(test_1_0);
		XTESTS_RUN_CASE(test_1_1);
		XTESTS_RUN_CASE(test_1_2);
		XTESTS_RUN_CASE(test_1_3);
		XTESTS_RUN_CASE(test_1_4);
		XTESTS_RUN_CASE(test_1_5);
		XTESTS_RUN_CASE(test_1_6);
		XTESTS_RUN_CASE(test_1_7);
		XTESTS_RUN_CASE(test_1_8);
		XTESTS_RUN_CASE(test_1_9);

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

	template<
		typename T2
	,	typename T3
	>
	void check_type_2(T3)
	{
		STLSOFT_STATIC_ASSERT((0 != stlsoft::is_same_type<T2, T3>::value));
	}

	template<
		typename T1
	,	typename T2
	>
	void check_type()
	{
		T1 const t1 = T1();

		check_type_2<T2>(stlsoft::to_signed(t1));
	}

static void test_1_0()
{
	check_type<stlsoft::sint8_t, stlsoft::sint8_t>();

	XTESTS_TEST_PASSED();
}

static void test_1_1()
{
	check_type<stlsoft::uint8_t, stlsoft::sint8_t>();

	XTESTS_TEST_PASSED();
}

static void test_1_2()
{
	check_type<stlsoft::sint16_t, stlsoft::sint16_t>();

	XTESTS_TEST_PASSED();
}

static void test_1_3()
{
	check_type<stlsoft::uint16_t, stlsoft::sint16_t>();

	XTESTS_TEST_PASSED();
}

static void test_1_4()
{
	check_type<stlsoft::sint32_t, stlsoft::sint32_t>();

	XTESTS_TEST_PASSED();
}

static void test_1_5()
{
	check_type<stlsoft::uint32_t, stlsoft::sint32_t>();

	XTESTS_TEST_PASSED();
}

static void test_1_6()
{
	check_type<stlsoft::sint64_t, stlsoft::sint64_t>();

	XTESTS_TEST_PASSED();
}

static void test_1_7()
{
	check_type<stlsoft::uint64_t, stlsoft::sint64_t>();

	XTESTS_TEST_PASSED();
}

static void test_1_8()
{
}

static void test_1_9()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
