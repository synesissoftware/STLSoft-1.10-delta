/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.comstl.string.BSTR_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.comstl.string.BSTR_functions project.
 *
 * Created:     31st May 2010
 * Updated:     31st May 2010
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

#include <comstl/string/BSTR_functions.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/dimensionof.h>
//#include <winstl/conversion/m2w.hpp>
#include <winstl/conversion/char_conversions.hpp>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_comstl_C_BSTR_create_w_1(void);
	static void test_comstl_C_BSTR_create_w_2(void);
	static void test_comstl_C_BSTR_create_a_1(void);
	static void test_comstl_C_BSTR_create_a_2(void);
	static void test_comstl_C_BSTR_create_len_w(void);
	static void test_comstl_C_BSTR_create_len_a(void);
	static void test_comstl_C_BSTR_compare(void);
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
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.comstl.string.BSTR_functions", verbosity))
	{
		XTESTS_RUN_CASE(test_comstl_C_BSTR_create_w_1);
		XTESTS_RUN_CASE(test_comstl_C_BSTR_create_w_2);
		XTESTS_RUN_CASE(test_comstl_C_BSTR_create_a_1);
		XTESTS_RUN_CASE(test_comstl_C_BSTR_create_a_2);
		XTESTS_RUN_CASE(test_comstl_C_BSTR_create_len_w);
		XTESTS_RUN_CASE(test_comstl_C_BSTR_create_len_a);
		XTESTS_RUN_CASE(test_comstl_C_BSTR_compare);
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
	using comstl::comstl_C_BSTR_compare;
	using comstl::comstl_C_BSTR_create_a;
	using comstl::comstl_C_BSTR_create_w;
	using comstl::comstl_C_BSTR_create_len_a;
	using comstl::comstl_C_BSTR_create_len_w;
	using comstl::comstl_C_BSTR_destroy;
	using comstl::comstl_C_BSTR_len;

	// NOTE: These are not true unit-tests, since we could be out of memory
	// to allocate the BSTR. In practice, however, this'll never happen
	// (unless we drive the system in/close to out-of-memory conditions).

static void test_comstl_C_BSTR_create_w_1()
{
	{
		BSTR s = comstl_C_BSTR_create_w(NULL);

		XTESTS_TEST_POINTER_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(0u, ::SysStringLen(s));
		XTESTS_TEST_INTEGER_EQUAL(::SysStringLen(s), comstl_C_BSTR_len(s));
	}

	{
		BSTR s = comstl_C_BSTR_create_w(L"");

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(0u, ::SysStringLen(s));
		XTESTS_TEST_INTEGER_EQUAL(::SysStringLen(s), comstl_C_BSTR_len(s));

		comstl_C_BSTR_destroy(s);
	}
}

static void test_comstl_C_BSTR_create_w_2()
{
	wchar_t const* const strings[] =
	{
			L""
		,	L"a"
		,	L"abc"
		,	L"abcdefghijklmnopqrstuvwxyz"
		,	L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	};

	{ for(size_t i = 0; i != dimensionof(strings); ++i)
	{
		BSTR const s = comstl_C_BSTR_create_w(strings[i]);

		XTESTS_TEST_WIDE_STRING_EQUAL(strings[i], s);
		XTESTS_TEST_INTEGER_EQUAL(::wcslen(strings[i]), ::SysStringLen(s));
		XTESTS_TEST_INTEGER_EQUAL(::SysStringLen(s), comstl_C_BSTR_len(s));

		comstl_C_BSTR_destroy(s);
	}}
}

static void test_comstl_C_BSTR_create_a_1()
{
	{
		BSTR s = comstl_C_BSTR_create_a(NULL);

		XTESTS_TEST_POINTER_EQUAL(NULL, s);
	}

	{
		BSTR s = comstl_C_BSTR_create_a("");

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(0u, ::SysStringLen(s));

		comstl_C_BSTR_destroy(s);
	}
}

static void test_comstl_C_BSTR_create_a_2()
{
	char const* const strings[] =
	{
			""
		,	"a"
		,	"abc"
		,	"abcdefghijklmnopqrstuvwxyz"
		,	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	};

	{ for(size_t i = 0; i != dimensionof(strings); ++i)
	{
		BSTR const s = comstl_C_BSTR_create_a(strings[i]);

		XTESTS_TEST_WIDE_STRING_EQUAL(winstl::m2w(strings[i]), s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(strings[i]), ::SysStringLen(s));
		XTESTS_TEST_INTEGER_EQUAL(::SysStringLen(s), comstl_C_BSTR_len(s));

		comstl_C_BSTR_destroy(s);
	}}
}

static void test_comstl_C_BSTR_create_len_w(void)
{
	wchar_t const alphabet[] = L"abcdefghijklmnopqrstuvwxyz";

	{ for(size_t i = 0; i != dimensionof(alphabet); ++i)
	{
		BSTR const s = comstl_C_BSTR_create_len_w(alphabet, i);

		XTESTS_TEST_WIDE_STRING_EQUAL_N(alphabet, s, int(i));
		XTESTS_TEST_INTEGER_EQUAL(i, ::SysStringLen(s));
		XTESTS_TEST_INTEGER_EQUAL(::SysStringLen(s), comstl_C_BSTR_len(s));

		comstl_C_BSTR_destroy(s);
	}}
}

static void test_comstl_C_BSTR_create_len_a(void)
{
	char const alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	{ for(size_t i = 0; i != dimensionof(alphabet); ++i)
	{
		BSTR const s = comstl_C_BSTR_create_len_a(alphabet, i);

		XTESTS_TEST_WIDE_STRING_EQUAL_N(winstl::m2w(alphabet), s, int(i));
		XTESTS_TEST_INTEGER_EQUAL(i, ::SysStringLen(s));
		XTESTS_TEST_INTEGER_EQUAL(::SysStringLen(s), comstl_C_BSTR_len(s));

		comstl_C_BSTR_destroy(s);
	}}
}

static void test_comstl_C_BSTR_compare()
{
	BSTR	abc	=	::SysAllocString(L"abc");
	BSTR	def	=	::SysAllocString(L"def");

	XTESTS_TEST_INTEGER_EQUAL(0, comstl_C_BSTR_compare(NULL, NULL));
	XTESTS_TEST_INTEGER_EQUAL(0, comstl_C_BSTR_compare(abc, abc));
	XTESTS_TEST_INTEGER_NOT_EQUAL(0, comstl_C_BSTR_compare(abc, def));
	XTESTS_TEST_INTEGER_NOT_EQUAL(0, comstl_C_BSTR_compare(def, abc));

	XTESTS_TEST_INTEGER_LESS(0, comstl_C_BSTR_compare(NULL, abc));
	XTESTS_TEST_INTEGER_GREATER(0, comstl_C_BSTR_compare(abc, NULL));
	XTESTS_TEST_INTEGER_LESS(0, comstl_C_BSTR_compare(NULL, def));
	XTESTS_TEST_INTEGER_GREATER(0, comstl_C_BSTR_compare(def, NULL));
	XTESTS_TEST_INTEGER_LESS(0, comstl_C_BSTR_compare(abc, def));
	XTESTS_TEST_INTEGER_GREATER(0, comstl_C_BSTR_compare(def, abc));

	comstl_C_BSTR_destroy(abc);
	comstl_C_BSTR_destroy(def);
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
