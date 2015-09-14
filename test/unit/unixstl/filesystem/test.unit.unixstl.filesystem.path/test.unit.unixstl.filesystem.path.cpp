/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.unixstl.filesystem.path.cpp
 *
 * Purpose:     Implementation file for the test.unit.unixstl.filesystem.path project.
 *
 * Created:     23rd January 2009
 * Updated:     11th August 2010
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
 * Compiler compatibility
 */

#if defined(_MSC_VER) && \
	_MSC_VER >= 1400
# pragma warning(disable : 4996)
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define PLATFORMSTL_PATH_NO_ALT_SEPARATOR

#include <unixstl/filesystem/path.hpp>

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
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_instantiation_multibyte(void);
	static void test_instantiation_wide(void);
	static void test_ctor_default(void);
	static void test_ctor_c_string(void);
	static void test_ctor_c_string_n(void);
	static void test_ctor_sas(void);
	static void test_ctor_copy(void);
	static void test_assignment_c_string(void);
	static void test_assignment_sas(void);
	static void test_assignment_copy(void);
	static void test_1_11(void);
	static void test_push(void);
	static void test_push_absolute(void);
	static void test_1_14(void);
	static void test_copy(void);

	static void test_pop(void);
	static void test_2_02(void);
	static void test_2_03(void);
	static void test_canonicalise(void);
	static void test_2_05(void);
	static void test_copy_empty(void);
	static void test_copy_1(void);
	static void test_copy_2(void);
	static void test_pop_ext(void);
	static void test_pop_file(void);
	static void test_2_11(void);
	static void test_2_12(void);
	static void test_2_13(void);
	static void test_2_14(void);
	static void test_bad_path_with_pipe(void);
	static void test_2_16(void);
	static void test_2_17(void);
	static void test_2_18(void);
	static void test_2_19(void);
	static void test_2_20(void);
	static void test_2_21(void);
	static void test_2_22(void);
	static void test_2_23(void);
	static void test_2_24(void);
	static void test_2_25(void);
	static void test_2_26(void);
	static void test_2_27(void);
	static void test_2_28(void);
	static void test_2_29(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.unixstl.filesystem.path", verbosity))
	{
		XTESTS_RUN_CASE(test_instantiation_multibyte);
		XTESTS_RUN_CASE(test_instantiation_wide);
		XTESTS_RUN_CASE(test_ctor_default);
		XTESTS_RUN_CASE(test_ctor_c_string);
		XTESTS_RUN_CASE(test_ctor_c_string_n);
		XTESTS_RUN_CASE(test_ctor_sas);
		XTESTS_RUN_CASE(test_ctor_copy);
		XTESTS_RUN_CASE(test_assignment_c_string);
		XTESTS_RUN_CASE(test_assignment_sas);
		XTESTS_RUN_CASE(test_assignment_copy);
		XTESTS_RUN_CASE(test_1_11);
		XTESTS_RUN_CASE(test_push);
		XTESTS_RUN_CASE(test_push_absolute);
		XTESTS_RUN_CASE(test_1_14);
		XTESTS_RUN_CASE(test_copy);

		XTESTS_RUN_CASE(test_pop);
		XTESTS_RUN_CASE(test_2_02);
		XTESTS_RUN_CASE(test_2_03);
		XTESTS_RUN_CASE(test_canonicalise);
		XTESTS_RUN_CASE(test_2_05);
		XTESTS_RUN_CASE(test_copy_empty);
		XTESTS_RUN_CASE(test_copy_1);
		XTESTS_RUN_CASE(test_copy_2);
		XTESTS_RUN_CASE(test_pop_ext);
		XTESTS_RUN_CASE(test_pop_file);
		XTESTS_RUN_CASE(test_2_11);
		XTESTS_RUN_CASE(test_2_12);
		XTESTS_RUN_CASE(test_2_13);
		XTESTS_RUN_CASE(test_2_14);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
		XTESTS_RUN_CASE_THAT_THROWS(test_bad_path_with_pipe, platformstl::platform_exception);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
		XTESTS_RUN_CASE(test_2_16);
		XTESTS_RUN_CASE(test_2_17);
		XTESTS_RUN_CASE(test_2_18);
		XTESTS_RUN_CASE(test_2_19);
		XTESTS_RUN_CASE(test_2_20);
		XTESTS_RUN_CASE(test_2_21);
		XTESTS_RUN_CASE(test_2_22);
		XTESTS_RUN_CASE(test_2_23);
		XTESTS_RUN_CASE(test_2_24);
		XTESTS_RUN_CASE(test_2_25);
		XTESTS_RUN_CASE(test_2_26);
		XTESTS_RUN_CASE(test_2_27);
		XTESTS_RUN_CASE(test_2_28);
		XTESTS_RUN_CASE(test_2_29);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*unixstl/*/path.hpp", NULL);
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
	typedef unixstl::basic_path<char>		path_m_t;
	typedef unixstl::basic_path<wchar_t>	path_w_t;

static void test_instantiation_multibyte()
{
	typedef path_m_t	path_t;
	typedef std::string	string_t;

	if(0)
	{
		// Construction and assignment

		path_t			path1;
		const path_t	path2("abc.def");
		const path_t	path3("abc.def", 7);
		const path_t	path4(string_t("abc.def"));
		const path_t	path5(path4);
		path_t			path6;
		path_t			path7;

		path1	=	"ABC.DEF";
		path6	=	string_t("ABC.DEF");
		path7	=	path3;

		path_t::root("abc.def");
		path_t::root(string_t("abc.def"));

		// Push / pop operations
		path1.pop();
		path1.pop(false);

		path1 = "";

		path1.push("H:\\");
		path1.push("H:\\", false);
		path1.push("xyz");
		path1.push("xyz", false);
		path1.push("mno");
		path1.push("mno", false);
		path1.push("abc.def");
		path1.push("abc.def", false);

		path1 = "";

		path1.push("H:\\");
		path1.push("xyz");
		path1.push("mno");
		path1.push("abc.def");

		path1.clear();

		path1.push("H:\\", false);
		path1.push("xyz", false);
		path1.push("mno", false);
		path1.push("abc.def", false);

		path1.push_ext("txt");
		path1.pop_ext();
		path1.pop_sep();

		path1.clear();

		path1 /= "abc.def";
		path1 /= string_t("ABC.DEF");
		path1 /= path3;

		path1.clear();

		path1 = "../../abc.def";
		path1.make_absolute();

		path1.clear();

		path1 = "../xyz/../mno/./abc.def";
		path1.canonicalise();

		path1.get_file();
		path1.get_ext();
		path1.length();
		path1.size();
		path1.empty();
		path1.c_str();
		path1.exists();
		path1.is_rooted();
		path1.is_absolute();
		path1.has_sep();

		path1.copy(NULL, 0);

		path1 == path2;
		path1 != path2;
	}

	XTESTS_TEST_PASSED();
}

static void test_instantiation_wide()
{
	typedef path_w_t		path_t;
	typedef std::wstring	string_t;

	if(0)
	{
		// Construction and assignment

		path_t			path1;
		const path_t	path2(L"abc.def");
		const path_t	path3(L"abc.def", 7);
		const path_t	path4(string_t(L"abc.def"));
		const path_t	path5(path4);
		path_t			path6;
		path_t			path7;

		path1	=	L"ABC.DEF";
		path6	=	string_t(L"ABC.DEF");
		path7	=	path3;

		path_t::root(L"abc.def");
		path_t::root(string_t(L"abc.def"));

		// Push / pop operations
		path1.pop();
		path1.pop(false);

		path1 = L"";

		path1.push(L"H:\\");
		path1.push(L"H:\\", false);
		path1.push(L"xyz");
		path1.push(L"xyz", false);
		path1.push(L"mno");
		path1.push(L"mno", false);
		path1.push(L"abc.def");
		path1.push(L"abc.def", false);

		path1 = L"";

		path1.push(L"H:\\");
		path1.push(L"xyz");
		path1.push(L"mno");
		path1.push(L"abc.def");

		path1.clear();

		path1.push(L"H:\\", false);
		path1.push(L"xyz", false);
		path1.push(L"mno", false);
		path1.push(L"abc.def", false);

		path1.push_ext(L"txt");
		path1.pop_ext();
		path1.pop_sep();

		path1.clear();

		path1 /= L"abc.def";
		path1 /= string_t(L"ABC.DEF");
		path1 /= path3;

		path1.clear();

#if 0
		path1 = L"../../abc.def";
		path1.make_absolute();

		path1.clear();
#endif /* 0 */

		path1 = L"../xyz/../mno/./abc.def";
		path1.canonicalise();

		path1.get_file();
		path1.get_ext();
		path1.length();
		path1.size();
		path1.empty();
		path1.c_str();
#if 0
		path1.exists();
#endif /* 0 */
		path1.is_rooted();
		path1.is_absolute();
		path1.has_sep();

		path1.copy(NULL, 0);

		path1 == path2;
		path1 != path2;
	}

	XTESTS_TEST_PASSED();
}

