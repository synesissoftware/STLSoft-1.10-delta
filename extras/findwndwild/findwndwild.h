/* /////////////////////////////////////////////////////////////////////////
 * File:        findwndwild/findwndwild.h
 *
 * Purpose:     Window searching using (shwild) wildcards.
 *
 * Created:     4th August 2006
 * Updated:     29th January 2011
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006-2011, Matthew Wilson and Synesis Software
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


#ifndef FWW_INCL_FINDWNDWILD_H_FINDWNDWILD
#define FWW_INCL_FINDWNDWILD_H_FINDWNDWILD

/* /////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-DOCFILELABEL]>]
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////
 * API version
 */

#define FWW_VER_FINDWNDWILD_H_FINDWNDWILD_MAJOR     1
#define FWW_VER_FINDWNDWILD_H_FINDWNDWILD_MINOR     1
#define FWW_VER_FINDWNDWILD_H_FINDWNDWILD_REVISON   3

#define FWW_VER_FINDWNDWILD_H_FINDWNDWILD           0x010103ff

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** \brief Searches for a top-level window using the shwild wild-card matching
 *    rules.
 */
HWND FindWindowWildA(LPCSTR classNamePattern, LPCSTR windowNamePattern);

/** \brief Searches for a top-level window using the shwild wild-card matching
 *    rules.
 */
HWND FindWindowWildW(LPCWSTR classNamePattern, LPCWSTR windowNamePattern);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#ifdef __cplusplus

inline HWND FindWindowWild(LPCTSTR classNamePattern, LPCTSTR windowNamePattern)
{
# ifdef UNICODE
    return FindWindowWildW(classNamePattern, windowNamePattern);
# else /* ? UNICODE */
    return FindWindowWildA(classNamePattern, windowNamePattern);
# endif /* UNICODE */
}

#else /* ? __cplusplus */

# ifdef UNICODE
#  define FindWindowWild            FindWindowWildW
# else /* ? UNICODE */
#  define FindWindowWild            FindWindowWildA
# endif /* UNICODE */

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FWW_INCL_FINDWNDWILD_H_FINDWNDWILD */

/* ///////////////////////////// end of file //////////////////////////// */
