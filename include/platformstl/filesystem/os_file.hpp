/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/filesystem/os_file.hpp
 *
 * Purpose:     Facade for OS-specific file handling.
 *
 * Created:     7th July 2010
 * Updated:     30th August 2010
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


/** \file stlsoft/filesystem/os_file.hpp
 *
 * \brief [C++ only] Definition of the platformstl::os_file_base class
 *   template, and the platformstl::os_file and 
 *   platformstl::thread_shareable_os_file specialisation typedefs
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_OS_FILE
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_OS_FILE

#ifndef PLATFORMSTL_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_OS_FILE_MAJOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_OS_FILE_MINOR       0
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_OS_FILE_REVISION    1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_OS_FILE_EDIT        2
#endif /* !PLATFORMSTL_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <platformstl/platformstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# include <platformstl/platformstl.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
# include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS
# include <platformstl/filesystem/filesystem_traits.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILESYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED
# include <stlsoft/synch/refcount_policies/refcount_policy_single_threaded.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE
# include <platformstl/filesystem/handles/os_file_handle.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE */
#if 0
#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_EXCEPTIONS
# include <stlsoft/exception/exceptions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_EXCEPTIONS */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING
# include <stlsoft/shims/access/string/std/c_string.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_STD_H_C_STRING */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR
# include <stlsoft/shims/attribute/get_FILE_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_FILE_PTR */
#ifndef STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR
# include <stlsoft/internal/safestr.h>
#endif /* !STLSOFT_INCL_STLSOFT_INTERNAL_H_SAFESTR */
#endif /* 0 */

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

/** Handle::Ref+<b>Wrapper</b> wrapper class
 *
 */
template <ss_typename_param_k R>
class os_file_base
{
private: // Member Types
    typedef R                                                           refcount_policy_type_;
public:
    /// This type
    typedef os_file_base<R>                                             class_type;

    /// The Handle::Ref+Wrapper <strong>HandleAdaptor</strong> type
    typedef os_file_handle<
        refcount_policy_type_
    >                                                                   HRW_HandleAdaptor_type;
    /// The Handle::Ref+Wrapper <strong>Handle</strong> type
    typedef ss_typename_type_k HRW_HandleAdaptor_type::HRW_Handle_type  HRW_Handle_type;
    /// The Handle::Ref+Wrapper <strong>Ref</strong> type
    typedef ss_typename_type_k HRW_HandleAdaptor_type::Ref              HRW_Ref_type;
    /// The Handle::Ref+Wrapper <strong>Wrapper</strong> type: this type
    typedef class_type                                                  HRW_Wrapper_type;

    typedef HRW_Handle_type                                             Handle;
    typedef HRW_Ref_type                                                Ref;
    typedef HRW_Wrapper_type                                            Wrapper;

public: // Construction
    /// Creates an instance of the class opened over a file stream for the
    /// given \c path, according to the given \c mode.
    template <typename S1, typename S2>
    os_file_base(S1 const& path, S2 const& mode)
        : m_ref(init_(stlsoft_ns_qual(c_str_ptr)(path), stlsoft_ns_qual(c_str_ptr)(mode)))
    {}
    /// Copy constructor
    os_file_base(class_type const& rhs)
        : m_ref(rhs.m_ref)
    {}

    /// Returns the Handle::Ref+Wrapper <strong>ref</strong>, which
    /// encapsulates a shared file stream handle.
    Ref get() const stlsoft_throw_0()
    {
        return m_ref;
    }

public: // Operations
    /// Writes the given string and the end-of-line character
    /// <code>'\n'</code> to the underlying file stream.
    ///
    /// \note The line is combined with the end-of-line character before
    ///   passing to the underlying <code>fwrite()</code> operation. In
    ///   cases where <code>fwrite()</code> is implemented to write
    ///   atomically to the underlying file, the line and character will be
    ///   written in a single operation.
    template <typename S>
    class_type& write_line(S const& line)
    {
        return write_line_(stlsoft_ns_qual(c_str_data)(line), stlsoft_ns_qual(c_str_len)(line));
    }
    /// Writes an empty line to the underlying stream.
    class_type& write_line()
    {
        return write_line_(NULL, 0u);
    }
    /// Writes the given string to the underlying stream.
    template <typename S>
    class_type& write(S const& text)
    {
        return write_(stlsoft_ns_qual(c_str_data)(text), stlsoft_ns_qual(c_str_len)(text));
    }

    /// Writes \c n bytes from the memory block pointed to by \c pv to the
    /// underlying file stream.
    class_type& write(void const* pv, size_t n)
    {
      return write_bytes_(pv, n);
    }

    /// Causes any buffered output to be emitted to the underlying file
    /// stream.
    void flush()
    {
        if(0 != ::fflush(m_ref->handle))
        {
            report_nonnormative_("failed to flush", errno);
        }
    }

