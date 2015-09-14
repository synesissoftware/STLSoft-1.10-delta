/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.unixstl.filesystem.file_types.cpp
 *
 * Purpose:     Implementation file for the test.component.unixstl.filesystem.file_types project.
 *
 * Created:     18th May 2012
 * Updated:     4th June 2012
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2012, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <unixstl/filesystem/filesystem_traits.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <unixstl/filesystem/path.hpp>
#include <unixstl/system/temporary_directory.hpp>
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

	static int setup(void* param);
	static int teardown(void* param);
	static char* setupParam = NULL;

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Helper types
 */

class directory_contents
{
public: // Member Types
	typedef directory_contents	class_type;

public: // Construction
	directory_contents(char const* path);
	~directory_contents() stlsoft_throw_0();

public: // Operations
	class_type&	create_directory(char const* path);
	class_type&	create_file(char const* path);
	class_type&	create_soft_link(char const* sourcePath, char const* linkPath);

	void cleanup() stlsoft_throw_0();

private: // Implementation

private: // Fields
};


directory_contents::directory_contents(
	char const* path
)
{}

directory_contents::~directory_contents() stlsoft_throw_0()
{}

directory_contents::class_type&
directory_contents::create_directory(
	char const* path
)
{

	return *this;
}

directory_contents::class_type&
directory_contents::create_file(
	char const* path
)
{

	return *this;
}

directory_contents::class_type&
directory_contents::create_soft_link(
	char const* sourcePath
, char const* linkPath
)
{

	return *this;
}

void
directory_contents::cleanup()
{

}


/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	unixstl::temporary_directory tempdir;

	setupParam = const_cast<char*>(tempdir.c_str());

	using unixstl::path_a;

	path_a const				base(tempdir.c_str());

	directory_contents	dc(base.c_str());

	dc
		.create_directory("dir0")
		.create_directory("dir1")
		.create_file("file0")
		.create_file("file1")
		.create_soft_link("file0", "link0")
		;

	if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.unixstl.filesystem.file_types", verbosity, setup, teardown, setupParam))
	{
		XTESTS_RUN_CASE(test_1_0);
		XTESTS_RUN_CASE(test_1_1);
		XTESTS_RUN_CASE(test_1_2);
		XTESTS_RUN_CASE(test_1_3);
		XTESTS_RUN_CASE(test_1_4);
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

	dc.cleanup();

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

static int setup(void* param)
{
	((void)param); /* TODO: Use the parameter, if you need to */

	return 0; /* Change to !0 to fail initialisation */
}

static int teardown(void* param)
{
	((void)param); /* TODO: Use the parameter, if you need to */

	return 0; /* Currently ignored by xTests */
}

static void test_1_0()
{

}

static void test_1_1()
{
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
