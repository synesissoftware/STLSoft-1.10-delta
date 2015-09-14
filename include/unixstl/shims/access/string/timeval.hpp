/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/shims/access/string/timeval.hpp
 *
 * Purpose:     String shims for UNIX timeval structure.
 *
 * Created:     5th May 2014
 * Updated:     9th May 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014, Matthew Wilson and Synesis Software
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


/** \file unixstl/shims/access/string/timeval.hpp
 *
 * \brief [C++] String shims for UNIX timeval structure
 *   (\ref group__concept__shim__string_access "String Access Shims" Concept).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_STRING_HPP_TIMEVAL
#define UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_STRING_HPP_TIMEVAL

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SHIMS_ACCESS_STRING_HPP_TIMEVAL_MAJOR      1
# define UNIXSTL_VER_UNIXSTL_SHIMS_ACCESS_STRING_HPP_TIMEVAL_MINOR      0
# define UNIXSTL_VER_UNIXSTL_SHIMS_ACCESS_STRING_HPP_TIMEVAL_REVISION   4
# define UNIXSTL_VER_UNIXSTL_SHIMS_ACCESS_STRING_HPP_TIMEVAL_EDIT       4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */
#ifndef STLSOFT_INCL_STLSOFT_TIME_UTIL_H_RAW_
# include <stlsoft/time/util/raw_.h>
#endif /* !STLSOFT_INCL_STLSOFT_TIME_UTIL_H_RAW_ */

#ifndef STLSOFT_INCL_H_TIME
# define STLSOFT_INCL_H_TIME
# include <time.h>
#endif /* !STLSOFT_INCL_H_TIME */
#ifndef STLSOFT_INCL_SYS_H_TIME
# define STLSOFT_INCL_SYS_H_TIME
# include <sys/time.h>
#endif /* !STLSOFT_INCL_SYS_H_TIME */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */
namespace stlsoft
{
namespace unixstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 *
 * All the struct timeval-related conversions assume a format of 27 characters
 */

/** \brief \ref group__concept__shim__string_access__c_str_data function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a C-style
 *   string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data_a(
    struct timeval const* tv
)
{
    typedef basic_shim_string<ss_char_a_t>  shim_string_t;

    shim_string_t s(28);

    if(NULL == tv)
    {
        s.truncate(0);
    }
    else
    {
		struct tm	tm;
		int const	e = ximpl_raw::gmtime_(&tm, &tv->tv_sec);

        if(0 != e)
        {
            s.truncate(14);
            s.write("(invalid time)");
        }
        else
        {
            ss_size_t const     n1  =   ::strftime(s.data(), 1 + s.size(), "%b %d %H:%M:%S.000000 %Y", &tm);
            ss_size_t			n2;

		    /* stlsoft_ns_qual(integer_to_decimal_string)(&s.data()[0] + 16, 7, tv->tv_usec, &n2); */
		    stlsoft_ns_qual(integer_to_decimal_string)(&s.data()[0], 16 + 7, static_cast< stlsoft_ns_qual(uint16_t)>(tv->tv_usec), &n2);
		    s.data()[22] = ' ';

            STLSOFT_ASSERT(27 == n1);
            STLSOFT_ASSERT(n2 <= 6);

            s.truncate(n1);
        }
    }

    return s;
}

/** \brief \ref group__concept__shim__string_access__c_str_data function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a C-style string.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data(
    struct timeval const* tv
)
{
    return c_str_data_a(tv);
}



/** \brief \ref group__concept__shim__string_access__c_str_len function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return Length (in bytes) of the string <code>s</code>.
 */
inline
ss_size_t
c_str_len_a(
    struct timeval const* tv
)
{
    if(NULL == tv)
    {
        return 0;
    }
    else
    {
		struct tm	tm;
		int const	e = ximpl_raw::gmtime_(&tm, &tv->tv_sec);

        if(0 != e)
        {
            return 14;
        }
        else
        {
            return 27;
        }
    }
}

