/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/filesystem/handles/FILE_stream_handle.hpp
 *
 * Purpose:     Handle::Ref+Wrapper handle-adapter class template for FILE
 *              streams.
 *
 * Created:     31st May 2009
 * Updated:     9th July 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2009-2010, Matthew Wilson and Synesis Software
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


/** \file stlsoft/filesystem/handles/FILE_stream_handle.hpp
 *
 * \brief [C++ only] Definition of the platformstl::FILE_stream_handle class
 *   template (\ref group__library__filesystem "File System" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE
#define STLSOFT_INCL_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE_MAJOR    1
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE_MINOR    0
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE_REVISION 5
# define STLSOFT_VER_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE_EDIT     10
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
#ifndef STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR
# include <stlsoft/smartptr/ref_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SMARTPTR_HPP_REF_PTR */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** A Handle::Ref+Wrapper handle class template for FILE streams
 */
template<
    ss_typename_param_k R
,   ss_typename_param_k I = int
>
struct FILE_stream_handle
{
public: // Member Types
    /// The handle type
    typedef FILE*                           handle_type;
    /// The reference count policy type
    typedef R                               refcount_policy;
    /// The reference count integer type
    typedef I                               refcount_integer_type;
    /// This type
    typedef FILE_stream_handle<R, I>        class_type;
    /// The Handle::Ref+Wrapper <strong>Ref</strong> type
    typedef stlsoft::ref_ptr<class_type>    Ref;

public: // Construction

    /// Creates an instance of the ref from the underlying 
    static Ref create(handle_type h)
    {
        return Ref(new class_type(h, true), false);
    }
    /// Destroys an instance of the underlying handle type
    static void destroy(handle_type h)
    {
        ::fclose(h);
    }

private:
    FILE_stream_handle(handle_type h, bool isOwner)
        : handle(h)
        , refCount(1)
        , isOwner(isOwner)
    {}
private:
    class_type& operator =(class_type const &);

public: // Reference-counting Operations
    /// Adds/increment the reference
    FILE_stream_handle* AddRef()
    {
        refcount_policy::addref(refCount);

        return this;
    }

    /// Releases/decrements the reference
    void Release()
    {
        if(0 == refcount_policy::release(refCount))
        {
            if(isOwner)
            {
                destroy(handle);
            }
            delete this;
        }
    }

public: // Member Variables
    /// The handle value
    handle_type             handle;
private:
    refcount_integer_type   refCount;
    const bool              isOwner;
};

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/** Elicits a file-stream handle (<code>FILE*</code>) from the given
 * instance.
 */
template<
    ss_typename_param_k R
,   ss_typename_param_k I
>
inline FILE* get_FILE_ptr(FILE_stream_handle<R, I>& h)
{
    return h.handle;
}

/** Elicits a file-stream handle (<code>FILE*</code>) from the given
 * instance.
 */
template<
    ss_typename_param_k R
,   ss_typename_param_k I
>
inline FILE* get_FILE_ptr(FILE_stream_handle<R, I>* h)
{
    return (NULL != h) ? h->handle : NULL;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_HANDLES_HPP_FILE_STREAM_HANDLE */

/* ///////////////////////////// end of file //////////////////////////// */
