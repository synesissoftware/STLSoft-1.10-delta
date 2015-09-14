/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/memory_map_functions.h (originally winstl/filesystem/memory_mapped_file.hpp, based on MMFile.h, ::SynesisWin)
 *
 * Purpose:     Windows memory mapping functions.
 *
 * Created:     15th December 1996
 * Updated:     6th June 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1996-2014, Matthew Wilson and Synesis Software
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

/** \file winstl/filesystem/memory_map_functions.h
 *
 * \brief [C, C++] Memory-mapping functions.
 */

#ifndef WINSTL_INCL_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS
#define WINSTL_INCL_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS_MAJOR      5
# define WINSTL_VER_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS_MINOR      1
# define WINSTL_VER_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS_REVISION   2
# define WINSTL_VER_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS_EDIT       103
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
 * Helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

/* NOTE: The offset params are reversed from Windows API! */
STLSOFT_INLINE
void*
winstl_C_call_MapViewOfFile_offset_32_(
    HANDLE          hMap
,   DWORD           access
,   ws_uint32_t     offset
,   ws_uintptr_t    viewSize
) stlsoft_throw_0()
{
    return STLSOFT_NS_GLOBAL(MapViewOfFile)(
        hMap
    ,   access
    ,   0
    ,   offset
    ,   viewSize
    );
}
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
STLSOFT_INLINE
void*
winstl_C_call_MapViewOfFile_offset_64_(
    HANDLE          hMap
,   DWORD           access
,   ws_uint64_t     offset
,   ws_uintptr_t    viewSize
) stlsoft_throw_0()
{
    return STLSOFT_NS_GLOBAL(MapViewOfFile)(
        hMap
    ,   access
    ,   stlsoft_static_cast(DWORD, offset >> 32)
    ,   stlsoft_static_cast(DWORD, offset)
    ,   viewSize
    );
}
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */


#if 0
STLSOFT_INLINE
void*
winstl_C_create_stub_map_view_(void) stlsoft_throw_0()
{
    HANDLE hmap = STLSOFT_NS_GLOBAL(CreateFileMappingA)(
        INVALID_HANDLE_VALUE
    ,   NULL
    ,   PAGE_READONLY
    ,   0
    ,   4096
    ,   NULL
    );

    if(NULL == hmap)
    {
        return NULL;
    }
    else
    {
        void*   pv  =   STLSOFT_NS_GLOBAL(MapViewOfFile)(hmap, FILE_MAP_READ, 0, 0, 4096);
        DWORD   dw  =   STLSOFT_NS_GLOBAL(GetLastError)();

        STLSOFT_NS_GLOBAL(CloseHandle)(hmap);

        if(NULL == pv)
        {
            STLSOFT_NS_GLOBAL(SetLastError)(dw);
        }

        return pv;
    }
}
#endif /* 0 */

STLSOFT_INLINE
void*
winstl_C_map_view_of_file_by_handle_(
    HANDLE          hFile
,   ws_uint64_t     offset
,   ws_uintptr_t    requestSize
,   ws_uintptr_t*   viewSize
,   int             readOnly
) stlsoft_throw_0();

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Functions (C)
 */

/* TODO: Allow named mapping */

