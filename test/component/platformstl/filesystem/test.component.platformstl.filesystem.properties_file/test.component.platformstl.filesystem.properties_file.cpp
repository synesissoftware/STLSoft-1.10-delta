/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.platformstl.filesystem.properties_file.cpp
 *
 * Purpose:     Implementation file for the test.component.platformstl.filesystem.properties_file project.
 *
 * Created:     17th May 2009
 * Updated:     19th January 2010
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
 * Test component header file include(s)
 */

#include <platformstl/filesystem/properties_file.hpp>

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
#include <stlsoft/conversion/integer_to_string.hpp>
#include <platformstl/filesystem/filesystem_traits.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

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

	static void test_2_01(void);

	static void test_3_01(void);
	static void test_3_02(void);
	static void test_3_03(void);

	// The following are from the Java documentation
	// at http://java.sun.com/j2se/1.5.0/docs/api/java/util/Properties.html#load(java.io.InputStream)
	static void test_javadoc_truth_beauty_1(void);
	static void test_javadoc_truth_beauty_2(void);
	static void test_javadoc_truth_beauty_3(void);
	static void test_javadoc_truth_beauty_4(void);
	static void test_javadoc_truth_beauty_5(void);
	static void test_javadoc_truth_beauty_6(void);
	static void test_javadoc_truth_beauty_7(void);

	static void test_javadoc_fruits(void);

	static void test_javadoc_cheeses(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.component.platformstl.filesystem.properties_file", verbosity))
	{
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
		XTESTS_RUN_CASE(test_2_01);
		XTESTS_RUN_CASE(test_3_01);
		XTESTS_RUN_CASE(test_3_02);
		XTESTS_RUN_CASE(test_3_03);

		XTESTS_RUN_CASE(test_javadoc_truth_beauty_1);
		XTESTS_RUN_CASE(test_javadoc_truth_beauty_2);
		XTESTS_RUN_CASE(test_javadoc_truth_beauty_3);
		XTESTS_RUN_CASE(test_javadoc_truth_beauty_4);
		XTESTS_RUN_CASE(test_javadoc_truth_beauty_5);
		XTESTS_RUN_CASE(test_javadoc_truth_beauty_6);
		XTESTS_RUN_CASE(test_javadoc_truth_beauty_7);
		XTESTS_RUN_CASE(test_javadoc_fruits);
		XTESTS_RUN_CASE(test_javadoc_cheeses);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*platformstl/*/properties_file.hpp", NULL);
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

	typedef platformstl::properties_file				properties_file_t;

	typedef platformstl::filesystem_traits<char>		traits_m_t;


#if 0
	const char contents[] =
	"\
	";
#endif /* 0 */


static void test_1_01()
{
	properties_file_t	props("", properties_file_t::contents);

	XTESTS_TEST_INTEGER_EQUAL(0u, props.size());
}

static void test_1_02()
{
	properties_file_t	props("abc=def", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", props["abc"]);
}

static void test_1_03()
{
	properties_file_t	props("abc def", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", props["abc"]);
}

static void test_1_04()
{
	properties_file_t	props("abc def=ghi", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def=ghi", props["abc"]);
}

static void test_1_05()
{
	properties_file_t	props("abc\\ def=ghi", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", props["abc def"]);
}

static void test_1_06()
{
}

static void test_1_07()
{
	const char contents[] =
"a = b\\\n\
          c\
";

	properties_file_t	props(contents, properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bc", props["a"]);
}

static void test_1_08()
{
	const char contents[] =
"message = Welcome to \\\n\
          Wikipedia!\
";

	properties_file_t	props(contents, properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Welcome to Wikipedia!", props["message"]);
}

static void test_1_09()
{
	properties_file_t	props("\\a\\b\\c=\\d\\e\\f", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", props["abc"]);
}

static void test_1_10()
{
	properties_file_t	props("abc = (d | e) || f ", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("(d | e) || f", props["abc"]);
}

static void test_1_11()
{
	properties_file_t	props("abc\ndef=ghi", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", props["abc"]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", props["def"]);
}

static void test_1_12()
{
	properties_file_t	props("abc=\ndef=ghi", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", props["abc"]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", props["def"]);
}

static void test_1_13()
{
	properties_file_t	props(" \\ \\ abc\\ \\  = \\ \\ ghi\\ ", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("  ghi ", props["  abc  "]);
}


static void test_2_01()
{
	std::string	contents;

	{ for(size_t i = 0; i != 1000; ++i)
	{
		char		sz[21];
		size_t		cch;
		char const*	s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), i, cch);

		contents.append(" name");
		contents.append(s);
		if(0 == (i % 2))
		{
			contents.append(" ");
		}
		else
		{
			contents.append("=");
		}
		contents.append(" v\\\n alue");
		contents.append(s);
		contents.append("\n");
	}}

	properties_file_t	props(contents, properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1000u, props.size()));

	{ for(size_t i = 0; i != 1000; ++i)
	{
		std::string	name("name");
		std::string	value("value");

		char		sz[21];
		size_t		cch;
		char const*	s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), i, cch);

		name.append(s);
		value.append(s);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(value, props[name.c_str()]);
	}}
}


static void test_3_01()
{
	properties_file_t	props("#abc=def\n!abc=def", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, props.size()));
}

static void test_3_02()
{
	properties_file_t	props(" #abc=def\n !abc=def", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, props.size()));
}

static void test_3_03()
{
	properties_file_t	props("\t#abc=def\n\t!abc=def", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0u, props.size()));
}


static void test_javadoc_truth_beauty_1()
{
	properties_file_t	props("Truth = Beauty", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Beauty", props["Truth"]);
}

static void test_javadoc_truth_beauty_2()
{
	properties_file_t	props("       Truth:Beauty", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Beauty", props["Truth"]);
}

static void test_javadoc_truth_beauty_3()
{
	properties_file_t	props("Truth                  :Beauty", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Beauty", props["Truth"]);
}

static void test_javadoc_truth_beauty_4()
{
	properties_file_t	props(" Truth : Beauty ", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Beauty", props["Truth"]);
}

static void test_javadoc_truth_beauty_5()
{
	properties_file_t	props(" Truth : Beauty\\ ", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Beauty ", props["Truth"]);
}

static void test_javadoc_truth_beauty_6()
{
	properties_file_t	props(" Truth : Beauty ful ", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Beauty ful", props["Truth"]);
}

static void test_javadoc_truth_beauty_7()
{
	properties_file_t	props(" Truth : Beauty ful \\ ", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Beauty ful  ", props["Truth"]);
}

static void test_javadoc_fruits()
{
	const char contents[] =
" fruits                           apple, banana, pear, \\\n\
                                  cantaloupe, watermelon, \\\n\
                                  kiwi, mango\n\
\n\
\n\
";

	properties_file_t	props(contents, properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("apple, banana, pear, cantaloupe, watermelon, kiwi, mango", props["fruits"]);
}

static void test_javadoc_cheeses()
{
	properties_file_t	props("cheeses", properties_file_t::contents);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, props.size()));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", props["cheeses"]);
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
