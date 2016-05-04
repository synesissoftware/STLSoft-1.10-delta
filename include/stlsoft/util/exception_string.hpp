/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/exception_string.hpp
 *
 * Purpose:     Contains the exception_string limited functionality string class.
 *
 * Created:     26th December 2005
 * Updated:     9th October 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2015, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/exception_string.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::exception_string class
 *   (\ref group__library__utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_MAJOR    2
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_MINOR    1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_REVISION 10
# define STLSOFT_VER_STLSOFT_UTIL_HPP_EXCEPTION_STRING_EDIT     36
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
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE
# include <stlsoft/string/string_slice.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>                     // for abort()
#endif /* !STLSOFT_INCL_H_STDLIB */

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

/** Minimalist string class for use within exceptions.
 *
 * Notable features are:
 * - small string optimisation (SSO)
 * - shared state (when SSO does not apply)
 * - immutable
 *
 * \ingroup group__library__string
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k T = stlsoft_char_traits<C>
        ,   ss_typename_param_k A = ss_typename_type_def_k stlsoft::allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k T /* = stlsoft_char_traits<C> */
        ,   ss_typename_param_k A /* = stlsoft::allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class exception_string_base
{
public: // Member Types
    // The character type
    typedef C                                               char_type;
    /// The traits type
    typedef T                                               traits_type;
    // The traits type
    typedef A                                               allocator_type;
    /// This type
    typedef exception_string_base<C, T, A>                  class_type;
    /// The size type
    typedef ss_size_t                                       size_type;
private:
    typedef string_slice<C, T>                              slice_type_;

#if defined(STLSOFT_COMPILER_IS_MWERKS)
public:
#endif /* compiler */
#if defined(STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT)
    typedef ss_typename_type_k allocator_type::ss_template_qual_k rebind<ss_byte_t>::other  byte_allocator_type_;
#else /* ? STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
    typedef ss_typename_type_k allocator_selector<ss_byte_t>::allocator_type                byte_allocator_type_;
#endif /* STLSOFT_LF_ALLOCATOR_REBIND_SUPPORT */
private:

    // NOTE: GCC offsetof() warning reasons:
    //
    // - virtual method
    // - protected data
    // - ctor

    // There are three variations of implementation:
    //
    // 1. protection measures on members + offsetof() - this is what GCC rejects
    // 2. offsetof() on a separate block
    // 3. protection measures on members (- payload) + payload-simulated-off-end

#if 1

    // 2. offsetof() on a separate block

    struct shared_message_block
    {
        size_type          length;
        char_type const*   message;
        ss_sint32_t        refCount;
        size_type          allocSize;
        char_type          payload[1];
    };

    struct shared_message_type
        : public shared_message_block
        , protected byte_allocator_type_
    {
    public: // Member Types
        typedef byte_allocator_type_        allocator_type;

    private: // Construction
        shared_message_type(allocator_type& ator, size_type allocSize, size_type len1, char_type const* s1, size_type len2, char_type const* s2)
            : allocator_type(ator)
        {
            this->length        =   len1 + len2;
            this->message       =   &this->payload[0];
            this->refCount  =   1;
            this->allocSize =   allocSize;

            ::memcpy(&this->payload[0] + 0, s1, sizeof(char_type) * len1);
            ::memcpy(&this->payload[0] + len1, s2, sizeof(char_type) * len2);
            this->payload[len1 + len2] = '\0';
        }
    public:
        static shared_message_type* create(char_type const* s1, size_type len1, char_type const* s2, size_type len2)
        {
            size_t const            len         =   len1 + len2;
            size_t const            fixed       =   STLSOFT_RAW_OFFSETOF(shared_message_block, payload);
            size_t const            variable    =   sizeof(char_type) * (1u + len);
            size_t const            total       =   fixed + variable;
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER < 1310
            byte_allocator_type_    ator        =   byte_allocator_type_(); // Avoids erroneous warning about not being initialised
#else /* ? compiler */
            byte_allocator_type_    ator;
#endif /* compiler */
            void*                   pv          =   ator.allocate(total, NULL);
            shared_message_type*    shared      =   new (ator, pv) shared_message_type(ator, total, len1, s1, len2, s2);

            return shared;
        }
    private:
        ~shared_message_type() stlsoft_throw_0()
        {}
    public:
        void* operator new(size_t /* cb */, allocator_type& /* ator */, void* pv)
        {
            STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != pv, "placement memory pointer cannot be NULL");

            return pv;
        }
    private:
        void operator delete(void* /* pv */)
        {
            STLSOFT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("execution should never reach this point");

            ::abort();
        }
# ifndef __BORLANDC__
        void operator delete(void* /* pv */, allocator_type& /* ator */, void* )
        {
            STLSOFT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("execution should never reach this point");

            ::abort();
        }
# endif /* compiler */

    public: // Reference-counting
        void AddRef()
        {
            ++this->refCount;
        }
        void Release()
        {
            if(0 == --this->refCount)
            {
                // Transfer the ator "state" out of the instance
                // before destroying it explicitly, then use that
                // ator to deallocate.

                byte_allocator_type_    ator(*this);
                size_type               cb = this->allocSize;
                void*                   pv = this;
                ss_byte_t*              py = static_cast<ss_byte_t*>(pv);

                this->~shared_message_type();

                ator.deallocate(py, cb);
            }
        }

    private: // Implementation
        char_type* get_payload_()
        {
            return this->payload;
        }
    };

