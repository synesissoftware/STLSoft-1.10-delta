/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.util.integral_printf_traits.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.util.integral_printf_traits project.
 *
 * Created:     6th July 2012
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
 * Compatibility
 */

#ifdef _MSC_VER
# pragma warning(disable : 4996)
# define _CRT_SECURE_NO_WARNINGS
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define STLSOFT_ALLOW_OBSOLETE_1_9_IN_1_10
#include <stlsoft/util/integral_printf_traits.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <limits.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_format_0(void);
	static void test_format_1(void);
	static void test_format_2(void);
	static void test_format_3(void);
	static void test_format_4(void);
	static void test_format_5(void);
	static void test_format_6(void);
	static void test_format_7(void);
	static void test_format_8(void);
	static void test_format_9(void);
	static void test_decimal_format_0(void);
	static void test_decimal_format_1(void);
	static void test_decimal_format_2(void);
	static void test_decimal_format_3(void);
	static void test_decimal_format_4(void);
	static void test_decimal_format_5(void);
	static void test_decimal_format_6(void);
	static void test_decimal_format_7(void);
	static void test_decimal_format_8(void);
	static void test_decimal_format_9(void);
	static void test_hex_format_0(void);
	static void test_hex_format_1(void);
	static void test_hex_format_2(void);
	static void test_hex_format_3(void);
	static void test_hex_format_4(void);
	static void test_hex_format_5(void);
	static void test_hex_format_6(void);
	static void test_hex_format_7(void);
	static void test_hex_format_8(void);
	static void test_hex_format_9(void);
	static void test_hexadecimal_format_lower_0(void);
	static void test_hexadecimal_format_lower_1(void);
	static void test_hexadecimal_format_lower_2(void);
	static void test_hexadecimal_format_lower_3(void);
	static void test_hexadecimal_format_lower_4(void);
	static void test_hexadecimal_format_lower_5(void);
	static void test_hexadecimal_format_lower_6(void);
	static void test_hexadecimal_format_lower_7(void);
	static void test_hexadecimal_format_lower_8(void);
	static void test_hexadecimal_format_lower_9(void);
	static void test_hexadecimal_format_upper_0(void);
	static void test_hexadecimal_format_upper_1(void);
	static void test_hexadecimal_format_upper_2(void);
	static void test_hexadecimal_format_upper_3(void);
	static void test_hexadecimal_format_upper_4(void);
	static void test_hexadecimal_format_upper_5(void);
	static void test_hexadecimal_format_upper_6(void);
	static void test_hexadecimal_format_upper_7(void);
	static void test_hexadecimal_format_upper_8(void);
	static void test_hexadecimal_format_upper_9(void);
	static void test_octal_format_0(void);
	static void test_octal_format_1(void);
	static void test_octal_format_2(void);
	static void test_octal_format_3(void);
	static void test_octal_format_4(void);
	static void test_octal_format_5(void);
	static void test_octal_format_6(void);
	static void test_octal_format_7(void);
	static void test_octal_format_8(void);
	static void test_octal_format_9(void);

	static void test_width_0(void);
	static void test_width_1(void);
	static void test_width_2(void);
	static void test_width_3(void);
	static void test_width_4(void);
	static void test_width_5(void);
	static void test_width_6(void);
	static void test_width_7(void);
	static void test_width_8(void);
	static void test_width_9(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.util.integral_printf_traits", verbosity))
	{
		XTESTS_RUN_CASE(test_format_0);
		XTESTS_RUN_CASE(test_format_1);
		XTESTS_RUN_CASE(test_format_2);
		XTESTS_RUN_CASE(test_format_3);
		XTESTS_RUN_CASE(test_format_4);
		XTESTS_RUN_CASE(test_format_5);
		XTESTS_RUN_CASE(test_format_6);
		XTESTS_RUN_CASE(test_format_7);
		XTESTS_RUN_CASE(test_format_8);
		XTESTS_RUN_CASE(test_format_9);
		XTESTS_RUN_CASE(test_decimal_format_0);
		XTESTS_RUN_CASE(test_decimal_format_1);
		XTESTS_RUN_CASE(test_decimal_format_2);
		XTESTS_RUN_CASE(test_decimal_format_3);
		XTESTS_RUN_CASE(test_decimal_format_4);
		XTESTS_RUN_CASE(test_decimal_format_5);
		XTESTS_RUN_CASE(test_decimal_format_6);
		XTESTS_RUN_CASE(test_decimal_format_7);
		XTESTS_RUN_CASE(test_decimal_format_8);
		XTESTS_RUN_CASE(test_decimal_format_9);
		XTESTS_RUN_CASE(test_hex_format_0);
		XTESTS_RUN_CASE(test_hex_format_1);
		XTESTS_RUN_CASE(test_hex_format_2);
		XTESTS_RUN_CASE(test_hex_format_3);
		XTESTS_RUN_CASE(test_hex_format_4);
		XTESTS_RUN_CASE(test_hex_format_5);
		XTESTS_RUN_CASE(test_hex_format_6);
		XTESTS_RUN_CASE(test_hex_format_7);
		XTESTS_RUN_CASE(test_hex_format_8);
		XTESTS_RUN_CASE(test_hex_format_9);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_0);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_1);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_2);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_3);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_4);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_5);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_6);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_7);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_8);
		XTESTS_RUN_CASE(test_hexadecimal_format_lower_9);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_0);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_1);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_2);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_3);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_4);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_5);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_6);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_7);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_8);
		XTESTS_RUN_CASE(test_hexadecimal_format_upper_9);
		XTESTS_RUN_CASE(test_octal_format_0);
		XTESTS_RUN_CASE(test_octal_format_1);
		XTESTS_RUN_CASE(test_octal_format_2);
		XTESTS_RUN_CASE(test_octal_format_3);
		XTESTS_RUN_CASE(test_octal_format_4);
		XTESTS_RUN_CASE(test_octal_format_5);
		XTESTS_RUN_CASE(test_octal_format_6);
		XTESTS_RUN_CASE(test_octal_format_7);
		XTESTS_RUN_CASE(test_octal_format_8);
		XTESTS_RUN_CASE(test_octal_format_9);

		XTESTS_RUN_CASE(test_width_0);
		XTESTS_RUN_CASE(test_width_1);
		XTESTS_RUN_CASE(test_width_2);
		XTESTS_RUN_CASE(test_width_3);
		XTESTS_RUN_CASE(test_width_4);
		XTESTS_RUN_CASE(test_width_5);
		XTESTS_RUN_CASE(test_width_6);
		XTESTS_RUN_CASE(test_width_7);
		XTESTS_RUN_CASE(test_width_8);
		XTESTS_RUN_CASE(test_width_9);

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
	using stlsoft::ss_uint8_t;
	using stlsoft::ss_sint16_t;
	using stlsoft::ss_uint16_t;
	using stlsoft::ss_sint32_t;
	using stlsoft::ss_uint32_t;
	using stlsoft::ss_sint64_t;
	using stlsoft::ss_uint64_t;

	using stlsoft::integral_printf_traits;

