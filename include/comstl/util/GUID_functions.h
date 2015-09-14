/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/util/GUID_functions.h
 *
 * Purpose:     GUID helper functions.
 *
 * Created:     12th May 2010
 * Updated:     3rd May 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2010-2014, Matthew Wilson and Synesis Software
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


/** \file comstl/util/GUID_functions.h
 *
 * \brief [C++ only; requires COM] GUID helper functions
 *   (\ref group__library__utility__com "COM Utility" Library).
 */

#ifndef COMSTL_INCL_COMSTL_UTIL_H_GUID_FUNCTIONS
#define COMSTL_INCL_COMSTL_UTIL_H_GUID_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_UTIL_H_GUID_FUNCTIONS_MAJOR      1
# define COMSTL_VER_COMSTL_UTIL_H_GUID_FUNCTIONS_MINOR      3
# define COMSTL_VER_COMSTL_UTIL_H_GUID_FUNCTIONS_REVISION   2
# define COMSTL_VER_COMSTL_UTIL_H_GUID_FUNCTIONS_EDIT       10
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

#ifdef __cplusplus
# ifndef COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS
#  include <comstl/error/exceptions.hpp>
# endif /* !COMSTL_INCL_COMSTL_ERROR_HPP_EXCEPTIONS */
# ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
#  include <stlsoft/shims/access/string.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#endif /* __cplusplus */

#ifndef STLSOFT_INCL_H_WCHAR
# define STLSOFT_INCL_H_WCHAR
# include <wchar.h>              /* for wcscmp() */
#endif /* !STLSOFT_INCL_H_WCHAR */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(COMSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# ifdef __cplusplus
namespace programmer_error
{
    struct cannot_pass_GUID_type_to_GUID_from_string
    {};

} /* namespace programmer_error */
# endif /* __cplusplus */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_INLINE HRESULT comstl_C_GUID_to_string_w(
    REFGUID     guid
,   cs_char_w_t (*buff)[1 + COMSTL_CCH_GUID]
);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/** \brief [C only] Compares two GUID instances
 *
 * \ingroup group__library__utility__com
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param lhs Pointer to the right-hand instances to compare
 * \param comparisonSucceeded Pointer to a result-code instance that will
 *   have an HRESULT value not equal to S_OK if the comparison cannot be
 *   made. May be NULL if the caller does not care.
 *
 * \return a value indicating the relative ordering of the two GUIDs
 * \retval <0 \c lhs is less than \c rhs
 * \retval 0 \c lhs is equal to \c rhs
 * \retval >0 \c lhs is greater than \c rhs
 *
 * \note This comparison is done in a byte-order independent manner, so
 *   will provide the same ordering regardless of the byte-order of the
 *   host machine on which it executes. For byte-comparison, use
 *   comstl_C_GUID_binary_compare().
 */
STLSOFT_INLINE int comstl_C_GUID_compare(
    GUID const* lhs
,   GUID const* rhs
,   HRESULT*    comparisonSucceeded
)
{
    HRESULT comparisonSucceeded_;

    /* Use the Null Object (Variable) pattern to relieve rest of code
     * of burden of knowing whether value required by caller
     */
    if(NULL == comparisonSucceeded)
    {
        comparisonSucceeded = &comparisonSucceeded_;
    }

    *comparisonSucceeded = S_OK;

    if(NULL == lhs)
    {
        return (NULL == rhs) ? 0 : -1;
    }
    else
    {
        if(NULL == rhs)
        {
            return +1;
        }
        else
        {
            OLECHAR s1[1 + COMSTL_CCH_GUID];

            if(FAILED(*comparisonSucceeded = comstl_C_GUID_to_string_w(COMSTL_PTR_2_REF(lhs), &s1)))
            {
                return -1;
            }
            else
            {
                OLECHAR s2[1 + COMSTL_CCH_GUID];

                if(FAILED(*comparisonSucceeded = comstl_C_GUID_to_string_w(COMSTL_PTR_2_REF(rhs), &s2)))
                {
                    return -1;
                }
                else
                {
                    return STLSOFT_NS_GLOBAL(wcscmp)(s1, s2);
                }
            }
        }
    }
}