#else

# if 1

    // 1. protection measures on members + offsetof() - this is what GCC rejects

    struct shared_message_type
        : protected byte_allocator_type_
    {
    public: // Member Types
        typedef byte_allocator_type_        allocator_type;

    private: // Construction
        shared_message_type(allocator_type& ator, size_type allocSize, size_type len1, char_type const* s1, size_type len2, char_type const* s2)
            : allocator_type(ator)
            , length(len1 + len2)
            , message(get_payload_())
            , refCount(1)
            , allocSize(allocSize)
        {
            ::memcpy(get_payload_() + 0, s1, sizeof(char_type) * len1);
            ::memcpy(get_payload_() + len1, s2, sizeof(char_type) * len2);
            get_payload_()[len1 + len2] = '\0';
        }
        ~shared_message_type() stlsoft_throw_0()
        {}
        void* operator new(size_t /* cb */, allocator_type& /* ator */, void* pv)
        {
            STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != pv, "placement memory pointer cannot be NULL");

            return pv;
        }
        void operator delete(void* pv)
        {
            allocator_type  ator;

#  ifndef __BORLANDC__
            operator delete(pv, ator, NULL);
        }
        void operator delete(void* pv, allocator_type& ator, void* )
        {
#  endif /* compiler */
            ss_byte_t* py = static_cast<ss_byte_t*>(pv);

            ator.deallocate(py, 0u);
        }
    private:
        shared_message_type& operator =(shared_message_type const&);

    public:
        static shared_message_type* create(char_type const* s1, size_type len1, char_type const* s2, size_type len2)
        {
            size_t const            len         =   len1 + len2;
            size_t const            fixed       =   STLSOFT_RAW_OFFSETOF(shared_message_type, payload);
            size_t const            variable    =   sizeof(char_type) * (1u + len);
            size_t const            total       =   fixed + variable;
            byte_allocator_type_    ator        =   byte_allocator_type_(); // Avoids erroneous warning about not being initialised
            void*                   pv          =   ator.allocate(total, NULL);
            shared_message_type*    shared      =   new (ator, pv) shared_message_type(ator, total, len1, s1, len2, s2);

            return shared;
        }

    public: // Reference-counting
        void AddRef()
        {
            ++this->refCount;
        }
        void Release()
        {
            if(0 == --this->refCount)
            {
                // Transfer the ator "state" out of the instance
                // before destroying it explicitly, then use that
                // ator to deallocate.

                byte_allocator_type_    ator(*this);
                size_type               cb = this->allocSize;
                void*                   pv = this;
                ss_byte_t*              py = static_cast<ss_byte_t*>(pv);

                this->~shared_message_type();

                ator.deallocate(py, cb);
            }
        }

    private: // Implementation
        char_type* get_payload_()
        {
            return this->payload;
        }

    public: // Fields
        size_type const         length;
        char_type const* const  message;
    private:
        ss_sint32_t             refCount;
        size_type               allocSize;
        char_type               payload[1];
    };

