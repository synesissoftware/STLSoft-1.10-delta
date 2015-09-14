/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/filesystem/link_functions.h
 *
 * Purpose:     Link functions.
 *
 * Created:     14th February 2011
 * Updated:     9th August 2015
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


/** \file winstl/filesystem/link_functions.h
 *
 * \brief [C, C++] Link functions
 *   (\ref group__library__filesystem "File System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_H_LINK_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_LINK_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_LINK_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_H_LINK_FUNCTIONS_MINOR       1
# define WINSTL_VER_WINSTL_H_LINK_FUNCTIONS_REVISION    6
# define WINSTL_VER_WINSTL_H_LINK_FUNCTIONS_EDIT        10
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

STLSOFT_INLINE
BOOL
winstl_C_call_CreateHardLinkA_(
    ws_char_a_t const*      linkPath
,   ws_char_a_t const*      existingFilePath
,   LPSECURITY_ATTRIBUTES   lpSecurityAttributes
)
{
#if (_WIN32_WINNT >= 0x0500)

    return STLSOFT_NS_GLOBAL(CreateHardLinkA)(linkPath, existingFilePath, lpSecurityAttributes);

#else /* ? _WIN32_WINNT < 0x0500 */

    typedef BOOL (WINAPI* pfn_t)(LPCSTR, LPCSTR, LPSECURITY_ATTRIBUTES);

    BOOL            r   =   FALSE;
    HMODULE const   h   =   STLSOFT_NS_GLOBAL(LoadLibraryA)("KERNEL32");

    if(NULL != h)
    {
        union
        {
            pfn_t   pfn;
            FARPROC pfp;
        }           u;

        u.pfp = STLSOFT_NS_GLOBAL(GetProcAddress)(h, "CreateHardLinkA");

        if(NULL != u.pfp)
        {
            if(u.pfn(linkPath, existingFilePath, lpSecurityAttributes))
            {
                r = TRUE;
            }
        }

        STLSOFT_NS_GLOBAL(FreeLibrary)(h);
    }

    return r;

#endif /* _WIN32_WINNT < 0x0500 */
}

