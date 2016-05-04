/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/time/datetime.hpp
 *
 * Purpose:     Definition of the platformstl::datetime class
 *
 * Created:     7th May 2014
 * Updated:     9th October 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014-2015, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file platformstl/time/datetime.hpp
 *
 * \brief [C++ only] Definition of the platformstl::datetime
 *  class
 *   (\ref group__library__time "Time" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_TIME_HPP_DATETIME
#define PLATFORMSTL_INCL_PLATFORMSTL_TIME_HPP_DATETIME

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_TIME_HPP_DATETIME_MAJOR    0
# define PLATFORMSTL_VER_PLATFORMSTL_TIME_HPP_DATETIME_MINOR    1
# define PLATFORMSTL_VER_PLATFORMSTL_TIME_HPP_DATETIME_REVISION 6
# define PLATFORMSTL_VER_PLATFORMSTL_TIME_HPP_DATETIME_EDIT     8
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <platformstl/platformstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error platformstl::datetime cannot be used in a compilation unit in which exception support is suppressed
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */

#ifdef PLATFORMSTL_OS_IS_WINDOWS
# include <winstl/time/modification_functions.h>
#else
#endif

#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR
# include <stlsoft/error/conversion_error.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_CONVERSION_ERROR */
#ifndef STLSOFT_INCL_STLSOFT_TIME_HPP_TIMESPAN
# include <stlsoft/time/timespan.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_TIME_HPP_TIMESPAN */
#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_STLSOFT_TIME_UTIL_H_RAW_
# include <stlsoft/time/util/raw_.h>
#endif /* !STLSOFT_INCL_STLSOFT_TIME_UTIL_H_RAW_ */

#ifndef STLSOFT_INCL_MEMORY
# define STLSOFT_INCL_MEMORY
# include <memory>
#endif /* !STLSOFT_INCL_MEMORY */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_TIME
# define STLSOFT_INCL_H_TIME
# include <time.h>
#endif /* !STLSOFT_INCL_H_TIME */
#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <sys/time.h>
# if defined(_WIN32)
#  include <unixem/time.h>
# endif
#endif 

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */

namespace stlsoft
{
namespace platformstl_project
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** Specifies a date/time.
 */
class datetime
{
public: // Types
    typedef datetime                class_type;
    struct                          current_date_type;
    struct                          current_time_type;
    struct                          second_fragment_type;
private:
    enum time_locality
    {
            SystemLocality  =   0
        ,   LocalLocality   =   1
    };
public:
    struct current_date_type
    {
    private:
        friend class datetime;

    private:
        explicit current_date_type(time_locality locality)
            : Locality(locality)
        {}

    public:
        time_locality const Locality;
    };

    struct current_time_type
    {
    private:
        friend class datetime;

    private:
        explicit current_time_type(time_locality locality)
            : Locality(locality)
        {}

    public:
        time_locality const Locality;
    };

    struct second_fragment_type
    {
    private:
        friend class datetime;

    private:
        explicit second_fragment_type(int microseconds)
            : Microseconds(microseconds)
        {}

        int const Microseconds;
    };

public: // Construction
    datetime();
    ~datetime() stlsoft_throw_0();
    datetime(
        int                     year
    ,   int                     month
    ,   int                     dayOfMonth
    ,   int                     hour
    ,   int                     minute
    ,   int                     second
    ,   second_fragment_type    secondFragment
    );
    datetime(
        int                     year
    ,   int                     month
    ,   int                     dayOfMonth
    ,   int                     hour
    ,   int                     minute
    ,   int                     second
    );
    datetime(
        current_date_type       date
    ,   int                     hour
    ,   int                     minute
    ,   int                     second
    ,   second_fragment_type    secondFragment
    );
    datetime(
        current_date_type       date
    ,   int                     hour
    ,   int                     minute
    ,   int                     second
    );
    datetime(
        int                     year
    ,   int                     month
    ,   int                     dayOfMonth
    ,   current_time_type       time
    );
    datetime(struct tm const* tm);
    datetime(struct tm const& tm);
#if defined(PLATFORMSTL_OS_IS_UNIX) || \
    defined(_TIMEVAL_DEFINED)
    datetime(timeval const& tv);
#endif 
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    datetime(SYSTEMTIME const& st);
    datetime(FILETIME const& ft);
#endif

    static
    datetime
    now_system();

    static
    datetime
    now_local();

public: // Utility

    static
    current_date_type
    current_date_local()
    {
        return current_date_type(LocalLocality);
    };
    static
    current_date_type
    current_date_system()
    {
        return current_date_type(SystemLocality);
    };

    static
    current_time_type
    current_time_local()
    {
        return current_time_type(LocalLocality);
    };
    static
    current_time_type
    current_time_system()
    {
        return current_time_type(SystemLocality);
    };

    static
    second_fragment_type
    microseconds(
        int us
    )
    {
        return second_fragment_type(us);
    }

    static
    second_fragment_type
    milliseconds(
        int ms
    )
    {
        return second_fragment_type(ms * 1000);
    }

public: // Accessors

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    template <typename T>
    T get(T const&) const;

# if defined(PLATFORMSTL_OS_IS_UNIX) || \
     defined(_TIMEVAL_DEFINED)
    STLSOFT_TEMPLATE_SPECIALISATION
    timeval get<timeval>(
        timeval const&
    ) const
    {
        struct tm   tm = { 0 };

        tm.tm_year  =   this->Year  -   1900;
        tm.tm_mon   =   this->Month;
        tm.tm_mday  =   this->Day;
        tm.tm_hour  =   this->Hour;
        tm.tm_min   =   this->Minute;
        tm.tm_sec   =   this->Second;

        timeval tv;

#if 0
        tv.tv_sec   =   ::mktime(&tm);
#else /* ? 0 */
        tv.tv_sec   =   ::timegm(&tm);
#endif /* 0 */
        tv.tv_usec  =   this->Microsecond;

        if(-1 == tv.tv_sec)
        {
#ifdef STLSOFT_DEBUG
            // TODO: throw
#else /* ? STLSOFT_DEBUG */
# error 
#endif /* STLSOFT_DEBUG */
        }

        return tv;
    }
# endif 

# ifdef PLATFORMSTL_OS_IS_WINDOWS

    STLSOFT_TEMPLATE_SPECIALISATION
    SYSTEMTIME get<SYSTEMTIME>(
        SYSTEMTIME const&
    ) const
    {
        SYSTEMTIME st;

        st.wYear            =   this->Year;
        st.wMonth           =   this->Month;
        st.wDay             =   this->Day;
        st.wHour            =   this->Hour;
        st.wMinute          =   this->Minute;
        st.wSecond          =   this->Second;
        st.wMilliseconds    =   this->Microsecond / 1000;

        return st;
    }

    STLSOFT_TEMPLATE_SPECIALISATION
    FILETIME get<FILETIME>(
        FILETIME const&
    ) const
    {
        SYSTEMTIME st;

        st.wYear            =   this->Year;
        st.wMonth           =   this->Month;
        st.wDay             =   this->Day;
        st.wHour            =   this->Hour;
        st.wMinute          =   this->Minute;
        st.wSecond          =   this->Second;
        st.wMilliseconds    =   0;

        FILETIME ft;

        if(!::SystemTimeToFileTime(&st, &ft))
        {
            // TODO: use winstl:: conversion exception type

            STLSOFT_THROW_X(conversion_error("could not convert time value", EINVAL));
        }

        uint64_t ft64 = 0;

        ft64    |=  ft.dwHighDateTime;
        ft64    <<= 32;
        ft64    |=  ft.dwLowDateTime;

        ft64    +=  10 * this->Microsecond;

        ft.dwLowDateTime    =   (ft64 >>  0) & 0xFFFFFFFF;
        ft.dwHighDateTime   =   (ft64 >> 32) & 0xFFFFFFFF;

        return ft;
    }

# endif /* PLATFORMSTL_OS_IS_WINDOWS */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    template <typename T>
    T get() const
    {
        return get(T());
    }

private: // Implementation

    static
    int
    invoke_localtime(
        struct tm*      tm
    ,   time_t const*   t
    );

    static
    int
    invoke_gmtime(
        struct tm*      tm
    ,   time_t const*   t
    );

    static
    void*
    check_not_null_(
        struct tm const* tm
    );

    static
    void*
    make_time_context_(
        current_time_type tt
    );

    static
    void*
    make_date_context_(
        current_date_type dt
    );

#if defined(PLATFORMSTL_OS_IS_UNIX) || \
    defined(_TIMEVAL_DEFINED)
    static
    void*
    make_context_datetime_(
        timeval const& ft
    );
#endif /* PLATFORMSTL_OS_IS_UNIX */

#ifdef PLATFORMSTL_OS_IS_WINDOWS
    static
    void*
    make_context_SYSTEMTIME_(
        FILETIME const& ft
    );
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

    void
    delete_context_()
    {
        ::free(initContext);
        initContext = NULL;
    }

    struct date_context_type_
    {
        int year;
        int month;
        int day;
    };

    struct time_context_type_
    {
        int hour;
        int minute;
        int second;
        int microsecond;
    };

    struct datetime_context_type_
    {
        int year;
        int month;
        int day;

        int hour;
        int minute;
        int second;
        int microsecond;
    };

private: // Fields
    void*       initContext;
public:
    int const   Year;
    int const   Month;
    int const   Day;
    int const   Hour;
    int const   Minute;
    int const   Second;
    int const   Microsecond;
};

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

inline
datetime
operator +(
    datetime const& dt
,   timespan const& ts
)
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    FILETIME const  origin  =   dt.get(FILETIME());
    FILETIME        result;

    winstl::increment_FILETIME_us(&result, &origin, 0, 0, 0, 0, ts.Microseconds);

    return datetime(result);
#else
# error Not currently supported
#endif
}

inline
datetime
operator -(
    datetime const& dt
,   timespan const& ts
)
{
#ifdef PLATFORMSTL_OS_IS_WINDOWS
    FILETIME const  origin  =   dt.get(FILETIME());
    FILETIME        result;

    winstl::increment_FILETIME_us(&result, &origin, 0, 0, 0, 0, -ts.Microseconds);

    return datetime(result);
#else
# error Not currently supported
#endif
}

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
/* static */
int
datetime::invoke_localtime(
    struct tm*      tm
,   time_t const*   t
)
{
    STLSOFT_ASSERT(NULL != tm);
    STLSOFT_ASSERT(NULL != t);

    return ximpl_raw::localtime_(tm, t);
}

inline
/* static */
int
datetime::invoke_gmtime(
    struct tm*      tm
,   time_t const*   t
)
{
    STLSOFT_ASSERT(NULL != tm);
    STLSOFT_ASSERT(NULL != t);

    return ximpl_raw::gmtime_(tm, t);
}

inline
/* static */
void*
datetime::check_not_null_(
    struct tm const* tm
)
{
    STLSOFT_MESSAGE_ASSERT("pointer may not be null", NULL != tm);

    return NULL;
}

inline
/* static */
void*
datetime::make_date_context_(
    datetime::current_date_type tt
)
{
    time_t const        t   =   ::time(NULL);
    date_context_type_* dc  =   static_cast<date_context_type_*>(::malloc(sizeof(date_context_type_)));

    if(NULL == dc)
    {
        STLSOFT_THROW_X(std::bad_alloc());
    }

    int (* const pfn)(struct tm*, time_t const*) = (tt.Locality == LocalLocality) ? &class_type::invoke_localtime : &class_type::invoke_gmtime;

    struct tm       tm;
    int const       e   =   (*pfn)(&tm, &t);

    if(0 != e)
    {
#ifdef STLSOFT_DEBUG
        dc->year        =   0;
        dc->month       =   0;
        dc->day         =   0;
#else /* ? STLSOFT_DEBUG */
        ::free(dc);

        STLSOFT_THROW_X(conversion_error("could not convert time value", EINVAL));
#endif /* STLSOFT_DEBUG */
    }
    else
    {
        dc->year        =   tm.tm_year + 1900;
        dc->month       =   tm.tm_mon;
        dc->day         =   tm.tm_mday;
    }

    return dc;
}

inline
/* static */
void*
datetime::make_time_context_(
    datetime::current_time_type tt
)
{
    time_t const                t   =   ::time(NULL);
    time_context_type_* const   tc  =   static_cast<time_context_type_*>(::malloc(sizeof(time_context_type_)));

    if(NULL == tc)
    {
        STLSOFT_THROW_X(std::bad_alloc());
    }

    int (* const pfn)(struct tm*, time_t const*) = (tt.Locality == LocalLocality) ? &class_type::invoke_localtime : &class_type::invoke_gmtime;

    struct tm       tm;
    int const       e   =   (*pfn)(&tm, &t);

    if(0 != e)
    {
#ifdef STLSOFT_DEBUG
        tc->hour        =   0;
        tc->minute      =   0;
        tc->second      =   0;
        tc->microsecond =   0;
#else /* ? STLSOFT_DEBUG */
        ::free(tc);

        STLSOFT_THROW_X(conversion_error("could not convert time value", EINVAL));
#endif /* STLSOFT_DEBUG */
    }
    else
    {
        tc->hour        =   tm.tm_hour;
        tc->minute      =   tm.tm_min;
        tc->second      =   tm.tm_sec;
        tc->microsecond =   0;
    }

    return tc;
}

#if defined(PLATFORMSTL_OS_IS_UNIX) || \
    defined(_TIMEVAL_DEFINED)
inline
/* static */
void*
datetime::make_context_datetime_(
    timeval const& tv
)
{
    datetime_context_type_* const dtc = static_cast<datetime_context_type_*>(::malloc(sizeof(datetime_context_type_)));

    if(NULL == dtc)
    {
        STLSOFT_THROW_X(std::bad_alloc());
    }

    time_t const    t   =   tv.tv_sec;
    struct tm       tm;
    int const       e   =   invoke_gmtime(&tm, &t);

    if(0 != e)
    {
#ifdef STLSOFT_DEBUG
        dtc->year           =   0;
        dtc->month          =   0;
        dtc->day            =   0;

        dtc->hour           =   0;
        dtc->minute         =   0;
        dtc->second         =   0;
        dtc->microsecond    =   0;
#else /* ? STLSOFT_DEBUG */
        ::free(dtc);

        throw ????;
#endif /* STLSOFT_DEBUG */
    }
    else
    {
        dtc->year           =   tm.tm_year + 1900;
        dtc->month          =   tm.tm_mon;
        dtc->day            =   tm.tm_mday;

        dtc->hour           =   tm.tm_hour;
        dtc->minute         =   tm.tm_min;
        dtc->second         =   tm.tm_sec;
        dtc->microsecond    =   tv.tv_usec;
    }

    return dtc;
}
#endif /* PLATFORMSTL_OS_IS_UNIX */


#ifdef PLATFORMSTL_OS_IS_WINDOWS
inline
/* static */
void*
datetime::make_context_SYSTEMTIME_(
    FILETIME const& ft
)
{
    datetime_context_type_* const dtc = static_cast<datetime_context_type_*>(::malloc(sizeof(datetime_context_type_)));

    if(NULL == dtc)
    {
        STLSOFT_THROW_X(std::bad_alloc());
    }

    SYSTEMTIME st;

    if(!::FileTimeToSystemTime(&ft, &st))
    {
#ifdef STLSOFT_DEBUG
        dtc->year           =   0;
        dtc->month          =   0;
        dtc->day            =   0;

        dtc->hour           =   0;
        dtc->minute         =   0;
        dtc->second         =   0;
        dtc->microsecond    =   0;
#else /* ? STLSOFT_DEBUG */
        ::free(dtc);

        STLSOFT_THROW_X(conversion_error("could not convert time value", EINVAL));
#endif /* STLSOFT_DEBUG */
    }
    else
    {
        dtc->year           =   st.wYear;
        dtc->month          =   st.wMonth;
        dtc->day            =   st.wDay;

        dtc->hour           =   st.wHour;
        dtc->minute         =   st.wMinute;
        dtc->second         =   st.wSecond;

        uint64_t ft64 = 0;

        ft64    |=  ft.dwHighDateTime;
        ft64    <<= 32;
        ft64    |=  ft.dwLowDateTime;

        ft64    %=  10000000;
        ft64    /=  10;

#if 0
        dtc->microsecond    =   st.wMilliseconds * 1000;
#else /* ? 0 */
        dtc->microsecond    =   static_cast<int>(ft64);
#endif /* 0 */
    }

    return dtc;
}
#endif /* PLATFORMSTL_OS_IS_WINDOWS */



inline
datetime::datetime()
    : initContext(NULL)
    , Year(0)
    , Month(0)
    , Day(0)
    , Hour(0)
    , Minute(0)
    , Second(0)
    , Microsecond(0)
{}

inline
datetime::~datetime() stlsoft_throw_0()
{
    STLSOFT_ASSERT(NULL == initContext);
}

inline
datetime::datetime(
    int                     year
,   int                     month
,   int                     dayOfMonth
,   int                     hour
,   int                     minute
,   int                     second
)
    : initContext(NULL)
    , Year(year)
    , Month(month)
    , Day(dayOfMonth)
    , Hour(hour)
    , Minute(minute)
    , Second(second)
    , Microsecond(0)
{}

inline
datetime::datetime(
    int                     year
,   int                     month
,   int                     dayOfMonth
,   int                     hour
,   int                     minute
,   int                     second
,   second_fragment_type    secondFragment
)
    : initContext(NULL)
    , Year(year)
    , Month(month)
    , Day(dayOfMonth)
    , Hour(hour)
    , Minute(minute)
    , Second(second)
    , Microsecond(secondFragment.Microseconds)
{}

inline
datetime::datetime(
    current_date_type       date
,   int                     hour
,   int                     minute
,   int                     second
,   second_fragment_type    secondFragment
)
    : initContext(make_date_context_(date))
    , Year(static_cast<date_context_type_ const*>(initContext)->year)
    , Month(static_cast<date_context_type_ const*>(initContext)->month)
    , Day(static_cast<date_context_type_ const*>(initContext)->day)
    , Hour(hour)
    , Minute(minute)
    , Second(second)
    , Microsecond(secondFragment.Microseconds)
{
    delete_context_();
}

inline
datetime::datetime(
    current_date_type       date
,   int                     hour
,   int                     minute
,   int                     second
)
    : initContext(make_date_context_(date))
    , Year(static_cast<date_context_type_ const*>(initContext)->year)
    , Month(static_cast<date_context_type_ const*>(initContext)->month)
    , Day(static_cast<date_context_type_ const*>(initContext)->day)
    , Hour(hour)
    , Minute(minute)
    , Second(second)
    , Microsecond(0)
{
    delete_context_();
}

inline
datetime::datetime(
    int                     year
,   int                     month
,   int                     dayOfMonth
,   current_time_type       time
)
    : initContext(make_time_context_(time))
    , Year(year)
    , Month(month)
    , Day(dayOfMonth)
    , Hour(static_cast<time_context_type_ const*>(initContext)->hour)
    , Minute(static_cast<time_context_type_ const*>(initContext)->minute)
    , Second(static_cast<time_context_type_ const*>(initContext)->second)
    , Microsecond(static_cast<time_context_type_ const*>(initContext)->microsecond)
{
    delete_context_();
}

inline
datetime::datetime(struct tm const* tm)
    : initContext(check_not_null_(tm))
    , Year(1900 + tm->tm_year)
    , Month(tm->tm_mon)
    , Day(tm->tm_mday)
    , Hour(tm->tm_hour)
    , Minute(tm->tm_min)
    , Second(tm->tm_sec)
    , Microsecond(0)
{}

inline
datetime::datetime(struct tm const& tm)
    : initContext(NULL)
    , Year(1900 + tm.tm_year)
    , Month(tm.tm_mon)
    , Day(tm.tm_mday)
    , Hour(tm.tm_hour)
    , Minute(tm.tm_min)
    , Second(tm.tm_sec)
    , Microsecond(0)
{}

#if defined(PLATFORMSTL_OS_IS_UNIX) || \
    defined(_TIMEVAL_DEFINED)
inline
datetime::datetime(timeval const& tv)
    : initContext(make_context_datetime_(tv))
    , Year(static_cast<datetime_context_type_ const*>(initContext)->year)
    , Month(static_cast<datetime_context_type_ const*>(initContext)->month)
    , Day(static_cast<datetime_context_type_ const*>(initContext)->day)
    , Hour(static_cast<datetime_context_type_ const*>(initContext)->hour)
    , Minute(static_cast<datetime_context_type_ const*>(initContext)->minute)
    , Second(static_cast<datetime_context_type_ const*>(initContext)->second)
    , Microsecond(static_cast<datetime_context_type_ const*>(initContext)->microsecond)
{
    delete_context_();
}
#endif 

#ifdef PLATFORMSTL_OS_IS_WINDOWS
inline
datetime::datetime(SYSTEMTIME const& st)
    : initContext(NULL)
    , Year(st.wYear)
    , Month(st.wMonth)
    , Day(st.wDay)
    , Hour(st.wHour)
    , Minute(st.wMinute)
    , Second(st.wSecond)
    , Microsecond(st.wMilliseconds * 1000)
{}

inline
datetime::datetime(FILETIME const& ft)
    : initContext(make_context_SYSTEMTIME_(ft))
    , Year(static_cast<datetime_context_type_ const*>(initContext)->year)
    , Month(static_cast<datetime_context_type_ const*>(initContext)->month)
    , Day(static_cast<datetime_context_type_ const*>(initContext)->day)
    , Hour(static_cast<datetime_context_type_ const*>(initContext)->hour)
    , Minute(static_cast<datetime_context_type_ const*>(initContext)->minute)
    , Second(static_cast<datetime_context_type_ const*>(initContext)->second)
    , Microsecond(static_cast<datetime_context_type_ const*>(initContext)->microsecond)
{
    delete_context_();
}
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

inline
/* static */
datetime
datetime::now_system()
{
    time_t const    t   =   ::time(NULL);
    struct tm       tm;
    int const       e   = invoke_gmtime(&tm, &t);

    if(0 != e)
    {
        STLSOFT_THROW_X(conversion_error("could not obtain time value", e));
    }

    return datetime(tm);
}

inline
/* static */
datetime
datetime::now_local()
{
    time_t const    t   =   ::time(NULL);
    struct tm       tm;
    int const       e   = invoke_localtime(&tm, &t);

    if(0 != e)
    {
        STLSOFT_THROW_X(conversion_error("could not obtain time value", e));
    }

    return datetime(tm);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
#else
} /* namespace platformstl_project */
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_TIME_HPP_DATETIME */

/* ///////////////////////////// end of file //////////////////////////// */
