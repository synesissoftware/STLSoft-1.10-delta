/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/module_functions.h
 *
 * Purpose:     Module functions.
 *
 * Created:     4th November 2014
 * Updated:     4th May 2016
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014-2016, Matthew Wilson and Synesis Software
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


/** \file winstl/system/module_functions.h
 *
 * \brief [C, C++] Module functions
 *   (\ref group__library__system "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_MODULE_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYSTEM_H_MODULE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_H_MODULE_FUNCTIONS_MAJOR      1
# define WINSTL_VER_WINSTL_SYSTEM_H_MODULE_FUNCTIONS_MINOR      0
# define WINSTL_VER_WINSTL_SYSTEM_H_MODULE_FUNCTIONS_REVISION   2
# define WINSTL_VER_WINSTL_SYSTEM_H_MODULE_FUNCTIONS_EDIT       2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION
# include <winstl/internal/windows_version.h>
#endif /* !WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(_WINSTL_NO_NAMESPACE) && \
    !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
# if defined(_STLSOFT_NO_NAMESPACE)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#ifdef __cplusplus
namespace ximpl_WinSTL_system_module_functions
{
#endif /* __cplusplus */

STLSOFT_INLINE
HMODULE
WinSTL_C_System_GetModuleFromAddress_MBI_(
    LPCVOID address
)
{
    MEMORY_BASIC_INFORMATION mbi = { 0 };

    if(0 != STLSOFT_NS_GLOBAL(VirtualQuery)(address, &mbi, sizeof(mbi)))
    {
        return STLSOFT_REINTERPRET_CAST(HMODULE, mbi.AllocationBase);
    }

    return NULL;
}

STLSOFT_INLINE
HMODULE
WinSTL_C_System_GetModuleFromAddress_GMHE_(
    LPCVOID address
)
{
#if _WIN32_WINNT > 0x0500 || \
    defined(WINBASE_DECLARE_GET_MODULE_HANDLE_EX)

    HMODULE hModule;

    if(STLSOFT_NS_GLOBAL(GetModuleHandleEx)(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, STLSOFT_STATIC_CAST(LPCTSTR, address), &hModule))
    {
        return hModule;
    }
#endif

    return NULL;
}

#ifdef __cplusplus
} /* namespace ximpl_WinSTL_system_module_functions */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * C functions
 */

/** 
 *
 * \param
 *
 * \return 
 */
STLSOFT_INLINE
HMODULE
WinSTL_C_System_GetModuleFromAddress(
    LPCVOID address
)
{
#ifdef __cplusplus
    using namespace ximpl_WinSTL_system_module_functions;
#endif /* __cplusplus */

    OSVERSIONINFO   osvi;

    osvi.dwOSVersionInfoSize = sizeof(osvi);

    if( WinSTL_C_internal_GetVersionEx(&osvi) &&
        (   osvi.dwMajorVersion > 5 ||
            (   osvi.dwMajorVersion == 5 &&
                osvi.dwMinorVersion >= 1)))
    {
        HMODULE const hModule = WinSTL_C_System_GetModuleFromAddress_GMHE_(address);

        if(NULL != hModule)
        {
            return hModule;
        }
    }

    return WinSTL_C_System_GetModuleFromAddress_MBI_(address);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifdef __cplusplus

inline
HMODULE
get_module_from_address(
    LPCVOID address
)
{
    return WinSTL_C_System_GetModuleFromAddress(address);
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_MODULE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
