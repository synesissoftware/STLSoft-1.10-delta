/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.platformstl.time.datetime.cpp
 *
 * Purpose:     Implementation file for the XXXX project.
 *
 * Created:     7th May 2014
 * Updated:     9th May 2014
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

#include <platformstl/time/datetime.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/internal/safestr.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_types_exists(void);
    static void test_default_construction(void);
    static void test_construction_from_tm_pointer(void);
    static void test_construction_from_tm_reference(void);
    static void test_construction_from_timeval_reference(void);
    static void test_construction_from_SYSTEMTIME(void);
    static void test_construction_from_FILETIME(void);
    static void test_construction_with_current_time_local(void);
    static void test_construction_with_current_time_system(void);
    static void test_construction_with_current_date_local(void);
    static void test_construction_with_current_date_system(void);
    static void test_construction_with_current_date_local_with_milliseconds(void);
    static void test_construction_with_current_date_local_with_microseconds(void);
    static void test_construction_with_current_date_system_with_milliseconds(void);
    static void test_construction_with_current_date_system_with_microseconds(void);
    static void test_now_local(void);
    static void test_now_system(void);
    static void test_get_as_SYSTEMTIME(void);
    static void test_get_as_FILETIME(void);
    static void test_get_as_timeval(void);
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

    if(XTESTS_START_RUNNER("test.unit.platformstl.time.datetime", verbosity))
    {
        XTESTS_RUN_CASE(test_types_exists);
        XTESTS_RUN_CASE(test_default_construction);
        XTESTS_RUN_CASE(test_construction_from_tm_pointer);
        XTESTS_RUN_CASE(test_construction_from_tm_reference);
        XTESTS_RUN_CASE(test_construction_from_timeval_reference);
        XTESTS_RUN_CASE(test_construction_from_SYSTEMTIME);
        XTESTS_RUN_CASE(test_construction_from_FILETIME);
        XTESTS_RUN_CASE(test_construction_with_current_time_local);
        XTESTS_RUN_CASE(test_construction_with_current_time_system);
        XTESTS_RUN_CASE(test_construction_with_current_date_local);
        XTESTS_RUN_CASE(test_construction_with_current_date_system);
        XTESTS_RUN_CASE(test_construction_with_current_date_local_with_milliseconds);
        XTESTS_RUN_CASE(test_construction_with_current_date_local_with_microseconds);
        XTESTS_RUN_CASE(test_construction_with_current_date_system_with_milliseconds);
        XTESTS_RUN_CASE(test_construction_with_current_date_system_with_microseconds);
        XTESTS_RUN_CASE(test_now_local);
        XTESTS_RUN_CASE(test_now_system);
        XTESTS_RUN_CASE(test_get_as_SYSTEMTIME);
        XTESTS_RUN_CASE(test_get_as_FILETIME);
        XTESTS_RUN_CASE(test_get_as_timeval);
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
    using platformstl::datetime;

    inline
    int
    diff(
        int value1
    ,   int value2
    ,   int range
    )
    {
        if(0 != range)
        {
            value1 %= range;
            value2 %= range;
        }

        if(value1 < value2)
        {
            return value2 - value1;
        }
        else
        {
            return value1 - value2;
        }
    }

    inline
    struct tm
    get_gmtime()
    {
        time_t const            t   =   ::time(NULL);
#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
        struct tm               tm;
        int const               e   =   ::gmtime_s(&tm, &t);

        if(0 != e)
#else
        struct tm const* const  tm  =   ::gmtime(&t);
        int const               e   =   ::errno;

        if(NULL == tm)
#endif
        {
#ifdef _DEBUG
            // TODO: throw
#else /* ? _DEBUG */
# error
#endif /* _DEBUG */
        }

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
        return tm;
#else
        return *tm;
#endif
    }

    inline
    struct tm
    get_localtime()
    {
        time_t const            t   =   ::time(NULL);
#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
        struct tm               tm;
        int const               e   =   ::localtime_s(&tm, &t);

        if(0 != e)
#else
        struct tm const* const  tm  =   ::localtime(&t);
        int const               e   =   ::errno;

        if(NULL == tm)
#endif
        {
#ifdef _DEBUG
            // TODO: throw
#else /* ? _DEBUG */
# error
#endif /* _DEBUG */
        }

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
        return tm;
#else
        return *tm;
#endif
    }


static void test_types_exists()
{
    typeid(::platformstl::datetime);

    XTESTS_TEST_PASSED();
}

static void test_default_construction()
{
    datetime dt;

    XTESTS_TEST_INTEGER_EQUAL(0, dt.Year);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Month);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Day);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Microsecond);
}

static void test_construction_from_tm_pointer()
{
    struct tm const tm = get_localtime();

    datetime dt(&tm);

    XTESTS_TEST_INTEGER_EQUAL(tm.tm_year + 1900, dt.Year);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_mon, dt.Month);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_mday, dt.Day);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_hour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_min, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_sec, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Microsecond);
}

