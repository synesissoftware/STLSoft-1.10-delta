/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/integer_to_string/integer_to_string.hpp (formerly stlsoft/conversion/integer_to_string.hpp; originally stlsoft_integer_to_string.h)
 *
 * Purpose:     Very efficient integer to string conversion functions.
 *
 * Created:     7th April 2002
 * Updated:     3rd September 2012
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


/** \file stlsoft/conversion/integer_to_string.hpp
 *
 * \brief [C++ only; DEPRECATED] Very efficient integer to string conversion functions
 *   (\ref group__library__conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING
#define STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING_MAJOR       5
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING_MINOR       1
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING_REVISION    4
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING_EDIT        84
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING
# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_DECIMAL_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifdef __STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
# error __STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT is no longer supported. Instead, define STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
#endif /* __STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_sint8_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_uint8_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_sint16_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_uint16_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_sint32_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_uint32_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_sint64_t const& i)
{
#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if(i < 0x80000000)
    {
        return integer_to_decimal_string(buf, cchBuf, static_cast<ss_sint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, ss_uint64_t const& i)
{
#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if(i < 0x80000000)
    {
        return integer_to_decimal_string(buf, cchBuf, static_cast<ss_uint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return integer_to_decimal_string(buf, cchBuf, i);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, short i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned short i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, int i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned int i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}
#endif /* !STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, long i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned long i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}
#endif /* !STLSOFT_CF_LONG_DISTINCT_INT_TYPE */


#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], ss_sint8_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 5));

    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], ss_uint8_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 4));

    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], ss_sint16_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 7));

    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], ss_uint16_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 6));

    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], ss_sint32_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 12));

    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], ss_uint32_t i)
{
    STLSOFT_STATIC_ASSERT(!(N < 11));

    return integer_to_decimal_string(buf, N, i);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], ss_sint64_t const& i)
{
    STLSOFT_STATIC_ASSERT(!(N < 21));

#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if(i < 0x80000000)
    {
        return integer_to_decimal_string(buf, N, static_cast<ss_sint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], ss_uint64_t const& i)
{
    STLSOFT_STATIC_ASSERT(!(N < 21));

#ifdef STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT
    if(i < 0x80000000)
    {
        return integer_to_decimal_string(buf, N, static_cast<ss_uint32_t>(i));
    }
#endif // STLSOFT_INTEGER_TO_STRING_OPTIMISE_64BIT

    return integer_to_decimal_string(buf, N, i);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], short i)
{
    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], unsigned short i)
{
    return integer_to_decimal_string(buf, N, i);
}
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], int i)
{
    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], unsigned int i)
{
    return integer_to_decimal_string(buf, N, i);
}
#endif /* !STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], long i)
{
    return integer_to_decimal_string(buf, N, i);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template< ss_typename_param_k C
        , ss_size_t           N
        >
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C (&buf)[N], unsigned long i)
{
    return integer_to_decimal_string(buf, N, i);
}
#endif /* !STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

#if 0
template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_int_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint_t i)
{
    return integer_to_decimal_string(buf, cchBuf, i);
}

template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_bool_t i);

template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_char_a_t i);

template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_char_w_t i);
#endif /* 0 */



/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint8_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint8_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint8_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint8_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint16_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint16_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint16_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint16_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint32_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint32_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint32_t i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint32_t i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint64_t const& i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_sint64_t const& i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint64_t const& i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, ss_uint64_t const& i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_SHORT_DISTINCT_INT_TYPE
template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, signed short i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}
template <ss_typename_param_k C>
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, unsigned short i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}
#endif /* STLSOFT_CF_SHORT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, int i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, int i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, cchRes);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned int i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C *buf, ss_size_t cchBuf, unsigned int i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}
#endif /* !STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, long i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, long i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, cchRes);
}

/** \brief Highly efficient conversion of integer to string.
 *
 * \ingroup group__library__conversion
 */
template <ss_typename_param_k C>
#if _STLSOFT_VER >= 0x010a0000
STLSOFT_DECLARE_FUNCTION_DEPRECATION_IN_FAVOUR_OF(integer_to_string, integer_to_decimal_string)
#endif /* >= 1.10 */
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, unsigned long i, ss_size_t* pcchRes)
{
    STLSOFT_ASSERT(NULL != pcchRes);

    return integer_to_decimal_string(buf, cchBuf, i, pcchRes);
}

template <ss_typename_param_k C>
STLSOFT_DECLARE_DEPRECATION_MESSAGE("The overloads of integer_to_string() that use a reference out-parameter to receive the written length are deprecated and will be removed in a future version of STLSoft; use the new pointer out-parameter overloads instead")
inline
C const*
integer_to_string(C* buf, ss_size_t cchBuf, unsigned long i, ss_size_t& cchRes)
{
    return integer_to_decimal_string(buf, cchBuf, i, &cchRes);
}
#endif /* !STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_STRING */

/* ///////////////////////////// end of file //////////////////////////// */
