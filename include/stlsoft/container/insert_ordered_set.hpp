/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/container/insert_ordered_set.hpp
 *
 * Purpose:     Contains the insert_ordered_set container class template.
 *
 * Created:     27th May 2010
 * Updated:     9th October 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2010-2015, Matthew Wilson and Synesis Software
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


/** \file stlsoft/container/insert_ordered_set.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::insert_ordered_set container
 *   class template
 *   (\ref group__library__container "Container" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONTAINER_HPP_INSERT_ORDERED_SET
#define STLSOFT_INCL_STLSOFT_CONTAINER_HPP_INSERT_ORDERED_SET

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONTAINER_HPP_INSERT_ORDERED_SET_MAJOR     1
# define STLSOFT_VER_STLSOFT_CONTAINER_HPP_INSERT_ORDERED_SET_MINOR     6
# define STLSOFT_VER_STLSOFT_CONTAINER_HPP_INSERT_ORDERED_SET_REVISION  2
# define STLSOFT_VER_STLSOFT_CONTAINER_HPP_INSERT_ORDERED_SET_EDIT      27
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
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */

# include <stlsoft/util/tr1/std_hash.hpp>

# include <utility>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/*
 *
 * Unordered Container requirements:
 *
 * - value_type
 * - reference
 * - const_reference
 * - iterator
 * - const_iterator
 * - difference_type
 * - size_type
 * + key_type
 * + key_equal
 * + hasher
 * + local_iterator
 * + const_local_iterator
 *
 * - class_type()
 * - class_type(class_type const& )
 * - ~class_type()
 * - class_type& operator =(class_type const& )
 *
 * - begin(), end()
 * - begin() const, end() const
 * - swap()
 *
 * - size()
 * - max_size()
 * - empty
 *
 * - 

 */

template<
    ss_typename_param_k V
,   ss_typename_param_k H = stlsoft_ns_qual(std_hash)<V>
,   ss_typename_param_k P = stlsoft_ns_qual_std(equal_to)<V>
,   ss_typename_param_k A = ss_typename_type_def_k stlsoft::allocator_selector<V>::allocator_type
>
class insert_ordered_set
{
public: // Member Types
    typedef V                               value_type;

    typedef V                               key_type;

    typedef H                               hasher;

    typedef P                               key_equal;

    typedef A                               allocator_type;

    typedef ss_size_t                       size_type;

    typedef ss_ptrdiff_t                    difference_type;

    typedef ss_bool_t                       bool_type;

    typedef insert_ordered_set<V, H, P, A>  class_type;

    typedef value_type&                     reference;

    typedef value_type const&               const_reference;

    typedef value_type*                     pointer;

    typedef value_type const*               const_pointer;

    class                                   const_iterator;

    typedef const_iterator                  iterator;

private:
    struct                                  node_type_;

public:

    class const_iterator
        : public iterator_base<
                stlsoft_ns_qual_std(bidirectional_iterator_tag)
            ,   value_type
            ,   ss_ptrdiff_t
            ,   const_pointer
            ,   const_reference
            >
    {
    public:
        typedef insert_ordered_set<V, H, P, A>      container_type;
        typedef const_iterator                      class_type;

    private:
        friend class insert_ordered_set<V, H, P, A>;

    public:
        const_iterator(class_type const& rhs)
            : m_container(rhs.m_container)
            , m_node(rhs.m_node)
            , m_tail(rhs.m_tail)
        {}
    private:
        const_iterator(container_type const* container, node_type_ const* node, node_type_ const* tail)
            : m_container(container)
            , m_node(node)
            , m_tail(tail)
        {}

    public:
        const_reference operator *() const
        {
            return m_node->value;
        }

        class_type& operator ++()
        {
            STLSOFT_ASSERT(NULL != m_node);

            m_node = m_node->outer_next;

            return *this;
        }

        class_type operator ++(int)
        {
            class_type t(*this);

            operator ++();

            return t;
        }

        class_type& operator --()
        {
            if(NULL == m_node)
            {
                // Currently the endpoint iterator
                m_node = m_tail;
            }
            else
            {
                m_node = m_node->outer_prev;
            }

            return *this;
        }

        class_type operator --(int)
        {
            class_type t(*this);

            operator --();

            return t;
        }

        bool equal(class_type const& rhs) const
        {
            STLSOFT_ASSERT(m_container == rhs.m_container);

            return m_node == rhs.m_node;
        }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# if 0 || \
     defined(STLSOFT_COMPILER_IS_BORLAND) || \
     defined(STLSOFT_COMPILER_IS_CLANG) || \
     defined(STLSOFT_COMPILER_IS_GCC) || \
     defined(STLSOFT_COMPILER_IS_MWERKS) || \
     (   defined(STLSOFT_COMPILER_IS_MSVC) && \
         _MSC_VER >= 1500) || \
     0
        bool operator ==(class_type const& rhs) const
        {
            return equal(rhs);
        }
        bool operator !=(class_type const& rhs) const
        {
            return !equal(rhs);
        }
# endif /* compiler */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    private:
        container_type const*   m_container;
        node_type_ const*       m_node;
        node_type_ const*       m_tail;
    };

public:
#if defined(STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT)
    typedef reverse_bidirectional_iterator_base<
        const_iterator
    ,   value_type
    ,   const_reference
    ,   const_pointer
    ,   difference_type
    >                                               const_reverse_iterator;
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */


private:
    typedef size_t                                  hash_type_;

