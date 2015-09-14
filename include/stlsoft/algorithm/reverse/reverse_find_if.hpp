/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/algorithm/reverse/reverse_find_if.hpp
 *
 * Purpose:     reverse_find_if algorithm.
 *
 * Created:     30th March 2007
 * Updated:     31st May 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2007-2010, Matthew Wilson and Synesis Software
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
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


/** \file stlsoft/algorithm/reverse/reverse_find_if.hpp
 *
 * \brief [C++ only] Definition of stlsoft::reverse_find_if() algorithm.
 *   (\ref group__library__algorithms "Algorithms" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ALGORITHM_REVERSE_HPP_REVERSE_FIND_IF
#define STLSOFT_INCL_STLSOFT_ALGORITHM_REVERSE_HPP_REVERSE_FIND_IF

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ALGORITHM_REVERSE_HPP_REVERSE_FIND_IF_MAJOR    2
# define STLSOFT_VER_STLSOFT_ALGORITHM_REVERSE_HPP_REVERSE_FIND_IF_MINOR    0
# define STLSOFT_VER_STLSOFT_ALGORITHM_REVERSE_HPP_REVERSE_FIND_IF_REVISION 2
# define STLSOFT_VER_STLSOFT_ALGORITHM_REVERSE_HPP_REVERSE_FIND_IF_EDIT     3
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
 * Algorithms
 */

/** Finds the last matching element in a range for which the given predicate
 *   holds true.
 *
 * The algorithm operates, in reverse, on the range <code>[from, to)</code>,
 * and returns the first (i.e. lastmost) element in the range for which
 * <code>pred(*i)</code>.
 *
 * \param from The first element in the range.
 * \param to The end-point element in the range. This position is not
 *   dereferenced.
 * \param pred A predicate to which the range elements will be applied.
 *
 * \returns The iterator whose element matches the predicate,
 *   or <code>to</code> if no match is found.
 */
template<   ss_typename_param_k RI
        ,   ss_typename_param_k PR
        >
inline RI reverse_find_if(
    RI  from
,   RI  to
,   PR  pred
)
{
    if(from != to)
    {
        RI  it(to);

        do
        {
            --it;

            if(pred(*it))
            {
                return it;
            }

        } while(it != from);
    }

    return to;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHM_REVERSE_HPP_REVERSE_FIND_IF */

/* ////////////////////////////////////////////////////////////////////// */
