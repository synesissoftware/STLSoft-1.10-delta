/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/integer_to_hex_string.hpp
 *
 * Purpose:     Conversion of integers to base-16 strings.
 *
 * Created:     12th July 2009
 * Updated:     21st June 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2009-2010, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/integer_to_hex_string.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::integer_to_hex_string function
 *   template
 *   (\ref group__library__conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_HEX_STRING
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_HEX_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_HEX_STRING_MAJOR     1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_HEX_STRING_MINOR     0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_HEX_STRING_REVISION  4
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_HEX_STRING_EDIT      7
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
*/

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_SIZE_TRAITS
# include <stlsoft/util/size_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_SIZE_TRAITS */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Code Coverage
 */

#ifdef STLSOFT_USE_XCOVER
namespace
{
    class register_with_xcover
    {
    public:
        register_with_xcover()
        {
            XCOVER_CREATE_FILE_ALIAS("integer_to_hex_string");
            XCOVER_MARK_FILE_START();
        }

    } instance;
}
#endif 

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

namespace ximpl_stlsoft_conversion_integer_to_hex_string
{
    static char const* integer_to_hex_string_get_characters(int useUppercase)
    {
        static const char s_chars[2][16] =
        {
            {
                    '0'
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
            },
            {
                    '0'
                ,   '1'
                ,   '2'
                ,   '3'
                ,   '4'
                ,   '5'
                ,   '6'
                ,   '7'
                ,   '8'
                ,   '9'
                ,   'A'
                ,   'B'
                ,   'C'
                ,   'D'
                ,   'E'
                ,   'F'
            },
        };

        STLSOFT_COVER_MARK_LINE();

        return s_chars[0 != useUppercase];
    }

    template <size_t N>
    struct integer_to_hex_string_type_selector;

    template <>
    struct integer_to_hex_string_type_selector<4>
    {
        typedef uint32_t    type;
    };
    template <>
    struct integer_to_hex_string_type_selector<8>
    {
        typedef uint32_t    type;
    };

} /* namespace ximpl_stlsoft_conversion_integer_to_hex_string */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** Converts a 32-bit unsigned integer to hex string form
 *
 * \pre (cchBuffer >= 9)
 */
template <ss_typename_param_k C>
inline C const* integer_to_hex_string(
    C*          buffer
,   size_t      cchBuffer
,   uint32_t    value
)
{
    STLSOFT_ASSERT(cchBuffer >= 9);

    STLSOFT_COVER_MARK_LINE();

    C*          p       =   &buffer[cchBuffer - 1];
    char const* chars   =   ximpl_stlsoft_conversion_integer_to_hex_string::integer_to_hex_string_get_characters(false);

    *p-- = '\0';

    if(0 == value)
    {
        STLSOFT_COVER_MARK_LINE();

        *p = chars[0];
    }
    else
    {
        STLSOFT_COVER_MARK_LINE();

        for(;;)
        {
            STLSOFT_COVER_MARK_LINE();

            *p = chars[value & 0x0f];

            value >>= 4;
            if(0 == value)
            {
                STLSOFT_COVER_MARK_LINE();

                break;
            }
            else
            {
                STLSOFT_COVER_MARK_LINE();

                --p;
            }

            STLSOFT_COVER_MARK_LINE();
        }

        STLSOFT_COVER_MARK_LINE();
    }

    return p;
}

template <ss_typename_param_k C>
inline C const* integer_to_hex_string(
    C*           buffer
,   size_t       cchBuffer
,   uint32_t     value
,   C const*     prefix
)
{
    STLSOFT_COVER_MARK_LINE();

    const size_t prefixLen = c_str_len(prefix);

    STLSOFT_ASSERT(cchBuffer >= 9 + prefixLen);

    C* p = const_cast<C*>(integer_to_hex_string(buffer, cchBuffer, value));

    memcpy(p - prefixLen, prefix, sizeof(C) * prefixLen);
    p -= prefixLen;

    return p;
}

template <ss_typename_param_k C>
inline C const* integer_to_hex_string(
    C*          buffer
,   size_t      cchBuffer
,   uint64_t    value
)
{
    STLSOFT_COVER_MARK_LINE();

    const uint32_t  low     =   static_cast<uint32_t>(value);
    const uint32_t  high    =   static_cast<uint32_t>(value >> 32);

    C* const    end =   buffer + cchBuffer;
    C*          p   =   const_cast<C*>(integer_to_hex_string(buffer, cchBuffer, low));

    if(0 != high)
    {
        STLSOFT_COVER_MARK_LINE();

        for(; p != end - 9;)
        {
            STLSOFT_COVER_MARK_LINE();

            *--p = '0';
        }

        STLSOFT_COVER_MARK_LINE();

        const C ch = buffer[cchBuffer - 9];
        p = const_cast<C*>(integer_to_hex_string(buffer, cchBuffer - 8, high));
        buffer[cchBuffer - 9] = ch;
    }

    return p;
}

template <ss_typename_param_k C>
inline C const* integer_to_hex_string(
    C*      buffer
,   size_t  cchBuffer
,   int     value
)
{
    typedef int_size_traits<sizeof(int)>::unsigned_type unsigned_t;

    return integer_to_hex_string(buffer, cchBuffer, static_cast<unsigned_t>(value));
}

template <ss_typename_param_k C>
inline C const* integer_to_hex_string(
    C*          buffer
,   size_t      cchBuffer
,   int         value
,   C const*    prefix
)
{
    typedef int_size_traits<sizeof(int)>::unsigned_type unsigned_t;

    return integer_to_hex_string(buffer, cchBuffer, static_cast<unsigned_t>(value), prefix);
}

#if defined(STLSOFT_CF_INT_DISTINCT_INT_TYPE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

template <ss_typename_param_k C>
inline C const* integer_to_hex_string(
    C*              buffer
,   size_t          cchBuffer
,   unsigned int    value
)
{
    typedef ximpl_stlsoft_conversion_integer_to_hex_string::integer_to_hex_string_type_selector<8>::type    unsigned_t;

    return integer_to_hex_string(buffer, cchBuffer, static_cast<unsigned_t>(value));
}

template <ss_typename_param_k C>
inline C const* integer_to_hex_string(
    C*              buffer
,   size_t          cchBuffer
,   unsigned int    value
,   C const*        prefix
)
{
    typedef ximpl_stlsoft_conversion_integer_to_hex_string::integer_to_hex_string_type_selector<8>::type    unsigned_t;

    return integer_to_hex_string(buffer, cchBuffer, static_cast<unsigned_t>(value), prefix);
}

#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE && !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Code Coverage
 */

#ifdef STLSOFT_USE_XCOVER
namespace
{
    class register_with_xcover_posterior
    {
    public:
        register_with_xcover_posterior()
        {
            XCOVER_MARK_FILE_END();
        }

    } instance_posterior;
}
#endif 

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_HEX_STRING */

/* ///////////////////////////// end of file //////////////////////////// */
