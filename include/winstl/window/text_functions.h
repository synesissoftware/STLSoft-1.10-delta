/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/text_functions.h (originally MWUser.h, ::SynesisWin)
 *
 * Purpose:     Window text functions.
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


/** \file winstl/window/text_functions.h
 *
 * \brief [C, C++] Window text functions
 *   (\ref group__library__windows_text "Windows Window Text" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_TEXT_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_TEXT_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_TEXT_FUNCTIONS_MAJOR    2
# define WINSTL_VER_WINSTL_WINDOW_H_TEXT_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_WINDOW_H_TEXT_FUNCTIONS_REVISION 4
# define WINSTL_VER_WINSTL_WINDOW_H_TEXT_FUNCTIONS_EDIT     34
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
#ifdef __cplusplus
# ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
#  include <stlsoft/memory/auto_buffer.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#endif /* __cplusplus */


    #if !defined(STLSOFT_COMPILER_IS_MSVC) || _MSC_VER >= 1310
    # define STLSOFT_CF_TEMPLATE_PARAMETER_PARTIAL_TEMPLATE_TYPE_SUPPORT
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
 * C Functions
 */

STLSOFT_INLINE size_t winstl_C_get_window_class_a(HWND hwnd, ws_char_a_t* dest, size_t cchDest)
{
    return stlsoft_static_cast(size_t, STLSOFT_NS_GLOBAL(GetClassNameA)(hwnd, dest, stlsoft_static_cast(int, cchDest)));
}

STLSOFT_INLINE size_t winstl_C_get_window_class_w(HWND hwnd, ws_char_w_t* dest, size_t cchDest)
{
    return stlsoft_static_cast(size_t, STLSOFT_NS_GLOBAL(GetClassNameW)(hwnd, dest, stlsoft_static_cast(int, cchDest)));
}

STLSOFT_INLINE size_t winstl_C_get_window_class(HWND hwnd, LPTSTR dest, size_t cchDest)
{
    return stlsoft_static_cast(size_t, STLSOFT_NS_GLOBAL(GetClassName)(hwnd, dest, stlsoft_static_cast(int, cchDest)));
}

STLSOFT_INLINE size_t winstl_C_get_window_text_a(HWND hwnd, ws_char_a_t* dest, size_t cchDest)
{
    return stlsoft_static_cast(size_t, STLSOFT_NS_GLOBAL(GetWindowTextA)(hwnd, dest, stlsoft_static_cast(int, cchDest)));
}

STLSOFT_INLINE size_t winstl_C_get_window_text_w(HWND hwnd, ws_char_w_t* dest, size_t cchDest)
{
    return stlsoft_static_cast(size_t, STLSOFT_NS_GLOBAL(GetWindowTextW)(hwnd, dest, stlsoft_static_cast(int, cchDest)));
}

STLSOFT_INLINE size_t winstl_C_get_window_text(HWND hwnd, LPTSTR dest, size_t cchDest)
{
    return stlsoft_static_cast(size_t, STLSOFT_NS_GLOBAL(GetWindowText)(hwnd, dest, stlsoft_static_cast(int, cchDest)));
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

inline size_t get_window_class_a(HWND hwnd, ws_char_a_t* dest, size_t cchDest)
{
    return winstl_C_get_window_class_a(hwnd, dest, cchDest);
}

inline size_t get_window_class_w(HWND hwnd, ws_char_w_t* dest, size_t cchDest)
{
    return winstl_C_get_window_class_w(hwnd, dest, cchDest);
}

inline size_t get_window_class(HWND hwnd, LPTSTR dest, size_t cchDest)
{
    return winstl_C_get_window_class_a(hwnd, dest, cchDest);
}

inline size_t _get_window_text_a(HWND hwnd, ws_char_a_t* dest, size_t cchDest)
{
    return winstl_C_get_window_text_a(hwnd, dest, cchDest);
}

inline size_t _get_window_text_w(HWND hwnd, ws_char_w_t* dest, size_t cchDest)
{
    return winstl_C_get_window_text_w(hwnd, dest, cchDest);
}

inline size_t _get_window_text(HWND hwnd, LPTSTR dest, size_t cchDest)
{
    return winstl_C_get_window_text_a(hwnd, dest, cchDest);
}


#ifdef STLSOFT_CF_TEMPLATE_PARAMETER_PARTIAL_TEMPLATE_TYPE_SUPPORT
template <size_t N>
inline size_t get_window_class_a(HWND hwnd, stlsoft::auto_buffer<char, N>& buffer)
#else /* ? STLSOFT_CF_TEMPLATE_PARAMETER_PARTIAL_TEMPLATE_TYPE_SUPPORT */
template <ss_typename_param_k B>
inline size_t get_window_class_a(HWND hwnd, B& buffer)
#endif /* STLSOFT_CF_TEMPLATE_PARAMETER_PARTIAL_TEMPLATE_TYPE_SUPPORT */
{
    for(size_t n = buffer.internal_size(); ; n *= 2)
    {
        if(!buffer.resize(n))
        {
            ::SetLastError(ERROR_NOT_ENOUGH_MEMORY);

            return 0;
        }
        else
        {
            int res = ::GetClassNameA(hwnd, &buffer[0], buffer.size());

            if(res + 1 < int(buffer.size()))
            {
                return res;
            }
        }
    }
}

#ifdef STLSOFT_CF_TEMPLATE_PARAMETER_PARTIAL_TEMPLATE_TYPE_SUPPORT
template <size_t N>
inline size_t get_window_text_a(HWND hwnd, stlsoft::auto_buffer<char, N>& buffer)
#else /* ? STLSOFT_CF_TEMPLATE_PARAMETER_PARTIAL_TEMPLATE_TYPE_SUPPORT */
template <ss_typename_param_k B>
inline size_t get_window_text_a(HWND hwnd, B& buffer)
#endif /* STLSOFT_CF_TEMPLATE_PARAMETER_PARTIAL_TEMPLATE_TYPE_SUPPORT */
{
    for(size_t n = buffer.internal_size(); ; n *= 2)
    {
        if(!buffer.resize(n))
        {
            ::SetLastError(ERROR_NOT_ENOUGH_MEMORY);

            return 0;
        }
        else
        {
            int res = ::GetWindowTextA(hwnd, &buffer[0], buffer.size());

            if(res + 1 < int(buffer.size()))
            {
                return res;
            }
        }
    }
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

#endif /* WINSTL_INCL_WINSTL_WINDOW_H_TEXT_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
