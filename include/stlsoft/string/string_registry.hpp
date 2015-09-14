/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/string_registry.hpp
 *
 * Purpose:     Defines the string_registry class template.
 *
 * Created:     21st February 2010
 * Updated:     27th August 2010
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


/** \file stlsoft/string/string_registry.hpp
 *
 * \brief [C++] Definition of the stlsoft::string_registry class template
 *   (\ref group__library__string "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_REGISTRY
#define STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_REGISTRY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_REGISTRY_MAJOR       1
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_REGISTRY_MINOR       0
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_REGISTRY_REVISION    6
# define STLSOFT_VER_STLSOFT_STRING_HPP_STRING_REGISTRY_EDIT        9
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
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE
# include <stlsoft/string/string_slice.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_SLICE */

#include <list>
#ifdef STLSOFT_STRING_REGISTRY_USE_IOM
# include <stlsoft/container/insert_ordered_map.hpp>
#else /* ? STLSOFT_STRING_REGISTRY_USE_IOM */
# include <map>
#endif /* STLSOFT_STRING_REGISTRY_USE_IOM */
#include <string>

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

/** A string registry class that avoids allocation
 *
 */
class string_registry
{
public:
    /// The boolean type
    typedef ss_bool_t                                                               bool_type;
    /// The size type
    typedef ss_size_t                                                               size_type;
    /// The character type
    typedef char                                                                    char_type;
    /// The allocator type
    typedef /* ss_typename_type_k */ allocator_selector<char_type>::allocator_type  allocator_type;
    /// The slice type
    typedef string_slice<char_type>                                                 slice_type;
private:
    typedef std::string                                                             string_type_;

public: // Construction
    string_registry()
        : m_strings()
        , m_map()
    {
        STLSOFT_ASSERT(is_valid_());
    }

public: // Size
    /// Indicates whether the registry is empty
    bool_type empty() const
    {
        STLSOFT_ASSERT(is_valid_());

        return 0u == size();
    }
    /// Indicates the number of unique strings registered
    size_type size() const
    {
        STLSOFT_ASSERT(is_valid_());

        return m_map.size();
    }

public: // Operations
    /// Adds the given string - <code>[s, s + n)</code> - to the registry,
    /// and returns a pointer to the resultant slice.
    ///
    /// \param s [in] Pointer to the string
    /// \param n [in] Number of elements in \c s
    /// \param slice_ptr [out] Pointer to a slice pointer. May not be NULL.
    ///
    /// \return The registration count of the string
    ///
    /// \pre NULL != slice_ptr
    /// \pre 0u == n || NULL != s
    size_type add(char const* s, size_type n, slice_type const** slice_ptr)
    {
        STLSOFT_ASSERT(NULL != slice_ptr);
        STLSOFT_ASSERT(0u == n || NULL != s);

        STLSOFT_ASSERT(is_valid_());

        slice_type slice(s, n);

        map_type_::iterator it = m_map.find(slice);

        if(m_map.end() == it)
        {
            strings_type_::iterator its =   m_strings.insert(m_strings.end(), string_type_());
            string_type_&           str =   *its;

            try
            {
                str.assign(s, n);
            }
            catch(std::exception&)
            {
                m_strings.erase(its);

                throw;
            }

            slice_type key(str.data(), str.size());

            try
            {
#ifdef STLSOFT_STRING_REGISTRY_USE_IOM
                it = m_map.insert(m_map.end(), std::make_pair(key, std::make_pair(0u, its))).first;
#else /* ? STLSOFT_STRING_REGISTRY_USE_IOM */
                it = m_map.insert(std::make_pair(key, std::make_pair(0u, its))).first;
#endif /* STLSOFT_STRING_REGISTRY_USE_IOM */
            }
            catch(std::exception&)
            {
                m_strings.erase(its);

                throw;
            }
        }

#ifdef STLSOFT_STRING_REGISTRY_USE_IOM
        map_type_::value_type& value = stlsoft::remove_const(*it);
#else /* ? STLSOFT_STRING_REGISTRY_USE_IOM */
        map_type_::value_type& value = *it;
#endif /* STLSOFT_STRING_REGISTRY_USE_IOM */

        *slice_ptr = &value.first;

        STLSOFT_ASSERT(is_valid_());

        return ++value.second.first;
    }

