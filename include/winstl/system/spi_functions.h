/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/spi_functions.h
 *
 * Purpose:     SystemParametersInfo() facade functions.
 *
 * Created:     18th May 1995
 * Updated:     6th November 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1995-2014, Matthew Wilson and Synesis Software
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


/** \file winstl/system/system_version.h
 *
 * \brief [C++ only] SystemParametersInfo() facade functions
 *   (\ref group__library__system "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_H_SPI_FUNCTIONS
#define WINSTL_INCL_WINSTL_SYSTEM_H_SPI_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_H_SPI_FUNCTIONS_MAJOR     1
# define WINSTL_VER_WINSTL_SYSTEM_H_SPI_FUNCTIONS_MINOR     0
# define WINSTL_VER_WINSTL_SYSTEM_H_SPI_FUNCTIONS_REVISION  1
# define WINSTL_VER_WINSTL_SYSTEM_H_SPI_FUNCTIONS_EDIT      1
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
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
 * General functions
 */

/* BOOL */

STLSOFT_INLINE
BOOL
WinSTL_C_spi_read_value_BOOL(
    UINT    action
,   LPBOOL  value
)
{
    WINSTL_ASSERT(NULL != value);

    return STLSOFT_NS_GLOBAL(SystemParametersInfo)(action, 0u, STLSOFT_C_CAST(LPVOID, value), 0);
}

STLSOFT_INLINE
BOOL
WinSTL_C_spi_set_value_BOOL_via_pvParam(
    UINT    action
,   BOOL    value
,   UINT    fWinIni
)
{
    return STLSOFT_NS_GLOBAL(SystemParametersInfo)(action, 0u, STLSOFT_C_CAST(LPVOID, value), fWinIni);
}

STLSOFT_INLINE
BOOL
WinSTL_C_spi_set_value_BOOL_via_uiParam(
    UINT    action
,   BOOL    value
,   UINT    fWinIni
)
{
    return STLSOFT_NS_GLOBAL(SystemParametersInfo)(action, STLSOFT_C_CAST(UINT, value), NULL, fWinIni);
}

/* DWORD */

STLSOFT_INLINE
BOOL
WinSTL_C_spi_read_value_DWORD(
    UINT    action
,   LPDWORD value
)
{
    WINSTL_ASSERT(NULL != value);

    return STLSOFT_NS_GLOBAL(SystemParametersInfo)(action, 0u, STLSOFT_C_CAST(LPVOID, value), 0);
}

STLSOFT_INLINE
BOOL
WinSTL_C_spi_set_value_DWORD_via_pvParam(
    UINT    action
,   DWORD   value
,   UINT    fWinIni
)
{
    return STLSOFT_NS_GLOBAL(SystemParametersInfo)(action, 0u, STLSOFT_C_CAST(LPVOID, &value), fWinIni);
}

STLSOFT_INLINE
BOOL
WinSTL_C_spi_set_value_UINT_via_uiParam(
    UINT    action
,   UINT    value
,   UINT    fWinIni
)
{
    return STLSOFT_NS_GLOBAL(SystemParametersInfo)(action, value, NULL, fWinIni);
}

/* /////////////////////////////////////////////////////////////////////////
 * System property-specific functions
 */

/* SPI_G/SETKEYBOARDCUES */

STLSOFT_INLINE
BOOL
WinSTL_C_spi_GETKEYBOARDCUES(
    BOOL*   enableCues
)
{
#ifndef SPI_GETKEYBOARDCUES
    int const SPI_GETKEYBOARDCUES = 0x100A;
#endif

    WINSTL_ASSERT(NULL != enableCues);

    return WinSTL_C_spi_read_value_BOOL(SPI_GETKEYBOARDCUES, enableCues);
}

STLSOFT_INLINE
BOOL
WinSTL_C_spi_SETKEYBOARDCUES(
    BOOL    enableCues
,   UINT    fWinIni
)
{
#ifndef SPI_SETKEYBOARDCUES
    int const SPI_SETKEYBOARDCUES = 0x100B;
#endif

    return WinSTL_C_spi_set_value_BOOL_via_pvParam(SPI_SETKEYBOARDCUES, enableCues, fWinIni);
}

#ifdef __cplusplus

inline
BOOL
spi_GETKEYBOARDCUES(
    bool*   enableCues
)
{
    WINSTL_ASSERT(NULL != enableCues);

    BOOL  v;
    BOOL  r = WinSTL_C_spi_GETKEYBOARDCUES(&v);

    if(r)
    {
        *enableCues = !(!v);
    }

    return r;
}

inline
BOOL
spi_SETKEYBOARDCUES(
    bool    enableCues
,   UINT    fWinIni = 0
)
{
    return WinSTL_C_spi_SETKEYBOARDCUES(enableCues, fWinIni);
}

#endif /* __cplusplus */