static void test_ctor_default()
{
	path_m_t	path;

	XTESTS_TEST_BOOLEAN_TRUE(path.empty());
	XTESTS_TEST_INTEGER_EQUAL(0u, path.size());
	XTESTS_TEST_INTEGER_EQUAL(0u, path.length());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path.c_str());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path.get_file());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path.get_ext());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

	XTESTS_TEST_BOOLEAN_TRUE(path == "");
	XTESTS_TEST_BOOLEAN_TRUE("" == path);
	XTESTS_TEST_BOOLEAN_TRUE(path == path);

	XTESTS_TEST_BOOLEAN_TRUE(path != "XX");
	XTESTS_TEST_BOOLEAN_TRUE("XX" != path);
}

static void test_ctor_c_string()
{
	{
		path_m_t	path("abc.def");

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\abc.def");

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/abc.def");

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(8u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(8u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "/abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("/abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\mno\\abc.def");

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\mno\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\mno\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/mno/abc.def");

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(12u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(12u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/mno/abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/mno/abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "/mno/abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("/mno/abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_ctor_c_string_n()
{
	{
		path_m_t	path("abc.def", 7);

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\abc.def", 10);

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/abc.def", 8);

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(8u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(8u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "/abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("/abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\mno\\abc.def", 14);

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\mno\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\mno\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/mno/abc.def", 12);

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(12u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(12u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/mno/abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/mno/abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "/mno/abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("/mno/abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_ctor_sas()
{
	typedef std::string	string_t;

	{
		path_m_t	path(string_t("abc.def"));

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path(string_t("H:\\abc.def"));

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path(string_t("H:\\mno\\abc.def"));

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\mno\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\mno\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_ctor_copy()
{
	typedef std::string	string_t;

	{
		path_m_t	path_("abc.def");
		path_m_t	path(path_);

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path_("H:\\abc.def");
		path_m_t	path(path_);

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path_("H:\\mno\\abc.def");
		path_m_t	path(path_);

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\mno\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\mno\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_assignment_c_string()
{
	{
		path_m_t	path;

		path = "abc.def";

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		path = "H:\\abc.def";

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		path = "H:\\mno\\abc.def";

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\mno\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\mno\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_assignment_sas()
{
	typedef std::string	string_t;

	{
		path_m_t	path;

		path = string_t("abc.def");

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		path = string_t("H:\\abc.def");

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		path = string_t("H:\\mno\\abc.def");

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\mno\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\mno\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_assignment_copy()
{
	typedef std::string	string_t;

	{
		path_m_t	path_("abc.def");
		path_m_t	path;

		path = path_;

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(7u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path_("H:\\abc.def");
		path_m_t	path;

		path = path_;

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(10u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path_("H:\\mno\\abc.def");
		path_m_t	path;

		path = path_;

		XTESTS_TEST_BOOLEAN_FALSE(path.empty());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.size());
		XTESTS_TEST_INTEGER_EQUAL(14u, path.length());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path.c_str());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc.def", path.get_file());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", path.get_ext());
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\mno\\abc.def", path);

		XTESTS_TEST_BOOLEAN_TRUE(path == "H:\\mno\\abc.def");
		XTESTS_TEST_BOOLEAN_TRUE("H:\\mno\\abc.def" == path);
		XTESTS_TEST_BOOLEAN_TRUE(path == path);

		XTESTS_TEST_BOOLEAN_TRUE(path != "abc");
		XTESTS_TEST_BOOLEAN_TRUE("abc" != path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_1_11()
{
}

static void test_push()
{
#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:/", false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:/", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:\\", false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:\\", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:\\dir", false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\dir", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:\\dir", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\dir/", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("H:\\dir\\", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:\\dir\\", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("abc");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", path);
	}

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("abc", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc/", path);
	}

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("/");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/", path);
	}

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("/", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/", path);
	}

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("\\\\server\\share");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share", path);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("\\\\server\\share", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share/", path);
	}

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("\\\\server\\share/", false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share/", path);
	}

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("\\\\server\\share/", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share/", path);
	}

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("\\\\server\\share\\", false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\", path);
	}

	{
		path_m_t	path;

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.push("\\\\server\\share\\", true);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_push_absolute()
{
#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path;

		path /= "\\\\server\\share\\directory\\abc.def";

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\abc.def", path);

		path /= "\\\\server\\share\\directory\\abc.def";

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\abc.def", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory", path);

		path.push("dir2");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2", path);

		path.push("dir3");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3", path);

		path.push("abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc.def", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc", path);

		path.push_ext("DEF");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc.DEF", path);

		path.push_ext("GHI");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc.DEF.GHI", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc.DEF", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc", path);

		path.push_ext(".def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc.def", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc", path);

		path.push_ext(".");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc.", path);

		path.push_ext("def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\directory\\dir2\\dir3\\abc..def", path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path;

		path /= "/user/matt/dir1/abc.def";

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/abc.def", path);

		path /= "/user/matt/dir1/abc.def";

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/abc.def", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1", path);

		path.push("dir2");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2", path);

		path.push("dir3");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3", path);

		path.push("abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc.def", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc", path);

		path.push_ext("DEF");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc.DEF", path);

		path.push_ext("GHI");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc.DEF.GHI", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc.DEF", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc", path);

		path.push_ext(".def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc.def", path);

		path.pop_ext();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc", path);

		path.push_ext(".");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc.", path);

		path.push_ext("def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/user/matt/dir1/dir2/dir3/abc..def", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_1_14()
{
}

static void test_copy()
{
#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\freelibs\\recls\\recls.ruby\\src");

		path /= "def";

		XTESTS_TEST_INTEGER_EQUAL(36u, path.size());
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/freelibs/recls/recls.ruby/src");

		path /= "def";

		XTESTS_TEST_INTEGER_EQUAL(34u, path.size());
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
}

static void test_pop()
{
	{
		path_m_t	path1;
		path_m_t	path2;

		path1.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(path2, path1);
	}

	{
		path_m_t	path1;
		path_m_t	path2;

		path1.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(path2, path1);
	}

	{
		path_m_t	path1("abc.def");
		path_m_t	path2;

		path1.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(path2, path1);
	}

	{
		path_m_t	path1("abc.def");
		path_m_t	path2;

		path1.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(path2, path1);
	}

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\abc.def");

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\", path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/abc.def");

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\abc.def");

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\", path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/abc.def");

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\xyz\\mno\\abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\xyz\\mno\\abc.def", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\xyz\\mno", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\xyz", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("", path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/xyz/mno/abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/xyz/mno/abc.def", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/xyz/mno", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/xyz", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("H:\\xyz\\mno\\abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\xyz\\mno\\abc.def", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\xyz\\mno\\", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\xyz\\", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("H:\\", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("", path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/xyz/mno/abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/xyz/mno/abc.def", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/xyz/mno/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/xyz/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("\\\\server\\share\\xyz\\mno\\abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\xyz\\mno\\abc.def", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\xyz\\mno", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\xyz", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/users/matt/xyz/mno/abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/matt/xyz/mno/abc.def", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/matt/xyz/mno", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/matt/xyz", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/matt", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	{
		path_m_t	path("\\\\server\\share\\xyz\\mno\\abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\xyz\\mno\\abc.def", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\xyz\\mno\\", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\xyz\\", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\\\\server\\share\\", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);
	}
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	{
		path_m_t	path("/users/matt/xyz/mno/abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/matt/xyz/mno/abc.def", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/matt/xyz/mno/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/matt/xyz/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/matt/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/users/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);
	}
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

	{
		path_m_t	path("/xyz/mno/abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/xyz/mno/abc.def", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/xyz/mno", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/xyz", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/", path);

		path.pop();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);
	}

	{
		path_m_t	path("/xyz/mno/abc.def");

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/xyz/mno/abc.def", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/xyz/mno/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/xyz/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("/", path);

		path.pop(false);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", path);
	}
}

static void test_2_02()
{
}

static void test_2_03()
{
}

	struct canonicalisation_pair
	{
		char const*	pre;
		char const*	post;
	};

static void test_canonicalise()
{
	static const canonicalisation_pair	pairs[] =
	{
		{	"abc",					NULL		},
		{	"../abc",				NULL		},
		{	".././abc",				"../abc"	},
		{	"./abc",				"abc"		},
		{	"../../abc",			NULL		},
		{	"../../abc/..",			"../.."		},
		{	"././././././././././abc/././././././././././././././././././",			"abc"		},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(pairs); ++i)
	{
		char const*	pre		=	pairs[i].pre;
		char const*	post	=	(NULL != pairs[i].post) ? pairs[i].post : pairs[i].pre;
		path_m_t	path(pre);

		path.canonicalise();

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(post, path);

	}}
}

static void test_2_05()
{
}

static void test_copy_empty()
{
	path_m_t path;

	{
		size_t cch = path.copy(NULL, 0);

		XTESTS_TEST_INTEGER_EQUAL(path.size(), cch);
	}

	{
		char buff[101];

		{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(buff); ++i)
		{
			size_t cch = path.copy(&buff[0], i);

			if(i < path.size())
			{
				XTESTS_TEST_INTEGER_EQUAL(i, cch);
			}
			else
			{
				XTESTS_TEST_INTEGER_EQUAL(path.size(), cch);
			}
		}}
	}
}

static void test_copy_1()
{
	path_m_t path("/");

	{
		size_t cch = path.copy(NULL, 0);

		XTESTS_TEST_INTEGER_EQUAL(path.size(), cch);
	}

	{
		char buff[101];

		{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(buff); ++i)
		{
			size_t	cch = path.copy(&buff[0], i);

			if(i <= path.size())
			{
				XTESTS_TEST_INTEGER_EQUAL(i, cch);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(path, buff, int(i));
			}
			else
			{
				XTESTS_TEST_INTEGER_EQUAL(path.size(), cch);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL(path, buff);
			}
		}}
	}
}

static void test_copy_2()
{
#ifndef PLATFORMSTL_PATH_NO_ALT_SEPARATOR
	path_m_t path("H:\\xyz\\mno\\abc.def");
#else /* ? !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */
	path_m_t path("/xyz/mno/abc.def");
#endif /* !PLATFORMSTL_PATH_NO_ALT_SEPARATOR */

	{
		size_t cch = path.copy(NULL, 0);

		XTESTS_TEST_INTEGER_EQUAL(path.size(), cch);
	}

	{
		char buff[101];

		{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(buff); ++i)
		{
			size_t	cch = path.copy(&buff[0], i);

			if(i <= path.size())
			{
				XTESTS_TEST_INTEGER_EQUAL(i, cch);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(path, buff, int(i));
			}
			else
			{
				XTESTS_TEST_INTEGER_EQUAL(path.size(), cch);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL(path, buff);
			}
		}}
	}
}

static void test_pop_ext()
{
}

static void test_pop_file()
{
}

static void test_2_11()
{
}

static void test_2_12()
{
}

static void test_2_13()
{
}

static void test_2_14()
{
}

static void test_bad_path_with_pipe()
{
	path_m_t	path("|");

	path.make_absolute();
}

static void test_2_16()
{
}

static void test_2_17()
{
}

static void test_2_18()
{
}

static void test_2_19()
{
}

static void test_2_20()
{
}

static void test_2_21()
{
}

static void test_2_22()
{
}

static void test_2_23()
{
}

static void test_2_24()
{
}

static void test_2_25()
{
}

static void test_2_26()
{
}

static void test_2_27()
{
}

static void test_2_28()
{
}

static void test_2_29()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
