/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.platformstl.filesystem.os_file.cpp
 *
 * Purpose:     Implementation file for the test.scratch.platformstl.filesystem.os_file project.
 *
 * Created:     7th July 2010
 * Updated:     30th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


//#include <winstl/filesystem/handles/os_file_handle.hpp>
#include <platformstl/filesystem/os_file.hpp>
#include <winstl/filesystem/os_file.hpp>

#if 0
//# if defined(STLSOFT_COMPILER_IS_MSVC) && \
//     _MSC_VER < 1310
# ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
#  include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
# endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */
# ifndef STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED
#  include <stlsoft/synch/refcount_policies/refcount_policy_single_threaded.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_SINGLE_THREADED */
//#endif /* compiler */

    template <ss_typename_param_k R>
    struct os_file_handle;

  typedef winstl_ns_qual(os_file_handle)<stlsoft_ns_qual(refcount_policy_single_threaded)>  x_t;

    STLSOFT_TEMPLATE_SPECIALISATION
    struct os_file_handle<stlsoft_ns_qual(refcount_policy_single_threaded)>
        : public x_t
    {};

    STLSOFT_TEMPLATE_SPECIALISATION
  struct os_file_handle<platformstl::refcount_policy_multi_threaded>
        : public winstl_ns_qual(os_file_handle)<platformstl::refcount_policy_multi_threaded>
    {};
#endif /* 0 */


/* UNIXem Header Files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/unixem.h>
#endif /* Win32 || Win64 */

/* Standard C++ Header Files */
#include <exception>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#endif /* 0 */

/* Standard C Header Files */
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */


/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if 0
typedef std::string     string_t;
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    platformstl::os_file  file	=	winstl::os_file::create(::CreateFile("abc", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL));

	platformstl::os_file  file2	=	file;

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _DEBUG */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _DEBUG */

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        fputs("Unhandled unknown error\n", stderr);

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
