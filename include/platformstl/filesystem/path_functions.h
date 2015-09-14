/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/path_functions.h
 *
 * Purpose:     Path manipulation functions.
 *
 * Created:     3rd February 2011
 * Updated:     23rd August 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2011-2015, Matthew Wilson and Synesis Software
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


/** \file platformstl/filesystem/path_functions.h
 *
 * \brief [C++ only] Path manipulation functions
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS

#ifndef PLATFORMSTL_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS_MAJOR    2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS_MINOR    1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS_REVISION 1
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_H_PATH_FUNCTIONS_EDIT     9
#endif /* !PLATFORMSTL_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <platformstl/platformstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# include <platformstl/platformstl.h>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */
#ifndef STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE
# include <stlsoft/string/string_slice.h>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_H_STRING_SLICE */

#ifndef STLSOFT_INCL_H_STRING
# define STLSOFT_INCL_H_STRING
# include <string.h>
#endif /* !STLSOFT_INCL_H_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(PLATFORMSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
# else
/* Define stlsoft::platformstl_project */
namespace stlsoft
{
namespace platformstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !PLATFORMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */


/** Gets a pointer to the executable name from the path
 *
 * \param path A full or partial path
 */
STLSOFT_INLINE
stlsoft_C_string_slice_a_t const
platformstl_C_get_executable_name_from_path(
    ss_char_a_t const* path
)
{
    if(NULL == path)
    {
#ifdef __cplusplus
        stlsoft_C_string_slice_a_t r;
#else /* ? __cplusplus */
        stlsoft_C_string_slice_a_t r = { 0, NULL };
#endif /* __cplusplus */

        return r;
    }
    else
    {
        stlsoft_C_string_slice_a_t  r;
        size_t const                cch     =   strlen(path);
        ss_char_a_t const*          slash   =   strrchr(path, '/');
#ifdef _WIN32
        ss_char_a_t const* const    bslash  =   strrchr(path, '\\');
        ss_char_a_t const*          dot;

        if(NULL == slash)
        {
            slash = bslash;
        }
        else
        {
            if(NULL != bslash)
            {
                if(slash < bslash)
                {
                    slash = bslash;
                }
            }
        }
#endif

        if(NULL != slash)
        {
            r.ptr = slash + 1;
        }
        else
        {
            r.ptr = path;
        }

#ifdef _WIN32
        dot = strrchr(r.ptr, '.');
        if(NULL != dot)
        {
            r.len = dot - r.ptr;
        }
        else
#endif
        {
            r.len = cch - (r.ptr - path);
        }

        return r;
    }
}

# if (   defined(WIN32) || \
        defined(WIN64)) && \
    (   defined(UNICODE) || \
        defined(_UNICODE))
STLSOFT_INLINE
stlsoft_C_string_slice_w_t const
platformstl_C_get_executable_name_from_path_w(
    ss_char_w_t const* path
)
{
    if(NULL == path)
    {
#ifdef __cplusplus
        stlsoft_C_string_slice_w_t r;
#else /* ? __cplusplus */
        stlsoft_C_string_slice_w_t r = { 0, NULL };
#endif /* __cplusplus */

        return r;
    }
    else
    {
        stlsoft_C_string_slice_w_t  r;
        size_t const                cch     =   wcslen(path);
        ss_char_w_t const*          slash   =   wcsrchr(path, '/');
#ifdef _WIN32
        ss_char_w_t const* const    bslash  =   wcsrchr(path, '\\');
        ss_char_w_t const*          dot;

        if(NULL == slash)
        {
            slash = bslash;
        }
        else
        {
            if(NULL != bslash)
            {
                if(slash < bslash)
                {
                    slash = bslash;
                }
            }
        }
#endif

        if(NULL != slash)
        {
            r.ptr = slash + 1;
        }
        else
        {
            r.ptr = path;
        }

        dot = wcsrchr(r.ptr, '.');
        if(NULL != dot)
        {
            r.len = dot - r.ptr;
        }
        else
        {
            r.len = cch - (r.ptr - path);
        }

        return r;
    }
}
# endif

/* /////////////////////////////////////////////////////////////////////////
 * C++ Functions
 */

#ifdef __cplusplus

inline
stlsoft_C_string_slice_a_t const
get_executable_name_from_path(
    ss_char_a_t const* path
)
{
    return platformstl_C_get_executable_name_from_path(path);
}

# if (   defined(WIN32) || \
        defined(WIN64)) && \
    (   defined(UNICODE) || \
        defined(_UNICODE))
inline
stlsoft_C_string_slice_w_t const
get_executable_name_from_path(
    ss_char_w_t const* path
)
{
    return platformstl_C_get_executable_name_from_path_w(path);
}
# endif

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef PLATFORMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
# else
} /* namespace platformstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !PLATFORMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_FILESYSTEM_H_PATH_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