    /// Seeks the underlying file stream pointer to an absolute position.
    void seek_from_start(long offset)
    {
        seek_(offset, SEEK_SET);
    }

    /// Seeks the underlying file stream pointer relative to the current
    /// position.
    void seek_relative(long offset)
    {
        seek_(offset, SEEK_CUR);
    }

    /// Seeks the underlying file stream pointer relative to the given
    /// origin.
    void seek_from(long offset, int origin)
    {
        seek_(offset, origin);
    }

    /// Elicits the current file stream pointer position.
    long tell() const
    {
        long pos = ::ftell(m_ref->handle);

        if(-1l == pos)
        {
            report_nonnormative_("failed to tell file position", errno);
        }

        return pos;
    }

private: // Implementation
    static Ref init_(char const* path, char const* mode)
    {
#if defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) && \
    defined(STLSOFT_COMPILER_IS_MSVC)
        FILE* handle;
        int   e = ::fopen_s(&handle, path, mode);

        if(0 != e)
        {
#else // }
        FILE* handle = ::fopen(path, mode);

        if(NULL == handle)
        {
            int e = errno;
#endif

            report_nonnormative_("failed to open/create file", path, e);
        }

        try
        {
            return handle_type_::create(handle);
        }
        catch(...)
        {
            handle_type_::destroy(handle);

            throw;
        }
    }
    static Ref init_(wchar_t const* path, wchar_t const* mode)
    {
#if defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) && \
    defined(STLSOFT_COMPILER_IS_MSVC)
        FILE* handle;
        int   e = ::_wfopen_s(&handle, path, mode);

        if(0 != e)
        {
#else // }
        FILE* handle = ::_wfopen(path, mode);

        if(NULL == handle)
        {
            int e = errno;
#endif

            report_nonnormative_("failed to open/create file", path, e);
        }

        try
        {
            return handle_type_::create(handle);
        }
        catch(...)
        {
            handle_type_::destroy(handle);

            throw;
        }
    }

    class_type& write_line_(char const* s, size_t len)
    {
        stlsoft_ns_qual(auto_buffer)<char>  buff(2u + len);

        ::memcpy(&buff[0], s, sizeof(char) * len);
        buff[len + 0] = '\n';
        buff[len + 1] = '\0';

        return write_(buff.data(), 1u + len);
    }

    class_type& write_(char const* s, size_t len)
    {
        size_t n = ::fwrite(s, sizeof(char), len, m_ref->handle);

        if(n < len)
        {
            report_nonnormative_("failed to write to file", errno);
        }

        return *this;
    }

    class_type& write_bytes_(void const* pv, size_t cb)
    {
        size_t n = ::fwrite(pv, sizeof(byte_t), cb, m_ref->handle);

        if(n < cb)
        {
            report_nonnormative_("failed to write to file", errno);
        }

        return *this;
    }

    void seek_(long offset, int origin)
    {
        if(0 != ::fseek(m_ref->handle, offset, origin))
        {
            report_nonnormative_("failed to seek", errno);
        }
    }

    static void report_nonnormative_(char const* message, int e)
    {
        switch(e)
        {
            case    ENOMEM:
                throw stlsoft_ns_qual(out_of_memory_exception)(e);
            case    ENOENT:
                throw stlsoft_ns_qual(file_not_found_exception)(message, e);
            case    EACCES:
                throw stlsoft_ns_qual(access_denied_exception)(message, e);
            default:
                throw stlsoft_ns_qual(filesystem_exception)(message, e);
        }
    }

    static void report_nonnormative_(char const* message, char const* path, int e)
    {
        switch(e)
        {
            case    ENOMEM:
                throw stlsoft_ns_qual(out_of_memory_exception)(e);
            case    ENOENT:
                throw stlsoft_ns_qual(file_not_found_exception)(message, e, path);
            case    EACCES:
                throw stlsoft_ns_qual(access_denied_exception)(message, e, path);
            default:
                throw stlsoft_ns_qual(filesystem_exception)(message, e, path);
        }
    }

    static void report_nonnormative_(char const* message, wchar_t const* path, int e);
#if 0
    static void report_nonnormative_(char const* message, wchar_t const* path, int e)
    {
        if( NULL == path ||
            '\0' == path[0])
        {
            report_nonnormative_(message, static_cast<char const*>(NULL), e);
        }
        else
        {
            // NOTE: 
        }
    }
#endif /* 0 */

private: // Member Variables
    Ref m_ref;
};

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** A file stream suitable for manipulating files from a single thread.
 */
typedef os_file_base<refcount_policy_single_threaded>   os_file;

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/** Elicits a file-stream handle (<code>FILE*</code>) from the given
 * instance.
 */
template <ss_typename_param_k R>
inline FILE* get_FILE_ptr(os_file_base<R>& file)
{
    file::Ref r = file.get();

    return (NULL != r.get()) ? r->handle : NULL;
}

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_OS_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
