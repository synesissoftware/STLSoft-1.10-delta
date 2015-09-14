/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/diagnostics/output_debug_line.hpp
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


/** \file winstl/diagnostics/output_debug_line.hpp
 *
 * \brief [C++ only] Functions to write lines to the Windows debugger.
 *   (\ref group__library__windows_diagnostics "Windows Diagnostics" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_OUTPUT_DEBUG_LINE
#define WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_OUTPUT_DEBUG_LINE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_OUTPUT_DEBUG_LINE_MAJOR      1
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_OUTPUT_DEBUG_LINE_MINOR      1
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_OUTPUT_DEBUG_LINE_REVISION   4
# define WINSTL_VER_WINSTL_DIAGNOSTICS_HPP_OUTPUT_DEBUG_LINE_EDIT       6
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

#ifndef WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE
# include <winstl/diagnostics/output_debug_line.h>
#endif /* !WINSTL_INCL_WINSTL_DIAGNOSTICS_H_OUTPUT_DEBUG_LINE */

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

inline
void
output_debug_line(
    winstl_ns_qual(ws_char_a_t) const* s0
)
{
    winstl_C_diagnostics_output_debug_line_1_m(s0);
}

inline
void
output_debug_line(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
)
{
    winstl_C_diagnostics_output_debug_line_2_m(s0, s1);
}

inline
void
output_debug_line(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
)
{
    winstl_C_diagnostics_output_debug_line_3_m(s0, s1, s2);
}

inline
void
output_debug_line(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
)
{
    winstl_C_diagnostics_output_debug_line_4_m(s0, s1, s2, s3);
}

inline
void
output_debug_line(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
)
{
    winstl_C_diagnostics_output_debug_line_5_m(s0, s1, s2, s3, s4);
}

inline
void
output_debug_line(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
)
{
    winstl_C_diagnostics_output_debug_line_6_m(s0, s1, s2, s3, s4, s5);
}

inline
void
output_debug_line(
    winstl_ns_qual(ws_char_a_t) const* s0
,   winstl_ns_qual(ws_char_a_t) const* s1
,   winstl_ns_qual(ws_char_a_t) const* s2
,   winstl_ns_qual(ws_char_a_t) const* s3
,   winstl_ns_qual(ws_char_a_t) const* s4
,   winstl_ns_qual(ws_char_a_t) const* s5
,   winstl_ns_qual(ws_char_a_t) const* s6
)
{
    winstl_C_diagnostics_output_debug_line_7_m(s0, s1, s2, s3, s4, s5, s6);
}

inline
void
output_debug_line(
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
    winstl_C_diagnostics_output_debug_line_8_m(s0, s1, s2, s3, s4, s5, s6, s7);
}

inline
void
output_debug_line(
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
    winstl_C_diagnostics_output_debug_line_9_m(s0, s1, s2, s3, s4, s5, s6, s7, s8);
}

inline
void
output_debug_line(
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
    winstl_C_diagnostics_output_debug_line_10_m(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
}

inline
void
output_debug_line(
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
    winstl_C_diagnostics_output_debug_line_11_m(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10);
}

inline
void
output_debug_line(
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
    winstl_C_diagnostics_output_debug_line_12_m(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11);
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

#endif /* WINSTL_INCL_WINSTL_DIAGNOSTICS_HPP_OUTPUT_DEBUG_LINE */

/* ///////////////////////////// end of file //////////////////////////// */
