/* /////////////////////////////////////////////////////////////////////////////
 * File:        compcatutil.cpp
 *
 * Purpose:     Implementation file for the component category cleaner API.
 *
 * Created:     4th September 2003
 * Updated:     11th March 2007
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Standard Source License)
 *
 *              Copyright (C) 2003-2007, Gregory Peet & Matthew Wilson.
 *              All rights reserved.
 *
 *              www:        http://www.gregpeet.com/projects.php
 *                          http://www.synesis.com.au/software
 *
 *              email:      admin@gregpeet.com
 *                          software@synesis.com.au
 *
 *              Redistribution and use in source and binary forms, with or
 *              without modification, are permitted provided that the following
 *              conditions are met:
 *
 *              (i) Redistributions of source code must retain the above
 *              copyright notice and contact information, this list of
 *              conditions and the following disclaimer.
 *
 *              (ii) Any derived versions of this software (howsoever modified)
 *              remain the sole property of Gregory Peet & Matthew Wilson.
 *
 *              (iii) Any derived versions of this software (howsoever modified)
 *              remain subject to all these conditions.
 *
 *              (iv) Neither the name of Gregory Peet & Matthew Wilson nor the
 *              names of any subdivisions, employees or agents of Gregory Peet &
 *              Matthew Wilson, nor the names of any other contributors to this
 *              software  may be used to endorse or promote products derived from
 *              this software without specific prior written permission.
 *
 *              This source code is provided by Gregory Peet & Matthew Wilson
 *              "as is" and any warranties, whether expressed or implied,
 *              including, but not limited to, the implied warranties of
 *              merchantability and fitness for a particular purpose are
 *              disclaimed. In no event
 *              shall the Gregory Peet & Matthew Wilson be liable for any direct,
 *              indirect, incidental, special, exemplary, or consequential
 *              damages (including, but not limited to, procurement of substitute
 *              goods or services; loss of use, data, or profits; or business
 *              interruption) however caused and on any theory of liability,
 *              whether in contract, strict liability, or tort (including
 *              negligence or otherwise) arising in any way out of the use of
 *              this software, even if advised of the possibility of such
 *              damage.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifdef STLSOFT_EXTRAS_NO_NESTED_INCLUDES
#include "compcatutil.h"
#else /* ? STLSOFT_EXTRAS_NO_NESTED_INCLUDES */
# include <compcatutil/compcatutil.h>
#endif /* STLSOFT_EXTRAS_NO_NESTED_INCLUDES */

#include <winstl/reg_key_sequence.hpp>
#include <winstl/char_conversions.hpp>

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{
    /* This is the function provided by Matthew Wilson in WDN, [NOT YET PUBLISHED] 2003
     */
    LONG Reg_DeleteKey(HKEY hkey, LPCTSTR lpszSubKey, BOOL bRecurse)
    {
        /* Open the sub-key. */
        HKEY    hkeySub;
        LONG    lRet = RegOpenKeyEx(hkey, lpszSubKey, 0,
                                    KEY_READ | KEY_WRITE, &hkeySub);

        if(lRet == ERROR_SUCCESS)
        {
            /* Enumerate all of the decendents of this child. */
            for(; lRet == ERROR_SUCCESS; )
            {
                FILETIME    time;
                TCHAR       szChildKey[MAX_PATH + 1];
                DWORD       dwSize = sizeof(szChildKey) /
                                        sizeof(szChildKey[0]);

                lRet = RegEnumKeyEx(hkeySub, 0, szChildKey, &dwSize,
                                    NULL, NULL, NULL, &time);

                if(lRet != ERROR_SUCCESS)
                {
                    if(lRet == ERROR_NO_MORE_ITEMS)
                    {
                        /* The enumeration is complete, so break main
                         * loop, but indicate success.
                         */
                        lRet = ERROR_SUCCESS;
                        break;
                    }
                }
                else
                {
                    if(!bRecurse)
                    {
                        /* Cannot delete keys with children, unless
                         * requested to do so.
                         */
                        lRet = ERROR_KEY_HAS_CHILDREN;
                    }
                    else
                    {
                        /* Recursively delete this child. */
                        lRet = Reg_DeleteKey(hkeySub, szChildKey,
                                                bRecurse);
                    }
                }
            }

            /* Close the sub-key. */
            RegCloseKey(hkeySub);

            /* Delete the sub-key. */
            if(lRet == ERROR_SUCCESS)
            {
                lRet = RegDeleteKey(hkey, lpszSubKey);
            }
        }

        return lRet;
    }

    /** This is the callback used by CompCat_DeleteBad()
     */
    BOOL WINAPI CompCat_DeleteBadKeyA(char const *key_name, DWORD param)
    {
        return ERROR_SUCCESS == Reg_DeleteKey((HKEY)param, key_name, true);
    }
}

/* /////////////////////////////////////////////////////////////////////////////
 * API Functions
 */

extern "C" {

ULONG WINAPI CompCat_FindBadA(PfnHandleBadKeyA pfn, DWORD param)
{
#ifndef _WINSTL_NO_NAMESPACE
    using winstl::a2w;
    using winstl::reg_key_a;
    using winstl::reg_key_sequence_a;
#endif /* _WINSTL_NO_NAMESPACE */

    ULONG                               cc_invalid_count = 0;
    reg_key_sequence_a                  cc_keys(HKEY_CLASSES_ROOT, "Component Categories");
    reg_key_sequence_a::const_iterator  begin = cc_keys.begin();
    reg_key_sequence_a::const_iterator  end   = cc_keys.end();

    for(; begin != end; ++begin)
    {
        CLSID           clsid;
        reg_key_a const key(*begin);

        if(CLSIDFromString(const_cast<LPOLESTR>((LPCOLESTR)a2w(key.name().c_str())), &clsid) != NOERROR)
        {
            if((*pfn)(key.name().c_str(), param))
            {
                ++cc_invalid_count;
            }
            else
            {
                break;
            }
        }
    }

    return cc_invalid_count;
}

ULONG WINAPI CompCat_FindBadW(PfnHandleBadKeyW pfn, DWORD param)
{
#ifndef _WINSTL_NO_NAMESPACE
    using winstl::reg_key_w;
    using winstl::reg_key_sequence_w;
#endif /* _WINSTL_NO_NAMESPACE */

    ULONG                               cc_invalid_count = 0;
    reg_key_sequence_w                  cc_keys(HKEY_CLASSES_ROOT, L"Component Categories");
    reg_key_sequence_w::const_iterator  begin = cc_keys.begin();
    reg_key_sequence_w::const_iterator  end   = cc_keys.end();

    for(; begin != end; ++begin)
    {
        CLSID           clsid;
        reg_key_w const key(*begin);

        if(CLSIDFromString(const_cast<LPOLESTR>(key.name().c_str()), &clsid) != NOERROR)
        {
            if((*pfn)(key.name().c_str(), param))
            {
                ++cc_invalid_count;
            }
            else
            {
                break;
            }
        }
    }

    return cc_invalid_count;
}

ULONG WINAPI CompCat_DeleteBad(void)
{
#ifndef _WINSTL_NO_NAMESPACE
    using winstl::reg_key_a;
#endif /* _WINSTL_NO_NAMESPACE */

    reg_key_a   key_root(HKEY_CLASSES_ROOT, "Component Categories");

    return CompCat_FindBadA(CompCat_DeleteBadKeyA, (DWORD)key_root.get_key_handle());
}

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////////// */