# else /* ? 0 */

    // 3. protection measures on members (- payload) + payload-simulated-off-end

    struct shared_message_type
        : protected byte_allocator_type_
    {
    public: // Member Types
        typedef byte_allocator_type_        allocator_type;

    private: // Construction
        shared_message_type(allocator_type& ator, size_type allocSize, size_type len1, char_type const* s1, size_type len2, char_type const* s2)
            : allocator_type(ator)
            , length(len1 + len2)
            , message(get_payload_())
            , refCount(1)
            , allocSize(allocSize)
        {
            ::memcpy(get_payload_() + 0, s1, sizeof(char_type) * len1);
            ::memcpy(get_payload_() + len1, s2, sizeof(char_type) * len2);
            get_payload_()[len1 + len2] = '\0';
        }
        ~shared_message_type() stlsoft_throw_0()
        {}
        void* operator new(size_t /* cb */, allocator_type& /* ator */, void* pv)
        {
            STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != pv, "placement memory pointer cannot be NULL");

            return pv;
        }
        void operator delete(void* pv)
        {
            allocator_type  ator;

#  ifndef __BORLANDC__
            operator delete(pv, ator, NULL);
        }
        void operator delete(void* pv, allocator_type& ator, void* )
        {
#  endif /* compiler */
            ss_byte_t* py = static_cast<ss_byte_t*>(pv);

            ator.deallocate(py, 0u);
        }
    private:
        shared_message_type& operator =(shared_message_type const&);

    public:
        static shared_message_type* create(char_type const* s1, size_type len1, char_type const* s2, size_type len2)
        {
            size_t const            len         =   len1 + len2;
            size_t const            fixed       =   sizeof(shared_message_type);
            size_t const            variable    =   sizeof(char_type) * (1u + len);
            size_t const            total       =   fixed + variable;
            byte_allocator_type_    ator        =   byte_allocator_type_(); // Avoids erroneous warning about not being initialised
            void*                   pv          =   ator.allocate(total, NULL);
            shared_message_type*    shared      =   new (ator, pv) shared_message_type(ator, total, len1, s1, len2, s2);

            return shared;
        }

    public: // Reference-counting
        void AddRef()
        {
            ++this->refCount;
        }
        void Release()
        {
            if(0 == --this->refCount)
            {
                // Transfer the ator "state" out of the instance
                // before destroying it explicitly, then use that
                // ator to deallocate.

                byte_allocator_type_    ator(*this);
                size_type               cb = this->allocSize;
                void*                   pv = this;
                ss_byte_t*              py = static_cast<ss_byte_t*>(pv);

                this->~shared_message_type();

                ator.deallocate(py, cb);
            }
        }

    private: // Implementation
        char_type* get_payload_()
        {
            void* p = this + 1;

            return static_cast<char_type*>(p);
        }

    public: // Fields
        size_type const         length;
        char_type const* const  message;
    private:
        ss_sint32_t             refCount;
        size_type               allocSize;
    };

# endif /* 0 */

#endif

private: // Member Constants
#ifdef STLSOFT_DEBUG
    enum { InternalBufferSize   =   16 };
#else /* ? STLSOFT_DEBUG */
    enum { InternalBufferSize   =   96 };
