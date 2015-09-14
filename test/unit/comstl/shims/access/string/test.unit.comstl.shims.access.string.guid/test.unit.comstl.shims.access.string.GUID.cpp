/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.comstl.shims.access.string.GUID.cpp
 *
 * Purpose:     Implementation file for the test.unit.comstl.shims.access.string.GUID project.
 *
 * Created:     15th October 2008
 * Updated:     8th June 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <comstl/shims/access/string/GUID.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Features
 */

#define FIXED_SEED		(101)

#ifdef UNICODE
# define XTESTS_TEST_T_STRING_EQUAL_			XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? UNICODE */
# define XTESTS_TEST_T_STRING_EQUAL_			XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* UNICODE */

typedef std::string								string_t;
typedef std::wstring							wstring_t;
#ifdef UNICODE
typedef std::wstring							tstring_t;
#else /* ? UNICODE */
typedef std::string								tstring_t;
#endif /* UNICODE */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_verify_width(void);
	static void test_calls_possible(void);
	static void test_c_str_data_GUID_NULL(void);
	static void test_c_str_len_GUID_NULL(void);
	static void test_c_str_ptr_GUID_NULL(void);
	static void test_c_str_ptr_null_GUID_NULL(void);
	static void test_c_str_len_RANDOM(void);
	static void test_c_str_data_vs_c_str_ptr_RANDOM(void);
	static void test_c_str_ptr_null_vs_c_str_ptr_RANDOM(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.comstl.shims.access.string.GUID", verbosity))
	{
		XTESTS_RUN_CASE(test_verify_width);
		XTESTS_RUN_CASE(test_calls_possible);
		XTESTS_RUN_CASE(test_c_str_data_GUID_NULL);
		XTESTS_RUN_CASE(test_c_str_len_GUID_NULL);
		XTESTS_RUN_CASE(test_c_str_ptr_GUID_NULL);
		XTESTS_RUN_CASE(test_c_str_ptr_null_GUID_NULL);
		XTESTS_RUN_CASE(test_c_str_len_RANDOM);
		XTESTS_RUN_CASE(test_c_str_data_vs_c_str_ptr_RANDOM);
		XTESTS_RUN_CASE(test_c_str_ptr_null_vs_c_str_ptr_RANDOM);

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
	}

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

namespace
{
	// Multibyte

	string_t invoke_c_str_data_a_(char const* s)
	{
		if(NULL == s)
		{
			return string_t();
		}
		else
		{
			return string_t(s, 38);
		}
	}
	string_t invoke_c_str_data_a(GUID const& guid)
	{
		return invoke_c_str_data_a_(::stlsoft::c_str_data_a(guid));
	}


	// Wide

	wstring_t invoke_c_str_data_w_(wchar_t const* s)
	{
		if(NULL == s)
		{
			return wstring_t();
		}
		else
		{
			return wstring_t(s, 38);
		}
	}
	wstring_t invoke_c_str_data_w(GUID const& guid)
	{
		return invoke_c_str_data_w_(::stlsoft::c_str_data_w(guid));
	}


	// Ambient

	tstring_t invoke_c_str_data_(TCHAR const* s)
	{
		if(NULL == s)
		{
			return tstring_t();
		}
		else
		{
			return tstring_t(s, 38);
		}
	}
	tstring_t invoke_c_str_data(GUID const& guid)
	{
		return invoke_c_str_data_(::stlsoft::c_str_data(guid));
	}


} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

static void test_verify_width()
{
	XTESTS_TEST_INTEGER_EQUAL(38u, comstl::COMSTL_CCH_GUID);
}

static void test_calls_possible()
{
	stlsoft::c_str_data_a(GUID_NULL);
	stlsoft::c_str_data_w(GUID_NULL);
	stlsoft::c_str_data(GUID_NULL);

	stlsoft::c_str_len_a(GUID_NULL);
	stlsoft::c_str_len_w(GUID_NULL);
	stlsoft::c_str_len(GUID_NULL);

	stlsoft::c_str_ptr_a(GUID_NULL);
	stlsoft::c_str_ptr_w(GUID_NULL);
	stlsoft::c_str_ptr(GUID_NULL);

	stlsoft::c_str_ptr_null_a(GUID_NULL);
	stlsoft::c_str_ptr_null_w(GUID_NULL);
	stlsoft::c_str_ptr_null(GUID_NULL);

	XTESTS_TEST_PASSED();
}

static void test_c_str_data_GUID_NULL()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("{00000000-0000-0000-0000-000000000000}", invoke_c_str_data_a(GUID_NULL));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"{00000000-0000-0000-0000-000000000000}", invoke_c_str_data_w(GUID_NULL));
	XTESTS_TEST_T_STRING_EQUAL_(TEXT("{00000000-0000-0000-0000-000000000000}"), invoke_c_str_data(GUID_NULL));
}

