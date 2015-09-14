/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/directory.hpp
 *
 * Purpose:     Simple class that provides directory operations.
 *
 * Created:     1st May 2014
 * Updated:     20th July 2014
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

/** \file winstl/filesystem/directory.hpp
 *
 * \brief [C++ only] Simple class that provides directory operations
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_DIRECTORY_MAJOR       1
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_DIRECTORY_MINOR       0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_DIRECTORY_REVISION    2
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_DIRECTORY_EDIT        2
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
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <winstl/filesystem/filesystem_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifdef WINSTL_NO_NAMESPACE
# define This component is no longer available for use in compilations with the winstl namespace suppressed
#endif /* WINSTL_NO_NAMESPACE */
#ifdef STLSOFT_NO_NAMESPACE
# define This component is no longer available for use in compilations with the stlsoft namespace suppressed
#endif /* STLSOFT_NO_NAMESPACE */

namespace stlsoft
{
namespace winstl_project
{

/* /////////////////////////////////////////////////////////////////////////
 * basic_directory
 */

template<
    ss_typename_param_k C
#  ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
,   ss_typename_param_k T = winstl_ns_qual(filesystem_traits)<C>
,   ss_typename_param_k A = winstl_ns_qual(processheap_allocator)<C>
#  else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k T /* = filesystem_traits<C> */
,   ss_typename_param_k A /* = processheap_allocator<C> */
#  endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class basic_directory
{
public: // Types
    /// The char type
    typedef C                           char_type;
    /// The traits type
    typedef T                           traits_type;
    /// The allocator type
    typedef A                           allocator_type;
    /// The current parameterisation of the type
    typedef basic_directory<C, T, A>    class_type;
    /// The size type
    typedef ss_size_t                   size_type;
    /// The Boolean type
    typedef ss_bool_t                   bool_type;

public: // Construction
    ss_explicit_k basic_directory(
        char_type const*    path
    );

public: // Operations

private: // Fields
};

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/** Specialisation of the basic_directory template for the ANSI character type \c char
 *
 * \ingroup group__library__system
 */
typedef basic_directory<
    ws_char_a_t
>                                               directory_a;

/** Specialisation of the basic_directory template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__system
 */
typedef basic_directory<
    ws_char_w_t
>                                               directory_w;

/** Specialisation of the basic_directory template for the Windows character type \c TCHAR
 *
 * \ingroup group__library__system
 */
typedef basic_directory<
    TCHAR
>                                               directory_t;

/** 
 *
 * \ingroup group__library__system
 */
typedef directory_t                             directory;

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline
basic_directory<C, T, A>::basic_directory(
	ss_typename_type_k basic_directory<C, T, A>::char_type const* path
)
{
	if(!traits_type::is_directory(path))
	{
		// TODO: proper exception type
		STLSOFT_THROW_X(std::runtime_error("path does not exist or is not a directory"));
	}
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace winstl_project */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_FILESYSTEM_HPP_DIRECTORY */

/* ///////////////////////////// end of file //////////////////////////// */
