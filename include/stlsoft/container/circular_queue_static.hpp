/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/container/circular_queue_static.hpp
 *
 * Purpose:     Definition of the circular_queue_static class template.
 *
 * Created:     23rd May 2014
 * Updated:     13th September 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014-2015, Matthew Wilson and Synesis Software
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


/** \file stlsoft/container/circular_queue_static.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::circular_queue_static container class
 *   (\ref group__library__containers "Containers" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CIRCULAR_QUEUE_STATIC
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CIRCULAR_QUEUE_STATIC

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_CIRCULAR_QUEUE_STATIC_MAJOR     1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_CIRCULAR_QUEUE_STATIC_MINOR     0
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_CIRCULAR_QUEUE_STATIC_REVISION  4
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_CIRCULAR_QUEUE_STATIC_EDIT      5
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
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE
# include <stlsoft/meta/is_fundamental_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_POINTER_TYPE
# include <stlsoft/meta/is_pointer_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_POINTER_TYPE */

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
class circular_queue_static_parent
{
protected:
    struct fake_type;

protected:
    static
    fake_type const*
    make_fake_type(
        void const* p
    )
    {
        return static_cast<fake_type const*>(p);
    }
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

template<
    ss_size_t           N
,   ss_typename_param_k V
>
class circular_queue_static
    : protected circular_queue_static_parent
{
public: // Member Constants
    enum { NumElements      =   N                           };
    enum { ValueTypeSize    =   static_cast<int>(sizeof(V)) };

public: // Member Types
    typedef circular_queue_static<N, V>             class_type;
    typedef circular_queue_static<N, V>             queue_class_type;
    typedef V                                       value_type;
    typedef bool                                    bool_type;
    typedef ss_ptrdiff_t                            difference_type;
    typedef size_t                                  size_type;
    typedef void (*overwrite_function_type)(
        void*               ctxt
    ,   class_type const&   q
    ,   value_type const&   newValue
    );
    typedef value_type const*                       const_pointer;
    typedef value_type const&                       const_reference;
    class                                           const_iterator;
private:
    union element_type
    {
        long double dummy_;
        ss_byte_t   value[sizeof(value_type)];

    public:
        value_type&         get_()
        {
            return *static_cast<value_type*>(static_cast<void*>(&value[0]));
        }
        value_type const&   get_() const
        {
            return *static_cast<value_type const*>(static_cast<void const*>(&value[0]));
        }
    };
public:
    class const_iterator
        : public iterator_base<
                stlsoft_ns_qual_std(random_access_iterator_tag)
            ,   value_type
            ,   ss_ptrdiff_t
            ,   const_pointer
            ,   const_reference
            >
    {
    public:
        typedef const_iterator                                  class_type;
        typedef ss_size_t                                       size_type;

    private:
        friend class circular_queue_static_parent;
    public: // Construction
        const_iterator(
            circular_queue_static_parent::fake_type const*  pq
        ,   size_type                                       index
        )
            : m_queue(static_cast<queue_class_type const*>(static_cast<void const*>(pq)))
            , m_index(index)
        {}

    public:
        const_reference operator *() const
        {
            STLSOFT_ASSERT(NULL != m_queue);
            STLSOFT_ASSERT(m_queue->size() != m_index);

            return (*m_queue)[m_index];
        }

    public:

        class_type& operator ++()
        {
            STLSOFT_ASSERT(NULL != m_queue);
            STLSOFT_ASSERT(m_queue->size() != m_index);

            ++m_index;

            return *this;
        }

        class_type operator ++(int)
        {
            class_type  ret(*this);

            operator ++();

            return ret;
        }

    public:

        class_type& operator --()
        {
            STLSOFT_ASSERT(NULL != m_queue);
            STLSOFT_ASSERT(0 != m_index);

            --m_index;

            return *this;
        }

        class_type operator --(int)
        {
            class_type  ret(*this);

            operator --();

            return ret;
        }

    public:

        class_type& operator +=(difference_type index)
        {
            STLSOFT_ASSERT(NULL != m_queue);
            STLSOFT_ASSERT(m_index + index <= m_queue->size());

            m_index += index;

            return *this;
        }

        class_type operator +(difference_type index) const
        {
            class_type r(*this);

            r += index;

            return r;
        }

        class_type& operator -=(difference_type index)
        {
            STLSOFT_ASSERT(NULL != m_queue);
            STLSOFT_ASSERT(m_index - index >= 0);

            m_index -= index;

            return *this;
        }

        class_type operator -(difference_type index) const
        {
            class_type r(*this);

            r -= index;

            return r;
        }

        difference_type operator -(class_type const& rhs) const
        {
            STLSOFT_ASSERT(NULL == m_queue || NULL == rhs.m_queue || m_queue == rhs.m_queue);

            return difference_type(m_index) - difference_type(rhs.m_index);
        }

        value_type operator [](difference_type index) const
        {
            STLSOFT_ASSERT(NULL != m_queue);
            STLSOFT_ASSERT((difference_type(m_index) + index) < difference_type(m_queue->size()));

            return (*m_queue)[m_index + index];
        }


    public: // Comparison
        bool_type operator ==(class_type const& rhs) const
        {
            STLSOFT_ASSERT(NULL == m_queue || NULL == rhs.m_queue || m_queue == rhs.m_queue);

            return m_index == rhs.m_index;
        }
        bool_type operator !=(class_type const& rhs) const
        {
            STLSOFT_ASSERT(NULL == m_queue || NULL == rhs.m_queue || m_queue == rhs.m_queue);

            return m_index != rhs.m_index;
        }

        bool_type operator <(class_type const& rhs) const
        {
            STLSOFT_ASSERT(NULL == m_queue || NULL == rhs.m_queue || m_queue == rhs.m_queue);

            return m_index < rhs.m_index;
        }
        bool_type operator >(class_type const& rhs) const
        {
            STLSOFT_ASSERT(NULL == m_queue || NULL == rhs.m_queue || m_queue == rhs.m_queue);

            return m_index > rhs.m_index;
        }

        bool_type operator <=(class_type const& rhs) const
        {
            STLSOFT_ASSERT(NULL == m_queue || NULL == rhs.m_queue || m_queue == rhs.m_queue);

            return m_index <= rhs.m_index;
        }
        bool_type operator >=(class_type const& rhs) const
        {
            STLSOFT_ASSERT(NULL == m_queue || NULL == rhs.m_queue || m_queue == rhs.m_queue);

            return m_index >= rhs.m_index;
        }

    private: // Fields
        queue_class_type const* m_queue;
        size_type               m_index;
    };

private: // Implementation
    static
    void overwrite_stub_function(
        void*               /* ctxt */
    ,   class_type const&   /* q */
    ,   value_type const&   /* newValue */
    )
    {}

public: // Construction
    circular_queue_static();
    ///
    /// \pre (NULL != pfn)
    circular_queue_static(
        overwrite_function_type pfn
    ,   void*                   ctxt
    );
    circular_queue_static(
        class_type const& rhs
    );
    ~circular_queue_static() stlsoft_throw_0();
    ///
    /// \note Copy assignment is only available for specialisations of
    ///   fundamental or pointer types
    class_type& operator =(
        class_type const& rhs
    );

public: // Modifiers
    void pop_front() stlsoft_throw_0();
    ///
    ///
    /// \note This operation provides strong exception guarantee only when
    ///   the condition <code>(size() < max_size())</code> is true;
    ///   otherwise it provides only the weak exception guarantee
    void push_back(value_type const& value);

public: // Attributes
    bool_type empty() const stlsoft_throw_0();
    size_type size() const stlsoft_throw_0();
    static
    size_type max_size() stlsoft_throw_0();

public: // Accessors
    value_type const&   operator [](size_type index) const stlsoft_throw_0();

    value_type const&   front() const  stlsoft_throw_0();
    value_type const&   back() const  stlsoft_throw_0();

public: // Iteration
    const_iterator      begin() const;
    const_iterator      end() const;

private: // Implementation
    template <ss_typename_type_k E2>
    static
    void
    destroy_element_(
        E2* element
    )
    {
        element->~V();
    }

private: // Fields
    element_type            m_rawElements[N];
    size_type               m_count;
    size_type               m_index0;
    overwrite_function_type m_pfn;
    void*                   m_ctxt;
};

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION



// Construction

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
circular_queue_static<N, V>::circular_queue_static()
    : m_count(0)
    , m_index0(0)
    , m_pfn(&class_type::overwrite_stub_function)
    , m_ctxt(NULL)
{
    STLSOFT_ASSERT(static_cast<overwrite_function_type>(0) != m_pfn);
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
circular_queue_static<N, V>::circular_queue_static(
    ss_typename_type_k circular_queue_static<N, V>::overwrite_function_type pfn
,   void*                                                                   ctxt
)
    : m_count(0)
    , m_index0(0)
    , m_pfn(pfn)
    , m_ctxt(ctxt)
{
    STLSOFT_ASSERT(static_cast<overwrite_function_type>(0) != m_pfn);
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
circular_queue_static<N, V>::circular_queue_static(
    ss_typename_type_k circular_queue_static<N, V>::class_type const& rhs
)
    : m_count(0)
    , m_index0(0)
    , m_pfn(rhs.m_pfn)
    , m_ctxt(rhs.m_ctxt)
{
    STLSOFT_ASSERT(static_cast<overwrite_function_type>(0) != m_pfn);

    { for(size_t i = 0; rhs.m_count != i; ++i)
    {
        push_back(rhs[i]);
    }}
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
circular_queue_static<N, V>::~circular_queue_static() stlsoft_throw_0()
{
    STLSOFT_STATIC_ASSERT(0 != NumElements);

    { for(size_type i = 0; m_count != i; ++i)
    {
        size_type const index = (i + m_index0) % N;

        STLSOFT_ASSERT(index < N);

        value_type* const element = &m_rawElements[index].get_();

        destroy_element_(element);
    }}
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
ss_typename_type_k circular_queue_static<N, V>::class_type&
circular_queue_static<N, V>::operator =(
    ss_typename_type_k circular_queue_static<N, V>::class_type const& rhs
)
{
    STLSOFT_STATIC_ASSERT((is_fundamental_type<V>::value || is_pointer_type<V>::value));

    m_count = 0;
    m_index0 = 0;

    { for(size_t i = 0; rhs.m_count != i; ++i)
    {
        push_back(rhs[i]);
    }}

    return *this;
}



// Modifiers

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
void
circular_queue_static<N, V>::pop_front() stlsoft_throw_0()
{
    STLSOFT_ASSERT(!empty());

    size_type const index = m_index0;

    STLSOFT_ASSERT(index < N);

    value_type* const element = &m_rawElements[index].get_();

    element->~V();

    if(N == ++m_index0)
    {
        m_index0 = 0;
    }
    --m_count;
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
void
circular_queue_static<N, V>::push_back(
    ss_typename_type_k circular_queue_static<N, V>::value_type const& value
)
{
    STLSOFT_ASSERT(m_index0 < N);
    STLSOFT_ASSERT(m_count <= N);

    size_type const index = (m_count + m_index0) % N;

    STLSOFT_ASSERT(index < N);

    if(m_count < N)
    {
        ++m_count;
    }
    else
    {
        value_type* const element = &m_rawElements[index].get_();

        (*m_pfn)(m_ctxt, *this, *element);

        element->~V();

        if(N == ++m_index0)
        {
            m_index0 = 0;
        }
    }

    new(&m_rawElements[index].value[0]) value_type(value);

    STLSOFT_ASSERT(m_index0 < N);
    STLSOFT_ASSERT(m_count <= N);
}



// Attributes

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
ss_typename_type_k circular_queue_static<N, V>::bool_type
circular_queue_static<N, V>::empty() const stlsoft_throw_0()
{
    return 0u == size();
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
ss_typename_type_k circular_queue_static<N, V>::size_type
circular_queue_static<N, V>::size() const stlsoft_throw_0()
{
    return m_count;
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
/* static */
ss_typename_type_k circular_queue_static<N, V>::size_type
circular_queue_static<N, V>::max_size() stlsoft_throw_0()
{
    return NumElements;
}



// Accessors

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
ss_typename_type_k circular_queue_static<N, V>::value_type const&
circular_queue_static<N, V>::operator [](
    ss_typename_type_k circular_queue_static<N, V>::size_type index
) const stlsoft_throw_0()
{
    STLSOFT_ASSERT(index <= size());

    size_type const index_ = (index + m_index0) % NumElements;

    return m_rawElements[index_].get_();
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
ss_typename_type_k circular_queue_static<N, V>::value_type const&
circular_queue_static<N, V>::front() const  stlsoft_throw_0()
{
    STLSOFT_ASSERT(!empty());

    return m_rawElements[m_index0].get_();
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
ss_typename_type_k circular_queue_static<N, V>::value_type const&
circular_queue_static<N, V>::back() const  stlsoft_throw_0()
{
    STLSOFT_ASSERT(!empty());

    size_type const index_ = ((m_count - 1) + m_index0) % NumElements;

    return m_rawElements[index_].get_();
}



// Iteration

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
ss_typename_type_k circular_queue_static<N, V>::const_iterator
circular_queue_static<N, V>::begin() const
{
    return const_iterator(circular_queue_static_parent::make_fake_type(this), 0);
}

template<
    ss_size_t           N
,   ss_typename_param_k V
>
inline
ss_typename_type_k circular_queue_static<N, V>::const_iterator
circular_queue_static<N, V>::end() const
{
    return const_iterator(circular_queue_static_parent::make_fake_type(this), m_count);
}


#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CIRCULAR_QUEUE_STATIC */

/* ///////////////////////////// end of file //////////////////////////// */
