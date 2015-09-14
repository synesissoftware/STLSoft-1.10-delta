/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/test/util/files/std/output_FILE.hpp
 *
 * Purpose:     Definition of the stlsoft::test::util::output_FILE class.
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


#ifndef STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_STD_HPP_OUTPUT_FILE
#define STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_STD_HPP_OUTPUT_FILE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_STD_HPP_OUTPUT_FILE_MAJOR      1
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_STD_HPP_OUTPUT_FILE_MINOR      0
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_STD_HPP_OUTPUT_FILE_REVISION   4
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_STD_HPP_OUTPUT_FILE_EDIT       4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h>
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#include <stlsoft/filesystem/read_line.hpp>
#include <stlsoft/test/util/files/std/ximpl/base_FILE.hpp>

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

class output_FILE
    : private ximpl::base_FILE
{
public: // Member Types
    typedef output_FILE         class_type;
private:
    typedef ximpl::base_FILE    parent_class_type;

public: // Construction
    output_FILE()
        : parent_class_type()
    {}
private:
    output_FILE(class_type const&);
    class_type& operator =(class_type const&);

public: // Operations
    template <typename C>
    size_t rewind_and_read_lines(C& c)
    {
        seek_or_throw_(0, SEEK_SET);

        typedef ss_typename_type_k C::value_type string_t;

        size_t n = 0;

        { for(string_t line; stlsoft::read_line(parent_class_type::get(), line); ++n)
        {
            c.insert(c.end(), line);
        }}
        if(0 != ferror_())
        {
            throw_("read failed", errno);
        }

        return n;
    }

public: // Accessors
    FILE* get()
    {
        return parent_class_type::get();
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace util */
} /* namespace test */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_STD_HPP_OUTPUT_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