static void test_c_str_len_GUID_NULL()
{
	XTESTS_TEST_INTEGER_EQUAL(38u, stlsoft::c_str_len_a(GUID_NULL));
	XTESTS_TEST_INTEGER_EQUAL(38u, stlsoft::c_str_len_w(GUID_NULL));
	XTESTS_TEST_INTEGER_EQUAL(38u, stlsoft::c_str_len(GUID_NULL));
}

static void test_c_str_ptr_GUID_NULL()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("{00000000-0000-0000-0000-000000000000}", stlsoft::c_str_ptr_a(GUID_NULL));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"{00000000-0000-0000-0000-000000000000}", stlsoft::c_str_ptr_w(GUID_NULL));
	XTESTS_TEST_T_STRING_EQUAL_(TEXT("{00000000-0000-0000-0000-000000000000}"), stlsoft::c_str_ptr(GUID_NULL));
}

static void test_c_str_ptr_null_GUID_NULL()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("{00000000-0000-0000-0000-000000000000}", stlsoft::c_str_ptr_null_a(GUID_NULL));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"{00000000-0000-0000-0000-000000000000}", stlsoft::c_str_ptr_null_w(GUID_NULL));
	XTESTS_TEST_T_STRING_EQUAL_(TEXT("{00000000-0000-0000-0000-000000000000}"), stlsoft::c_str_ptr_null(GUID_NULL));
}

static void test_c_str_len_RANDOM()
{
#ifdef FIXED_SEED
	::srand(FIXED_SEED);
#else /* ? FIXED_SEED */
	union
	{
		void*	p;
		int		i;
	} u;
	u.p = &u;

	::srand(u.i);
#endif /* FIXED_SEED */

	{ for(size_t i = 0; i != 1000; ++i)
	{
		GUID	guid;

		guid.Data1		=	static_cast<DWORD>(::rand());
		guid.Data2		=	static_cast<WORD>(::rand());
		guid.Data3		=	static_cast<WORD>(::rand());
		{ for(size_t j = 0; j != 8; ++j)
		{
			guid.Data4[0]	=	static_cast<BYTE>(j + i);
		}}

		XTESTS_TEST_INTEGER_EQUAL(38u, stlsoft::c_str_len_a(guid));
		XTESTS_TEST_INTEGER_EQUAL(38u, stlsoft::c_str_len_w(guid));
		XTESTS_TEST_INTEGER_EQUAL(38u, stlsoft::c_str_len(guid));
	}}
}

static void test_c_str_data_vs_c_str_ptr_RANDOM()
{
#ifdef FIXED_SEED
	::srand(FIXED_SEED);
#else /* ? FIXED_SEED */
	union
	{
		void*	p;
		int		i;
	} u;
	u.p = &u;

	::srand(u.i);
#endif /* FIXED_SEED */

	{ for(size_t i = 0; i != 1000; ++i)
	{
		GUID	guid;

		guid.Data1		=	static_cast<DWORD>(::rand());
		guid.Data2		=	static_cast<WORD>(::rand());
		guid.Data3		=	static_cast<WORD>(::rand());
		{ for(size_t j = 0; j != 8; ++j)
		{
			guid.Data4[0]	=	static_cast<BYTE>(j + i);
		}}

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(stlsoft::c_str_ptr_a(guid), invoke_c_str_data_a(guid));
		XTESTS_TEST_WIDE_STRING_EQUAL(stlsoft::c_str_ptr_w(guid), invoke_c_str_data_w(guid));
		XTESTS_TEST_T_STRING_EQUAL_(stlsoft::c_str_ptr(guid), invoke_c_str_data(guid));
	}}
}

static void test_c_str_ptr_null_vs_c_str_ptr_RANDOM()
{
#ifdef FIXED_SEED
	::srand(FIXED_SEED);
#else /* ? FIXED_SEED */
	union
	{
		void*	p;
		int		i;
	} u;
	u.p = &u;

	::srand(u.i);
#endif /* FIXED_SEED */

	{ for(size_t i = 0; i != 1000; ++i)
	{
		GUID	guid;

		guid.Data1		=	static_cast<DWORD>(::rand());
		guid.Data2		=	static_cast<WORD>(::rand());
		guid.Data3		=	static_cast<WORD>(::rand());
		{ for(size_t j = 0; j != 8; ++j)
		{
			guid.Data4[0]	=	static_cast<BYTE>(j + i);
		}}

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(stlsoft::c_str_ptr_a(guid), stlsoft::c_str_ptr_null_a(guid));
		XTESTS_TEST_WIDE_STRING_EQUAL(stlsoft::c_str_ptr_w(guid), stlsoft::c_str_ptr_null_w(guid));
		XTESTS_TEST_T_STRING_EQUAL_(stlsoft::c_str_ptr(guid), stlsoft::c_str_ptr_null(guid));
	}}
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
