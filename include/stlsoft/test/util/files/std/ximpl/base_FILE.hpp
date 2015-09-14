/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/test/util/files/std/ximpl/base_FILE.hpp
 *
 * Purpose:     Definition of the stlsoft::test::util::ximpl::base_FILE class.
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


#ifndef STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_XIMPL_STD_HPP_BASE_FILE
#define STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_XIMPL_STD_HPP_BASE_FILE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_XIMPL_STD_HPP_BASE_FILE_MAJOR      1
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_XIMPL_STD_HPP_BASE_FILE_MINOR      0
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_XIMPL_STD_HPP_BASE_FILE_REVISION   3
# define STLSOFT_VER_STLSOFT_TEST_UTIL_FILES_XIMPL_STD_HPP_BASE_FILE_EDIT       3
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

namespace ximpl
{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

class base_FILE
{
public: // Member Types
    typedef base_FILE  class_type;

public: // Construction
    base_FILE()
        : m_stm(open_temp_for_readwrite_or_throw_())
    {}
    ~base_FILE() stlsoft_throw_0()
    {
        ::fclose(m_stm);
    }
private:
    base_FILE(class_type const&);
    class_type& operator =(class_type const&);

public: // Accessors
    FILE* get()
    {
        return m_stm;
    }

protected: // Implementation
    void throw_(
        char const* message
    ,   int         e
    )
    {
#ifdef _DEBUG
#else /* ? _DEBUG */
        throw ...;
#endif /* _DEBUG */
    }

    FILE* open_temp_for_readwrite_or_throw_()
    {
        FILE* stm = ::tmpfile();

        if(NULL == stm)
        {
            throw_("could not acquire temporary file", errno);
        }

        return stm;
    }

    void seek_or_throw_(long offset, int whence)
    {
        if(0 != ::fseek(m_stm, offset, whence))
        {
            throw_("could not seek", errno);
        }
    }

    int ferror_()
    {
        return ferror(m_stm);
    }

private: // Fields
    FILE* const m_stm;
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace ximpl */
} /* namespace util */
} /* namespace test */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_TEST_UTIL_FILES_XIMPL_STD_HPP_BASE_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