static void test_construction_from_tm_reference()
{
    struct tm const tm = get_localtime();

    datetime dt(tm);

    XTESTS_TEST_INTEGER_EQUAL(tm.tm_year + 1900, dt.Year);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_mon, dt.Month);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_mday, dt.Day);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_hour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_min, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(tm.tm_sec, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Microsecond);
}

static void test_construction_from_timeval_reference()
{
#ifdef PLATFORMSTL_OS_IS_UNIX
    struct tm const tm = get_gmtime();
    struct timeval  tv;

    ::gettimeofday(&tv, NULL);

    datetime dt(tv);

    XTESTS_TEST_BOOLEAN_TRUE(diff(tm.tm_year + 1900, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(tm.tm_mon, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(tm.tm_mday, dt.Day, 31) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(tm.tm_hour, dt.Hour, 24) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(tm.tm_min, dt.Minute, 60) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(tm.tm_sec, dt.Second, 60) < 2);
    XTESTS_TEST_INTEGER_EQUAL(tv.tv_usec, dt.Microsecond);

#endif /* PLATFORMSTL_OS_IS_UNIX */
}

static void test_construction_from_SYSTEMTIME()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetLocalTime(&st);

    datetime dt(st);

    XTESTS_TEST_INTEGER_EQUAL(st.wYear, dt.Year);
    XTESTS_TEST_INTEGER_EQUAL(st.wMonth, dt.Month);
    XTESTS_TEST_INTEGER_EQUAL(st.wDay, dt.Day);
    XTESTS_TEST_INTEGER_EQUAL(st.wHour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(st.wMinute, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(st.wSecond, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(st.wMilliseconds * 1000, dt.Microsecond);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_from_FILETIME()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetLocalTime(&st);

    FILETIME    ft;

    ::SystemTimeToFileTime(&st, &ft);

    datetime dt(ft);

    XTESTS_TEST_INTEGER_EQUAL(st.wYear, dt.Year);
    XTESTS_TEST_INTEGER_EQUAL(st.wMonth, dt.Month);
    XTESTS_TEST_INTEGER_EQUAL(st.wDay, dt.Day);
    XTESTS_TEST_INTEGER_EQUAL(st.wHour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(st.wMinute, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(st.wSecond, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(st.wMilliseconds, dt.Microsecond / 1000);
    XTESTS_TEST_INTEGER_EQUAL(st.wMilliseconds * 1000, dt.Microsecond);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_with_current_time_local()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetLocalTime(&st);

    datetime dt(st.wYear, st.wMonth, st.wDay, datetime::current_time_local());

    XTESTS_TEST_INTEGER_EQUAL(st.wYear, dt.Year);
    XTESTS_TEST_INTEGER_EQUAL(st.wMonth, dt.Month);
    XTESTS_TEST_INTEGER_EQUAL(st.wDay, dt.Day);

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wHour, dt.Hour, 24) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMinute, dt.Minute, 60) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wSecond, dt.Second, 60) < 2);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_with_current_time_system()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetSystemTime(&st);

    datetime dt(st.wYear, st.wMonth, st.wDay, datetime::current_time_system());

    XTESTS_TEST_INTEGER_EQUAL(st.wYear, dt.Year);
    XTESTS_TEST_INTEGER_EQUAL(st.wMonth, dt.Month);
    XTESTS_TEST_INTEGER_EQUAL(st.wDay, dt.Day);

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wHour, dt.Hour, 24) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMinute, dt.Minute, 60) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wSecond, dt.Second, 60) < 2);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_with_current_date_local()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetLocalTime(&st);

    datetime dt(datetime::current_date_local(), st.wHour, st.wMinute, st.wSecond);

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wYear, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMonth, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wDay, dt.Day, 31) < 2);

    XTESTS_TEST_INTEGER_EQUAL(st.wHour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(st.wMinute, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(st.wSecond, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Microsecond);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_with_current_date_system()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetSystemTime(&st);

    datetime dt(datetime::current_date_system(), st.wHour, st.wMinute, st.wSecond);

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wYear, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMonth, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wDay, dt.Day, 31) < 2);

    XTESTS_TEST_INTEGER_EQUAL(st.wHour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(st.wMinute, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(st.wSecond, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(0, dt.Microsecond);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_with_current_date_local_with_milliseconds()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetLocalTime(&st);

    datetime dt(datetime::current_date_local(), st.wHour, st.wMinute, st.wSecond, datetime::milliseconds(st.wMilliseconds));

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wYear, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMonth, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wDay, dt.Day, 31) < 2);

    XTESTS_TEST_INTEGER_EQUAL(st.wHour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(st.wMinute, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(st.wSecond, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(st.wMilliseconds * 1000, dt.Microsecond);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_with_current_date_local_with_microseconds()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetLocalTime(&st);

    datetime dt(datetime::current_date_local(), st.wHour, st.wMinute, st.wSecond, datetime::microseconds(st.wMilliseconds * 1000));

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wYear, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMonth, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wDay, dt.Day, 31) < 2);

    XTESTS_TEST_INTEGER_EQUAL(st.wHour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(st.wMinute, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(st.wSecond, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(st.wMilliseconds * 1000, dt.Microsecond);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_with_current_date_system_with_milliseconds()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetSystemTime(&st);

    datetime dt(datetime::current_date_system(), st.wHour, st.wMinute, st.wSecond, datetime::milliseconds(st.wMilliseconds));

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wYear, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMonth, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wDay, dt.Day, 31) < 2);

    XTESTS_TEST_INTEGER_EQUAL(st.wHour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(st.wMinute, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(st.wSecond, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(st.wMilliseconds * 1000, dt.Microsecond);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_construction_with_current_date_system_with_microseconds()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetSystemTime(&st);

    datetime dt(datetime::current_date_system(), st.wHour, st.wMinute, st.wSecond, datetime::microseconds(st.wMilliseconds * 1000));

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wYear, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMonth, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wDay, dt.Day, 31) < 2);

    XTESTS_TEST_INTEGER_EQUAL(st.wHour, dt.Hour);
    XTESTS_TEST_INTEGER_EQUAL(st.wMinute, dt.Minute);
    XTESTS_TEST_INTEGER_EQUAL(st.wSecond, dt.Second);
    XTESTS_TEST_INTEGER_EQUAL(st.wMilliseconds * 1000, dt.Microsecond);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_now_local()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetLocalTime(&st);

    datetime dt = datetime::now_local();

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wYear, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMonth, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wDay, dt.Day, 31) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wHour, dt.Hour, 24) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMinute, dt.Minute, 60) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wSecond, dt.Second, 60) < 2);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_now_system()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    SYSTEMTIME  st;

    ::GetSystemTime(&st);

    datetime dt = datetime::now_system();

    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wYear, dt.Year, 0) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMonth, dt.Month, 12) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wDay, dt.Day, 31) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wHour, dt.Hour, 24) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wMinute, dt.Minute, 60) < 2);
    XTESTS_TEST_BOOLEAN_TRUE(diff(st.wSecond, dt.Second, 60) < 2);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_get_as_SYSTEMTIME()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    datetime dt(2014, 5, 8, 16, 19, 35, datetime::microseconds(123456));

    SYSTEMTIME const st = dt.get(SYSTEMTIME());

    XTESTS_TEST_INTEGER_EQUAL(2014u, st.wYear);
    XTESTS_TEST_INTEGER_EQUAL(5u, st.wMonth);
    XTESTS_TEST_INTEGER_EQUAL(8u, st.wDay);
    XTESTS_TEST_INTEGER_EQUAL(16u, st.wHour);
    XTESTS_TEST_INTEGER_EQUAL(19u, st.wMinute);
    XTESTS_TEST_INTEGER_EQUAL(35u, st.wSecond);
    XTESTS_TEST_INTEGER_EQUAL(123u, st.wMilliseconds);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_get_as_FILETIME()
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    datetime dt(2014, 5, 8, 16, 19, 35, datetime::microseconds(123456));

    FILETIME const ft = dt.get(FILETIME());

    SYSTEMTIME st;

    ::FileTimeToSystemTime(&ft, &st);

    XTESTS_TEST_INTEGER_EQUAL(2014u, st.wYear);
    XTESTS_TEST_INTEGER_EQUAL(5u, st.wMonth);
    XTESTS_TEST_INTEGER_EQUAL(8u, st.wDay);
    XTESTS_TEST_INTEGER_EQUAL(16u, st.wHour);
    XTESTS_TEST_INTEGER_EQUAL(19u, st.wMinute);
    XTESTS_TEST_INTEGER_EQUAL(35u, st.wSecond);
    XTESTS_TEST_INTEGER_EQUAL(123u, st.wMilliseconds);
#endif /* PLATFORMSTL_OS_IS_WINDOWS */
}

static void test_get_as_timeval()
{
#ifdef PLATFORMSTL_OS_IS_UNIX

    struct timeval tv1;

    ::gettimeofday(&tv1, NULL);

    datetime dt1(tv1);

    datetime dt2(dt1.Year, dt1.Month, dt1.Day, dt1.Hour, dt1.Minute, dt1.Second, datetime::microseconds(dt1.Microsecond));

    struct timeval tv2 = dt2.get(timeval());

    XTESTS_TEST_INTEGER_EQUAL(tv1.tv_sec, tv2.tv_sec);
    XTESTS_TEST_INTEGER_EQUAL(tv1.tv_usec, tv2.tv_usec);

#endif /* PLATFORMSTL_OS_IS_UNIX */
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
