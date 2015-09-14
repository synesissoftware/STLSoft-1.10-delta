/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.performance.performance_counter.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.performance.performance_counter project.
 *
 * Created:     11th August 2010
 * Updated:     12th August 2010
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

#include <platformstl/performance/performance_counter.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xCover Header Files */
#ifdef STLSOFT_USE_XCOVER
# include <xcover/xcover.h>
#endif /* STLSOFT_USE_XCOVER */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/rand.hpp>
#include <platformstl/synch/sleep_functions.h>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_ctor(void);
	static void test_start_stop(void);
	static void test_pause(void);
	static void test_1_04(void);
	static void test_1_05(void);
	static void test_1_06(void);
	static void test_1_07(void);
	static void test_1_08(void);
	static void test_1_09(void);
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

	if(XTESTS_START_RUNNER("test.component.winstl.performance.performance_counter", verbosity))
	{
		XTESTS_RUN_CASE(test_ctor);
		XTESTS_RUN_CASE(test_start_stop);
		XTESTS_RUN_CASE(test_pause);
		XTESTS_RUN_CASE(test_1_04);
		XTESTS_RUN_CASE(test_1_05);
		XTESTS_RUN_CASE(test_1_06);
		XTESTS_RUN_CASE(test_1_07);
		XTESTS_RUN_CASE(test_1_08);
		XTESTS_RUN_CASE(test_1_09);
		XTESTS_RUN_CASE(test_1_10);
		XTESTS_RUN_CASE(test_1_11);
		XTESTS_RUN_CASE(test_1_12);
		XTESTS_RUN_CASE(test_1_13);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*platformstl/*/performance_counter.hpp", NULL);
#endif /* STLSOFT_USE_XCOVER */

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

static void test_ctor()
{
	platformstl::performance_counter	counter;

	XTESTS_TEST_PASSED();
}

static void test_start_stop()
{
	platformstl::performance_counter	counter;

	counter.start();
	counter.stop();

	XTESTS_TEST_PASSED();
}

static void test_pause()
{
	platformstl::performance_counter	counter;

	counter.start();
	platformstl::micro_sleep(110000);
	counter.stop();

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(100, counter.get_milliseconds());
	XTESTS_TEST_INTEGER_LESS_OR_EQUAL(250, counter.get_milliseconds());
}

static void test_1_04()
{
	platformstl::performance_counter	counter;

	unsigned t = 100u + (stlsoft::rand<unsigned>() % 200);

	counter.start();
	platformstl::micro_sleep(t * 1000);
	counter.stop();

	platformstl::performance_counter::interval_type	ts	=	counter.get_seconds();
	platformstl::performance_counter::interval_type	tms	=	counter.get_milliseconds();
	platformstl::performance_counter::interval_type	tus	=	counter.get_microseconds();

	if(	ts < tms / 1000u ||
		tms < tus / 1000u)
	{
		::fprintf(stderr, "ts : %lu\n", static_cast<unsigned long>(ts));
		::fprintf(stderr, "tms: %lu\n", static_cast<unsigned long>(tms));
		::fprintf(stderr, "tus: %lu\n", static_cast<unsigned long>(tus));
	}

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(ts, tms / 1000u);
	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(tms, tus / 1000u);
}

static void test_1_05()
{

//	get_period_and_restart();
}

static void test_1_06()
{
}

static void test_1_07()
{
}

static void test_1_08()
{
}

static void test_1_09()
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
