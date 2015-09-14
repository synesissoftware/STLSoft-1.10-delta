/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/file_size_functions.h
 *
 * Purpose:     File-system size functions
 *
 * Created:     13th May 2010
 * Updated:     13th October 2010
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

/** \file winstl/filesystem/file_size_functions.h
 *
 * \brief [C, C++] File-system size functions.
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_FILE_SIZE_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_H_FILE_SIZE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_H_FILE_SIZE_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_FILESYSTEM_H_FILE_SIZE_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_FILESYSTEM_H_FILE_SIZE_FUNCTIONS_REVISION    6
# define WINSTL_VER_WINSTL_FILESYSTEM_H_FILE_SIZE_FUNCTIONS_EDIT        9
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS
# include <winstl/filesystem/file_seek_functions.h>
#endif /* !WINSTL_INCL_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS */

#ifdef __cplusplus
# ifndef WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_OS_FILE_HANDLE
#  include <winstl/shims/attribute/get_os_file_handle.hpp>
# endif /* !WINSTL_INCL_WINSTL_SHIMS_ATTRIBUTE_HPP_GET_OS_FILE_HANDLE */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{
namespace winstl_project
{

# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions (C)
 */

#if 0
winstl_C_file_get_size_by_handle_32()
winstl_C_file_get_size_by_handle_64()
winstl_C_file_set_size_by_handle_32()
winstl_C_file_set_size_by_handle_64()
winstl_C_file_set_size_by_name_a()
winstl_C_file_set_size_by_name_w()
winstl_C_file_get_size_by_name_32_a()
winstl_C_file_get_size_by_name_32_w()
winstl_C_file_get_size_by_name_64_a()
winstl_C_file_get_size_by_name_64_w()

winstl_C_file_set_size_by_name()
winstl_C_file_get_size_by_name_32()
winstl_C_file_get_size_by_name_64()

file_get_size_by_handle_32()
file_get_size_by_handle_64()
file_get_size_by_name_32()
file_get_size_by_name_64()
file_set_size_by_handle_32()
file_set_size_by_handle_64()
file_set_size()
#endif /* 0 */

/** Gets the size of the file, as two 32-bit unsigned integer values.
 *
 * \param hFile The file whose size is to be elicited.
 * \param sizeLo Pointer to a variable that will receive the low 32-bits of
 *   the file size. May not be NULL.
 * \param sizeHi Pointer to a variable that will receive the high 32-bits of
 *   the file size. May not be NULL.
 *
 * \return !0 The function succeeded.
 * \return 0 The function failed. Extended error information is obtained
 *   via <code>GetLastError()</code>.
 *
 * \pre (INVALID_HANDLE_VALUE != hFile)
 * \pre (NULL != sizeLo) && (NULL != sizeHi)
 */
STLSOFT_INLINE BOOL winstl_C_file_get_size_by_handle_32(
    HANDLE          hFile
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
) stlsoft_throw_0()
{
    DWORD   fileSizeHi;
    DWORD   fileSizeLo;

    WINSTL_ASSERT(NULL != sizeLo);
    WINSTL_ASSERT(NULL != sizeHi);

    fileSizeLo = STLSOFT_NS_GLOBAL(GetFileSize)(hFile, &fileSizeHi);

    if( INVALID_FILE_SIZE == fileSizeLo &&
        ERROR_SUCCESS != STLSOFT_NS_GLOBAL(GetLastError)())
    {
        return FALSE;
    }
    else
    {
        *sizeLo = fileSizeLo;
        *sizeHi = fileSizeHi;

        return TRUE;
    }
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** Gets the size of the file, as a single 64-bit unsigned integer value.
 *
 * \param hFile The file whose size is to be elicited.
 * \param size Pointer to a variable that will receive the file size. May
 *   not be NULL.
 *
 * \return !0 The function succeeded.
 * \return 0 The function failed. Extended error information is obtained
 *   via <code>GetLastError()</code>.
 *
 * \pre (INVALID_HANDLE_VALUE != hFile)
 * \pre (NULL != size)
 */
STLSOFT_INLINE BOOL winstl_C_file_get_size_by_handle_64(
    HANDLE          hFile
,   ws_uint64_t*    size
) stlsoft_throw_0()
{
    ws_uint32_t sizeLo;
    ws_uint32_t sizeHi;

    if(!winstl_C_file_get_size_by_handle_32(hFile, &sizeLo, &sizeHi))
    {
        return FALSE;
    }
    else
    {
        *size = sizeHi;
        *size <<= 32;
        *size += sizeLo;

        return TRUE;
    }
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

/** Sets the size of a file, as defined by two 32-bit unsigned integer
 * values.
 *
 * \param hFile The file whose size is to be set.
 * \param sizeLo The low 32-bits of the file size.
 * \param sizeHi The high 32-bits of the file size.
 *
 * \return !0 The function succeeded.
 * \return 0 The function failed. Extended error information is obtained
 *   via <code>GetLastError()</code>.
 *
 * \pre (INVALID_HANDLE_VALUE != hFile)
 */
STLSOFT_INLINE BOOL winstl_C_file_set_size_by_handle_32(
    HANDLE      hFile
,   ws_uint32_t sizeLo
,   ws_uint32_t sizeHi
) stlsoft_throw_0()
{
    return winstl_C_set_file_pointer_32(hFile, sizeLo, sizeHi) && STLSOFT_NS_GLOBAL(SetEndOfFile)(hFile);
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** Sets the size of a file, as a single 64-bit unsigned integer value.
 *
 * \param hFile The file whose size is to be set.
 * \param size The file size.
 *
 * \return !0 The function succeeded.
 * \return 0 The function failed. Extended error information is obtained
 *   via <code>GetLastError()</code>.
 *
 * \pre (INVALID_HANDLE_VALUE != hFile)
 */
STLSOFT_INLINE BOOL winstl_C_file_set_size_by_handle_64(
    HANDLE      hFile
,   ws_uint64_t size
) stlsoft_throw_0()
{
    return winstl_C_set_file_pointer_64(hFile, size) && STLSOFT_NS_GLOBAL(SetEndOfFile)(hFile);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
/** Sets the size of the named file.
 */
STLSOFT_INLINE BOOL winstl_C_file_set_size_by_name_a(
    ws_char_a_t const*  path
,   ws_uint64_t         size
,   DWORD               creationDisposition
) stlsoft_throw_0()
{
#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8013
#endif

    HANDLE hFile;

    WINSTL_ASSERT(
        CREATE_NEW          == creationDisposition ||
        CREATE_ALWAYS       == creationDisposition ||
        OPEN_EXISTING       == creationDisposition ||
        OPEN_ALWAYS         == creationDisposition ||
        TRUNCATE_EXISTING   == creationDisposition
    );

    hFile = STLSOFT_NS_GLOBAL(CreateFileA)(path, GENERIC_WRITE, 0, NULL, creationDisposition, 0, 0);

    if(INVALID_HANDLE_VALUE == hFile)
    {
        return FALSE;
    }
    else
    {
        BOOL    r   =   winstl_C_file_set_size_by_handle_64(hFile, size);
        DWORD   dw  =   STLSOFT_NS_GLOBAL(GetLastError)();

        STLSOFT_NS_GLOBAL(CloseHandle(hFile));

        if(!r)
        {
            STLSOFT_NS_GLOBAL(SetLastError)(dw);
        }

        return r;
    }

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn .8013
#endif
}

STLSOFT_INLINE DWORD winstl_C_file_set_size_by_name_w(
    ws_char_w_t const*  path
,   ws_uint64_t         size
,   DWORD               creationDisposition
) stlsoft_throw_0()
{
#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn -8013
#endif

    HANDLE hFile;

    WINSTL_ASSERT(
        CREATE_NEW          == creationDisposition ||
        CREATE_ALWAYS       == creationDisposition ||
        OPEN_EXISTING       == creationDisposition ||
        OPEN_ALWAYS         == creationDisposition ||
        TRUNCATE_EXISTING   == creationDisposition
    );

    hFile = STLSOFT_NS_GLOBAL(CreateFileW)(path, GENERIC_WRITE, 0, NULL, creationDisposition, 0, 0);

    if(INVALID_HANDLE_VALUE == hFile)
    {
        return FALSE;
    }
    else
    {
        BOOL    r   =   winstl_C_file_set_size_by_handle_64(hFile, size);
        DWORD   dw  =   STLSOFT_NS_GLOBAL(GetLastError)();

        STLSOFT_NS_GLOBAL(CloseHandle(hFile));

        if(!r)
        {
            STLSOFT_NS_GLOBAL(SetLastError)(dw);
        }

        return r;
    }

#if defined(STLSOFT_COMPILER_IS_BORLAND)
# pragma warn .8013
#endif
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

STLSOFT_INLINE BOOL winstl_C_file_get_size_by_name_32_a(
    ws_char_a_t const*  path
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
)
{
  WIN32_FIND_DATAA  data;
  HANDLE        hFind = STLSOFT_NS_GLOBAL(FindFirstFileA)(path, &data);

    WINSTL_ASSERT(NULL != sizeLo);
    WINSTL_ASSERT(NULL != sizeHi);

  if(INVALID_HANDLE_VALUE == hFind)
  {
    return FALSE;
  }
  else
  {
    STLSOFT_NS_GLOBAL(FindClose)(hFind);

    *sizeLo = data.nFileSizeLow;
    *sizeHi = data.nFileSizeHigh;

    return TRUE;
  }
}

STLSOFT_INLINE BOOL winstl_C_file_get_size_by_name_32_w(
    ws_char_w_t const*  path
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
)
{
  WIN32_FIND_DATAW  data;
  HANDLE        hFind = STLSOFT_NS_GLOBAL(FindFirstFileW)(path, &data);

    WINSTL_ASSERT(NULL != sizeLo);
    WINSTL_ASSERT(NULL != sizeHi);

  if(INVALID_HANDLE_VALUE == hFind)
  {
    return FALSE;
  }
  else
  {
    STLSOFT_NS_GLOBAL(FindClose)(hFind);

    *sizeLo = data.nFileSizeLow;
    *sizeHi = data.nFileSizeHigh;

    return TRUE;
  }
}

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_INLINE BOOL winstl_C_file_get_size_by_name_64_a(
    ws_char_a_t const*  path
,   ws_uint64_t*    size
)
{
  ws_uint32_t sizeLo;
  ws_uint32_t sizeHi;

  if(!winstl_C_file_get_size_by_name_32_a(path, &sizeLo, &sizeHi))
  {
    return FALSE;
  }
  else
  {
        *size = sizeHi;
        *size <<= 32;
        *size += sizeLo;

    return TRUE;
  }
}
STLSOFT_INLINE BOOL winstl_C_file_get_size_by_name_64_w(
    ws_char_w_t const*  path
,   ws_uint64_t*    size
)
{
  ws_uint32_t sizeLo;
  ws_uint32_t sizeHi;

  if(!winstl_C_file_get_size_by_name_32_w(path, &sizeLo, &sizeHi))
  {
    return FALSE;
  }
  else
  {
        *size = sizeHi;
        *size <<= 32;
        *size += sizeLo;

    return TRUE;
  }
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


#ifdef __cplusplus

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
inline DWORD winstl_C_file_set_size_by_name(
    ws_char_w_t const*  path
,   ws_uint64_t         size
,   DWORD               creationDisposition
) stlsoft_throw_0()
{
    return winstl_C_file_set_size_by_name_w(path, size, creationDisposition);
}
inline DWORD winstl_C_file_set_size_by_name(
    ws_char_a_t const*  path
,   ws_uint64_t         size
,   DWORD               creationDisposition
) stlsoft_throw_0()
{
    return winstl_C_file_set_size_by_name_a(path, size, creationDisposition);
}
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

inline BOOL winstl_C_file_get_size_by_name_32(
    ws_char_a_t const*  path
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
) stlsoft_throw_0()
{
  return winstl_C_file_get_size_by_name_32_a(path, sizeLo, sizeHi);
}
inline BOOL winstl_C_file_get_size_by_name_32(
    ws_char_w_t const*  path
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
) stlsoft_throw_0()
{
  return winstl_C_file_get_size_by_name_32_w(path, sizeLo, sizeHi);
}

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
inline BOOL winstl_C_file_get_size_by_name_64(
    ws_char_a_t const*  path
,   ws_uint64_t*    size
)
{
  return winstl_C_file_get_size_by_name_64_a(path, size);
}
inline BOOL winstl_C_file_get_size_by_name_64(
    ws_char_w_t const*  path
,   ws_uint64_t*    size
)
{
  return winstl_C_file_get_size_by_name_64_w(path, size);
}
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


#else /* ? __cplusplus */

# ifdef UNICODE
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
#   define winstl_C_file_set_size_by_name       winstl_C_file_set_size_by_name_w
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#  define winstl_C_file_get_size_by_name_32     winstl_C_file_get_size_by_name_32_w
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
#   define winstl_C_file_get_size_by_name_64  winstl_C_file_get_size_by_name_64_w
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
# else /* ? UNICODE */
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
#   define winstl_C_file_set_size_by_name       winstl_C_file_set_size_by_name_a
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
#  define winstl_C_file_get_size_by_name_32     winstl_C_file_get_size_by_name_32_a
#  ifdef STLSOFT_CF_64BIT_INT_SUPPORT
#   define winstl_C_file_get_size_by_name_64  winstl_C_file_get_size_by_name_64_a
#  endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
# endif /* UNICODE */

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Functions (C++)
 */

#ifdef __cplusplus

inline BOOL file_get_size_by_handle_32(
    HANDLE          hFile
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
)
{
    return winstl_C_file_get_size_by_handle_32(hFile, sizeLo, sizeHi);
}
template <ss_typename_param_k F>
inline BOOL file_get_size_by_handle_32(
    F&              file
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
)
{
    return winstl_C_file_get_size_by_handle_32(winstl_ns_qual(get_os_file_handle)(file), sizeLo, sizeHi);
}

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
inline BOOL file_get_size_by_handle_64(
    HANDLE          hFile
,   ws_uint64_t*    size
)
{
    return winstl_C_file_get_size_by_handle_64(hFile, size);
}
template <ss_typename_param_k F>
inline BOOL file_get_size_by_handle_64(
    F&              file
,   ws_uint64_t*    size
)
{
    return winstl_C_file_get_size_by_handle_64(winstl_ns_qual(get_os_file_handle)(file), size);
}
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

inline BOOL file_get_size_by_name_32(
    ws_char_a_t const*  path
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
)
{
    return winstl_C_file_get_size_by_name_32(path, sizeLo, sizeHi);
}
inline BOOL file_get_size_by_name_32(
    ws_char_w_t const*  path
,   ws_uint32_t*    sizeLo
,   ws_uint32_t*    sizeHi
)
{
    return winstl_C_file_get_size_by_name_32(path, sizeLo, sizeHi);
}
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
inline BOOL file_get_size_by_name_64(
    ws_char_a_t const*  path
,   ws_uint64_t*    size
)
{
    return winstl_C_file_get_size_by_name_64(path, size);
}
inline BOOL file_get_size_by_name_64(
    ws_char_w_t const*  path
,   ws_uint64_t*    size
)
{
    return winstl_C_file_get_size_by_name_64(path, size);
}
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

inline BOOL file_set_size_by_handle_32(
    HANDLE      hFile
,   ws_uint32_t sizeLo
,   ws_uint32_t sizeHi
)
{
    return winstl_C_file_set_size_by_handle_32(hFile, sizeLo, sizeHi);
}

template <ss_typename_param_k F>
inline BOOL file_set_size_by_handle_32(
    F&          file
,   ws_uint32_t sizeLo
,   ws_uint32_t sizeHi
)
{
    return winstl_C_file_set_size_by_handle_32(winstl_ns_qual(get_os_file_handle)(file), sizeLo, sizeHi);
}

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
inline BOOL file_set_size_by_handle_64(
    HANDLE      hFile
,   ws_uint64_t size
)
{
    return winstl_C_file_set_size_by_handle_64(hFile, size);
}

template <ss_typename_param_k F>
inline BOOL file_set_size_by_handle_64(
    F&          file
,   ws_uint64_t size
)
{
    return winstl_C_file_set_size_by_handle_64(winstl_ns_qual(get_os_file_handle)(file), size);
}

template <ss_typename_param_k S>
inline DWORD file_set_size(
    S const&    path
,   ws_uint64_t size
,   DWORD       creationDisposition = OPEN_EXISTING
)
{
    return winstl_C_file_set_size_by_name(stlsoft_ns_qual(c_str_ptr)(path), size, creationDisposition);
}
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_FILESYSTEM_H_FILE_SIZE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