    /// Adds the given string - <code>s</code> - to the registry.
    ///
    /// \param s [in] The string to be registered
    ///
    /// \return The registration count of the string
    template <ss_typename_param_k S>
    size_type add(S const& s)
    {
        STLSOFT_ASSERT(is_valid_());

        slice_type const* dummy;

        return add(stlsoft_ns_qual(c_str_data)(s), stlsoft_ns_qual(c_str_len)(s), &dummy);
    }

    /// Adds the given string - <code>s</code> - to the registry,
    /// and returns a pointer to the resultant slice.
    ///
    /// \param s [in] The string to be registered
    /// \param slice_ptr [out] Pointer to a slice pointer
    ///
    /// \return The registration count of the string
    ///
    /// \pre NULL != slice_ptr
    template <ss_typename_param_k S>
    size_type add(S const& s, slice_type const** slice_ptr)
    {
        STLSOFT_ASSERT(is_valid_());

        return add(stlsoft_ns_qual(c_str_data)(s), stlsoft_ns_qual(c_str_len)(s), slice_ptr);
    }

    /// Removes the string from the registry.
    ///
    /// \param slice [in] The string slice to be removed
    ///
    /// \return The remaining registration count of the string
    size_type remove(slice_type const* slice)
    {
        STLSOFT_ASSERT(NULL != slice);

        map_type_::iterator it = m_map.find(*slice);

        STLSOFT_MESSAGE_ASSERT("string must be registered!", m_map.end() != it);

        STLSOFT_ASSERT(is_valid_());

#ifdef STLSOFT_STRING_REGISTRY_USE_IOM
        size_type n = --stlsoft::remove_const((*it).second).first;
#else /* ? STLSOFT_STRING_REGISTRY_USE_IOM */
        size_type n = --(*it).second.first;
#endif /* STLSOFT_STRING_REGISTRY_USE_IOM */

        if(0u == n)
        {
            m_strings.erase((*it).second.second);
            m_map.erase(it);
        }

        STLSOFT_ASSERT(is_valid_());

        return n;
    }

    /// Removes all strings from the registry whose reference count is lower
    /// than the given \c threshold
    ///
    /// \param threshold [in] 
    size_type remove_below_count(size_type threshold)
    {
        size_type n = 0;

        { for(map_type_::iterator it = m_map.begin(); it != m_map.end(); )
        {
            if((*it).second.first < threshold)
            {
                m_strings.erase((*it).second.second);

                map_type_::iterator it2 = it;

                ++it2;

                m_map.erase(it);

                it = it2;

                ++n;
            }
            else
            {
                ++it;
            }
        }}

        return n;
    }

    /// Indicates whether the given string - <code>[s, s + n)</code> - is
    /// registered in the registry, and returns a pointer to the resultant
    /// slice if it does.
    ///
    /// \param s [in] Pointer to the string
    /// \param n [in] Number of elements in \c s
    /// \param slice_ptr [out] Pointer to a slice pointer. May not be NULL.
    ///
    /// \retval true The string is registered
    /// \retval false The string is not registered
    ///
    /// \pre NULL != slice_ptr
    /// \pre 0u == n || NULL != s
    bool_type is_registered(char const* s, size_type n, slice_type const** slice_ptr) const
    {
        STLSOFT_ASSERT(NULL != slice_ptr);
        STLSOFT_ASSERT(0u == n || NULL != s);

        STLSOFT_ASSERT(is_valid_());

        slice_type slice(s, n);

        map_type_::const_iterator it = m_map.find(slice);

        if(m_map.end() == it)
        {
            *slice_ptr = NULL;

            STLSOFT_ASSERT(is_valid_());

            return false;
        }
        else
        {
            *slice_ptr = &(*it).first;

            STLSOFT_ASSERT(is_valid_());

            return true;
        }
    }

