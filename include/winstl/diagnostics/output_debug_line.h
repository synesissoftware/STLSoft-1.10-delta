/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/diagnostics/output_debug_line.h
 *
 * Purpose:     Functions to write lines to the Windows debugger.
 *
 * Created:     5th January 2011
 * Updated:     7th November 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2011-2014, Matthew Wilson and Synesis Software
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


/** \file winstl/diagnostics/output_debug_line.h
 *
 * \brief [C++ only] Functions to write lines to the Windows debugger.
 *   (\ref group__library__windows_diagnostics "Windows Diagnostics" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE
#define WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE_MAJOR    1
# define WINSTL_VER_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE_MINOR    1
# define WINSTL_VER_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE_REVISION 4
# define WINSTL_VER_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE_EDIT     7
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

#include <stlsoft/shims/access/string/std/c_string.h>

#include <stdarg.h>
#include <string.h>

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
namespace diagnostics
{
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

STLSOFT_INLINE
stlsoft_ns_qual(ss_size_t)
stlsoft_C_concatenate_N_m(
    stlsoft_ns_qual(ss_char_a_t)*           buff
,   stlsoft_ns_qual(ss_size_t)              cchBuff
,   stlsoft_ns_qual(ss_char_a_t) const**    psz
,   stlsoft_ns_qual(ss_size_t)              n
,   ...
)
{
    stlsoft_ns_using(ss_char_a_t);
    stlsoft_ns_using(ss_size_t);

    {
        ss_size_t total = 0;

        {
            va_list     args;
            ss_size_t   i;

            va_start(args, n);

            for(i = 0; i != n; ++i)
            {
                ss_char_a_t const*  s   =   va_arg(args, ss_char_a_t const*);
                ss_size_t           len =   stlsoft_ns_qual(c_str_len_a)(s);

                total += len;
            }

            va_end(args);
        }

        {
            va_list         args;
            ss_size_t       i;
            ss_char_a_t*    dest;

            if(total + 1 > cchBuff)
            {
                dest = stlsoft_static_cast(stlsoft_ns_qual(ss_char_a_t)*, STLSOFT_NS_GLOBAL(malloc)(sizeof(ss_char_a_t) * (1 + total)));

                if(NULL == dest)
                {
                    *psz = NULL;

                    return 0;
                }
            }
            else
            {
                dest = buff;
            }

            *psz = dest;

            va_start(args, n);

            for(i = 0; i != n; ++i)
            {
                ss_char_a_t const*  s   =   va_arg(args, ss_char_a_t const*);
                ss_size_t           len =   stlsoft_ns_qual(c_str_len_a)(s);

                STLSOFT_NS_GLOBAL(memcpy)(dest, s, sizeof(ss_char_a_t) * len);
                dest += len;
            }
            *dest = '\0';

            va_end(args);

            return total;
        }
    }
}

STLSOFT_INLINE
void
stlsoft_C_concatenate_free_m(
    stlsoft_ns_qual(ss_char_a_t)*       buff
,   stlsoft_ns_qual(ss_char_a_t) const* psz
)
{
    if(buff != psz)
    {
        STLSOFT_NS_GLOBAL(free)(stlsoft_const_cast(stlsoft_ns_qual(ss_char_a_t)*, psz));
    }
}

/* ////////////////////////////////////////////////////////////////////// */

/* This is provided to facilitate unit-testing */
#ifndef WINSTL_DIAGNOSTICS_OUTPUT_DEBUG_LINE_SUPPRESS_ODS_

STLSOFT_INLINE
void
winstl_C_call_OutputDebugStringA_(
    winstl_ns_qual(ws_char_a_t) const* s
)
{
    if(NULL != s)
    {
        STLSOFT_NS_GLOBAL(OutputDebugStringA)(s);
    }
}

#endif /* WINSTL_DIAGNOSTICS_OUTPUT_DEBUG_LINE_SUPPRESS_ODS_ */

