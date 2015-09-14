/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/search_functions.hpp (originally MWUser.h, ::SynesisWin)
 *
 * Purpose:     Window search functions.
 *
 * Created:     20th October 1994
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2012, Matthew Wilson and Synesis Software
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


/** \file winstl/window/search_functions.hpp
 *
 * \brief [C, C++] Window search functions
 *   (\ref group__library__windows_search "Windows Window Search" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_HPP_SEARCH_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_HPP_SEARCH_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_HPP_SEARCH_FUNCTIONS_MAJOR    2
# define WINSTL_VER_WINSTL_WINDOW_HPP_SEARCH_FUNCTIONS_MINOR    3
# define WINSTL_VER_WINSTL_WINDOW_HPP_SEARCH_FUNCTIONS_REVISION 3
# define WINSTL_VER_WINSTL_WINDOW_HPP_SEARCH_FUNCTIONS_EDIT     39
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
#ifndef __cplusplus
# error Requires C++ compilation
#endif /* __cplusplus */
#ifndef WINSTL_INCL_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS
# include <winstl/window/relationship_functions.h>
#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_RELATIONSHIP_FUNCTIONS */
#ifndef WINSTL_INCL_WINSTL_WINDOW_H_TEXT_FUNCTIONS
# include <winstl/window/text_functions.h>
#endif /* !WINSTL_INCL_WINSTL_WINDOW_H_TEXT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */

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
 * Typedefs
 */

/** Application-defined function callback for searching windows with
 * find_window_a(), find_window_in_process_a() and find_child_window_a()
 *
 * \param hwnd The current window
 * \param windowClassLen The number of characters refered to
 *   by \c windowClass
 * \param windowClass The window's class; may be \c NULL
 *   if \c windowClassLen is 0
 * \param windowTextLen The number of characters refered to
 *   by \c windowText
 * \param windowText The window's text; may be \c NULL
 *   if \c windowTextLen is 0
 * \param param Caller-supplied parameter passed to find_child_window_a()
 *
 * \return a value controlling the search
 * \retval +1 The window is found
 * \retval 0 Continue
 * \retval -1 Cancel the search
 */
typedef int (STLSOFT_STDCALL *find_window_proc_a)(
    HWND                hwnd
,   size_t              windowClassLen
,   ws_char_a_t const*  windowClass
,   size_t              windowTextLen
,   ws_char_a_t const*  windowText
,   void*               param
);

/** Application-defined function callback for searching windows with
 * find_window_w(), find_window_in_process_w() and find_child_window_w()
 *
 * \param hwnd The current window
 * \param windowClassLen The number of characters refered to
 *   by \c windowClass
 * \param windowClass The window's class; may be \c NULL
 *   if \c windowClassLen is 0
 * \param windowTextLen The number of characters refered to
 *   by \c windowText
 * \param windowText The window's text; may be \c NULL
 *   if \c windowTextLen is 0
 * \param param Caller-supplied parameter passed to find_child_window_w()
 *
 * \return a value controlling the search
 * \retval +1 The window is found
 * \retval 0 Continue
 * \retval -1 Cancel the search
 */
typedef int (STLSOFT_STDCALL *find_window_proc_w)(
    HWND                hwnd
,   size_t              childClassLen
,   ws_char_w_t const*  childClass
,   size_t              childTextLen
,   ws_char_w_t const*  childText
,   void*               param
);


/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

/** Searches for a top-level window matching the given criteria
 *
 * \ingroup group__library__windows_search
 *
 * \param windowClass The name of the window class, or \c NULL if no class
 *   is specified
 * \param windowTitle The name of the window title, or \c NULL if no title
 *   is specified
 *
 * \return The first top-level window matching the given \c windowClass
 *   and/or \c windowTitle
 */
inline HWND find_window(ws_char_a_t const* windowClass, ws_char_a_t const* windowTitle)
{
    return ::FindWindowA(windowClass, windowTitle);
}
/** Searches for a top-level window matching the given criteria
 *
 * \ingroup group__library__windows_search
 *
 * \param windowClass The name of the window class, or \c NULL if no class
 *   is specified
 * \param windowTitle The name of the window title, or \c NULL if no title
 *   is specified
 *
 * \return The first top-level window matching the given \c windowClass
 *   and/or \c windowTitle
 */