    /// Indicates whether the given string - <code>s</code> - is registered
    /// in the registry.
    ///
    /// \param s [in] The string
    ///
    /// \retval true The string is registered
    /// \retval false The string is not registered
    template <ss_typename_param_k S>
    bool_type is_registered(S const& s) const
    {
        STLSOFT_ASSERT(is_valid_());

        slice_type const* dummy;

        return is_registered(stlsoft_ns_qual(c_str_data)(s), stlsoft_ns_qual(c_str_len)(s), &dummy);
    }

    /// Indicates whether the given string - <code>s</code> - is registered
    /// in the registry, and returns a pointer to the resultant slice if it
    /// does.
    ///
    /// \param s [in] The string
    /// \param slice_ptr [out] Pointer to a slice pointer. May not be NULL.
    ///
    /// \retval true The string is registered
    /// \retval false The string is not registered
    ///
    /// \pre NULL != slice_ptr
    template <ss_typename_param_k S>
    bool_type is_registered(S const& s, slice_type const** slice_ptr) const
    {
        STLSOFT_ASSERT(is_valid_());

        return is_registered(stlsoft_ns_qual(c_str_data)(s), stlsoft_ns_qual(c_str_len)(s), slice_ptr);
    }

public: // Access

private: // Implementation
    bool_type is_valid_() const
    {
        return m_strings.size() == m_map.size();
    }

private: // Member Variables
    typedef std::list<
        string_type_
    >                             strings_type_;
    typedef std::pair<
        size_type
    ,   strings_type_::iterator
    >                             mapped_type_;
#ifdef STLSOFT_STRING_REGISTRY_USE_IOM
        struct compare_slice_type_
        {
                size_t operator ()(
                    slice_type const& v
                ) const
                {
                    size_t const    MAX_LEN =   10u;

                    size_t                      r = 0;
#if 1
                    char_type const*    p;
                    size_t                      n;

                    if(v.len > MAX_LEN)
                    {
                        n = 10;
                        p = v.ptr + (v.len - MAX_LEN);
                    }
                    else
                    {
                        n = v.len;
                        p = v.ptr;
                    }

                    for(size_t i = 0; i != n; ++i, ++p)
                    {
                        r += *p;
                    }

#if 0
                        for(size_t i = 0; i != v.len; ++i)
                        {
                            r += v.ptr[i];
                        }
#endif /* 0 */
#else /* ? 0 */

                    if(v.len > MAX_LEN)
                    {
                        for(size_t i = 0; i != v.len; ++i)
                        {
                            r += v.ptr[i];
                        }
                    }
#endif /* 0 */

                    return r;
                }

                bool operator ()(
                    slice_type const& lhs
                ,   slice_type const& rhs
                ) const
                {
                    return lhs == rhs;
                }
        };
    typedef stlsoft::insert_ordered_map<
        slice_type
    ,   mapped_type_
        ,       compare_slice_type_
        ,       compare_slice_type_
    >                             map_type_;
#else /* ? STLSOFT_STRING_REGISTRY_USE_IOM */
    typedef std::map<
        slice_type
    ,   mapped_type_
    >                             map_type_;
#endif /* STLSOFT_STRING_REGISTRY_USE_IOM */

    strings_type_   m_strings;
    map_type_       m_map;
};

/* /////////////////////////////////////////////////////////////////////////
 * Specialisations
 */

#if 0
typedef string_registry_base<ss_char_a_t, ss_typename_type_k allocator_selector<ss_char_a_t>::allocator_type> >     string_registry;

typedef string_registry_base<ss_char_w_t, ss_typename_type_k allocator_selector<ss_char_w_t>::allocator_type> >     wstring_registry;
#endif /* 0 */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_REGISTRY */

/* ///////////////////////////// end of file //////////////////////////// */