#endif /* STLSOFT_DEBUG */

public: // Construction
    /// Constructs an empty exception
    exception_string_base()
        : m_shared(NULL)
        , m_slice(&m_internal[0], 0u)
    {
        m_internal[0] = '\0';

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(is_valid(), "invariant does not hold after construction");
    }
    /// Constructs an exception from the given message
    ///
    /// \note This is deliberately not explicit
    exception_string_base(char_type const* message)
    {
        size_type const len = (NULL == message) ? 0u : traits_type::length(message);

        init_(message, len, NULL, 0u);

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(is_valid(), "invariant does not hold after construction");
    }
    /// Constructs an exception from the given message, to the given length
    exception_string_base(char_type const* message, size_type len)
    {
        init_(message, len, NULL, 0u);

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(is_valid(), "invariant does not hold after construction");
    }

    /// Copy construction
    exception_string_base(class_type const& rhs)
    {
        if(NULL != rhs.m_shared)
        {
            m_shared        =   rhs.m_shared;
            m_shared->AddRef();
            m_slice         =   rhs.m_slice;
            m_internal[0]   =   '\0';
        }
        else
        {
            m_shared        =   NULL;
            m_slice.len     =   rhs.m_slice.len;
            m_slice.ptr     =   m_internal;
            ::memcpy(&m_internal[0], &rhs.m_internal[0], sizeof(char_type) * (1u + rhs.m_slice.len));
        }

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(is_valid(), "invariant does not hold after construction");
    }

    /// Destructor
    ~exception_string_base()
    {
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(is_valid(), "invariant does not hold before destruction");

        if(NULL != m_shared)
        {
            m_shared->Release();
        }
    }

    /// Creation method
    static class_type create(char_type const* s1, char_type const* s2)
    {
        size_type const len1    =   (NULL == s1) ? 0u : traits_type::length(s1);
        size_type const len2    =   (NULL == s2) ? 0u : traits_type::length(s2);
        //size_type const len     =   len1 + len2;

        class_type  s;

        s.init_(s1, len1, s2, len2);

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(s.is_valid(), "invariant does not hold after creation");

        return s;
    }

    /// Swaps the states between two instances
    void swap(class_type& rhs) stlsoft_throw_0()
    {
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(    is_valid(), "invariant does not hold before swap");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(rhs.is_valid(), "invariant does not hold before swap");

        // Swapping the m_shared and m_internal members are
        // straightforward. By contrast, swapping m_slice is complex, since
        // it might refer to the internal buffer or the shared buffer.

        bool const thisExternal =   m_slice.ptr != &m_internal[0];
        bool const rhsExternal  =   rhs.m_slice.ptr != &rhs.m_internal[0];

        std_swap(m_shared, rhs.m_shared);
        std_swap(m_slice.len, rhs.m_slice.len);
        if(rhsExternal)
        {
            m_slice.ptr = m_shared->message;
        }
        else
        {
            m_slice.ptr = &m_internal[0];
        }
        if(thisExternal)
        {
            rhs.m_slice.ptr = rhs.m_shared->message;
        }
        else
        {
            rhs.m_slice.ptr = &rhs.m_internal[0];
        }
        swap_buffer_(&m_internal[0], &rhs.m_internal[0], InternalBufferSize + 1);

        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(    is_valid(), "invariant does not hold after swap");
        STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(rhs.is_valid(), "invariant does not hold after swap");
    }