/** Maps a view onto a region of a file.
 *
 * \param hFile Handle to the file to be mapped. May not
 *   be <code>INVALID_HANDLE_VALUE</code>.
 * \param offset The offset into the file where the mapped region will
 *   begin. Must be a multiple of the system's allocation granularity.
 * \param requestSize The size of the mapped region. May be 0, in which
 *   case the whole file will be mapped.
 * \param viewSize Pointer to variable to receive the actual size of the
 *   mapping view. This will always be set, regardless of whether the
 *   function returns <code>NULL</code> or non-<code>NULL</code>.
 *
 * \return When mapping a file with non-zero length, then the return value
 *   is either a pointer to the mapping view, or <code>NULL</code> if the
 *   mapping could not be created or viewed. When mapping a zero length
 *   file, success is denoted by: (i) returning <code>NULL</code>; (ii)
 *   setting <code>*viewSize</code> to 0; (iii) <code>GetLastError()</code>
 *   returns <code>ERROR_SUCCESS</code>. Any other combination indicates
 *   failure.
 *
 * \note If a zero-length file is mapped, <code>*viewSize</code> will be
 *   0, and an unreferenceable non-NULL pointer will be returned.
 *
 * \note When <code>NULL</code> is returned, this function *always* changes
 *   the calling thread's last-error code, even if successful (when it will
 *   set it to <code>ERROR_SUCCESS</code>).
 *
 * \pre (INVALID_HANDLE_VALUE != hFile)
 */