inline HWND find_window(ws_char_w_t const* windowClass, ws_char_w_t const* windowTitle)
{
    return ::FindWindowW(windowClass, windowTitle);
}
/** Searches for a top-level window matching the given criteria
 *
 * \ingroup group__library__windows_search
 *
 * \param windowClass The atom of the window class, or \c NULL if no class
 *   is specified
 * \param windowTitle The name of the window title, or \c NULL if no title
 *   is specified
 *
 * \return The first top-level window matching the given \c windowClass
 *   and/or \c windowTitle
 */
inline HWND find_window(ATOM windowClass, ws_char_a_t const* windowTitle)
{
    return ::FindWindowA(MAKEINTRESOURCEA(windowClass), windowTitle);
}
/** Searches for a top-level window matching the given criteria
 *
 * \ingroup group__library__windows_search
 *
 * \param windowClass The atom of the window class, or \c NULL if no class
 *   is specified
 * \param windowTitle The name of the window title, or \c NULL if no title
 *   is specified
 *
 * \return The first top-level window matching the given \c windowClass
 *   and/or \c windowTitle
 */
inline HWND find_window(ATOM windowClass, ws_char_w_t const* windowTitle)
{
    return ::FindWindowW(MAKEINTRESOURCEW(windowClass), windowTitle);
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
inline HWND find_window(int windowClass, ws_char_a_t const* windowTitle)
{
    WINSTL_MESSAGE_ASSERT("the only valid integer literal to specify to find_window is 0", 0 == windowClass);

    return find_window(stlsoft_static_cast(ws_char_a_t const*, NULL), windowTitle);
}
inline HWND find_window(int windowClass, ws_char_w_t const* windowTitle)
{
    WINSTL_MESSAGE_ASSERT("the only valid integer literal to specify to find_window is 0", 0 == windowClass);

    return find_window(stlsoft_static_cast(ws_char_w_t const*, NULL), windowTitle);
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** Finds all immediate children of the given window
 *
 * \param hwnd The handle of the window whose immediate children are to be
 *   obtained
 * \param fn A caller-supplied function to be invoked for each immediate
 *   child
 * \param param A caller-defined value to be passed back to \c fn
 *
 * \return An indication of success.
 * \retval !0 The function completed successfully
 * \retval FALSE The function failed. Call <code>GetLastError()</code> to
 *   obtain further information
 *
 * \remarks This function is similar to the Windows API function
 *   <code>EnumChildWindows()</code>, except that the callback function is
 *   only invoked for windows whose parent window is \c hwnd.
 */
inline BOOL enumerate_immediate_children(HWND hwnd, WNDENUMPROC fn, LPARAM param)
{
    struct context_t
    {
        context_t(HWND hwndParent, WNDENUMPROC fn, LPARAM param)
            : hwndParent(hwndParent)
            , clientFn(fn)
            , clientParam(param)
        {}

        HWND        hwndParent;
        WNDENUMPROC clientFn;
        LPARAM      clientParam;

        static BOOL CALLBACK fn(HWND hwnd, LPARAM param)
        {
            context_t& ctxt = *stlsoft_c_cast(context_t*, param);

            WINSTL_ASSERT(0 != param);

            if(get_window_parent(hwnd) == ctxt.hwndParent)
            {
                return ctxt.clientFn(hwnd, ctxt.clientParam);
            }

            return true;
        }

    } ctxt(hwnd, fn, param);

    return ::EnumChildWindows(hwnd, context_t::fn, stlsoft_reinterpret_cast(LPARAM, &ctxt));
}


inline HWND find_window_a(find_window_proc_a fn, void* param)
{
    struct context_t
    {
        find_window_proc_a const    fn;
        HWND                        hwnd;
        void* const                 param;

        context_t(find_window_proc_a f, void* p)
            : fn(f)
            , hwnd(NULL)
            , param(p)
        {}

        static BOOL CALLBACK f(HWND hwnd, LPARAM param)
        {
            context_t&                      ctxt            =   *stlsoft_c_cast(context_t*, param);
            stlsoft::auto_buffer<char, 64>  windowClass(1);
            stlsoft::auto_buffer<char, 64>  windowText(1);
            size_t                          windowClassLen  =   get_window_class_a(hwnd, windowClass);
            size_t                          windowTextLen   =   get_window_text_a(hwnd, windowText);

            int res = ctxt.fn(hwnd, windowClassLen, windowClass.data(), windowTextLen, windowText.data(), ctxt.param);

            if(0 == res)
            {
                return true;
            }
            else
            {
                ctxt.hwnd = (res > 0) ? hwnd : NULL;

                return false;
            }
        }


    } context(fn, param);

    ::EnumWindows(context_t::f, stlsoft_c_cast(LPARAM, &context));

    return context.hwnd;
}


inline HWND find_window_in_process_a(DWORD pid, find_window_proc_a fn, void* param)
{
    WINSTL_MESSAGE_ASSERT("Must specify non-0 process identifier value", 0 != pid);

    struct context_t
    {
        void* const                 m_param;
        find_window_proc_a const    m_fn;
        DWORD const                 m_pid;

        context_t(void* param, find_window_proc_a fn, DWORD pid)
            : m_param(param)
            , m_fn(fn)
            , m_pid(pid)
        {}

        static int STLSOFT_STDCALL fn(
            HWND                hwnd
        ,   size_t              windowClassLen
        ,   ws_char_a_t const*  windowClass
        ,   size_t              windowTextLen
        ,   ws_char_a_t const*  windowText
        ,   void*               param
        )
        {
            context_t& context = *stlsoft_static_cast(context_t*, param);

            return context.fn(hwnd, windowClassLen, windowClass, windowTextLen, windowText);
        }

        int fn(
            HWND                hwnd
        ,   size_t              windowClassLen
        ,   ws_char_a_t const*  windowClass
        ,   size_t              windowTextLen
        ,   ws_char_a_t const*  windowText
        ) const
        {
            DWORD pid = 0;

            ::GetWindowThreadProcessId(hwnd, &pid);

            if(pid == m_pid)
            {
                return m_fn(hwnd, windowClassLen, windowClass, windowTextLen, windowText, m_param);
            }

            return 0;
        }

    } context(param, fn, pid);

    return find_window_a(context_t::fn, &context);
}


inline HWND find_window_in_process(
    DWORD               pid
,   ws_char_a_t const*  childClass
,   ws_char_a_t const*  childText
)
{
    struct param_t
    {
        DWORD const                 m_pid;
        ws_char_a_t const* const    m_childClass;
        ws_char_a_t const* const    m_childText;

        param_t(DWORD pid, ws_char_a_t const* childClass, ws_char_a_t const* childText)
            : m_pid(pid)
            , m_childClass(childClass)
            , m_childText(childText)
        {}

        int fn(
            HWND                hwnd
        ,   size_t              childClassLen
        ,   ws_char_a_t const*  childClass
        ,   size_t              childTextLen
        ,   ws_char_a_t const*  childText
        ) const
        {
            if(NULL != m_childClass)
            {
                size_t len = ::strlen(m_childClass);

                if( len != childClassLen ||
                    0 != _strnicmp(m_childClass, childClass, childClassLen))
                {
                    return 0;
                }
            }

            if(NULL != m_childText)
            {
                size_t len = ::strlen(m_childText);

                if( len != childTextLen ||
                    0 != _strnicmp(m_childText, childText, childTextLen))
                {
                    return 0;
                }
            }

            return +1;
        }

        static int STLSOFT_STDCALL fn(
            HWND                hwnd
        ,   size_t              childClassLen
        ,   ws_char_a_t const*  childClass
        ,   size_t              childTextLen
        ,   ws_char_a_t const*  childText
        ,   void*               param
        )
        {
            param_t& this_ = *stlsoft_c_cast(param_t*, param);

            return this_.fn(hwnd, childClassLen, childClass, childTextLen, childText);
        }
    } param(NULL, childClass, childText);

    return find_window_in_process_a(pid, param_t::fn, &param);
}



inline HWND find_child_window_a(HWND hwndParent, find_window_proc_a fn, void* param)
{
    struct context_t
    {
        find_window_proc_a const    fn;
        HWND                        hwnd;
        void* const                 param;

        context_t(find_window_proc_a f, void* p)
            : fn(f)
            , hwnd(NULL)
            , param(p)
        {}

        static BOOL CALLBACK f(HWND hwnd, LPARAM param)
        {
            context_t&                      ctxt            =   *stlsoft_c_cast(context_t*, param);
            stlsoft::auto_buffer<char, 64>  windowClass(1);
            stlsoft::auto_buffer<char, 64>  windowText(1);
            size_t                          windowClassLen  =   get_window_class_a(hwnd, windowClass);
            size_t                          windowTextLen   =   get_window_text_a(hwnd, windowText);

            int res = ctxt.fn(hwnd, windowClassLen, windowClass.data(), windowTextLen, windowText.data(), ctxt.param);

            if(0 == res)
            {
                return true;
            }
            else
            {
                ctxt.hwnd = (res > 0) ? hwnd : NULL;

                return false;
            }
        }


    } context(fn, param);

    ::EnumChildWindows(hwndParent, context_t::f, stlsoft_c_cast(LPARAM, &context));

    return context.hwnd;
}


inline HWND find_child_window(
    HWND                hwndParent
,   ws_char_a_t const*  childClass
,   ws_char_a_t const*  childText
)
{
    struct param_t
    {
        HWND const                  m_hwnd;
        ws_char_a_t const* const    m_childClass;
        ws_char_a_t const* const    m_childText;

        param_t(HWND hwnd, ws_char_a_t const* childClass, ws_char_a_t const* childText)
            : m_hwnd(hwnd)
            , m_childClass(childClass)
            , m_childText(childText)
        {}

        int fn(
            HWND                hwnd
        ,   size_t              childClassLen
        ,   ws_char_a_t const*  childClass
        ,   size_t              childTextLen
        ,   ws_char_a_t const*  childText
        ) const
        {
            if(NULL != m_childClass)
            {
                size_t len = ::strlen(m_childClass);

                if( len != childClassLen ||
                    0 != _strnicmp(m_childClass, childClass, childClassLen))
                {
                    return 0;
                }
            }

            if(NULL != m_childText)
            {
                size_t len = ::strlen(m_childText);

                if( len != childTextLen ||
                    0 != _strnicmp(m_childText, childText, childTextLen))
                {
                    return 0;
                }
            }

            return +1;
        }

        static int STLSOFT_STDCALL fn(
            HWND                hwnd
        ,   size_t              childClassLen
        ,   ws_char_a_t const*  childClass
        ,   size_t              childTextLen
        ,   ws_char_a_t const*  childText
        ,   void*               param
        )
        {
            param_t& this_ = *stlsoft_c_cast(param_t*, param);

            return this_.fn(hwnd, childClassLen, childClass, childTextLen, childText);
        }
    } param(NULL, childClass, childText);

    return find_child_window_a(hwndParent, param_t::fn, &param);
}



HWND find_window_by_pattern_cc_a(
    ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_CDECL *pfnMatch_cdecl)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   ws_uint32_t         flags
    )
,   int (STLSOFT_STDCALL *pfnMatch_stdcall)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   ws_uint32_t         flags
    )
