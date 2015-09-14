/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.filesystem.filesystem_traits.2.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.filesystem.filesystem_traits.2 project.
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

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_stat(void);
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

	if(XTESTS_START_RUNNER("test.unit.winstl.filesystem.filesystem_traits.2", verbosity))
	{
		XTESTS_RUN_CASE(test_stat);
		XTESTS_RUN_CASE(test_1_17);
		XTESTS_RUN_CASE(test_1_18);
		XTESTS_RUN_CASE(test_1_19);

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

	typedef winstl::filesystem_traits<char>			traits_m_t;
	typedef winstl::filesystem_traits<wchar_t>		traits_w_t;

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
no_file_found:
			throw std::runtime_error("failed to find a file in Windows directory");
		}
		else
		{
			for(; traits_m_t::is_directory(&data); )
			{
				if(!::FindNextFileA(h, &data))
				{
					goto no_file_found;
				}
			}

			return windir + '\\' + data.cFileName;
		}
	}
#endif /* 0 */


static void test_stat()
{
#if 0
	traits_m_t::stat_data_type	stat_data;

	XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::stat(get_a_file_in_win_dir().c_str(), &stat_data));

	stlsoft::uint64_t	expected;
	stlsoft::uint64_t	actual;

	expected = stat_data.nFileSizeHigh;
	expected <<= 32;
	expected += stat_data.nFileSizeLow;

	actual = traits_m_t::get_file_size(&stat_data);

	XTESTS_TEST_INTEGER_EQUAL(expected, actual);
#endif /* 0 */
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