    enum
    {
        OverwritesEqual = true
    };

private:
#if 0
    struct node_type_;
    struct node_type_
    {
        node_type_* prev;
        node_type_* next;
        size_t      hash;
        V           value;
    };
    struct slot_type_;
    struct slot_type_
    {
        node_type_* node;
        slot_type_* next;
    };
#else /* ? 0 */
    struct node_type_
    {
        // The place in the ordered list
        node_type_* outer_prev;
        node_type_* outer_next;
        // The place in the table linked-list
        node_type_* inner_prev;
        node_type_* inner_next;
        size_t      hash;
        V           value;

        node_type_(V const& v, size_t h)
            : outer_prev(NULL)
            , outer_next(NULL)
            , inner_prev(NULL)
            , inner_next(NULL)
            , value(v)
            , hash(h)
        {}

        void unhook_from_outer(node_type_*& head, node_type_*& tail)
        {
            STLSOFT_ASSERT(NULL != head);
            STLSOFT_ASSERT(NULL != tail);

            if(head == tail)
            {
                STLSOFT_ASSERT(this == head);
                STLSOFT_ASSERT(this == tail);

                STLSOFT_ASSERT(NULL == this->outer_prev);
                STLSOFT_ASSERT(NULL == this->outer_next);

                // Hook previous' next
                head = NULL;

                // Hook next's previous
                tail = NULL;

                // Reset this' pointers
            }
            else if(this == head)
            {
                STLSOFT_ASSERT(NULL == this->outer_prev);
                STLSOFT_ASSERT(NULL != this->outer_next);

                // Hook previous' next
                head = this->outer_next;

                // Hook next's previous
                this->outer_next->outer_prev = NULL;

                // Reset this' pointers
                this->outer_next = NULL;
            }
            else if(this == tail)
            {
                STLSOFT_ASSERT(NULL != this->outer_prev);
                STLSOFT_ASSERT(NULL == this->outer_next);

                // Hook previous' next
                this->outer_prev->outer_next = NULL;

                // Hook next's previous
                tail = this->outer_prev;

                // Reset this' pointers
                this->outer_prev = NULL;
            }
            else
            {
                STLSOFT_ASSERT(NULL != this->outer_prev);
                STLSOFT_ASSERT(NULL != this->outer_next);

                // Hook previous' next
                this->outer_prev->outer_next = this->outer_next;

                // Hook next's previous
                this->outer_next->outer_prev = this->outer_prev;

                // Reset this' pointers
                this->outer_prev = NULL;
                this->outer_next = NULL;
            }
        }

        void unhook_from_inner(node_type_*& slot)
        {
            STLSOFT_ASSERT(NULL != slot);
            STLSOFT_ASSERT(NULL == slot->inner_prev);

            if(this == slot)
            {
                STLSOFT_ASSERT(NULL == this->inner_prev);

                // 'this' is the head of the slot list
                slot = this->inner_next;
                this->inner_next = NULL;
                if(NULL != slot)
                {
                    slot->inner_prev = NULL;
                }
            }
            else
            {
                node_type_* prev    =   this->inner_prev;
                node_type_* next    =   this->inner_next;

                STLSOFT_ASSERT(NULL != prev); // Otherwise slot == this

                // Hook previous' next
                prev->inner_next = next;
                // Hook next's previous
                if(NULL != next)
                {
                    next->inner_prev = prev;
                }

                // Reset this
                this->inner_prev = NULL;
                this->inner_next = NULL;
            }

            STLSOFT_ASSERT(NULL == slot || NULL == slot->inner_prev);
        }
    };
#endif /* 0 */

