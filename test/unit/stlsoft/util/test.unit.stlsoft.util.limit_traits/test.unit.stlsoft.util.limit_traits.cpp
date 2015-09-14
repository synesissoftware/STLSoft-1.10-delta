/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.util.limit_traits.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.util.limit_traits project.
 *
 * Created:     11th July 2012
 * Updated:     11th July 2012
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

#include <stlsoft/util/limit_traits.h>

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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.util.limit_traits", verbosity))
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

static void test_1_0()
{
}

static void test_1_1()
{
	XTESTS_TEST_INTEGER_EQUAL(SCHAR_MIN, stlsoft::limit_traits<signed char>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(SCHAR_MAX, stlsoft::limit_traits<signed char>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(SCHAR_MIN, stlsoft::limit_traits<signed char>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(SCHAR_MAX, stlsoft::limit_traits<signed char>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_2()
{
	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::limit_traits<unsigned char>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(UCHAR_MAX, stlsoft::limit_traits<unsigned char>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::limit_traits<unsigned char>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(UCHAR_MAX, stlsoft::limit_traits<unsigned char>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_3()
{
	XTESTS_TEST_INTEGER_EQUAL(SHRT_MIN, stlsoft::limit_traits<signed short>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(SHRT_MAX, stlsoft::limit_traits<signed short>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(SHRT_MIN, stlsoft::limit_traits<signed short>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(SHRT_MAX, stlsoft::limit_traits<signed short>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_4()
{
	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::limit_traits<unsigned short>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(USHRT_MAX, stlsoft::limit_traits<unsigned short>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::limit_traits<unsigned short>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(USHRT_MAX, stlsoft::limit_traits<unsigned short>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_5()
{
	XTESTS_TEST_INTEGER_EQUAL(INT_MIN, stlsoft::limit_traits<signed int>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(INT_MAX, stlsoft::limit_traits<signed int>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(INT_MIN, stlsoft::limit_traits<signed int>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(INT_MAX, stlsoft::limit_traits<signed int>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_6()
{
	XTESTS_TEST_INTEGER_EQUAL(0u,       stlsoft::limit_traits<unsigned int>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(UINT_MAX, stlsoft::limit_traits<unsigned int>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(0u,       stlsoft::limit_traits<unsigned int>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(UINT_MAX, stlsoft::limit_traits<unsigned int>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_7()
{
	XTESTS_TEST_INTEGER_EQUAL(LONG_MIN, stlsoft::limit_traits<signed long>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(LONG_MAX, stlsoft::limit_traits<signed long>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(LONG_MIN, stlsoft::limit_traits<signed long>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(LONG_MAX, stlsoft::limit_traits<signed long>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_8()
{
	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::limit_traits<unsigned long>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(ULONG_MAX, stlsoft::limit_traits<unsigned long>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(0u,        stlsoft::limit_traits<unsigned long>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(ULONG_MAX, stlsoft::limit_traits<unsigned long>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_9()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT

# ifdef LLONG_MIN
	XTESTS_TEST_INTEGER_EQUAL(LLONG_MIN,  stlsoft::limit_traits<signed long long>::minimum());
# endif
# ifdef LLONG_MAX
	XTESTS_TEST_INTEGER_EQUAL(LLONG_MAX,  stlsoft::limit_traits<signed long long>::maximum());
# endif

# ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
#  ifdef LLONG_MIN
	XTESTS_TEST_INTEGER_EQUAL(LLONG_MIN,  stlsoft::limit_traits<signed long long>::minimum_value);
#  endif
#  ifdef LLONG_MAX
	XTESTS_TEST_INTEGER_EQUAL(LLONG_MAX,  stlsoft::limit_traits<signed long long>::maximum_value);
#  endif
# endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */

#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_1_10()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT

	XTESTS_TEST_INTEGER_EQUAL(0,          stlsoft::limit_traits<unsigned long long>::minimum());
# ifdef ULLONG_MAX
	XTESTS_TEST_INTEGER_EQUAL(ULLONG_MAX, stlsoft::limit_traits<unsigned long long>::maximum());
# endif

# ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(0,          stlsoft::limit_traits<unsigned long long>::minimum_value);
#  ifdef ULLONG_MAX
	XTESTS_TEST_INTEGER_EQUAL(ULLONG_MAX, stlsoft::limit_traits<unsigned long long>::maximum_value);
#  endif
# endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */

#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}


static void test_1_11()
{
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT8_SUFFIX(-128), stlsoft::limit_traits<stlsoft::ss_sint8_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT8_SUFFIX(+127), stlsoft::limit_traits<stlsoft::ss_sint8_t>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT8_SUFFIX(-128), stlsoft::limit_traits<stlsoft::ss_sint8_t>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT8_SUFFIX(+127), stlsoft::limit_traits<stlsoft::ss_sint8_t>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_12()
{
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT8_SUFFIX(0)   , stlsoft::limit_traits<stlsoft::ss_uint8_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT8_SUFFIX(+255), stlsoft::limit_traits<stlsoft::ss_uint8_t>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT8_SUFFIX(0)   , stlsoft::limit_traits<stlsoft::ss_uint8_t>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT8_SUFFIX(+255), stlsoft::limit_traits<stlsoft::ss_uint8_t>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_13()
{
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT16_SUFFIX(-32768), stlsoft::limit_traits<stlsoft::ss_sint16_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT16_SUFFIX(+32767), stlsoft::limit_traits<stlsoft::ss_sint16_t>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT16_SUFFIX(-32768), stlsoft::limit_traits<stlsoft::ss_sint16_t>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT16_SUFFIX(+32767), stlsoft::limit_traits<stlsoft::ss_sint16_t>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_14()
{
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT16_SUFFIX(0)     , stlsoft::limit_traits<stlsoft::ss_uint16_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT16_SUFFIX(+65535), stlsoft::limit_traits<stlsoft::ss_uint16_t>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT16_SUFFIX(0)     , stlsoft::limit_traits<stlsoft::ss_uint16_t>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT16_SUFFIX(+65535), stlsoft::limit_traits<stlsoft::ss_uint16_t>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_15()
{
	XTESTS_TEST_INTEGER_EQUAL((- STLSOFT_GEN_SINT32_SUFFIX(2147483647) - 1), stlsoft::limit_traits<stlsoft::ss_sint32_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT32_SUFFIX(0x7fffffff)        , stlsoft::limit_traits<stlsoft::ss_sint32_t>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL((- STLSOFT_GEN_SINT32_SUFFIX(2147483647) - 1), stlsoft::limit_traits<stlsoft::ss_sint32_t>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT32_SUFFIX(0x7fffffff)        , stlsoft::limit_traits<stlsoft::ss_sint32_t>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_16()
{
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT32_SUFFIX(0)          , stlsoft::limit_traits<stlsoft::ss_uint32_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT32_SUFFIX(+4294967295), stlsoft::limit_traits<stlsoft::ss_uint32_t>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT32_SUFFIX(0)          , stlsoft::limit_traits<stlsoft::ss_uint32_t>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT32_SUFFIX(+4294967295), stlsoft::limit_traits<stlsoft::ss_uint32_t>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_17()
{
	XTESTS_TEST_INTEGER_EQUAL((-STLSOFT_GEN_SINT64_SUFFIX(9223372036854775807) - 1), stlsoft::limit_traits<stlsoft::ss_sint64_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT64_SUFFIX(0x7fffffffffffffff)        , stlsoft::limit_traits<stlsoft::ss_sint64_t>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL((-STLSOFT_GEN_SINT64_SUFFIX(9223372036854775807) - 1), stlsoft::limit_traits<stlsoft::ss_sint64_t>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_SINT64_SUFFIX(0x7fffffffffffffff)        , stlsoft::limit_traits<stlsoft::ss_sint64_t>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_18()
{
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT64_SUFFIX(0)                    , stlsoft::limit_traits<stlsoft::ss_uint64_t>::minimum());
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT64_SUFFIX(+18446744073709551615), stlsoft::limit_traits<stlsoft::ss_uint64_t>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT64_SUFFIX(0)                    , stlsoft::limit_traits<stlsoft::ss_uint64_t>::minimum_value);
	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_GEN_UINT64_SUFFIX(+18446744073709551615), stlsoft::limit_traits<stlsoft::ss_uint64_t>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

static void test_1_19()
{
	XTESTS_TEST_BOOLEAN_FALSE(stlsoft::limit_traits<bool>::minimum());
	XTESTS_TEST_BOOLEAN_TRUE(stlsoft::limit_traits<bool>::maximum());

#ifdef STLSOFT_CF_MEMBER_CONSTANT_SUPPORT
	XTESTS_TEST_BOOLEAN_FALSE(stlsoft::limit_traits<bool>::minimum_value);
	XTESTS_TEST_BOOLEAN_TRUE(stlsoft::limit_traits<bool>::maximum_value);
#endif /* STLSOFT_CF_MEMBER_CONSTANT_SUPPORT */
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