,   ws_uint32_t             flags
,   int                     cc
)
{
    struct param_t
    {
        typedef int (STLSOFT_CDECL *pfnMatch_cdecl_t)(
            ws_char_a_t const*  pattern
        ,   ws_char_a_t const*  string
        ,   ws_uint32_t         flags
        );
        typedef int (STLSOFT_STDCALL *pfnMatch_stdcall_t)(
            ws_char_a_t const*  pattern
        ,   ws_char_a_t const*  string
        ,   ws_uint32_t         flags
        );

        ws_char_a_t const* const    m_classPattern;
        ws_char_a_t const* const    m_textPattern;
        pfnMatch_cdecl_t const      m_pfnMatch_cdecl;
        pfnMatch_stdcall_t const    m_pfnMatch_stdcall;
        ws_uint32_t const           m_flags;

        param_t(
            ws_char_a_t const*      classPattern
        ,   ws_char_a_t const*      textPattern
        ,   pfnMatch_cdecl_t        pfnMatch_cdecl
        ,   pfnMatch_stdcall_t      pfnMatch_stdcall
        ,   ws_uint32_t             flags
        )
            : m_classPattern(classPattern)
            , m_textPattern(textPattern)
            , m_pfnMatch_cdecl(pfnMatch_cdecl)
            , m_pfnMatch_stdcall(pfnMatch_stdcall)
            , m_flags(flags)
        {}

        static int STLSOFT_STDCALL fn(
            HWND                hwnd
        ,   size_t              windowClassLen
        ,   ws_char_a_t const*  windowClass
        ,   size_t              windowTextLen
        ,   ws_char_a_t const*  windowText
        ,   void*               param
        )
        {
            param_t& p = *stlsoft_static_cast(param_t*, param);

            return p.fn(hwnd, (0 == windowClassLen) ? "" : windowClass, (0 == windowTextLen) ? "" : windowText);
        }

        int fn(HWND hwnd, ws_char_a_t const* windowClass, ws_char_a_t const* windowText) const
        {
            if(NULL != m_classPattern)
            {
                int res = match(m_classPattern, windowClass, m_flags);

                if(res < 0)
                {
                    return -1;
                }
                else if(0 != res)
                {
                    return 0;
                }
            }

            if(NULL != m_textPattern)
            {
                int res = match(m_textPattern, windowText, m_flags);

                if(res < 0)
                {
                    return -1;
                }
                else if(0 != res)
                {
                    return 0;
                }
            }

            return +1;
        }

        int match(ws_char_a_t const* pattern, ws_char_a_t const* string, ws_uint32_t flags) const
        {
            if(NULL != m_pfnMatch_cdecl)
            {
                return m_pfnMatch_cdecl(pattern, string, flags);
            }
            else
            {
                return m_pfnMatch_stdcall(pattern, string, flags);
            }
        }

    } param(classPattern, textPattern, pfnMatch_cdecl, pfnMatch_stdcall, flags);

    return find_window_a(param_t::fn, &param);
}

