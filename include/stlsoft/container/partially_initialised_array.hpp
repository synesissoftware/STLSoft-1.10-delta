/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/container/partially_initialised_array.hpp
 *
 * Purpose:     Contains the partially_initialised_array class.
 *
 * Created:     23rd May 2010
 * Updated:     11th June 2010
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


/** \file stlsoft/container/partially_initialised_array.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::partially_initialised_array container class
 *   template
 *   (\ref group__library__container "Container" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINER_HPP_PARTIALLY_INITIALISED_ARRAY
#define STLSOFT_INCL_STLSOFT_CONTAINER_HPP_PARTIALLY_INITIALISED_ARRAY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONTAINER_HPP_PARTIALLY_INITIALISED_ARRAY_MAJOR      1
# define STLSOFT_VER_STLSOFT_CONTAINER_HPP_PARTIALLY_INITIALISED_ARRAY_MINOR      0
# define STLSOFT_VER_STLSOFT_CONTAINER_HPP_PARTIALLY_INITIALISED_ARRAY_REVISION   4
# define STLSOFT_VER_STLSOFT_CONTAINER_HPP_PARTIALLY_INITIALISED_ARRAY_EDIT       5
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
 * Classes
 */

template<   ss_typename_param_k T
        ,   ss_size_t           N
        >
struct partially_initialised_array
{
public:
    ///  The size type
    typedef size_t                              size_type;
    ///  The reference type
    typedef T&                                  reference;
    ///  The non-mutating (const) reference type
    typedef T const&                            const_reference;
    ///  The pointer type
    typedef T*                                  pointer;
    ///  The non-mutating (const) pointer type
    typedef T const*                            const_pointer;
    ///  The iterator type
    typedef pointer                             iterator;
    ///  The non-mutating (const) iterator type
    typedef const_pointer                       const_iterator;
    ///  This type
    typedef partially_initialised_array<T, N>   class_type;

public:
    partially_initialised_array(size_type n, T const& value)
    {
        STLSOFT_ASSERT(n <= STLSOFT_NUM_ELEMENTS(values));

        { for(size_t i = 0; i != n; ++i)
        {
            values[i] = value;
        }}
    }

public:
#if 0
    static size_type size()
    {
        return N;
    }
#endif /* 0 */
    size_type size() const
    {
        return N;
    }

    reference       operator [](size_type index)
    {
        STLSOFT_ASSERT(index < size());

        return values[index];
    }
    const_reference operator [](size_type index) const
    {
        STLSOFT_ASSERT(index < size());

        return values[index];
    }

public: // Iteration
    iterator            begin()
    {
        return &values[0];
    }
    iterator            end()
    {
        return begin() + N;
    }
    const_iterator      begin() const
    {
        return &values[0];
    }
    const_iterator      end() const
    {
        return &values[0];
    }

public:
    T   values[N];
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINER_HPP_PARTIALLY_INITIALISED_ARRAY */

/* ///////////////////////////// end of file //////////////////////////// */
