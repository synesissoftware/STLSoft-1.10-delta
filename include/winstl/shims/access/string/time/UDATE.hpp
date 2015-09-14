/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/access/string/time/UDATE.hpp
 *
 * Purpose:     String access shims for the Windows UDATE structure.
 *
 * Created:     2nd December 2004
 * Updated:     29th May 2014
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


/** \file winstl/shims/access/string/time/UDATE.hpp
 *
 * \brief [C++] Definition of the string access shims for the Windows
 *   <code>UDATE</code> structure
 *   (\ref group__concept__shim__string_access "String Access Shims" Concept).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE
#define WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE_MAJOR     3
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE_MINOR     0
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE_REVISION  1
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE_EDIT      58
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_UDATE_DEFINED
# error UDATE is not defined. If you are certain that your compiler's Windows header files define this type, #define the symbol WINSTL_FORCE_UDATE
#endif /* !WINSTL_UDATE_DEFINED */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME
# include <winstl/shims/access/string/time/SYSTEMTIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING
# include <stlsoft/string/shim_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SHIM_STRING */
#ifdef WINSTL_UDATE_DEFINED
# include <objbase.h>
# include <oleauto.h>
#endif /* WINSTL_UDATE_DEFINED */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
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
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helper Classes
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
struct ximpl_winstl_shims_access_string_time_UDATE
{
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 */

#ifdef WINSTL_UDATE_DEFINED

// UDATE

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_a(
    UDATE const&    ud
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_a(ud.st, bMilliseconds);
}

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_a(
    UDATE const& ud
)
{
    return c_str_ptr_a(ud.st);
}

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_w(
    UDATE const&    ud
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_w(ud.st, bMilliseconds);
}

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_w(
    UDATE const& ud
)
{
    return c_str_ptr_w(ud.st);
}

inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr(
    UDATE const&    ud
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr(ud.st, bMilliseconds);
}

inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr(
    UDATE const& ud
)
{
    return c_str_ptr(ud.st);
}

#endif /* WINSTL_UDATE_DEFINED */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 */

// UDATE

#ifdef WINSTL_UDATE_DEFINED

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_data_a(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_a(t.st, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_data_a(
    UDATE const& t
)
{
    return c_str_data_a(t.st, ws_false_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_data_w(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_w(t.st, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_data_w(
    UDATE const& t
)
{
    return c_str_data_w(t.st, ws_false_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_data(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr(t.st, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_data(
    UDATE const& t
)
{
    return c_str_data(t.st, ws_false_v);
}

#endif /* WINSTL_UDATE_DEFINED */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 */

// UDATE

#ifdef WINSTL_UDATE_DEFINED

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_null_a(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_null_a(t.st, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_null_a(
    UDATE const& t
)
{
    return c_str_ptr_null_a(t.st, ws_false_v);
}


inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_null_w(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_null_w(t.st, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_null_w(
    UDATE const& t
)
{
    return c_str_ptr_null_w(t.st, ws_false_v);
}


inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr_null(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_ptr_null(t.st, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr_null(
    UDATE const& t
)
{
    return c_str_ptr_null(t.st, ws_false_v);
}

#endif /* WINSTL_UDATE_DEFINED */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * NOTE: The following are provided as function overloads, rather than, as
 * originally implemented, with defaulted bMilliseconds argument, because
 * DMC++ gives "ambiguous reference to symbol" errors. (And I didn't have
 * time to investigate further.)
 */

// UDATE

#ifdef WINSTL_UDATE_DEFINED

inline
ws_size_t
c_str_len_a(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_len_a(t.st, bMilliseconds);
}
inline
ws_size_t
c_str_len_a(
    UDATE const& t
)
{
    return c_str_len_a(t.st, ws_false_v);
}

inline
ws_size_t
c_str_len_w(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_len_w(t.st, bMilliseconds);
}
inline
ws_size_t
c_str_len_w(
    UDATE const& t
)
{
    return c_str_len_w(t.st, ws_false_v);
}

inline
ws_size_t
c_str_len(
    UDATE const&    t
,   ws_bool_t       bMilliseconds
)
{
    return c_str_len(t.st, bMilliseconds);
}
inline
ws_size_t
c_str_len(
    UDATE const& t
)
{
    return c_str_len(t.st, ws_false_v);
}

#endif /* WINSTL_UDATE_DEFINED */


/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */

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

#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE */

/* ///////////////////////////// end of file //////////////////////////// */
