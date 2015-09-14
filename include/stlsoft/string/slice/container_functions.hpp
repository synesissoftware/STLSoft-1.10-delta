/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/slice/container_functions.hpp
 *
 * Purpose:     String container slice functions.
 *
 * Created:     25th April 2005
 * Updated:     24th July 2012
 *
 * Thanks:      To Pablo Aguilar for inspiration for these functions.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2012, Matthew Wilson and Synesis Software
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


/** \file stlsoft/string/slice/container_functions.hpp
 *
 * \brief [C++ only] String container slice functions
 *   (\ref group__library__string "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_SLICE_HPP_CONTAINER_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_SLICE_HPP_CONTAINER_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_STRING_SLICE_HPP_CONTAINER_FUNCTIONS_MAJOR    3
# define STLSOFT_VER_INCL_STLSOFT_STRING_SLICE_HPP_CONTAINER_FUNCTIONS_MINOR    0
# define STLSOFT_VER_INCL_STLSOFT_STRING_SLICE_HPP_CONTAINER_FUNCTIONS_REVISION 2
# define STLSOFT_VER_INCL_STLSOFT_STRING_SLICE_HPP_CONTAINER_FUNCTIONS_EDIT     25
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[Incompatibilies-start]
STLSOFT_COMPILER_IS_WATCOM:
[Incompatibilies-end]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_TRAITS
# include <stlsoft/string/string_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_TRAITS */
#if !defined(STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE)
# if defined(STLSOFT_STRING_CONTAINERS_SLICE_FNS_USE_std_basic_string) || \
     defined(STLSOFT_STRING_CONTAINERS_SLICE_FNS_USE_STD_BASIC_STRING)
#  include <string>
# else /* ? std::basic_string */
#  ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
#   include <stlsoft/string/simple_string.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */
# endif /* std::basic_string */
#endif /* !STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX
# include <stlsoft/util/minmax.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_MINMAX */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

namespace ximpl_stlsoft_string_slice_container_
{

    template <ss_typename_param_k S>
    inline ss_size_t left_len(S const& s, ss_size_t n)
    {
        const ss_size_t len = stlsoft_ns_qual(c_str_len)(s);

        if(n > len)
        {
            n = len;
        }

        return n;
    }

} /* namespace ximpl_stlsoft_string_slice_container_ */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * String class functions
 */

/** \brief
 *
 * \ingroup group__library__string
 */
template <ss_typename_param_k S>
inline S left(S const& s, ss_size_t n)
{
    using namespace ximpl_stlsoft_string_slice_container_;

    typedef string_traits<S> traits_t;

    return traits_t::construct(s, 0, left_len(s, n));
}

/** \brief
 *
 * \ingroup group__library__string
 */
template <ss_typename_param_k S>
inline S right(S const& s, ss_size_t n)
{
    typedef string_traits<S> traits_t;

    const ss_size_t len = stlsoft_ns_qual(c_str_len)(s);

    if(n > len)
    {
        n = len;
    }

    return traits_t::construct(s, len - n, n);
}

/** \brief
 *
 * \ingroup group__library__string
 */
template <ss_typename_param_k S>
inline S mid(S const& s, ss_size_t pos, ss_size_t n)
{
    typedef string_traits<S> traits_t;

    const ss_size_t len = stlsoft_ns_qual(c_str_len)(s);

    if(pos > len)
    {
        pos = len;
    }

    if(n > len - pos)
    {
        n = len - pos;
    }

    return traits_t::construct(s, pos, n);
}

/* /////////////////////////////////////////////////////////////////////////
 * C-style string slice functions
 */

#if defined(STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE)
# define STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_  STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE
#elif defined(STLSOFT_STRING_CONTAINERS_SLICE_FNS_USE_std_basic_string) || \
      defined(STLSOFT_STRING_CONTAINERS_SLICE_FNS_USE_STD_BASIC_STRING)
# define STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_  stlsoft_ns_qual_std(basic_string)
#else /* ? STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE */
# define STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_  stlsoft_ns_qual(basic_simple_string)
#endif /* !STLSOFT_STRING_CONTAINER_SLICE_FNS_STRING_TEMPLATE */


/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> left(ss_char_a_t const* s, ss_size_t n)
{
    using namespace ximpl_stlsoft_string_slice_container_;

    typedef STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> string_t;

    return string_t(s, left_len(s, n));
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> left(ss_char_a_t *s, ss_size_t n)
{
    return left(const_cast<ss_char_a_t const*>(s), n);
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> left(ss_char_w_t const* s, ss_size_t n)
{
    using namespace ximpl_stlsoft_string_slice_container_;

    typedef STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> string_t;

    return string_t(s, left_len(s, n));
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> left(ss_char_w_t *s, ss_size_t n)
{
    return left(const_cast<ss_char_w_t const*>(s), n);
}


/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> right(ss_char_a_t const* s, ss_size_t n)
{
    typedef STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> string_t;

    const ss_size_t len = stlsoft_ns_qual(c_str_len)(s);

    if(n > len)
    {
        n = len;
    }

    return string_t(s + (len - n), n);
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> right(ss_char_a_t *s, ss_size_t n)
{
    return right(const_cast<ss_char_a_t const*>(s), n);
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> right(ss_char_w_t const* s, ss_size_t n)
{
    typedef STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> string_t;

    const ss_size_t len = stlsoft_ns_qual(c_str_len)(s);

    if(n > len)
    {
        n = len;
    }

    return string_t(s + (len - n), n);
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> right(ss_char_w_t *s, ss_size_t n)
{
    return right(const_cast<ss_char_w_t const*>(s), n);
}


/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> mid(ss_char_a_t const* s, ss_size_t pos, ss_size_t n)
{
    typedef STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> string_t;

    const ss_size_t len = stlsoft_ns_qual(c_str_len)(s);

    if(pos > len)
    {
        pos = len;
    }

    if(n > len - pos)
    {
        n = len - pos;
    }

    return string_t(s + pos, n);
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_a_t> mid(ss_char_a_t *s, ss_size_t pos, ss_size_t n)
{
    return mid(const_cast<ss_char_a_t const*>(s), pos, n);
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> mid(ss_char_w_t const* s, ss_size_t pos, ss_size_t n)
{
    typedef STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> string_t;

    const ss_size_t len = stlsoft_ns_qual(c_str_len)(s);

    if(pos > len)
    {
        pos = len;
    }

    if(n > len - pos)
    {
        n = len - pos;
    }

    return string_t(s + pos, n);
}

/** \brief
 *
 * \ingroup group__library__string
 */
inline STLSOFT_STRING_CONTAINER_SLICE_FUNCTIONS_RETURN_TEMPLATE_<ss_char_w_t> mid(ss_char_w_t *s, ss_size_t pos, ss_size_t n)
{
    return mid(const_cast<ss_char_w_t const*>(s), pos, n);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_SLICE_HPP_CONTAINER_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
