/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/string_lookup.hpp
 *
 * Purpose:     String lookup functions.
 *
 * Created:     8th September 2014
 * Updated:     8th September 2014
 *
 * Thanks:      To Pablo Aguilar for inspiration for these functions, and
 *              collaboration on their implementation.
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


/** \file stlsoft/string/string_lookup.hpp
 *
 * \brief [C++ only] String lookup functions
 *   (\ref group__library__string "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_LOOKUP_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_LOOKUP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_LOOKUP_FUNCTIONS_MAJOR     1
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_LOOKUP_FUNCTIONS_MINOR     0
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_LOOKUP_FUNCTIONS_REVISION  1
# define STLSOFT_VER_INCL_STLSOFT_STRING_HPP_LOOKUP_FUNCTIONS_EDIT      1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helpers
 */

namespace ximpl_string_lookup_
{

    template<
        ss_typename_param_k C
    ,   ss_typename_param_k L
    >
    inline
    bool
    string_lookup_from_slice_(
        L const*    input
    ,   L const**   output
    ,   ss_size_t   numMappings
    ,   L const*    fromMappings
    ,   L const*    toMappings
    )
    {
        STLSOFT_ASSERT(NULL != output);
        STLSOFT_ASSERT(0 == numMappings || (NULL != fromMappings && NULL != toMappings));

        *output = NULL;

        if(0 == numMappings)
        {
            return false;
        }

        if(0 == input->len)
        {
            return false;
        }

        { for(ss_size_t i = 0; i != numMappings; ++i)
        {
            L const& from = fromMappings[i];

            if( input->len == from.len &&
                0 == ::memcmp(input->ptr, from.ptr, sizeof(C) * input->len))
            {
                *output = toMappings + i;

                return true;
            }
        }}

        return false;
    }

    template<
        ss_typename_param_k C
    ,   ss_typename_param_k L
    >
    inline
    bool
    string_lookup_from_ptr_and_len_(
        C const*    input
    ,   ss_size_t   cchInput
    ,   L const**   output
    ,   ss_size_t   numMappings
    ,   L const*    fromMappings
    ,   L const*    toMappings
    )
    {
        L l;

        l.ptr   =   input;
        l.len   =   cchInput;

        return string_lookup_from_slice_<C>(&l, output, numMappings, fromMappings, toMappings);
    }

    template<
        ss_typename_param_k C
    >
    inline
    bool
    compare_(
        C const*    p1
    ,   ss_size_t   n1
    ,   C const*    p2
    ,   ss_size_t   n2
    )
    {
        if(n1 != n2)
        {
            return false;
        }

        return 0 == ::memcmp(p1, p2, sizeof(C) * n1);
    }

    template<
        ss_typename_param_k S1
    ,   ss_typename_param_k S2
    >
    inline
    bool
    compare_(
        S1 const&   s1
    ,   S2 const&   s2
    )
    {
        return compare_(c_str_data(s1), c_str_len(s1), c_str_data(s2), c_str_len(s2));
    }

    template<
        ss_typename_param_k S1
    ,   ss_typename_param_k V
    ,   ss_typename_param_k S2
    >
    inline
    bool
    compare_and_assign_(
        S1 const&   input
    ,   V const&    v
    ,   S2&         output
    )
    {
        if(compare_(c_str_data(input), c_str_len(input), c_str_data(v.first), c_str_len(v.first)))
        {
            S2(c_str_data(v.second), c_str_len(v.second)).swap(output);

            return true;
        }

        return false;
    }

    template<
        ss_typename_param_k S1
    ,   ss_typename_param_k S2
    ,   ss_typename_param_k I
    >
    inline
    bool
    string_lookup_string_instance_map_iterators_(
        S1 const&   input
    ,   S2&         output
    ,   I           from
    ,   I const     to
    )
    {
        for(; from != to; ++from)
        {
            if(compare_and_assign_(input, *from, output))
            {
                return true;
            }
        }

        S2().swap(output);

        return false;
    }

} /* namespace ximpl_string_lookup_ */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */


/**
 *
 * \pre NULL != output
 * \pre 0 == numMappings || (NULL != fromMappings && NULL != toMappings)
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k L
>
inline
bool
string_lookup(
    C const*    input
,   L const**   output
,   ss_size_t   numMappings
,   L const*    fromMappings
,   L const*    toMappings
)
{
    STLSOFT_ASSERT(NULL != output);
    STLSOFT_ASSERT(0 == numMappings || (NULL != fromMappings && NULL != toMappings));

    return ximpl_string_lookup_::string_lookup_from_ptr_and_len_(c_str_data(input), c_str_len(input), output, numMappings, fromMappings, toMappings);
}

/**
 *
 */
template<
    ss_typename_param_k S1
,   ss_typename_param_k S2
,   ss_typename_param_k M
>
inline
bool
string_lookup(
    S1 const&   input
,   S2&         output
,   M const&    mappings
)
{
    return ximpl_string_lookup_::string_lookup_string_instance_map_iterators_(input, output, mappings.begin(), mappings.end());
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_LOOKUP_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
