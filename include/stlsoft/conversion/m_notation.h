/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/m_notation.h
 *
 * Purpose:     M-notation conversion.
 *
 * Created:     1st June 2009
 * Updated:     27th April 2010
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


/** \file stlsoft/conversion/m_notation.h
 *
 * \brief [C++ only] Definition of the stlsoft::convert_to_M_notation()
 *   function
 *   (\ref group__library__conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_H_M_NOTATION
#define STLSOFT_INCL_STLSOFT_CONVERSION_H_M_NOTATION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_H_M_NOTATION_MAJOR      1
# define STLSOFT_VER_STLSOFT_CONVERSION_H_M_NOTATION_MINOR      0
# define STLSOFT_VER_STLSOFT_CONVERSION_H_M_NOTATION_REVISION   2
# define STLSOFT_VER_STLSOFT_CONVERSION_H_M_NOTATION_EDIT       4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

 /* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** Converts a character to M-notation
 *
 * \param ch The character whose value will be converted to M-notation
 * \param ar A pointer to an array of five characters to receive the result
 *   of the conversion
 *
 * \return The number of characters written to \c ar, not including the 
 *   nul-terminator
 */
STLSOFT_INLINE stlsoft_ns_qual(ss_size_t) convert_to_M_notation(
    signed char ch
,   char        (*ar)[5]
)
{
    char*   p = ar[0];
    size_t  b = 0u;

    /* These characters don't have M- equivalents, so handle them
     * as special cases
     */
    switch(ch)
    {
        case    ' ':
        case    '\t':
        case    '\n':
            p[0] = ch;
            p[1] = '\0';
            return 1u;
        case    -96:
            p[0] = 'M';
            p[1] = '-';
            p[2] = ' ';
            p[3] = '\0';
            return 3u;
        default:
            break;
    }

    /* For all other characters, we can use M- equivalent if
     * they're < 0
     */

    if(ch < 0)
    {
        *p++ = 'M';
        *p++ = '-';
        ch = stlsoft_static_cast(signed char, 128 + ch);
        b += 2;
    }

    if(127 == ch)
    {
        p[0] = '^';
        p[1] = '?';
        p[2] = '\0';
        return b + 2u;
    }
    else if(ch >= 0 &&
            ch < 32)
    {
        p[0] = '^';
        p[1] = stlsoft_static_cast(signed char, ch + '@');
        p[2] = '\0';
        return b + 2u;
    }
    else
    {
        p[0] = ch;
        p[1] = '\0';

        return b + 1u;
    }

    return 5u; // Error value
}    


/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_CONVERSION_H_M_NOTATION */

/* ///////////////////////////// end of file //////////////////////////// */
