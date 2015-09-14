/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.platformstl.filesystem.readdir_sequence.cpp
 *
 * Purpose:     Implementation file for the test.component.platformstl.filesystem.readdir_sequence project.
 *
 * Created:     24th January 2009
 * Updated:     24th February 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <platformstl/filesystem/readdir_sequence.hpp>

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

	if(XTESTS_START_RUNNER("test.component.platformstl.filesystem.readdir_sequence", verbosity))
	{
		XTESTS_RUN_CASE(test_1_17);
		XTESTS_RUN_CASE(test_1_18);
		XTESTS_RUN_CASE(test_1_19);
		XTESTS_RUN_CASE(test_1_20);
		XTESTS_RUN_CASE(test_1_21);
		XTESTS_RUN_CASE(test_1_22);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*platformstl/*/readdir_sequence.hpp", NULL);
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

	typedef platformstl::readdir_sequence				readdir_sequence_t;

	typedef platformstl::filesystem_traits<char>		traits_m_t;

static void test_1_17()
{
	readdir_sequence_t	files(".");

	{ for(readdir_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_18()
{
	readdir_sequence_t	files(".", readdir_sequence_t::absolutePath);

	{ for(readdir_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_19()
{
	readdir_sequence_t	files(".", readdir_sequence_t::files);

	{ for(readdir_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_20()
{
	readdir_sequence_t	directories(".", readdir_sequence_t::directories);

	{ for(readdir_sequence_t::const_iterator b = directories.begin(); b != directories.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_directory(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_21()
{
	readdir_sequence_t	files(".", readdir_sequence_t::files);

	{ for(readdir_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}

static void test_1_22()
{
	readdir_sequence_t	files(".", readdir_sequence_t::files);

	{ for(readdir_sequence_t::const_iterator b = files.begin(); b != files.end(); ++b)
	{
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::file_exists(stlsoft::c_str_ptr(*b)));
		XTESTS_TEST_BOOLEAN_TRUE(traits_m_t::is_file(stlsoft::c_str_ptr(*b)));
	}}

	XTESTS_TEST_PASSED();
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
