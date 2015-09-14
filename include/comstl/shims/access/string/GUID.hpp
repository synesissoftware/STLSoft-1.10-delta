/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/shims/access/string/GUID.hpp
 *
 * Purpose:     Definition of the string access shims for the GUID type.
 *
 * Created:     24th May 2002
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2012, Matthew Wilson and Synesis Software
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


/** \file comstl/shims/access/string/GUID.hpp
 *
 * \brief [C++] Definition of the string access shims for the
 *   <code>GUID</code> type
 *   (\ref group__concept__shim__string_access "String Access Shims" Concept).
 */

#ifndef COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID
#define COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID_MAJOR       5
# define COMSTL_VER_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID_MINOR       3
# define COMSTL_VER_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID_REVISION    2
# define COMSTL_VER_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID_EDIT        123
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <comstl/comstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifndef COMSTL_INCL_COMSTL_UTIL_H_GUID_FUNCTIONS
# include <comstl/util/GUID_functions.h>
#endif /* !COMSTL_INCL_COMSTL_UTIL_H_GUID_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */

#ifndef STLSOFT_INCL_H_WCHAR
# define STLSOFT_INCL_H_WCHAR
# include <wchar.h>
#endif /* !STLSOFT_INCL_H_WCHAR */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */

namespace stlsoft
{

namespace comstl_project
{

# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/// A fixed-size shim string
template <ss_typename_param_k C>
struct c_str_ptr_GUID_proxy
{
    /// Character buffer used to hold conversion results
    C   data[1 + COMSTL_CCH_GUID];

public:
    c_str_ptr_GUID_proxy(GUID const& guid);

public: // Operators
    /// Implicit conversion to pointer to the character buffer
    operator C const* () const
    {
        return &data[0];
    }
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
inline /* static */ c_str_ptr_GUID_proxy<cs_char_w_t>::c_str_ptr_GUID_proxy(GUID const& guid)
{
    comstl_C_GUID_to_string_w(guid, &data);
}

STLSOFT_TEMPLATE_SPECIALISATION
inline /* static */ c_str_ptr_GUID_proxy<cs_char_a_t>::c_str_ptr_GUID_proxy(GUID const& guid)
{
    comstl_C_GUID_to_string_a(guid, &data);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline c_str_ptr_GUID_proxy<cs_char_a_t> c_str_data_a(GUID const& guid)
{
    return c_str_ptr_GUID_proxy<cs_char_a_t>(guid);
}

inline c_str_ptr_GUID_proxy<cs_char_w_t> c_str_data_w(GUID const& guid)
{
    return c_str_ptr_GUID_proxy<cs_char_w_t>(guid);
}

inline c_str_ptr_GUID_proxy<cs_char_w_t> c_str_data_o(GUID const& guid)
{
    return c_str_data_w(guid);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief Returns the corresponding possibly unterminated C-string pointer of the GUID \c guid
 *
 * \ingroup group__concept__shim__string_access
 *
 */
inline c_str_ptr_GUID_proxy<TCHAR> c_str_data(GUID const& guid)
{
#ifdef UNICODE
    return c_str_data_w(guid);
#else /* ? UNICODE */
    return c_str_data_a(guid);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * This can be applied to an expression, and the return value is the number of
 * characters in the character string in the expression.
 */

/* GUID */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline cs_size_t c_str_len_a(GUID const& /* guid */)
{
    return COMSTL_CCH_GUID;
}

inline cs_size_t c_str_len_w(GUID const& /* guid */)
{
    return COMSTL_CCH_GUID;
}

inline cs_size_t c_str_len_o(GUID const& /* guid */)
{
    return COMSTL_CCH_GUID;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief Returns the length (in characters) of the GUID \c guid, <b><i>not</i></b> including the null-terminating character
 *
 * \ingroup group__concept__shim__string_access
 *
 */
inline cs_size_t c_str_len(GUID const& /* guid */)
{
    return COMSTL_CCH_GUID;
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or to an empty string.
 */

/* GUID */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline c_str_ptr_GUID_proxy<cs_char_a_t> c_str_ptr_a(GUID const& guid)
{
    return c_str_data_a(guid);
}

inline c_str_ptr_GUID_proxy<cs_char_w_t> c_str_ptr_w(GUID const& guid)
{
    return c_str_data_w(guid);
}

inline c_str_ptr_GUID_proxy<cs_char_o_t> c_str_ptr_o(GUID const& guid)
{
    return c_str_data_o(guid);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief Returns the corresponding C-string pointer of the GUID \c guid
 *
 * \ingroup group__concept__shim__string_access
 *
 */
inline c_str_ptr_GUID_proxy<TCHAR> c_str_ptr(GUID const& guid)
{
#ifdef UNICODE
    return c_str_ptr_w(guid);
#else /* ? UNICODE */
    return c_str_ptr_a(guid);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 *
 * This can be applied to an expression, and the return value is either a
 * pointer to the character string or NULL.
 */

/* GUID */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline c_str_ptr_GUID_proxy<cs_char_a_t> c_str_ptr_null_a(GUID const& guid)
{
    return c_str_data_a(guid);
}

inline c_str_ptr_GUID_proxy<cs_char_w_t> c_str_ptr_null_w(GUID const& guid)
{
    return c_str_data_w(guid);
}

inline c_str_ptr_GUID_proxy<cs_char_o_t> c_str_ptr_null_o(GUID const& guid)
{
    return c_str_data_o(guid);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \brief Returns the corresponding C-string pointer of the GUID \c guid
 *
 * \ingroup group__concept__shim__string_access
 *
 */
inline c_str_ptr_GUID_proxy<TCHAR> c_str_ptr_null(GUID const& guid)
{
#ifdef UNICODE
    return c_str_ptr_null_w(guid);
#else /* ? UNICODE */
    return c_str_ptr_null_a(guid);
#endif /* UNICODE */
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace comstl
# else
} // namespace stlsoft::comstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef COMSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::comstl::c_str_data_a;
using ::comstl::c_str_data_w;
using ::comstl::c_str_data_o;
using ::comstl::c_str_data;

using ::comstl::c_str_len_a;
using ::comstl::c_str_len_w;
using ::comstl::c_str_len_o;
using ::comstl::c_str_len;

using ::comstl::c_str_ptr_a;
using ::comstl::c_str_ptr_w;
using ::comstl::c_str_ptr_o;
using ::comstl::c_str_ptr;

using ::comstl::c_str_ptr_null_a;
using ::comstl::c_str_ptr_null_w;
using ::comstl::c_str_ptr_null_o;
using ::comstl::c_str_ptr_null;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace stlsoft
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_SHIMS_ACCESS_STRING_HPP_GUID */

/* ///////////////////////////// end of file //////////////////////////// */
