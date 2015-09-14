/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.limits.integral_limits.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.limits.integral_limits project.
 *
 * Created:     10th July 2012
 * Updated:     10th July 2012
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
 * Compiler compatibility
 */

#ifdef _MSC_VER
# pragma warning(disable : 4702)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/limits/integral_limits.hpp>

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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.limits.integral_limits", verbosity))
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
	using stlsoft::ss_sint8_t;
	using stlsoft::ss_sint16_t;
	using stlsoft::ss_sint32_t;
	using stlsoft::ss_sint64_t;

	using stlsoft::ss_uint8_t;
	using stlsoft::ss_uint16_t;
	using stlsoft::ss_uint32_t;
	using stlsoft::ss_uint64_t;


static void test_1_0()
{
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT8_SUFFIX(-128), stlsoft::integral_limits<ss_sint8_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT8_SUFFIX(+127), stlsoft::integral_limits<ss_sint8_t>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT8_SUFFIX(0),    stlsoft::integral_limits<ss_uint8_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT8_SUFFIX(+255), stlsoft::integral_limits<ss_uint8_t>::maximum());
}

static void test_1_1()
{
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT16_SUFFIX(-32768), stlsoft::integral_limits<ss_sint16_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT16_SUFFIX(+32767), stlsoft::integral_limits<ss_sint16_t>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT16_SUFFIX(0),      stlsoft::integral_limits<ss_uint16_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT16_SUFFIX(+65535), stlsoft::integral_limits<ss_uint16_t>::maximum());
}

static void test_1_2()
{
	XTESTS_TEST_INTEGER_EQUAL((- STLSOFT_GEN_SINT32_SUFFIX(2147483647) - 1), stlsoft::integral_limits<ss_sint32_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT32_SUFFIX(0x7fffffff), stlsoft::integral_limits<ss_sint32_t>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT32_SUFFIX(0),           stlsoft::integral_limits<ss_uint32_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT32_SUFFIX(+4294967295), stlsoft::integral_limits<ss_uint32_t>::maximum());
}

static void test_1_3()
{
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL((-STLSOFT_GEN_SINT64_SUFFIX(9223372036854775807) - 1), stlsoft::integral_limits<ss_sint64_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT64_SUFFIX(0x7fffffffffffffff),  stlsoft::integral_limits<ss_sint64_t>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT64_SUFFIX(0),                     stlsoft::integral_limits<ss_uint64_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT64_SUFFIX(+18446744073709551615), stlsoft::integral_limits<ss_uint64_t>::maximum());
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
}

static void test_1_4()
{
}

static void test_1_5()
{
	XTESTS_TEST_INTEGER_EQUAL(SCHAR_MIN, stlsoft::integral_limits<signed char>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(SCHAR_MAX, stlsoft::integral_limits<signed char>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::integral_limits<unsigned char>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(UCHAR_MAX, stlsoft::integral_limits<unsigned char>::maximum());
}

static void test_1_6()
{
	XTESTS_TEST_INTEGER_EQUAL(SHRT_MIN,  stlsoft::integral_limits<signed short>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(SHRT_MAX,  stlsoft::integral_limits<signed short>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::integral_limits<unsigned short>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(USHRT_MAX, stlsoft::integral_limits<unsigned short>::maximum());
}

static void test_1_7()
{
	XTESTS_TEST_INTEGER_EQUAL(INT_MIN,  stlsoft::integral_limits<signed int>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(INT_MAX,  stlsoft::integral_limits<signed int>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(0u,       stlsoft::integral_limits<unsigned int>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(UINT_MAX, stlsoft::integral_limits<unsigned int>::maximum());
}

static void test_1_8()
{
	XTESTS_TEST_INTEGER_EQUAL(LONG_MIN,  stlsoft::integral_limits<signed long>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(LONG_MAX,  stlsoft::integral_limits<signed long>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::integral_limits<unsigned long>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(ULONG_MAX, stlsoft::integral_limits<unsigned long>::maximum());
}

static void test_1_9()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT

# ifdef LLONG_MIN
	XTESTS_TEST_INTEGER_EQUAL(LLONG_MIN,  stlsoft::integral_limits<signed long long>::minimum());
# endif
# ifdef LLONG_MAX
	XTESTS_TEST_INTEGER_EQUAL(LLONG_MAX,  stlsoft::integral_limits<signed long long>::maximum());
# endif

	XTESTS_TEST_INTEGER_EQUAL(0,          stlsoft::integral_limits<unsigned long long>::minimum());
# ifdef ULLONG_MAX
	XTESTS_TEST_INTEGER_EQUAL(ULLONG_MAX, stlsoft::integral_limits<unsigned long long>::maximum());
# endif

#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
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
