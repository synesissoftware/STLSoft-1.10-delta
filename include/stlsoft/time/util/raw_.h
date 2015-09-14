/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/time/util/raw_.h
 *
 * Purpose:     internal implementation.
 *
 * Created:     9th May 2014
 * Updated:     8th August 2015
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


/** \file stlsoft/time/timespan.hpp
 *
 * \brief [C/C++] internal implementation
 */

#ifndef STLSOFT_INCL_STLSOFT_TIME_UTIL_H_RAW_
#define STLSOFT_INCL_STLSOFT_TIME_UTIL_H_RAW_

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */

#ifndef STLSOFT_INCL_H_TIME
# define STLSOFT_INCL_H_TIME
# include <time.h>
#endif /* !STLSOFT_INCL_H_TIME */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Internal functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#ifdef __cplusplus
namespace ximpl_raw
{
#endif /* __cplusplus */

STLSOFT_INLINE
int
stlsoft_C_raw_time_gmtime_(
    struct tm*      tm
,   time_t const*   t
)
{
    STLSOFT_ASSERT(NULL != tm);
    STLSOFT_ASSERT(NULL != t);

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

    STLSOFT_COVER_MARK_LINE();

    return STLSOFT_NS_GLOBAL(gmtime_s)(tm, t);

#else
  {
    struct tm const* const ptm = STLSOFT_NS_GLOBAL(gmtime)(t);

    STLSOFT_COVER_MARK_LINE();

    if(NULL == ptm)
    {
        STLSOFT_COVER_MARK_LINE();

        return errno;
    }
    else
    {
        STLSOFT_COVER_MARK_LINE();

        *tm = *ptm;

        return 0;
    }
  }
#endif
}

STLSOFT_INLINE
int
stlsoft_C_raw_time_localtime_(
    struct tm*      tm
,   time_t const*   t
)
{
    STLSOFT_ASSERT(NULL != tm);
    STLSOFT_ASSERT(NULL != t);

#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

    STLSOFT_COVER_MARK_LINE();

    return STLSOFT_NS_GLOBAL(localtime_s)(tm, t);

#else
  {
    struct tm const* const ptm = STLSOFT_NS_GLOBAL(localtime)(t);

    STLSOFT_COVER_MARK_LINE();

    if(NULL == ptm)
    {
        STLSOFT_COVER_MARK_LINE();

        return errno;
    }
    else
    {
        STLSOFT_COVER_MARK_LINE();

        *tm = *ptm;

        return 0;
    }
  }
#endif
}

#ifdef __cplusplus

inline
int
gmtime_(
    struct tm*      tm
,   time_t const*   t
)
{
    STLSOFT_COVER_MARK_LINE();

    return stlsoft_C_raw_time_gmtime_(tm, t);
}

inline
int
localtime_(
    struct tm*      tm
,   time_t const*   t
)
{
    STLSOFT_COVER_MARK_LINE();

    return stlsoft_C_raw_time_localtime_(tm, t);
}

} /* namespace ximpl_raw */
#endif /* __cplusplus */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_TIME_UTIL_H_RAW_ */

/* ///////////////////////////// end of file //////////////////////////// */