static void test_format_0()
{
#ifdef STLSOFT_CF_char_IS_UNSIGNED
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<char>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<char>::format_w());
#else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<char>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<char>::format_w());
#endif
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<signed char>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<signed char>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<unsigned char>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<unsigned char>::format_w());
}

static void test_format_1()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<signed short>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<signed short>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<unsigned short>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<unsigned short>::format_w());
}

static void test_format_2()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<signed int>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<signed int>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<unsigned int>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<unsigned int>::format_w());
}

static void test_format_3()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%ld", stlsoft::integral_printf_traits<signed long>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%ld", stlsoft::integral_printf_traits<signed long>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lu", stlsoft::integral_printf_traits<unsigned long>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lu", stlsoft::integral_printf_traits<unsigned long>::format_w());
}

static void test_format_4()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64d", stlsoft::integral_printf_traits<signed long long>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64d", stlsoft::integral_printf_traits<signed long long>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64u", stlsoft::integral_printf_traits<unsigned long long>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64u", stlsoft::integral_printf_traits<unsigned long long>::format_w());
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lld", stlsoft::integral_printf_traits<signed long long>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lld", stlsoft::integral_printf_traits<signed long long>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llu", stlsoft::integral_printf_traits<unsigned long long>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llu", stlsoft::integral_printf_traits<unsigned long long>::format_w());
# endif
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_format_5()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<stlsoft::sint8_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<stlsoft::sint8_t>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<stlsoft::uint8_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<stlsoft::uint8_t>::format_w());
}

