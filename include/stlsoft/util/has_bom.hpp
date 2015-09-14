/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/has_bom.hpp
 *
 * Purpose:     Functions for searching for byte-headers in a byte range.
 *
 * Created:     19th March 2010
 * Updated:     21st August 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2010-2015, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/has_bom.hpp
 *
 * \brief [C++] Definition of the stlsoft::has_bom() function suite
 *   (\ref group__library__utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_HAS_BOM
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_HAS_BOM

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_HAS_BOM_MAJOR     1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_HAS_BOM_MINOR     0
# define STLSOFT_VER_STLSOFT_UTIL_HPP_HAS_BOM_REVISION  4
# define STLSOFT_VER_STLSOFT_UTIL_HPP_HAS_BOM_EDIT      7
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

inline
bool
has_bom(
    byte_t              b0
,   byte_t              b1
,   byte_t              b2
,   byte_t              b3
,   byte_t const*       from
,   byte_t const* const to
)
{
    if(from == to)
    {
        return false;
    }
    if(b0 != *from++)
    {
        return false;
    }

    if(from == to)
    {
        return false;
    }
    if(b1 != *from++)
    {
        return false;
    }

    if(from == to)
    {
        return false;
    }
    if(b2 != *from++)
    {
        return false;
    }

    if(from == to)
    {
        return false;
    }
    if(b3 != *from++)
    {
        return false;
    }

    return true;
}

inline
bool
has_bom(
    byte_t              b0
,   byte_t              b1
,   byte_t              b2
,   byte_t const*       from
,   byte_t const* const to
)
{
    if(from == to)
    {
        return false;
    }
    if(b0 != *from++)
    {
        return false;
    }

    if(from == to)
    {
        return false;
    }
    if(b1 != *from++)
    {
        return false;
    }

    if(from == to)
    {
        return false;
    }
    if(b2 != *from++)
    {
        return false;
    }

    return true;
}

inline
bool
has_bom(
    byte_t              b0
,   byte_t              b1
,   byte_t const*       from
,   byte_t const* const to
)
{
    if(from == to)
    {
        return false;
    }
    if(b0 != *from++)
    {
        return false;
    }

    if(from == to)
    {
        return false;
    }
    if(b1 != *from++)
    {
        return false;
    }

    return true;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_HAS_BOM */

/* ///////////////////////////// end of file //////////////////////////// */
