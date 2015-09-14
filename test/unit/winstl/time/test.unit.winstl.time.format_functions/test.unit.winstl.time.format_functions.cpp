/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.time.format_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.time.format_functions project.
 *
 * Created:     30th July 2012
 * Updated:     30th July 2012
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

#include <winstl/time/format_functions.hpp>

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

	if(XTESTS_START_RUNNER("test.unit.winstl.time.format_functions", verbosity))
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
	SYSTEMTIME const t = { 
		2012
	,	7
	,	-1
	,	28
	,	0
	,	0
	,	0
	,	  1
	};

	CHAR	buf[120];

	int r = winstl::GetTimeFormat_msA(
		LOCALE_SYSTEM_DEFAULT
	,	0
	,	&t
	,	"h:m:s"
	,	buf
	,	STLSOFT_NUM_ELEMENTS(buf)
	);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0:0:0.001", buf);
}

static void test_1_1()
{
	SYSTEMTIME const t = { 
		2012
	,	7
	,	-1
	,	28
	,	0
	,	0
	,	0
	,	  1
	};

	CHAR	buf[120];

	int r = winstl::GetTimeFormat_msA(
		LOCALE_SYSTEM_DEFAULT
	,	0
	,	&t
	,	"hh:mm:ss"
	,	buf
	,	STLSOFT_NUM_ELEMENTS(buf)
	);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("00:00:00.001", buf);
}

static void test_1_2()
{
	SYSTEMTIME const t = { 
		2012
	,	7
	,	-1
	,	28
	,	1
	,	2
	,	3
	,	 45
	};

	CHAR	buf[120];

	int r = winstl::GetTimeFormat_msA(
		LOCALE_SYSTEM_DEFAULT
	,	0
	,	&t
	,	"hh:mm:ss"
	,	buf
	,	STLSOFT_NUM_ELEMENTS(buf)
	);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("01:02:03.045", buf);
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
	SYSTEMTIME const t = { 
		2012
	,	7
	,	-1
	,	28
	,	14
	,	25
	,	59
	,	  1
	};

	CHAR	buf[120];

	int r = winstl::GetTimeFormat_msA(
		LOCALE_SYSTEM_DEFAULT
	,	0
	,	&t
	,	"h:mm:ss tt"
	,	buf
	,	STLSOFT_NUM_ELEMENTS(buf)
	);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("2:25:59.001 pm", buf);
}

static void test_1_7()
{
	SYSTEMTIME const t = { 
		2012
	,	7
	,	-1
	,	28
	,	14
	,	25
	,	59
	,	  1
	};

	CHAR	buf[120];

	int r = winstl::GetTimeFormat_msA(
		LOCALE_SYSTEM_DEFAULT
	,	0
	,	&t
	,	"h:mm:ss t"
	,	buf
	,	STLSOFT_NUM_ELEMENTS(buf)
	);

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("2:25:59.001 p", buf);
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
	XTESTS_TEST_TIME_EQUAL_( 0,  0,  0,   0, "h:m:s",  "0:0:0.000");
	XTESTS_TEST_TIME_EQUAL_( 1,  2,  3,   4, "h:m:s",  "1:2:3.004");
	XTESTS_TEST_TIME_EQUAL_(13,  2,  3,   4, "h:m:s",  "1:2:3.004");
	XTESTS_TEST_TIME_EQUAL_(13,  2,  3,   4, "H:m:s", "13:2:3.004");
}

static void test_1_11()
{
	XTESTS_TEST_TIME_EQUAL_( 0,  0,  0,   0, "h:m", "0:0");
	XTESTS_TEST_TIME_EQUAL_( 1,  2,  3, 456, "h:m", "1:2");

	XTESTS_TEST_TIME_EQUAL_( 1,  2,  3, 456, "hh:mm", "01:02");

	XTESTS_TEST_TIME_EQUAL_(14,  2,  3, 456, "hh:mm", "02:02");
	XTESTS_TEST_TIME_EQUAL_(14,  2,  3, 456, "HH:mm", "14:02");
}

static void test_1_12()
{
}

static void test_1_13()
{
	XTESTS_TEST_TIME_EQUAL_TM_( 0,  0,  0,   0, "h:m:s tt", "am", "pm",    "0:0:0.000 am");
	XTESTS_TEST_TIME_EQUAL_TM_( 1,  2,  3,   4, "h:m:s tt", "am", "pm",    "1:2:3.004 am");
	XTESTS_TEST_TIME_EQUAL_TM_(13,  2,  3,   4, "h:m:s tt", "am", "pm",    "1:2:3.004 pm");
	XTESTS_TEST_TIME_EQUAL_TM_(13,  2,  3,   4, "H:m:s tt", "am", "pm",   "13:2:3.004 pm");

	XTESTS_TEST_TIME_EQUAL_TM_( 0,  0,  0,   0, "h:m:s tt", "XX", "postmeridian",    "0:0:0.000 XX");
	XTESTS_TEST_TIME_EQUAL_TM_( 1,  2,  3,   4, "h:m:s tt", "XX", "postmeridian",    "1:2:3.004 XX");
	XTESTS_TEST_TIME_EQUAL_TM_(13,  2,  3,   4, "h:m:s tt", "XX", "postmeridian",    "1:2:3.004 postmeridian");
	XTESTS_TEST_TIME_EQUAL_TM_(13,  2,  3,   4, "H:m:s tt", "XX", "postmeridian",   "13:2:3.004 postmeridian");
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
