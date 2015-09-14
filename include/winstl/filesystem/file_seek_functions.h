/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/file_seek_functions.h
 *
 * Purpose:     File-system seek functions
 *
 * Created:     27th August 2010
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2010-2011, Matthew Wilson and Synesis Software
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

/** \file winstl/filesystem/file_seek_functions.h
 *
 * \brief [C, C++] File-system seek functions.
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS_REVISION    4
# define WINSTL_VER_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS_EDIT        4
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

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

STLSOFT_INLINE BOOL winstl_C_get_file_pointer_32(
    HANDLE          hFile
,   ws_uint32_t*    offsetLo
,   ws_uint32_t*    offsetHi
) stlsoft_throw_0()
{
    DWORD       distanceLo;
    LONG        distanceHi;

    WINSTL_ASSERT(NULL != offsetLo);
    WINSTL_ASSERT(NULL != offsetHi);

    distanceLo = STLSOFT_NS_GLOBAL(SetFilePointer)(hFile, 0, &distanceHi, FILE_CURRENT);

    if( INVALID_SET_FILE_POINTER == distanceLo &&
        ERROR_SUCCESS != STLSOFT_NS_GLOBAL(GetLastError()))
    {
        return FALSE;
    }
    else
    {
        *offsetLo = distanceLo;
        *offsetHi = stlsoft_static_cast(DWORD, distanceHi);

        return TRUE;
    }
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_INLINE BOOL winstl_C_get_file_pointer_64(
    HANDLE          hFile
,   ws_uint64_t*    offset
) stlsoft_throw_0()
{
    ws_uint32_t offsetLo;
    ws_uint32_t offsetHi;

    WINSTL_ASSERT(NULL != offset);

    if(!winstl_C_get_file_pointer_32(hFile, &offsetLo, &offsetHi))
    {
        return FALSE;
    }
    else
    {
        *offset = offsetHi;
        *offset <<= 32;
        *offset += offsetLo;

        return TRUE;
    }
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

STLSOFT_INLINE BOOL winstl_C_set_file_pointer_32(
    HANDLE      hFile
,   ws_uint32_t offsetLo
,   ws_uint32_t offsetHi
) stlsoft_throw_0()
{
    LONG    moveLow     =   stlsoft_static_cast(LONG, offsetLo);
    LONG    moveHigh    =   stlsoft_static_cast(LONG, offsetHi);
    DWORD   dw          =   STLSOFT_NS_GLOBAL(SetFilePointer)(hFile, moveLow, &moveHigh, FILE_BEGIN);

    if( INVALID_SET_FILE_POINTER == dw &&
        ERROR_SUCCESS != STLSOFT_NS_GLOBAL(GetLastError()))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_INLINE BOOL winstl_C_set_file_pointer_64(
    HANDLE      hFile
,   ws_uint64_t offset
) stlsoft_throw_0()
{
    ws_uint32_t offsetLo    =   stlsoft_static_cast(ws_uint32_t, offset >> 0);
    ws_uint32_t offsetHi    =   stlsoft_static_cast(ws_uint32_t, offset >> 32);

    return winstl_C_set_file_pointer_32(hFile, offsetLo, offsetHi);
}
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * Functions (C++)
 */

#ifdef __cplusplus

inline BOOL get_file_pointer32(
    HANDLE          hFile
,   ws_uint32_t*    offsetLo
,   ws_uint32_t*    offsetHi
) stlsoft_throw_0()
{
    return winstl_C_get_file_pointer_32(hFile, offsetLo, offsetHi);
}

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
inline BOOL get_file_pointer64(
    HANDLE          hFile
,   ws_uint64_t*    offset
) stlsoft_throw_0()
{
    return winstl_C_get_file_pointer_64(hFile, offset);
}
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */

inline BOOL set_file_pointer32(
    HANDLE      hFile
,   ws_uint32_t offsetLo
,   ws_uint32_t offsetHi
) stlsoft_throw_0()
{
    return winstl_C_set_file_pointer_32(hFile, offsetLo, offsetHi);
}

# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
inline BOOL set_file_pointer64(
    HANDLE      hFile
,   ws_uint64_t offset
) stlsoft_throw_0()
{
    return winstl_C_set_file_pointer_64(hFile, offset);
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

#endif /* WINSTL_INCL_WINSTL_FILESYSTEM_H_FILE_SEEK_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