/** \brief [C only] Compares two GUID instances
 *
 * \ingroup group__library__utility__com
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param lhs Pointer to the right-hand instances to compare
 *
 * \return a value indicating the relative binary ordering of the two GUIDs
 * \retval <0 \c lhs is less than \c rhs
 * \retval 0 \c lhs is equal to \c rhs
 * \retval >0 \c lhs is greater than \c rhs
 *
 * \note This comparison is done by treating the GUID instances as
 *   opaque binary blocks, so may provide different ordering when
 *   executed on different hosts. For host independent comparison, use
 *   comstl_C_GUID_binary()
 */
STLSOFT_INLINE int comstl_C_GUID_binary_compare(
    GUID const* lhs
,   GUID const* rhs
)
{
    if(NULL == lhs)
    {
        return (NULL == rhs) ? 0 : -1;
    }
    else
    {
        if(NULL == rhs)
        {
            return +1;
        }
        else
        {
            return STLSOFT_NS_GLOBAL(memcmp)(lhs, rhs, sizeof(GUID));
        }
    }
}

/** \brief [C only] Indicates whether two GUID structures are equal
 *
 * \ingroup group__library__utility__com
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param lhs Pointer to the right-hand instances to compare
 *
 * \return a value indicating whether the values are equal
 * \retval 0 The structures are not equal
 * \retval !0 The structures are equal
 */
STLSOFT_INLINE int comstl_C_GUID_equal(
    GUID const* lhs
,   GUID const* rhs
)
{
    STLSOFT_CONTRACT_ENFORCE_ASSUMPTION((0 == comstl_C_GUID_binary_compare(lhs, rhs)) == (0 == comstl_C_GUID_compare(lhs, rhs, NULL)));

    return 0 == comstl_C_GUID_binary_compare(lhs, rhs);
}


STLSOFT_INLINE HRESULT comstl_C_GUID_from_string_w(
    cs_char_w_t const*  str
,   GUID*               pguid
)
{
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != str, "string parameter may not be null");
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != pguid, "return value out parameter may not be null");

    return STLSOFT_NS_GLOBAL(CLSIDFromString(stlsoft_const_cast(LPOLESTR, str), pguid));
}

STLSOFT_INLINE HRESULT comstl_C_GUID_from_string_a(
    cs_char_a_t const*  str
,   GUID*               pguid
)
{
    OLECHAR     ws[1 + COMSTL_CCH_GUID];
    HRESULT     hr  =   S_OK;

    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != str, "string parameter may not be null");
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != pguid, "return value out parameter may not be null");

    switch(STLSOFT_NS_GLOBAL(MultiByteToWideChar)(0, 0, str, -1, &ws[0], 1 + COMSTL_CCH_GUID))
    {
        case    1 + COMSTL_CCH_GUID:
            ws[COMSTL_CCH_GUID] = L'\0';
            hr = comstl_C_GUID_from_string_w(ws, pguid);
            break;
        default:
            if(S_OK == (hr = HRESULT_FROM_WIN32(STLSOFT_NS_GLOBAL(GetLastError)())))
            {
                hr = E_INVALIDARG;
            }
            break;
    }

    return hr;
}

STLSOFT_INLINE HRESULT comstl_C_GUID_to_string_w(
    REFGUID     guid
,   cs_char_w_t (*buff)[1 + COMSTL_CCH_GUID]
)
{
    int r;

#ifndef __cplusplus
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != guid, "GUID parameter may not be null");
#endif /* !__cplusplus */
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != buff, "array parameter may not be null");

    r = STLSOFT_NS_GLOBAL(StringFromGUID2)(guid, *buff, 1 + COMSTL_CCH_GUID);

    if(0 == r)
    {
        return E_INVALIDARG;
    }
    else
    {
        STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_EXTERNAL(L'\0' == (*buff)[COMSTL_CCH_GUID], "buffer must be nul-terminated");

        return S_OK;
    }
}

