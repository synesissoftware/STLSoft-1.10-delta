/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/auto/functions.h
 *
 * Purpose:     Automation (IDispatch) helper functions.
 *
 * Created:     24th May 2002
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2011, Matthew Wilson and Synesis Software
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


/** \file comstl/auto/functions.h
 *
 * \brief [C++] Automation (IDispatch) helper functions
 *   (\ref group__library__com_automation "COM Automation" Library).
 */

#ifndef COMSTL_INCL_COMSTL_AUTO_H_FUNCTIONS
#define COMSTL_INCL_COMSTL_AUTO_H_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_AUTO_H_FUNCTIONS_MAJOR       1
# define COMSTL_VER_COMSTL_AUTO_H_FUNCTIONS_MINOR       0
# define COMSTL_VER_COMSTL_AUTO_H_FUNCTIONS_REVISION    6
# define COMSTL_VER_COMSTL_AUTO_H_FUNCTIONS_EDIT        9
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <comstl/comstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */

namespace stlsoft
{

namespace comstl_project
{

# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

STLSOFT_INLINE HRESULT comstl_C_IDispatch_put_property(LPDISPATCH pobj, DISPID dispid, UINT cArgs, VARIANT const* args, EXCEPINFO* xi, UINT* pArgErr, LCID lcid)
{
    DISPPARAMS  params;
    DISPID      dispidNamed = DISPID_PROPERTYPUT;

    COMSTL_ASSERT(NULL != pobj);
    COMSTL_ASSERT(cArgs >= 1);
    COMSTL_ASSERT(NULL != args);

    params.cArgs                =   cArgs;
    params.rgvarg               =   stlsoft_const_cast(VARIANT*, args);
    params.cNamedArgs           =   1;
    params.rgdispidNamedArgs    =   &dispidNamed;

    return COMSTL_ITF_CALL(pobj)->Invoke(COMSTL_ITF_THIS(pobj) dispid, COMSTL_IID_2_REF(IID_NULL), lcid, DISPATCH_PROPERTYPUT, &params, NULL, xi, pArgErr);
}

STLSOFT_INLINE HRESULT comstl_C_IDispatch_get_property(LPDISPATCH pobj, DISPID dispid, VARIANT* presult, EXCEPINFO* xi, LCID lcid)
{
    DISPPARAMS  params;

    COMSTL_ASSERT(NULL != pobj);
    COMSTL_ASSERT(NULL != presult);

    params.cArgs                =   0;
    params.rgvarg               =   NULL;
    params.cNamedArgs           =   0;
    params.rgdispidNamedArgs    =   NULL;

    return COMSTL_ITF_CALL(pobj)->Invoke(COMSTL_ITF_THIS(pobj) dispid, COMSTL_IID_2_REF(IID_NULL), lcid, DISPATCH_PROPERTYGET, &params, presult, xi, NULL);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ Functions
 */

#ifdef __cplusplus

inline HRESULT IDispatch_put_property(LPDISPATCH pobj, DISPID dispid, UINT cArgs, VARIANT const* args, EXCEPINFO* xi = NULL, UINT* pArgErr = NULL, LCID lcid = LOCALE_SYSTEM_DEFAULT)
{
    return comstl_C_IDispatch_put_property(pobj, dispid, cArgs, args, xi, pArgErr, lcid);
}

inline HRESULT IDispatch_put_property(LPDISPATCH pobj, DISPID dispid, VARIANT const& arg, EXCEPINFO* xi = NULL, UINT* pArgErr = NULL, LCID lcid = LOCALE_SYSTEM_DEFAULT)
{
    return comstl_C_IDispatch_put_property(pobj, dispid, 1, &arg, xi, pArgErr, lcid);
}

inline HRESULT IDispatch_get_property(LPDISPATCH pobj, DISPID dispid, VARIANT* presult, EXCEPINFO* xi = NULL, LCID lcid = LOCALE_SYSTEM_DEFAULT)
{
    return comstl_C_IDispatch_get_property(pobj, dispid, presult, xi, lcid);
}

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace stlsoft::comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !COMSTL_INCL_COMSTL_AUTO_H_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
