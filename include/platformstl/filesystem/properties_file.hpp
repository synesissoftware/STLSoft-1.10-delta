/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/properties_file.hpp
 *
 * Purpose:     Definition of the platformstl::properties_file class
 *
 * Created:     27th November 2007
 * Updated:     14th February 2016
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2007-2016, Matthew Wilson and Synesis Software
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


/** \file platformstl/filesystem/properties_file.hpp
 *
 * \brief [C++ only] Definition of the platformstl::properties_file
 *  class
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PROPERTIES_FILE
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PROPERTIES_FILE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PROPERTIES_FILE_MAJOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PROPERTIES_FILE_MINOR       2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PROPERTIES_FILE_REVISION    2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_PROPERTIES_FILE_EDIT        20
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <platformstl/platformstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHARSET_TOKENISER
# include <stlsoft/string/charset_tokeniser.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHARSET_TOKENISER */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS
# include <stlsoft/string/split_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPLIT_FUNCTIONS */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW
# include <stlsoft/string/string_view.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW */
# include <stlsoft/string/trim_functions.hpp>
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_ERROR_HPP_EXCEPTIONS
# include <platformstl/error/exceptions.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_ERROR_HPP_EXCEPTIONS */
#ifndef PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT
# ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
#  include <platformstl/filesystem/filesystem_traits.hpp>
# endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
# ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE
#  include <platformstl/filesystem/memory_mapped_file.hpp>
# endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_MEMORY_MAPPED_FILE */
#endif /* !PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT */

#include <map>
#include <stdexcept>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */

namespace stlsoft
{
namespace platformstl_project
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** Reads in a properties file, from file-system or memory, and makes the
 * properties available via a map-like interface
 */
class properties_file
{
public: // Member Types
    typedef char                                    char_type;
    typedef properties_file                         class_type;
    typedef stlsoft::basic_string_view<char_type>   view_type;
private:
    typedef std::basic_string<char_type>            string_type_;
    typedef std::map<   view_type
                    ,   view_type
                    >                               values_map_type_;
#ifndef PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT
    typedef filesystem_traits<char_type>            traits_type_;
#endif /* !PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT */
public:
    typedef values_map_type_::value_type            value_type;
    typedef values_map_type_::const_iterator        const_iterator;
    typedef ss_size_t                               size_type;

    enum source_type
    {
            evaluate = 0
#ifndef PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT
        ,   file
#endif /* !PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT */
        ,   contents
    };

public: // Construction
    template <typename S>
    ss_explicit_k
    properties_file(S const& source, source_type type = evaluate)
    {
        open_(stlsoft_ns_qual(c_str_ptr)(source), stlsoft_ns_qual(c_str_len)(source), type);
    }

public: // Accessors
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    /// Returns the value associated with the given property, or throws an
    /// exception (of type <code>std::out_of_range</code>) if it does not
    /// exist in the properties file
    template <ss_typename_param_k S>
    view_type operator [](S const& propertyName) const
    {
        return operator_subscript_(view_type(stlsoft_ns_qual(c_str_data)(propertyName), stlsoft_ns_qual(c_str_len)(propertyName)));
    }

private:
    view_type operator_subscript_(view_type const& propertyName) const
    {
        values_map_type_::const_iterator it = m_properties.find(propertyName);

        if(m_properties.end() == it)
        {
            string_type_ msg("Failed to find property named '");

            msg.append(propertyName.data(), propertyName.size());
            msg.append(1, '\'');

            STLSOFT_THROW_X(std::out_of_range(msg));
        }

        return (*it).second;
    }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

public:
    size_type   size() const        {   return m_properties.size();     }

public: // Search
    template <ss_typename_param_k S>
    const_iterator  find(S const& name) const
    {
        return m_properties.find(view_type(stlsoft_ns_qual(c_str_data)(name), stlsoft_ns_qual(c_str_len)(name)));
    }

public: // Iteration
    const_iterator  begin() const   {   return m_properties.begin();    }
    const_iterator  end() const     {   return m_properties.end();      }

private: // Implementation
    static bool is_space_not_nl(char_type ch)
    {
        return isspace(ch) && (ch != '\r' && ch != '\n');
    }

    void open_(char_type const* source, size_type len, source_type type)
    {
        STLSOFT_ASSERT(NULL != source);

        switch(type)
        {
            default:
                STLSOFT_MESSAGE_ASSERT("Invalid source type!", 0);
            case    evaluate:
                open_(source, len, evaluate_type_(source, len));
                break;
#ifndef PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT
            case    file:
                open_file_(source);
                break;
#endif /* !PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT */
            case    contents:
                parse_(source, len);
                break;
        }
    }

