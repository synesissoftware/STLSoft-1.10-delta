/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/integer_to_string/integer_to_hexadecimal_string.hpp (originally stlsoft_integer_to_string.h)
 *
 * Purpose:     Very efficient integer to string conversion functions for
 *              hexadecimal representation.
 *
 * Created:     7th April 2002
 * Updated:     20th May 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2014, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/integer_to_string/integer_to_hexadecimal_string.hpp
 *
 * \brief [C++ only] Very efficient integer to string conversion functions
 *   for hexadecimal representation
 *  (\ref group__library__conversion "Conversion" Library.)
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING
#define STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING_MAJOR       5
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING_MINOR       0
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING_REVISION    11
# define STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING_EDIT        80
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
# include <stlsoft/meta/is_integral_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE
# include <stlsoft/meta/is_signed_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES
# include <stlsoft/meta/n_types.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS
# include <stlsoft/limits/integral_format_width_limits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_FORMAT_WIDTH_LIMITS */
#ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS
# include <stlsoft/limits/integral_limits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS
# include <stlsoft/util/sign_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS */

#ifndef STLSOFT_INCL_H_STRING
# define STLSOFT_INCL_H_STRING
# include <string.h>
#endif /* !STLSOFT_INCL_H_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Worker functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_OPEN_WORKER_NS_(ximpl_I2S)

/* get subscriptable pointer to array of hexadecimal characters */
template <ss_typename_param_k C>
inline
C const*
#ifdef STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS
# define STLSOFT_I2S_H2S_GET_DIGIT_CHARACTER(C)     get_hexadecimal_digit_character(static_cast<C*>(0))
get_hexadecimal_digit_character(C*)
#else /* ? STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */
# define STLSOFT_I2S_H2S_GET_DIGIT_CHARACTER(C)     get_hexadecimal_digit_character<C>()
get_hexadecimal_digit_character()
#endif /* STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */
{
    static C const s_characters[31] =
    {
            'f'
        ,   'e'
        ,   'd'
        ,   'c'
        ,   'b'
        ,   'a'
        ,   '9'
        ,   '8'
        ,   '7'
        ,   '6'
        ,   '5'
        ,   '4'
        ,   '3'
        ,   '2'
        ,   '1'
        ,   '0'
        ,   '1'
        ,   '2'
        ,   '3'
        ,   '4'
        ,   '5'
        ,   '6'
        ,   '7'
        ,   '8'
        ,   '9'
        ,   'a'
        ,   'b'
        ,   'c'
        ,   'd'
        ,   'e'
        ,   'f'
    };
#if 0
    static C const* s_mid = s_characters + 15;

    return s_mid;
#else /* ? 0 */
    return s_characters + 15;
#endif /* 0 */
}

/* selector traits class for remainder type */
template <ss_typename_param_k T_Integer>
struct i2s_hexadecimal_remainder_traits_t
{
#if 0
    typedef T_Integer       remainder_type;
#else
    typedef unsigned int    remainder_type;
#endif
};

/* main conversion function (unsigned) */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
unsigned_integer_to_hexadecimal_string(
    C*          buf
,   ss_size_t   cchBuf
,   I /* const& */  i
)
{
    STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<I>::value);
    STLSOFT_STATIC_ASSERT(0 == stlsoft::is_signed_type<I>::value);

    typedef integral_format_width_limits<I>         width_traits_t;
    typedef i2s_hexadecimal_remainder_traits_t<I>   remainder_traits_t;

    STLSOFT_ASSERT(cchBuf >= 1 + width_traits_t::maxHexadecimalWidth);

    C* end = buf + (cchBuf - 1);

    // Whichever we do it, we write the nul-terminator (and move down
    // one)
    *end-- = '\0';

    STLSOFT_COVER_MARK_LINE();

    if(0 == i)
    {
        STLSOFT_COVER_MARK_LINE();

        *end = '0';

        return end;
    }
    else
    {
        STLSOFT_COVER_MARK_LINE();

#if 1
        C const* const hchars = STLSOFT_I2S_H2S_GET_DIGIT_CHARACTER(C);
#endif /* 0 */

        C* p = end;

        for(;;)
        {
            STLSOFT_COVER_MARK_LINE();

            ss_typename_type_k remainder_traits_t::remainder_type const rem = i & 0xf;

#if 0
            *p = STLSOFT_I2S_H2S_GET_DIGIT_CHARACTER(C)[rem];
#else /* ? 0 */
            *p = hchars[rem];
#endif /* 0 */

            i >>= 4;

            if(0 == i)
            {
                STLSOFT_COVER_MARK_LINE();

                break;
            }
            else
            {
                STLSOFT_COVER_MARK_LINE();

                --p;
            }
        }

        STLSOFT_COVER_MARK_LINE();

        return p;
    }
}