HWND find_window_by_pattern(
    ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_CDECL *pfnMatch)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   ws_uint32_t         flags
    )
,   ws_uint32_t             flags
)
{
    return find_window_by_pattern_cc_a(classPattern, textPattern, pfnMatch, NULL, flags, STLSOFT_CDECL_VALUE);
}

HWND find_window_by_pattern(
    ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_STDCALL *pfnMatch)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   ws_uint32_t         flags
    )
,   ws_uint32_t             flags
)
{
    return find_window_by_pattern_cc_a(classPattern, textPattern, NULL, pfnMatch, flags, STLSOFT_STDCALL_VALUE);
}

#if (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC)) && \
    _MSC_VER == 1200
HWND find_window_by_pattern(
    ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_CDECL *pfnMatch)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   unsigned int        flags
    )
,   ws_uint32_t             flags
)
{
    return find_window_by_pattern(classPattern, textPattern, (int (STLSOFT_CDECL*)(ws_char_a_t const*, ws_char_a_t const*, ws_uint32_t))pfnMatch, flags);
}

HWND find_window_by_pattern(
    ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_STDCALL *pfnMatch)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   unsigned int        flags
    )
,   unsigned int            flags
)
{
    return find_window_by_pattern(classPattern, textPattern, (int (STLSOFT_STDCALL*)(ws_char_a_t const*, ws_char_a_t const*, ws_uint32_t))pfnMatch, flags);
}
#endif