STLSOFT_INLINE HRESULT comstl_C_GUID_to_string_a(
    REFGUID     guid
,   cs_char_a_t (*buff)[1 + COMSTL_CCH_GUID]
)
{
    OLECHAR     wbuff[1 + COMSTL_CCH_GUID];
    HRESULT     hr;

#ifndef __cplusplus
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != guid, "GUID parameter may not be null");
#endif /* !__cplusplus */
    STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != buff, "array parameter may not be null");

    hr = comstl_C_GUID_to_string_w(guid, &wbuff);

    if(FAILED(hr))
    {
        (*buff)[0] = '\0';
    }
    else
    {
        switch(STLSOFT_NS_GLOBAL(WideCharToMultiByte)(0, 0, wbuff, 1 + COMSTL_CCH_GUID, *buff, 1 + COMSTL_CCH_GUID, NULL, NULL))
        {
            case    1 + COMSTL_CCH_GUID:
                STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_EXTERNAL(L'\0' == (*buff)[COMSTL_CCH_GUID], "buffer must be nul-terminated");
                break;
            default:
                if(S_OK == (hr = HRESULT_FROM_WIN32(STLSOFT_NS_GLOBAL(GetLastError)())))
                {
                    hr = E_INVALIDARG;
                }
                break;
        }
    }

    return hr;
}


#ifdef __cplusplus

inline HRESULT comstl_C_GUID_from_string(
    cs_char_w_t const*  str
,   GUID*               pguid
)
{
    return comstl_C_GUID_from_string_w(str, pguid);
}

inline HRESULT comstl_C_GUID_from_string(
    cs_char_a_t const*  str
,   GUID*               pguid
)
{
    return comstl_C_GUID_from_string_a(str, pguid);
}

inline HRESULT comstl_C_GUID_to_string(
    REFGUID     guid
,   cs_char_w_t (*buff)[1 + COMSTL_CCH_GUID]
)
{
    return comstl_C_GUID_to_string_w(guid, buff);
}

inline HRESULT comstl_C_GUID_to_string(
    REFGUID     guid
,   cs_char_a_t (*buff)[1 + COMSTL_CCH_GUID]
)
{
    return comstl_C_GUID_to_string_a(guid, buff);
}

#else /* ? __cplusplus */

# ifdef UNICODE
#  define comstl_C_GUID_from_string     comstl_C_GUID_from_string_w
#  define comstl_C_GUID_to_string       comstl_C_GUID_to_string_w
# else /* ? UNICODE */
#  define comstl_C_GUID_from_string     comstl_C_GUID_from_string_a
#  define comstl_C_GUID_to_string       comstl_C_GUID_to_string_a
# endif /* UNICODE */

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace comstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** \brief [C++ only] Compares two GUID instances in an architecture-independent manner
 *
 * \ingroup group__library__utility__com
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param lhs Pointer to the right-hand instances to compare
 * \param comparisonSucceeded Pointer to a result-code instance that will
 *   have an HRESULT value not equal to S_OK if the comparison cannot be
 *   made. May be NULL if the caller does not care, in which case failures
 *   will result in an instance of comstl::com_exception being thrown.
 *
 * \return a value indicating the relative ordering of the two GUIDs
 * \retval <0 \c lhs is less than \c rhs
 * \retval 0 \c lhs is equal to \c rhs
 * \retval >0 \c lhs is greater than \c rhs
 *
 * \exception comstl::com_exception Thrown if <code>comparisonSucceeded</code>
 *   is <code>NULL</code> and the comparison fails.
 */
