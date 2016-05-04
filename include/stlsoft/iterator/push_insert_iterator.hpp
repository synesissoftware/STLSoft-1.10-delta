/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterator/push_insert_iterator.hpp
 *
 * Purpose:     Eraser iterator for sorted sequence containers.
 *
 * Created:     6th April 2005
 * Updated:     14th February 2016
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2016, Matthew Wilson and Synesis Software
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


/** \file stlsoft/iterator/push_insert_iterator.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::push_insert_iterator
 *   class template
 *   (\ref group__library__iterators "Iterators" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR_MAJOR      2
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR_MINOR      0
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR_REVISION   3
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR_EDIT       23
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

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helpers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

template <ss_typename_param_k C>
// [[synesis:class:iterator: push_insert_iterator<C>]]
class push_insert_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name Member Types
/// @{
public:
    /// The container type
    typedef C                                               container_type;
    /// This type
    typedef push_insert_iterator<container_type>            class_type;
private:
    typedef class_type                                      insert_iterator_type_;
private:
    class deref_proxy;
    friend class deref_proxy;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k
    push_insert_iterator(
        container_type& container
    )
        : m_container(container)
    {}
private:
    class_type& operator =(class_type const&);
/// @}

/// \name Implementation
/// @{
private:
    class deref_proxy
    {
    public:
        deref_proxy(insert_iterator_type_* it)
            : m_it(it)
        {}

    public:
        template <ss_typename_param_k A>
        void operator =(A const& value)
        {
            m_it->invoke_(value);
        }

    private:
        insert_iterator_type_* const m_it;

    // Not to be implemented
    private:
        void operator =(deref_proxy const&);
    };

    template <ss_typename_param_k A>
    void invoke_(A const& value)
    {
        m_container.push(value);
    }
/// @}

/// \name Ouput Iterator Methods
/// @{
public:
    /// \brief Dereference operator
    deref_proxy operator *()
    {
        return deref_proxy(this);
    }
    /// \brief Pre-increment operator
    class_type& operator ++()
    {
        return *this;
    }
    /// \brief Post-increment operator
    class_type& operator ++(int)
    {
        return *this;
    }
/// @}

/// \name Members
/// @{
private:
    container_type& m_container;
/// @}
};

/** Creator function for push_insert_iterator
 */
template <ss_typename_param_k C>
inline push_insert_iterator<C> make_push_insert_iterator(
    C& container
)
{
    return push_insert_iterator<C>(container);
}

/** Creator function for push_insert_iterator
 */
template <ss_typename_param_k C>
inline push_insert_iterator<C> push_inserter(
    C& container
)
{
    return make_push_insert_iterator(container);
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATOR_HPP_PUSH_INSERT_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */
