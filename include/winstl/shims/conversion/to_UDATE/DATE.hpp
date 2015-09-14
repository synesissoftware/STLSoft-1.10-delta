/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/shims/conversion/to_UDATE/DATE.hpp
 *
 * Purpose:     winstl::to_UDATE(DATE const&) overload.
 *
 * Created:     29th May 2014
 * Updated:     29th May 2014
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


/** \file winstl/shims/conversion/to_UDATE/DATE.hpp
 *
 * \brief [C++] Definition of the winstl::to_UDATE(DATE const&)
 *   overload
 *   (\ref group__concept__shim__time_conversion__to_UDATE "winstl::to_UDATE" Time Conversion Shim).
 */

#ifndef WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_UDATE_HPP_DATE
#define WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_UDATE_HPP_DATE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_UDATE_HPP_DATE_MAJOR     1
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_UDATE_HPP_DATE_MINOR     0
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_UDATE_HPP_DATE_REVISION  1
# define WINSTL_VER_WINSTL_SHIMS_CONVERSION_TO_UDATE_HPP_DATE_EDIT      1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_UDATE_DEFINED
# error UDATE is not defined. If you are certain that your compiler's Windows header files define this type, #define the symbol WINSTL_FORCE_UDATE
#else /* ? WINSTL_UDATE_DEFINED */
#endif /* !WINSTL_UDATE_DEFINED */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR
#  include <winstl/error/conversion_error.hpp>
# endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_CONVERSION_ERROR */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

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
 * Functions
 */

/** \brief Converts an instance of DATE to an instance of UDATE,
 *    using the Windows API function <code>VarUdateFromDate()</code>.
 *
 * \ingroup group__concept__shim__time_conversion__to_UDATE
 *
 * \param rhs A valid date, of type <code>DATE</code>
 * \return A valid date, of type <code>UDATE</code>
 *
 * \exception winstl::conversion_error If the conversion fails, e.g. the
 *   <code>DATE</code> instance does not contain a valid date. When
 *   compiling absent exception support, a zero-initialised instance of
 *   <code>UDATE</code> is returned.
 */
inline
UDATE
to_UDATE(
    DATE const& rhs
)
{
    UDATE           ud;
    HRESULT const   hr = ::VarUdateFromDate(rhs, 0, &ud);

    if(FAILED(hr))
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        STLSOFT_THROW_X(conversion_error("failed to convert time value", DWORD(hr)));
#else /* STLSOFT_CF_EXCEPTION_SUPPORT */
        ::memset(&ud, 0, sizeof(ud));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return ud;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SHIMS_CONVERSION_TO_UDATE_HPP_DATE */

/* ///////////////////////////// end of file //////////////////////////// */
