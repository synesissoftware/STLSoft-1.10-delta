/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/iterator/sorted_eraser_iterator.hpp
 *
 * Purpose:     Eraser iterator for sorted sequence containers.
 *
 * Created:     28th January 2005
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


/** \file stlsoft/iterator/sorted_eraser_iterator.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::sorted_eraser_iterator
 *   class template
 *   (\ref group__library__iterators "Iterators" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_ITERATOR_HPP_SORTED_ERASE_ITERATOR
#define STLSOFT_INCL_STLSOFT_ITERATOR_HPP_SORTED_ERASE_ITERATOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_SORTED_ERASE_ITERATOR_MAJOR      1
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_SORTED_ERASE_ITERATOR_MINOR      2
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_SORTED_ERASE_ITERATOR_REVISION   3
# define STLSOFT_VER_STLSOFT_ITERATOR_HPP_SORTED_ERASE_ITERATOR_EDIT       21
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

#ifndef STLSOFT_INCL_ALGORITHM
# define STLSOFT_INCL_ALGORITHM
# include <algorithm>                // for std::binary_search
#endif /* !STLSOFT_INCL_ALGORITHM */

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
// [[synesis:class:iterator: sorted_eraser_iterator<C>]]
class sorted_eraser_iterator
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
/// \name Member Types
/// @{
public:
    /// The container type
    typedef C                                           container_type;
    /// The size type
    typedef ss_size_t                                   size_type;
    /// This type
    typedef sorted_eraser_iterator<container_type>      class_type;
private:
    typedef class_type                                  erase_iterator_type_;
private:
    class deref_proxy;
    friend class deref_proxy;
/// @}

/// \name Construction
/// @{
public:
    ss_explicit_k
    sorted_eraser_iterator(
        container_type& container
    ,   size_type*      hits
    ,   size_type*      misses
    )
        : m_container(container)
        , m_hits(*hits)
        , m_misses(*misses)
    {
        STLSOFT_ASSERT(NULL != hits);
        STLSOFT_ASSERT(NULL != misses);

        m_hits      =   0u;
        m_misses    =   0u;
    }
private:
    class_type& operator =(class_type const&);
/// @}

/// \name Implementation
/// @{
private:
    class deref_proxy
    {
    public:
        deref_proxy(erase_iterator_type_* it)
            : m_it(it)
        {}

    public:
        template <ss_typename_param_k A>
        void operator =(A const& value)
        {
            m_it->invoke_(value);
        }

    private:
        erase_iterator_type_* const m_it;

    // Not to be implemented
    private:
        void operator =(deref_proxy const&);
    };

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k A
    >
    bool try_erase_(I from, I to, A const& value)
    {
        I const i = stlsoft_ns_qual_std(lower_bound)(from, to, value);

        if(to == i)
        {
            return false;
        }
        else if(*i == value)
        {
            m_container.erase(i);

            return true;
        }

        return false;
    }

    template <ss_typename_param_k A>
    void invoke_(A const& value)
    {
        // This defered to method template so don't have to assume iterator vs const_iterator

        size_type n = 0u;

        for(; try_erase_(m_container.begin(), m_container.end(), value); ++n)
        {}

        if(0u == n)
        {
            m_misses += 1;
        }
        else
        {
            m_hits += n;
        }
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
    size_type&      m_hits;
    size_type&      m_misses;
/// @}
};

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1500

template <ss_typename_param_k C>
// [[synesis:class:iterator: sorted_eraser_iterator_0<C>]]
class sorted_eraser_iterator_0
    : public stlsoft_ns_qual(iterator_base)<stlsoft_ns_qual_std(output_iterator_tag), void, void, void, void>
{
public:
    typedef C                                           container_type;
    typedef ss_size_t                                   size_type;
    typedef sorted_eraser_iterator_0<container_type>    class_type;
private:
    typedef class_type                                  erase_iterator_type_;
private:
    class deref_proxy;
    friend class deref_proxy;

public:
    ss_explicit_k
    sorted_eraser_iterator_0(
        container_type& container
    )
        : m_container(container)
    {}
private:
    class_type& operator =(class_type const&);

private:
    class deref_proxy
    {
    public:
        deref_proxy(erase_iterator_type_* it)
            : m_it(it)
        {}

    public:
        template <ss_typename_param_k A>
        void operator =(A const& value)
        {
            m_it->invoke_(value);
        }

    private:
        erase_iterator_type_* const m_it;

    private:
        void operator =(deref_proxy const&);
    };

    template<
        ss_typename_param_k I
    ,   ss_typename_param_k A
    >
    bool try_erase_(I from, I to, A const& value)
    {
        I const i = stlsoft_ns_qual_std(lower_bound)(from, to, value);

        if(to == i)
        {
            return false;
        }
        else if(*i == value)
        {
            m_container.erase(i);

            return true;
        }

        return false;
    }

    template <ss_typename_param_k A>
    void invoke_(A const& value)
    {
        // This defered to method template so don't have to assume iterator vs const_iterator

        for(; try_erase_(m_container.begin(), m_container.end(), value); )
        {}
    }
/// @}

public:
    deref_proxy operator *()
    {
        return deref_proxy(this);
    }
    class_type& operator ++()
    {
        return *this;
    }
    class_type& operator ++(int)
    {
        return *this;
    }

private:
    container_type& m_container;
};

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Creator Functions
 */

/** Creator function for sorted_eraser_iterator
 */
template <ss_typename_param_k C>
inline sorted_eraser_iterator<C> make_sorted_eraser_iterator(
    C&          container
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1500
,   ss_size_t*  hits /* =   NULL */
,   ss_size_t*  misses  =   NULL
#else /* ? compiler */
,   ss_size_t*  hits    =   NULL
,   ss_size_t*  misses  =   NULL
#endif /* compiler */
)
{
    static ss_size_t dummy;

    if(NULL == hits)
    {
        hits = &dummy;
    }
    if(NULL == misses)
    {
        misses = &dummy;
    }

    return sorted_eraser_iterator<C>(container, hits, misses);
}

/** Creator function for sorted_eraser_iterator
 */
template <ss_typename_param_k C>
inline sorted_eraser_iterator<C> sorted_eraser(
    C&          container
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1500
,   ss_size_t*  hits /* =   NULL */
,   ss_size_t*  misses  =   NULL
#else /* ? compiler */
,   ss_size_t*  hits    =   NULL
,   ss_size_t*  misses  =   NULL
#endif /* compiler */
)
{
    static ss_size_t dummy;

    if(NULL == hits)
    {
        hits = &dummy;
    }
    if(NULL == misses)
    {
        misses = &dummy;
    }

    return sorted_eraser_iterator<C>(container, hits, misses);
}

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1500
template <ss_typename_param_k C>
inline sorted_eraser_iterator_0<C> make_sorted_eraser_iterator_0(
    C& container
)
{
    return sorted_eraser_iterator_0<C>(container);
}
template <ss_typename_param_k C>
inline sorted_eraser_iterator_0<C> sorted_eraser(
    C& container
)
{
    return sorted_eraser_iterator_0<C>(container);
}
#endif /* compiler */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_ITERATOR_HPP_SORTED_ERASE_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */
