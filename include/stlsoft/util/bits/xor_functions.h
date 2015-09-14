/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/bits/xor_functions.h
 *
 * Purpose:     Bit XOR functions
 *
 * Created:     2nd June 2010
 * Updated:     6th July 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2010, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/bits/xor_functions.h
 *
 * \brief [C++ only] Functions to calculate XOR
 *   (\ref group__library__utility__bits "Bits" Utility Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS_MINOR    0
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS_REVISION 2
# define STLSOFT_VER_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS_EDIT     2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** Calculates the XOR over a range of 32-bit unsigned integers
 */
STLSOFT_INLINE ss_uint32_t calculate_xor_over_32bit_unsigned_range(
    ss_uint32_t const*  p
,   size_t              n
)
{
    ss_uint32_t r = 0;

    STLSOFT_COVER_MARK_LINE();

    { for(; 0u != n; ++p, --n)
    {
        STLSOFT_COVER_MARK_LINE();

        r ^= *p;
    }}

    STLSOFT_COVER_MARK_LINE();

    return r;
}

/** Calculates the XOR over a range of 8-bit unsigned integers
 */
STLSOFT_INLINE ss_uint8_t calculate_xor_over_8bit_unsigned_range(
    ss_uint8_t const*   p
,   size_t              n
)
{
    ss_uint8_t r = 0;

    STLSOFT_COVER_MARK_LINE();

    { for(; 0u != n; ++p, --n)
    {
        STLSOFT_COVER_MARK_LINE();

        r ^= *p;
    }}

    STLSOFT_COVER_MARK_LINE();

    return r;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_UTIL_BITS_H_XOR_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
