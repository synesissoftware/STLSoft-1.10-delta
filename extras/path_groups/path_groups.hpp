/* /////////////////////////////////////////////////////////////////////////
 * File:        extras/path_groups/path_groups.hpp
 *
 * Purpose:     stlsoft::extras::path_groups class.
 *
 * Created:     5th September 2010
 * Updated:     25th July 2015
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


#ifndef STLSOFT_EXTRAS_INCL_PATH_GROUPS_HPP_PATH_GROUPS
#define STLSOFT_EXTRAS_INCL_PATH_GROUPS_HPP_PATH_GROUPS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_PATH_GROUPS_HPP_PATH_GROUPS_MAJOR      1
# define STLSOFT_VER_PATH_GROUPS_HPP_PATH_GROUPS_MINOR      0
# define STLSOFT_VER_PATH_GROUPS_HPP_PATH_GROUPS_REVISION   5
# define STLSOFT_VER_PATH_GROUPS_HPP_PATH_GROUPS_EDIT       14
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <platformstl/filesystem/file_lines.hpp>
#include <stlsoft/memory/allocator_selector.hpp>
#include <stlsoft/string/char_traits.hpp>
#include <stlsoft/string/simple_string.hpp>
#include <stlsoft/string/string_tokeniser.hpp>
#include <stlsoft/string/trim_functions.hpp>
#include <stlsoft/smartptr/shared_ptr.hpp>
#include <stlsoft/util/std/iterator_helper.hpp>

#include <list>
#include <map>
#include <vector>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(_STLSOFT_NO_NAMESPACE)
namespace stlsoft
{
namespace extras
{
#endif /* !_STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

template<
    ss_typename_param_k C
,   ss_typename_param_k T = stlsoft_char_traits<C>
,   ss_typename_param_k A = ss_typename_type_def_k stlsoft::allocator_selector<C>::allocator_type
,   ss_typename_param_k S = stlsoft::basic_simple_string<C, T, A>
>
class basic_file_groups
{
public: // Member Types
    typedef C                                               char_type;
    typedef S                                               string_type;
    typedef std::vector<
        string_type
    >                                                       group_type;
    typedef basic_file_groups<C, T, A, S>                   class_type;
private:
    typedef stlsoft::string_tokeniser<
        string_type
    ,   C
    >                                                       tokeniser_type_;
    typedef stlsoft::shared_ptr<
        group_type
    >                                                       strings_ptr_type_;
    typedef std::map<
        string_type
    ,   strings_ptr_type_
    >                                                       map_type_;
    typedef std::list<
        strings_ptr_type_
    >                                                       groups_type_;
    struct dereference_ptr_
        : std::unary_function<strings_ptr_type_, group_type>
    {
        group_type const& operator ()(strings_ptr_type_ ptr) const
        {
            return *ptr;
        }
    };
public:
    typedef ss_typename_type_k map_type_::const_iterator    item_const_iterator;
    class group_const_iterator
        : public iterator_base< stlsoft_ns_qual_std(forward_iterator_tag)
                            ,   group_type const&
                            ,   ss_ptrdiff_t
                            ,   group_type const*
                            ,   group_type const&
                            >
    {
    private: // Member Types
        typedef ss_typename_type_k groups_type_::const_iterator underlying_iterator_;
    public:
        typedef group_const_iterator                            class_type;

    private: // Construction
        friend class basic_file_groups<C, T, A, S>;
        group_const_iterator(underlying_iterator_ iter)
            : m_iter(iter)
        {}
    public:
        group_const_iterator()
            : m_iter()
        {}
        group_const_iterator(class_type const& rhs)
            : m_iter(rhs.m_iter)
        {}

    public: // Operators
        bool operator ==(class_type const& rhs) const
        {
            return m_iter == rhs.m_iter;
        }
        bool operator !=(class_type const& rhs) const
        {
            return !operator ==(rhs);
        }

        class_type& operator ++()
        {
            ++m_iter;

            return *this;
        }
        class_type operator ++(int)
        {
            class_type r(*this);

            operator ++();

            return r;
        }

        group_type const& operator *()
        {
            return **m_iter;
        }

    private: // Fields
        underlying_iterator_ m_iter;
    };
    typedef ss_size_t                                       size_type;
    typedef ss_bool_t                                       bool_type;

public: // Construction
    template <ss_typename_param_k S2>
    ss_explicit_k basic_file_groups(
        S2 const& path
    )
    {
        typedef platformstl::basic_file_lines<
            C
        > file_lines_t_;

        file_lines_t_ lines(path);

        create_(lines);
    }

public: // Iteration
    item_const_iterator begin_item() const
    {
        return m_map.begin();
    }
    item_const_iterator end_item() const
    {
        return m_map.end();
    }

    group_const_iterator begin_group() const
    {
        return group_const_iterator(m_groups.begin());
    }
    group_const_iterator end_group() const
    {
        return group_const_iterator(m_groups.end());
    }

public: // Accessors
    bool_type contains(string_type const& item) const
    {
        return m_map.end() == m_map.find(item);
    }

    bool_type lookup(
        string_type const&  item
    ,   group_type&         group
    ) const
    {
        map_type_::const_iterator it = m_map.find(item);

        if(m_map.end() == it)
        {
            group.swap(group_type());

            return false;
        }
        else
        {
            group.assign((*it).second->begin(), (*it).second->end());

            return true;
        }
    }

private: // Implementation
    template <ss_typename_param_k FL>
    void create_(FL const& lines)
    {
        group_type ml_items;

        { for(size_t i = 0; i != lines.size(); ++i)
        {
            string_type line(lines[i].data(), lines[i].size());

            stlsoft::trim_all(line);

            if( !line.empty() &&
                '#' == line[0])
            {
                continue;
            }
            else
            {
                bool lineHasPipe = false;

                // Has it got a pipe?
                if( line.empty() ||
                    false != (lineHasPipe = (line.find('|') < line.size())))
                {
                    if(ml_items.size() > 1)
                    {
                        strings_ptr_type_ ptr(new group_type());

                        ml_items.swap(*ptr);

                        { for(group_type::const_iterator i = ptr->begin(); i != ptr->end(); ++i)
                        {
                            m_map.insert(std::make_pair(*i, ptr));
                        }}
                        m_groups.push_back(ptr);
                    }

                    ml_items.clear();

                    if(lineHasPipe)
                    {
                        tokeniser_type_ tokens(line, '|');
#if 0
                        group_type      items(tokens.begin(), tokens.end());
#else /* ? 0 */
                        group_type      items;

                        { for(tokeniser_type_::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
                        {
                            items.push_back(*i);
                        }}
#endif /* 0 */

                        if(items.size() > 1)
                        {
                            strings_ptr_type_ ptr(new group_type());

                            items.swap(*ptr);

                            { for(group_type::const_iterator i = ptr->begin(); i != ptr->end(); ++i)
                            {
                                m_map.insert(std::make_pair(*i, ptr));
                            }}
                            m_groups.push_back(ptr);
                        }
                    }
                }
                else
                {
                    ml_items.push_back(line);
                }
            }
        }}
        if(ml_items.size() > 1)
        {
            strings_ptr_type_ ptr(new group_type());

            ml_items.swap(*ptr);

            { for(group_type::const_iterator i = ptr->begin(); i != ptr->end(); ++i)
            {
                m_map.insert(std::make_pair(*i, ptr));
            }}
            m_groups.push_back(ptr);
        }
    }

private: // Fields
    map_type_       m_map;
    groups_type_    m_groups;
};

typedef basic_file_groups<ss_char_a_t>      file_groups_a;
typedef basic_file_groups<ss_char_w_t>      file_groups_w;
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
typedef basic_file_groups<TCHAR>            file_groups;
#else /* ? OS */
typedef basic_file_groups<char>             file_groups;
#endif /* OS */

/* ////////////////////////////////////////////////////////////////////// */

#if !defined(_STLSOFT_NO_NAMESPACE)
} // namespace extras
} // namespace stlsoft
#endif /* !_STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_EXTRAS_INCL_PATH_GROUPS_HPP_PATH_GROUPS */

/* ///////////////////////////// end of file //////////////////////////// */
