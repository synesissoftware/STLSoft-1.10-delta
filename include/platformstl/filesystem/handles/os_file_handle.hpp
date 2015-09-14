/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/handles/os_file_handle.hpp
 *
 * Purpose:     Handle::Ref+Wrapper handle-adapter class template for
 *              os-specific file handles.
 *
 * Created:     7th July 2010
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


/** \file platformstl/filesystem/handles/os_file_handle.hpp
 *
 * \brief [C++ only] Definition of the platformstl::os_file_handle
 *  class template
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE_MAJOR    1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE_MINOR    0
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE_REVISION 1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE_EDIT     2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_PLATFORMSTL */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE
#  include <unixstl/filesystem/handles/os_file_handle.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# ifndef WINSTL_INCL_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE
#  include <winstl/filesystem/handles/os_file_handle.hpp>
# endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE */
#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310
# ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
#  include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
# endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */
# ifndef STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED
#  include <stlsoft/synch/refcount_policies/refcount_policy_single_threaded.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if defined(_STLSOFT_NO_NAMESPACE) || \
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
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)

    /** \brief Traits class for file-system operations.
     *
     * \ingroup group__library__filesystem
     *
     * The class is not actually defined in the
     * \link ::platformstl platformstl\endlink namespace. Rather, it
     * resolves to the appropriate type for the given platform, relying on
     * \ref section__principle__conformance__intersecting_conformance "Intersecting Conformance"
     * of the resolved platform-specific types.
     *
     * When compiling on UNIX platforms, the platformstl::os_file_handle
     * type resolves to the unixstl::os_file_handle class template. On Windows
     * platforms it resolves to the winstl::os_file_handle class template. It
     * is not defined for other platforms.
     */
    template <ss_typename_param_k R>
    class os_file_handle
    {};

#elif defined(PLATFORMSTL_OS_IS_UNIX)

    // Because early incarnations of Visual C++ are pretty stupid, we need to
    // work around their inability to introduce a template via using by
    // defining and deriving here

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER < 1310

    template <ss_typename_param_k R>
    struct os_file_handle;

    STLSOFT_TEMPLATE_SPECIALISATION
    struct os_file_handle<stlsoft_ns_qual(refcount_policy_single_threaded)>
        : public unixstl_ns_qual(os_file_handle)<stlsoft_ns_qual(refcount_policy_single_threaded)>
    {};

    STLSOFT_TEMPLATE_SPECIALISATION
    struct os_file_handle<refcount_policy_multi_threaded>
        : public unixstl_ns_qual(os_file_handle)<refcount_policy_multi_threaded>
    {};

# else /* ? compiler */

#  ifdef _UNIXSTL_NO_NAMESPACE
    using ::os_file_handle;
#  else /* ? _UNIXSTL_NO_NAMESPACE */
    using ::unixstl::os_file_handle;
#  endif /* _UNIXSTL_NO_NAMESPACE */
# endif /* compiler */

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    // Because early incarnations of Visual C++ are pretty stupid, we need to
    // work around their inability to introduce a template via using by
    // defining and deriving here

# if defined(STLSOFT_COMPILER_IS_MSVC) && 0 && \
     _MSC_VER < 1310

    template <ss_typename_param_k R>
    struct os_file_handle;

    STLSOFT_TEMPLATE_SPECIALISATION
    struct os_file_handle<stlsoft_ns_qual(refcount_policy_single_threaded)>
        : public winstl_ns_qual(os_file_handle)<stlsoft_ns_qual(refcount_policy_single_threaded)>
    {};

    STLSOFT_TEMPLATE_SPECIALISATION
    struct os_file_handle<refcount_policy_multi_threaded>
        : public winstl_ns_qual(os_file_handle)<refcount_policy_multi_threaded>
    {};

# else /* ? compiler */

#  ifdef _WINSTL_NO_NAMESPACE
    using ::os_file_handle;
#  else /* ? _WINSTL_NO_NAMESPACE */
    using ::winstl::os_file_handle;
#  endif /* _WINSTL_NO_NAMESPACE */

# endif /* compiler */

#else /* ? operating system */
# error Operating system not discriminated
#endif /* operating system */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(_STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_OS_FILE_HANDLE */

/* ///////////////////////////// end of file //////////////////////////// */
