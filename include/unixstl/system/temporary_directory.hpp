/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/system/temporary_directory.hpp
 *
 * Purpose:     Simple class that gets, and makes accessible, the UNIX
 *              temporary directory.
 *
 * Created:     18th May 2012
 * Updated:     10th May 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2012-2014, Matthew Wilson and Synesis Software
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


/** \file unixstl/system/temporary_directory.hpp
 *
 * \brief [C++ only] Definition of the unixstl::temporary_directory and
 *  associated types
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_TEMPORARY_DIRECTORY
#define UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_TEMPORARY_DIRECTORY

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_SYSTEM_HPP_TEMPORARY_DIRECTORY_MAJOR     1
# define UNIXSTL_VER_UNIXSTL_SYSTEM_HPP_TEMPORARY_DIRECTORY_MINOR     0
# define UNIXSTL_VER_UNIXSTL_SYSTEM_HPP_TEMPORARY_DIRECTORY_REVISION  2
# define UNIXSTL_VER_UNIXSTL_SYSTEM_HPP_TEMPORARY_DIRECTORY_EDIT      3
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE
# include <stlsoft/string/special_string_instance.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE */
#ifndef STLSOFT_INCL_UNIXSTL_MEMORY_HPP_NEW_ALLOCATOR
# include <stlsoft/memory/new_allocator.hpp>
#endif /* !STLSOFT_INCL_UNIXSTL_MEMORY_HPP_NEW_ALLOCATOR */
#ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_FEATURES
# include <unixstl/synch/util/features.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_UTIL_H_FEATURES */
#ifdef UNIXSTL_USING_PTHREADS
# ifndef UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX
#  include <unixstl/synch/spin_mutex.hpp>
# endif /* !UNIXSTL_INCL_UNIXSTL_SYNCH_HPP_SPIN_MUTEX */
#else /* ? UNIXSTL_USING_PTHREADS */

/* TODO: null_spin_mutex */

# include <stlsoft/synch/lock_scope.hpp>
# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
# endif /* !_STLSOFT_NO_NAMESPACE */

		struct unixstl_tempdir_spin_mutex_type
		{
		public: // Member Types
				typedef int			atomic_int_type;

		public: // X
				unixstl_tempdir_spin_mutex_type(atomic_int_type*)
				{}
		};

		STLSOFT_TEMPLATE_SPECIALISATION
		struct lock_traits<unixstl_tempdir_spin_mutex_type>
		{
		public:
		    typedef unixstl_tempdir_spin_mutex_type	lock_type;

		public:
		    static void lock(lock_type &c)
				{}
		    static void unlock(lock_type &c)
				{}
		};

# ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */

#endif /* UNIXSTL_USING_PTHREADS */
#ifndef UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <unixstl/system/system_traits.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */
#ifndef STLSOFT_INCL_H_STDIO
# define STLSOFT_INCL_H_STDIO
# include <stdio.h>
#endif /* !STLSOFT_INCL_H_STDIO */
#ifndef STLSOFT_INCL_H_STDLIB
# define STLSOFT_INCL_H_STDLIB
# include <stdlib.h>
#endif /* !STLSOFT_INCL_H_STDLIB */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{
namespace unixstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Sub-project namespace
 */

STLSOFT_OPEN_WORKER_NS_(system_policies)

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \ref group__pattern__special_string_instance "Special String Instance"
 *   policy template for eliciting a temporary directory.
 *
 * \ingroup group__library__system
 */
template <ss_typename_param_k C>
struct tempdir_policy
{
/// \name Member Types
/// @{
public:
    typedef C                                 char_type;
    typedef stlsoft_ns_qual(new_allocator)<C> allocator_type;
    typedef us_size_t                         size_type;
    typedef size_type                         (*pfn_type)(char_type *, size_type);
#ifdef UNIXSTL_USING_PTHREADS
    typedef unixstl::spin_mutex               spin_mutex_type;
    typedef unixstl::atomic_int_t             atomic_int_type;
#else /* ? UNIXSTL_USING_PTHREADS */
    typedef unixstl_tempdir_spin_mutex_type   spin_mutex_type;
    typedef spin_mutex_type::atomic_int_type  atomic_int_type;
#endif /* UNIXSTL_USING_PTHREADS */
/// @}

/// \name Member Constants
/// @{
public:
    enum { internalBufferSize       =   64  };

    enum { allowImplicitConversion  =   1   };

    enum { sharedState              =   0   };
/// @}

/// \name Operations
/// @{
public:
    static pfn_type get_fn()
    {
        return /* unixstl::system_traits<char_type>:: */get_temporary_directory;
    }
/// @}

/// \name Implementation
private:
    // TODO: move these into system_traits<>

    static size_type get_temporary_directory(us_char_a_t* buff, size_type cchBuff)
    {
#ifdef _WIN32
        char const* const tmpdir  =   ::getenv("TEMP");
#else
        char const* const tmpdir  =   ::getenv("TMPDIR");
#endif
        char const* const tempdir =   (NULL != tmpdir) ? tmpdir : "/tmp";
        us_size_t const   len     =   ::strlen(tempdir);

        if(0 == cchBuff)
        {
            return len;
        }
        else
        {
            us_size_t const n = (len < cchBuff) ? len : cchBuff;

            ::memcpy(buff, tempdir, sizeof(char) * n);

            if(n < cchBuff)
            {
                buff[n] = '\0';
            }

            return n;
        }
    }
    static size_type get_temporary_directory(us_char_w_t* buff, size_type cchBuff);
};

/* /////////////////////////////////////////////////////////////////////////
 * Sub-project namespace
 */

STLSOFT_CLOSE_WORKER_NS_(system_policies)

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs for commonly encountered types
 */

/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>Windows</b> directory; ANSI specialisation.
 *
 * \ingroup group__library__system
 */
typedef stlsoft_ns_qual(special_string_instance_0)<
    STLSOFT_WORKER_NS_QUAL_(system_policies, tempdir_policy)<
        us_char_a_t
    >
>                                                               temporary_directory_a;

/** A \ref group__pattern__special_string_instance "Special String Instance"
 *   that represents the <b>Windows</b> directory; 'Unicode' specialisation.
 *
 * \ingroup group__library__system
 */
typedef stlsoft_ns_qual(special_string_instance_0)<
    STLSOFT_WORKER_NS_QUAL_(system_policies, tempdir_policy)<
        us_char_w_t
    >
>                                                               temporary_directory_w;

/** 
 *
 * \ingroup group__library__system
 */
typedef temporary_directory_a                                   temporary_directory;

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _UNIXSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace unixstl
# else
} // namespace unixstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* UNIXSTL_INCL_UNIXSTL_SYSTEM_HPP_TEMPORARY_DIRECTORY */

/* ///////////////////////////// end of file //////////////////////////// */