STLSOFT_INLINE
void*
winstl_C_map_readonly_view_of_file_by_handle(
    HANDLE          hFile
,   ws_uint64_t     offset
,   ws_uintptr_t    requestSize
,   ws_uintptr_t*   viewSize
) stlsoft_throw_0()
{
    return winstl_C_map_view_of_file_by_handle_(hFile, offset, requestSize, viewSize, TRUE);
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_INLINE
void*
winstl_C_map_view_of_file_by_handle_(
    HANDLE          hFile
,   ws_uint64_t     offset
,   ws_uintptr_t    requestSize
,   ws_uintptr_t*   viewSize
,   int             readOnly
) stlsoft_throw_0()
{
    DWORD           fileSizeHigh;
    DWORD           fileSizeLow;
    DWORD           error;
    ws_uintptr_t    dummy;

    WINSTL_ASSERT(INVALID_HANDLE_VALUE != hFile);
    WINSTL_ASSERT(NULL != viewSize);

    if(NULL == viewSize)
    {
        viewSize = &dummy;
    }
    *viewSize = ~stlsoft_static_cast(ws_uintptr_t, 0);

    fileSizeLow =   STLSOFT_NS_GLOBAL(GetFileSize)(hFile, &fileSizeHigh);
    error       =   STLSOFT_NS_GLOBAL(GetLastError)();

    if( INVALID_FILE_SIZE == fileSizeLow &&
        ERROR_SUCCESS != error)
    {
        return NULL;
    }
    else
    {
        typedef ws_uint64_t     offset_type;
        typedef ws_uintptr_t    size_type;

        ws_uint64_t fileSize    =   (stlsoft_static_cast(ws_uint64_t, fileSizeHigh) << 32) | fileSizeLow;
        ws_uint64_t mapSize     =   offset + requestSize;

        if(mapSize < offset) // Overflow?
        {
            STLSOFT_NS_GLOBAL(SetLastError)(ERROR_INVALID_PARAMETER);

            return NULL;
        }

        if(offset > fileSize)
        {
            if(0 == requestSize)
            {
                STLSOFT_NS_GLOBAL(SetLastError)(ERROR_INVALID_PARAMETER);

                return NULL;
            }
            else
            {
                // Do nothing, because MapViewOfFile() will fail for us
            }
        }
        else if(0 == requestSize)
        {
#ifdef WINSTL_OS_IS_WIN64

            // all 64-bit

            requestSize = fileSize - offset;

#else /* ? WINSTL_OS_IS_WIN64 */

            // offset is 64-bit; file-size is 64-bit; request size is 32-bit

            ws_uint64_t requestSize2 = fileSize - offset;

            if(requestSize2 > stlsoft_static_cast(ws_uint64_t, 0xffffffff))
            {
                STLSOFT_NS_GLOBAL(SetLastError)(ERROR_NOT_ENOUGH_MEMORY);

                return NULL;
            }

            requestSize =   stlsoft_static_cast(ws_uint32_t, requestSize2);

#endif /* WINSTL_OS_IS_WIN64 */

            mapSize     =   offset + requestSize;
        }
        else if(readOnly)
        {
#ifndef WINSTL_MMF_DONT_TRIM_REQUEST_SIZE
            // Work out how large the file mapping object has to be
            // to cater to all the requested region. Also check if
            // have asked for too much, and reduce request if
            // necessary.
            //
            // NOTE: This request trimming is only appropriate
            // because we are providing only a read-only view. Even
            // so, it is possible that the map will cause the file
            // to increase in size. But that's caveat emptor for
            // the user of MMFs, and nothing per se to do with this
            // component.

            if(mapSize > fileSize)
            {
                WINSTL_ASSERT((mapSize - fileSize) <= stlsoft_static_cast(ws_uint64_t, 0xffffffff));
                WINSTL_ASSERT(offset <= fileSize);

                requestSize -= stlsoft_static_cast(size_type, (mapSize - fileSize));
                mapSize = 0;
            }
#endif /* !WINSTL_MMF_DONT_TRIM_REQUEST_SIZE */
        }

        if(0 == requestSize)
        {
            // Windows CreateFileMapping() does not support mapping
            // zero-length files, so we catch this condition here

            STLSOFT_NS_GLOBAL(SetLastError)(ERROR_SUCCESS);

            *viewSize   =   0;

            return NULL;
        }
        else
        {
            DWORD   mapSizeHi   =   stlsoft_static_cast(DWORD, mapSize >> 32);
            DWORD   mapSizeLo   =   stlsoft_static_cast(DWORD, mapSize);

            HANDLE  hmap = STLSOFT_NS_GLOBAL(CreateFileMappingA)(
                        hFile
                    ,   NULL
                    ,   readOnly ? PAGE_READONLY : PAGE_READWRITE
                    ,   mapSizeHi
                    ,   mapSizeLo
                    ,   NULL
                    );

            if(NULL == hmap)
            {
                return NULL;
            }
            else
            {
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
                void* memory = winstl_C_call_MapViewOfFile_offset_64_(
# else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
                void* memory = winstl_C_call_MapViewOfFile_offset_32_(
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
                        hmap
                    ,   readOnly ? FILE_MAP_READ : FILE_MAP_WRITE
                    ,   offset
                    ,   requestSize
                    );

                DWORD e = STLSOFT_NS_GLOBAL(GetLastError)();

                STLSOFT_NS_GLOBAL(CloseHandle)(hmap);

                STLSOFT_NS_GLOBAL(SetLastError)(e);

                if(NULL == memory)
                {
                    return NULL;
                }
                else
                {
                    *viewSize = requestSize;

                    return memory;
                }
            }
        }
    }
}

STLSOFT_INLINE
void*
winstl_C_map_view_on_pagefile_(
    ws_uintptr_t    requestSize
) stlsoft_throw_0()
{
    ws_uint64_t mapSize     =   requestSize;
    DWORD       mapSizeHi   =   stlsoft_static_cast(DWORD, mapSize >> 32);
    DWORD       mapSizeLo   =   stlsoft_static_cast(DWORD, mapSize);

    HANDLE  hmap = STLSOFT_NS_GLOBAL(CreateFileMappingA)(
                INVALID_HANDLE_VALUE
            ,   NULL
            ,   PAGE_READWRITE
            ,   mapSizeHi
            ,   mapSizeLo
            ,   NULL
            );

    if(NULL == hmap)
    {
        return NULL;
    }
    else
    {
# ifdef STLSOFT_CF_64BIT_INT_SUPPORT
        void* memory = winstl_C_call_MapViewOfFile_offset_64_(
# else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
        void* memory = winstl_C_call_MapViewOfFile_offset_32_(
# endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
                hmap
            ,   FILE_MAP_WRITE
            ,   0
            ,   requestSize
            );

        DWORD e = STLSOFT_NS_GLOBAL(GetLastError)();

        STLSOFT_NS_GLOBAL(CloseHandle)(hmap);

        STLSOFT_NS_GLOBAL(SetLastError)(e);

        if(NULL == memory)
        {
            return NULL;
        }
        else
        {
            return memory;
        }
    }
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

STLSOFT_INLINE
void*
winstl_C_map_readwrite_view_of_file_by_handle(
    HANDLE          hFile
,   ws_uint64_t     offset
,   ws_uintptr_t    requestSize
,   ws_uintptr_t*   viewSize
) stlsoft_throw_0()
{
    return winstl_C_map_view_of_file_by_handle_(hFile, offset, requestSize, viewSize, FALSE);
}

STLSOFT_INLINE
void*
winstl_C_map_view_on_pagefile(
    ws_uintptr_t    requestSize
) stlsoft_throw_0()
{
    return winstl_C_map_view_on_pagefile_(requestSize);
}

/** Unmaps a file mapping view, and releases any associated mapping
 *   resources.
 *
 * \param view Pointer to the base of the view to be unmapped.
 *
 * \note Because winstl_C_map_readonly_view_of_file_by_handle() allows
 *   mapping of zero-length files, by returning <code>NULL</code>,
 *   winstl_C_unmap_view_of_file() is tolerant of being passed a
 *   <code>NULL</code> view, even though the underlying operating system API
 *   function, <code>UnmapViewOfFile()</code>, is not.
 */
STLSOFT_INLINE
void
winstl_C_unmap_view_of_file(
    void*           view
) stlsoft_throw_0()
{
    if(NULL != view)
    {
        STLSOFT_NS_GLOBAL(UnmapViewOfFile)(view);
    }
}

STLSOFT_INLINE
void*
winstl_C_map_readonly_view_of_file_by_name_a(
    ws_char_a_t const*  path
,   DWORD               access
,   DWORD               shareMode
,   ws_uint64_t         offset
,   ws_uintptr_t        requestSize
,   ws_uintptr_t*       actualSize
) stlsoft_throw_0()
{
    HANDLE hFile = STLSOFT_NS_GLOBAL(CreateFileA)(path, access, shareMode, NULL, OPEN_EXISTING, 0, NULL);

    if(INVALID_HANDLE_VALUE == hFile)
    {
        return NULL;
    }
    else
    {
        void* view = winstl_C_map_readonly_view_of_file_by_handle(
                hFile
            ,   offset
            ,   requestSize
            ,   actualSize
            );

        DWORD e = STLSOFT_NS_GLOBAL(GetLastError)();

        STLSOFT_NS_GLOBAL(CloseHandle)(hFile);

        STLSOFT_NS_GLOBAL(SetLastError)(e);

        return view;
    }
}

STLSOFT_INLINE
void*
winstl_C_map_readonly_view_of_file_by_name_w(
    ws_char_w_t const*  path
,   DWORD               access
,   DWORD               shareMode
,   ws_uint64_t         offset
,   ws_uintptr_t        requestSize
,   ws_uintptr_t*       actualSize
) stlsoft_throw_0()
{
    HANDLE hFile = STLSOFT_NS_GLOBAL(CreateFileW)(path, access, shareMode, NULL, OPEN_EXISTING, 0, NULL);

    if(INVALID_HANDLE_VALUE == hFile)
    {
        return NULL;
    }
    else
    {
        void* view = winstl_C_map_readonly_view_of_file_by_handle(
                hFile
            ,   offset
            ,   requestSize
            ,   actualSize
            );

        DWORD e = STLSOFT_NS_GLOBAL(GetLastError)();

        STLSOFT_NS_GLOBAL(CloseHandle)(hFile);

        STLSOFT_NS_GLOBAL(SetLastError)(e);

        return view;
    }
}


#ifdef __cplusplus

inline
void*
winstl_C_map_readonly_view_of_file_by_name(
    ws_char_a_t const*  path
,   DWORD               access
,   DWORD               shareMode
,   ws_uint64_t         offset
,   ws_uintptr_t        requestSize
,   ws_uintptr_t*       actualSize
) stlsoft_throw_0()
{
    return winstl_C_map_readonly_view_of_file_by_name_a(path, access, shareMode, offset, requestSize, actualSize);
}

inline
void*
winstl_C_map_readonly_view_of_file_by_name(
    ws_char_w_t const*  path
,   DWORD               access
,   DWORD               shareMode
,   ws_uint64_t         offset
,   ws_uintptr_t        requestSize
,   ws_uintptr_t*       actualSize
) stlsoft_throw_0()
{
    return winstl_C_map_readonly_view_of_file_by_name_w(path, access, shareMode, offset, requestSize, actualSize);
}

#else /* ? __cplusplus */

# ifdef UNICODE

#  define winstl_C_map_readonly_view_of_file_by_name    winstl_C_map_readonly_view_of_file_by_name_w

# else /* ? UNICODE */

#  define winstl_C_map_readonly_view_of_file_by_name    winstl_C_map_readonly_view_of_file_by_name_a

# endif /* UNICODE */

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Functions (C++)
 */

#ifdef __cplusplus

inline
void*
map_readonly_view_of_file_by_handle(
    HANDLE          hFile
,   ws_uintptr_t*   actualSize
)
{
    return winstl_C_map_readonly_view_of_file_by_handle(
        hFile
    ,   0
    ,   0
    ,   actualSize
    );
}

inline
void*
map_readonly_view_of_file_by_handle(
    HANDLE          hFile
,   ws_uint64_t     offset
,   ws_uintptr_t    requestSize
,   ws_uintptr_t*   actualSize
)
{
    return winstl_C_map_readonly_view_of_file_by_handle(hFile, offset, requestSize, actualSize);
}

inline
void*
map_readwrite_view_of_file_by_handle(
    HANDLE          hFile
,   ws_uint64_t     offset
,   ws_uintptr_t    requestSize
,   ws_uintptr_t*   actualSize
)
{
    return winstl_C_map_readwrite_view_of_file_by_handle(hFile, offset, requestSize, actualSize);
}

inline
void*
map_view_on_pagefile(
    ws_uintptr_t    requestSize
)
{
    return winstl_C_map_view_on_pagefile(requestSize);
}

inline
void
unmap_view_of_file(
    void* view
)
{
    winstl_C_unmap_view_of_file(view);
}

inline
void*
map_readonly_view_of_file_by_name(
    ws_char_a_t const*  path
,   DWORD               access
,   DWORD               shareMode
,   ws_uint64_t         offset
,   ws_uintptr_t        requestSize
,   ws_uintptr_t*       actualSize
) stlsoft_throw_0()
{
    return winstl_C_map_readonly_view_of_file_by_name_a(path, access, shareMode, offset, requestSize, actualSize);
}

inline
void*
map_readonly_view_of_file_by_name(
    ws_char_w_t const*  path
,   DWORD               access
,   DWORD               shareMode
,   ws_uint64_t         offset
,   ws_uintptr_t        requestSize
,   ws_uintptr_t*       actualSize
) stlsoft_throw_0()
{
    return winstl_C_map_readonly_view_of_file_by_name_w(path, access, shareMode, offset, requestSize, actualSize);
}

inline
void*
map_readonly_view_of_file_by_name(
    ws_char_a_t const*  path
,   DWORD               access
,   DWORD               shareMode
,   ws_uintptr_t*       actualSize
) stlsoft_throw_0()
{
    return winstl_C_map_readonly_view_of_file_by_name_a(path, access, shareMode, 0, 0, actualSize);
}

inline
void*
map_readonly_view_of_file_by_name(
    ws_char_w_t const*  path
,   DWORD               access
,   DWORD               shareMode
,   ws_uintptr_t*       actualSize
) stlsoft_throw_0()
{
    return winstl_C_map_readonly_view_of_file_by_name_w(path, access, shareMode, 0, 0, actualSize);
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

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

#endif /* WINSTL_INCL_WINSTL_FILESYSTEM_H_MEMORY_MAP_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