    source_type evaluate_type_(char_type const* source, size_type)
    {
        STLSOFT_ASSERT(NULL != source);

#ifndef PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT
        if('\0' == *source)
        {
            return contents;
        }
        else
        if(traits_type_::is_file(source))
        {
            return file;
        }
        else if(NULL != traits_type_::str_pbrk(source, "\r\n\t|"))
        {
            return contents;
        }
        else
        {
            char const* colon1 = traits_type_::str_chr(source, ':');

            if(NULL != colon1)
            {
                char const* colon2 = traits_type_::str_rchr(source, ':');

                if( colon1 != colon2 ||
                    colon1 > source + 4)
                {
                    return contents;
                }

                char const* slash1 = traits_type_::str_rchr(source, '/');
                char const* slash2 = traits_type_::str_rchr(source, '\\');

                if( NULL == slash1 &&
                    NULL == slash2)
                {
                    return contents;
                }
            }
        }

        return file;
#else /* ? PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT */
        STLSOFT_SUPPRESS_UNUSED(source);

        return contents;
#endif /* !PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT */
    }

#ifndef PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT
    void open_file_(char_type const* fileName)
    {
        memory_mapped_file  file(fileName);

        // TODO: need runtime throw if file.size() > limit_traits<size_type>::maximum()

// NOTE: QM: should we use truncation cast here? If that's the _only_ 
// way a std::out_of_range could be thrown, then fine. But if not, then
// there's a possible ambiguity in the receiver
//
// OPTIONS: do we attach a message? do we derive a special class? do we attach a result code?

        parse_(static_cast<char const*>(file.memory()), static_cast<size_type>(file.size()));
    }
#endif /* !PLATFORMSTL_PROPERTIES_FILE_NO_FILE_SUPPORT */

