/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.filesystem.findfile_sequence.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.filesystem.findfile_sequence project.
 *
 * Created:     31st December 2008
 * Updated:     6th May 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/filesystem/findfile_sequence.hpp>

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

	static void test_1_17(void);
	static void test_1_18(void);
	static void test_1_19(void);
	static void test_1_20(void);
	static void test_1_21(void);
	static void test_1_22(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.component.winstl.filesystem.findfile_sequence", verbosity))
	{
		XTESTS_RUN_CASE(test_1_17);
		XTESTS_RUN_CASE(test_1_18);
		XTESTS_RUN_CASE(test_1_19);
		XTESTS_RUN_CASE(test_1_20);
		XTESTS_RUN_CASE(test_1_21);
		XTESTS_RUN_CASE(test_1_22);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*winstl/*/findfile_sequence.hpp", NULL);
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

	typedef winstl::basic_findfile_sequence<char>			findfile_sequence_m_t;
	typedef winstl::basic_findfile_sequence<wchar_t>		findfile_sequence_w_t;

	typedef winstl::filesystem_traits<char>					traits_m_t;
	typedef winstl::filesystem_traits<wchar_t>				traits_w_t;

	typedef std::basic_string<char>					string_m_t;
	typedef std::basic_string<wchar_t>				string_w_t;

#if 0
	static string_m_t get_windows_directory()
	{
		char	path[1 + _MAX_PATH];
		size_t	cch = ::GetWindowsDirectoryA(&path[0], STLSOFT_NUM_ELEMENTS(path));

		return string_m_t(path, cch);
	}

	static string_m_t get_current_directory()
	{
		char	path[1 + _MAX_PATH];
		size_t	cch = ::GetCurrentDirectoryA(STLSOFT_NUM_ELEMENTS(path), &path[0]);

		return string_m_t(path, cch);
	}

	static string_m_t get_a_file_in_win_dir()
	{
		string_m_t	windir	=	get_windows_directory();
		string_m_t	path	=	windir + "\\*.*";

		WIN32_FIND_DATAA	data;
		HANDLE				h = ::FindFirstFileA(path.c_str(), &data);

		if(INVALID_HANDLE_VALUE == h)
		{
			throw std::runtime_error("failed to find a file in Windows directory");
		}

		return data.cFileName;
	}
#endif /* 0 */


static void test_1_17()
{
	findfile_sequence_m_t	files("*.*");

	{ for(findfile_sequence_m_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_18()
{
	findfile_sequence_m_t	files("*.*", findfile_sequence_m_t::relativePath);

	{ for(findfile_sequence_m_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_19()
{
	findfile_sequence_m_t	files("/", "*.*", findfile_sequence_m_t::files);

	{ for(findfile_sequence_m_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_20()
{
	findfile_sequence_m_t	directories("/", "*.*", findfile_sequence_m_t::directories);

	{ for(findfile_sequence_m_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_21()
{
	findfile_sequence_m_t	files("*.*", '|', findfile_sequence_m_t::files);

	{ for(findfile_sequence_m_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_22()
{
	findfile_sequence_m_t	files(".", "*.*", '|', findfile_sequence_m_t::files);

	{ for(findfile_sequence_m_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