HWND find_child_window_by_pattern_cc_a(
    HWND                    hwndParent
,   ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_CDECL *pfnMatch_cdecl)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   ws_uint32_t         flags
    )
,   int (STLSOFT_STDCALL *pfnMatch_stdcall)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   ws_uint32_t         flags
    )
,   ws_uint32_t             flags
,   int                     cc
)
{
    struct param_t
    {
        typedef int (STLSOFT_CDECL *pfnMatch_cdecl_t)(
            ws_char_a_t const*  pattern
        ,   ws_char_a_t const*  string
        ,   ws_uint32_t         flags
        );
        typedef int (STLSOFT_STDCALL *pfnMatch_stdcall_t)(
            ws_char_a_t const*  pattern
        ,   ws_char_a_t const*  string
        ,   ws_uint32_t         flags
        );

        ws_char_a_t const* const    m_classPattern;
        ws_char_a_t const* const    m_textPattern;
        pfnMatch_cdecl_t const      m_pfnMatch_cdecl;
        pfnMatch_stdcall_t const    m_pfnMatch_stdcall;
        ws_uint32_t const           m_flags;

        param_t(
            ws_char_a_t const*      classPattern
        ,   ws_char_a_t const*      textPattern
        ,   pfnMatch_cdecl_t        pfnMatch_cdecl
        ,   pfnMatch_stdcall_t      pfnMatch_stdcall
        ,   ws_uint32_t             flags
        )
            : m_classPattern(classPattern)
            , m_textPattern(textPattern)
            , m_pfnMatch_cdecl(pfnMatch_cdecl)
            , m_pfnMatch_stdcall(pfnMatch_stdcall)
            , m_flags(flags)
        {}

        static int STLSOFT_STDCALL fn(
            HWND                hwnd
        ,   size_t              windowClassLen
        ,   ws_char_a_t const*  windowClass
        ,   size_t              windowTextLen
        ,   ws_char_a_t const*  windowText
        ,   void*               param
        )
        {
            param_t& p = *stlsoft_static_cast(param_t*, param);

            return p.fn(hwnd, (0 == windowClassLen) ? "" : windowClass, (0 == windowTextLen) ? "" : windowText);
        }

        int fn(HWND hwnd, ws_char_a_t const* windowClass, ws_char_a_t const* windowText) const
        {
            if(NULL != m_classPattern)
            {
                int res = match(m_classPattern, windowClass, m_flags);

                if(res < 0)
                {
                    return -1;
                }
                else if(0 != res)
                {
                    return 0;
                }
            }

            if(NULL != m_textPattern)
            {
                int res = match(m_textPattern, windowText, m_flags);

                if(res < 0)
                {
                    return -1;
                }
                else if(0 != res)
                {
                    return 0;
                }
            }

            return +1;
        }

        int match(ws_char_a_t const* pattern, ws_char_a_t const* string, ws_uint32_t flags) const
        {
            if(NULL != m_pfnMatch_cdecl)
            {
                return m_pfnMatch_cdecl(pattern, string, flags);
            }
            else
            {
                return m_pfnMatch_stdcall(pattern, string, flags);
            }
        }

    } param(classPattern, textPattern, pfnMatch_cdecl, pfnMatch_stdcall, flags);

    return find_child_window_a(hwndParent, param_t::fn, &param);
}

