/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.limits.integral_format_width_limits.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.limits.integral_format_width_limits project.
 *
 * Created:     10th July 2012
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
 * Compiler compatibility
 */

#ifdef _MSC_VER
# pragma warning(disable : 4702 4996)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/limits/integral_format_width_limits.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/limits/integral_limits.hpp>
#include <stlsoft/traits/integral_printf_format_traits.hpp>
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_decimal_0(void);
	static void test_decimal_1(void);
	static void test_decimal_2(void);
	static void test_decimal_3(void);
	static void test_decimal_4(void);
	static void test_decimal_5(void);
	static void test_decimal_6(void);
	static void test_decimal_7(void);
	static void test_decimal_8(void);
	static void test_decimal_9(void);
	static void test_decimal_10(void);
	static void test_decimal_11(void);
	static void test_decimal_12(void);
	static void test_decimal_13(void);
	static void test_decimal_14(void);
	static void test_decimal_15(void);
	static void test_decimal_16(void);
	static void test_decimal_17(void);
	static void test_decimal_18(void);
	static void test_decimal_19(void);

	static void test_octal_0(void);
	static void test_octal_1(void);
	static void test_octal_2(void);
	static void test_octal_3(void);
	static void test_octal_4(void);
	static void test_octal_5(void);
	static void test_octal_6(void);
	static void test_octal_7(void);
	static void test_octal_8(void);
	static void test_octal_9(void);
	static void test_octal_10(void);
	static void test_octal_11(void);
	static void test_octal_12(void);
	static void test_octal_13(void);
	static void test_octal_14(void);
	static void test_octal_15(void);
	static void test_octal_16(void);
	static void test_octal_17(void);
	static void test_octal_18(void);
	static void test_octal_19(void);

	static void test_hexadecimal_0(void);
	static void test_hexadecimal_1(void);
	static void test_hexadecimal_2(void);
	static void test_hexadecimal_3(void);
	static void test_hexadecimal_4(void);
	static void test_hexadecimal_5(void);
	static void test_hexadecimal_6(void);
	static void test_hexadecimal_7(void);
	static void test_hexadecimal_8(void);
	static void test_hexadecimal_9(void);
	static void test_hexadecimal_10(void);
	static void test_hexadecimal_11(void);
	static void test_hexadecimal_12(void);
	static void test_hexadecimal_13(void);
	static void test_hexadecimal_14(void);
	static void test_hexadecimal_15(void);
	static void test_hexadecimal_16(void);
	static void test_hexadecimal_17(void);
	static void test_hexadecimal_18(void);
	static void test_hexadecimal_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.limits.integral_format_width_limits", verbosity))
	{
		XTESTS_RUN_CASE(test_decimal_0);
		XTESTS_RUN_CASE(test_decimal_1);
		XTESTS_RUN_CASE(test_decimal_2);
		XTESTS_RUN_CASE(test_decimal_3);
		XTESTS_RUN_CASE(test_decimal_4);
		XTESTS_RUN_CASE(test_decimal_5);
		XTESTS_RUN_CASE(test_decimal_6);
		XTESTS_RUN_CASE(test_decimal_7);
		XTESTS_RUN_CASE(test_decimal_8);
		XTESTS_RUN_CASE(test_decimal_9);
		XTESTS_RUN_CASE(test_decimal_10);
		XTESTS_RUN_CASE(test_decimal_11);
		XTESTS_RUN_CASE(test_decimal_12);
		XTESTS_RUN_CASE(test_decimal_13);
		XTESTS_RUN_CASE(test_decimal_14);
		XTESTS_RUN_CASE(test_decimal_15);
		XTESTS_RUN_CASE(test_decimal_16);
		XTESTS_RUN_CASE(test_decimal_17);
		XTESTS_RUN_CASE(test_decimal_18);
		XTESTS_RUN_CASE(test_decimal_19);

		XTESTS_RUN_CASE(test_octal_0);
		XTESTS_RUN_CASE(test_octal_1);
		XTESTS_RUN_CASE(test_octal_2);
		XTESTS_RUN_CASE(test_octal_3);
		XTESTS_RUN_CASE(test_octal_4);
		XTESTS_RUN_CASE(test_octal_5);
		XTESTS_RUN_CASE(test_octal_6);
		XTESTS_RUN_CASE(test_octal_7);
		XTESTS_RUN_CASE(test_octal_8);
		XTESTS_RUN_CASE(test_octal_9);
		XTESTS_RUN_CASE(test_octal_10);
		XTESTS_RUN_CASE(test_octal_11);
		XTESTS_RUN_CASE(test_octal_12);
		XTESTS_RUN_CASE(test_octal_13);
		XTESTS_RUN_CASE(test_octal_14);
		XTESTS_RUN_CASE(test_octal_15);
		XTESTS_RUN_CASE(test_octal_16);
		XTESTS_RUN_CASE(test_octal_17);
		XTESTS_RUN_CASE(test_octal_18);
		XTESTS_RUN_CASE(test_octal_19);

		XTESTS_RUN_CASE(test_hexadecimal_0);
		XTESTS_RUN_CASE(test_hexadecimal_1);
		XTESTS_RUN_CASE(test_hexadecimal_2);
		XTESTS_RUN_CASE(test_hexadecimal_3);
		XTESTS_RUN_CASE(test_hexadecimal_4);
		XTESTS_RUN_CASE(test_hexadecimal_5);
		XTESTS_RUN_CASE(test_hexadecimal_6);
		XTESTS_RUN_CASE(test_hexadecimal_7);
		XTESTS_RUN_CASE(test_hexadecimal_8);
		XTESTS_RUN_CASE(test_hexadecimal_9);
		XTESTS_RUN_CASE(test_hexadecimal_10);
		XTESTS_RUN_CASE(test_hexadecimal_11);
		XTESTS_RUN_CASE(test_hexadecimal_12);
		XTESTS_RUN_CASE(test_hexadecimal_13);
		XTESTS_RUN_CASE(test_hexadecimal_14);
		XTESTS_RUN_CASE(test_hexadecimal_15);
		XTESTS_RUN_CASE(test_hexadecimal_16);
		XTESTS_RUN_CASE(test_hexadecimal_17);
		XTESTS_RUN_CASE(test_hexadecimal_18);
		XTESTS_RUN_CASE(test_hexadecimal_19);

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

static void test_decimal_0()
{
	char		buf[21];
#ifdef STLSOFT_CF_char_IS_UNSIGNED
	int const	n = ::sprintf(buf, "%u", UCHAR_MAX);
#else /* ? STLSOFT_CF_char_IS_UNSIGNED */
	int const	n = ::sprintf(buf, "%d", SCHAR_MIN);
#endif /* STLSOFT_CF_char_IS_UNSIGNED */

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<char>::maxDecimalWidth));
}

