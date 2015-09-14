/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.split_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.split_functions project.
 *
 * Created:     12th May 2010
 * Updated:     17th May 2010
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

#include <stlsoft/string/split_functions.hpp>

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
#include <stlsoft/string/string_view.hpp>

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
	static void test_1_05(void);
	static void test_1_06(void);
	static void test_1_07(void);
	static void test_1_08(void);
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

	static void test_2_00(void);
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

	static void test_3_00(void);
	static void test_3_01(void);
	static void test_3_02(void);
	static void test_3_03(void);
	static void test_3_04(void);
	static void test_3_05(void);
	static void test_3_06(void);
	static void test_3_07(void);
	static void test_3_08(void);
	static void test_3_09(void);
	static void test_3_10(void);
	static void test_3_11(void);
	static void test_3_12(void);
	static void test_3_13(void);
	static void test_3_14(void);
	static void test_3_15(void);
	static void test_3_16(void);
	static void test_3_17(void);
	static void test_3_18(void);
	static void test_3_19(void);

	static void test_4_00(void);
	static void test_4_01(void);
	static void test_4_02(void);
	static void test_4_03(void);
	static void test_4_04(void);
	static void test_4_05(void);
	static void test_4_06(void);
	static void test_4_07(void);
	static void test_4_08(void);
	static void test_4_09(void);
	static void test_4_10(void);
	static void test_4_11(void);
	static void test_4_12(void);
	static void test_4_13(void);
	static void test_4_14(void);
	static void test_4_15(void);
	static void test_4_16(void);
	static void test_4_17(void);
	static void test_4_18(void);
	static void test_4_19(void);

	static void test_5_00(void);
	static void test_5_01(void);
	static void test_5_02(void);
	static void test_5_03(void);
	static void test_5_04(void);
	static void test_5_05(void);
	static void test_5_06(void);
	static void test_5_07(void);
	static void test_5_08(void);
	static void test_5_09(void);
	static void test_5_10(void);
	static void test_5_11(void);
	static void test_5_12(void);
	static void test_5_13(void);
	static void test_5_14(void);
	static void test_5_15(void);
	static void test_5_16(void);
	static void test_5_17(void);
	static void test_5_18(void);
	static void test_5_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.string.split_functions", verbosity))
	{
		XTESTS_RUN_CASE(test_1_00);
		XTESTS_RUN_CASE(test_1_01);
		XTESTS_RUN_CASE(test_1_02);
		XTESTS_RUN_CASE(test_1_03);
		XTESTS_RUN_CASE(test_1_04);
		XTESTS_RUN_CASE(test_1_05);
		XTESTS_RUN_CASE(test_1_06);
		XTESTS_RUN_CASE(test_1_07);
		XTESTS_RUN_CASE(test_1_08);
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

		XTESTS_RUN_CASE(test_2_00);
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

		XTESTS_RUN_CASE(test_3_00);
		XTESTS_RUN_CASE(test_3_01);
		XTESTS_RUN_CASE(test_3_02);
		XTESTS_RUN_CASE(test_3_03);
		XTESTS_RUN_CASE(test_3_04);
		XTESTS_RUN_CASE(test_3_05);
		XTESTS_RUN_CASE(test_3_06);
		XTESTS_RUN_CASE(test_3_07);
		XTESTS_RUN_CASE(test_3_08);
		XTESTS_RUN_CASE(test_3_09);
		XTESTS_RUN_CASE(test_3_10);
		XTESTS_RUN_CASE(test_3_11);
		XTESTS_RUN_CASE(test_3_12);
		XTESTS_RUN_CASE(test_3_13);
		XTESTS_RUN_CASE(test_3_14);
		XTESTS_RUN_CASE(test_3_15);
		XTESTS_RUN_CASE(test_3_16);
		XTESTS_RUN_CASE(test_3_17);
		XTESTS_RUN_CASE(test_3_18);
		XTESTS_RUN_CASE(test_3_19);

		XTESTS_RUN_CASE(test_4_00);
		XTESTS_RUN_CASE(test_4_01);
		XTESTS_RUN_CASE(test_4_02);
		XTESTS_RUN_CASE(test_4_03);
		XTESTS_RUN_CASE(test_4_04);
		XTESTS_RUN_CASE(test_4_05);
		XTESTS_RUN_CASE(test_4_06);
		XTESTS_RUN_CASE(test_4_07);
		XTESTS_RUN_CASE(test_4_08);
		XTESTS_RUN_CASE(test_4_09);
		XTESTS_RUN_CASE(test_4_10);
		XTESTS_RUN_CASE(test_4_11);
		XTESTS_RUN_CASE(test_4_12);
		XTESTS_RUN_CASE(test_4_13);
		XTESTS_RUN_CASE(test_4_14);
		XTESTS_RUN_CASE(test_4_15);
		XTESTS_RUN_CASE(test_4_16);
		XTESTS_RUN_CASE(test_4_17);
		XTESTS_RUN_CASE(test_4_18);
		XTESTS_RUN_CASE(test_4_19);

		XTESTS_RUN_CASE(test_5_00);
		XTESTS_RUN_CASE(test_5_01);
		XTESTS_RUN_CASE(test_5_02);
		XTESTS_RUN_CASE(test_5_03);
		XTESTS_RUN_CASE(test_5_04);
		XTESTS_RUN_CASE(test_5_05);
		XTESTS_RUN_CASE(test_5_06);
		XTESTS_RUN_CASE(test_5_07);
		XTESTS_RUN_CASE(test_5_08);
		XTESTS_RUN_CASE(test_5_09);
		XTESTS_RUN_CASE(test_5_10);
		XTESTS_RUN_CASE(test_5_11);
		XTESTS_RUN_CASE(test_5_12);
		XTESTS_RUN_CASE(test_5_13);
		XTESTS_RUN_CASE(test_5_14);
		XTESTS_RUN_CASE(test_5_15);
		XTESTS_RUN_CASE(test_5_16);
		XTESTS_RUN_CASE(test_5_17);
		XTESTS_RUN_CASE(test_5_18);
		XTESTS_RUN_CASE(test_5_19);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_ALIAS_COVERAGE("split_functions", NULL);
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
	std::string const	s("abc|def");
	std::string			s1;
	std::string			s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
}