STLSOFT_INLINE
BOOL
winstl_C_call_CreateHardLinkW_(
    ws_char_w_t const*      linkPath
,   ws_char_w_t const*      existingFilePath
,   LPSECURITY_ATTRIBUTES   lpSecurityAttributes
)
{
#if (_WIN32_WINNT >= 0x0500)

    return STLSOFT_NS_GLOBAL(CreateHardLinkW)(linkPath, existingFilePath, lpSecurityAttributes);

#else /* ? _WIN32_WINNT < 0x0500 */

    typedef BOOL (WINAPI* pfn_t)(LPCWSTR, LPCWSTR, LPSECURITY_ATTRIBUTES);

    BOOL            r   =   FALSE;
    HMODULE const   h   =   STLSOFT_NS_GLOBAL(LoadLibraryW)(L"KERNEL32");

    if(NULL != h)
    {
        union
        {
            pfn_t   pfn;
            FARPROC pfp;
        }           u;

        u.pfp = STLSOFT_NS_GLOBAL(GetProcAddress)(h, "CreateHardLinkW");

        if(NULL != u.pfp)
        {
            if(u.pfn(linkPath, existingFilePath, lpSecurityAttributes))
            {
                r = TRUE;
            }
        }

        STLSOFT_NS_GLOBAL(FreeLibrary)(h);
    }

    return r;

#endif /* _WIN32_WINNT < 0x0500 */
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

STLSOFT_INLINE
ws_int_t
winstl_C_hard_link_create_a(
    ws_char_a_t const*  existingFilePath
,   ws_char_a_t const*  linkPath
)
{
    return FALSE != winstl_C_call_CreateHardLinkA_(linkPath, existingFilePath, NULL);
}

STLSOFT_INLINE
ws_int_t
winstl_C_hard_link_create_w(
    ws_char_w_t const*  existingFilePath
,   ws_char_w_t const*  linkPath
)
{
    return FALSE != winstl_C_call_CreateHardLinkW_(linkPath, existingFilePath, NULL);
}

STLSOFT_INLINE
ws_int_t
winstl_C_hard_link_get_link_information_by_handle(
    HANDLE              hFile
,   ws_dword_t*         fileIndexHigh
,   ws_dword_t*         fileIndexLow
,   ws_dword_t*         volumeSerialNumber
,   ws_dword_t*         numLinks
)
{
    BY_HANDLE_FILE_INFORMATION  bhfi;
    ws_int_t                   r   =   ws_false_v;

    WINSTL_ASSERT(NULL != fileIndexHigh);
    WINSTL_ASSERT(NULL != fileIndexLow);
    WINSTL_ASSERT(NULL != volumeSerialNumber);
    WINSTL_ASSERT(NULL != numLinks);

    *fileIndexHigh      =   0;
    *fileIndexLow       =   0;
    *volumeSerialNumber =   0;
    *numLinks           =   0;

    if(STLSOFT_NS_GLOBAL(GetFileInformationByHandle)(hFile, &bhfi))
    {
        *fileIndexHigh      =   bhfi.nFileIndexHigh;
        *fileIndexLow       =   bhfi.nFileIndexLow;
        *volumeSerialNumber =   bhfi.dwVolumeSerialNumber;
        *numLinks           =   bhfi.nNumberOfLinks;

        r = ws_true_v;
    }

    return r;
}

STLSOFT_INLINE
ws_int_t
winstl_C_hard_link_get_link_information_a(
    ws_char_a_t const*  path
,   ws_dword_t*         fileIndexHigh
,   ws_dword_t*         fileIndexLow
,   ws_dword_t*         volumeSerialNumber
,   ws_dword_t*         numLinks
)
{
    ws_int_t        r   =   ws_false_v;
    HANDLE const    h   =   STLSOFT_NS_GLOBAL(CreateFileA)(
                                path
                            ,   0
                            ,   FILE_SHARE_READ | FILE_SHARE_WRITE
                            ,   NULL
                            ,   OPEN_EXISTING
                            ,   0
                            ,   NULL
                            );

    WINSTL_ASSERT(NULL != fileIndexHigh);
    WINSTL_ASSERT(NULL != fileIndexLow);
    WINSTL_ASSERT(NULL != volumeSerialNumber);
    WINSTL_ASSERT(NULL != numLinks);

    *fileIndexHigh      =   0;
    *fileIndexLow       =   0;
    *volumeSerialNumber =   0;
    *numLinks           =   0;

    if(INVALID_HANDLE_VALUE != h)
    {
        r = winstl_C_hard_link_get_link_information_by_handle(h, fileIndexHigh, fileIndexLow, volumeSerialNumber, numLinks);

        STLSOFT_NS_GLOBAL(CloseHandle)(h);
    }

    return r;
}

STLSOFT_INLINE
ws_int_t
winstl_C_hard_link_get_link_information_w(
    ws_char_w_t const*  path
,   ws_dword_t*         fileIndexHigh
,   ws_dword_t*         fileIndexLow
,   ws_dword_t*         volumeSerialNumber
,   ws_dword_t*         numLinks
)
{
    ws_int_t        r   =   ws_false_v;
    HANDLE const    h   =   STLSOFT_NS_GLOBAL(CreateFileW)(
                                path
                            ,   0
                            ,   FILE_SHARE_READ | FILE_SHARE_WRITE
                            ,   NULL
                            ,   OPEN_EXISTING
                            ,   0
                            ,   NULL
                            );

    WINSTL_ASSERT(NULL != fileIndexHigh);
    WINSTL_ASSERT(NULL != fileIndexLow);
    WINSTL_ASSERT(NULL != volumeSerialNumber);
    WINSTL_ASSERT(NULL != numLinks);

    *fileIndexHigh      =   0;
    *fileIndexLow       =   0;
    *volumeSerialNumber =   0;
    *numLinks           =   0;

    if(INVALID_HANDLE_VALUE != h)
    {
        r = winstl_C_hard_link_get_link_information_by_handle(h, fileIndexHigh, fileIndexLow, volumeSerialNumber, numLinks);

        STLSOFT_NS_GLOBAL(CloseHandle)(h);
    }

    return r;
}

STLSOFT_INLINE
ws_int_t
winstl_C_hard_link_count_links_a(
    ws_char_a_t const*  path
,   ws_dword_t*         numLinks
)
{
    ws_dword_t  dummy1;
    ws_dword_t  dummy2;
    ws_dword_t  dummy3;

    return winstl_C_hard_link_get_link_information_a(path, &dummy1, &dummy2, &dummy3, numLinks);
}

STLSOFT_INLINE
ws_int_t
winstl_C_hard_link_count_links_w(
    ws_char_w_t const*  path
,   ws_dword_t*         numLinks
)
{
    ws_dword_t  dummy1;
    ws_dword_t  dummy2;
    ws_dword_t  dummy3;

    return winstl_C_hard_link_get_link_information_w(path, &dummy1, &dummy2, &dummy3, numLinks);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ Functions
 */

#ifdef __cplusplus

inline
ws_bool_t
hard_link_create(
    ws_char_a_t const*  existingFilePath
,   ws_char_a_t const*  linkPath
)
{
    return 0 !=  winstl_C_hard_link_create_a(existingFilePath, linkPath);
}

inline
ws_bool_t
hard_link_create(
    ws_char_w_t const*  existingFilePath
,   ws_char_w_t const*  linkPath
)
{
    return 0 !=  winstl_C_hard_link_create_w(existingFilePath, linkPath);
}

inline
ws_bool_t
hard_link_get_link_information(
    ws_char_a_t const*  path
,   ws_dword_t*         fileIndexHigh
,   ws_dword_t*         fileIndexLow
,   ws_dword_t*         volumeSerialNumber
,   ws_dword_t*         numLinks
)
{
    return 0 !=  winstl_C_hard_link_get_link_information_a(path, fileIndexHigh, fileIndexLow, volumeSerialNumber, numLinks);
}

inline
ws_bool_t
hard_link_get_link_information(
    ws_char_w_t const*  path
,   ws_dword_t*         fileIndexHigh
,   ws_dword_t*         fileIndexLow
,   ws_dword_t*         volumeSerialNumber
,   ws_dword_t*         numLinks
)
{
    return 0 !=  winstl_C_hard_link_get_link_information_w(path, fileIndexHigh, fileIndexLow, volumeSerialNumber, numLinks);
}

STLSOFT_INLINE
ws_bool_t
hard_link_count_links(
    ws_char_a_t const*  path
,   ws_dword_t*         numLinks
)
{
    return 0 !=  winstl_C_hard_link_count_links_a(path, numLinks);
}

STLSOFT_INLINE
ws_bool_t
hard_link_count_links(
    ws_char_w_t const*  path
,   ws_dword_t*         numLinks
)
{
    return 0 !=  winstl_C_hard_link_count_links_w(path, numLinks);
}

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_H_LINK_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