private:
    void init_(char_type const* s1, size_type len1, char_type const* s2, size_type len2)
    {
        size_type const len = len1 + len2;

        if(0u == len)
        {
            m_shared        =   NULL;
            m_slice.len     =   0u;
            m_slice.ptr     =   &m_internal[0];
            m_internal[0]   = '\0';
        }
        else
        {
            if(len < STLSOFT_NUM_ELEMENTS(m_internal))
            {
                // Internal

                m_shared        =   NULL;
                m_slice.len     =   len;
                m_slice.ptr     =   &m_internal[0];
                ::memcpy(&m_internal[0] + 0, s1, sizeof(char_type) * len1);
                ::memcpy(&m_internal[0] + len1, s2, sizeof(char_type) * len2);
                m_internal[len] =   '\0';
            }
            else
            {
                // Shared
                m_shared        =   shared_message_type::create(s1, len1, s2, len2);
                m_slice.len     =   len;
                m_slice.ptr     =   m_shared->message;
                m_internal[0]   =   '\0';
            }
        }
    }

    // TODO: Put this into an internal helper component
    static void swap_buffer_(
        char_type*  buff1
    ,   char_type*  buff2
    ,   size_type   n
    )
    {
        STLSOFT_ASSERT(InternalBufferSize + 1 == n);

        char_type t[InternalBufferSize + 1];

        ::memcpy(&t[0], buff1, sizeof(char_type) * n);
        ::memcpy(buff1, buff2, sizeof(char_type) * n);
        ::memcpy(buff2, &t[0], sizeof(char_type) * n);
    }


protected: // Contract
    bool is_valid() const
    {
        if(NULL != m_shared)
        {
            // Shared state

            if(m_slice.len != m_shared->length)
            {
                return false;
            }
            if(m_slice.ptr != m_shared->message)
            {
                return false;
            }

            if('\0' != m_internal[0])
            {
                return false;
            }
        }
        else
        {
            if(m_slice.ptr != m_internal)
            {
                return false;
            }
            if(m_slice.len >= STLSOFT_NUM_ELEMENTS(m_internal))
            {
                return false;
            }
        }

        return true;
    }

private:
    class_type& operator =(class_type const&);

#if 0
    class_type& operator =(class_type const& rhs)
    {
        class_type t(rhs);

        t.swap(*this);

        return *this;
    }
#endif /* 0 */

public: // Attributes
    /// Returns a null-terminated c-style string string representing
    /// the message
    char_type const* c_str() const
    {
        return data();
    }
    /// Returns a null-terminated c-style string string representing
    /// the message
    char_type const* data() const
    {
        STLSOFT_ASSERT(NULL != m_slice.ptr);

        return m_slice.ptr;
    }
    /// Returns the number of characters in the message
    size_type   length() const
    {
        return size();
    }
    /// Returns the number of characters in the message
    size_type   size() const
    {
        return m_slice.len;
    }
    /// Indicates whether or not the message is blank
    ss_bool_t   empty() const
    {
        return 0 == this->length();
    }

private: // Fields
    shared_message_type*    m_shared;
    slice_type_             m_slice;
    char_type               m_internal[InternalBufferSize + 1];
};

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

typedef exception_string_base<
    ss_char_a_t
,   stlsoft_char_traits<ss_char_a_t>
,   stlsoft::allocator_selector<ss_char_a_t>::allocator_type
>                                                           exception_string_a;
typedef exception_string_base<
    ss_char_w_t
,   stlsoft_char_traits<ss_char_w_t>
,   stlsoft::allocator_selector<ss_char_w_t>::allocator_type
>                                                           exception_string_w;

typedef exception_string_a                                  exception_string;
typedef exception_string_w                                  exception_wstring;

/* /////////////////////////////////////////////////////////////////////////
 * swap()
 */

