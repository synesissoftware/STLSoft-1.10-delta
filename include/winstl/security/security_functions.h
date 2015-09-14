/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/security/security_functions.h
 *
 * Purpose:     Security functions.
 *
 * Created:     7th November 2014
 * Updated:     5th August 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014-2015, Matthew Wilson and Synesis Software
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


/** \file winstl/security/security_functions.h
 *
 * \brief [C, C++] Security functions
 *   (\ref group__library__security "Security" Library).
 */

#ifndef WINSTL_INCL_WINSTL_H_SECURITY_FUNCTIONS
#define WINSTL_INCL_WINSTL_H_SECURITY_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_H_SECURITY_FUNCTIONS_MAJOR       1
# define WINSTL_VER_WINSTL_H_SECURITY_FUNCTIONS_MINOR       0
# define WINSTL_VER_WINSTL_H_SECURITY_FUNCTIONS_REVISION    3
# define WINSTL_VER_WINSTL_H_SECURITY_FUNCTIONS_EDIT        3
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

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
void*
WinSTL_C_Security_alloc_(
    ws_size_t   cb
)
{
    return STLSOFT_C_CAST(SECURITY_DESCRIPTOR*, STLSOFT_NS_GLOBAL(HeapAlloc)(STLSOFT_NS_GLOBAL(GetProcessHeap)(), 0, cb));
}

STLSOFT_INLINE
void*
WinSTL_C_Security_free_(
    void*       pv
)
{
    return STLSOFT_C_CAST(SECURITY_DESCRIPTOR*, STLSOFT_NS_GLOBAL(HeapFree)(STLSOFT_NS_GLOBAL(GetProcessHeap)(), 0, pv));
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

STLSOFT_INLINE
void
WinSTL_C_Security_free_string_a(
    ws_char_a_t*    s
)
{
    WinSTL_C_Security_free_(s);
}

STLSOFT_INLINE
BOOL
WinSTL_C_Security_lookup_account_SID_info_a(
    ws_char_a_t const*  systemName
,   PSID                psid
,   ws_char_a_t**       pAccountName
,   ws_size_t*          pcchAccountName
,   ws_char_a_t**       pDomainName
,   ws_size_t*          pcchDomainName
,   SID_NAME_USE*       pNameUse
)
{
    DWORD           accountNameLen  =   0;
    DWORD           domainNameLen   =   0;
    SID_NAME_USE    nameUseDummy_;
    ws_char_a_t*    account;
    ws_char_a_t*    domain;

    if(NULL == pNameUse)
    {
        pNameUse = &nameUseDummy_;
    }

    STLSOFT_NS_GLOBAL(LookupAccountSid)(systemName, psid, NULL, &accountNameLen, NULL, &domainNameLen, pNameUse);

    switch(STLSOFT_NS_GLOBAL(GetLastError)())
    {
        default:
            return FALSE;
        case    ERROR_INSUFFICIENT_BUFFER:
            break;
    }

    if(NULL == (account = STLSOFT_STATIC_CAST(ws_char_a_t*, WinSTL_C_Security_alloc_(sizeof(ws_char_a_t) * accountNameLen))))
    {
        return FALSE;
    }
    if(NULL == (domain = STLSOFT_STATIC_CAST(ws_char_a_t*, WinSTL_C_Security_alloc_(sizeof(ws_char_a_t) * domainNameLen))))
    {
        WinSTL_C_Security_free_(account);

        return FALSE;
    }

    if(!STLSOFT_NS_GLOBAL(LookupAccountSid)(systemName, psid, &account[0], &accountNameLen, &domain[0], &domainNameLen, pNameUse))
    {
        WinSTL_C_Security_free_(account);
        WinSTL_C_Security_free_(domain);

        return FALSE;
    }

    if(NULL != pAccountName)
    {
        *pAccountName   =   account;
        account         =   NULL;
    }

    if(NULL != pcchAccountName)
    {
        *pcchAccountName    =   accountNameLen;
    }

    if(NULL != pDomainName)
    {
        *pDomainName    =   domain;
        domain          =   NULL;
    }

    if(NULL != pcchDomainName)
    {
        *pcchDomainName =   domainNameLen;
    }

    WinSTL_C_Security_free_(account);
    WinSTL_C_Security_free_(domain);

    return TRUE;
}


STLSOFT_INLINE
BOOL
WinSTL_C_Security_lookup_account_SID_info_w(
    ws_char_w_t const*  systemName
,   PSID                psid
,   ws_char_w_t**       pAccountName
,   ws_size_t*          pcchAccountName
,   ws_char_w_t**       pDomainName
,   ws_size_t*          pcchDomainName
,   SID_NAME_USE*       pNameUse
)
;

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

#ifndef WINSTL_NO_NAMESPACE
namespace security
{

inline
void
free_string(
    ws_char_a_t*    s
)
{
    WinSTL_C_Security_free_string_a(s);
}

inline
BOOL
lookup_account_SID_info(
    ws_char_a_t const*  systemName
,   PSID                psid
,   ws_char_a_t**       pAccountName
,   ws_size_t*          pcchAccountName
,   ws_char_a_t**       pDomainName
,   ws_size_t*          pcchDomainName
,   SID_NAME_USE*       pNameUse
)
{
    return WinSTL_C_Security_lookup_account_SID_info_a(systemName, psid, pAccountName, pcchAccountName, pDomainName, pcchDomainName, pNameUse);
}

} /* namespace security */
#endif /* !WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#if !defined(WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(STLSOFT_NO_NAMESPACE)
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

#endif /* WINSTL_INCL_WINSTL_H_SECURITY_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
