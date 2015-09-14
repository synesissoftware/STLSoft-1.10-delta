/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/view/transforming/random_access_transforming_view_base.hpp
 *
 * Purpose:     Contains the random_access_transforming_view_base class template.
 *
 * Created:     4th January 2010
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


/** \file stlsoft/view/transforming/random_access_transforming_view_base.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::random_access_transforming_view_base
 *   class template
 *   (\ref group__library__view "View" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_VIEW_TRANSFORMING_HPP_RANDOM_ACCESS_TRANSFORMING_VIEW_BASE
#define STLSOFT_INCL_STLSOFT_VIEW_TRANSFORMING_HPP_RANDOM_ACCESS_TRANSFORMING_VIEW_BASE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_VIEW_TRANSFORMING_HPP_RANDOM_ACCESS_TRANSFORMING_VIEW_BASE_MAJOR       1
# define STLSOFT_VER_STLSOFT_VIEW_TRANSFORMING_HPP_RANDOM_ACCESS_TRANSFORMING_VIEW_BASE_MINOR       0
# define STLSOFT_VER_STLSOFT_VIEW_TRANSFORMING_HPP_RANDOM_ACCESS_TRANSFORMING_VIEW_BASE_REVISION    5
# define STLSOFT_VER_STLSOFT_VIEW_TRANSFORMING_HPP_RANDOM_ACCESS_TRANSFORMING_VIEW_BASE_EDIT        7
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

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1200
# error stlsoft/view/transforming/random_access_transforming_view_base.hpp is not compatible versions of Visual C++ prior to 6.0 (with SP6)
#endif /* compiler */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

#ifndef STLSOFT_INCL_STDEXCEPT
# define STLSOFT_INCL_STDEXCEPT
# include <stdexcept>                            // for std::out_of_range
#endif /* !STLSOFT_INCL_STDEXCEPT */

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

/** \brief Efficient vector class for use with POD types only
 *
 * \ingroup group__library__container
 */

template<   ss_typename_param_k D
        ,   ss_typename_param_k V
        ,   ss_typename_param_k RI
        >
class random_access_transforming_view_base
{
public: // Member Types
    typedef D                                               derived_type;
    typedef V                                               value_type;
    typedef RI                                              source_iterator_type;
    typedef random_access_transforming_view_base<D, V, RI>  class_type;
    typedef class_type                                      sequence_type;
    typedef value_type                                      sequence_value_type;
    class                                                   const_iterator;
    typedef ss_size_t                                       size_type;
    typedef ss_ptrdiff_t                                    difference_type;
    typedef bool                                            bool_type;

    class const_iterator
        : public stlsoft_ns_qual(iterator_base)<
            stlsoft_ns_qual_std(random_access_iterator_tag)
        ,   value_type
        ,   ptrdiff_t
        ,   void        // By-Value Temporary reference
        ,   value_type  // By-Value Temporary reference
        >
    {
    private:
        typedef const_iterator                  class_type;
    public:
        typedef sequence_value_type             value_type;

    public:
        const_iterator(source_iterator_type iterator)
            : m_iterator(iterator)
        {}
        const_iterator()
            : m_iterator(NULL)
        {}
        const_iterator(class_type const& rhs)
            : m_iterator(rhs.m_iterator)
        {}

        class_type& operator =(class_type const& rhs)
        {
            m_iterator = rhs.m_iterator;

            return *this;
        }

    public:
        /// Dereference operator
        value_type operator *() const
        {
            return sequence_type::create_value(m_iterator);
        }

        bool operator ==(class_type const& rhs) const
        {
            return m_iterator == rhs.m_iterator;
        }

        bool operator !=(class_type const& rhs) const
        {
            return m_iterator != rhs.m_iterator;
        }

        /// Pre-increment operator
        class_type& operator ++()
        {
            ++m_iterator;

            return *this;
        }

        /// Post-increment operator
        class_type operator ++(int)
        {
            class_type  ret(*this);

            operator ++();

            return ret;
        }

        /// Pre-decrement operator
        class_type& operator --()
        {
            --m_iterator;

            return *this;
        }

        /// Post-decrement operator
        class_type operator --(int)
        {
            class_type  ret(*this);

            operator --();

            return ret;
        }

        // Random access operations

        /// Offset
        class_type& operator +=(difference_type index)
        {
            m_iterator += index;

            return *this;
        }

        /// Offset
        class_type& operator -=(difference_type index)
        {
            m_iterator -= index;

            return *this;
        }

        /// Subscript operator
        value_type operator [](difference_type index) const
        {
            return sequence_type::create_value(m_iterator + index);
        }

        /// Calculate the distance between \c this and \c rhs
        difference_type distance(class_type const& rhs) const
        {
            return m_iterator - rhs.m_iterator;
        }

        /// Pointer subtraction
        class_type operator -(difference_type n) const
        {
            return class_type(*this) -= n;
        }

        /// Pointer addition
        class_type operator +(difference_type n) const
        {
            return class_type(*this) += n;
        }

        /// Pointer difference
        difference_type operator -(class_type const& rhs) const
        {
            return distance(rhs);
        }

    // Members
    private:
        source_iterator_type    m_iterator;
    };

public: // Construction
    random_access_transforming_view_base(source_iterator_type from, source_iterator_type to)
        : m_from(from)
        , m_to(to)
    {}
    random_access_transforming_view_base(class_type const& rhs)
        : m_from(rhs.m_from)
        , m_to(rhs.m_to)
    {}
private:
    class_type& operator =(class_type const&);

public: // Iteration
    const_iterator  begin() const
    {
        return const_iterator(m_from);
    }
    const_iterator  end() const
    {
        return const_iterator(m_to);
    }

public: // Size
    size_type size() const
    {
        return m_to - m_from;
    }

    bool_type empty() const
    {
        return 0u == size();
    }

    /// Subscript operator
    value_type operator [](difference_type index) const
    {
        STLSOFT_ASSERT(index < difference_type(size()));

        return sequence_type::create_value(m_from + index);
    }

public: // Utility
    static value_type create_value(source_iterator_type iterator)
    {
        return derived_type::create_value(*iterator);
    }

private:
    source_iterator_type const  m_from;
    source_iterator_type const  m_to;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_VIEW_TRANSFORMING_HPP_RANDOM_ACCESS_TRANSFORMING_VIEW_BASE */

/* ///////////////////////////// end of file //////////////////////////// */
