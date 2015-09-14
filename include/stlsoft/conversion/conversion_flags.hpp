/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/conversion_flags.hpp
 *
 * Purpose:     Specifies compile-time enforced conversion flags used by
 *              various elements in the Conversion library.
 *
 * Created:     16th July 2012
 * Updated:     20th May 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006-2014, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/conversion_flags.hpp
 *
 * \brief [C++ only] Specifies compile-time enforced conversion flags used
 *   by various elements in
 *   the \ref group__library__conversion "Conversion" Library
 *   (\ref group__library__conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CONVERSION_FLAGS
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CONVERSION_FLAGS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_CONVERSION_FLAGS_MAJOR      1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_CONVERSION_FLAGS_MINOR      0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_CONVERSION_FLAGS_REVISION   5
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_CONVERSION_FLAGS_EDIT       9
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

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace ximpl_conversion
{

    enum conversion_base_t
    {
            cb_none                 =   0
#if 0
        ,   cb_binary               =   2
#endif /* 0 */
        ,   cb_octal                =   8
        ,   cb_decimal              =   10
        ,   cb_hexadecimal          =   16
    };

    enum conversion_decorations_t
    {
            cd_none                 =   0
        ,   cd_showPlusSign         =   0x0001
        ,   cd_showBasePrefix       =   0x0002
        ,   cd_uppercaseAlpha       =   0x0010
#if 0
        ,   cd_padToTypeWidth       =   0x0100
#endif /* 0 */
        ,   cd_withLocaleSeparators =   0x1000
    };

    /* Proscribe enumeration OR-operations */
    void operator |(conversion_base_t, conversion_base_t);
    void operator |(conversion_decorations_t, conversion_decorations_t);


    template<
        conversion_base_t           B
    ,   conversion_decorations_t    D
    >
    struct conversion_flag;

    template<
        conversion_base_t           B1
    ,   conversion_decorations_t    D1
    ,   conversion_base_t           B2
    ,   conversion_decorations_t    D2
    >
    struct flag_type_generator
    {
    private:
        typedef conversion_flag<B1, D1>     flag_1_type;
        typedef conversion_flag<B2, D2>     flag_2_type;

    public:
        typedef conversion_flag<
            conversion_base_t(static_cast<conversion_base_t>(static_cast<int>(B1) | static_cast<int>(B2)))
        ,   conversion_decorations_t(static_cast<conversion_decorations_t>(static_cast<int>(D1) | static_cast<int>(D2)))
        >   type;
    };

    template <>
    struct conversion_flag<
        cb_none
    ,   cd_none
    >
    {
        enum {  base        =   cb_none     };
        enum {  decorations =   cd_none     };

#if defined(STLSOFT_COMPILER_IS_GCC)
    public:
        conversion_flag()
        {}
#endif /* compiler */
    };

    template<
        conversion_base_t           B
    ,   conversion_decorations_t    D
    >
    struct conversion_flag
        : public conversion_flag<cb_none, cd_none>
    {
        enum {  base        =   B           };
        enum {  decorations =   D           };

#if defined(STLSOFT_COMPILER_IS_GCC)
    public:
        conversion_flag()
        {}
#endif /* compiler */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
    public:
        template <
            conversion_base_t           B2
        ,   conversion_decorations_t    D2
        >
        ss_typename_type_k flag_type_generator<B, D, B2, D2>::type
        operator |(
            conversion_flag<B2, D2> const&
        ) const
        {
            typedef conversion_flag<B, D>       flag_1_t;
            typedef conversion_flag<B2, D2>     flag_2_t;

            STLSOFT_STATIC_ASSERT((0 == flag_1_t::base) || (0 == flag_2_t::base));

            typedef ss_typename_type_k flag_type_generator<B, D, B2, D2>::type  return_t;

            return return_t();
        }
#endif /* compiler */
    };

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1310
    template<
        conversion_base_t           B1
    ,   conversion_decorations_t    D1
    ,   conversion_base_t           B2
    ,   conversion_decorations_t    D2
    >
    inline
    ss_typename_type_k flag_type_generator<B1, D1, B2, D2>::type
    operator |(
        conversion_flag<B1, D1> //const&
    ,   conversion_flag<B2, D2> //const&
    )
    {
        typedef conversion_flag<B1, D1>     flag_1_t;
        typedef conversion_flag<B2, D2>     flag_2_t;

        STLSOFT_STATIC_ASSERT((0 == flag_1_t::base) || (0 == flag_2_t::base));

# if defined(STLSOFT_COMPILER_IS_DMC)
        typedef ss_typename_type_k flag_type_generator<B1, D1, B2, D2>::type    return_t;

        return return_t();
# else
        return ss_typename_type_k flag_type_generator<B1, D1, B2, D2>::type();
# endif
    }
#endif /* compiler */


    typedef conversion_flag<cb_none, cd_none>                   none_t;

    typedef conversion_flag<cb_octal, cd_none>                  octal_t;
    typedef conversion_flag<cb_decimal, cd_none>                decimal_t;
    typedef conversion_flag<cb_hexadecimal, cd_none>            hexadecimal_t;

    typedef conversion_flag<cb_none, cd_uppercaseAlpha>         uppercaseAlpha_t;
    typedef conversion_flag<cb_none, cd_showPlusSign>           showPlusSign_t;
    typedef conversion_flag<cb_none, cd_showBasePrefix>         showBasePrefix_t;
    typedef conversion_flag<cb_none, cd_withLocaleSeparators>   withLocaleSeparators_t;

} /* namespace ximpl_conversion */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

namespace conversion
{

    /// Specifies default formatting
    const ::stlsoft::ximpl_conversion::none_t                   none;

    /// Specifies that formatting should result in decimal numeric representation
    const ::stlsoft::ximpl_conversion::octal_t                  octal;
    /// Specifies that formatting should result in octal numeric representation
    const ::stlsoft::ximpl_conversion::decimal_t                decimal;
    /// Specifies that formatting should result in hexadecimal numeric representation
    const ::stlsoft::ximpl_conversion::hexadecimal_t            hexadecimal;

    /// Specifies that formatting should use uppercase alpha digits
    const ::stlsoft::ximpl_conversion::uppercaseAlpha_t         uppercaseAlpha;
    /// Specifies that formatting should include a +-sign prefix for positive numeric values
    const ::stlsoft::ximpl_conversion::showPlusSign_t           showPlusSign;
    /// Specifies that formatting should include a (C-language) base prefix for non-decimal numeric representation
    const ::stlsoft::ximpl_conversion::showBasePrefix_t         showBasePrefix;
#if 0
    const ::stlsoft::ximpl_conversion::padToTypeSize_t          padToTypeSize;
#endif /* 0 */
    /// Specifies that formatting should use locale-specific grouping and separators for (decimal) numeric representation
    const ::stlsoft::ximpl_conversion::withLocaleSeparators_t   withLocaleSeparators;

} /* namespace conversion */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CONVERSION_FLAGS */

/* ///////////////////////////// end of file //////////////////////////// */
