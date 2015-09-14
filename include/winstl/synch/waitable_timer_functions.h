/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/waitable_timer_functions.h
 *
 * Purpose:     WinSTL waitable timer functions.
 *
 * Created:     17th April 2014
 * Updated:     20th May 2014
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
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


/** \file winstl/synch/waitable_timer_functions.h
 *
 * \brief [C, C++] Various waitable timer functions
 *   (\ref group__library__synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS_REVISION    1
# define WINSTL_VER_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS_EDIT        4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

/* /////////////////////////////////////////////////////////////////////////
 * Windows API version check
 */

#if !defined(_WIN32_WINNT) || \
    _WIN32_WINNT < 0x0400
# error This file uses Windows Waitable Timer functions that require _WIN32_WINNT >= 0x0400
#endif /* !_WIN32_WINNT || _WIN32_WINNT < 0x0400 */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(_WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(_STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

STLSOFT_INLINE
BOOL
winstl_C_set_waitable_timer_FILETIME(
    HANDLE              hTimer
,   FILETIME const*     pDueTime
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    LARGE_INTEGER li;

    WINSTL_ASSERT(NULL != pDueTime);
    WINSTL_ASSERT(0 == (0x8000000 & period));

    li.QuadPart =   pDueTime->dwHighDateTime;
    li.QuadPart <<= 32;
    li.QuadPart +=  pDueTime->dwLowDateTime; 

    return STLSOFT_NS_GLOBAL(SetWaitableTimer)(hTimer, &li, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

STLSOFT_INLINE
BOOL
winstl_C_set_waitable_timer_SYSTEMTIME(
    HANDLE              hTimer
,   SYSTEMTIME const*   pDueTime
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    FILETIME ft;

    WINSTL_ASSERT(NULL != pDueTime);
    WINSTL_ASSERT(0 == (0x8000000 & period));

    if(STLSOFT_NS_GLOBAL(SystemTimeToFileTime)(pDueTime, &ft))
    {
        return winstl_C_set_waitable_timer_FILETIME(hTimer, &ft, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
    }

    return FALSE;
}

STLSOFT_INLINE
BOOL
winstl_C_set_waitable_timer_hence_microseconds(
    HANDLE              hTimer
,   ws_uint64_t         dueTimeHence
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    LARGE_INTEGER li;

    WINSTL_ASSERT(0 == (0x8000000 & period));

    li.QuadPart = dueTimeHence * 10;
    li.QuadPart = -li.QuadPart;

    if(0 == li.QuadPart)
    {
        li.QuadPart = -1;
    }

    return STLSOFT_NS_GLOBAL(SetWaitableTimer)(hTimer, &li, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

STLSOFT_INLINE
BOOL
winstl_C_set_waitable_timer_hence_milliseconds(
    HANDLE              hTimer
,   ws_uint64_t         dueTimeHence
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_hence_microseconds(hTimer, dueTimeHence * 1000, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

STLSOFT_INLINE
BOOL
winstl_C_set_waitable_timer_hence_seconds(
    HANDLE              hTimer
,   ws_uint64_t         dueTimeHence
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_hence_milliseconds(hTimer, dueTimeHence * 1000, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

inline
BOOL
set_waitable_timer(
    HANDLE              hTimer
,   FILETIME const*     dueTime
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_FILETIME(hTimer, dueTime, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

inline
BOOL
set_waitable_timer(
    HANDLE              hTimer
,   FILETIME const&     dueTime
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_FILETIME(hTimer, &dueTime, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

inline
BOOL
set_waitable_timer(
    HANDLE              hTimer
,   SYSTEMTIME const*   dueTime
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_SYSTEMTIME(hTimer, dueTime, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

inline
BOOL
set_waitable_timer(
    HANDLE              hTimer
,   SYSTEMTIME const&   dueTime
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_SYSTEMTIME(hTimer, &dueTime, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}


STLSOFT_INLINE
BOOL
set_waitable_timer_hence_microseconds(
    HANDLE              hTimer
,   ws_uint64_t         dueTimeHence
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_hence_microseconds(hTimer, dueTimeHence, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

STLSOFT_INLINE
BOOL
set_waitable_timer_hence_milliseconds(
    HANDLE              hTimer
,   ws_uint64_t         dueTimeHence
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_hence_milliseconds(hTimer, dueTimeHence, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

STLSOFT_INLINE
BOOL
set_waitable_timer_hence_seconds(
    HANDLE              hTimer
,   ws_uint64_t         dueTimeHence
,   DWORD               period
,   PTIMERAPCROUTINE    pfnCompletionRoutine
,   LPVOID              lpArgToCompletionRoutine
,   BOOL                fResume
)
{
    return winstl_C_set_waitable_timer_hence_seconds(hTimer, dueTimeHence, period, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume);
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
