/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/FILE_stream.hpp
 *
 * Purpose:     Facade for the standard C Streams API.
 *
 * Created:     31st May 2009
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2009-2012, Matthew Wilson and Synesis Software
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


/** \file platformstl/filesystem/FILE_stream.hpp
 *
 * \brief [C++ only] Definition of the platformstl::thread_shareable_FILE_stream typedef
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MAJOR       1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MINOR       0
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_REVISION    8
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_EDIT        11
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
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
# include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_ATOMIC_TYPES
# include <platformstl/synch/atomic_types.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_H_ATOMIC_TYPES */
#ifndef STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_FILE_STREAM
# include <stlsoft/filesystem/FILE_stream.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_HPP_FILE_STREAM */

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
 * Typedefs
 */

/** A file stream whose underlying handle can be shared between threads.
 */
typedef stlsoft_ns_qual(FILE_stream_base)<
    refcount_policy_multi_threaded
,   atomic_int_t
>           thread_shareable_FILE_stream;

/* ////////////////////////////////////////////////////////////////////// */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace platformstl
#else
} // namespace platformstl_project
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM */

/* ///////////////////////////// end of file //////////////////////////// */
