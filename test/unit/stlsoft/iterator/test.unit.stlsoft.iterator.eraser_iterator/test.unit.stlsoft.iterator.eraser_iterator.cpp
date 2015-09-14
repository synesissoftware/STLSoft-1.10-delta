/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.iterator.eraser_iterator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.iterator.eraser_iterator project.
 *
 * Created:     17th June 2010
 * Updated:     18th June 2010
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

#define _SCL_SECURE_NO_WARNINGS

#include <stlsoft/iterator/eraser_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/algorithm/literal_copy.hpp>
#include <stlsoft/iterator/string_concatenator_iterator.hpp>
#include <stlsoft/util/dimensionof.h>

/* Standard C++ Header Files */
#include <deque>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_vector(void);
	static void test_deque(void);
	static void test_list(void);
	static void test_set(void);
	static void test_1_4(void);
	static void test_1_5(void);
	static void test_1_6(void);
	static void test_1_7(void);
	static void test_1_8(void);
	static void test_1_9(void);
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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.iterator.eraser_iterator", verbosity))
	{
		XTESTS_RUN_CASE(test_vector);
		XTESTS_RUN_CASE(test_deque);
		XTESTS_RUN_CASE(test_list);
		XTESTS_RUN_CASE(test_set);
		XTESTS_RUN_CASE(test_1_4);
		XTESTS_RUN_CASE(test_1_5);
		XTESTS_RUN_CASE(test_1_6);
		XTESTS_RUN_CASE(test_1_7);
		XTESTS_RUN_CASE(test_1_8);
		XTESTS_RUN_CASE(test_1_9);
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

	typedef std::string						string_t;
#if 0
	typedef std::deque<string_t>			string_deque_t;
	typedef std::set<string_t>				stringset_t;
	typedef std::map<string_t, string_t>	string_to_string_map_t;
#endif /* 0 */

	static char const* STRINGS[] =
	{
		"abc",
		"def",
		"ghi",
		"jkl",
	};

	template <typename I>
	string_t cat(I from, I to)
	{
		string_t r;

		std::copy(from, to, stlsoft::string_concatenator(r, ""));

		return r;
	}

static void test_vector()
{
	std::vector<string_t>	c;

	std::copy(	STRINGS, STRINGS + dimensionof(STRINGS)
			,	std::back_inserter(c));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[2]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[3]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijkl", cat(c.begin(), c.end()));

	std::vector<string_t>	r;

	r.push_back("def");
	r.push_back("mno");

	std::copy(	r.begin(), r.end()
			,	stlsoft::eraser(c));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[2]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcghijkl", cat(c.begin(), c.end()));
}

static void test_deque()
{
	std::deque<string_t>	c;

	std::copy(	STRINGS, STRINGS + dimensionof(STRINGS)
			,	std::back_inserter(c));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[2]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[3]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijkl", cat(c.begin(), c.end()));

	std::vector<string_t>	r;

	r.push_back("def");
	r.push_back("mno");

	std::copy(	r.begin(), r.end()
			,	stlsoft::eraser(c));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[2]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcghijkl", cat(c.begin(), c.end()));
}

static void test_list()
{
	std::list<string_t>	c;

	std::copy(	STRINGS, STRINGS + dimensionof(STRINGS)
			,	std::back_inserter(c));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
#if 0
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[2]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[3]);
#endif /* 0 */
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijkl", cat(c.begin(), c.end()));

	std::vector<string_t>	r;

	r.push_back("def");
	r.push_back("mno");

	std::copy(	r.begin(), r.end()
			,	stlsoft::eraser(c));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
#if 0
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[2]);
#endif /* 0 */
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcghijkl", cat(c.begin(), c.end()));
}

static void test_set()
{
	std::set<string_t>	c;

	std::copy(	STRINGS, STRINGS + dimensionof(STRINGS)
			,	std::inserter(c, c.end()));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
#if 0
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[2]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[3]);
#endif /* 0 */
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijkl", cat(c.begin(), c.end()));

	std::vector<string_t>	r;

	r.push_back("def");
	r.push_back("mno");

	std::copy(	r.begin(), r.end()
			,	stlsoft::eraser(c));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
#if 0
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[2]);
#endif /* 0 */
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcghijkl", cat(c.begin(), c.end()));
}

static void test_1_4()
{
#if 1
	std::map<string_t, string_t>	c;

	{ for(size_t i = 0; i != dimensionof(STRINGS); ++i)
	{
		c.insert(std::make_pair(STRINGS[i], STRINGS[i]));
	}}

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
#if 0
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[2]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[3]);
#endif /* 0 */

	std::vector<string_t>	r;

	r.push_back("def");
	r.push_back("mno");

	std::copy(	r.begin(), r.end()
			,	stlsoft::eraser(c));

	XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
#if 0
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", c[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", c[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", c[2]);
#endif /* 0 */
#endif /* 0 */
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

static void test_1_8()
{
}

static void test_1_9()
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