    enum
    {
        // Currently going for 31, as per advice in TPOP
        defaultNumberOfIndexes = 31
    };
    enum
    {
        maxSpare = 10
    };
    typedef stlsoft::auto_buffer<
        node_type_*
    ,   defaultNumberOfIndexes
    >                                               slot_buffer_type_;

public:


public: // Construction
    insert_ordered_set()
        : m_hasher()
        , m_equal()
        , m_allocator()
        , m_slots(defaultNumberOfIndexes)
        , m_head(NULL)
        , m_tail(NULL)
        , m_spare(NULL)
        , m_count(0)
    {
        { for(size_t i = 0; i != m_slots.size(); ++i)
        {
            m_slots[i] = NULL;
        }}

        STLSOFT_ASSERT(is_valid());
    }
    template <ss_typename_param_k I>
    insert_ordered_set(I from, I to)
        : m_hasher()
        , m_equal()
        , m_allocator()
        , m_slots(defaultNumberOfIndexes)
        , m_head(NULL)
        , m_tail(NULL)
        , m_spare(NULL)
        , m_count(0)
    {
        { for(size_t i = 0; i != m_slots.size(); ++i)
        {
            m_slots[i] = NULL;
        }}

        insert(from, to);

        STLSOFT_ASSERT(is_valid());
    }
    ~insert_ordered_set() stlsoft_throw_0()
    {
        STLSOFT_ASSERT(is_valid());

        // Walk head, and erase
        { for(node_type_* n = m_head; NULL != n;)
        {
            node_type_* t = n;

            n = n->outer_next;

            delete_node_finally_(t);
        }}

        { for(node_type_* n = m_spare; NULL != n;)
        {
            node_type_* t = n;

            n = n->outer_next;

            delete_node_finally_(t);
        }}
    }

public: // Operations

    void push_front(value_type const& value)
    {
        STLSOFT_ASSERT(is_valid());

        if(0 == m_count)
        {
            insert_into_empty_(value);
        }
        else
        {
            STLSOFT_ASSERT(NULL != m_head);
            STLSOFT_ASSERT(NULL != m_tail);

            hash_type_      h       =   m_hasher(value);
            size_type const index   =   h % m_slots.size();
            node_type_*&    slot    =   m_slots[index];

            // Need to check whether it's already in the container, and
            // whether it's the head

            { for(node_type_* n2 = slot; NULL != n2; n2 = n2->inner_next)
            {
                if(m_equal(n2->value, value))
                {
                    if(OverwritesEqual)
                    {
                        n2->value = value;
                    }

                    if(n2 != m_head)
                    {
                        // Need to unhook from wherever it is ...
                        n2->unhook_from_outer(m_head, m_tail);

                        // ... and (re)hook into front

                        n2->outer_next      =   m_head;
                        m_head->outer_prev  =   n2;
                        m_head              =   n2;
                    }

                    return;
                }
            }}

            // Attach into slot list

            node_type_* node = new_node_(value, h);

            node->inner_next = slot;
            if(NULL != slot)
            {
                slot->inner_prev = node;
            }
            slot = node;

            STLSOFT_ASSERT(NULL == slot->inner_prev);

            // Attach into main list

            m_head->outer_prev  =   node;
            node->outer_next    =   m_head;
            m_head              =   node;

            ++m_count;
        }

        STLSOFT_ASSERT(is_valid());
    }

