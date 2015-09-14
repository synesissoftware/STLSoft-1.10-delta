/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/access/string/time/SYSTEMTIME.hpp
 *
 * Purpose:     String access shims for the Windows SYSTEMTIME structure.
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


/** \file winstl/shims/access/string/time/SYSTEMTIME.hpp
 *
 * \brief [C++] Definition of the string access shims for the Windows
 *   <code>SYSTEMTIME</code> structure
 *   (\ref group__concept__shim__string_access "String Access Shims" Concept).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME
#define WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME_MAJOR    3
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME_MINOR    1
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME_REVISION 5
# define WINSTL_VER_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME_EDIT     63
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR
# include <winstl/error/conversion_error.hpp>
#endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR */
#ifndef WINSTL_INCL_WINSTL_TIME_HPP_FORMAT_FUNCTIONS
# include <winstl/time/format_functions.hpp>
#endif /* !WINSTL_INCL_WINSTL_TIME_HPP_FORMAT_FUNCTIONS */
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

# if defined(STLSOFT_COMPILER_IS_MSVC)
   /* The following calc_sizes() methods experience alternately C4702 and
    * C4715 in debug and release configurations, so pragmatism dictates
    * warning suppression
    */
#  pragma warning(push)
#  pragma warning(disable : 4702)
# endif /* compiler */

struct ximpl_winstl_shims_access_string_time_SYSTEMTIME
{
    typedef int (STLSOFT_STDCALL *pfnGetDateTimeFmtA_t)(LCID                Locale      // locale
                                                    ,   DWORD               dwFlags     // options
                                                    ,   CONST SYSTEMTIME    *lpTime     // time
                                                    ,   ws_char_a_t const   *lpFormat   // time format string
                                                    ,   ws_char_a_t         *lpTimeStr  // formatted string buffer
                                                    ,   int                 cchTime);   // size of string buffer

    typedef int (STLSOFT_STDCALL *pfnGetDateTimeFmtW_t)(LCID                Locale      // locale
                                                    ,   DWORD               dwFlags     // options
                                                    ,   CONST SYSTEMTIME    *lpTime     // time
                                                    ,   ws_char_w_t const   *lpFormat   // time format string
                                                    ,   ws_char_w_t         *lpTimeStr  // formatted string buffer
                                                    ,   int                 cchTime);   // size of string buffer

    //
    static
    ws_size_t
    calc_sizes(
        SYSTEMTIME const&       t
    ,   pfnGetDateTimeFmtA_t    pfnGetDateFmtA
    ,   pfnGetDateTimeFmtA_t    pfnGetTimeFmtA
    ,   ws_size_t&              cchDate
    ,   ws_size_t&              cchTime
    )
    {
        cchDate = static_cast<ws_size_t>(pfnGetDateFmtA(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0));

        if(0 != cchDate)
        {
            cchTime = static_cast<ws_size_t>(pfnGetTimeFmtA(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0));

            if(0 != cchTime)
            {
                return (cchDate - 1) + 1 + (cchTime - 1);
            }
        }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        DWORD const e = ::GetLastError();

        // TODO: discriminate on e and on the values of t to determine
        // which condition (of invalid value, out-of-range, etc.)

        STLSOFT_THROW_X(conversion_error("failed to convert date/time", e));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return 0;
    }

    //
    static
    ws_size_t
    calc_sizes(
        SYSTEMTIME const&       t
    ,   pfnGetDateTimeFmtW_t    pfnGetDateFmtW
    ,   pfnGetDateTimeFmtW_t    pfnGetTimeFmtW
    ,   ws_size_t&              cchDate
    ,   ws_size_t&              cchTime
    )
    {
        cchDate = static_cast<ws_size_t>(pfnGetDateFmtW(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0));

        if(0 != cchDate)
        {
            cchTime = static_cast<ws_size_t>(pfnGetTimeFmtW(LOCALE_USER_DEFAULT, 0, &t, NULL, NULL, 0));

            if(0 != cchTime)
            {
                return (cchDate - 1) + 1 + (cchTime - 1);
            }
        }

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        DWORD const e = ::GetLastError();

        // TODO: discriminate on e and on the values of t to determine
        // which condition (of invalid value, out-of-range, etc.)

        STLSOFT_THROW_X(conversion_error("failed to convert date/time", e));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return 0;
    }
};

