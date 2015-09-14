/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.filesystem.directory.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.filesystem.directory project.
 *
 * Created:     1st May 2014
 * Updated:     1st May 2014
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

#include <winstl/filesystem/directory.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Windows header files */
#include <tchar.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_types_exist(void);
    static void test_constructor_exists(void);
    static void test_can_open_root(void);
    static void test_cannot_open_non_existent_root(void);
    static void test_can_open_current_directory(void);
    static void test_1_5(void);
    static void test_1_6(void);
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
 * Statics
 */

namespace
{

    static char s_arg0[1024 + 1];

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    ::strcpy(s_arg0, argv[0]);

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.winstl.filesystem.directory", verbosity))
    {
        XTESTS_RUN_CASE(test_types_exist);
        XTESTS_RUN_CASE(test_constructor_exists);
        XTESTS_RUN_CASE(test_can_open_root);
        XTESTS_RUN_CASE(test_cannot_open_non_existent_root);
        XTESTS_RUN_CASE(test_can_open_current_directory);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
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

static void test_types_exist()
{
	typeid(winstl::directory_a);
	typeid(winstl::directory_w);
	typeid(winstl::directory_t);
	typeid(winstl::directory);

    XTESTS_TEST_PASSED();
}

static void test_constructor_exists()
{
    if(0)
    {
		winstl::directory_a		instance(".");

        STLSOFT_SUPPRESS_UNUSED(instance);
    }
    if(0)
    {
		winstl::directory_w		instance(L".");

        STLSOFT_SUPPRESS_UNUSED(instance);
    }
	if(0)
	{
		winstl::directory_t		instance(_T("."));

        STLSOFT_SUPPRESS_UNUSED(instance);
	}
	if(0)
	{
		winstl::directory		instance(_T("."));

        STLSOFT_SUPPRESS_UNUSED(instance);
	}

    XTESTS_TEST_PASSED();
}

static void test_can_open_root()
{
	winstl::directory_a		instance("/");

    XTESTS_TEST_PASSED();
}

static void test_cannot_open_non_existent_root()
{
	{ for(char ch = 'A'; ch != 'Z' + 1; ++ch)
	{
		char root[4] = { ch, ':', '\\', '\0' };

		if(DRIVE_NO_ROOT_DIR == ::GetDriveType(root))
		{
			try
			{
				winstl::directory_a instance(root);

				XTESTS_TEST_FAIL(std::string("should not get here: '") + root + "' does not exist");
			}
			catch(std::exception& /* x */)
			{
				XTESTS_TEST_PASSED();
			}
		}
	}}
}

static void test_can_open_current_directory()
{
	winstl::directory_a		dir(".");

	XTESTS_TEST_PASSED();
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
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
