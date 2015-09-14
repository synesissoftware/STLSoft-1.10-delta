/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/waitable_timer.hpp
 *
 * Purpose:     Semaphore class, based on Windows kernel waitable timer
 *              object.
 *
 * Created:     4th January 2014
 * Updated:     24th August 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/synch/waitable_timer.hpp
 *
 * \brief [C++ only] Definition of winstl::waitable_timer class
 *   (\ref group__library__synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_WAITABLE_TIMER
#define WINSTL_INCL_WINSTL_SYNCH_HPP_WAITABLE_TIMER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAITABLE_TIMER_MAJOR       0
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAITABLE_TIMER_MINOR       2
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAITABLE_TIMER_REVISION    4
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAITABLE_TIMER_EDIT        5
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
# error This component cannot be used in compilation units in which exception-handling is suppressed
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS
# include <winstl/synch/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS
# include <winstl/synch/waitable_timer_functions.h>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_WAITABLE_TIMER_FUNCTIONS */

#if !defined( _WIN32_WINNT) || \
     _WIN32_WINNT < 0x0400
# include <winstl/dl/dl_call.hpp>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
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
 * Classes
 */

// class waitable_timer
/** This class acts as an waitable_timer based on the Windows
 *   kernel waitable timer object
 *
 * \ingroup group__library__synch
 */
class waitable_timer
    : public stlsoft_ns_qual(synchronisable_object_tag)
{
public:
    /// This type
    typedef waitable_timer  class_type;
    /// The synchronisation handle type
    typedef HANDLE          synch_handle_type;

/// \name Construction
/// @{
public:
    /// Conversion constructor
    waitable_timer()
        : m_timer(create_timer_())
    {
        WINSTL_ASSERT(NULL != m_timer);
    }
    /// Destroys an instance of the waitable_timer
    ~waitable_timer() stlsoft_throw_0()
    {
        ::CloseHandle(m_timer);
    }
private:
    waitable_timer(class_type const& rhs);              // proscribed
    waitable_timer& operator =(class_type const& rhs);  // proscribed
/// @}

/// \name Operations
/// @{
public:
    /// Activates the timer to the given dueTime and period
    ///
    /// \param dueTime The due time for the first signal
    /// \param period The period at which to signal
    ///
    /// \exception winstl::synchronisation_object_state_change_failed_exception
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    void
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    BOOL
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    set(
        SYSTEMTIME const&   dueTime
    ,   DWORD               period
    )
    {
        if(!set_waitable_timer(m_timer, dueTime, period, NULL, NULL, false))
        {
            DWORD const e = ::GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_object_state_change_failed_exception(e, "set waitable timer operation failed", Synchronisation_WaitableTimerSetFailed));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            return FALSE;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        return TRUE;
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    /// Deactivates the timer
    ///
    /// \exception winstl::synchronisation_object_state_change_failed_exception
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    void
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    BOOL
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    cancel()
    {
        if(!::CancelWaitableTimer(m_timer))
        {
            DWORD const e = ::GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_object_state_change_failed_exception(e, "failed to cancel waitable timer", Synchronisation_WaitableTimerSetFailed));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            return FALSE;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
        return TRUE;
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */
    }
/// @}

/// \name Accessors
/// @{
public:
    /// The underlying kernel object handle
    synch_handle_type handle()
    {
        return m_timer;
    }
    /// The underlying kernel object handle
    synch_handle_type get()
    {
        return m_timer;
    }
/// @}

// Implementation
private:
    static
    HANDLE create_timer_(
    )
    {
        HANDLE hTimer = 
#if !defined( _WIN32_WINNT) || \
     _WIN32_WINNT < 0x0400
        winstl::dl_call<HANDLE>("S:CreateWaitableTimerA", "KERNEL32", static_cast<void*>(NULL), static_cast<BOOL>(FALSE), static_cast<LPCSTR>(NULL));
#else
        STLSOFT_NS_GLOBAL(CreateWaitableTimerA)(NULL, FALSE, NULL);
#endif

        if(NULL == hTimer)
        {
            DWORD const e = ::GetLastError();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(synchronisation_creation_exception(e, "failed to create kernel waitable timer object"));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return hTimer;
    }

// Members
private:
    synch_handle_type const m_timer;    // The underlying waitable_timer object
};

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/** Overload of the form of the winstl::get_synch_handle() shim for
 *    the winstl::waitable_timer type.
 *
 * \param timer The winstl::waitable_timer instance
 *
 * \retval The synchronisation handle of \c timer
 */
inline
HANDLE
get_synch_handle(
    waitable_timer &timer
)
{
    return timer.get();
}

/** Overload of the form of the winstl::get_kernel_handle() shim for
 *    the winstl::waitable_timer type.
 *
 * \ingroup group__library__shims__kernel_handle_attribute
 *
 * \param timer The winstl::waitable_timer instance
 *
 * \retval The synchronisation handle of \c timer
 */
inline
HANDLE
get_kernel_handle(
    waitable_timer &timer
)
{
    return timer.get();
}

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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_WAITABLE_TIMER */

/* ///////////////////////////// end of file //////////////////////////// */
