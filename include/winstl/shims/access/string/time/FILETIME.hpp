/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/access/string/time/FILETIME.hpp
 *
 * Purpose:     Helper functions for the FILETIME structures.
 *
 * Created:     2nd December 2004
 * Updated:     7th November 2014
 *
 * Thanks to:   David Wang, for spotting an error in one of the shim
 *              functions.
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2014, Matthew Wilson and Synesis Software
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


/** \file winstl/shims/access/string/time/FILETIME.hpp
 *
 * \brief [C++] Definition of the string access shims for the Windows
 *   <code>FILETIME</code> structure
 *   (\ref group__concept__shim__string_access "String Access Shims" Concept).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME
#define WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME_MAJOR      3
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME_MINOR      0
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME_REVISION   2
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME_EDIT       59
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME
# include <winstl/shims/access/string/time/SYSTEMTIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME */

#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_SYSTEMTIME_HPP_FILETIME
# include <winstl/shims/conversion/to_SYSTEMTIME/FILETIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_SYSTEMTIME_HPP_FILETIME */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */

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
 * Helper Classes
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
struct ximpl_winstl_shims_access_string_time_FILETIME
{
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 */

// FILETIME

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_a(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_a(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_a(
    FILETIME const& t
)
{
    return c_str_ptr_a(t, ws_false_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_w(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_w(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_w(
    FILETIME const& t
)
{
    return c_str_ptr_w(t, ws_false_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr(
    FILETIME const& t
)
{
    return c_str_ptr(t, ws_false_v);
}


/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 */

// FILETIME

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_data_a(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_a(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_data_a(
    FILETIME const& t
)
{
    return c_str_data_a(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_data_w(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_w(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_data_w(
    FILETIME const& t
)
{
    return c_str_data_w(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_data(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_data(
    FILETIME const& t
)
{
    return c_str_data(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}


/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 */

// FILETIME

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_null_a(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_null_a(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_null_a(
    FILETIME const& t
)
{
    return c_str_ptr_null_a(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}


inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_null_w(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_null_w(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_null_w(
    FILETIME const& t
)
{
    return c_str_ptr_null_w(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}


inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr_null(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_null(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr_null(
    FILETIME const& t
)
{
    return c_str_ptr_null(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}


/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * NOTE: The following are provided as function overloads, rather than, as
 * originally implemented, with defaulted bMilliseconds argument, because
 * DMC++ gives "ambiguous reference to symbol" errors. (And I didn't have
 * time to investigate further.)
 */

// FILETIME

inline
ws_size_t
c_str_len_a(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_len_a(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
ws_size_t
c_str_len_a(
    FILETIME const& t
)
{
    return c_str_len_a(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}

inline
ws_size_t
c_str_len_w(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_len_w(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
ws_size_t
c_str_len_w(
    FILETIME const& t
)
{
    return c_str_len_w(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}


inline
ws_size_t
c_str_len(
    FILETIME const& t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_len(winstl_ns_qual(to_SYSTEMTIME)(t), bMilliseconds);
}
inline
ws_size_t
c_str_len(
    FILETIME const& t
)
{
    return c_str_len(winstl_ns_qual(to_SYSTEMTIME)(t), ws_false_v);
}


/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */

namespace stlsoft
{
    using ::winstl::c_str_ptr_null;
    using ::winstl::c_str_ptr_null_a;
    using ::winstl::c_str_ptr_null_w;

    using ::winstl::c_str_ptr;
    using ::winstl::c_str_ptr_a;
    using ::winstl::c_str_ptr_w;

    using ::winstl::c_str_data;
    using ::winstl::c_str_data_a;
    using ::winstl::c_str_data_w;

    using ::winstl::c_str_len;

    using ::winstl::c_str_len_a;
    using ::winstl::c_str_len_w;

} /* namespace stlsoft */

#endif /* !WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME */

/* ///////////////////////////// end of file //////////////////////////// */
