/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/test/util/files/std/input_FILE.hpp
 *
 * Purpose:     Definition of the stlsoft::test::util::input_FILE class.
 *
 * Created:     9th February 2012
 * Updated:     24th July 2012
 *
 * Author:      Matthew Wilson
 *
 * Copyright:   Synesis Software Pty Ltd, (c) 2012. All rights reserved.
 *
 * Home:        www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_STD_HPP_INPUT_FILE
#define STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_STD_HPP_INPUT_FILE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_STD_HPP_INPUT_FILE_MAJOR       1
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_STD_HPP_INPUT_FILE_MINOR       0
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_STD_HPP_INPUT_FILE_REVISION    4
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_STD_HPP_INPUT_FILE_EDIT        4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h>
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/shims/access/string.hpp>
//#include <stlsoft/shims/access/string/fwd.hpp>
#include <stlsoft/shims/access/string/std/c_string.h>

#include <stlsoft/test/util/files/std/ximpl/base_FILE.hpp>

#include <string>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{

namespace test
{

namespace util
{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

class input_FILE
  : private ximpl::base_FILE
{
public: // Member Types
    typedef input_FILE      class_type;
private:
  typedef ximpl::base_FILE  parent_class_type;

public: // Construction
    input_FILE()
        : parent_class_type()
    {}
private:
    input_FILE(class_type const&);
    class_type& operator =(class_type const&);

public: // Operations
    class_type& write()
    {
        return write_(NULL, 0);
    }

    template <typename T_String>
    class_type& write(T_String const& s)
    {
        return write_(stlsoft::c_str_data_a(s), stlsoft::c_str_len_a(s));
    }

    class_type& write_line()
    {
        return write_line_(NULL, 0);
    }

    template <typename T_String>
    class_type& write_line(T_String const& line)
    {
        return write_line_(stlsoft::c_str_data_a(line), stlsoft::c_str_len_a(line));
    }

    template <typename T_Collection>
    class_type& write_lines(T_Collection const& lines)
    {
        { for(ss_typename_type_k T_Collection::const_iterator i = lines.begin(); i != lines.end(); ++i)
        {
            write_line_(*i);
        }}

        return *this;
    }

    void rewind_for_read()
    {
        seek_or_throw_(0, SEEK_SET);
    }

public: // Accessors
    FILE* get()
    {
        return parent_class_type::get();
    }

private: // Implementation
    class_type& write_(
        char const* s
    ,   size_t      n
    )
    {
        STLSOFT_ASSERT(NULL != s || 0 == n);

        if( 0 != n &&
            n != ::fwrite(s, sizeof(char), n, parent_class_type::get()))
        {
            throw_("could not write", errno);
        }

        return *this;
    }

    class_type& write_line_(
        char const* s
    ,   size_t      n
    )
    {
        STLSOFT_ASSERT(NULL != s || 0 == n);

        if(0 == n)
        {
            return write_("\n", 1u);
        }
        else
        {
            stlsoft::auto_buffer<char> buff(1 + n);

            ::memcpy(&buff[0], s, sizeof(char) * n);
            buff[n] = '\n';

            return write_(buff.data(), n + 1);
        }

        return *this;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace util */
} /* namespace test */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_STD_HPP_INPUT_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