    void push_back(value_type const& value)
    {
        STLSOFT_ASSERT(is_valid());

        if(0 == m_count)
        {
            insert_into_empty_(value);
        }
        else
        {
            STLSOFT_ASSERT(NULL != m_head);
            STLSOFT_ASSERT(NULL != m_tail);

            hash_type_      h       =   m_hasher(value);
            size_type const index   =   h % m_slots.size();
            node_type_*&    slot    =   m_slots[index];

            // Need to check whether it's already in the container, and
            // whether it's the tail

            { for(node_type_* n2 = slot; NULL != n2; n2 = n2->inner_next)
            {
                if(m_equal(n2->value, value))
                {
                    if(OverwritesEqual)
                    {
                        n2->value = value;
                    }

                    if(n2 != m_tail)
                    {
                        // Need to unhook from wherever it is ...
                        n2->unhook_from_outer(m_head, m_tail);

                        // ... and (re)hook into back

                        n2->outer_prev      =   m_tail;
                        m_tail->outer_next  =   n2;
                        m_tail              =   n2;
                    }

                    return;
                }
            }}

            // Attach into slot list

            node_type_* node = new_node_(value, h);

            node->inner_next = slot;
            if(NULL != slot)
            {
                slot->inner_prev = node;
            }
            slot = node;

            STLSOFT_ASSERT(NULL == slot->inner_prev);

            // Attach into main list

            m_tail->outer_next  =   node;
            node->outer_prev    =   m_tail;
            m_tail              =   node;

            ++m_count;
        }

        STLSOFT_ASSERT(is_valid());
    }

    stlsoft_ns_qual_std(pair)<const_iterator, bool> insert(const_iterator i, value_type const& value)
    {
        STLSOFT_ASSERT(is_valid());

        if(0 == m_count)
        {
            STLSOFT_ASSERT(end() == i);

            insert_into_empty_(value);

            return stlsoft_ns_qual_std(make_pair)(begin(), true);
        }
        else
        {
            STLSOFT_ASSERT(NULL != m_head);
            STLSOFT_ASSERT(NULL != m_tail);

            hash_type_      h       =   m_hasher(value);
            size_type const index   =   h % m_slots.size();
            node_type_*&    slot    =   m_slots[index];

            // Need to check whether it's already in the container
            node_type_*     node    =   NULL;

            { for(node_type_* n2 = slot; NULL != n2; n2 = n2->inner_next)
            {
                if(m_equal(n2->value, value))
                {
                    if(OverwritesEqual)
                    {
                        n2->value = value;
                    }

                    // Need to unhook from wherever it is ...
                    n2->unhook_from_outer(m_head, m_tail);

                    node = n2;

                    break;
                }
            }}

            bool exists = (NULL != node);

            if(!exists)
            {
                // Does not already exist
                node = new_node_(value, h);

                // Attach into slot list

                node->inner_next = slot;
                if(NULL != slot)
                {
                    slot->inner_prev = node;
                }
                slot = node;

                ++m_count;
            }

            // Attach into outer list, before i

            node_type_* ni = const_cast<node_type_*>(i.m_node);

            if(NULL == ni)
            {
                // Attach at end

                node->outer_prev    =   m_tail;
                m_tail->outer_next  =   node;
                m_tail              =   node;
            }
            else if(ni == m_head)
            {
                node->outer_next    =   m_head;
                m_head->outer_prev  =   node;
                m_head              =   node;
            }
            else
            {
                // Attach between two valid nodes

                node_type_* after   =   ni;
                node_type_* before  =   ni->outer_prev;

                STLSOFT_ASSERT(before->outer_next == after);

                after->outer_prev   =   node;
                node->outer_next    =   after;

                before->outer_next  =   node;
                node->outer_prev    =   before;
            }

            return stlsoft_ns_qual_std(make_pair)(const_iterator(this, node, m_tail), exists);
        }
    }

    template <ss_typename_param_k I>
    void insert(I from, I to)
    {
        // TODO: try to make strongly exception-safe
        for(; from != to; ++from)
        {
            insert(end(), *from);
        }
    }

    size_type erase(value_type const& value) stlsoft_throw_0()
    {
        STLSOFT_ASSERT(is_valid());

        node_type_**    slot;
        node_type_*     n = find_(value, &slot);

        if(NULL == n)
        {
            STLSOFT_ASSERT(is_valid());

            return 0;
        }
        else
        {
            n->unhook_from_outer(m_head, m_tail);
            n->unhook_from_inner(*slot);

            delete_node_(n);

            --m_count;

            STLSOFT_ASSERT(is_valid());

            return 1u;
        }
    }

