/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.unixstl.filesystem.glob_sequence.cpp
 *
 * Purpose:     Implementation file for the test.component.unixstl.filesystem.glob_sequence project.
 *
 * Created:     24th January 2009
 * Updated:     4th June 2012
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2012, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

//#define UNIXSTL_GLOB_SEQUENCE_TRUST_ONLYDIR
//#define UNIXSTL_GLOB_SEQUENCE_TRUST_ONLYFILE
#define UNIXSTL_GLOB_SEQUENCE_DONT_TRUST_MARK

#include <unixstl/filesystem/glob_sequence.hpp>

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
#include <unixstl/filesystem/filesystem_traits.hpp>
#include <unixstl/filesystem/path.hpp>
#include <unixstl/filesystem/current_directory.hpp>

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

    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);
    static void test_1_20(void);
    static void test_1_21(void);
    static void test_1_22(void);
    static void test_1_23(void);
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_1_26(void);
	static void test_1_27(void);
	static void test_1_28(void);
	static void test_1_29(void);
	static void test_1_30(void);

    static void test_2_13(void);
    static void test_2_14(void);
    static void test_2_15(void);
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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.unixstl.filesystem.glob_sequence", verbosity))
    {
		XTESTS_RUN_CASE(test_1_00);

        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_1_29);
        XTESTS_RUN_CASE(test_1_30);

        XTESTS_RUN_CASE(test_2_13);
        XTESTS_RUN_CASE(test_2_14);
        XTESTS_RUN_CASE(test_2_15);
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

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*unixstl/*/glob_sequence.hpp", NULL);
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

    typedef unixstl::glob_sequence              glob_sequence_t;
    typedef unixstl::filesystem_traits<char>    traits_m_t;
    typedef unixstl::basic_path<char>			path_m_t;

static void test_1_00(void)
{
#ifdef _WIN32
	{
		char			buff[] = "?";
		size_t const	n = traits_m_t::get_full_path_name("C:\\", buff, 0u);

		XTESTS_TEST_INTEGER_EQUAL(0u, n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("?", buff);
	}

	{
		size_t const n = traits_m_t::get_full_path_name("C:\\", NULL, 0u);

		XTESTS_TEST_INTEGER_EQUAL(3u, n);
	}

	{
		char			buff[] = "????";
		size_t const	n = traits_m_t::get_full_path_name("C:\\", buff, 1);

		XTESTS_TEST_INTEGER_EQUAL(1u, n);
		XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C???", buff);
	}

	{
		char			buff[] = "????";
		size_t const	n = traits_m_t::get_full_path_name("C:\\", buff, 2);

		XTESTS_TEST_INTEGER_EQUAL(2u, n);
		XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
		XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:??", buff);
	}

	{
		char			buff[] = "????";
		size_t const	n = traits_m_t::get_full_path_name("C:\\", buff, 3);

		XTESTS_TEST_INTEGER_EQUAL(3u, n);
		XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
		XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
		XTESTS_TEST_CHARACTER_EQUAL('\\', buff[2]);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\?", buff);
	}

	{ for(size_t i = 4; i != 1000; ++i)
	{
		char			buff[1001];
		size_t const	n = traits_m_t::get_full_path_name("C:\\", buff, i);

		XTESTS_TEST_INTEGER_EQUAL(3u, n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\", buff);
	}}


	{
		unixstl::current_directory	cwd;

		chdir("C:\\");

		{
			{
				char			buff[] = "?";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 0u);

				XTESTS_TEST_INTEGER_EQUAL(0u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("?", buff);
			}

			{
				size_t const	n = traits_m_t::get_full_path_name(".", NULL, 0u);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
			}

			{
				char			buff[] = "????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 1);

				XTESTS_TEST_INTEGER_EQUAL(1u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C???", buff);
			}

			{
				char			buff[] = "????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 2);

				XTESTS_TEST_INTEGER_EQUAL(2u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:??", buff);
			}

			{
				char			buff[] = "????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 3);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
				XTESTS_TEST_CHARACTER_EQUAL('\\', buff[2]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\?", buff);
			}

			{ for(size_t i = 4; i != 1000; ++i)
			{
				char			buff[1001];
				size_t const	n = traits_m_t::get_full_path_name(".", buff, i);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\", buff);
			}}
		}

		{
			{
				char			buff[] = "?";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 0u);

				XTESTS_TEST_INTEGER_EQUAL(0u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("?", buff);
			}

			{
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", NULL, 0u);

				XTESTS_TEST_INTEGER_EQUAL(14u, n);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 1);

				XTESTS_TEST_INTEGER_EQUAL(1u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C??????????????", buff);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 2);

				XTESTS_TEST_INTEGER_EQUAL(2u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:?????????????", buff);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 3);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\????????????", buff);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 4);

				XTESTS_TEST_INTEGER_EQUAL(4u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\a???????????", buff);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 8);

				XTESTS_TEST_INTEGER_EQUAL(8u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\d???????", buff);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 12);

				XTESTS_TEST_INTEGER_EQUAL(12u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.g???", buff);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 13);

				XTESTS_TEST_INTEGER_EQUAL(13u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.gh??", buff);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 14);

				XTESTS_TEST_INTEGER_EQUAL(14u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.ghi?", buff);
			}

			{
				char			buff[] = "???????????????";
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, 15);

				XTESTS_TEST_INTEGER_EQUAL(14u, n);
				XTESTS_TEST_CHARACTER_EQUAL('C', buff[0]);
				XTESTS_TEST_CHARACTER_EQUAL(':', buff[1]);
				XTESTS_TEST_CHARACTER_EQUAL('\\', buff[2]);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.ghi", buff);
			}

			{ for(size_t i = 15; i != 1000; ++i)
			{
				char			buff[1001];
				size_t const	n = traits_m_t::get_full_path_name("abc\\def.ghi", buff, i);

				XTESTS_TEST_INTEGER_EQUAL(14u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.ghi", buff);
			}}
		}

#if 0	/* UNIXSTL does not support quoted paths */
		{
			{
				char			buff[] = "?";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 0u);

				XTESTS_TEST_INTEGER_EQUAL(0u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("?", buff);
			}

			{
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", NULL, 0u);

				XTESTS_TEST_INTEGER_EQUAL(16u, n);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 1);

				XTESTS_TEST_INTEGER_EQUAL(1u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("\"??????????????", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 2);

				XTESTS_TEST_INTEGER_EQUAL(2u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:?????????????", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 3);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\????????????", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 4);

				XTESTS_TEST_INTEGER_EQUAL(4u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\a???????????", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 8);

				XTESTS_TEST_INTEGER_EQUAL(8u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\d???????", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 12);

				XTESTS_TEST_INTEGER_EQUAL(12u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.g???", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 13);

				XTESTS_TEST_INTEGER_EQUAL(13u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.gh??", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 14);

				XTESTS_TEST_INTEGER_EQUAL(14u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.ghi?", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 15);

				XTESTS_TEST_INTEGER_EQUAL(14u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.ghi", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 16);

				XTESTS_TEST_INTEGER_EQUAL(14u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.ghi", buff);
			}

			{
				char			buff[] = "?????????????????";
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, 17);

				XTESTS_TEST_INTEGER_EQUAL(14u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.ghi", buff);
			}

			{ for(size_t i = 17; i != 1000; ++i)
			{
				char			buff[1001];
				size_t const	n = traits_m_t::get_full_path_name("\"abc\\def.ghi\"", buff, i);

				XTESTS_TEST_INTEGER_EQUAL(16u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\abc\\def.ghi", buff);
			}}
		}
#endif /* 0 */

		chdir(cwd);
	}


	{
		unixstl::current_directory	cwd;

		if(0 == chdir("C:\\temp"))
		{
			{
				char			buff[] = "?";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 0u);

				XTESTS_TEST_INTEGER_EQUAL(0u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("?", buff);
			}

			{
				size_t const	n = traits_m_t::get_full_path_name(".", NULL, 0u);

				XTESTS_TEST_INTEGER_EQUAL(7u, n);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 1);

				XTESTS_TEST_INTEGER_EQUAL(1u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C???????", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 2);

				XTESTS_TEST_INTEGER_EQUAL(2u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:??????", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 3);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\?????", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 4);

				XTESTS_TEST_INTEGER_EQUAL(4u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\t????", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 5);

				XTESTS_TEST_INTEGER_EQUAL(5u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\te???", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 6);

				XTESTS_TEST_INTEGER_EQUAL(6u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\tem??", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 7);

				XTESTS_TEST_INTEGER_EQUAL(7u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\temp?", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name(".", buff, 8);

				XTESTS_TEST_INTEGER_EQUAL(7u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\temp", buff);
			}

			{ for(size_t i = 9; i != 1000; ++i)
			{
				char			buff[1001];
				size_t const	n = traits_m_t::get_full_path_name(".", buff, i);

				XTESTS_TEST_INTEGER_EQUAL(7u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\temp", buff);
			}}
		}

		chdir(cwd);
	}


{
		unixstl::current_directory	cwd;

		if(0 == chdir("C:\\temp"))
		{
			{
				char			buff[] = "?";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 0u);

				XTESTS_TEST_INTEGER_EQUAL(0u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("?", buff);
			}

			{
				size_t const	n = traits_m_t::get_full_path_name("..", NULL, 0u);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 1);

				XTESTS_TEST_INTEGER_EQUAL(1u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C???????", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 2);

				XTESTS_TEST_INTEGER_EQUAL(2u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:??????", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 3);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\?????", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 4);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 5);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 6);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 7);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\", buff);
			}

			{
				char			buff[] = "????????";
				size_t const	n = traits_m_t::get_full_path_name("..", buff, 8);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\", buff);
			}

			{ for(size_t i = 9; i != 1000; ++i)
			{
				char			buff[1001];
				size_t const	n = traits_m_t::get_full_path_name("..", buff, i);

				XTESTS_TEST_INTEGER_EQUAL(3u, n);
				XTESTS_TEST_MULTIBYTE_STRING_EQUAL("C:\\", buff);
			}}
		}

		chdir(cwd);
	}
#else /* ? _WIN32 */
#endif /* _WIN32 */
}


static void test_1_13()
{
    glob_sequence_t files(".");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
#if 0
		XTESTS_TEST_FAIL("dot directory should be elided");
		return;
#else /* ? 0 */
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
#endif /* 0 */
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_14()
{
    glob_sequence_t files(".", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_15()
{
    glob_sequence_t files("..");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_16()
{
    glob_sequence_t files("..", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_17()
{
    glob_sequence_t files(".", glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(".", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_18()
{
    glob_sequence_t files(".", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(".", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_19()
{
    glob_sequence_t files("..", glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_20()
{
    glob_sequence_t files("..", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_21()
{
    glob_sequence_t files("./*.*", glob_sequence_t::files);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_22()
{
    glob_sequence_t directories("./*.*", glob_sequence_t::directories);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_23()
{
    glob_sequence_t files("./*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_24()
{
    glob_sequence_t directories("./*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_25()
{
    glob_sequence_t files("../*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_26()
{
    glob_sequence_t directories("../*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_27()
{
    glob_sequence_t files(".*");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));

		XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(".", *b);
		XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("..", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_28()
{
    glob_sequence_t files(".*", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_29()
{
    glob_sequence_t files(".*", glob_sequence_t::matchPeriod);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));

		XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(".", *b);
		XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL("..", *b);
    }}

    XTESTS_TEST_PASSED();
}

static void test_1_30()
{
    glob_sequence_t files(".*", glob_sequence_t::includeDots | glob_sequence_t::matchPeriod);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}


static void test_2_13()
{
    glob_sequence_t files(".", ".");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
#if 0
		XTESTS_TEST_FAIL("dot directory should be elided");
		return;
#else /* ? 0 */
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
#endif /* 0 */
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_14()
{
    glob_sequence_t files(".", ".", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_15()
{
    glob_sequence_t files(".", "..");

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_16()
{
    glob_sequence_t files(".", "..", glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_17()
{
    glob_sequence_t files(".", ".", glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_18()
{
    glob_sequence_t files(".", ".", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_19()
{
    glob_sequence_t files(".", "..", glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_20()
{
    glob_sequence_t files(".", "..", glob_sequence_t::absolutePath | glob_sequence_t::includeDots);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_21()
{
    glob_sequence_t files(".", "*.*", glob_sequence_t::files);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_22()
{
    glob_sequence_t directories(".", "*.*", glob_sequence_t::directories);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(!traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_23()
{
    glob_sequence_t files(".", "*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_24()
{
    glob_sequence_t directories(".", "*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_25()
{
    glob_sequence_t files("..", "*.*", glob_sequence_t::files | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}

static void test_2_26()
{
    glob_sequence_t directories("..", "*.*", glob_sequence_t::directories | glob_sequence_t::absolutePath);

    { for(glob_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
    {
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
        XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_path_absolute(stlsoft::c_str_ptr(*b)));
    }}

    XTESTS_TEST_PASSED();
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