/* secondary conversion function (unsigned) that calculates numWritten */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
unsigned_integer_to_hexadecimal_string(
    C*          buf
,   ss_size_t   cchBuf
,   I const&    i
,   ss_size_t*  numWritten
)
{
    STLSOFT_COVER_MARK_LINE();

    C const* const r = unsigned_integer_to_hexadecimal_string<I, C>(buf, cchBuf, i);

    if(NULL != numWritten)
    {
        STLSOFT_COVER_MARK_LINE();

        *numWritten = cchBuf - (r - (buf - 1));
    }

    STLSOFT_COVER_MARK_LINE();

    return r;
}

/* (invalid) generic form of signed-minimum-handler */
template<
    ss_typename_param_k C
>
void
i2s_handle_signed_minimum_in_hexadecimal_2_(
    C*          buf
,   ss_size_t   cchBuf
,   ...
);

/* 8-bit form of signed-minimum-handler */
template<
    ss_typename_param_k C
>
inline
C const*
i2s_handle_signed_minimum_in_hexadecimal_2_(
    C*          buf
,   ss_size_t   cchBuf
,   size_type<1> const&
)
{
    STLSOFT_COVER_MARK_LINE();

    static C const  s_minimum[] = { '-', '8', '0', '\0' };

    STLSOFT_ASSERT(cchBuf >= STLSOFT_NUM_ELEMENTS(s_minimum));

    C* end  =   buf + cchBuf;
    C* r    =   end - STLSOFT_NUM_ELEMENTS(s_minimum);

    ::memcpy(r, s_minimum, sizeof(C) * STLSOFT_NUM_ELEMENTS(s_minimum));

    STLSOFT_COVER_MARK_LINE();

    return r;
}

/* 16-bit form of signed-minimum-handler */
template<
    ss_typename_param_k C
>
inline
C const*
i2s_handle_signed_minimum_in_hexadecimal_2_(
    C*          buf
,   ss_size_t   cchBuf
,   size_type<2> const&
)
{
    STLSOFT_COVER_MARK_LINE();

    static C const  s_minimum[] = { '-', '8', '0', '0', '0', '\0' };

    STLSOFT_ASSERT(cchBuf >= STLSOFT_NUM_ELEMENTS(s_minimum));

    C* end  =   buf + cchBuf;
    C* r    =   end - STLSOFT_NUM_ELEMENTS(s_minimum);

    ::memcpy(r, s_minimum, sizeof(C) * STLSOFT_NUM_ELEMENTS(s_minimum));

    STLSOFT_COVER_MARK_LINE();

    return r;
}

/* 32-bit form of signed-minimum-handler */
template<
    ss_typename_param_k C
>
inline
C const*
i2s_handle_signed_minimum_in_hexadecimal_2_(
    C*          buf
,   ss_size_t   cchBuf
,   size_type<4> const&
)
{
    STLSOFT_COVER_MARK_LINE();

    static C const  s_minimum[] = { '-', '8', '0', '0', '0', '0', '0', '0', '0', '\0' };

    STLSOFT_ASSERT(cchBuf >= STLSOFT_NUM_ELEMENTS(s_minimum));

    C* end  =   buf + cchBuf;
    C* r    =   end - STLSOFT_NUM_ELEMENTS(s_minimum);

    ::memcpy(r, s_minimum, sizeof(C) * STLSOFT_NUM_ELEMENTS(s_minimum));

    STLSOFT_COVER_MARK_LINE();

    return r;
}

