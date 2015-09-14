/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/path.hpp
 *
 * Purpose:     Simple class that represents a path.
 *
 * Created:     1st May 1993
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1993-2012, Matthew Wilson and Synesis Software
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

/** \file winstl/filesystem/path.hpp
 *
 * \brief [OBSOLETE; C++ only] Users of STLSoft 1.10+ should change to using
 *   the PlatformSTL basic_path component, defined in
 *   platformstl/filesystem/path.hpp
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH
#define WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_MAJOR    7
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_MINOR    0
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_REVISION 5
# define WINSTL_VER_WINSTL_FILESYSTEM_HPP_PATH_EDIT     260
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
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH
# include <platformstl/filesystem/path.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH */

#include <winstl/memory/processheap_allocator.hpp>

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
 * basic_path
 */

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

    template<   ss_typename_param_k C
#  ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
            ,   ss_typename_param_k T = winstl_ns_qual(filesystem_traits)<C>
            ,   ss_typename_param_k A = winstl_ns_qual(processheap_allocator)<C>
#  else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            ,   ss_typename_param_k T /* = filesystem_traits<C> */
            ,   ss_typename_param_k A /* = processheap_allocator<C> */
#  endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_path
        : public platformstl_ns_qual(basic_path_x_)<C, T, A>
    {
    private:
        typedef platformstl_ns_qual(basic_path_x_)<C, T, A>             parent_class_type;
        typedef basic_path<C, T, A>                                     class_type;
    public:
        typedef ss_typename_type_k parent_class_type::char_type         char_type;
        typedef ss_typename_type_k parent_class_type::traits_type       traits_type;
        typedef ss_typename_type_k parent_class_type::allocator_type    allocator_type;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;

    public:
        basic_path()
            : parent_class_type()
        {}
        ss_explicit_k basic_path(char_type const* path)
            : parent_class_type(path)
        {}
        basic_path(parent_class_type const& s)
            : parent_class_type(s)
        {}
#  ifdef STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
        /// Constructs a path from \c path
        template<ss_typename_param_k S>
        ss_explicit_k basic_path(S const& s)
            : parent_class_type(s)
        {}
#  endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
        basic_path(char_type const* path, size_type cch)
            : parent_class_type(path, cch)
        {}
        basic_path(class_type const& rhs)
            : parent_class_type(rhs)
        {}

#if 0
        class_type& operator =(class_type const& rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
        class_type& operator =(parent_class_type const& rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
        class_type& operator =(char_type const* rhs)
        {
            parent_class_type::operator =(rhs);

            return *this;
        }
#endif /* 0 */
#  ifdef STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
        template<ss_typename_param_k S>
        class_type& operator =(S const& s)
        {
            parent_class_type::operator =(s);

            return *this;
        }
#  endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    };

    typedef basic_path<ws_char_a_t>                 path_a;
    typedef basic_path<ws_char_w_t>                 path_w;
    typedef basic_path<TCHAR>                       path;

# else /* compiler */

    using ::platformstl::basic_path;

    typedef ::platformstl::basic_path<ws_char_a_t>  path_a;
    typedef ::platformstl::basic_path<ws_char_w_t>  path_w;
    typedef ::platformstl::basic_path<TCHAR>        path;

# endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace winstl_project */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_FILESYSTEM_HPP_PATH */

/* ///////////////////////////// end of file //////////////////////////// */
