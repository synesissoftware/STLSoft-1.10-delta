/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/algorithm/literal_copy.hpp
 *
 * Purpose:     Definition of the stlsoft::literal_copy() function suite.
 *
 * Created:     17th March 2010
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


/** \file stlsoft/algorithm/literal_copy.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::literal_copy() function
 *   suite
 *   (\ref group__library__algorithms "Algorithms" Library).
 */


#ifndef STLSOFT_INCL_STLSOFT_ALGORITHM_HPP_LITERAL_COPY
#define STLSOFT_INCL_STLSOFT_ALGORITHM_HPP_LITERAL_COPY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ALGORITHM_HPP_LITERAL_COPY_MAJOR       1
# define STLSOFT_VER_STLSOFT_ALGORITHM_HPP_LITERAL_COPY_MINOR       0
# define STLSOFT_VER_STLSOFT_ALGORITHM_HPP_LITERAL_COPY_REVISION    2
# define STLSOFT_VER_STLSOFT_ALGORITHM_HPP_LITERAL_COPY_EDIT        3
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

namespace stlsoft
{

/* /////////////////////////////////////////////////////////////////////////
 * Algorithms
 */

/** Copies 1 item to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   O           o
)
{
    *o++ = arg0;

    return o;
}

/** Copies 2 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   O           o
)
{
    return literal_copy(arg1, literal_copy(arg0, o));
}

/** Copies 3 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param arg2 The 3rd item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   A const&    arg2
,   O           o
)
{
    return literal_copy(arg2, literal_copy(arg0, arg1, o));
}

/** Copies 4 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param arg2 The 3rd item to be copied to the iterator
 * \param arg3 The 4th item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   A const&    arg2
,   A const&    arg3
,   O           o
)
{
    return literal_copy(arg3, literal_copy(arg0, arg1, arg2, o));
}

/** Copies 5 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param arg2 The 3rd item to be copied to the iterator
 * \param arg3 The 4th item to be copied to the iterator
 * \param arg4 The 5th item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   A const&    arg2
,   A const&    arg3
,   A const&    arg4
,   O           o
)
{
    return literal_copy(arg4, literal_copy(arg0, arg1, arg2, arg3, o));
}

/** Copies 6 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param arg2 The 3rd item to be copied to the iterator
 * \param arg3 The 4th item to be copied to the iterator
 * \param arg4 The 5th item to be copied to the iterator
 * \param arg5 The 6th item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   A const&    arg2
,   A const&    arg3
,   A const&    arg4
,   A const&    arg5
,   O           o
)
{
    return literal_copy(arg5, literal_copy(arg0, arg1, arg2, arg3, arg4, o));
}

/** Copies 7 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param arg2 The 3rd item to be copied to the iterator
 * \param arg3 The 4th item to be copied to the iterator
 * \param arg4 The 5th item to be copied to the iterator
 * \param arg5 The 6th item to be copied to the iterator
 * \param arg6 The 7th item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   A const&    arg2
,   A const&    arg3
,   A const&    arg4
,   A const&    arg5
,   A const&    arg6
,   O           o
)
{
    return literal_copy(arg6, literal_copy(arg0, arg1, arg2, arg3, arg4, arg5, o));
}

/** Copies 8 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param arg2 The 3rd item to be copied to the iterator
 * \param arg3 The 4th item to be copied to the iterator
 * \param arg4 The 5th item to be copied to the iterator
 * \param arg5 The 6th item to be copied to the iterator
 * \param arg6 The 7th item to be copied to the iterator
 * \param arg7 The 8th item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   A const&    arg2
,   A const&    arg3
,   A const&    arg4
,   A const&    arg5
,   A const&    arg6
,   A const&    arg7
,   O           o
)
{
    return literal_copy(arg7, literal_copy(arg0, arg1, arg2, arg3, arg4, arg5, arg6, o));
}

/** Copies 9 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param arg2 The 3rd item to be copied to the iterator
 * \param arg3 The 4th item to be copied to the iterator
 * \param arg4 The 5th item to be copied to the iterator
 * \param arg5 The 6th item to be copied to the iterator
 * \param arg6 The 7th item to be copied to the iterator
 * \param arg7 The 8th item to be copied to the iterator
 * \param arg8 The 9th item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   A const&    arg2
,   A const&    arg3
,   A const&    arg4
,   A const&    arg5
,   A const&    arg6
,   A const&    arg7
,   A const&    arg8
,   O           o
)
{
    return literal_copy(arg8, literal_copy(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, o));
}

/** Copies 10 items to the given output iterator in turn
 *
 * \param arg0 The 1st item to be copied to the iterator
 * \param arg1 The 2nd item to be copied to the iterator
 * \param arg2 The 3rd item to be copied to the iterator
 * \param arg3 The 4th item to be copied to the iterator
 * \param arg4 The 5th item to be copied to the iterator
 * \param arg5 The 6th item to be copied to the iterator
 * \param arg6 The 7th item to be copied to the iterator
 * \param arg7 The 8th item to be copied to the iterator
 * \param arg8 The 9th item to be copied to the iterator
 * \param arg9 The 10th item to be copied to the iterator
 * \param o The output iterator to which the other arguments are written
 * 
 * \return <code>o</code>
 */
template<   ss_typename_param_k A
        ,   ss_typename_param_k O
        >
inline O literal_copy(
    A const&    arg0
,   A const&    arg1
,   A const&    arg2
,   A const&    arg3
,   A const&    arg4
,   A const&    arg5
,   A const&    arg6
,   A const&    arg7
,   A const&    arg8
,   A const&    arg9
,   O           o
)
{
    return literal_copy(arg9, literal_copy(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, o));
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ALGORITHM_HPP_LITERAL_COPY */

/* ///////////////////////////// end of file //////////////////////////// */