    const_iterator erase(const_iterator it) stlsoft_throw_0()
    {
        STLSOFT_MESSAGE_ASSERT("cannot erase endpoint iterator", end() != it);

        STLSOFT_ASSERT(is_valid());

        node_type_*     n       =   const_cast<node_type_*>(it.m_node);
        size_type const index   =   n->hash % m_slots.size();
        node_type_*&    slot    =   m_slots[index];

        ++it;

        n->unhook_from_outer(m_head, m_tail);
        n->unhook_from_inner(slot);

        delete_node_(n);

        --m_count;

        STLSOFT_ASSERT(is_valid());

        return it;
    }

    const_iterator erase(const_iterator from, const_iterator to) stlsoft_throw_0()
    {
        STLSOFT_ASSERT(is_valid());

        for(; from != to; )
        {
            node_type_*     n       =   const_cast<node_type_*>(from.m_node);
            size_type const index   =   n->hash % m_slots.size();
            node_type_*&    slot    =   m_slots[index];

            ++from;

            n->unhook_from_outer(m_head, m_tail);
            n->unhook_from_inner(slot);

            delete_node_(n);

            --m_count;
        }

        STLSOFT_ASSERT(is_valid());

        return to;
    }

    void clear()
    {
        STLSOFT_ASSERT(is_valid());

        erase(begin(), end());

        STLSOFT_ASSERT(is_valid());
    }

    void swap(class_type& rhs) stlsoft_throw_0()
    {
        STLSOFT_ASSERT(is_valid());

        stlsoft_ns_qual(std_swap)(m_count, rhs.m_count);
        stlsoft_ns_qual(std_swap)(m_head, rhs.m_head);
        stlsoft_ns_qual(std_swap)(m_tail, rhs.m_tail);
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1300
        // Silly old VC++ can't be persuaded from emitting C4101 here, so we do them manually
        {
            hasher t1 = m_hasher;
            m_hasher = rhs.m_hasher;
            rhs.m_hasher = t1;

            STLSOFT_SUPPRESS_UNUSED(t1);
        }
        {
            key_equal t2 = m_equal;
            m_equal = rhs.m_equal;
            rhs.m_equal = t2;

            STLSOFT_SUPPRESS_UNUSED(t2);
        }
        {
            allocator_type t3 = m_allocator;
            m_allocator = rhs.m_allocator;
            rhs.m_allocator = t3;

            STLSOFT_SUPPRESS_UNUSED(t3);
        }
#else /* ? compiler */
        stlsoft_ns_qual(std_swap)(m_hasher, rhs.m_hasher);
        stlsoft_ns_qual(std_swap)(m_equal, rhs.m_equal);
        stlsoft_ns_qual(std_swap)(m_allocator, rhs.m_allocator);
#endif /* compiler */
        m_slots.swap(rhs.m_slots);

        STLSOFT_ASSERT(is_valid());
    }

public: // Accessors

    const_reference front() const
    {
        STLSOFT_ASSERT(!empty());

        STLSOFT_ASSERT(is_valid());

        return m_head->value;
    }

    const_reference back() const
    {
        STLSOFT_ASSERT(!empty());

        STLSOFT_ASSERT(is_valid());

        return m_tail->value;
    }

    const_iterator find(value_type const& value) const
    {
        STLSOFT_ASSERT(is_valid());

        node_type_* n = find_(value);

        if(NULL != n)
        {
            return const_iterator(this, n, m_tail);
        }

        return end();
    }

public: // Iteration
    const_iterator  begin() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_iterator(this, m_head, m_tail);
    }

    const_iterator  end() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_iterator(this, NULL, m_tail);
    }

    const_reverse_iterator  rbegin() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_reverse_iterator(end());
    }
    const_reverse_iterator  rend() const
    {
        STLSOFT_ASSERT(is_valid());

        return const_reverse_iterator(begin());
    }

public: // Accessors
    bool_type   empty() const
    {
        STLSOFT_ASSERT(is_valid());

        return 0u == size();
    }
    size_type   size() const
    {
        STLSOFT_ASSERT(is_valid());

        return m_count;
    }

