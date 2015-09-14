/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.conversion.integer_to_hex_string.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.conversion.integer_to_hex_string project.
 *
 * Created:     12th July 2009
 * Updated:     11th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/conversion/integer_to_hex_string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/printf_traits.hpp>
#include <stlsoft/util/rand.hpp>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C++ Header Files */
#include <algorithm>
#include <vector>

/* Standard C Header Files */
#include <stdarg.h>
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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.conversion.integer_to_hex_string", verbosity))
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

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
	}

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 */

namespace
{

#if defined(STLSOFT_COMPILER_IS_MSVC) || \
	(	defined(STLSOFT_COMPILER_IS_INTEL) && \
		defined(_WIN32) && \
		defined(_MSC_VER))
# define vsnprintf			_vsnprintf
# if _MSC_VER >= 1200
#  pragma warning(push)
# endif
# if _MSC_VER >= 1400
#  pragma warning(disable : 4996)
# endif
#endif

int call_snprintf(
	char*		buffer
,	size_t		cchBuffer
,	char const*	fmt
,	...
)
{
	va_list	args;

	va_start(args, fmt);

	int		r = ::vsnprintf(buffer, cchBuffer, fmt, args);

	va_end(args);

	return r;
}

#if defined(STLSOFT_COMPILER_IS_MSVC) || \
	(	defined(STLSOFT_COMPILER_IS_INTEL) && \
		defined(_WIN32) && \
		defined(_MSC_VER))
# if _MSC_VER >= 1200
#  pragma warning(pop)
# endif
#endif

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{
	using stlsoft::uint32_t;
	using stlsoft::uint64_t;


static void test_1_0()
{
	char		sz[19];
	char const*	result = stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), 0);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", result);
}

static void test_1_1()
{
	char		sz[19];
	char const*	result = stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), 1);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1", result);
}

static void test_1_2()
{
	{
		char		sz[19];
		char const*	result = stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), 8);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("8", result);
	}

	{
		char		sz[19];
		char const*	result = stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), 10);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", result);
	}

	{
		char		sz[19];
		char const*	result = stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), 14);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("e", result);
	}

	{
		char		sz[19];
		char const*	result = stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), 15);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("f", result);
	}
}

static void test_1_3()
{
	{
		char		sz[19];
		char const*	result = stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), 16);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("10", result);
	}

	{
		char		sz[19];
		char const*	result = stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), 31);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1f", result);
	}
}

static void test_1_4()
{
	::srand(10101);

	{ for(unsigned i = 0; i != 100000; ++i)
	{
		char		sz1[19];
		char		sz2[19];
		unsigned	value	=	stlsoft::rand<unsigned>(/* static_cast<unsigned*>(NULL) */);
		char const*	result	=	stlsoft::integer_to_hex_string(&sz2[0], STLSOFT_NUM_ELEMENTS(sz2), value);

		call_snprintf(&sz1[0], STLSOFT_NUM_ELEMENTS(sz1), "%x", value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, result);
	}}
}

static void test_1_5()
{
	platformstl::performance_counter	counter;

	platformstl::performance_counter::interval_type		t1, t2;

	std::vector<unsigned>	values(1000000);

#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    (	!defined(STLSOFT_COMPILER_IS_MSVC) || \
		_MSC_VER >= 1310)
	unsigned (*pfn)(void) = stlsoft::rand<unsigned>;

	std::generate(values.begin(), values.end(), pfn);
#else /* ? compiler */
	{ for(std::vector<unsigned>::iterator i = values.begin(); i != values.end(); ++i)
	{
		*i = stlsoft::rand<unsigned>();
	}}
#endif /* compiler */

	counter.start();
	{ for(std::vector<unsigned>::const_iterator i = values.begin(); i != values.end(); ++i)
	{
		char sz[19];

		stlsoft::integer_to_hex_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), *i);
	}}
	counter.stop();
	t1 = counter.get_microseconds();

	::srand(10101);
	counter.start();
	{ for(std::vector<unsigned>::const_iterator i = values.begin(); i != values.end(); ++i)
	{
		char sz[19];

		call_snprintf(&sz[0], STLSOFT_NUM_ELEMENTS(sz), "%x", *i);
	}}
	counter.stop();
	t2 = counter.get_microseconds();

#ifdef _DEBUG
	printf("i2hs:    %lu\n", static_cast<unsigned long>(t1));
	printf("sprintf: %lu\n", static_cast<unsigned long>(t2));
#else /* ? _DEBUG */
	STLSOFT_SUPPRESS_UNUSED(t1);
	STLSOFT_SUPPRESS_UNUSED(t2);
#endif /* _DEBUG */
}

static void test_1_6()
{
	::srand(10101);

	{ for(unsigned i = 0; i != 100000; ++i)
	{
		char		sz1[19];
		char		sz2[19];
		unsigned	value	=	static_cast<unsigned>(rand()) * static_cast<unsigned>(rand());
		char const*	result	=	stlsoft::integer_to_hex_string(&sz2[0], STLSOFT_NUM_ELEMENTS(sz2), value, "0x");

		call_snprintf(&sz1[0], STLSOFT_NUM_ELEMENTS(sz1), "0x%x", value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, result);
	}}
}

static void test_1_7()
{
	::srand(10101);

	{ for(uint64_t i = 0; i != 100/* 000 */; ++i)
	{
		char		sz1[19];
		char		sz2[19];
		uint64_t	value	=	static_cast<uint64_t>(rand()) * static_cast<uint64_t>(rand()) * static_cast<uint64_t>(rand());
		char const*	result	=	stlsoft::integer_to_hex_string(&sz2[0], STLSOFT_NUM_ELEMENTS(sz2), value);

		call_snprintf(&sz1[0], STLSOFT_NUM_ELEMENTS(sz1), "%x%08x", static_cast<uint32_t>(value >> 32), value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, result);
	}}
}

static void test_1_8()
{
}

static void test_1_9()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
