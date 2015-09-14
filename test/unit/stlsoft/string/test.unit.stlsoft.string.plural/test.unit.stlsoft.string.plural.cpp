/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.plural.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.plural project.
 *
 * Created:     15th November 2014
 * Updated:     15th November 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/string/plural_functions.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <map>
#include <string>
#include <vector>

/* Standard C header files */
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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.string.plural", verbosity))
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

	typedef char									char_t;
	typedef std::basic_string<char_t>				string_t;
	typedef std::vector<string_t>					strings_t;
	typedef std::map<int, string_t>					int_to_string_t;
	typedef std::map<string_t, string_t>			string_to_string_t;
	typedef std::map<string_t, strings_t>			string_to_strings_t;
	typedef std::map<string_t, int_to_string_t>		string_to_int_to_string_t;

static void test_1_0()
{
	string_to_string_t			m;
	char_t const*				noun	=	"item";

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0 item", stlsoft::plural<string_t>(0, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1 item", stlsoft::plural<string_t>(1, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2 item", stlsoft::plural<string_t>(2, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3 item", stlsoft::plural<string_t>(3, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("4 item", stlsoft::plural<string_t>(4, noun, m));
}

static void test_1_1()
{
	string_to_strings_t			m;
	char_t const*				noun	=	"item";

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0 item", stlsoft::plural<string_t>(0, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1 item", stlsoft::plural<string_t>(1, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2 item", stlsoft::plural<string_t>(2, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3 item", stlsoft::plural<string_t>(3, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("4 item", stlsoft::plural<string_t>(4, noun, m));
}

static void test_1_2()
{
	string_to_int_to_string_t	m;
	char_t const*				noun	=	"item";

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0 item", stlsoft::plural<string_t>(0, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1 item", stlsoft::plural<string_t>(1, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2 item", stlsoft::plural<string_t>(2, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3 item", stlsoft::plural<string_t>(3, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("4 item", stlsoft::plural<string_t>(4, noun, m));
}

static void test_1_3()
{
	string_to_string_t			m;
	char_t const*				noun	=	"item";

	m["item"] = "items";

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0 items", stlsoft::plural<string_t>(0, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1 item",  stlsoft::plural<string_t>(1, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2 items", stlsoft::plural<string_t>(2, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3 items", stlsoft::plural<string_t>(3, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("4 items", stlsoft::plural<string_t>(4, noun, m));
}

static void test_1_4()
{
	string_to_strings_t			m;
	char_t const*				noun	=	"item";

	m["item"].push_back("items");
	m["item"].push_back("item");
	m["item"].push_back("items");

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0 items", stlsoft::plural<string_t>(0, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1 item",  stlsoft::plural<string_t>(1, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2 items", stlsoft::plural<string_t>(2, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3 items", stlsoft::plural<string_t>(3, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("4 items", stlsoft::plural<string_t>(4, noun, m));
}

static void test_1_5()
{
	string_to_int_to_string_t	m;
	char_t const*				noun	=	"items";

	m["items"][1] = "item";
	m["items"][3] = "blahs";

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0 items", stlsoft::plural<string_t>(0, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1 item",  stlsoft::plural<string_t>(1, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2 items", stlsoft::plural<string_t>(2, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3 blahs", stlsoft::plural<string_t>(3, noun, m));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("4 items", stlsoft::plural<string_t>(4, noun, m));
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