static void test_format_6()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<stlsoft::sint16_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<stlsoft::sint16_t>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<stlsoft::uint16_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<stlsoft::uint16_t>::format_w());
}

static void test_format_7()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<stlsoft::sint32_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<stlsoft::sint32_t>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<stlsoft::uint32_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<stlsoft::uint32_t>::format_w());
}

static void test_format_8()
{
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64d", stlsoft::integral_printf_traits<stlsoft::sint64_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64d", stlsoft::integral_printf_traits<stlsoft::sint64_t>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64u", stlsoft::integral_printf_traits<stlsoft::uint64_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64u", stlsoft::integral_printf_traits<stlsoft::uint64_t>::format_w());
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lld", stlsoft::integral_printf_traits<stlsoft::sint64_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lld", stlsoft::integral_printf_traits<stlsoft::sint64_t>::format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llu", stlsoft::integral_printf_traits<stlsoft::uint64_t>::format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llu", stlsoft::integral_printf_traits<stlsoft::uint64_t>::format_w());
# endif
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
}

static void test_format_9()
{
}

static void test_decimal_format_0()
{
#ifdef STLSOFT_CF_char_IS_UNSIGNED
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<char>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<char>::decimal_format_w());
#else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<char>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<char>::decimal_format_w());
#endif
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<signed char>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<signed char>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<unsigned char>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<unsigned char>::decimal_format_w());
}

static void test_decimal_format_1()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<signed short>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<signed short>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<unsigned short>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<unsigned short>::decimal_format_w());
}

static void test_decimal_format_2()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<signed int>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<signed int>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<unsigned int>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<unsigned int>::decimal_format_w());
}

static void test_decimal_format_3()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%ld", stlsoft::integral_printf_traits<signed long>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%ld", stlsoft::integral_printf_traits<signed long>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lu", stlsoft::integral_printf_traits<unsigned long>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lu", stlsoft::integral_printf_traits<unsigned long>::decimal_format_w());
}

static void test_decimal_format_4()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64d", stlsoft::integral_printf_traits<signed long long>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64d", stlsoft::integral_printf_traits<signed long long>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64u", stlsoft::integral_printf_traits<unsigned long long>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64u", stlsoft::integral_printf_traits<unsigned long long>::decimal_format_w());
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lld", stlsoft::integral_printf_traits<signed long long>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lld", stlsoft::integral_printf_traits<signed long long>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llu", stlsoft::integral_printf_traits<unsigned long long>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llu", stlsoft::integral_printf_traits<unsigned long long>::decimal_format_w());
# endif
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_decimal_format_5()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<stlsoft::sint8_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<stlsoft::sint8_t>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<stlsoft::uint8_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<stlsoft::uint8_t>::decimal_format_w());
}

static void test_decimal_format_6()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<stlsoft::sint16_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<stlsoft::sint16_t>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<stlsoft::uint16_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<stlsoft::uint16_t>::decimal_format_w());
}