    void parse_(char_type const* base, size_type size)
    {
        const char  SPLIT_CHAR      =   '\0';
        const char  EOL_STRING[]    =   "\0\0";

        enum state_t
        {
                inWhitespace
            ,   inCommentLine
            ,   inName
            ,   inNameWithBackslash
            ,   inSeparator
            ,   inValue
            ,   inValueWithBackslash
            ,   inValueLineContinuation

        }                   state   =   inWhitespace;
        char const* const   begin   =   base;
        char const* const   end     =   begin + size;
        char const*         p;
        string_type_        spaces; // temporary store for spaces in value that might be trailing, or might be embedded

        m_contents.reserve(static_cast<size_type>(end - begin));

        for(p = begin; p != end; ++p)
        {
            const char  ch = *p;

            switch(state)
            {
                default:
                    STLSOFT_ASSERT(!"Invalid state");
                case    inWhitespace:
                    if(isspace(ch))
                    {
                        ; // Nothing to do, since already in whitespace
                    }
                    else switch(ch)
                    {
                        case    '\\':
                            state = inNameWithBackslash;
                            break;
                        case    '!':
                        case    '#':
                            state = inCommentLine;
                            break;
                        case    '=':
                        case    ':':
                            state = inValue;
                            break;
                        default:
                            state = inName;
                            m_contents.append(1, ch);
                            break;
                    }
                    break;

                case    inCommentLine:
                    switch(ch)
                    {
                        case    '\r':
                            if(p + 1 < end)
                            {
                                if('\n' == 1[p])
                                {
                                    ++p;
                                }
                            }
                            // Fall through
                        case    '\n':
                            state = inWhitespace;
                            break;
                    }
                    break;

                case    inName:
                    if(is_space_not_nl(ch))
                    {
                        state = inSeparator;
                        break;
                    }
                    else switch(ch)
                    {
                        case    '\r':
                            if(p + 1 < end)
                            {
                                if('\n' == 1[p])
                                {
                                    ++p;
                                }
                            }
                            // Fall through
                        case    '\n':
                            state = inWhitespace;
                            m_contents.append(EOL_STRING, STLSOFT_NUM_ELEMENTS(EOL_STRING) - 1u);
                            break;
                        case    ':':
                        case    '=':
                            state = inSeparator;
                            break;
                        case    '\\':
                            state = inNameWithBackslash;
                            break;
                        default:
                            m_contents.append(1, ch);
                            break;
                    }
                    break;

                case    inNameWithBackslash:
                    switch(ch)
                    {
                        case    '\r':
                            if(p + 1 < end)
                            {
                                if('\n' == 1[p])
                                {
                                    ++p;
                                }
                            }
                            // Fall through
                        case    '\n':
                            state = inWhitespace;
                            break;
                        case    'r':
                            m_contents.append(1, '\r');
                            state = inName;
                            break;
                        case    'n':
                            m_contents.append(1, '\n');
                            state = inName;
                            break;
                        default:
                            m_contents.append(1, ch);
                            state = inName;
                            break;
                    }
                    break;

                case    inSeparator:
                    if(is_space_not_nl(ch))
                    {
                        ; // Ignore
                    }
                    else switch(ch)
                    {
                        case    '\r':
                            if(p + 1 < end)
                            {
                                if('\n' == 1[p])
                                {
                                    ++p;
                                }
                            }
                            // Fall through
                        case    '\n':
                            state = inWhitespace;
                            m_contents.append(EOL_STRING, STLSOFT_NUM_ELEMENTS(EOL_STRING) - 1u);
                            break;
                        case    '\\':
                            state = inValueWithBackslash;
                            m_contents.append(1, SPLIT_CHAR);
                            break;
                        case    ':':
                        case    '=':
                            break;
                        default:
                            // Need to insert a line separator here, if going to 
                            m_contents.append(1, SPLIT_CHAR);
                            state = inValue;
                            m_contents.append(1, ch);
                            break;
                    }
                    break;

                case    inValue:
                    if(is_space_not_nl(ch))
                    {
                        spaces.append(1, ch); // remember, in case they're embedded
                    }
                    else switch(ch)
                    {
                        case    '\r':
                            if(p + 1 < end)
                            {
                                if('\n' == 1[p])
                                {
                                    ++p;
                                }
                            }
                            // Fall through
                        case    '\n':
                            state = inWhitespace;
                            m_contents.append(EOL_STRING, STLSOFT_NUM_ELEMENTS(EOL_STRING) - 1u);
                            break;
                        case    '\\':
                            m_contents.append(spaces);
                            spaces.erase();
                            state = inValueWithBackslash;
                            break;
                        default:
                            m_contents.append(spaces);
                            spaces.erase();
                            m_contents.append(1, ch);
                            break;
                    }
                    break;

                case    inValueWithBackslash:
                    switch(ch)
                    {
                        case    '\r':
                            if(p + 1 < end)
                            {
                                if('\n' == 1[p])
                                {
                                    ++p;
                                }
                            }
                            // Fall through
                        case    '\n':
                            // End of line, so just ignore, and the value will carry on.
                            state = inValueLineContinuation;
                            break;
                        case    'n':
                            state = inValue;
                            m_contents.append(1, '\n');
                            break;
                        default:
                            state = inValue;
                            m_contents.append(1, ch);
                            break;
                    }
                    break;

                case    inValueLineContinuation:
                    if(is_space_not_nl(ch))
                    {
                        ; // Ignore leading space
                    }
                    else switch(ch)
                    {
                        case    '\r':
                            if(p + 1 < end)
                            {
                                if('\n' == 1[p])
                                {
                                    ++p;
                                }
                            }
                            // Fall through
                        case    '\n':
                            state = inWhitespace;
                            m_contents.append(EOL_STRING, STLSOFT_NUM_ELEMENTS(EOL_STRING) - 1u);
                            break;
                        case    '\\':
                            state = inValueWithBackslash;
                            break;
                        default:
                            state = inValue;
                            m_contents.append(1, ch);
                            break;
                    }
                    break;
            }
        }

        typedef ::stlsoft::string_tokeniser<view_type, view_type>   tokeniser_t;

        tokeniser_t lines(view_type(m_contents.data(), m_contents.size()), view_type(EOL_STRING, STLSOFT_NUM_ELEMENTS(EOL_STRING) - 1u));

        { for(tokeniser_t::const_iterator b = lines.begin(); b != lines.end(); ++b)
        {
            view_type   line(*b);

            if(line.empty())
            {
                continue;
            }
            else switch(line[0])
            {
                case    '!':
                case    '#':
                    continue;
                default:
                    {
                        view_type   name;
                        view_type   value;

                        stlsoft::split(line, SPLIT_CHAR, name, value);

                        m_properties.insert(values_map_type_::value_type(name, value));
                    }
                    break;
            }
        }}
    }

private:
    string_type_        m_contents;
    values_map_type_    m_properties;

private: // Not to be implemented
    properties_file(class_type const&);
    class_type& operator =(class_type const&);
};

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PROPERTIES_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
