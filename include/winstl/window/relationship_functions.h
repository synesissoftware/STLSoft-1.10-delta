/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/relationship_functions.h (originally MWUser.h, ::SynesisWin)
 *
 * Purpose:     Window relationship functions.
 *
 * Created:     20th October 1994
 * Updated:     8th August 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2015, Matthew Wilson and Synesis Software
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


/** \file winstl/window/relationship_functions.h
 *
 * \brief [C, C++] Window relationship functions.
 *   (\ref group__library__windows_window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS_MAJOR    2
# define WINSTL_VER_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS_MINOR    1
# define WINSTL_VER_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS_REVISION 4
# define WINSTL_VER_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS_EDIT     90
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

#  include <winstl/window/functions.h> /* Until winstl__get_window_sptrint_() is factored into smaller worker file */

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
 * C functions
 */

/** Obtains the owner window of the given window
 *
 * \param hwnd The handle of the window whose owner is to be obtained
 */
STLSOFT_INLINE HWND winstl_C_get_window_owner(HWND hwnd)
{
    WINSTL_ASSERT(::IsWindow(hwnd));

    return STLSOFT_NS_GLOBAL(GetWindow)(hwnd, GW_OWNER);
}

/** Obtains the parent window of the given window
 *
 * \param hwnd The handle of the window whose parent is to be obtained
 */
STLSOFT_INLINE HWND winstl_C_get_window_parent(HWND hwnd)
{
    WINSTL_ASSERT(::IsWindow(hwnd));

    return stlsoft_reinterpret_cast(HWND, winstl__get_window_sptrint_(hwnd, GWL_HWNDPARENT));
}

/** Obtains the identifier of the process that created the given window
 *
 * \param hwnd The handle of the window whose creating process is to be
 *   obtained
 *
 * \return The identifier of the process that created the window, or 0 if it
 *   cannot be obtained
 */
STLSOFT_INLINE DWORD winstl_C_get_window_process_id(HWND hwnd)
{
    DWORD pid = 0;

    WINSTL_ASSERT(::IsWindow(hwnd));

    STLSOFT_NS_GLOBAL(GetWindowThreadProcessId)(hwnd, &pid);

    return pid;
}

/** Obtains the identifier of the thread that created the given window
 *
 * \param hwnd The handle of the window whose creating thread is to be
 *   obtained
 *
 * \return The identifier of the thread that created the window, or 0 if it
 *   cannot be obtained
 */
STLSOFT_INLINE DWORD winstl_C_get_window_thread_id(HWND hwnd)
{
    WINSTL_ASSERT(::IsWindow(hwnd));

    return STLSOFT_NS_GLOBAL(GetWindowThreadProcessId)(hwnd, NULL);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** Obtains the owner window of the given window
 *
 * \param hwnd The handle of the window whose owner is to be obtained
 */
inline HWND get_window_owner(HWND hwnd)
{
    return winstl_C_get_window_owner(hwnd);
}

/** Obtains the parent window of the given window
 *
 * \param hwnd The handle of the window whose parent is to be obtained
 */
inline HWND get_window_parent(HWND hwnd)
{
    return winstl_C_get_window_parent(hwnd);
}

/** Obtains the identifier of the process that created the given window
 *
 * \param hwnd The handle of the window whose creating process is to be
 *   obtained
 *
 * \return The identifier of the process that created the window, or 0 if it
 *   cannot be obtained
 */
inline DWORD get_window_process_id(HWND hwnd)
{
    return winstl_C_get_window_process_id(hwnd);
}

/** Obtains the identifier of the thread that created the given window
 *
 * \param hwnd The handle of the window whose creating thread is to be
 *   obtained
 *
 * \return The identifier of the thread that created the window, or 0 if it
 *   cannot be obtained
 */
inline DWORD get_window_thread_id(HWND hwnd)
{
    return winstl_C_get_window_thread_id(hwnd);
}

#endif /* __cplusplus */

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

#endif /* WINSTL_INCL_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