static void test_decimal_1()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%d", SCHAR_MIN);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<signed char>::maxDecimalWidth));
}

static void test_decimal_2()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%u", UCHAR_MAX);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<unsigned char>::maxDecimalWidth));
}

static void test_decimal_3()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%d", SHRT_MIN);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<signed short>::maxDecimalWidth));
}

static void test_decimal_4()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%u", USHRT_MAX);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<unsigned short>::maxDecimalWidth));
}

static void test_decimal_5()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%d", INT_MIN);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<signed int>::maxDecimalWidth));
}

static void test_decimal_6()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%u", UINT_MAX);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<unsigned int>::maxDecimalWidth));
}

static void test_decimal_7()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%d", LONG_MIN);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<signed long>::maxDecimalWidth));
}

static void test_decimal_8()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%u", ULONG_MAX);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<unsigned long>::maxDecimalWidth));
}

static void test_decimal_9()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
	char		buf[21];
	int const	n = ::sprintf(buf, "%lld", LLONG_MIN);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<signed long long>::maxDecimalWidth));
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_decimal_10()
{
#ifdef STLSOFT_CF_BUILTIN_long_long_SUPPORT
	char		buf[21];
	int const	n = ::sprintf(buf, "%llu", ULLONG_MAX);

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<unsigned long long>::maxDecimalWidth));
#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT */
}

static void test_decimal_11()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%d", stlsoft::integral_limits<stlsoft::ss_sint8_t>::minimum());

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint8_t>::maxDecimalWidth));


	XTESTS_TEST_INTEGER_EQUAL(4, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint8_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(3, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint8_t>::maxDecimalWidthWithoutSign));
}

