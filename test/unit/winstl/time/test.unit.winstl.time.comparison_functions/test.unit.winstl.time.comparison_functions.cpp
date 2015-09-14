/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.time.comparison_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.time.comparison_functions project.
 *
 * Created:     8th April 2014
 * Updated:     1st June 2014
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

#include <winstl/time/comparison_functions.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <winstl/shims/conversion/to_FILETIME.hpp>
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

	static void test_same_instance_SYSTEMTIME(void);
	static void test_same_time_SYSTEMTIME(void);
	static void test_different_ms_SYSTEMTIME(void);
	static void test_different_s_SYSTEMTIME(void);
	static void test_different_m_SYSTEMTIME(void);
	static void test_different_h_SYSTEMTIME(void);

	static void test_same_instance_FILETIME(void);
	static void test_same_time_FILETIME(void);
	static void test_different_ms_FILETIME(void);
	static void test_different_s_FILETIME(void);
	static void test_different_m_FILETIME(void);
	static void test_different_h_FILETIME(void);

	static void test_same_time_SYSTEMTIME_FILETIME(void);
	static void test_different_ms_SYSTEMTIME_FILETIME(void);
	static void test_different_s_SYSTEMTIME_FILETIME(void);
	static void test_different_m_SYSTEMTIME_FILETIME(void);
	static void test_different_h_SYSTEMTIME_FILETIME(void);

	static void test_1_5(void);
	static void test_1_6(void);
	static void test_1_7(void);
	static void test_1_8(void);
	static void test_1_9(void);
	static void test_1_10(void);
	static void test_1_11(void);
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

	if(XTESTS_START_RUNNER("test.unit.winstl.time.comparison_functions", verbosity))
	{
		XTESTS_RUN_CASE(test_same_instance_SYSTEMTIME);
		XTESTS_RUN_CASE(test_same_time_SYSTEMTIME);
		XTESTS_RUN_CASE(test_different_ms_SYSTEMTIME);
		XTESTS_RUN_CASE(test_different_s_SYSTEMTIME);
		XTESTS_RUN_CASE(test_different_m_SYSTEMTIME);
		XTESTS_RUN_CASE(test_different_h_SYSTEMTIME);

		XTESTS_RUN_CASE(test_same_instance_FILETIME);
		XTESTS_RUN_CASE(test_same_time_FILETIME);
		XTESTS_RUN_CASE(test_different_ms_FILETIME);
		XTESTS_RUN_CASE(test_different_s_FILETIME);
		XTESTS_RUN_CASE(test_different_m_FILETIME);
		XTESTS_RUN_CASE(test_different_h_FILETIME);

		XTESTS_RUN_CASE(test_same_time_SYSTEMTIME_FILETIME);
		XTESTS_RUN_CASE(test_different_ms_SYSTEMTIME_FILETIME);
		XTESTS_RUN_CASE(test_different_s_SYSTEMTIME_FILETIME);
		XTESTS_RUN_CASE(test_different_m_SYSTEMTIME_FILETIME);
		XTESTS_RUN_CASE(test_different_h_SYSTEMTIME_FILETIME);

		XTESTS_RUN_CASE(test_1_5);
		XTESTS_RUN_CASE(test_1_6);
		XTESTS_RUN_CASE(test_1_7);
		XTESTS_RUN_CASE(test_1_8);
		XTESTS_RUN_CASE(test_1_9);
		XTESTS_RUN_CASE(test_1_10);
		XTESTS_RUN_CASE(test_1_11);
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

static void test_same_instance_SYSTEMTIME()
{
	SYSTEMTIME	t1 = { 0 };

	t1.wYear			=	2014;
	t1.wMonth			=	4;
	t1.wDay				=	8;
	t1.wHour			=	7;
	t1.wMinute			=	20;
	t1.wSecond			=	23;
	t1.wMilliseconds	=	0;

	int const		cr	=	winstl::compare(t1, t1);

	XTESTS_TEST_INTEGER_EQUAL(0, cr);

	uint64_t const	dus	=	winstl::absolute_difference_in_microseconds(t1, t1);
	uint64_t const	dms	=	winstl::absolute_difference_in_milliseconds(t1, t1);
	uint64_t const	ds	=	winstl::absolute_difference_in_seconds(t1, t1);

	XTESTS_TEST_INTEGER_EQUAL(0u, dus);
	XTESTS_TEST_INTEGER_EQUAL(0u, dms);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds);
}