/** Swaps the state of
 * two \ref stlsoft::exception_string_base exception_string\endlink
 * instances.
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k T
,   ss_typename_param_k A
>
inline void swap(
    exception_string_base<C, T, A>& lhs
,   exception_string_base<C, T, A>& rhs
)
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline exception_string::char_type const* c_str_data(exception_string const& xs)
{
    return xs.data();
}

inline exception_string::size_type c_str_len(exception_string const& xs)
{
    return xs.size();
}

inline exception_string::char_type const* c_str_ptr(exception_string const& xs)
{
    return xs.c_str();
}


inline ss_char_a_t const* c_str_data_a(exception_string_a const& xs)
{
    return xs.data();
}

inline size_t c_str_len_a(exception_string_a const& xs)
{
    return xs.size();
}

inline ss_char_a_t const* c_str_ptr_a(exception_string_a const& xs)
{
    return xs.data();
}


inline ss_char_w_t const* c_str_data_w(exception_string_w const& xs)
{
    return xs.data();
}

inline size_t c_str_len_w(exception_string_w const& xs)
{
    return xs.size();
}

inline ss_char_w_t const* c_str_ptr_w(exception_string_w const& xs)
{
    return xs.data();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

/** Adds a C-style string to an exception_string
 *
 * \ingroup group__library__string
 */

template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline exception_string_base<C, T, A> operator +(exception_string_base<C, T, A> const& lhs, ss_typename_type_k exception_string_base<C, T, A>::char_type const* rhs)
{
    return exception_string_base<C, T, A>::create(lhs.c_str(), rhs);
}

/** Adds an exception_string to a character
 *
 * \ingroup group__library__string
 */
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline exception_string_base<C, T, A> operator +(ss_typename_type_k exception_string_base<C, T, A>::char_type lhs, exception_string_base<C, T, A> const& rhs)
{
    ss_typename_type_k exception_string::char_type lhs_[2] = { lhs, '\0' };

    return exception_string_base<C, T, A>::create(lhs_, rhs.c_str());
}

/** Adds a character to an exception_string
 *
 * \ingroup group__library__string
 */
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline exception_string_base<C, T, A> operator +(exception_string_base<C, T, A> const& lhs, ss_typename_type_k exception_string_base<C, T, A>::char_type rhs)
{
    ss_typename_type_k exception_string::char_type rhs_[2] = { rhs, '\0' };

    return exception_string_base<C, T, A>::create(lhs.c_str(), rhs_);
}

/** Adds an exception_string to a C-style string
 *
 * \ingroup group__library__string
 */
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline exception_string_base<C, T, A> operator +(ss_typename_type_k exception_string_base<C, T, A>::char_type const* lhs, exception_string_base<C, T, A> const& rhs)
{
    return exception_string_base<C, T, A>::create(lhs, rhs.c_str());
}

/** Adds an exception_string to an exception_string
 *
 * \ingroup group__library__string
 */
template <ss_typename_param_k C, ss_typename_param_k T, ss_typename_param_k A>
inline exception_string_base<C, T, A> operator +(exception_string_base<C, T, A> const& lhs, exception_string_base<C, T, A> const& rhs)
{
    return exception_string_base<C, T, A>::create(lhs.c_str(), rhs.c_str());
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

/* VC++ 6 requires this to be (illegally) placed in namespace std, otherwise
 * it's not picked up.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
namespace std
{

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1300

    inline void swap(
        stlsoft_ns_qual(exception_string_a)& lhs
    ,   stlsoft_ns_qual(exception_string_a)& rhs
    )
    {
        lhs.swap(rhs);
    }
    inline void swap(
        stlsoft_ns_qual(exception_string_w)& lhs
    ,   stlsoft_ns_qual(exception_string_w)& rhs
    )
    {
        lhs.swap(rhs);
    }

# else /* ? VC++ 6- */

    template<
        ss_typename_param_k C
    ,   ss_typename_param_k T
    ,   ss_typename_param_k A
    >
    inline void swap(
        stlsoft_ns_qual(exception_string_base)<C, T, A>&  lhs
    ,   stlsoft_ns_qual(exception_string_base)<C, T, A>&  rhs
    )
    {
        lhs.swap(rhs);
    }

# endif /* VC++ 6- */

} // namespace std
#endif /* STLSOFT_CF_std_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_EXCEPTION_STRING */

/* ///////////////////////////// end of file //////////////////////////// */