static void test_decimal_format_7()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%d", stlsoft::integral_printf_traits<stlsoft::sint32_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%d", stlsoft::integral_printf_traits<stlsoft::sint32_t>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%u", stlsoft::integral_printf_traits<stlsoft::uint32_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%u", stlsoft::integral_printf_traits<stlsoft::uint32_t>::decimal_format_w());
}

static void test_decimal_format_8()
{
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64d", stlsoft::integral_printf_traits<stlsoft::sint64_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64d", stlsoft::integral_printf_traits<stlsoft::sint64_t>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64u", stlsoft::integral_printf_traits<stlsoft::uint64_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64u", stlsoft::integral_printf_traits<stlsoft::uint64_t>::decimal_format_w());
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lld", stlsoft::integral_printf_traits<stlsoft::sint64_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lld", stlsoft::integral_printf_traits<stlsoft::sint64_t>::decimal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llu", stlsoft::integral_printf_traits<stlsoft::uint64_t>::decimal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llu", stlsoft::integral_printf_traits<stlsoft::uint64_t>::decimal_format_w());
# endif
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
}

static void test_decimal_format_9()
{
}

static void test_hex_format_0()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<signed char>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<signed char>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<unsigned char>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<unsigned char>::hex_format_w());
}

static void test_hex_format_1()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<signed short>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<signed short>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<unsigned short>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<unsigned short>::hex_format_w());
}

static void test_hex_format_2()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<signed int>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<signed int>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<unsigned int>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<unsigned int>::hex_format_w());
}

static void test_hex_format_3()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lx", stlsoft::integral_printf_traits<signed long>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lx", stlsoft::integral_printf_traits<signed long>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lx", stlsoft::integral_printf_traits<unsigned long>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lx", stlsoft::integral_printf_traits<unsigned long>::hex_format_w());
}

static void test_hex_format_4()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", stlsoft::integral_printf_traits<signed long long>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", stlsoft::integral_printf_traits<signed long long>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", stlsoft::integral_printf_traits<unsigned long long>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", stlsoft::integral_printf_traits<unsigned long long>::hex_format_w());
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", stlsoft::integral_printf_traits<signed long long>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", stlsoft::integral_printf_traits<signed long long>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", stlsoft::integral_printf_traits<unsigned long long>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", stlsoft::integral_printf_traits<unsigned long long>::hex_format_w());
# endif
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_hex_format_5()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::sint8_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::sint8_t>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::uint8_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::uint8_t>::hex_format_w());
}

static void test_hex_format_6()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::sint16_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::sint16_t>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::uint16_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::uint16_t>::hex_format_w());
}

static void test_hex_format_7()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::sint32_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::sint32_t>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::uint32_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::uint32_t>::hex_format_w());
}

static void test_hex_format_8()
{
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hex_format_w());
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hex_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hex_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hex_format_w());
# endif
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
}

static void test_hex_format_9()
{
}

static void test_hexadecimal_format_lower_0()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<signed char>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<signed char>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<unsigned char>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<unsigned char>::hexadecimal_format_w(false));
}

static void test_hexadecimal_format_lower_1()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<signed short>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<signed short>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<unsigned short>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<unsigned short>::hexadecimal_format_w(false));
}

static void test_hexadecimal_format_lower_2()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<signed int>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<signed int>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<unsigned int>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<unsigned int>::hexadecimal_format_w(false));
}

static void test_hexadecimal_format_lower_3()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lx", stlsoft::integral_printf_traits<signed long>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lx", stlsoft::integral_printf_traits<signed long>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lx", stlsoft::integral_printf_traits<unsigned long>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lx", stlsoft::integral_printf_traits<unsigned long>::hexadecimal_format_w(false));
}

static void test_hexadecimal_format_lower_4()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", stlsoft::integral_printf_traits<signed long long>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", stlsoft::integral_printf_traits<signed long long>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", stlsoft::integral_printf_traits<unsigned long long>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", stlsoft::integral_printf_traits<unsigned long long>::hexadecimal_format_w(false));
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", stlsoft::integral_printf_traits<signed long long>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", stlsoft::integral_printf_traits<signed long long>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", stlsoft::integral_printf_traits<unsigned long long>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", stlsoft::integral_printf_traits<unsigned long long>::hexadecimal_format_w(false));
# endif
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_hexadecimal_format_lower_5()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::sint8_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::sint8_t>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::uint8_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::uint8_t>::hexadecimal_format_w(false));
}

