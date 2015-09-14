/* /////////////////////////////////////////////////////////////////////////////
 * File:        modulelist.cpp
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
# include "modulelist.h"
#else /* ? STLSOFT_EXTRAS_NO_NESTED_INCLUDES */
# include <modulelist/modulelist.h>
#endif /* STLSOFT_EXTRAS_NO_NESTED_INCLUDES */

#include <winstl/system/version_info.hpp>
#include <winstl/toolhelp/module_sequence.hpp>

#include <tchar.h>
#include <commctrl.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

extern "C" DWORD STLSOFT_CDECL ModuleList_PopulateListView(HWND hwndControl, DWORD flags, LPCTSTR colTitles[2])
{
    LV_COLUMN   col;
    LPCTSTR     defaultTitles[] = { _T("Module"), _T("Version"), _T("Vendor") };

    col.mask    =   LVCF_WIDTH;
    col.cx      =   -1;

    if(NULL == colTitles)
    {
        colTitles = defaultTitles;
    }

    if( !ListView_GetColumn(hwndControl, 0, &col) &&
        PAMW_MLF_CREATE_COLUMNS_IF_EMPTY == (PAMW_MLF_CREATE_COLUMNS_IF_EMPTY & flags))
    {
        RECT    rc;
        int     cx;
        int     cxModule;
        int     cxVersion;
        int     cxVendor;

        ::GetClientRect(hwndControl, &rc);

        cx = (rc.right - rc.left) - (2 + ::GetSystemMetrics(SM_CXVSCROLL));

        if(flags & PAMW_MLF_NO_VERSION_INFO)
        {
            cxModule    =   cx;
            cxVersion   =   0;
            cxVendor    =   0;
        }
        else
        {
            switch(flags & PAMW_MLF_VENDOR_MASK)
            {
                default:
                    STLSOFT_ASSERT(0);
                case    0:  // 
                    cxModule    =   (cx * 3) / 5;
                    cxVersion   =   (cx * 2) / 5;
                    cxVendor    =   0;
                    break;
                case    PAMW_MLF_INCLUDE_VENDOR:
                    cxModule    =   (cx * 3) / 7;
                    cxVersion   =   (cx * 2) / 7;
                    cxVendor    =   (cx * 2) / 7;
                    break;
            }
        }

        col.mask    =   LVCF_WIDTH | LVCF_TEXT;
        col.cx      =   cxModule;
        col.pszText =   const_cast<LPTSTR>(colTitles[0]);

        ListView_InsertColumn(hwndControl, 0, &col);

        if(0 == (PAMW_MLF_NO_VERSION_INFO & flags))
        {
            col.cx      =   cxVersion;
            col.pszText =   const_cast<LPTSTR>(colTitles[1]);

            ListView_InsertColumn(hwndControl, 1, &col);

            if(PAMW_MLF_INCLUDE_VENDOR & flags)
            {
                col.cx      =   cxVendor;
                col.pszText =   const_cast<LPTSTR>(colTitles[2]);

                ListView_InsertColumn(hwndControl, 2, &col);
            }
        }
    }

    if(0 == (PAMW_MLF_NO_RESET_CONTENT_BEFORE_INSERT & flags))
    {
        ListView_DeleteAllItems(hwndControl);
    }

    // Now insert the module information
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    {
        winstl::module_sequence     modules;
        DWORD                       numInserted =   0;

        { for(winstl::module_sequence::const_iterator   b = modules.begin(); b != modules.end(); ++b)
        {
            winstl::module_sequence::value_type const   &value  =   *b;
            LV_ITEM                                     item;

            item.mask       =   LVIF_TEXT;
            item.iItem      =   ListView_GetItemCount(hwndControl);
            item.iSubItem   =   0;
            item.pszText    =   const_cast<LPTSTR>(value.szModule);

            item.iItem = ListView_InsertItem(hwndControl, &item);

            if(-1 != item.iItem)
            {
                ++numInserted;

                if(0 == (PAMW_MLF_NO_VERSION_INFO & flags))
                {
                    char    szVersion[101];

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                    try
                    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                        winstl::version_info        vi((*b).szModule);

#ifndef STLSOFT_CF_EXCEPTION_SUPPORT
                        if(0 == vi.Length())
                        {
                            continue;
                        }
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

                        winstl::fixed_file_info     ffi =   vi.FixedFileInfo();

                        ::wsprintf(szVersion, "%u.%u.%02u.%04u", ffi.FileVerMajor(), ffi.FileVerMinor(), ffi.FileVerRevision(), ffi.FileVerBuild());

                        ListView_SetItemText(hwndControl, item.iItem, 1, szVersion);

                        if(PAMW_MLF_INCLUDE_VENDOR & flags)
                        {
                            if(vi.HasStringFileInfo())
                            {
                                winstl::VsStringFileInfo    sfi =   vi.StringFileInfo();

                                { for(winstl::VsStringFileInfo::const_iterator b1 = sfi.begin(); b1 != sfi.end(); ++b1)
                                {
                                    winstl::VsStringTable   vst =   *b1;

                                    { for(winstl::VsStringTable::const_iterator b2 = vst.begin(); b2 != vst.end(); ++b2)
                                    {
                                        winstl::VsString    str =   *b2;

                                        if(0 == ::wcscmp(L"CompanyName", str.name()))
                                        {
                                            LV_ITEMW    lvi;

                                            lvi.iSubItem    =   2;
                                            lvi.pszText     =   const_cast<LPWSTR>(str.value());
                                            ::SendMessage(hwndControl, LVM_SETITEMTEXTW, (WPARAM)item.iItem, (LPARAM)&lvi);

                                            goto enumeration_complete;
                                        }
                                    }}
                                }}

enumeration_complete:
                                ;
                            }
                        }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                    }
                    catch(winstl::version_info_exception &)
                    {}
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                }
            }
        }}

        ::SetLastError(ERROR_SUCCESS);
        return numInserted;
    }
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    catch(winstl::toolhelp_exception &x)
    {
        ::SetLastError(x.get_error_code());
    }
    catch(std::exception &)
    {
        ::SetLastError(E_FAIL);
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    return 0;
}

/* ////////////////////////////////////////////////////////////////////////// */
