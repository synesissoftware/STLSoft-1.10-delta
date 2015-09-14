/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.time.casts.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.time.casts project.
 *
 * Created:     8th April 2014
 * Updated:     26th May 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/time/time_cast.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <winstl/time/comparison_functions.h>
#include <winstl/time/elicitation_functions.h>
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Custom macros
 */

#define XTESTS_TEST_TIME_EQUAL_(h, m, s, ms, tp, r)							\
																			\
	test_time_equal_((r), (tp), (h), (m), (s), (ms), __FILE__, __LINE__)

#define XTESTS_TEST_TIME_EQUAL_TM_(h, m, s, ms, tp, am, pm, r)				\
																			\
	test_time_equal_tm_((r), (tp), (am), (pm), (h), (m), (s), (ms), __FILE__, __LINE__)

#define test_time_equal_(r, tp, h, m, s, ms, file, line)					\
																			\
	do																		\
	{																		\
		SYSTEMTIME const t = {												\
			2012															\
		,	7																\
		,	-1																\
		,	28																\
		,	(h)																\
		,	(m)																\
		,	(s)																\
		,	(ms)															\
		};																	\
		CHAR buf[120] = "";													\
		int const rv = winstl::GetTimeFormat_msA(							\
			LOCALE_SYSTEM_DEFAULT											\
		,	0																\
		,	&t																\
		,	(tp)															\
		,	buf																\
		,	STLSOFT_NUM_ELEMENTS(buf)										\
		);																	\
																			\
	    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed()) &&			\
		XTESTS_NS_C_QUAL(xtests_testMultibyteStrings)(file, line, XTESTS_GET_FUNCTION_(), "", (r), (buf), XTESTS_NS_C_QUAL(xtestsComparisonEqual)));	\
	} while(0)

#define test_time_equal_tm_(r, tp, am, pm, h, m, s, ms, file, line)			\
																			\
	do																		\
	{																		\
		SYSTEMTIME const t = {												\
			2012															\
		,	7																\
		,	-1																\
		,	28																\
		,	(h)																\
		,	(m)																\
		,	(s)																\
		,	(ms)															\
		};																	\
		CHAR buf[120] = "";													\
		LPCTSTR timeMarkers[2] = { (am), (pm) };							\
		int const rv = winstl::GetTimeFormat_msExA(							\
			LOCALE_SYSTEM_DEFAULT											\
		,	0																\
		,	&t																\
		,	(tp)															\
		,	&timeMarkers													\
		,	buf																\
		,	STLSOFT_NUM_ELEMENTS(buf)										\
		);																	\
																			\
	    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed()) &&			\
		XTESTS_NS_C_QUAL(xtests_testMultibyteStrings)(file, line, XTESTS_GET_FUNCTION_(), "", (r), (buf), XTESTS_NS_C_QUAL(xtestsComparisonEqual)));	\
	} while(0)

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_cast_SYSTEMTIME_to_FILETIME(void);
	static void test_cast_SYSTEMTIME_to_SYSTEMTIME(void);
	static void test_cast_FILETIME_to_SYSTEMTIME(void);
	static void test_cast_FILETIME_to_FILETIME(void);
	static void test_1_12(void);
	static void test_1_13(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.winstl.time.casts", verbosity))
	{
		XTESTS_RUN_CASE(test_cast_SYSTEMTIME_to_FILETIME);
		XTESTS_RUN_CASE(test_cast_SYSTEMTIME_to_SYSTEMTIME);
		XTESTS_RUN_CASE(test_cast_FILETIME_to_SYSTEMTIME);
		XTESTS_RUN_CASE(test_cast_FILETIME_to_FILETIME);
		XTESTS_RUN_CASE(test_1_12);
		XTESTS_RUN_CASE(test_1_13);

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
	using winstl::uint64_t;

	using winstl::winstl_C_get_local_time_as_SYSTEMTIME;
	using winstl::winstl_C_get_local_time_as_FILETIME;
	using winstl::winstl_C_get_UTC_time_as_SYSTEMTIME;
	using winstl::winstl_C_get_UTC_time_as_FILETIME;

	using winstl::get_local_time_as_SYSTEMTIME;
	using winstl::get_local_time_as_FILETIME;
	using winstl::get_UTC_time_as_SYSTEMTIME;
	using winstl::get_UTC_time_as_FILETIME;



static void test_cast_SYSTEMTIME_to_FILETIME()
{
	FILETIME const		expected	=	winstl::get_time(::GetSystemTimeAsFileTime);
	SYSTEMTIME const	actual_st	=	winstl::get_time(::GetSystemTime);
	FILETIME const		actual		=	winstl::time_cast<FILETIME>(actual_st);

	XTESTS_TEST_INTEGER_LESS(100, winstl::absolute_difference_in_milliseconds(expected, actual));
}

static void test_cast_SYSTEMTIME_to_SYSTEMTIME()
{
	SYSTEMTIME const	expected	=	winstl::get_time(::GetSystemTime);
	SYSTEMTIME const	actual_st	=	winstl::get_time(::GetSystemTime);
	SYSTEMTIME const	actual		=	winstl::time_cast<SYSTEMTIME>(actual_st);

	XTESTS_TEST_INTEGER_LESS(100, winstl::absolute_difference_in_milliseconds(expected, actual));
}

static void test_cast_FILETIME_to_SYSTEMTIME()
{
	SYSTEMTIME const	expected	=	winstl::get_time(::GetSystemTime);
	FILETIME const		actual_ft	=	winstl::get_time(::GetSystemTimeAsFileTime);
	SYSTEMTIME const	actual		=	winstl::time_cast<SYSTEMTIME>(actual_ft);

	XTESTS_TEST_INTEGER_LESS(100, winstl::absolute_difference_in_milliseconds(expected, actual));
}

static void test_cast_FILETIME_to_FILETIME()
{
	FILETIME const		expected	=	winstl::get_time(::GetSystemTimeAsFileTime);
	FILETIME const		actual_ft	=	winstl::get_time(::GetSystemTimeAsFileTime);
	FILETIME const		actual		=	winstl::time_cast<FILETIME>(actual_ft);

	XTESTS_TEST_INTEGER_LESS(100, winstl::absolute_difference_in_milliseconds(expected, actual));
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
