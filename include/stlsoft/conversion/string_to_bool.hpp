/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/string_to_bool.hpp
 *
 * Purpose:     String to integer conversions.
 *
 * Created:     6th September 2014
 * Updated:     7th September 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/string_to_bool.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::string_to_bool conversion
 *   function suite
 *   (\ref group__library__conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_BOOL
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_BOOL

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_BOOL_MAJOR    1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_BOOL_MINOR    0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_BOOL_REVISION 1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_STRING_TO_BOOL_EDIT     1
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
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */

# include <stlsoft/string/string_slice.h>

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
            XCOVER_CREATE_FILE_ALIAS("string_to_bool");
            XCOVER_MARK_FILE_START();
        }

    } instance;
}
#endif 

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

namespace ximpl_string_to_bool
{
    enum string_to_bool_flags_t
    {
    };

} /* namespace ximpl_string_to_bool */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

inline
bool
try_parse_to_bool(
    stlsoft_C_string_slice_a_t const*   trueSlices
,   ss_size_t                           numTrueSlices
,   stlsoft_C_string_slice_a_t const*   falseSlices
,   ss_size_t                           numFalseSlices
,   ss_char_a_t const*                  s
,   ss_size_t                           n
,   bool*                               result
,   int                              /* flags */
,   ss_char_a_t const**                 endptr
)
{
    ss_char_a_t const*  dummy;

    if(NULL == endptr)
    {
        endptr = &dummy;
    }

    { for(ss_size_t i = 0; numTrueSlices != i; ++i)
    {
        stlsoft_C_string_slice_a_t const& slice = trueSlices[i];

        if( 0 != slice.len &&
            n >= slice.len &&
            0 == ::memcmp(s, slice.ptr, slice.len * sizeof(ss_char_a_t)))
        {
            if(n > slice.len)
            {
                *endptr = &s[0] + slice.len;
            }
            else
            {
                *endptr = NULL;
            }

            *result = true;

            return true;
        }
    }}

    { for(ss_size_t i = 0; numFalseSlices != i; ++i)
    {
        stlsoft_C_string_slice_a_t const& slice = falseSlices[i];

        if( 0 != slice.len &&
            n >= slice.len &&
            0 == ::memcmp(s, slice.ptr, slice.len * sizeof(ss_char_a_t)))
        {
            if(n > slice.len)
            {
                *endptr = &s[0] + slice.len;
            }
            else
            {
                *endptr = NULL;
            }

            *result = false;

            return true;
        }
    }}

    *result = false;

    return false;
}

inline
bool
try_parse_to_bool(
    stlsoft_C_string_slice_w_t const*   trueSlices
,   ss_size_t                           numTrueSlices
,   stlsoft_C_string_slice_w_t const*   falseSlices
,   ss_size_t                           numFalseSlices
,   ss_char_w_t const*                  s
,   ss_size_t                           n
,   bool*                               result
,   int                              /* flags */
,   ss_char_w_t const**                 endptr
)
{
    ss_char_w_t const*  dummy;

    if(NULL == endptr)
    {
        endptr = &dummy;
    }

    { for(ss_size_t i = 0; numTrueSlices != i; ++i)
    {
        stlsoft_C_string_slice_w_t const& slice = trueSlices[i];

        if( 0 != slice.len &&
            n >= slice.len &&
            0 == ::memcmp(s, slice.ptr, slice.len * sizeof(ss_char_w_t)))
        {
            if(n > slice.len)
            {
                *endptr = &s[0] + slice.len;
            }
            else
            {
                *endptr = NULL;
            }

            *result = true;

            return true;
        }
    }}

    { for(ss_size_t i = 0; numFalseSlices != i; ++i)
    {
        stlsoft_C_string_slice_w_t const& slice = falseSlices[i];

        if( 0 != slice.len &&
            n >= slice.len &&
            0 == ::memcmp(s, slice.ptr, slice.len * sizeof(ss_char_w_t)))
        {
            if(n > slice.len)
            {
                *endptr = &s[0] + slice.len;
            }
            else
            {
                *endptr = NULL;
            }

            *result = false;

            return true;
        }
    }}

    *result = false;

    return false;
}