static void test_hexadecimal_format_lower_6()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::sint16_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::sint16_t>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::uint16_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::uint16_t>::hexadecimal_format_w(false));
}

static void test_hexadecimal_format_lower_7()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::sint32_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::sint32_t>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%x", stlsoft::integral_printf_traits<stlsoft::uint32_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%x", stlsoft::integral_printf_traits<stlsoft::uint32_t>::hexadecimal_format_w(false));
}

static void test_hexadecimal_format_lower_8()
{
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64x", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64x", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hexadecimal_format_w(false));
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hexadecimal_format_w(false));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llx", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hexadecimal_format_a(false));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llx", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hexadecimal_format_w(false));
# endif
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
}

static void test_hexadecimal_format_lower_9()
{
}

static void test_hexadecimal_format_upper_0()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<signed char>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<signed char>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<unsigned char>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<unsigned char>::hexadecimal_format_w(true));
}

static void test_hexadecimal_format_upper_1()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<signed short>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<signed short>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<unsigned short>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<unsigned short>::hexadecimal_format_w(true));
}

static void test_hexadecimal_format_upper_2()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<signed int>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<signed int>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<unsigned int>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<unsigned int>::hexadecimal_format_w(true));
}

static void test_hexadecimal_format_upper_3()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lX", stlsoft::integral_printf_traits<signed long>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lX", stlsoft::integral_printf_traits<signed long>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lX", stlsoft::integral_printf_traits<unsigned long>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lX", stlsoft::integral_printf_traits<unsigned long>::hexadecimal_format_w(true));
}

static void test_hexadecimal_format_upper_4()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64X", stlsoft::integral_printf_traits<signed long long>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64X", stlsoft::integral_printf_traits<signed long long>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64X", stlsoft::integral_printf_traits<unsigned long long>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64X", stlsoft::integral_printf_traits<unsigned long long>::hexadecimal_format_w(true));
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llX", stlsoft::integral_printf_traits<signed long long>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llX", stlsoft::integral_printf_traits<signed long long>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llX", stlsoft::integral_printf_traits<unsigned long long>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llX", stlsoft::integral_printf_traits<unsigned long long>::hexadecimal_format_w(true));
# endif
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_hexadecimal_format_upper_5()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<stlsoft::sint8_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<stlsoft::sint8_t>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<stlsoft::uint8_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<stlsoft::uint8_t>::hexadecimal_format_w(true));
}

static void test_hexadecimal_format_upper_6()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<stlsoft::sint16_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<stlsoft::sint16_t>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<stlsoft::uint16_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<stlsoft::uint16_t>::hexadecimal_format_w(true));
}

static void test_hexadecimal_format_upper_7()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<stlsoft::sint32_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<stlsoft::sint32_t>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%X", stlsoft::integral_printf_traits<stlsoft::uint32_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%X", stlsoft::integral_printf_traits<stlsoft::uint32_t>::hexadecimal_format_w(true));
}

static void test_hexadecimal_format_upper_8()
{
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64X", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64X", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64X", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64X", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hexadecimal_format_w(true));
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llX", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llX", stlsoft::integral_printf_traits<stlsoft::sint64_t>::hexadecimal_format_w(true));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llX", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hexadecimal_format_a(true));
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llX", stlsoft::integral_printf_traits<stlsoft::uint64_t>::hexadecimal_format_w(true));
# endif
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
}

static void test_hexadecimal_format_upper_9()
{
}

static void test_octal_format_0()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<signed char>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<signed char>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<unsigned char>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<unsigned char>::octal_format_w());
}

