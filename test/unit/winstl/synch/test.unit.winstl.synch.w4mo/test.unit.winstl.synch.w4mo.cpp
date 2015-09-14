/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.synch.w4mo.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.synch.w4mo project.
 *
 * Created:     14th November 2008
 * Updated:     21st June 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#ifdef __GNUC__
# include <winstl/synch/process_mutex.hpp>
# include <winstl/synch/semaphore.hpp>
#endif

#include <winstl/synch/wait_functions.hpp>

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
#include <winstl/synch/process_mutex.hpp>
#include <winstl/synch/semaphore.hpp>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 */

#ifdef __BORLANDC__

# pragma warn -8008
# pragma warn -8066

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_specialisations(void);
	static void test_2_mx(void);
	static void test_null_handle(void);
	static void test_duplicate_handle(void);
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

	if(XTESTS_START_RUNNER("test.unit.winstl.synch.w4mo", verbosity))
	{
		XTESTS_RUN_CASE(test_specialisations);
		XTESTS_RUN_CASE(test_2_mx);
		XTESTS_RUN_CASE(test_null_handle);
		XTESTS_RUN_CASE(test_duplicate_handle);
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

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*winstl/*/wait_functions.hpp", NULL);
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

static void test_specialisations()
{
    winstl::process_mutex   mx1;
    winstl::process_mutex   mx2;
    winstl::process_mutex   mx3;
    winstl::process_mutex   mx4;
    winstl::semaphore       sem1(0, 10);
    winstl::semaphore       sem2(0, 10);
    winstl::semaphore       sem3(0, 10);
    winstl::semaphore       sem4(0, 10);
    HANDLE                  h1  =   NULL;
    HANDLE                  h2  =   NULL;

    if(0)
    {
        winstl::wait_for_multiple_objects(h1, h2, true, 10);
        winstl::wait_for_multiple_objects(h1, mx2, true, 10);
        winstl::wait_for_multiple_objects(h1, sem2, true, 10);
        winstl::wait_for_multiple_objects(mx1, h2, true, 10);
        winstl::wait_for_multiple_objects(mx1, mx2, true, 10);
        winstl::wait_for_multiple_objects(mx1, sem2, true, 10);
        winstl::wait_for_multiple_objects(sem1, h2, true, 10);
        winstl::wait_for_multiple_objects(sem1, mx2, true, 10);
        winstl::wait_for_multiple_objects(sem1, sem2, true, 10);

        winstl::wait_for_multiple_objects(mx1, mx2, mx3, mx4, sem1, sem2, sem3, sem4, h1, h2, true, 10);
    }
}

static void test_2_mx()
{
    winstl::process_mutex   mx1;
    winstl::process_mutex   mx2;
    winstl::process_mutex   mx3;
    winstl::process_mutex   mx4;
    winstl::semaphore       sem1(0, 10);
    winstl::semaphore       sem2(0, 10);
//    HANDLE                  h1  =   NULL;
//    HANDLE                  h2  =   NULL;

	XTESTS_TEST_INTEGER_NOT_EQUAL(WAIT_FAILED, winstl::wait_for_multiple_objects(mx1, mx2, true, 10));
}

static void test_null_handle()
{
	winstl::process_mutex	mx1;
	winstl::process_mutex	mx2;
	winstl::process_mutex	mx3;
	winstl::process_mutex	mx4;
	winstl::semaphore		sem1(0, 10);
	winstl::semaphore		sem2(0, 10);
//	HANDLE					h1	=	NULL;
	HANDLE					h2	=	NULL;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

	try
	{
		XTESTS_TEST_INTEGER_EQUAL(WAIT_FAILED, winstl::wait_for_multiple_objects(mx1, h2, true, 10));
		XTESTS_TEST_INTEGER_EQUAL(DWORD(ERROR_INVALID_HANDLE), ::GetLastError());
	}
	catch(winstl::null_wait_handle_exception& x)
	{
		XTESTS_TEST_INTEGER_EQUAL(1, x.waitIndex);
		XTESTS_TEST_INTEGER_EQUAL(DWORD(ERROR_INVALID_HANDLE), x.get_error_code());

		XTESTS_TEST_PASSED();
	}
	catch(std::bad_alloc& )
	{
		throw;
	}
	catch(std::exception& x)
	{
		XTESTS_TEST_FAIL_WITH_QUALIFIER("did not throw required exception", typeid(x).name());
	}

#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

	XTESTS_TEST_INTEGER_EQUAL(WAIT_FAILED, winstl::wait_for_multiple_objects(mx1, h2, true, 10));
	XTESTS_TEST_INTEGER_EQUAL(ERROR_INVALID_HANDLE, ::GetLastError());

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

static void test_duplicate_handle()
{
	winstl::process_mutex	mx1;
	winstl::process_mutex	mx2;
	winstl::process_mutex	mx3;
	winstl::process_mutex	mx4;
	winstl::semaphore		sem1(0, 10);
	winstl::semaphore		sem2(0, 10);
//	HANDLE					h1	=	NULL;
//	HANDLE					h2	=	NULL;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

	XTESTS_TEST_INTEGER_EQUAL(WAIT_FAILED, winstl::wait_for_multiple_objects(mx1, mx1, true, 10));
	XTESTS_TEST_INTEGER_EQUAL(ERROR_INVALID_PARAMETER, ::GetLastError());

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

static void test_1_4()
{
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
