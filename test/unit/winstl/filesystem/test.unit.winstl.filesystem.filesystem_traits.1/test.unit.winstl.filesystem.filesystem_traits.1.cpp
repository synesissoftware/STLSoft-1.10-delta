/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.filesystem.filesystem_traits.1.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.filesystem.filesystem_traits.1 project.
 *
 * Created:     31st December 2008
 * Updated:     26th February 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/filesystem/filesystem_traits.hpp>

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
//#include <winstl/filesystem/current_directory.hpp>
//#include <winstl/system/windows_directory.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_get_full_path_name_1(void);
    static void test_get_full_path_name_2(void);
    static void test_stat(void);
    static void test_pathComparisonIsCaseSensitive(void);
    static void test_1_18(void);
    static void test_1_19(void);
    static void test_is_dots_1(void);
    static void test_is_path_rooted_1(void);
    static void test_is_path_rooted_2(void);
    static void test_is_path_absolute_1(void);
    static void test_is_path_absolute_2(void);
    static void test_is_path_UNC_1(void);
    static void test_is_path_UNC_2(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.filesystem.filesystem_traits.1", verbosity))
    {
        XTESTS_RUN_CASE(test_get_full_path_name_1);
        XTESTS_RUN_CASE(test_get_full_path_name_2);
        XTESTS_RUN_CASE(test_stat);
        XTESTS_RUN_CASE(test_pathComparisonIsCaseSensitive);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
		XTESTS_RUN_CASE(test_is_dots_1);
		XTESTS_RUN_CASE(test_is_path_rooted_1);
		XTESTS_RUN_CASE(test_is_path_rooted_2);
		XTESTS_RUN_CASE(test_is_path_absolute_1);
		XTESTS_RUN_CASE(test_is_path_absolute_2);
		XTESTS_RUN_CASE(test_is_path_UNC_1);
		XTESTS_RUN_CASE(test_is_path_UNC_2);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/filesystem_traits.hpp", NULL);
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

    typedef winstl::filesystem_traits<char>         filesystem_traits_m_t;
    typedef winstl::filesystem_traits<wchar_t>      filesystem_traits_w_t;

    typedef std::basic_string<char>                 string_m_t;
    typedef std::basic_string<wchar_t>              string_w_t;

    static string_m_t get_windows_directory()
    {
        char    path[1 + _MAX_PATH];
        size_t  cch = ::GetWindowsDirectoryA(&path[0], STLSOFT_NUM_ELEMENTS(path));

        return string_m_t(path, cch);
    }

    static string_m_t get_current_directory()
    {
        char    path[1 + _MAX_PATH];
        size_t  cch = ::GetCurrentDirectoryA(STLSOFT_NUM_ELEMENTS(path), &path[0]);

        return string_m_t(path, cch);
    }

    static string_m_t get_a_file_in_win_dir()
    {
        string_m_t  windir  =   get_windows_directory();
        string_m_t  path    =   windir + "\\*.*";

        WIN32_FIND_DATAA    data;
        HANDLE              h = ::FindFirstFileA(path.c_str(), &data);

        if(INVALID_HANDLE_VALUE == h)
        {
            throw std::runtime_error("failed to find a file in Windows directory");
        }

        return windir + '\\' + data.cFileName;
    }


static void test_get_full_path_name_1()
{
    {
        const string_m_t windir =   get_windows_directory();
        const string_m_t file   =   get_a_file_in_win_dir();
        const string_m_t cwd    =   get_current_directory();

        char    buff[1 + _MAX_PATH];
        size_t  cch;

        std::fill(&buff[0], &buff[0] + STLSOFT_NUM_ELEMENTS(buff), '~');
        cch = filesystem_traits_m_t::get_full_path_name(".", &buff[0], STLSOFT_NUM_ELEMENTS(buff));

        XTESTS_TEST_INTEGER_EQUAL(cwd.size(), cch);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(cwd, buff);

        std::fill(&buff[0], &buff[0] + STLSOFT_NUM_ELEMENTS(buff), '~');
        cch = filesystem_traits_m_t::get_full_path_name("\".\"", &buff[0], STLSOFT_NUM_ELEMENTS(buff));

        XTESTS_TEST_INTEGER_EQUAL(cwd.size() + 2, cch);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("\"" + cwd + "\"", buff);


        std::fill(&buff[0], &buff[0] + STLSOFT_NUM_ELEMENTS(buff), '~');
        cch = filesystem_traits_m_t::get_full_path_name(".", &buff[0], 10u);
        buff[cch] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(10u, cch);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(cwd.substr(0u, 10u), buff);

        std::fill(&buff[0], &buff[0] + STLSOFT_NUM_ELEMENTS(buff), '~');
        cch = filesystem_traits_m_t::get_full_path_name("\".\"", &buff[0], 10u);
        buff[cch] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(10u, cch);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("\"" + cwd.substr(0u, 9u), buff);
    }
}

static void test_get_full_path_name_2()
{
    char    buff[1 + _MAX_PATH];
    size_t  cch;

    cch = filesystem_traits_m_t::get_full_path_name("", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);

    cch = filesystem_traits_m_t::get_full_path_name(".", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);

    cch = filesystem_traits_m_t::get_full_path_name("./", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);

    cch = filesystem_traits_m_t::get_full_path_name("\".\"", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);

    cch = filesystem_traits_m_t::get_full_path_name("\"./\"", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);

    cch = filesystem_traits_m_t::get_full_path_name("./abc", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);

    cch = filesystem_traits_m_t::get_full_path_name("./abc/", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);

    cch = filesystem_traits_m_t::get_full_path_name("\"./abc\"", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);

    cch = filesystem_traits_m_t::get_full_path_name("\"./abc/\"", &buff[0], STLSOFT_NUM_ELEMENTS(buff));
    STLSOFT_SUPPRESS_UNUSED(cch);
}

static void test_stat()
{
    {
        filesystem_traits_m_t::stat_data_type   stat_data;

        XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::stat("C:\\", &stat_data));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("C:\\", stat_data.cFileName);

        char    winDir[1 + _MAX_PATH];

        if(!::GetWindowsDirectoryA(&winDir[0], STLSOFT_NUM_ELEMENTS(winDir)))
        {
        }
        else
        {
            XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::stat((string_m_t(winDir) + "\\").c_str(), &stat_data));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(filesystem_traits_m_t::str_rchr(winDir, '\\') + 1, stat_data.cFileName);
        }
    }
}

