/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterator/filter_iterator.hpp
 *
 * Purpose:     An iterator adaptor that uses a predicate to filter desired
 *              values from the iterator's underlying sequence.
 *
 * Created:     9th July 2004
 * Updated:     12th August 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2004-2010, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file stlsoft/iterator/filter_iterator.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::filter_iterator
 *   class template
 *   (\ref group__library__iterators "Iterators" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATOR_HPP_FILTER_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATOR_HPP_FILTER_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_FILTER_ITERATOR_MAJOR     5
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_FILTER_ITERATOR_MINOR     0
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_FILTER_ITERATOR_REVISION  1
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_FILTER_ITERATOR_EDIT      42
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

// Include the STLSoft 1.9 component
//
// TODO: Merge the two files into 1.10
#include <stlsoft/iterators/filter_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Creator functions
 */

/** \brief Creates an end-point filter iterator
 *
 * \ingroup group__library__iterators
 *
 * \param end The iterator marking (one past) the end of the range to filter
 * \param pr The predicate used to filter the underlying range
 *
 * \return An instance of the specialisation filter_iterator&lt;T, P&gt;
 *
 * \note This should only ever be used as a complement to filter()
 */
template<   ss_typename_param_k I
        ,   ss_typename_param_k P
        >
inline filter_iterator<I, P> filter_end(I end, P pr)
{
    return make_filter_iterator(end, end, pr);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATOR_HPP_FILTER_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */
