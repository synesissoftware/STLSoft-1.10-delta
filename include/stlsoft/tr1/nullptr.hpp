/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/tr1/nullptr.hpp
 *
 * Purpose:     Include for defining nullptr to be the NULL_v template class.
 *
 * Created:     28th April 2010
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2010-2012, Matthew Wilson and Synesis Software
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


/** \file stlsoft/tr1/nullptr.hpp
 *
 * \brief [C++ only] Defines the \c nullptr preprocessor symbol as
 *   stlsoft::NULL_v() (except for compilers that support C++ 0x)
 *   (\ref group__library__utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_TR1_HPP_NULLPTR
#define STLSOFT_INCL_STLSOFT_TR1_HPP_NULLPTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_TR1_HPP_NULLPTR_MAJOR    1
# define STLSOFT_VER_STLSOFT_TR1_HPP_NULLPTR_MINOR    0
# define STLSOFT_VER_STLSOFT_TR1_HPP_NULLPTR_REVISION 2
# define STLSOFT_VER_STLSOFT_TR1_HPP_NULLPTR_EDIT     4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_CF_BUILTIN_nullptr_SUPPORT
# ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_NULL
#  include <stlsoft/util/null.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_NULL */
#endif /* !STLSOFT_CF_BUILTIN_nullptr_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * Definitions
 */

#ifndef STLSOFT_CF_BUILTIN_nullptr_SUPPORT
# ifndef STLSOFT_nullptr_DEFINED
#  if defined(_STLSOFT_NULL_v_DEFINED) || \
      defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
  /// \def nullptr
  ///
  /// By including this file, \c nullptr is (re-)defined to be
  /// <code>stlsoft::NULL_v()</code>
  /// which means that any use of \c nullptr must be with pointer types.
#   define nullptr                          stlsoft_ns_qual(NULL_v)::create()
#   define STLSOFT_nullptr_DEFINED
#  else /* ? _STLSOFT_NULL_v_DEFINED */
#   define nullptr                          NULL
#  endif /* _STLSOFT_NULL_v_DEFINED */
# endif /* STLSOFT_nullptr_DEFINED */
#endif /* !STLSOFT_CF_BUILTIN_nullptr_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_TR1_HPP_NULLPTR */

/* ///////////////////////////// end of file //////////////////////////// */
