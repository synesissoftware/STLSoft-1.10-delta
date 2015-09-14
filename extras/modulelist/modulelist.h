/* /////////////////////////////////////////////////////////////////////////////
 * File:        modulelist/modulelist.h
 *
 * Purpose:     Populates a windows control with the list of modules attached
 *              to the calling process.
 *
 * Created:     8th April 2006
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


#ifndef PAMW_INCL_MODULELIST_H_MODULELIST
#define PAMW_INCL_MODULELIST_H_MODULELIST

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-DOCFILELABEL]>]
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/

/* /////////////////////////////////////////////////////////////////////////////
 * API version
 */

#define PAMW_VER_MODULELIST_H_MODULELIST_MAJOR      1
#define PAMW_VER_MODULELIST_H_MODULELIST_MINOR      1
#define PAMW_VER_MODULELIST_H_MODULELIST_REVISON    3

#define PAMW_VER_MODULELIST_H_MODULELIST            0x00010103

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Constants
 */

#define PAMW_MLF_CREATE_COLUMNS_IF_EMPTY            (0x00000001)
#define PAMW_MLF_NO_RESET_CONTENT_BEFORE_INSERT     (0x00000002)
#define PAMW_MLF_NO_VERSION_INFO                    (0x00000004)
#define PAMW_MLF_INCLUDE_VENDOR						(0x00000100)
#define PAMW_MLF_VENDOR_MASK						(0x0000ff00)

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** \brief Populates the given list view control with the current module list
 *
 * \return Number of elements inserted
 */
DWORD STLSOFT_CDECL ModuleList_PopulateListView(HWND hwndControl, DWORD flags, LPCTSTR colTitles[2]);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* PAMW_INCL_MODULELIST_H_MODULELIST */

/* ////////////////////////////////////////////////////////////////////////// */