# if defined(STLSOFT_COMPILER_IS_MSVC)
#  pragma warning(pop)
# endif /* compiler */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr
 */

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_a(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    typedef stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>     string_t;
    typedef ximpl_winstl_shims_access_string_time_SYSTEMTIME    impl_t;

    int (STLSOFT_STDCALL *pfnGetTimeFormatA)(   LCID                Locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_a_t const   *lpFormat   // time format string
                                            ,   ws_char_a_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer

                                            =   bMilliseconds ? GetTimeFormat_msA : ::GetTimeFormatA;

    ws_size_t       cchDate     =   0;
    ws_size_t       cchTime     =   0;
    const ws_size_t cchTotal    =   impl_t::calc_sizes(t, ::GetDateFormatA, pfnGetTimeFormatA, cchDate, cchTime);
    string_t        s(cchTotal);

    if( 0 != cchTotal &&
        cchTotal == s.size())
    {
        ::GetDateFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], static_cast<int>(cchDate));
        s.data()[cchDate - 1] = ' ';
        pfnGetTimeFormatA(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, static_cast<int>(cchTime));

        // Because it's possible for external action to change the date
        // and/or time pictures between the call to calc_sizes and the
        // two preceeding calls, we guard against an unterminated
        // C-style string by forcibly appending the nul-terminator that
        // GetTimeFormat() will do for us normally.
        s.data()[cchTotal] = '\0';
    }

    return s;
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_a(
    SYSTEMTIME const& t
)
{
    return c_str_ptr_a(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_a(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return "(null)";
	}

    return c_str_ptr_a(*t, ws_true_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_w(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    typedef stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>     string_t;
    typedef ximpl_winstl_shims_access_string_time_SYSTEMTIME    impl_t;

    int (STLSOFT_STDCALL *pfnGetTimeFormatW)(   LCID                Locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_w_t const   *lpFormat   // time format string
                                            ,   ws_char_w_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer

                                            =   bMilliseconds ? GetTimeFormat_msW : ::GetTimeFormatW;

    ws_size_t       cchDate     =   0;
    ws_size_t       cchTime     =   0;
    const ws_size_t cchTotal    =   impl_t::calc_sizes(t, ::GetDateFormatW, pfnGetTimeFormatW, cchDate, cchTime);
    string_t        s(cchTotal);

    if( 0 != cchTotal &&
        cchTotal == s.size())
    {
        ::GetDateFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0], static_cast<int>(cchDate));
        s.data()[cchDate - 1] = ' ';
        pfnGetTimeFormatW(LOCALE_USER_DEFAULT, 0, &t, NULL, &s.data()[0] + cchDate, static_cast<int>(cchTime));

        // Because it's possible for external action to change the date
        // and/or time pictures between the call to calc_sizes and the
        // two preceeding calls, we guard against an unterminated
        // C-style string by forcibly appending the nul-terminator that
        // GetTimeFormat() will do for us normally.
        s.data()[cchTotal] = '\0';
    }

    return s;
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_w(
    SYSTEMTIME const& t
)
{
    return c_str_ptr_w(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_w(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return L"(null)";
	}

    return c_str_ptr_w(*t, ws_true_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
#ifdef UNICODE
    return c_str_ptr_w(t, bMilliseconds);
#else /* ? UNICODE */
    return c_str_ptr_a(t, bMilliseconds);
#endif /* UNICODE */
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr(
    SYSTEMTIME const& t
)
{
    return c_str_ptr(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr(
    SYSTEMTIME const* t
)
{
#ifdef UNICODE
	return c_str_ptr_w(t);
#else /* ? UNICODE */
	return c_str_ptr_a(t);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_data
 */

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_data_a(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    return c_str_ptr_a(t, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_data_a(
    SYSTEMTIME const& t
)
{
    return c_str_data_a(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_data_a(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return "(null)";
	}

    return c_str_data_a(*t, ws_true_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_data_w(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    return c_str_ptr_w(t, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_data_w(
    SYSTEMTIME const& t
)
{
    return c_str_data_w(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_data_w(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return L"(null)";
	}

    return c_str_data_w(*t, ws_true_v);
}

inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_data(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
#ifdef UNICODE
    return c_str_data_w(t, bMilliseconds);
#else /* ? UNICODE */
    return c_str_data_a(t, bMilliseconds);
#endif /* UNICODE */
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_data(
    SYSTEMTIME const& t
)
{
    return c_str_data(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_data(
    SYSTEMTIME const* t
)
{
#ifdef UNICODE
    return c_str_data_w(t);
#else /* ? UNICODE */
    return c_str_data_a(t);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_ptr_null
 */

inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_null_a(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    return c_str_ptr_a(t, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_null_a(
    SYSTEMTIME const& t
)
{
    return c_str_ptr_null_a(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_a_t>
c_str_ptr_null_a(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return "(null)";
	}

    return c_str_ptr_null_a(*t, ws_true_v);
}


inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_null_w(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    return c_str_ptr_w(t, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_null_w(
    SYSTEMTIME const& t
)
{
    return c_str_ptr_null_w(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<ws_char_w_t>
c_str_ptr_null_w(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return L"(null)";
	}

    return c_str_ptr_null_w(*t, ws_true_v);
}


inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr_null(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    return c_str_ptr(t, bMilliseconds);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr_null(
    SYSTEMTIME const& t
)
{
    return c_str_ptr_null(t, ws_false_v);
}
inline
stlsoft_ns_qual(basic_shim_string)<TCHAR>
c_str_ptr_null(
    SYSTEMTIME const* t
)
{
#ifdef UNICODE
    return c_str_ptr_null_w(t);
#else /* ? UNICODE */
    return c_str_ptr_null_a(t);
#endif /* UNICODE */
}

/* /////////////////////////////////////////////////////////////////////////
 * c_str_len
 *
 * NOTE: The following are provided as function overloads, rather than, as
 * originally implemented, with defaulted bMilliseconds argument, because
 * DMC++ gives "ambiguous reference to symbol" errors. (And I didn't have
 * time to investigate further.)
 */

inline
ws_size_t
c_str_len_a(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    typedef ximpl_winstl_shims_access_string_time_SYSTEMTIME impl_t;

    int (STLSOFT_STDCALL *pfnGetTimeFormatA)(   LCID                Locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_a_t const   *lpFormat   // time format string
                                            ,   ws_char_a_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer

                                            =   bMilliseconds ? GetTimeFormat_msA : ::GetTimeFormatA;

    ws_size_t cchDate = 0;
    ws_size_t cchTime = 0;

    return impl_t::calc_sizes(t, ::GetDateFormatA, pfnGetTimeFormatA, cchDate, cchTime);
}
inline
ws_size_t
c_str_len_a(
    SYSTEMTIME const& t
)
{
    return c_str_len_a(t, ws_false_v);
}
inline
ws_size_t
c_str_len_a(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return 6u;
	}

    return c_str_len_a(*t, ws_true_v);
}

inline
ws_size_t
c_str_len_w(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
    typedef ximpl_winstl_shims_access_string_time_SYSTEMTIME impl_t;

    int (STLSOFT_STDCALL *pfnGetTimeFormatW)(   LCID                Locale      // locale
                                            ,   DWORD               dwFlags     // options
                                            ,   CONST SYSTEMTIME    *lpTime     // time
                                            ,   ws_char_w_t const   *lpFormat   // time format string
                                            ,   ws_char_w_t         *lpTimeStr  // formatted string buffer
                                            ,   int                 cchTime)    // size of string buffer

                                            =   bMilliseconds ? GetTimeFormat_msW : ::GetTimeFormatW;

    ws_size_t cchDate = 0;
    ws_size_t cchTime = 0;

    return impl_t::calc_sizes(t, ::GetDateFormatW, pfnGetTimeFormatW, cchDate, cchTime);
}
inline
ws_size_t
c_str_len_w(
    SYSTEMTIME const& t
)
{
    return c_str_len_w(t, ws_false_v);
}
inline
ws_size_t
c_str_len_w(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return 6u;
	}

    return c_str_len_w(*t, ws_true_v);
}

inline
ws_size_t
c_str_len(
    SYSTEMTIME const&   t
,   ws_bool_t           bMilliseconds
)
{
#ifdef UNICODE
    return c_str_len_w(t, bMilliseconds);
#else /* ? UNICODE */
    return c_str_len_a(t, bMilliseconds);
#endif /* UNICODE */
}
inline
ws_size_t
c_str_len(
    SYSTEMTIME const& t
)
{
    return c_str_len(t, ws_false_v);
}
inline
ws_size_t
c_str_len(
    SYSTEMTIME const* t
)
{
	if(NULL == t)
	{
		return 6u;
	}

    return c_str_len(*t, ws_true_v);
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

#endif /* !WINSTL_INCL_WINSTL_SHIMS_ACCESS_STRING_TIME_HPP_SYSTEMTIME */

/* ///////////////////////////// end of file //////////////////////////// */