static void test_1_01()
{
	std::string const	s("abc|def");
	std::string			s1;
	std::string			s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::split(s, ':', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", s1);
}

static void test_1_02()
{
	std::string const	s("abc|def|ghi");
	std::string			s1;
	std::string			s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def|ghi", s2);
}

static void test_1_03()
{
	stlsoft::string_view const	s("abc|def");
	stlsoft::string_view		s1;
	stlsoft::string_view		s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
}

static void test_1_04()
{
	stlsoft::string_view const	s("abc|def");
	stlsoft::string_view		s1;
	stlsoft::string_view		s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::split(s, ':', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", s1);
}

static void test_1_05()
{
}

static void test_1_06()
{
	std::string const	s("abc|");
	std::string			s1;
	std::string			s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
}

static void test_1_07()
{
}

static void test_1_08()
{
}

static void test_1_09()
{
}

static void test_1_10()
{
	stlsoft::string_view const	s("abc|def|ghi");
	stlsoft::string_view		s1;
	stlsoft::string_view		s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def|ghi", s2);
}

static void test_1_11()
{
	std::string const		s("abc|def");
	stlsoft::string_view	s1;
	stlsoft::string_view	s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
}

static void test_1_12()
{
	std::string const		s("abc|def");
	stlsoft::string_view	s1;
	stlsoft::string_view	s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::split(s, ':', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", s1);
}

static void test_1_13()
{
	std::string const		s("abc|def|ghi");
	stlsoft::string_view	s1;
	stlsoft::string_view	s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def|ghi", s2);
}

static void test_1_14()
{
	stlsoft::string_view const	s("abc|def");
	std::string					s1;
	std::string					s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
}

static void test_1_15()
{
	stlsoft::string_view const	s("abc|def");
	std::string					s1;
	std::string					s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(stlsoft::split(s, ':', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", s1);
}

static void test_1_16()
{
	stlsoft::string_view const	s("abc|def|ghi");
	std::string					s1;
	std::string					s2;

	XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::split(s, '|', s1, s2)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def|ghi", s2);
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
	std::string const	s("");
	std::string			s1;
	std::string			s2;
	std::string			s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
}

static void test_2_01()
{
	std::string const	s("abc");
	std::string			s1;
	std::string			s2;
	std::string			s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
}

static void test_2_02()
{
	std::string const	s("abc|def");
	std::string			s1;
	std::string			s2;
	std::string			s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
}

static void test_2_03()
{
	std::string const	s("abc|def|ghi");
	std::string			s1;
	std::string			s2;
	std::string			s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
}

static void test_2_04()
{
	std::string const	s("abc|def|ghi|jkl");
	std::string			s1;
	std::string			s2;
	std::string			s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi|jkl", s3);
}

static void test_2_05()
{
	std::string const	s("abc|def|ghi");
	std::string			s1;
	std::string			s2;
	std::string			s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split(s, ':', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def|ghi", s1);
}

static void test_2_06()
{
	std::string			s1;
	std::string			s2;
	std::string			s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split("abc|def|ghi", '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::split("abc|def", '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split("abc", '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::split("", '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);
}

static void test_2_07()
{
	stlsoft::string_view const	s("abc|def|ghi");
	stlsoft::string_view		s1;
	stlsoft::string_view		s2;
	stlsoft::string_view		s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
}

static void test_2_08()
{
	stlsoft::string_view const	s("abc|def|ghi|jkl");
	stlsoft::string_view		s1;
	stlsoft::string_view		s2;
	stlsoft::string_view		s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi|jkl", s3);
}

static void test_2_09()
{
	stlsoft::string_view const	s("abc|def|ghi");
	stlsoft::string_view		s1;
	stlsoft::string_view		s2;
	stlsoft::string_view		s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split(s, ':', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def|ghi", s1);
}

static void test_2_10()
{
	std::string const		s("abc|def|ghi");
	stlsoft::string_view	s1;
	stlsoft::string_view	s2;
	stlsoft::string_view	s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
}

static void test_2_11()
{
	std::string const		s("abc|def|ghi|jkl");
	stlsoft::string_view	s1;
	stlsoft::string_view	s2;
	stlsoft::string_view	s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi|jkl", s3);
}

static void test_2_12()
{
	std::string const		s("abc|def|ghi");
	stlsoft::string_view	s1;
	stlsoft::string_view	s2;
	stlsoft::string_view	s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split(s, ':', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def|ghi", s1);
}

static void test_2_13()
{
	stlsoft::string_view const	s("abc|def|ghi");
	std::string					s1;
	std::string					s2;
	std::string					s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
}

static void test_2_14()
{
	stlsoft::string_view const	s("abc|def|ghi|jkl");
	std::string					s1;
	std::string					s2;
	std::string					s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi|jkl", s3);
}

static void test_2_15()
{
	stlsoft::string_view const	s("abc|def|ghi");
	std::string					s1;
	std::string					s2;
	std::string					s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split(s, ':', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def|ghi", s1);
}

static void test_2_16()
{
}

static void test_2_17()
{
	std::string const	s("abc|");
	std::string			s1;
	std::string			s2;
	std::string			s3;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::split(s, '|', s1, s2, s3)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
}

static void test_2_18()
{
}

static void test_2_19()
{
}



static void test_3_00()
{
	std::string const	s("");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::split(s, '|', s1, s2, s3, s4)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
}

static void test_3_01()
{
	std::string const	s("abc");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split(s, '|', s1, s2, s3, s4)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
}

static void test_3_02()
{
	std::string const	s("abc|def");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::split(s, '|', s1, s2, s3, s4)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
}

static void test_3_03()
{
	std::string const	s("abc|def|ghi");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3, s4)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
}

static void test_3_04()
{
	std::string const	s("abc|def|ghi|jkl");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, stlsoft::split(s, '|', s1, s2, s3, s4)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", s4);
}

static void test_3_05()
{
	std::string const	s("abc|def|ghi|jkl|mno");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, stlsoft::split(s, '|', s1, s2, s3, s4)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl|mno", s4);
}

static void test_3_06()
{
}

static void test_3_07()
{
}

static void test_3_08()
{
}

static void test_3_09()
{
}

static void test_3_10()
{
}

static void test_3_11()
{
}

static void test_3_12()
{
}

static void test_3_13()
{
}

static void test_3_14()
{
}

static void test_3_15()
{
}

static void test_3_16()
{
}

static void test_3_17()
{
}

static void test_3_18()
{
}

static void test_3_19()
{
}



static void test_4_00()
{
	std::string const	s("");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::split(s, '|', s1, s2, s3, s4, s5)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
}

static void test_4_01()
{
	std::string const	s("abc");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split(s, '|', s1, s2, s3, s4, s5)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
}

static void test_4_02()
{
	std::string const	s("abc|def");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::split(s, '|', s1, s2, s3, s4, s5)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
}

static void test_4_03()
{
	std::string const	s("abc|def|ghi");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3, s4, s5)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
}

static void test_4_04()
{
	std::string const	s("abc|def|ghi|jkl");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, stlsoft::split(s, '|', s1, s2, s3, s4, s5)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
}

static void test_4_05()
{
	std::string const	s("abc|def|ghi|jkl|mno");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(5u, stlsoft::split(s, '|', s1, s2, s3, s4, s5)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("mno", s5);
}

static void test_4_06()
{
	std::string const	s("abc|def|ghi|jkl|mno|pqr");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(5u, stlsoft::split(s, '|', s1, s2, s3, s4, s5)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("mno|pqr", s5);
}

static void test_4_07()
{
}

static void test_4_08()
{
}

static void test_4_09()
{
}

static void test_4_10()
{
}

static void test_4_11()
{
}

static void test_4_12()
{
}

static void test_4_13()
{
}

static void test_4_14()
{
}

static void test_4_15()
{
}

static void test_4_16()
{
}

static void test_4_17()
{
}

static void test_4_18()
{
}

static void test_4_19()
{
}



static void test_5_00()
{
	std::string const	s("");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s6);
}

static void test_5_01()
{
	std::string const	s("abc");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s6);
}

static void test_5_02()
{
	std::string const	s("abc|def");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s6);
}

static void test_5_03()
{
	std::string const	s("abc|def|ghi");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s6);
}

static void test_5_04()
{
	std::string const	s("abc|def|ghi|jkl");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s6);
}

static void test_5_05()
{
	std::string const	s("abc|def|ghi|jkl|mno");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(5u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("mno", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s6);
}

static void test_5_06()
{
	std::string const	s("abc|def|ghi|jkl|mno|pqr");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("mno", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("pqr", s6);
}

static void test_5_07()
{
	std::string const	s("abc|def|ghi|jkl|mno|pqr|stu");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("mno", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("pqr|stu", s6);
}

static void test_5_08()
{
}

static void test_5_09()
{
}

static void test_5_10()
{
}

static void test_5_11()
{
}

static void test_5_12()
{
	std::string const	s("abc|def|ghi|");
	std::string			s1;
	std::string			s2;
	std::string			s3;
	std::string			s4;
	std::string			s5;
	std::string			s6;

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, stlsoft::split(s, '|', s1, s2, s3, s4, s5, s6)));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s3);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s4);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s5);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s6);
}

static void test_5_13()
{
}

static void test_5_14()
{
}

static void test_5_15()
{
}

static void test_5_16()
{
}

static void test_5_17()
{
}

static void test_5_18()
{
}

static void test_5_19()
{
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
