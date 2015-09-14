/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/access/string/time.hpp
 *
 * Purpose:     Helper functions for the Windows time types.
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


/** \file winstl/shims/access/string/time.hpp
 *
 * \brief [C++] Definition of the string access shims for the Windows time
 *   types
 *   (\ref group__concept__shim__string_access "String Access Shims" Concept).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME
#define WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME_MAJOR       3
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME_MINOR       0
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME_REVISION    1
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME_EDIT        58
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME
# include <winstl/shims/access/string/time/FILETIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_FILETIME */
#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME
# include <winstl/shims/access/string/time/SYSTEMTIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME */
#ifdef WINSTL_UDATE_DEFINED
# ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE
#  include <winstl/shims/access/string/time/UDATE.hpp>
# endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_UDATE */
#endif /* WINSTL_UDATE_DEFINED */


#ifndef WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR
# include <winstl/error/conversion_error.hpp>
#endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR */
#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_SYSTEMTIME_HPP_FILETIME
# include <winstl/shims/conversion/to_SYSTEMTIME/FILETIME.hpp>
#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_SYSTEMTIME_HPP_FILETIME */
#ifndef WINSTL_INCL_WINSTL_TIME_HPP_FORMAT_FUNCTIONS
# include <winstl/time/format_functions.hpp>
#endif /* !WINSTL_INCL_WINSTL_TIME_HPP_FORMAT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */

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
struct ximpl_winstl_shims_access_string_time
{
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Helper Functions
 */

/** \brief [DEPRECATED] Converts a <code>FILETIME</code> value to a
 *   <code>SYSTEMTIME</code> value.
 *
 * \deprecated Instead use winstl::to_SYSTEMTIME(FILETIME const&)
 *
 * \ingroup group__library__shims__string_access
 *
 * \param ft The <code>FILETIME</code> instance whose value is to be converted
 *
 * \note If <code>ft</code> does not represent a valid time value, the
 *  return value is undefined. The caller may check
 *  <code>GetLastError()</code> to determine whether the conversion has been
 *  successful.
 */
inline
SYSTEMTIME
FILETIME2SYSTEMTIME(
    FILETIME const& ft
)
{
    return winstl_ns_qual(to_SYSTEMTIME)(ft);
}

template <ss_typename_param_k S>
inline
void
stream_insert(S &stm, SYSTEMTIME const& t)
{
    typedef stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>     string_t;
    typedef ximpl_winstl_shims_access_string_time               impl_t;

    ws_size_t       cchDate     =   0;
    ws_size_t       cchTime     =   0;
    const ws_size_t cchTotal    =   impl_t::calc_sizes(t, ::GetDateFormatA, ::GetTimeFormatA, cchDate, cchTime);

#ifdef STLSOFT_CD_EXCEPTION_SUPPORT
    WINSTL_ASSERT(0 != cchTotal);
#else /* ? STLSOFT_CD_EXCEPTION_SUPPORT */
    if(0 != cchTotal)
#endif /* STLSOFT_CD_EXCEPTION_SUPPORT */
    {
        string_t s(cchTotal);

        if(cchTotal == s.size())
        {
            ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], static_cast<int>(cchDate));
            s.data()[cchDate - 1] = ' ';
            ::GetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, static_cast<int>(cchTime));

            // Because it's possible for external action to change the date
            // and/or time pictures between the call to calc_sizes and the
            // two preceeding calls, we guard against an unterminated
            // C-style string by forcibly appending the nul-terminator that
            // GetTimeFormat() will do for us normally.
            s.data()[cchTotal] = '\0';
        }

        stm << s.data();
    }
}

template <ss_typename_param_k S>
inline
void
stream_insert(S &stm, FILETIME const& ft)
{
    stream_insert(stm, winstl_ns_qual(to_SYSTEMTIME)(ft));
}

#ifdef WINSTL_UDATE_DEFINED

template <ss_typename_param_k S>
inline
void
stream_insert(S &stm, UDATE const& ud)
{
    stream_insert(stm, ud.st);
}

#endif /* WINSTL_UDATE_DEFINED */

/* /////////////////////////////////////////////////////////////////////////
 * Stream inserter
 */

/** \brief An inserter function for SYSTEMTIME into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline
S&
operator <<(
    S&                  s
,   SYSTEMTIME const&   st
)
{
    stream_insert(s, st);

    return s;
}

/** \brief An inserter function for FILETIME into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline
S&
operator <<(
    S&              s
,   FILETIME const& ft
)
{
    stream_insert(s, ft);

    return s;
}

#ifdef WINSTL_UDATE_DEFINED

/** \brief An inserter function for UDATE into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline
S&
operator <<(
    S&              s
,   UDATE const&    ud
)
{
    stream_insert(s, ud);

    return s;
}

#endif /* WINSTL_UDATE_DEFINED */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */

/** \brief An inserter function for SYSTEMTIME into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline
S&
operator <<(
    S&                  s
,   SYSTEMTIME const&   st
)
{
    ::winstl::stream_insert(s, st);

    return s;
}

/** \brief An inserter function for FILETIME into output streams
 *
 * \ingroup group__library__shims__string_access
 *
 */
template <ss_typename_param_k S>
inline
S&
operator <<(
    S&              s
,   FILETIME const& st
)
{
    ::winstl::stream_insert(s, st);

    return s;
}

#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_HPP_TIME */

/* ///////////////////////////// end of file //////////////////////////// */
