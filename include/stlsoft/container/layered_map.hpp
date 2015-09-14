/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/layered_map.hpp
 *
 * Purpose:     .
 *
 * Created:     29th May 2009
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006-2012, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/layered_map.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::layered_map container class
 *   (\ref group__library__containers "Containers" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_LAYERED_MAP
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_LAYERED_MAP

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_LAYERED_MAP_MAJOR       1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_LAYERED_MAP_MINOR       0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_LAYERED_MAP_REVISION    2
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_LAYERED_MAP_EDIT        7
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
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifndef STLSOFT_INCL_MAP
# define STLSOFT_INCL_MAP
# include <map>
#endif /* !STLSOFT_INCL_MAP */
#ifndef STLSOFT_INCL_UTILITY
# define STLSOFT_INCL_UTILITY
# include <utility>
#endif /* !STLSOFT_INCL_UTILITY */

namespace stlsoft
{

    template<   ss_typename_param_k K
            ,   ss_typename_param_k V
            ,   ss_typename_param_k P = std::less<K>
            ,   ss_typename_param_k A = std::allocator<V>
            >
    class layered_map
    {
    public: // Member Types
        typedef layered_map<K, V, P, A>                 class_type;
        typedef K                                       key_type;
        typedef V                                       mapped_type;
        typedef P                                       key_compare;
        typedef A                                       allocator_type;
        typedef stlsoft_ns_qual_std(pair)</* const */ K, V>   value_type;
        typedef bool                                    bool_type;
        typedef size_t                                  size_type;
    private:
        typedef stlsoft_ns_qual_std(map)<K, V>          map_type_;

    public: // Construction
        layered_map()
        {}

    public: // Modifiers
        void insert(value_type const& value)
        {
            m_map.insert(value);
        }
        void clear()
        {
            m_map.clear();
        }

    public: // Attributes
        bool_type empty() const stlsoft_throw_0()
        {
            return 0u == size();
        }
        size_type size() const stlsoft_throw_0()
        {
            return m_map.size();
        }

    private: // Member Variables
        map_type_   m_map;
    };

/* ////////////////////////////////////////////////////////////////////// */

} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_LAYERED_MAP */

/* ///////////////////////////// end of file //////////////////////////// */