inline int GUID_compare(GUID const* lhs, GUID const* rhs, HRESULT* comparisonSucceeded = NULL)
{
    HRESULT succeeded;
    int result = comstl_C_GUID_compare(lhs, rhs, &succeeded);

    if(S_OK != succeeded)
    {
        if(NULL == comparisonSucceeded)
        {
            STLSOFT_THROW_X(com_exception("comparison failed", succeeded));
        }
        else
        {
            *comparisonSucceeded = succeeded;
        }
    }

    return result;
}

/** \brief [C++ only] Compares two GUID instances in an architecture-dependent manner
 *
 * \ingroup group__library__utility__com
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param lhs Pointer to the right-hand instances to compare
 *
 * \return a value indicating the relative ordering of the two GUIDs
 * \retval <0 \c lhs is less than \c rhs
 * \retval 0 \c lhs is equal to \c rhs
 * \retval >0 \c lhs is greater than \c rhs
 */
inline int GUID_binary_compare(GUID const* lhs, GUID const* rhs)
{
    return comstl_C_GUID_binary_compare(lhs, rhs);
}

/** \brief [C++ only] Indicates whether two GUID structures are equal
 *
 * \ingroup group__library__utility__com
 *
 * \param lhs Reference to the left-hand instances to compare
 * \param lhs Reference to the right-hand instances to compare
 * \param comparisonSucceeded Pointer to a result-code instance that will have
 *   an HRESULT value not equal to S_OK if the comparison cannot be made. May
 *   be NULL if the caller does not care
 *
 * \return a value indicating the relative ordering of the two GUIDs
 * \retval <0 \c lhs is less than \c rhs
 * \retval 0 \c lhs is equal to \c rhs
 * \retval >0 \c lhs is greater than \c rhs
 */
inline int GUID_compare(GUID const& lhs, GUID const& rhs, HRESULT* comparisonSucceeded = NULL)
{
    return GUID_compare(&lhs, &rhs, comparisonSucceeded);
}

/** \brief [C++ only] Indicates whether two GUID structures are equal
 *
 * \ingroup group__library__utility__com
 *
 * \param lhs Pointer to the left-hand instances to compare
 * \param lhs Pointer to the right-hand instances to compare
 *
 * \return a value indicating whether the values are equal
 * \retval 0 The structures are not equal
 * \retval !0 The structures are equal
 */
inline bool GUID_equal(GUID const* lhs, GUID const* rhs)
{
    return 0 != comstl_C_GUID_equal(lhs, rhs);
}

/** \brief [C++ only] Indicates whether two GUID structures are equal
 *
 * \ingroup group__library__utility__com
 *
 * \param lhs Reference to the left-hand instances to compare
 * \param lhs Reference to the right-hand instances to compare
 *
 * \return a value indicating whether the values are equal
 * \retval 0 The structures are not equal
 * \retval !0 The structures are equal
 */
inline bool GUID_equal(GUID const& lhs, GUID const& rhs)
{
    return 0 != comstl_C_GUID_equal(&lhs, &rhs);
}

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
     _MSC_VER >= 1310
programmer_error::cannot_pass_GUID_type_to_GUID_from_string
    GUID_from_string(GUID const&, GUID*);
# endif /* _MSC_VER */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

template <ss_typename_param_k S>
inline HRESULT GUID_from_string(S const& str, GUID* pguid)
{
    return comstl_C_GUID_from_string(stlsoft_ns_qual(c_str_ptr)(str), pguid);
}

inline HRESULT GUID_to_string(
    REFGUID     guid
,   cs_char_w_t (*buff)[1 + COMSTL_CCH_GUID]
)
{
    return comstl_C_GUID_to_string_w(guid, buff);
}

inline HRESULT GUID_to_string(
    REFGUID     guid
,   cs_char_a_t (*buff)[1 + COMSTL_CCH_GUID]
)
{
    return comstl_C_GUID_to_string_a(guid, buff);
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_UTIL_H_GUID_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
