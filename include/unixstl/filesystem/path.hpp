/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/path.hpp
 *
 * Purpose:     Simple class that represents a path.
 *
 * Created:     1st May 1993
 * Updated:     8th June 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1993-2010, Matthew Wilson and Synesis Software
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

/** \file unixstl/filesystem/path.hpp
 *
 * \brief [OBSOLETE; C++ only] Users of STLSoft 1.10+ should change to using
 *   the PlatformSTL basic_path component, defined in
 *   platformstl/filesystem/path.hpp
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PATH_MAJOR      7
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PATH_MINOR      0
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PATH_REVISION   5
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_PATH_EDIT       239
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <unixstl/unixstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH
# include <platformstl/filesystem/path.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PATH */

#include <stlsoft/memory/allocator_selector.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifdef UNIXSTL_NO_NAMESPACE
# define This component is no longer available for use in compilations with the unixstl namespace suppressed
#endif /* UNIXSTL_NO_NAMESPACE */
#ifdef STLSOFT_NO_NAMESPACE
# define This component is no longer available for use in compilations with the stlsoft namespace suppressed
#endif /* STLSOFT_NO_NAMESPACE */

namespace stlsoft
{
namespace unixstl_project
{

/* /////////////////////////////////////////////////////////////////////////
 * basic_path
 */

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

    template<   ss_typename_param_k C
#  ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
            ,   ss_typename_param_k T = unixstl_ns_qual(filesystem_traits)<C>
            ,   ss_typename_param_k A = ss_typename_type_def_k stlsoft_ns_qual(allocator_selector)<C>::allocator_type
#  else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            ,   ss_typename_param_k T /* = filesystem_traits<C> */
            ,   ss_typename_param_k A /* = ss_typename_type_def_k stlsoft::allocator_selector<C>::allocator_type */
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


    typedef basic_path<us_char_a_t>                 path_a;
    typedef basic_path<us_char_w_t>                 path_w;

# else /* compiler */

    using ::platformstl::basic_path;

    typedef ::platformstl::basic_path<us_char_a_t>  path_a;
    typedef ::platformstl::basic_path<us_char_w_t>  path_w;

# endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace unixstl_project */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_PATH */

/* ///////////////////////////// end of file //////////////////////////// */
