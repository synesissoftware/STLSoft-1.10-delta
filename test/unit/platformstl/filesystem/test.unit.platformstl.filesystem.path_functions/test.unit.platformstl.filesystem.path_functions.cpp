/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.platformstl.filesystem.path_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.platformstl.filesystem.path_functions project.
 *
 * Created:     3rd May 2014
 * Updated:     3rd May 2014
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

#include <platformstl/filesystem/path_functions.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_get_executable_name_from_path_exists(void);
    static void test_get_executable_name_from_path_1(void);
    static void test_get_executable_name_from_path_2(void);
    static void test_get_executable_name_from_path_3(void);
    static void test_get_executable_name_from_path_4(void);
    static void test_get_executable_name_from_path_5(void);
    static void test_get_executable_name_from_path_6(void);
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

    if(XTESTS_START_RUNNER("test.unit.platformstl.filesystem.path_functions", verbosity))
    {
        XTESTS_RUN_CASE(test_get_executable_name_from_path_exists);
        XTESTS_RUN_CASE(test_get_executable_name_from_path_1);
        XTESTS_RUN_CASE(test_get_executable_name_from_path_2);
        XTESTS_RUN_CASE(test_get_executable_name_from_path_3);
        XTESTS_RUN_CASE(test_get_executable_name_from_path_4);
        XTESTS_RUN_CASE(test_get_executable_name_from_path_5);
        XTESTS_RUN_CASE(test_get_executable_name_from_path_6);
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
	using stlsoft::stlsoft_C_string_slice_a_t;


static void test_get_executable_name_from_path_exists()
{
	&platformstl::get_executable_name_from_path;

    XTESTS_TEST_PASSED();
}

static void test_get_executable_name_from_path_1()
{
	char const* const					input	=	"";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_INTEGER_EQUAL(0u, result.len);
}

static void test_get_executable_name_from_path_2()
{
	char const* const					input	=	"/program";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("program", result.ptr, result.len);
}

static void test_get_executable_name_from_path_3()
{
#ifdef _WIN32
	char const* const					input	=	"\\program";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("program", result.ptr, result.len);
#endif /* _WIN32 */
}

static void test_get_executable_name_from_path_4()
{
	char const* const					input	=	"/program.exe";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

#ifdef _WIN32
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("program", result.ptr, result.len);
#else /* ? _WIN32 */
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("program.exe", result.ptr, result.len);
#endif /* _WIN32 */
}

static void test_get_executable_name_from_path_5()
{
#ifdef _WIN32
	char const* const					input	=	"C:\\program.exe";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("program", result.ptr, result.len);
#endif /* _WIN32 */
}

static void test_get_executable_name_from_path_6()
{
	char const* const					input	=	"dir0/a.out";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("a.out", result.ptr, result.len);
}

static void test_1_7()
{
#ifdef _WIN32
	char const* const					input	=	"dir0\\a.out";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("a.out", result.ptr, result.len);
#endif /* _WIN32 */
}

static void test_1_8()
{
	char const* const					input	=	".out";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(".out", result.ptr, result.len);
}

static void test_1_9()
{
	char const* const					input	=	"dir0/.out";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(".out", result.ptr, result.len);
}

static void test_1_10()
{
#ifdef _WIN32
	char const* const					input	=	"dir0\\.out";
	stlsoft_C_string_slice_a_t const	result	=	platformstl::get_executable_name_from_path(input);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(".out", result.ptr, result.len);
#endif /* _WIN32 */
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