inline
bool
try_parse_to_bool(
    ss_char_a_t const*  s
,   ss_size_t           n
,   bool*               result
,   ss_char_a_t const** endptr
)
{
    static stlsoft_C_string_slice_a_t const trueSlices[] =
    {
            stlsoft_C_string_slice_a_t("true", 4)
        ,   stlsoft_C_string_slice_a_t("True", 4)
        ,   stlsoft_C_string_slice_a_t("TRUE", 4)
    };
    static stlsoft_C_string_slice_a_t const falseSlices[] =
    {
            stlsoft_C_string_slice_a_t("false", 5)
        ,   stlsoft_C_string_slice_a_t("False", 5)
        ,   stlsoft_C_string_slice_a_t("FALSE", 5)
    };

    return try_parse_to_bool(
                &trueSlices[0]
            ,   STLSOFT_NUM_ELEMENTS(trueSlices)
            ,   &falseSlices[0]
            ,   STLSOFT_NUM_ELEMENTS(falseSlices)
            ,   s
            ,   n
            ,   result
            ,   0
            ,   endptr
            );
}

inline
bool
try_parse_to_bool(
    ss_char_w_t const*  s
,   ss_size_t           n
,   bool*               result
,   ss_char_w_t const** endptr
);



inline
bool
try_parse_to_bool(
    ss_char_a_t const*  s
,   ss_size_t           n
,   bool*               result
)
{
    return try_parse_to_bool(s, n, result, static_cast<ss_char_a_t const**>(NULL));
}

inline
bool
try_parse_to_bool(
    ss_char_w_t const*  s
,   ss_size_t           n
,   bool*               result
)
{
    return try_parse_to_bool(s, n, result, static_cast<ss_char_w_t const**>(NULL));
}



inline
bool
try_parse_to_bool(
    ss_char_a_t const*  s
,   bool*               result
,   ss_char_a_t const** endptr
)
{
    static stlsoft_C_string_slice_a_t const trueSlices[] =
    {
            stlsoft_C_string_slice_a_t("true", 4)
        ,   stlsoft_C_string_slice_a_t("True", 4)
        ,   stlsoft_C_string_slice_a_t("TRUE", 4)
    };
    static stlsoft_C_string_slice_a_t const falseSlices[] =
    {
            stlsoft_C_string_slice_a_t("false", 5)
        ,   stlsoft_C_string_slice_a_t("False", 5)
        ,   stlsoft_C_string_slice_a_t("FALSE", 5)
    };

    return try_parse_to_bool(
                &trueSlices[0]
            ,   STLSOFT_NUM_ELEMENTS(trueSlices)
            ,   &falseSlices[0]
            ,   STLSOFT_NUM_ELEMENTS(falseSlices)
            ,   s
            ,   stlsoft::c_str_len_a(s)
            ,   result
            ,   0
            ,   endptr
            );
}

inline
bool
try_parse_to_bool(
    ss_char_w_t const*  s
,   bool*               result
,   ss_char_w_t const** endptr
)
{
    static stlsoft_C_string_slice_w_t const trueSlices[] =
    {
            stlsoft_C_string_slice_w_t(L"true", 4)
        ,   stlsoft_C_string_slice_w_t(L"True", 4)
        ,   stlsoft_C_string_slice_w_t(L"TRUE", 4)
    };
    static stlsoft_C_string_slice_w_t const falseSlices[] =
    {
            stlsoft_C_string_slice_w_t(L"false", 5)
        ,   stlsoft_C_string_slice_w_t(L"False", 5)
        ,   stlsoft_C_string_slice_w_t(L"FALSE", 5)
    };

    return try_parse_to_bool(
                trueSlices
            ,   STLSOFT_NUM_ELEMENTS(trueSlices)
            ,   falseSlices
            ,   STLSOFT_NUM_ELEMENTS(falseSlices)
            ,   s
            ,   stlsoft::c_str_len_w(s)
            ,   result
            ,   0
            ,   endptr
            );
}



inline
bool
try_parse_to_bool(
    ss_char_a_t const*  s
,   bool*               result
)
{
    return try_parse_to_bool(s, result, static_cast<ss_char_a_t const**>(NULL));
}

inline
bool
try_parse_to_bool(
    ss_char_w_t const*  s
,   bool*               result
)
{
    return try_parse_to_bool(s, result, static_cast<ss_char_w_t const**>(NULL));
}

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

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_BOOL */

/* ///////////////////////////// end of file //////////////////////////// */