inline HWND find_child_window_by_pattern(
    HWND                    hwndParent
,   ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_CDECL *pfnMatch)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   ws_uint32_t         flags
    )
,   ws_uint32_t             flags
)
{
    return find_child_window_by_pattern_cc_a(hwndParent, classPattern, textPattern, pfnMatch, NULL, flags, STLSOFT_CDECL_VALUE);
}

inline HWND find_child_window_by_pattern(
    HWND                    hwndParent
,   ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_STDCALL *pfnMatch)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   ws_uint32_t         flags
    )
,   ws_uint32_t             flags
)
{
    return find_child_window_by_pattern_cc_a(hwndParent, classPattern, textPattern, NULL, pfnMatch, flags, STLSOFT_STDCALL_VALUE);
}

#if (   defined(STLSOFT_COMPILER_IS_INTEL) || \
        defined(STLSOFT_COMPILER_IS_MSVC)) && \
    _MSC_VER == 1200
inline HWND find_child_window_by_pattern(
    HWND                    hwndParent
,   ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_CDECL *pfnMatch)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   unsigned int        flags
    )
,   ws_uint32_t             flags
)
{
    return find_child_window_by_pattern(hwndParent, classPattern, textPattern, (int (STLSOFT_CDECL*)(ws_char_a_t const*, ws_char_a_t const*, ws_uint32_t))pfnMatch, flags);
}

inline HWND find_child_window_by_pattern(
    HWND                    hwndParent
,   ws_char_a_t const*      classPattern
,   ws_char_a_t const*      textPattern
,   int (STLSOFT_STDCALL *pfnMatch)(
        ws_char_a_t const*  pattern
    ,   ws_char_a_t const*  string
    ,   unsigned int        flags
    )
,   ws_uint32_t             flags
)
{
    return find_child_window_by_pattern(hwndParent, classPattern, textPattern, (int (STLSOFT_STDCALL*)(ws_char_a_t const*, ws_char_a_t const*, ws_uint32_t))pfnMatch, flags);
}
#endif


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

#endif /* WINSTL_INCL_WINSTL_WINDOW_HPP_SEARCH_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