/* ////////////////////////////////////////////////////////////////////// */

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_1_m(
    winstl_ns_qual(ws_char_a_t) const* s0
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 2u, s0, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_2_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 3u, s0, s1, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_3_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 4u, s0, s1, s2, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_4_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 5u, s0, s1, s2, s3, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_5_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 6u, s0, s1, s2, s3, s4, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_6_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 7u, s0, s1, s2, s3, s4, s5, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_7_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
,   winstl_ns_qual(ws_char_a_t) const* s6
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 8u, s0, s1, s2, s3, s4, s5, s6, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_8_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
,   winstl_ns_qual(ws_char_a_t) const* s6
,   winstl_ns_qual(ws_char_a_t) const* s7
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 9u, s0, s1, s2, s3, s4, s5, s6, s7, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_9_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
,   winstl_ns_qual(ws_char_a_t) const* s6
,   winstl_ns_qual(ws_char_a_t) const* s7
,   winstl_ns_qual(ws_char_a_t) const* s8
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 10u, s0, s1, s2, s3, s4, s5, s6, s7, s8, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_10_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
,   winstl_ns_qual(ws_char_a_t) const* s6
,   winstl_ns_qual(ws_char_a_t) const* s7
,   winstl_ns_qual(ws_char_a_t) const* s8
,   winstl_ns_qual(ws_char_a_t) const* s9
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 11u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_11_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
,   winstl_ns_qual(ws_char_a_t) const* s6
,   winstl_ns_qual(ws_char_a_t) const* s7
,   winstl_ns_qual(ws_char_a_t) const* s8
,   winstl_ns_qual(ws_char_a_t) const* s9
,   winstl_ns_qual(ws_char_a_t) const* s10
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 12u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_(s10);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

STLSOFT_INLINE
void
winstl_C_diagnostics_output_debug_line_12_m(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
,   winstl_ns_qual(ws_char_a_t) const* s6
,   winstl_ns_qual(ws_char_a_t) const* s7
,   winstl_ns_qual(ws_char_a_t) const* s8
,   winstl_ns_qual(ws_char_a_t) const* s9
,   winstl_ns_qual(ws_char_a_t) const* s10
,   winstl_ns_qual(ws_char_a_t) const* s11
)
{
    winstl_ns_using(ws_char_a_t);

    {
#ifdef _DEBUG
        ws_char_a_t         buff[10];
#else /* ? _DEBUG */
        ws_char_a_t         buff[1000];
#endif /* _DEBUG */
        ws_char_a_t const*  psz;

        if(0 == stlsoft_C_concatenate_N_m(buff, STLSOFT_NUM_ELEMENTS(buff), &psz, 13u, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, "\n"))
        {
            winstl_C_call_OutputDebugStringA_(s0);
            winstl_C_call_OutputDebugStringA_(s1);
            winstl_C_call_OutputDebugStringA_(s2);
            winstl_C_call_OutputDebugStringA_(s3);
            winstl_C_call_OutputDebugStringA_(s4);
            winstl_C_call_OutputDebugStringA_(s5);
            winstl_C_call_OutputDebugStringA_(s6);
            winstl_C_call_OutputDebugStringA_(s7);
            winstl_C_call_OutputDebugStringA_(s8);
            winstl_C_call_OutputDebugStringA_(s9);
            winstl_C_call_OutputDebugStringA_(s10);
            winstl_C_call_OutputDebugStringA_(s11);
            winstl_C_call_OutputDebugStringA_("\n");
        }
        else
        {
            winstl_C_call_OutputDebugStringA_(psz);

            stlsoft_C_concatenate_free_m(buff, psz);
        }
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef WINSTL_NO_NAMESPACE
} /* namespace diagnostics */
# if defined(STLSOFT_NO_NAMESPACE) || \
         defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
namespace winstl = ::stlsoft::winstl_project;
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE */

/* ///////////////////////////// end of file //////////////////////////// */
