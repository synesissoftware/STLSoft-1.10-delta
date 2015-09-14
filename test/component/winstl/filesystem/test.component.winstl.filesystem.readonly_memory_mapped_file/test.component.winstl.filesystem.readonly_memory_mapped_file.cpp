/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.filesystem.readonly_memory_mapped_file.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.filesystem.readonly_memory_mapped_file project.
 *
 * Created:     30th August 2010
 * Updated:     30th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/filesystem/readonly_memory_mapped_file.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/synch/refcount_policies/refcount_policy_single_threaded.hpp>
#include <stlsoft/util/limit_traits.h>
#include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
#include <winstl/filesystem/file_creation_functions.h>
#include <winstl/filesystem/memory_map_functions.h>

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

	if(XTESTS_START_RUNNER("test.component.winstl.filesystem.readonly_memory_mapped_file", verbosity))
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

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{
	using winstl::ws_uintptr_t;

	typedef winstl::readonly_memory_mapped_file_base<stlsoft::refcount_policy_single_threaded>		ro_mmf_st_t;
	typedef winstl::readonly_memory_mapped_file_base<platformstl::refcount_policy_multi_threaded>	ro_mmf_mt_t;

static void test_1_0()
{
	if(0)
	{
		ro_mmf_st_t	instance("abc");

		STLSOFT_SUPPRESS_UNUSED(instance);
	}
	if(0)
	{
		ro_mmf_st_t	instance(L"abc");

		STLSOFT_SUPPRESS_UNUSED(instance);
	}

	XTESTS_TEST_PASSED();
}

static void test_1_1()
{
	if(0)
	{
		ro_mmf_mt_t	instance("abc");

		STLSOFT_SUPPRESS_UNUSED(instance);
	}
	if(0)
	{
		ro_mmf_mt_t	instance(L"abc");

		STLSOFT_SUPPRESS_UNUSED(instance);
	}

	XTESTS_TEST_PASSED();
}

static void test_1_2()
{
	// Map a non-zero sized file

	ro_mmf_st_t	mmf(s_arg0);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, mmf.memory());
	XTESTS_TEST_INTEGER_NOT_EQUAL(0u, mmf.size());
}

static void test_1_3()
{
	// Map a section of a non-zero sized file

	ro_mmf_st_t	mmf(s_arg0, 0, 1024);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, mmf.memory());
	XTESTS_TEST_INTEGER_EQUAL(1024u, mmf.size());
}

static void test_1_4()
{
	// Map an over-large section of a non-zero sized file

	ro_mmf_st_t	mmf1(s_arg0);

	ro_mmf_st_t	mmf2(s_arg0, 0, stlsoft::limit_traits<ro_mmf_st_t::size_type>::maximum());

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, mmf1.memory());
	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, mmf2.memory());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(mmf1.size(), mmf2.size()));

	XTESTS_TEST_INTEGER_EQUAL(0, ::memcmp(mmf1.memory(), mmf2.memory(), mmf1.size()));
}

static void test_1_5()
{
	// Map a zero-length file

	char const TEST_FILE_NAME[] = "test_1_5.DATAFILE";

	HANDLE h = winstl::file_create_always(TEST_FILE_NAME, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0);

	HANDLE h2 = winstl::file_create_always(TEST_FILE_NAME, GENERIC_READ, FILE_SHARE_READ, 0);

	if(INVALID_HANDLE_VALUE == h)
	{
	}
	else
	{
		stlsoft::scoped_handle<char const*> scoper1(TEST_FILE_NAME, ::DeleteFile);
#if 0
		stlsoft::scoped_handle<HANDLE> scoper2(h, ::CloseHandle, INVALID_HANDLE_VALUE);
#else /* ? 0 */
		::CloseHandle(h);
#endif /* 0 */

		ro_mmf_st_t	mmf1(TEST_FILE_NAME);

		XTESTS_TEST_POINTER_EQUAL(NULL, mmf1.memory());
		XTESTS_TEST_INTEGER_EQUAL(0u, mmf1.size());

		ro_mmf_st_t	mmf2(mmf1);

		XTESTS_TEST_POINTER_EQUAL(NULL, mmf2.memory());
		XTESTS_TEST_INTEGER_EQUAL(0u, mmf2.size());
	}
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