static void test_same_time_SYSTEMTIME()
{
	SYSTEMTIME	t1 = { 0 };
	SYSTEMTIME	t2 = { 0 };

	t1.wYear			=	t2.wYear			= 2014;
	t1.wMonth			=	t2.wMonth			= 4;
	t1.wDay				=	t2.wDay				= 8;
	t1.wHour			=	t2.wHour			= 7;
	t1.wMinute			=	t2.wMinute			= 20;
	t1.wSecond			=	t2.wSecond			= 23;
	t1.wMilliseconds	=	t2.wMilliseconds	= 0;

	int const		cr1	=	winstl::compare(t1, t2);
	int const		cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(0, cr1);
	XTESTS_TEST_INTEGER_EQUAL(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(0u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(0u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(0u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(0u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds2);
}

static void test_different_ms_SYSTEMTIME()
{
	SYSTEMTIME	t1 = { 0 };
	SYSTEMTIME	t2 = { 0 };

	t1.wYear			=	t2.wYear			= 2014;
	t1.wMonth			=	t2.wMonth			= 4;
	t1.wDay				=	t2.wDay				= 8;
	t1.wHour			=	t2.wHour			= 7;
	t1.wMinute			=	t2.wMinute			= 20;
	t1.wSecond			=	t2.wSecond			= 23;
	t1.wMilliseconds	=						  0;
							t2.wMilliseconds	= 1;

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(1000u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(1000u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(1u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(1u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds2);
}

static void test_different_s_SYSTEMTIME()
{
	SYSTEMTIME	t1 = { 0 };
	SYSTEMTIME	t2 = { 0 };

	t1.wYear			=	t2.wYear			= 2014;
	t1.wMonth			=	t2.wMonth			= 4;
	t1.wDay				=	t2.wDay				= 8;
	t1.wHour			=	t2.wHour			= 7;
	t1.wMinute			=	t2.wMinute			= 20;
	t1.wSecond			=						  23;
							t2.wSecond			= 24;
	t1.wMilliseconds	=	t2.wMilliseconds	= 0;

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(1000000u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(1000000u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(1000u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(1000u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(1u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(1u, ds2);
}

static void test_different_m_SYSTEMTIME()
{
	SYSTEMTIME	t1 = { 0 };
	SYSTEMTIME	t2 = { 0 };

	t1.wYear			=	t2.wYear			= 2014;
	t1.wMonth			=	t2.wMonth			= 4;
	t1.wDay				=	t2.wDay				= 8;
	t1.wHour			=	t2.wHour			= 7;
	t1.wMinute			=						  10;
							t2.wMinute			= 11;
	t1.wSecond			=	t2.wSecond			= 23;
	t1.wMilliseconds	=	t2.wMilliseconds	= 0;

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(60000000u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(60000000u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(60000u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(60000u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(60u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(60u, ds2);
}

static void test_different_h_SYSTEMTIME()
{
	SYSTEMTIME	t1 = { 0 };
	SYSTEMTIME	t2 = { 0 };

	t1.wYear			=	t2.wYear			= 2014;
	t1.wMonth			=	t2.wMonth			= 4;
	t1.wDay				=	t2.wDay				= 8;
	t1.wHour			=						  7;
							t2.wHour			= 8;
	t1.wMinute			=	t2.wMinute			= 10;
	t1.wSecond			=	t2.wSecond			= 23;
	t1.wMilliseconds	=	t2.wMilliseconds	= 0;

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(3600000000u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(3600000000u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(3600000u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(3600000u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(3600u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(3600u, ds2);
}

static void test_same_instance_FILETIME()
{
	SYSTEMTIME		t1_ = { 0 };

	t1_.wYear			=	2014;
	t1_.wMonth			=	4;
	t1_.wDay			=	8;
	t1_.wHour			=	7;
	t1_.wMinute			=	20;
	t1_.wSecond			=	23;
	t1_.wMilliseconds	=	0;

	FILETIME		t1	=	winstl::to_FILETIME(t1_);

	int const		cr	=	winstl::compare(t1, t1);

	XTESTS_TEST_INTEGER_EQUAL(0, cr);

	uint64_t const	dus	=	winstl::absolute_difference_in_microseconds(t1, t1);
	uint64_t const	dms	=	winstl::absolute_difference_in_milliseconds(t1, t1);
	uint64_t const	ds	=	winstl::absolute_difference_in_seconds(t1, t1);

	XTESTS_TEST_INTEGER_EQUAL(0u, dus);
	XTESTS_TEST_INTEGER_EQUAL(0u, dms);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds);
}

static void test_same_time_FILETIME()
{
	SYSTEMTIME	t1_ = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1_.wYear			=	t2_.wYear			= 2014;
	t1_.wMonth			=	t2_.wMonth			= 4;
	t1_.wDay			=	t2_.wDay			= 8;
	t1_.wHour			=	t2_.wHour			= 7;
	t1_.wMinute			=	t2_.wMinute			= 20;
	t1_.wSecond			=	t2_.wSecond			= 23;
	t1_.wMilliseconds	=	t2_.wMilliseconds	= 0;

	FILETIME		t1	=	winstl::to_FILETIME(t1_);
	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const		cr1	=	winstl::compare(t1, t2);
	int const		cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(0, cr1);
	XTESTS_TEST_INTEGER_EQUAL(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(0u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(0u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(0u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(0u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds2);
}

static void test_different_ms_FILETIME()
{
	SYSTEMTIME	t1_ = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1_.wYear			=	t2_.wYear			= 2014;
	t1_.wMonth			=	t2_.wMonth			= 4;
	t1_.wDay			=	t2_.wDay			= 8;
	t1_.wHour			=	t2_.wHour			= 7;
	t1_.wMinute			=	t2_.wMinute			= 20;
	t1_.wSecond			=	t2_.wSecond			= 23;
	t1_.wMilliseconds	=						  0;
							t2_.wMilliseconds	= 1;

	FILETIME		t1	=	winstl::to_FILETIME(t1_);
	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(1000u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(1000u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(1u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(1u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(0u, ds2);
}

static void test_different_s_FILETIME()
{
	SYSTEMTIME	t1_ = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1_.wYear			=	t2_.wYear			= 2014;
	t1_.wMonth			=	t2_.wMonth			= 4;
	t1_.wDay			=	t2_.wDay			= 8;
	t1_.wHour			=	t2_.wHour			= 7;
	t1_.wMinute			=	t2_.wMinute			= 20;
	t1_.wSecond			=						  23;
							t2_.wSecond			= 24;
	t1_.wMilliseconds	=	t2_.wMilliseconds	= 0;

	FILETIME		t1	=	winstl::to_FILETIME(t1_);
	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(1000000u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(1000000u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(1000u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(1000u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(1u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(1u, ds2);
}

static void test_different_m_FILETIME()
{
	SYSTEMTIME	t1_ = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1_.wYear			=	t2_.wYear			= 2014;
	t1_.wMonth			=	t2_.wMonth			= 4;
	t1_.wDay			=	t2_.wDay			= 8;
	t1_.wHour			=	t2_.wHour			= 7;
	t1_.wMinute			=						  10;
							t2_.wMinute			= 11;
	t1_.wSecond			=	t2_.wSecond			= 23;
	t1_.wMilliseconds	=	t2_.wMilliseconds	= 0;

	FILETIME		t1	=	winstl::to_FILETIME(t1_);
	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(60000000u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(60000000u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(60000u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(60000u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(60u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(60u, ds2);
}

static void test_different_h_FILETIME()
{
	SYSTEMTIME	t1_ = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1_.wYear			=	t2_.wYear			= 2014;
	t1_.wMonth			=	t2_.wMonth			= 4;
	t1_.wDay			=	t2_.wDay			= 8;
	t1_.wHour			=						  7;
							t2_.wHour			= 8;
	t1_.wMinute			=	t2_.wMinute			= 10;
	t1_.wSecond			=	t2_.wSecond			= 23;
	t1_.wMilliseconds	=	t2_.wMilliseconds	= 0;

	FILETIME		t1	=	winstl::to_FILETIME(t1_);
	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);

	uint64_t const	dus1	=	winstl::absolute_difference_in_microseconds(t1, t2);
	uint64_t const	dus2	=	winstl::absolute_difference_in_microseconds(t2, t1);
	uint64_t const	dms1	=	winstl::absolute_difference_in_milliseconds(t1, t2);
	uint64_t const	dms2	=	winstl::absolute_difference_in_milliseconds(t2, t1);
	uint64_t const	ds1		=	winstl::absolute_difference_in_seconds(t1, t2);
	uint64_t const	ds2		=	winstl::absolute_difference_in_seconds(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(3600000000u, dus1);
	XTESTS_TEST_INTEGER_EQUAL(3600000000u, dus2);
	XTESTS_TEST_INTEGER_EQUAL(3600000u, dms1);
	XTESTS_TEST_INTEGER_EQUAL(3600000u, dms2);
	XTESTS_TEST_INTEGER_EQUAL(3600u, ds1);
	XTESTS_TEST_INTEGER_EQUAL(3600u, ds2);
}

static void test_same_time_SYSTEMTIME_FILETIME()
{
	SYSTEMTIME		t1 = { 0 };

	t1.wYear			=	2014;
	t1.wMonth			=	4;
	t1.wDay				=	8;
	t1.wHour			=	7;
	t1.wMinute			=	20;
	t1.wSecond			=	23;
	t1.wMilliseconds	=	0;

	FILETIME		t2	=	winstl::to_FILETIME(t1);

	int const		cr1	=	winstl::compare(t1, t2);
	int const		cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_EQUAL(0, cr1);
	XTESTS_TEST_INTEGER_EQUAL(0, cr2);
}

static void test_different_ms_SYSTEMTIME_FILETIME()
{
	SYSTEMTIME	t1  = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1.wYear			=	t2_.wYear			= 2014;
	t1.wMonth			=	t2_.wMonth			= 4;
	t1.wDay				=	t2_.wDay			= 8;
	t1.wHour			=	t2_.wHour			= 7;
	t1.wMinute			=	t2_.wMinute			= 20;
	t1.wSecond			=	t2_.wSecond			= 23;
	t1.wMilliseconds	=						  0;
							t2_.wMilliseconds	= 1;

	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const		cr1	=	winstl::compare(t1, t2);
	int const		cr2	=	winstl::compare(t2, t1);

	XTESTS_TEST_INTEGER_LESS(0, cr1);
	XTESTS_TEST_INTEGER_GREATER(0, cr2);
}

static void test_different_s_SYSTEMTIME_FILETIME()
{
	SYSTEMTIME	t1  = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1.wYear			=	t2_.wYear			= 2014;
	t1.wMonth			=	t2_.wMonth			= 4;
	t1.wDay				=	t2_.wDay			= 8;
	t1.wHour			=	t2_.wHour			= 7;
	t1.wMinute			=	t2_.wMinute			= 20;
	t1.wSecond			=						  23;
							t2_.wSecond			= 24;
	t1.wMilliseconds	=	t2_.wMilliseconds	= 0;

	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const		cr1	=	winstl::compare(t1, t2);
	int const		cr2	=	winstl::compare(t2, t1);
}

static void test_different_m_SYSTEMTIME_FILETIME()
{
	SYSTEMTIME	t1  = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1.wYear			=	t2_.wYear			= 2014;
	t1.wMonth			=	t2_.wMonth			= 4;
	t1.wDay				=	t2_.wDay			= 8;
	t1.wHour			=	t2_.wHour			= 7;
	t1.wMinute			=						  10;
							t2_.wMinute			= 11;
	t1.wSecond			=	t2_.wSecond			= 23;
	t1.wMilliseconds	=	t2_.wMilliseconds	= 0;

	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const		cr1	=	winstl::compare(t1, t2);
	int const		cr2	=	winstl::compare(t2, t1);
}

static void test_different_h_SYSTEMTIME_FILETIME()
{
	SYSTEMTIME	t1  = { 0 };
	SYSTEMTIME	t2_ = { 0 };

	t1.wYear			=	t2_.wYear			= 2014;
	t1.wMonth			=	t2_.wMonth			= 4;
	t1.wDay				=	t2_.wDay			= 8;
	t1.wHour			=						  7;
							t2_.wHour			= 8;
	t1.wMinute			=	t2_.wMinute			= 10;
	t1.wSecond			=	t2_.wSecond			= 23;
	t1.wMilliseconds	=	t2_.wMilliseconds	= 0;

	FILETIME		t2	=	winstl::to_FILETIME(t2_);

	int const	cr1	=	winstl::compare(t1, t2);
	int const	cr2	=	winstl::compare(t2, t1);
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