static void test_pathComparisonIsCaseSensitive()
{
    XTESTS_TEST_ENUM_EQUAL(0, filesystem_traits_m_t::pathComparisonIsCaseSensitive);
}

static void test_1_18()
{
}

static void test_1_19()
{
}

static void test_is_dots_1()
{
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_dots(""));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_dots("a"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_dots("."));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_dots(".."));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_dots("./"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_dots("../"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_dots("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_dots("../abc"));
}

static void test_is_path_rooted_1()
{
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted(""));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("a"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("."));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted(".."));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("./"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("../"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("../abc"));

	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("/"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("/a"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("/./a"));

	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\a"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\.\\a"));

	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("H:\\"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("H:\\a"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("H:\\./a"));

	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\a"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\./a"));
}

static void test_is_path_rooted_2()
{
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted(".", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted(".", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("..", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("..", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("..", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("./", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("./", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("./", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("../", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("../", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("../", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("../", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("../abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("../abc"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("/", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("/", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("/a", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("/a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("/a", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("/./a", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("/./a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("/./a", 4));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("\\", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("\\a", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\a", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("\\.\\a", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\.\\a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\.\\a", 4));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("H:\\", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("H:\\", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("H:\\", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("H:\\", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("H:\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("H:\\a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("H:\\a", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("H:\\a", 3));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("H:\\./a"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\a", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\a", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\a", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\./a", 0));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\./a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\./a", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_rooted("\\\\svr\\share\\./a", 3));
}

static void test_is_path_absolute_1()
{
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute(""));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("a"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("."));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute(".."));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("./"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("../"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("../abc"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/a"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/./a"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\a"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\.\\a"));

	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("H:\\"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("H:\\a"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("H:\\./a"));

	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\a"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\./a"));
}

static void test_is_path_absolute_2()
{
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute(".", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute(".", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("..", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("..", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("..", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("./", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("./", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("./", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("../", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("../", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("../", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("../", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("../abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("../abc"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/a", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/./a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/./a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("/./a", 4));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\a", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\.\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\.\\a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\.\\a", 4));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("H:\\", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("H:\\", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("H:\\", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("H:\\", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("H:\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("H:\\a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("H:\\a", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("H:\\a", 3));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("H:\\./a"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\a", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\a", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\./a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\./a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\./a", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_absolute("\\\\svr\\share\\./a", 3));
}

static void test_is_path_UNC_1()
{
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC(""));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("a"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("."));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC(".."));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("./"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("../"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("../abc"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/a"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/./a"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\a"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\.\\a"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\a"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\./a"));

	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\a"));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\./a"));
}

static void test_is_path_UNC_2()
{
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC(".", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC(".", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("..", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("..", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("..", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("./", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("./", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("./", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("../", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("../", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("../", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("../", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("./abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("../abc"));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("../abc"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/a", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/./a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/./a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("/./a", 4));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\a", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\.\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\.\\a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\.\\a", 4));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\a", 1));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\a", 2));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\a", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("H:\\./a"));

	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\a", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\a", 3));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\./a", 0));
	XTESTS_TEST_BOOLEAN_FALSE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\./a", 1));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\./a", 2));
	XTESTS_TEST_BOOLEAN_TRUE(filesystem_traits_m_t::is_path_UNC("\\\\svr\\share\\./a", 3));
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
