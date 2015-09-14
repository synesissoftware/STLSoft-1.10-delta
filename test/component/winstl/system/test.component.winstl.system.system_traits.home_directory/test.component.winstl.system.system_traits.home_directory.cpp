/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.system.system_traits.home_directory.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.system.system_traits.home_directory project.
 *
 * Created:     29th January 2013
 * Updated:     29th January 2013
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2013, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/system/system_traits.hpp>

#include <winstl/system/environment_variable.hpp>

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

	static void test_1_0(void);
	static void test_1_1(void);
	static void test_1_2(void);
	static void test_1_3(void);
	static void test_1_4(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.component.winstl.system.system_traits.home_directory", verbosity))
	{
		XTESTS_RUN_CASE(test_1_0);
		XTESTS_RUN_CASE(test_1_1);
		XTESTS_RUN_CASE(test_1_2);
		XTESTS_RUN_CASE(test_1_3);
		XTESTS_RUN_CASE(test_1_4);

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

static void test_1_0()
{
	size_t const required = winstl::system_traits<char>::get_home_directory(NULL, 0);

	if(0 != required)
	{
		{ for(size_t i = 1; i != required; ++i)
		{
			stlsoft::auto_buffer<char>	buff(i);

			size_t const cch = winstl::system_traits<char>::get_home_directory(&buff[0], buff.size());

			XTESTS_TEST_INTEGER_EQUAL(required, cch);
		}}
	}

	stlsoft::auto_buffer<char>	buff(required);
	size_t const				actual = winstl::system_traits<char>::get_home_directory(&buff[0], buff.size());

	XTESTS_TEST_INTEGER_EQUAL(required - 1, actual);
}

static void test_1_1()
{
	winstl::environment_variable_a	HOMEDRIVE("HOMEDRIVE");
	winstl::environment_variable_a	HOMEPATH("HOMEPATH");

	stlsoft::auto_buffer<char>		buff(1 + HOMEDRIVE.size() + HOMEPATH.size());
	size_t const					cch = winstl::system_traits<char>::get_home_directory(&buff[0], buff.size());

	XTESTS_TEST_INTEGER_EQUAL(HOMEDRIVE.size() + HOMEPATH.size(), cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL(std::string(HOMEDRIVE) + std::string(HOMEPATH), buff.data());
}

static void test_1_2()
{
}

static void test_1_3()
{
}

static void test_1_4()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