/* SPI_G/SETKEYBOARDDELAY */

STLSOFT_INLINE
BOOL
WinSTL_C_spi_GETKEYBOARDDELAY(
    DWORD*  delay
)
{
#ifndef SPI_GETKEYBOARDDELAY
    int const SPI_GETKEYBOARDDELAY = 22;
#endif

    WINSTL_ASSERT(NULL != delay);

    *delay = 0;

    return WinSTL_C_spi_read_value_DWORD(SPI_GETKEYBOARDDELAY, delay);
}

STLSOFT_INLINE
BOOL
WinSTL_C_spi_SETKEYBOARDDELAY(
    DWORD   delay
,   UINT    fWinIni
)
{
#ifndef SPI_SETKEYBOARDDELAY
    int const SPI_SETKEYBOARDDELAY = 23;
#endif

    return WinSTL_C_spi_set_value_UINT_via_uiParam(SPI_SETKEYBOARDDELAY, STLSOFT_STATIC_CAST(UINT, delay), fWinIni);
}

#ifdef __cplusplus

inline
BOOL
spi_GETKEYBOARDDELAY(
    DWORD*  delay
)
{
    WINSTL_ASSERT(NULL != delay);

    return WinSTL_C_spi_GETKEYBOARDDELAY(delay);
}

inline
BOOL
spi_SETKEYBOARDDELAY(
    DWORD   delay
,   UINT    fWinIni = 0
)
{
    return WinSTL_C_spi_SETKEYBOARDDELAY(delay, fWinIni);
}

#endif /* __cplusplus */


/* SPI_G/SETKEYBOARDSPEED */

STLSOFT_INLINE
BOOL
WinSTL_C_spi_GETKEYBOARDSPEED(
    DWORD*  speed
)
{
#ifndef SPI_GETKEYBOARDSPEED
    int const SPI_GETKEYBOARDSPEED = 10;
#endif

    WINSTL_ASSERT(NULL != speed);

    *speed = 0;

    return WinSTL_C_spi_read_value_DWORD(SPI_GETKEYBOARDSPEED, speed);
}

STLSOFT_INLINE
BOOL
WinSTL_C_spi_SETKEYBOARDSPEED(
    DWORD   speed
,   UINT    fWinIni
)
{
#ifndef SPI_SETKEYBOARDSPEED
    int const SPI_SETKEYBOARDSPEED = 11;
#endif

    return WinSTL_C_spi_set_value_UINT_via_uiParam(SPI_SETKEYBOARDSPEED, STLSOFT_STATIC_CAST(UINT, speed), fWinIni);
}

#ifdef __cplusplus

inline
BOOL
spi_GETKEYBOARDSPEED(
    DWORD*  speed
)
{
    WINSTL_ASSERT(NULL != speed);

    return WinSTL_C_spi_GETKEYBOARDSPEED(speed);
}

inline
BOOL
spi_SETKEYBOARDSPEED(
    DWORD   speed
,   UINT    fWinIni = 0
)
{
    return WinSTL_C_spi_SETKEYBOARDSPEED(speed, fWinIni);
}

#endif /* __cplusplus */


/* SPI_G/SETKEYBOARDPREF */

STLSOFT_INLINE
BOOL
WinSTL_C_spi_GETKEYBOARDPREF(
    BOOL*   enablePref
)
{
#ifndef SPI_GETKEYBOARDPREF
    int const SPI_GETKEYBOARDPREF = 68;
#endif

    WINSTL_ASSERT(NULL != enablePref);

    return WinSTL_C_spi_read_value_BOOL(SPI_GETKEYBOARDPREF, enablePref);
}

STLSOFT_INLINE
BOOL
WinSTL_C_spi_SETKEYBOARDPREF(
    BOOL    enablePref
,   UINT    fWinIni
)
{
#ifndef SPI_SETKEYBOARDPREF
    int const SPI_SETKEYBOARDPREF = 69;
#endif

    return WinSTL_C_spi_set_value_BOOL_via_pvParam(SPI_SETKEYBOARDPREF, enablePref, fWinIni);
}

#ifdef __cplusplus

inline
BOOL
spi_GETKEYBOARDPREF(
    bool*   enablePref
)
{
    WINSTL_ASSERT(NULL != enablePref);

    BOOL  v;
    BOOL  r = WinSTL_C_spi_GETKEYBOARDPREF(&v);

    if(r)
    {
        *enablePref = !(!v);
    }

    return r;
}

inline
BOOL
spi_SETKEYBOARDPREF(
    bool    enablePref
,   UINT    fWinIni = 0
)
{
    return WinSTL_C_spi_SETKEYBOARDPREF(enablePref, fWinIni);
}

#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#ifdef __cplusplus
#else /* ? __cplusplus */
#endif /* __cplusplus */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_H_SPI_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
