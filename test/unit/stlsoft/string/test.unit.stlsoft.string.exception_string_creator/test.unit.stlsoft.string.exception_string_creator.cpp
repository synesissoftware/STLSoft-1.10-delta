/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.exception_string_creator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.exception_string_creator project.
 *
 * Created:     25th May 2010
 * Updated:     10th March 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/util/exception_string_creator.hpp>

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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.string.exception_string_creator", verbosity))
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

	using stlsoft::exception_string_creator;
	using stlsoft::exception_wstring_creator;

static void test_1_0()
{
	exception_string_creator instance;

	STLSOFT_SUPPRESS_UNUSED(instance);

	XTESTS_TEST_PASSED();
}

static void test_1_1()
{
	exception_string_creator instance;

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", instance.create());
}

static void test_1_2()
{
	exception_string_creator instance(1024u);

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, instance.capacity());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", instance.create());
}

static void test_1_3()
{
	exception_string_creator instance;

	instance.reserve(1024u);

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u, instance.capacity());
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", instance.create());
}

static void test_1_4()
{
	exception_string_creator instance("abc");

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance.create());
}

static void test_1_5()
{
	exception_string_creator instance("abcd", 3u);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance.create());
}

static void test_1_6()
{
	exception_string_creator instance1("abc");

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance1);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance1.create());

	exception_string_creator instance2(instance1);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance2);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance2.create());
}

static void test_1_7()
{
	exception_string_creator instance("abcd", 4u);

	instance.truncate(3u);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance.create());
}

static void test_1_8()
{
	exception_wstring_creator instance(L"abcd", 4u);

	instance.truncate(3u);

	XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", instance.create());
}

static void test_1_9()
{
	exception_string_creator instance("abcd", 4u);

	instance.append("efghijklmnopqrstuvwxyz", 4u);
	instance.append(L"ijk");
	instance.append("lmnopq");
	instance.append(L"rstuvwxyz", 8u);
	instance.append('z');

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", instance.create());
}

static void test_1_10()
{
	exception_string_creator instance("abcd", 4u);

	instance.append("efghijklmnopqrstuvwxyz", 4u);
	instance.append(L"ijk");

	std::string		lmn("lmn");
	instance.append(lmn);

	std::wstring	opq(L"opq");
	instance.append(opq);

	instance.append(L"rstuvwxyz", 8u);
	instance.append('z');

	instance.append(0)
			.append(12)
			.append(345)
			.append(6)
			.append(78)
			.append(9);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz0123456789", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz0123456789", instance.create());
}

static void test_1_11()
{
	using stlsoft::ss_sint8_t;
	using stlsoft::ss_uint8_t;
	using stlsoft::ss_sint16_t;
	using stlsoft::ss_uint16_t;
	using stlsoft::ss_sint32_t;
	using stlsoft::ss_uint32_t;
	using stlsoft::ss_sint64_t;
	using stlsoft::ss_uint64_t;

	exception_string_creator instance(10u);

	instance.append_number(ss_sint8_t(0))
			.append_number(ss_uint8_t(1))
			.append_number(ss_sint16_t(2))
			.append_number(ss_uint16_t(3))
			.append_number(ss_sint32_t(4))
			.append_number(ss_uint32_t(5))
			.append_number(ss_sint64_t(6))
			.append_number(ss_uint64_t(7))
			.append_number(int(8))
			.append_number(long(9))
			.append_number(static_cast<unsigned int>(0))
			.append_number(static_cast<unsigned long>(1));

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("012345678901", instance);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("012345678901", instance.create());
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