/* 64-bit form of signed-minimum-handler */
template<
    ss_typename_param_k C
>
inline
C const*
i2s_handle_signed_minimum_in_hexadecimal_2_(
    C*          buf
,   ss_size_t   cchBuf
,   size_type<8> const&
)
{
    STLSOFT_COVER_MARK_LINE();

    static C const  s_minimum[] = { '-', '8', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };

    STLSOFT_ASSERT(cchBuf >= STLSOFT_NUM_ELEMENTS(s_minimum));

    C* end  =   buf + cchBuf;
    C* r    =   end - STLSOFT_NUM_ELEMENTS(s_minimum);

    ::memcpy(r, s_minimum, sizeof(C) * STLSOFT_NUM_ELEMENTS(s_minimum));

    STLSOFT_COVER_MARK_LINE();

    return r;
}

/* generic signed-type catch-all handler : casts to sized, signed type */
template<
    ss_typename_param_k C
,   ss_typename_param_k I
>
inline
C const*
i2s_handle_signed_minimum_in_hexadecimal_(
    C*          buf
,   ss_size_t   cchBuf
,   I           /* i */
)
{
    STLSOFT_STATIC_ASSERT(0 != stlsoft::is_signed_type<I>::value);

    STLSOFT_COVER_MARK_LINE();

    enum { sizeofI = sizeof(I) };

    typedef size_type<sizeofI>      sized_t;

    return i2s_handle_signed_minimum_in_hexadecimal_2_(buf, cchBuf, sized_t());
}

/* secondary conversion function (signed), implemented in terms of unsigned version */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
signed_integer_to_hexadecimal_string(
    C*          buf
,   ss_size_t   cchBuf
,   I /* const& */  i
)
{
    STLSOFT_COVER_MARK_LINE();

    STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<I>::value);
    STLSOFT_STATIC_ASSERT(0 != stlsoft::is_signed_type<I>::value);

    typedef integral_format_width_limits<I>                     width_traits_t;
    typedef integral_limits<I>                                  limit_traits_t;

    STLSOFT_ASSERT(cchBuf >= 1 + width_traits_t::maxHexadecimalWidth);

    typedef ss_typename_type_k sign_traits<I>::unsigned_type    unsigned_t;

    if(i < 0)
    {
        STLSOFT_COVER_MARK_LINE();

        if(i == limit_traits_t::minimum())
        {
            STLSOFT_COVER_MARK_LINE();

            return i2s_handle_signed_minimum_in_hexadecimal_(buf, cchBuf, i);
        }
        else
        {
            STLSOFT_COVER_MARK_LINE();

            C const* r2 = unsigned_integer_to_hexadecimal_string(buf, cchBuf, unsigned_t(-i));

            *const_cast<C*>(--r2) = C('-');

            STLSOFT_COVER_MARK_LINE();

            return r2;
        }
    }
    else
    {
        STLSOFT_COVER_MARK_LINE();

        return unsigned_integer_to_hexadecimal_string(buf, cchBuf, unsigned_t(i));
    }
}

/* secondary conversion function (signed) that calculates numWritten */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
signed_integer_to_hexadecimal_string(
    C*          buf
,   ss_size_t   cchBuf
,   I const&    i
,   ss_size_t*  numWritten
)
{
    STLSOFT_COVER_MARK_LINE();

    C const* const r = signed_integer_to_hexadecimal_string<I, C>(buf, cchBuf, i);

    if(NULL != numWritten)
    {
        STLSOFT_COVER_MARK_LINE();

        *numWritten = cchBuf - (r - (buf - 1));
    }

    STLSOFT_COVER_MARK_LINE();

    return r;
}

/* TMP compile-time selector of unsigned/signed work function */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
integer_to_hexadecimal_string_if_signed_(
    yes_type
,   C*          buf
,   ss_size_t   cchBuf
,   I const&    i
,   ss_size_t*  numWritten
)
{
    STLSOFT_COVER_MARK_LINE();

    return signed_integer_to_hexadecimal_string(buf, cchBuf, i, numWritten);
}