static void test_octal_format_1()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<signed short>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<signed short>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<unsigned short>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<unsigned short>::octal_format_w());
}

static void test_octal_format_2()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<signed int>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<signed int>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<unsigned int>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<unsigned int>::octal_format_w());
}

static void test_octal_format_3()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lo", stlsoft::integral_printf_traits<signed long>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lo", stlsoft::integral_printf_traits<signed long>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%lo", stlsoft::integral_printf_traits<unsigned long>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%lo", stlsoft::integral_printf_traits<unsigned long>::octal_format_w());
}

static void test_octal_format_4()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64o", stlsoft::integral_printf_traits<signed long long>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64o", stlsoft::integral_printf_traits<signed long long>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64o", stlsoft::integral_printf_traits<unsigned long long>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64o", stlsoft::integral_printf_traits<unsigned long long>::octal_format_w());
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llo", stlsoft::integral_printf_traits<signed long long>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llo", stlsoft::integral_printf_traits<signed long long>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llo", stlsoft::integral_printf_traits<unsigned long long>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llo", stlsoft::integral_printf_traits<unsigned long long>::octal_format_w());
# endif
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_octal_format_5()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<stlsoft::sint8_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<stlsoft::sint8_t>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<stlsoft::uint8_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<stlsoft::uint8_t>::octal_format_w());
}

static void test_octal_format_6()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<stlsoft::sint16_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<stlsoft::sint16_t>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<stlsoft::uint16_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<stlsoft::uint16_t>::octal_format_w());
}

static void test_octal_format_7()
{
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<stlsoft::sint32_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<stlsoft::sint32_t>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%o", stlsoft::integral_printf_traits<stlsoft::uint32_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%o", stlsoft::integral_printf_traits<stlsoft::uint32_t>::octal_format_w());
}

static void test_octal_format_8()
{
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
# ifdef STLSOFT_CF_64_BIT_PRINTF_USES_I64
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64o", stlsoft::integral_printf_traits<stlsoft::sint64_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64o", stlsoft::integral_printf_traits<stlsoft::sint64_t>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%I64o", stlsoft::integral_printf_traits<stlsoft::uint64_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%I64o", stlsoft::integral_printf_traits<stlsoft::uint64_t>::octal_format_w());
# else
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llo", stlsoft::integral_printf_traits<stlsoft::sint64_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llo", stlsoft::integral_printf_traits<stlsoft::sint64_t>::octal_format_w());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("%llo", stlsoft::integral_printf_traits<stlsoft::uint64_t>::octal_format_a());
	XTESTS_TEST_WIDE_STRING_EQUAL(L"%llo", stlsoft::integral_printf_traits<stlsoft::uint64_t>::octal_format_w());
# endif
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
}

static void test_octal_format_9()
{
}


