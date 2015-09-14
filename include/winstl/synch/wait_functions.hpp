/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/wait_functions.hpp
 *
 * Purpose:     Definition of the winstl::wait_for_multiple_objects()
 *              function template suite
 *
 * Created:     30th May 2006
 * Updated:     20th May 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006-2014, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/wait_functions.hpp
 *
 * \brief [C++ only] Definition of the winstl::wait_for_multiple_objects()
 *  function template suite
 *   (\ref group__library__synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_MAJOR       2
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_MINOR       2
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_REVISION    6
# define WINSTL_VER_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS_EDIT        21
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
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS
# include <stlsoft/synch/concepts.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_CONCEPTS */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_SYNCH_HANDLE
# include <winstl/shims/attribute/get_synch_handle.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_SYNCH_HANDLE */
#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS
# include <winstl/synch/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS */

#include <stdarg.h>

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
 * Code Coverage
 */

#ifdef STLSOFT_USE_XCOVER
namespace
{
    class register_with_xcover
    {
    public:
        register_with_xcover()
        {
            XCOVER_CREATE_FILE_ALIAS("wait_functions");
        }

    } instance;
}
#endif 

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifndef WINSTL_WAIT_FUNCTIONS_NO_USE_SHIM_VERIFIER

# ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k H>
inline
HANDLE
w4mo_verify_and_get_discriminator(H& h, H const*)
{
    STLSOFT_COVER_MARK_LINE();

    // If the compiler balks here with a message complaining about being
    //
    //     "unable to convert to HANDLE (*)(H&)",
    //
    // then it means that you're trying to pass an argument to
    // wait_for_multiple_object() for which an overload of the
    // winstl::get_synch_handle() attribute shim is not defined.
    //
    // This may confuse you if your type may be implicitly convertible to
    // HANDLE, but use of such types without shims is dangerous, and is
    // therefore disallowed. In such a case you MUST define an overload
    // of the winstl::get_synch_handle() attribute shim for your type.

    HANDLE (*pfn)(H&) = winstl_ns_qual(get_synch_handle);

    return (*pfn)(h);
}

inline
HANDLE
w4mo_verify_and_get_discriminator(HANDLE h, HANDLE const*)
{
    STLSOFT_COVER_MARK_LINE();

    return h;
}

template <ss_typename_param_k H>
inline
HANDLE
w4mo_verify_and_get(H& h)
{
    STLSOFT_COVER_MARK_LINE();

    return w4mo_verify_and_get_discriminator(h, &h);
}

# endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#else /* ? WINSTL_WAIT_FUNCTIONS_NO_USE_SHIM_VERIFIER */

template <ss_typename_param_k H>
inline
HANDLE
w4mo_verify_and_get(H& h)
{
    STLSOFT_COVER_MARK_LINE();

    return winstl_ns_qual(get_synch_handle)(h);
}

#endif /* !WINSTL_WAIT_FUNCTIONS_NO_USE_SHIM_VERIFIER */


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline
bool
w4mo_helper_find_first_duplicate_(
    ws_size_t   numHandles
,   HANDLE*     handles
,   ws_size_t*  i0
,   ws_size_t*  i1
)
{
    STLSOFT_COVER_MARK_LINE();

    WINSTL_ASSERT(numHandles >= 2);

    // Simple bubble search, since small arrays (<= 10)
    { for(ws_size_t j = 1; j != numHandles; ++j)
    {
        STLSOFT_COVER_MARK_LINE();

        { for(ws_size_t i = 0; i != j; ++i)
        {
            STLSOFT_COVER_MARK_LINE();

            if(handles[i] == handles[j])
            {
                STLSOFT_COVER_MARK_LINE();

                *i0 = i;
                *i1 = j;

                return true;
            }
        }}
    }}

    return false;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \brief [IMPLEMENTATION]
 *
 * \ingroup group__library__synch
 */
inline
DWORD
w4mo_helper_N(
    ws_dword_t  timeout     /* time out */
,   ws_bool_t   waitsForAll /* indicates whether a wait-all or wait-first operation is requested */
,   ws_size_t   numHandles  /* number of handles passed into function */
,   ...
)
{
    STLSOFT_COVER_MARK_LINE();

    WINSTL_ASSERT((numHandles >= 2 && numHandles <= 10));

    va_list args;
    HANDLE  handles[MAXIMUM_WAIT_OBJECTS];

    WINSTL_ASSERT(numHandles <= STLSOFT_NUM_ELEMENTS(handles));

    va_start(args, numHandles);

    for(ws_size_t i = 0; i != numHandles; ++i)
    {
        STLSOFT_COVER_MARK_LINE();

        HANDLE h = va_arg(args, HANDLE);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(NULL == h)
        {
            STLSOFT_COVER_MARK_LINE();

            STLSOFT_THROW_X(null_wait_handle_exception(ERROR_INVALID_HANDLE, int(i)));
        }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        WINSTL_MESSAGE_ASSERT("synchronisation handle may not be null", NULL != h);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

        handles[i] = h;
    }

    va_end(args);

    ws_size_t   i0 = STLSOFT_NUM_ELEMENTS(handles);
    ws_size_t   i1 = STLSOFT_NUM_ELEMENTS(handles);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(w4mo_helper_find_first_duplicate_(numHandles, &handles[0], &i0, &i1))
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_THROW_X(duplicate_wait_handle_exception(ERROR_INVALID_PARAMETER, i0, i1));
    }
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    WINSTL_MESSAGE_ASSERT("synchronisation handles must be unique", !w4mo_helper_find_first_duplicate_(numHandles, &handles[0], &i0, &i1));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return ::WaitForMultipleObjects(static_cast<DWORD>(numHandles), &handles[0], waitsForAll, timeout);
}


/** \brief Execute wait for 10 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        ,   ss_typename_param_k L5
        ,   ss_typename_param_k L6
        ,   ss_typename_param_k L7
        ,   ss_typename_param_k L8
        ,   ss_typename_param_k L9
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   L5&         l5
,   L6&         l6
,   L7&         l7
,   L8&         l8
,   L9&         l9
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l5));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l6));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l7));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l8));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l9));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 10
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l2)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l3)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l4)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l5)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l6)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l7)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l8)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l9)
        );
}

/** \brief Execute wait for 9 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        ,   ss_typename_param_k L5
        ,   ss_typename_param_k L6
        ,   ss_typename_param_k L7
        ,   ss_typename_param_k L8
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   L5&         l5
,   L6&         l6
,   L7&         l7
,   L8&         l8
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l5));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l6));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l7));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l8));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 9
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l2)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l3)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l4)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l5)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l6)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l7)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l8)
        ,   NULL
        );
}

/** \brief Execute wait for 8 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        ,   ss_typename_param_k L5
        ,   ss_typename_param_k L6
        ,   ss_typename_param_k L7
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   L5&         l5
,   L6&         l6
,   L7&         l7
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l5));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l6));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l7));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 8
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l2)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l3)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l4)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l5)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l6)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l7)
        ,   NULL
        ,   NULL
        );
}

/** \brief Execute wait for 7 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        ,   ss_typename_param_k L5
        ,   ss_typename_param_k L6
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   L5&         l5
,   L6&         l6
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l5));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l6));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 7
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l2)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l3)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l4)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l5)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l6)
        ,   NULL
        ,   NULL
        ,   NULL
        );
}

/** \brief Execute wait for 6 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        ,   ss_typename_param_k L5
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   L5&         l5
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l5));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 6
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l2)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l3)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l4)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l5)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        );
}

/** \brief Execute wait for 5 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        ,   ss_typename_param_k L4
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   L4&         l4
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l4));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 5
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l2)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l3)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l4)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        );
}

/** \brief Execute wait for 4 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        ,   ss_typename_param_k L3
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   L3&         l3
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l3));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 4
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l2)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l3)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        );
}

/** \brief Execute wait for 3 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        ,   ss_typename_param_k L2
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   L2&         l2
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l2));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 3
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l2)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        );
}

/** \brief Execute wait for 2 synchronisation objects of heterogeneous types.
 *
 * \ingroup group__library__synch
 */
template<   ss_typename_param_k L0
        ,   ss_typename_param_k L1
        >
inline
DWORD
wait_for_multiple_objects(
    L0&         l0
,   L1&         l1
,   ws_bool_t   waitsForAll
,   ws_dword_t  timeout
)
{
    STLSOFT_COVER_MARK_LINE();

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l0));
    WINSTL_ASSERT(NULL != winstl_ns_qual(get_synch_handle)(l1));
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

    return w4mo_helper_N(timeout, waitsForAll, 2
        ,   winstl_ns_qual(w4mo_verify_and_get)(l0)
        ,   winstl_ns_qual(w4mo_verify_and_get)(l1)
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        ,   NULL
        );
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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_WAIT_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