/* TMP compile-time selector of unsigned/signed work function */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
integer_to_hexadecimal_string_if_signed_(
    no_type
,   C*          buf
,   ss_size_t   cchBuf
,   I const&    i
,   ss_size_t*  numWritten
)
{
    STLSOFT_COVER_MARK_LINE();

    return unsigned_integer_to_hexadecimal_string(buf, cchBuf, i, numWritten);
}

/* TMP compile-time selector of unsigned/signed work function */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
integer_to_hexadecimal_string_if_signed_(
    yes_type
,   C*          buf
,   ss_size_t   cchBuf
,   I const&    i
)
{
    STLSOFT_COVER_MARK_LINE();

    return signed_integer_to_hexadecimal_string(buf, cchBuf, i);
}

/* TMP compile-time selector of unsigned/signed work function */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
integer_to_hexadecimal_string_if_signed_(
    no_type
,   C*          buf
,   ss_size_t   cchBuf
,   I const&    i
)
{
    STLSOFT_COVER_MARK_LINE();

    return unsigned_integer_to_hexadecimal_string(buf, cchBuf, i);
}

STLSOFT_CLOSE_WORKER_NS_(ximpl_I2S)

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Converts an integer value into a hexadecimal string representation in the
 * given character buffer.
 *
 */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
integer_to_hexadecimal_string(
    C*          buf
,   ss_size_t   cchBuf
,   I const&    i
)
{
    STLSOFT_COVER_MARK_LINE();

    typedef ss_typename_type_k is_signed_type<I>::type signed_yesno_t;

    return STLSOFT_WORKER_NS_QUAL_(ximpl_I2S, integer_to_hexadecimal_string_if_signed_)(signed_yesno_t(), buf, cchBuf, i);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
/** Converts an integer value into a hexadecimal string representation in the
 * given character buffer.
 *
 */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
,   ss_size_t           N
>
inline
C const*
integer_to_hexadecimal_string(
    C         (&ar)[N]
,   I const&    i
)
{
    STLSOFT_COVER_MARK_LINE();

    typedef integral_format_width_limits<I> width_traits_t;

    STLSOFT_STATIC_ASSERT(N >= 1 + width_traits_t::maxHexadecimalWidth);

    STLSOFT_COVER_MARK_LINE();

    return integer_to_hexadecimal_string(&ar[0], N, i);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

/** Converts an integer value into a hexadecimal string representation in the
 * given character buffer, assigning the number of characters (excluding
 * the nul-terminator) written into the given size variable.
 *
 */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
>
inline
C const*
integer_to_hexadecimal_string(
    C*          buf
,   ss_size_t   cchBuf
,   I const&    i
,   ss_size_t*  numWritten
)
{
    STLSOFT_COVER_MARK_LINE();

    typedef ss_typename_type_k is_signed_type<I>::type signed_yesno_t;

    return STLSOFT_WORKER_NS_QUAL_(ximpl_I2S, integer_to_hexadecimal_string_if_signed_)(signed_yesno_t(), buf, cchBuf, i, numWritten);
}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
/** Converts an integer value into a hexadecimal string representation in the
 * given character buffer, assigning the number of characters (excluding
 * the nul-terminator) written into the given size variable.
 *
 */
template<
    ss_typename_param_k I
,   ss_typename_param_k C
,   ss_size_t           N
>
inline
C const*
integer_to_hexadecimal_string(
    C         (&ar)[N]
,   I const&    i
,   ss_size_t*  numWritten
)
{
    STLSOFT_COVER_MARK_LINE();

    typedef integral_format_width_limits<I> width_traits_t;

    STLSOFT_STATIC_ASSERT(N >= 1 + width_traits_t::maxHexadecimalWidth);

    return integer_to_hexadecimal_string(&ar[0], N, i, numWritten);
}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING */

/* ///////////////////////////// end of file //////////////////////////// */
