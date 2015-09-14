/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/file_creation_functions.h
 *
 * Purpose:     File creation functions.
 *
 * Created:     12th September 2005
 * Updated:     28th August 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2010, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/filesystem/file_creation_functions.h
 *
 * \brief [C, C++] File creation functions
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_MAJOR      3
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_MINOR      0
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_REVISION   2
# define WINSTL_VER_WINSTL_H_FILE_CREATION_FUNCTIONS_EDIT       16
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(_WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(_STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE HANDLE winstl_C_file_call_CreateFile_a_(
    LPCSTR                  path
,   DWORD                   desiredAccess
,   DWORD                   shareMode
,   LPSECURITY_ATTRIBUTES   securityAttributes
,   DWORD                   creationDisposition
,   DWORD                   flagsAndAttributes
,   HANDLE                  templateFile
) stlsoft_throw_0()
{
    WINSTL_ASSERT(
        CREATE_NEW          == creationDisposition ||
        CREATE_ALWAYS       == creationDisposition ||
        OPEN_EXISTING       == creationDisposition ||
        OPEN_ALWAYS         == creationDisposition ||
        TRUNCATE_EXISTING   == creationDisposition
    );

    return STLSOFT_NS_GLOBAL(CreateFileA)(path, desiredAccess, shareMode, securityAttributes, creationDisposition, flagsAndAttributes, templateFile);
}

STLSOFT_INLINE HANDLE winstl_C_file_call_CreateFile_w_(
    LPCWSTR                 path
,   DWORD                   desiredAccess
,   DWORD                   shareMode
,   LPSECURITY_ATTRIBUTES   securityAttributes
,   DWORD                   creationDisposition
,   DWORD                   flagsAndAttributes
,   HANDLE                  templateFile
) stlsoft_throw_0()
{
    WINSTL_ASSERT(
        CREATE_NEW          == creationDisposition ||
        CREATE_ALWAYS       == creationDisposition ||
        OPEN_EXISTING       == creationDisposition ||
        OPEN_ALWAYS         == creationDisposition ||
        TRUNCATE_EXISTING   == creationDisposition
    );

    return STLSOFT_NS_GLOBAL(CreateFileW)(path, desiredAccess, shareMode, securityAttributes, creationDisposition, flagsAndAttributes, templateFile);
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** A short-cut for <code>CreateFileA()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
STLSOFT_INLINE HANDLE winstl_C_file_create_file_a(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
) stlsoft_throw_0()
{
    return winstl_C_file_call_CreateFile_a_(path, desiredAccess, shareMode, NULL, creationDisposition, flagsAndAttributes, NULL);
}

/** A short-cut for <code>CreateFileW()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
STLSOFT_INLINE HANDLE winstl_C_file_create_file_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
) stlsoft_throw_0()
{
    return winstl_C_file_call_CreateFile_w_(path, desiredAccess, shareMode, NULL, creationDisposition, flagsAndAttributes, NULL);
}

/** Creates a file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
STLSOFT_INLINE HANDLE winstl_C_file_create_always_a(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) stlsoft_throw_0()
{
    return winstl_C_file_call_CreateFile_a_(path, desiredAccess, shareMode, NULL, CREATE_ALWAYS, flagsAndAttributes, NULL);
}

/** Creates a file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
STLSOFT_INLINE HANDLE winstl_C_file_create_always_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) stlsoft_throw_0()
{
    return winstl_C_file_call_CreateFile_w_(path, desiredAccess, shareMode, NULL, CREATE_ALWAYS, flagsAndAttributes, NULL);
}

/** Opens an existing file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
STLSOFT_INLINE HANDLE winstl_C_file_open_existing_a(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) stlsoft_throw_0()
{
    return winstl_C_file_call_CreateFile_a_(path, desiredAccess, shareMode, NULL, OPEN_EXISTING, flagsAndAttributes, NULL);
}

/** Opens an existing file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
STLSOFT_INLINE HANDLE winstl_C_file_open_existing_w(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
) stlsoft_throw_0()
{
    return winstl_C_file_call_CreateFile_w_(path, desiredAccess, shareMode, NULL, OPEN_EXISTING, flagsAndAttributes, NULL);
}

#ifdef __cplusplus

/** A short-cut for <code>CreateFile()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE winstl_C_file_create_file(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_file_a(path, desiredAccess, shareMode, creationDisposition, flagsAndAttributes);
}

/** A short-cut for <code>CreateFile()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE winstl_C_file_create_file(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_file_w(path, desiredAccess, shareMode, creationDisposition, flagsAndAttributes);
}

/** Creates a file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE winstl_C_file_create_always(
    LPCSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_always_a(path, desiredAccess, shareMode, flagsAndAttributes);
}

/** Creates a file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE winstl_C_file_create_always(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_always_w(path, desiredAccess, shareMode, flagsAndAttributes);
}

/** Opens an existing file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE winstl_C_file_open_existing(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_open_existing_a(path, desiredAccess, shareMode, flagsAndAttributes);
}

/** Opens an existing file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE winstl_C_file_open_existing(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_open_existing_w(path, desiredAccess, shareMode, flagsAndAttributes);
}

#else /* ? __cplusplus */

# ifdef UNICODE
#  define winstl_C_create_file          winstl_C_create_file_w
#  define winstl_C_file_create_always   winstl_C_file_create_always_w
#  define winstl_C_file_open_existing   winstl_C_file_open_existing_w
# else /* ? UNICODE */
#  define winstl_C_create_file          winstl_C_create_file_a
#  define winstl_C_file_create_always   winstl_C_file_create_always_a
#  define winstl_C_file_open_existing   winstl_C_file_open_existing_a
# endif /* UNICODE */

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Obsolete functions
 */

#ifdef STLSOFT_OBSOLETE

/*
 * \ingroup group__library__filesystem
 */
STLSOFT_INLINE HANDLE winstl__open_file_read_shared_a(ws_char_a_t const* fileName, DWORD dwShareMode)
{
    return STLSOFT_NS_GLOBAL(CreateFileA)(fileName, GENERIC_READ, dwShareMode, NULL, OPEN_ALWAYS, 0, NULL);
}
/*
 * \ingroup group__library__filesystem
 */
STLSOFT_INLINE HANDLE winstl__open_file_read_shared_w(ws_char_w_t const* fileName, DWORD dwShareMode)
{
    return STLSOFT_NS_GLOBAL(CreateFileW)(fileName, GENERIC_READ, dwShareMode, NULL, OPEN_ALWAYS, 0, NULL);
}
/*
 * \ingroup group__library__filesystem
 */
STLSOFT_INLINE HANDLE winstl__open_file_exclusive_a(ws_char_a_t const* fileName)
{
    return STLSOFT_NS_GLOBAL(CreateFileA)(fileName, GENERIC_READ, 0, NULL, OPEN_ALWAYS, 0, NULL);
}
/*
 * \ingroup group__library__filesystem
 */
STLSOFT_INLINE HANDLE winstl__open_file_exclusive_w(ws_char_w_t const* fileName)
{
    return STLSOFT_NS_GLOBAL(CreateFileW)(fileName, GENERIC_READ, 0, NULL, OPEN_ALWAYS, 0, NULL);
}

#endif /* STLSOFT_OBSOLETE */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifdef STLSOFT_DOCUMENTATION_SKIP_SECTION
namespace winstl
{
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

/** A short-cut for <code>CreateFile()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE file_create_file(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_file(path, desiredAccess, shareMode, creationDisposition, flagsAndAttributes);
}

/** A short-cut for <code>CreateFile()</code> that does not require the
 * security attributes or template file parameters.
 *
 * \param path The path - relative or absolute - of the file to be created/opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param creationDisposition The creation/open action to be performed.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE file_create_file(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   creationDisposition
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_file(path, desiredAccess, shareMode, creationDisposition, flagsAndAttributes);
}

/** Creates a file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE file_create_always(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_always(path, desiredAccess, shareMode, flagsAndAttributes);
}

/** Creates a file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be created.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE file_create_always(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_create_always(path, desiredAccess, shareMode, flagsAndAttributes);
}

/** Opens an existing file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE file_open_existing(
    LPCSTR  path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_open_existing(path, desiredAccess, shareMode, flagsAndAttributes);
}

/** Opens an existing file, according to the given access, share and flags parameters.
 *
 * \param path The path - relative or absolute - of the file to be opened.
 * \param desiredAccess The desired file access.
 * \param shareMode The share mode.
 * \param flagsAndAttributes Flags and attributes that affect the operation and/or the file.
 */
inline HANDLE file_open_existing(
    LPCWSTR path
,   DWORD   desiredAccess
,   DWORD   shareMode
,   DWORD   flagsAndAttributes
)
{
    return winstl_C_file_open_existing(path, desiredAccess, shareMode, flagsAndAttributes);
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Obsolete functions
 */

#ifdef STLSOFT_OBSOLETE
# ifdef __cplusplus

/*
 * \ingroup group__library__filesystem
 */
inline HANDLE open_file_read_shared(ws_char_a_t const* fileName, DWORD dwShareMode)
{
    return winstl__open_file_read_shared_a(fileName, dwShareMode);
}
/*
 * \ingroup group__library__filesystem
 */
inline HANDLE open_file_read_shared(ws_char_w_t const* fileName, DWORD dwShareMode)
{
    return winstl__open_file_read_shared_w(fileName, dwShareMode);
}
/*
 * \ingroup group__library__filesystem
 */
inline HANDLE open_file_exclusive(ws_char_a_t const* fileName)
{
    return winstl__open_file_exclusive_a(fileName);
}
/*
 * \ingroup group__library__filesystem
 */
inline HANDLE open_file_exclusive(ws_char_w_t const* fileName)
{
    return winstl__open_file_exclusive_w(fileName);
}

# endif /* __cplusplus */
#endif /* STLSOFT_OBSOLETE */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_H_FILE_CREATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