static void test_decimal_12()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%u", stlsoft::integral_limits<stlsoft::ss_uint8_t>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint8_t>::maxDecimalWidth));


	XTESTS_TEST_INTEGER_EQUAL(3, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint8_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(3, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint8_t>::maxDecimalWidthWithoutSign));
}

static void test_decimal_13()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%d", stlsoft::integral_limits<stlsoft::ss_sint16_t>::minimum());

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint16_t>::maxDecimalWidth));


	XTESTS_TEST_INTEGER_EQUAL(6, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint16_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(5, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint16_t>::maxDecimalWidthWithoutSign));
}

static void test_decimal_14()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%u", stlsoft::integral_limits<stlsoft::ss_uint16_t>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint16_t>::maxDecimalWidth));


	XTESTS_TEST_INTEGER_EQUAL(5, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint16_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(5, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint16_t>::maxDecimalWidthWithoutSign));
}

static void test_decimal_15()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%d", stlsoft::integral_limits<stlsoft::ss_sint32_t>::minimum());

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint32_t>::maxDecimalWidth));


	XTESTS_TEST_INTEGER_EQUAL(11, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint32_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(10, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint32_t>::maxDecimalWidthWithoutSign));
}

static void test_decimal_16()
{
	char		buf[21];
	int const	n = ::sprintf(buf, "%u", stlsoft::integral_limits<stlsoft::ss_uint32_t>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint32_t>::maxDecimalWidth));


	XTESTS_TEST_INTEGER_EQUAL(10, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint32_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(10, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint32_t>::maxDecimalWidthWithoutSign));
}

static void test_decimal_17()
{
	char		buf[21];
	int const	n = ::sprintf(buf, stlsoft::integral_printf_format_traits<stlsoft::ss_sint64_t>::decimal_format_a(), stlsoft::integral_limits<stlsoft::ss_sint64_t>::minimum());

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint64_t>::maxDecimalWidth));


	XTESTS_TEST_INTEGER_EQUAL(20, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint64_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(19, int(stlsoft::integral_format_width_limits<stlsoft::ss_sint64_t>::maxDecimalWidthWithoutSign));
}

static void test_decimal_18()
{
	char		buf[21];
	int const	n = ::sprintf(buf, stlsoft::integral_printf_format_traits<stlsoft::ss_uint64_t>::decimal_format_a(), stlsoft::integral_limits<stlsoft::ss_uint64_t>::maximum());

	XTESTS_TEST_INTEGER_EQUAL(n, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint64_t>::maxDecimalWidth));


	XTESTS_TEST_INTEGER_EQUAL(20, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint64_t>::maxDecimalWidth));
	XTESTS_TEST_INTEGER_EQUAL(20, int(stlsoft::integral_format_width_limits<stlsoft::ss_uint64_t>::maxDecimalWidthWithoutSign));
}

static void test_decimal_19()
{
}


static void test_octal_0()
{
}

static void test_octal_1()
{
}

static void test_octal_2()
{
}

static void test_octal_3()
{
}

static void test_octal_4()
{
}

static void test_octal_5()
{
}

static void test_octal_6()
{
}

static void test_octal_7()
{
}

static void test_octal_8()
{
}

static void test_octal_9()
{
}

static void test_octal_10()
{
}

static void test_octal_11()
{
}

static void test_octal_12()
{
}

static void test_octal_13()
{
}

static void test_octal_14()
{
}

static void test_octal_15()
{
}

static void test_octal_16()
{
}

static void test_octal_17()
{
}

static void test_octal_18()
{
}

static void test_octal_19()
{
}


static void test_hexadecimal_0()
{
}

static void test_hexadecimal_1()
{
}

static void test_hexadecimal_2()
{
}

static void test_hexadecimal_3()
{
}

static void test_hexadecimal_4()
{
}

static void test_hexadecimal_5()
{
}

static void test_hexadecimal_6()
{
}

static void test_hexadecimal_7()
{
}

static void test_hexadecimal_8()
{
}

static void test_hexadecimal_9()
{
}

static void test_hexadecimal_10()
{
}

static void test_hexadecimal_11()
{
}

static void test_hexadecimal_12()
{
}

static void test_hexadecimal_13()
{
}

static void test_hexadecimal_14()
{
}

static void test_hexadecimal_15()
{
}

static void test_hexadecimal_16()
{
}

static void test_hexadecimal_17()
{
}

static void test_hexadecimal_18()
{
}

static void test_hexadecimal_19()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