/** \brief \ref group__concept__shim__string_access__c_str_len function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return Length of the string <code>s</code>.
 */
inline
ss_size_t
c_str_len(
    struct timeval const* tv
)
{
    return c_str_len_a(tv);
}



/** \brief \ref group__concept__shim__string_access__c_str_ptr function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return None-NULL, nul-terminated, non-mutating pointer to a C-style
 *   string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_a(
    struct timeval const* tv
)
{
    return c_str_data_a(tv);
}

/** \brief \ref group__concept__shim__string_access__c_str_ptr function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return None-NULL, nul-terminated, non-mutating pointer to a C-style
 *   string.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr(
    struct timeval const* tv
)
{
    return c_str_data_a(tv);
}



/** \brief \ref group__concept__shim__string_access__c_str_ptr_null function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return Possibly NULL, nul-terminated, non-mutating pointer to a C-style
 *   string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_null_a(
    struct timeval const* tv
)
{
    return c_str_data_a(tv);
}

/** \brief \ref group__concept__shim__string_access__c_str_ptr_null function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return Possibly NULL, nul-terminated, non-mutating pointer to a C-style
 *   string.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_null(
    struct timeval const* tv
)
{
    return c_str_data_a(tv);
}






/** \brief \ref group__concept__shim__string_access__c_str_data function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a C-style
 *   string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data(
    struct timeval const& tv
)
{
    return c_str_data(&tv);
}

/** \brief \ref group__concept__shim__string_access__c_str_data function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return None-NULL, non-mutating pointer to a C-style string.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_data_a(
    struct timeval const& tv
)
{
    return c_str_data_a(&tv);
}


/** \brief \ref group__concept__shim__string_access__c_str_len function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return Length (in bytes) of the string <code>s</code>.
 */
inline
ss_size_t
c_str_len_a(
    struct timeval const& tv
)
{
    return c_str_len_a(&tv);
}

/** \brief \ref group__concept__shim__string_access__c_str_len function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return Length of the string <code>s</code>.
 */
inline
ss_size_t
c_str_len(
    struct timeval const& tv
)
{
    return c_str_len(&tv);
}


/** \brief \ref group__concept__shim__string_access__c_str_ptr function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return None-NULL, nul-terminated, non-mutating pointer to a C-style
 *   string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_a(
    struct timeval const& tv
)
{
    return c_str_ptr_a(&tv);
}
/** \brief \ref group__concept__shim__string_access__c_str_ptr function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return None-NULL, nul-terminated, non-mutating pointer to a C-style
 *   string.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr(
    struct timeval const& tv
)
{
    return c_str_ptr(&tv);
}


/** \brief \ref group__concept__shim__string_access__c_str_ptr_null function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return Possibly NULL, nul-terminated, non-mutating pointer to a C-style
 *   string of <code>char</code>.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_null_a(
    struct timeval const& tv
)
{
    return c_str_ptr_null_a(&tv);
}
/** \brief \ref group__concept__shim__string_access__c_str_ptr_null function
 *    for <code>struct timeval</code>.
 *
 * \ingroup group__concept__shim__string_access
 *
 * \return Possibly NULL, nul-terminated, non-mutating pointer to a C-style
 *   string.
 */
inline
basic_shim_string<ss_char_a_t>
c_str_ptr_null(
    struct timeval const& tv
)
{
    return c_str_ptr_null(&tv);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace stlsoft::unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::unixstl::c_str_data_a;
using ::unixstl::c_str_data;

using ::unixstl::c_str_len_a;
using ::unixstl::c_str_len;

using ::unixstl::c_str_ptr_a;
using ::unixstl::c_str_ptr;

using ::unixstl::c_str_ptr_null_a;
using ::unixstl::c_str_ptr_null;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_STRING_HPP_TIMEVAL */

/* ///////////////////////////// end of file //////////////////////////// */