private:
    node_type_* new_node_(V const& v, size_t h)
    {
        return new node_type_(v, h);
    }
    void delete_node_(node_type_* n)
    {
        size_t c;

        if(NULL != m_spare)
        {
            c = m_spare->hash + 1u;
        }
        else
        {
            c = 1u;
        }

        if(c < maxSpare)
        {
            n->hash         =   c;
            n->outer_next   =   m_spare;
            m_spare         =   n;
        }
        else
        {
            delete_node_finally_(n);
        }
    }
    void delete_node_finally_(node_type_* n)
    {
        delete n;
    }

    void insert_into_empty_(value_type const& value)
    {
        STLSOFT_ASSERT(NULL == m_head);
        STLSOFT_ASSERT(NULL == m_tail);

        hash_type_      h       =   m_hasher(value);
        size_type const index   =   h % m_slots.size();
        node_type_*&    slot    =   m_slots[index];
        node_type_*     node    =   new_node_(value, h);

        m_count =   1u;
        m_head  =   node;
        m_tail  =   node;
        slot    =   node;
    }

    node_type_* find_(
        value_type const&   value
    ,   node_type_***       pp = NULL
    ) const
    {
        hash_type_          h       =   m_hasher(value);
        size_type const     index   =   h % m_slots.size();
        node_type_* const&  slot    =   m_slots[index];

        if(NULL != slot)
        {
            // Now do a linear search through the slot list
            { for(node_type_* n = slot; NULL != n; n = n->inner_next)
            {
                if(m_equal(value, n->value))
                {
                    if(NULL != pp)
                    {
                        *pp = const_cast<node_type_**>(&slot);
                    }

                    return n;
                }
            }}
        }

        return NULL;
    }


private:
    bool is_valid() const
    {
        if(0 == m_count)
        {
            if(NULL != m_head)
            {
                return false;
            }
            if(NULL != m_tail)
            {
                return false;
            }
        }
        else
        {
            // Outer list

            // Traverse m_head->NULL in m_count steps

            {
                size_type total = 0;
                { for(node_type_* n = m_head; NULL != n; ++total, n = n->outer_next)
                {
                }}
                if(m_count != total)
                {
                    return false;
                }
            }

            // Traverse m_head->NULL in m_count steps

            {
                size_type total = 0;
                { for(node_type_* n = m_tail; NULL != n; ++total, n = n->outer_prev)
                {
                }}
                if(m_count != total)
                {
                    return false;
                }
            }

            // Inner list
            {
                // Check total == m_count
                // Check every item in each slot list has same hash value

                size_type total = 0;

                { for(ss_typename_type_k slot_buffer_type_::const_iterator i = m_slots.begin(); i != m_slots.end(); ++i)
                {
                    node_type_ const* slot = *i;

                    if(NULL != slot)
                    {
                        size_t const h = slot->hash;

                        ++total;

                        { for(node_type_ const* n = slot->inner_next; NULL != n; n = n->inner_next, ++total)
                        {
                            if((n->hash % m_slots.size()) != (h % m_slots.size()))
                            {
                                return false;
                            }
                        }}
                    }
                }}
                if(m_count != total)
                {
                    return false;
                }
            }
        }

        return true;
    }

private:
    size_type           m_count;
    node_type_*         m_head;
    node_type_*         m_tail;
    node_type_*         m_spare;
    hasher              m_hasher;
    key_equal           m_equal;
    allocator_type      m_allocator;
    slot_buffer_type_   m_slots;
};

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

template<
    ss_typename_param_k V
,   ss_typename_param_k H
,   ss_typename_param_k P
,   ss_typename_param_k A
>
inline bool operator ==(
    ss_typename_type_k insert_ordered_set<V, H, P, A>::const_iterator const& lhs
,   ss_typename_type_k insert_ordered_set<V, H, P, A>::const_iterator const& rhs
)
{
    return lhs.equal(rhs);  
}

template<
    ss_typename_param_k V
,   ss_typename_param_k H
,   ss_typename_param_k P
,   ss_typename_param_k A
>
inline bool operator !=(
    ss_typename_type_k insert_ordered_set<V, H, P, A>::const_iterator const& lhs
,   ss_typename_type_k insert_ordered_set<V, H, P, A>::const_iterator const& rhs
)
{
    return !lhs.equal(rhs); 
}

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<
    ss_typename_param_k V
,   ss_typename_param_k H
,   ss_typename_param_k P
,   ss_typename_param_k A
>
inline void swap(
    insert_ordered_set<V, H, P, A>& lhs
,   insert_ordered_set<V, H, P, A>& rhs
)
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_CONTAINER_HPP_INSERT_ORDERED_SET */

/* ///////////////////////////// end of file //////////////////////////// */
