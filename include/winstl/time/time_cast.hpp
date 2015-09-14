/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/time/time_cast.hpp
 *
 * Purpose:     winstl::time_cast<>.
 *
 * Created:     26th May 2014
 * Updated:     9th October 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014, Matthew Wilson and Synesis Software
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


/** \file winstl/time/time_cast.hpp
 *
 * \brief [C, C++] winstl::time_cast<>
 *   (\ref group__library__time "Time" Library).
 */

#ifndef WINSTL_INCL_WINSTL_TIME_HPP_TIME_CAST
#define WINSTL_INCL_WINSTL_TIME_HPP_TIME_CAST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_TIME_HPP_TIME_CAST_MAJOR     1
# define WINSTL_VER_WINSTL_TIME_HPP_TIME_CAST_MINOR     0
# define WINSTL_VER_WINSTL_TIME_HPP_TIME_CAST_REVISION  2
# define WINSTL_VER_WINSTL_TIME_HPP_TIME_CAST_EDIT      2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#ifndef WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS
# include <winstl/time/conversion_functions.h>
#endif /* !WINSTL_INCL_WINSTL_TIME_H_CONVERSION_FUNCTIONS */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#ifndef __cplusplus
# error This file requires C++ compilation
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace ximpl_winstl_time_cast
{

    template <
        typename R
    ,   typename T
    >
    struct time_cast_traits;

    template <>
    struct time_cast_traits<SYSTEMTIME, SYSTEMTIME>
    {
    public:
        static
        SYSTEMTIME
        convert(
            SYSTEMTIME const& t
        )
        {
            return t;
        }
    };

    template <>
    struct time_cast_traits<FILETIME, FILETIME>
    {
    public:
        static
        FILETIME
        convert(
            FILETIME const& t
        )
        {
            return t;
        }
    };

    template <>
    struct time_cast_traits<FILETIME, SYSTEMTIME>
    {
    public:
        static
        FILETIME
        convert(
            SYSTEMTIME const& t
        )
        {
            FILETIME ft;

            if(!::SystemTimeToFileTime(&t, &ft))
            {
                DWORD const e = ::GetLastError();

#ifdef _DEBUG
#else /* ? _DEBUG */
# error
                STLSOFT_THROW_X(bad_time_cast(e));
#endif /* _DEBUG */
            }

            return ft;
        }
    };

    template <>
    struct time_cast_traits<SYSTEMTIME, FILETIME>
    {
    public:
        static
        SYSTEMTIME
        convert(
            FILETIME const& t
        )
        {
            SYSTEMTIME st;

            if(!::FileTimeToSystemTime(&t, &st))
            {
                DWORD const e = ::GetLastError();

#ifdef _DEBUG
#else /* ? _DEBUG */
# error
                STLSOFT_THROW_X(bad_time_cast(e));
#endif /* _DEBUG */
            }

            return st;
        }
    };

} /* namespace ximpl_winstl_time_cast */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Casts
 */

#if 0

template <typename T>
class time_cast;

template <>
class time_cast<FILETIME>
{
};

#else /* ? 0 */

template <
    typename R
,   typename T
>
R
time_cast(T const& t)
{
    return ximpl_winstl_time_cast::time_cast_traits<R, T>::convert(t);
}

#endif /* 0 */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_TIME_HPP_TIME_CAST */

/* ///////////////////////////// end of file //////////////////////////// */
