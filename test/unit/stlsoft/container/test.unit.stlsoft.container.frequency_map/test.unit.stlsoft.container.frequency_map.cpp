/* /////////////////////////////////////////////////////////////////////////
 * File:		test.unit.stlsoft.container.frequency_map.cpp
 *
 * Purpose: 	Implementation file for the test.unit.stlsoft.container.frequency_map project.
 *
 * Created: 	6th March 2010
 * Updated: 	6th March 2010
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

#include <stlsoft/containers/frequency_map.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C++ Header Files */
#include <map>
#include <numeric>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_maps_default_ctor(void);
	static void test_maps_size(void);
	static void test_maps_empty(void);
	static void tests_maps_insert_1(void);
	static void tests_maps_insert_2(void);
	static void tests_maps_insert_3(void);
	static void tests_maps_clear_0(void);
	static void tests_maps_clear_1(void);
	static void test_1_09(void);
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
	static void test_1_20(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.container.frequency_map", verbosity))
	{
		XTESTS_RUN_CASE(test_maps_default_ctor);
		XTESTS_RUN_CASE(test_maps_size);
		XTESTS_RUN_CASE(test_maps_empty);
		XTESTS_RUN_CASE(tests_maps_insert_1);
		XTESTS_RUN_CASE(tests_maps_insert_2);
		XTESTS_RUN_CASE(tests_maps_insert_3);
		XTESTS_RUN_CASE(tests_maps_clear_0);
		XTESTS_RUN_CASE(tests_maps_clear_1);
		XTESTS_RUN_CASE(test_1_09);
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
		XTESTS_RUN_CASE(test_1_20);

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

	typedef std::string 						string_t;

	typedef stlsoft::frequency_map<string_t>	string_fmap_t;

static void test_maps_default_ctor()
{
	string_fmap_t	map;

	XTESTS_TEST_PASSED();
}

static void test_maps_size()
{
	string_fmap_t	map;

	XTESTS_TEST_INTEGER_EQUAL(0u, map.size());
}

static void test_maps_empty()
{
	string_fmap_t	map;

	XTESTS_TEST_BOOLEAN_TRUE(map.empty());
}

static void tests_maps_insert_1()
{
	string_fmap_t	map;

	map.push("key-11");

	XTESTS_TEST_BOOLEAN_FALSE(map.empty());
	XTESTS_TEST_INTEGER_EQUAL(1u, map.size());
}

static void tests_maps_insert_2()
{
	string_fmap_t	map;

	map.push("key-11");
	map.push("key-22");

	XTESTS_TEST_BOOLEAN_FALSE(map.empty());
	XTESTS_TEST_INTEGER_EQUAL(2u, map.size());
}

static void tests_maps_insert_3()
{
	string_fmap_t	map;

	map.push("key-11");
	map.push("key-22");
	map.push("key-11");
	map.push("key-22");

	XTESTS_TEST_BOOLEAN_FALSE(map.empty());
	XTESTS_TEST_INTEGER_EQUAL(2u, map.size());
}

static void tests_maps_clear_0()
{
	string_fmap_t	map;

	XTESTS_TEST_BOOLEAN_TRUE(map.empty());
	XTESTS_TEST_INTEGER_EQUAL(0u, map.size());

	map.clear();

	XTESTS_TEST_BOOLEAN_TRUE(map.empty());
	XTESTS_TEST_INTEGER_EQUAL(0u, map.size());
}

static void tests_maps_clear_1()
{
	string_fmap_t	map;

	map.push("key-11");
	map.push("key-22");

	XTESTS_TEST_BOOLEAN_FALSE(map.empty());
	XTESTS_TEST_INTEGER_EQUAL(2u, map.size());

	map.clear();

	XTESTS_TEST_BOOLEAN_TRUE(map.empty());
	XTESTS_TEST_INTEGER_EQUAL(0u, map.size());
}

static void test_1_09()
{
}

static void test_1_10()
{
	string_fmap_t	map1;
	string_fmap_t	map2;

	map1.push("key-11");
	map1.push("key-22");

	XTESTS_TEST_BOOLEAN_FALSE(map1.empty());
	XTESTS_TEST_INTEGER_EQUAL(2u, map1.size());
	XTESTS_TEST_INTEGER_EQUAL(1u, map1["key-11"]);
	XTESTS_TEST_INTEGER_EQUAL(1u, map1["key-22"]);

	map2.push("key-11");
	map2.push("key-21");

	XTESTS_TEST_BOOLEAN_FALSE(map2.empty());
	XTESTS_TEST_INTEGER_EQUAL(2u, map2.size());
	XTESTS_TEST_INTEGER_EQUAL(1u, map2["key-11"]);
	XTESTS_TEST_INTEGER_EQUAL(1u, map2["key-21"]);

	map1.merge(map2);

	XTESTS_TEST_BOOLEAN_FALSE(map1.empty());
	XTESTS_TEST_INTEGER_EQUAL(3u, map1.size());
	XTESTS_TEST_INTEGER_EQUAL(2u, map1["key-11"]);
	XTESTS_TEST_INTEGER_EQUAL(1u, map1["key-21"]);
	XTESTS_TEST_INTEGER_EQUAL(1u, map1["key-22"]);

	XTESTS_TEST_BOOLEAN_FALSE(map2.empty());
	XTESTS_TEST_INTEGER_EQUAL(2u, map2.size());
	XTESTS_TEST_INTEGER_EQUAL(1u, map2["key-11"]);
	XTESTS_TEST_INTEGER_EQUAL(1u, map2["key-21"]);

	map2.clear();

	XTESTS_TEST_BOOLEAN_FALSE(map1.empty());
	XTESTS_TEST_INTEGER_EQUAL(3u, map1.size());
	XTESTS_TEST_INTEGER_EQUAL(2u, map1["key-11"]);
	XTESTS_TEST_INTEGER_EQUAL(1u, map1["key-21"]);
	XTESTS_TEST_INTEGER_EQUAL(1u, map1["key-22"]);

	XTESTS_TEST_INTEGER_EQUAL(0u, map2.size());
	XTESTS_TEST_BOOLEAN_TRUE(map2.empty());
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

static void test_1_20()
{
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
