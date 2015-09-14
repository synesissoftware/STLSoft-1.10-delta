/* /////////////////////////////////////////////////////////////////////////////
 * File:        compcatutil.h
 *
 * Purpose:     Header file for the component category cleaner API.
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


#ifndef GP_COMCLEAN_H
#define GP_COMCLEAN_H 1

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

#define GP_COMCATCLEAN_VER_MAJOR    1
#define GP_COMCATCLEAN_VER_MINOR    0
#define GP_COMCATCLEAN_VER_REVISON  2

#define GP_COMCATCLEAN_VER          0x00010002

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

typedef BOOL (WINAPI PfnHandleBadKeyA)(LPCSTR, DWORD);
typedef BOOL (WINAPI PfnHandleBadKeyW)(LPCWSTR, DWORD);

#if defined(UNICODE) || \
    defined(_UNICODE)
typedef PfnHandleBadKeyW    PfnHandleBadKey;
#else /* ? UNICODE */
typedef PfnHandleBadKeyA    PfnHandleBadKey;
#endif /* UNICODE || _UNICODE */

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

ULONG WINAPI CompCat_FindBadA(PfnHandleBadKeyA pfn, DWORD param);
ULONG WINAPI CompCat_FindBadW(PfnHandleBadKeyW pfn, DWORD param);

ULONG WINAPI CompCat_DeleteBad(void);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////////
 * Default character encoding functions
 */

#ifdef __cplusplus
# if defined(UNICODE) || \
     defined(_UNICODE)
inline ULONG CompCat_FindBad(PfnHandleBadKey pfn, DWORD param)
{
    return CompCat_FindBadW(pfn, param);
}
# else /* ? UNICODE */
inline ULONG CompCat_FindBad(PfnHandleBadKey pfn, DWORD param)
{
    return CompCat_FindBadA(pfn, param);
}
# endif /* UNICODE || _UNICODE */
#else
# if defined(UNICODE) || \
     defined(_UNICODE)
#  define CompCat_FindBad                           CompCat_FindBadW
# else /* ? UNICODE */
#  define CompCat_FindBad                           CompCat_FindBadA
# endif /* UNICODE || _UNICODE */
#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* GP_COMCLEAN_H */

/* ////////////////////////////////////////////////////////////////////////// */