static void test_width_0()
{
#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_FORMAT_TRAITS) || \
	defined(STLSOFT_ALLOW_OBSOLETE_1_9_IN_1_10)

	XTESTS_TEST_INTEGER_EQUAL(5,  int(stlsoft::integral_printf_traits<ss_sint8_t>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(4,  int(stlsoft::integral_printf_traits<ss_sint8_t>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(2,  int(stlsoft::integral_printf_traits<ss_uint8_t>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(4,  int(stlsoft::integral_printf_traits<ss_uint8_t>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(7,  int(stlsoft::integral_printf_traits<ss_sint16_t>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(6,  int(stlsoft::integral_printf_traits<ss_sint16_t>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(2,  int(stlsoft::integral_printf_traits<ss_uint16_t>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(6,  int(stlsoft::integral_printf_traits<ss_uint16_t>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(12, int(stlsoft::integral_printf_traits<ss_sint32_t>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(11, int(stlsoft::integral_printf_traits<ss_sint32_t>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(2,  int(stlsoft::integral_printf_traits<ss_uint32_t>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(11, int(stlsoft::integral_printf_traits<ss_uint32_t>::size_max));

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(21, int(stlsoft::integral_printf_traits<ss_sint64_t>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(20, int(stlsoft::integral_printf_traits<ss_sint64_t>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(2,  int(stlsoft::integral_printf_traits<ss_uint64_t>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(21, int(stlsoft::integral_printf_traits<ss_uint64_t>::size_max));
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_FORMAT_TRAITS || STLSOFT_ALLOW_OBSOLETE_1_9_IN_1_10 */
}

static void test_width_1()
{
#if !defined(STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_FORMAT_TRAITS) || \
	defined(STLSOFT_ALLOW_OBSOLETE_1_9_IN_1_10)

	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_SCHAR_MIN)),  size_t(stlsoft::integral_printf_traits<signed char>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_SCHAR_MAX)),  size_t(stlsoft::integral_printf_traits<signed char>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_UCHAR_MIN)),  size_t(stlsoft::integral_printf_traits<unsigned char>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_UCHAR_MAX)),  size_t(stlsoft::integral_printf_traits<unsigned char>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_SHORT_MIN)),  size_t(stlsoft::integral_printf_traits<signed short>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_SHORT_MAX)),  size_t(stlsoft::integral_printf_traits<signed short>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_USHORT_MIN)), size_t(stlsoft::integral_printf_traits<unsigned short>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_USHORT_MAX)), size_t(stlsoft::integral_printf_traits<unsigned short>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_MIN)),   size_t(stlsoft::integral_printf_traits<signed long>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_LONG_MAX)),   size_t(stlsoft::integral_printf_traits<signed long>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_MIN)),  size_t(stlsoft::integral_printf_traits<unsigned long>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_ULONG_MAX)),  size_t(stlsoft::integral_printf_traits<unsigned long>::size_max));

# ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT_x
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_LLONG_MIN)),  size_t(stlsoft::integral_printf_traits<signed long long>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_LLONG_MAX)),  size_t(stlsoft::integral_printf_traits<signed long long>::size_max));

	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_ULLONG_MIN)), size_t(stlsoft::integral_printf_traits<unsigned long long>::size_min));
	XTESTS_TEST_INTEGER_EQUAL(sizeof(STLSOFT_STRINGIZE(STLSOFT_INTEGRAL_PRINTF_TRAITS_ULLONG_MAX)), size_t(stlsoft::integral_printf_traits<unsigned long long>::size_max));
# endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_FORMAT_TRAITS || STLSOFT_ALLOW_OBSOLETE_1_9_IN_1_10 */
}

static void test_width_2()
{
}

static void test_width_3()
{
}

static void test_width_4()
{
#ifdef STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_FORMAT_TRAITS
	XTESTS_TEST_INTEGER_EQUAL(4,  int(stlsoft::integral_printf_traits<ss_sint8_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(3,  int(stlsoft::integral_printf_traits<ss_uint8_t>::maxDecimalWidth));

	XTESTS_TEST_INTEGER_EQUAL(6,  int(stlsoft::integral_printf_traits<ss_sint16_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(5,  int(stlsoft::integral_printf_traits<ss_uint16_t>::maxDecimalWidth));

	XTESTS_TEST_INTEGER_EQUAL(11, int(stlsoft::integral_printf_traits<ss_sint32_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(10, int(stlsoft::integral_printf_traits<ss_uint32_t>::maxDecimalWidth));

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
	XTESTS_TEST_INTEGER_EQUAL(20, int(stlsoft::integral_printf_traits<ss_sint64_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(20, int(stlsoft::integral_printf_traits<ss_uint64_t>::maxDecimalWidth));
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#endif /* STLSOFT_INCL_STLSOFT_UTIL_HPP_INTEGRAL_PRINTF_FORMAT_TRAITS */
}

static void test_width_5()
{
}

static void test_width_6()
{
}

static void test_width_7()
{
}

static void test_width_8()
{
}

static void test_width_9()
{
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
