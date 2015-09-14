/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/rand.hpp
 *
 * Purpose:     Random number generator for large integral types.
 *
 * Created:     12th July 2009
 * Updated:     13th October 2010
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


/** \file stlsoft/util/rand.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::rand<> function
 *   template
 *   (\ref group__library__conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_RAND
#define STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_RAND

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_RAND_MAJOR       1
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_RAND_MINOR       0
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_RAND_REVISION    5
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_RAND_EDIT        7
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
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
# include <stlsoft/meta/is_integral_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS
# include <stlsoft/util/limit_traits.h>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_H_LIMIT_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_SIZE_TRAITS
# include <stlsoft/util/size_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_SIZE_TRAITS */

#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h> // for rand()
#endif /* !STLSOFT_INCL_H_STDLIB */

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
            XCOVER_CREATE_FILE_ALIAS("rand");
            XCOVER_MARK_FILE_START();
        }

    } instance;
}
#endif 

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct x_stlsoft_util_rand_impl
{
    template <typename T>
    static size_t bits_in_(T const& t)
    {
        typedef ss_typename_type_k stlsoft::int_size_traits<sizeof(T)>::unsigned_type   unsigned_t;

        unsigned_t  bits    =   static_cast<unsigned_t>(t);
        size_t      n       =   0;

        for(; 0 != bits; bits >>= 1, ++n)
        {}

        return n;
    }

    static size_t bits_in_RAND_MAX()
    {
        static size_t n = bits_in_(static_cast<unsigned>(RAND_MAX));

        return n;
    }

#if 0
	static ss_uint32_t get_low_mask_32_(size_t i)
	{
		static ss_uint32_t s_masks[] =
		{
			0x00000001,
			0x00000003,
			0x00000007,
			0x0000000f,
			0x0000001f,
			0x0000003f,
			0x0000007f,
			0x000000ff,	
			0x000001ff,
			0x000003ff,
			0x000007ff,
			0x00000fff,	
			0x00001fff,
			0x00003fff,
			0x00007fff,
			0x0000ffff,	
			0x0001ffff,
			0x0003ffff,
			0x0007ffff,
			0x000fffff,	
			0x001fffff,
			0x003fffff,
			0x007fffff,
			0x00ffffff,	
			0x01ffffff,
			0x03ffffff,
			0x07ffffff,
			0x0fffffff,	
			0x1fffffff,
			0x3fffffff,
			0x7fffffff,
			0xffffffff,	
			0x00000000
		};

		STLSOFT_ASSERT(i < 32);

		return s_masks[i];
	}
#endif
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** Generates random values over the full range of the given integral
 *   type
 *
 * \note Implemented in terms of the C standard <code>rand()</code> function
 *
 * \pre T is an integral type
 */
template <typename T>
inline T rand()
{
    STLSOFT_STATIC_ASSERT(is_integral_type<T>::value);

    const size_t numBitsInT         =   8u * sizeof(T);
    const size_t numBitsInRandMax   =   x_stlsoft_util_rand_impl::bits_in_RAND_MAX();
    const size_t N                  =   1u + (numBitsInT / numBitsInRandMax);

    T result = static_cast<T>(::rand());

    if(N > 1)
    {
        { for(unsigned i = 1; i < N - 1; ++i)
        {
            result *= static_cast<T>(::rand());
        }}

        T resultN = static_cast<T>(::rand());

        if(numBitsInT != numBitsInRandMax)
        {
            result *= static_cast<T>((resultN * numBitsInRandMax) / numBitsInT);
        }
        else
        {
            result *= resultN;
        }
    }

    return result;
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

#endif /* STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_RAND */

/* ///////////////////////////// end of file //////////////////////////// */
