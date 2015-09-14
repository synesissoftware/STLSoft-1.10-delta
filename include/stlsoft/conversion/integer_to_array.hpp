/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/integer_to_array.hpp
 *
 * Purpose:     Bitwise splitting of integer values into arrays.
 *
 * Created:     13th May 2009
 * Updated:     31st May 2010
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


/** \file stlsoft/conversion/integer_to_array.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::integer_to_array function
 *   template
 *   (\ref group__library__conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_ARRAY
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_ARRAY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_ARRAY_MAJOR      1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_ARRAY_MINOR      0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_ARRAY_REVISION   2
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_INTEGER_TO_ARRAY_EDIT       5
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
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
# include <stlsoft/meta/is_integral_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS
# include <stlsoft/util/sign_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS */

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
            XCOVER_CREATE_FILE_ALIAS("string_to_integer");
            XCOVER_MARK_FILE_START();
        }

    } instance;
}
#endif 

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

class integer_array
    : public stlsoft::auto_buffer<int>
{
public:
    typedef stlsoft::auto_buffer<int>   parent_class_type;
    typedef integer_array               class_type;

public:
    integer_array(size_t n)
        : parent_class_type(n)
    {}
    integer_array(integer_array const& rhs)
        : parent_class_type(rhs.size())
    {
        ::memcpy(data(), rhs.data(), rhs.size() * sizeof(int));
    }
};


/** Converts an integer value into a number of units of the given
 * bits
 *
 * \param v The value to split
 * \param bitSplitFactor The number of bits in each unit
 */
template <ss_typename_param_k I>
integer_array integer_to_array(I v, size_t bitSplitFactor)
{
    STLSOFT_STATIC_ASSERT(is_integral_type<I>::value);

    STLSOFT_ASSERT(0 != bitSplitFactor);

#ifndef STLSOFT_COMPILER_IS_BORLAND
    const // Good old Borland thinks a const one of these never gets used!
#endif /* !compiler */
          size_t    bits    =   sign_traits<I>::bits;
    size_t          n       =   (bitSplitFactor < bits) ? ((bits + (bitSplitFactor - 1u)) / bitSplitFactor) : 1u;
    I               mask;

    if(bitSplitFactor >= bits)
    {
        bitSplitFactor = bits;

        mask = I(~I(0));
    }
    else
    {
        mask = I((I(1) << bitSplitFactor) - 1);
    }

    integer_array   r(n);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if(!r.empty())
#endif
    {
        { for(size_t i = 0; i != n; ++i)
        {
            r[i] = int(v & mask);
            v >>= bitSplitFactor;
        }}
    }

    return r;
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

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_INTEGER_TO_ARRAY */

/* ///////////////////////////// end of file //////////////////////////// */
