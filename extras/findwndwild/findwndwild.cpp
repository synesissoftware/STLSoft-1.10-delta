/* /////////////////////////////////////////////////////////////////////////////
 * File:        ../extras/findwndwild/findwndwild.cpp
 *
 * Purpose:     Window searching using (shwild) wildcards.
 *
 * Created:     4th August 2006
 * Updated:     11th March 2007
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006-2007, Matthew Wilson and Synesis Software
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
 * ////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-DOCFILELABEL]>]
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifdef STLSOFT_EXTRAS_NO_NESTED_INCLUDES
#include "findwndwild.h"
#else /* ? STLSOFT_EXTRAS_NO_NESTED_INCLUDES */
# include <findwndwild/findwndwild.h>
#endif /* STLSOFT_EXTRAS_NO_NESTED_INCLUDES */

#include <stlsoft/stlsoft.h>
#include <stlsoft/conversion/union_cast.hpp>

#include <shwild/shwild.hpp>	// Download the shwild project from http://shwild.org/

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

namespace
{
    struct MatchInfo
    {
        LPCSTR  classNamePattern;
        LPCSTR  windowNamePattern;
        HWND    hwndResult;
    };

    BOOL CALLBACK WildMatchProc(HWND hwnd, LPARAM lparam)
    {
        MatchInfo   &info   =   *stlsoft::union_cast<MatchInfo*>(lparam);   // Union cast guarantees same size
        CHAR        sz[2001];
        size_t      cch;

        // Match the window text first
        cch = static_cast<size_t>(::GetWindowTextA(hwnd, &sz[0], STLSOFT_NUM_ELEMENTS(sz) - 1));
        sz[cch] = '\0';

        if(0 != shwild_match(info.windowNamePattern, sz, SHWILD_F_IGNORE_CASE))
        {
            return true;    // Not found, so continue enumeration
        }

        // Now try the class name
        cch = static_cast<size_t>(::GetClassNameA(hwnd, &sz[0], STLSOFT_NUM_ELEMENTS(sz) - 1));
        sz[cch] = '\0';

        if(0 != shwild_match(info.classNamePattern, sz, SHWILD_F_IGNORE_CASE))
        {
            return true;    // Not found, so continue enumeration
        }

        // Found a match, so ...

        info.hwndResult = hwnd; // ... record the window handle, and ...

        return false;           // ... stop searching.
    }
}

HWND FindWindowWildA(LPCSTR classNamePattern, LPCSTR windowNamePattern)
{
    if(NULL == classNamePattern)
    {
        classNamePattern = "*";
    }
    if(NULL == windowNamePattern)
    {
        windowNamePattern = "*";
    }

    MatchInfo   info;

    info.classNamePattern   =   classNamePattern;
    info.windowNamePattern  =   windowNamePattern;
    info.hwndResult         =   NULL;

    ::EnumWindows(WildMatchProc, stlsoft::union_cast<LPARAM>(&info));

    return info.hwndResult;
}

/* ////////////////////////////////////////////////////////////////////////// */
