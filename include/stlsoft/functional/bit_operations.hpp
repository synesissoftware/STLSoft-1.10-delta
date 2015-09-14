/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/functional/bit_operations.hpp
 *
 * Purpose:     bit-wise function classes.
 *
 * Created:     19th March 2010
 * Updated:     31st May 2010
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


/** \file stlsoft/functional/bit_operations.hpp
 *
 * \brief [C++] Definition of the stlsoft::and_with, stlsoft::or_with,
 *   and stlsoft::xor_with bitwise function classes
 *   (\ref group__library__functional "Functional" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_BIT_OPERATIONS
#define STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_BIT_OPERATIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_BIT_OPERATIONS_MAJOR    1
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_BIT_OPERATIONS_MINOR    0
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_BIT_OPERATIONS_REVISION 4
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_BIT_OPERATIONS_EDIT     6
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

#include <functional>

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

template <ss_typename_param_k T>
struct and_with
    : stlsoft_ns_qual_std(binary_function)<T, T, T>
{
    T operator() (const T& lhs, const T& rhs) const
    {
        return lhs & rhs;
    }
};

template <ss_typename_param_k T>
struct or_with
    : stlsoft_ns_qual_std(binary_function)<T, T, T>
{
    T operator() (const T& lhs, const T& rhs) const
    {
        return lhs | rhs;
    }
};

template <ss_typename_param_k T>
struct xor_with
    : stlsoft_ns_qual_std(binary_function)<T, T, T>
{
    T operator() (const T& lhs, const T& rhs) const
    {
        return lhs ^ rhs;
    }
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_BIT_OPERATIONS */

/* ///////////////////////////// end of file //////////////////////////// */
