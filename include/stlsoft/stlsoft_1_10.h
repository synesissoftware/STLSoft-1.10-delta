/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/stlsoft_1_10.h
 *
 * Purpose:     Root header for the STLSoft libraries. Performs various
 *              compiler and platform discriminations, and definitions of
 *              types.
 *
 * Created:     15th January 2002
 * Updated:     4th May 2016
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2002-2016, Matthew Wilson and Synesis Software
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


/** \file stlsoft/stlsoft_1_10.h
 *
 * \brief [C, C++] The root header for the 1.10 alpha releases of the
 *   \ref group__project__stlsoft "STLSoft" project.
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT_1_10
#define STLSOFT_INCL_STLSOFT_H_STLSOFT_1_10

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * Library version verification
 */

#if _STLSOFT_VER >= 0x010a01ff
# error This file - stlsoft_1_10.h - is now obsolete, because STLSoft version is 1.10+
#endif /* _STLSOFT_VER */

/* /////////////////////////////////////////////////////////////////////////
 * Feature Management - 1
 */

#if defined(SYNESIS_ALL_FOSS_TRACE_INCLUDE) && \
    !defined(STLSOFT_TRACE_INCLUDE)
# define STLSOFT_TRACE_INCLUDE
#endif /* SYNESIS_ALL_FOSS_TRACE_INCLUDE && !STLSOFT_TRACE_INCLUDE */

#if defined(STLSOFT_TRACE_INCLUDE) && \
    !defined(STLSOFT_PPF_pragma_message_SUPPORT)
# undef STLSOFT_TRACE_INCLUDE
#endif /* STLSOFT_TRACE_INCLUDE */

#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * STLSoft 1.10 version
 */

/** \def _STLSOFT_1_10_VER_MAJOR
 * \brief The major version number of STLSoft 1.10 alpha
 *
 * A change to the major version component implies that a dramatic change
 * has occurred in the libraries, such that considerable changes to source
 * dependent on previous versions would need to be effected.
 */

/** \def _STLSOFT_1_10_VER_MINOR
 * \brief The minor version number of STLSoft 1.10 alpha
 *
 * A change to the minor version component imply that a significant change
 * has occurred to the libraries, either in the addition of new functionality
 * or in the destructive change to one or more components such that
 * recompilation and code change may be necessitated.
 */

/** \def _STLSOFT_1_10_VER_REVISION
 * \brief The revision version number of STLSoft 1.10 alpha
 *
 * A change to the revision version component imply that a bug has been
 * fixed. Dependent code should be recompiled in order to pick up the
 * changes.
 */

/** \def _STLSOFT_1_10_VER
 * \brief The current composite version number of STLSoft 1.10 alpha
 *
 * In addition to the individual version symbols - _STLSOFT_1_10_VER_MAJOR,
 * _STLSOFT_1_10_VER_MINOR and _STLSOFT_1_10_VER_REVISION - a composite
 * symbol _STLSOFT_1_10_VER is defined, where:
 *  - bits 24-31: the major version
 *  - bits 16-23: the minor version
 *  - bits 8-15: the revision version
 *  - bits 0-7: the beta number; if not a beta, it is 0xFF
 */


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define _STLSOFT_1_10_VER_1_10_1_A01       0x010a0101  /*!< Version 1.10.1 alpha 1 (24th Oct 2008) */
# define _STLSOFT_1_10_VER_1_10_1_A02       0x010a0102  /*!< Version 1.10.1 alpha 2 (27th Oct 2008) */
# define _STLSOFT_1_10_VER_1_10_1_A03       0x010a0103  /*!< Version 1.10.1 alpha 3 (29th Oct 2008) */
# define _STLSOFT_1_10_VER_1_10_1_A05       0x010a0105  /*!< Version 1.10.1 alpha 5 (9th Dec 2008) */
# define _STLSOFT_1_10_VER_1_10_1_A06       0x010a0106  /*!< Version 1.10.1 alpha 6 (19th Dec 2008) */
# define _STLSOFT_1_10_VER_1_10_1_A08       0x010a0108  /*!< Version 1.10.1 alpha 8 (24th Feb 2009) */
# define _STLSOFT_1_10_VER_1_10_1_A09       0x010a0109  /*!< Version 1.10.1 alpha 9 (6th Mar 2009) */
# define _STLSOFT_1_10_VER_1_10_1_A10       0x010a010a  /*!< Version 1.10.1 alpha 10 (9th Mar 2009) */
# define _STLSOFT_1_10_VER_1_10_1_A11       0x010a010b  /*!< Version 1.10.1 alpha 11 (17th May 2009) */
# define _STLSOFT_1_10_VER_1_10_1_A13       0x010a010d  /*!< Version 1.10.1 alpha 13 (19th Jan 2010) */
# define _STLSOFT_1_10_VER_1_10_1_A14       0x010a010e  /*!< Version 1.10.1 alpha 14 (27th Apr 2010) */
# define _STLSOFT_1_10_VER_1_10_1_A15       0x010a010f  /*!< Version 1.10.1 alpha 15 (14th October 2010) */
# define _STLSOFT_1_10_VER_1_10_1_A16       0x010a0110  /*!< Version 1.10.1 alpha 16 (30th July 2012) */
# define _STLSOFT_1_10_VER_1_10_1_A17       0x010a0111  /*!< Version 1.10.1 alpha 17 (16th November 2013) */
# define _STLSOFT_1_10_VER_1_10_1_A18       0x010a0112  /*!< Version 1.10.1 alpha 18 (13th May 2014) */
# define _STLSOFT_1_10_VER_1_10_1_A19       0x010a0113  /*!< Version 1.10.1 alpha 19 (23rd August 2015) */
# define _STLSOFT_1_10_VER_1_10_1_A20       0x010a0114  /*!< Version 1.10.1 alpha 20 (4th May 2016) */
# define _STLSOFT_1_10_VER_1_10_1_A21       0x010a0115  /*!< Version 1.10.1 alpha 21 (4th May 2016) */
# define _STLSOFT_1_10_VER_1_10_1_A22       0x010a0116  /*!< Version 1.10.1 alpha 22 (4th May 2016) */
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

#define _STLSOFT_1_10_VER_MAJOR         1
#define _STLSOFT_1_10_VER_MINOR         10
#define _STLSOFT_1_10_VER_REVISION      0
#define _STLSOFT_1_10_VER               _STLSOFT_1_10_VER_1_10_1_A22

/* /////////////////////////////////////////////////////////////////////////
 * Symbol Management
 */

#ifdef _STLSOFT_NO_NAMESPACES
# ifdef __cplusplus
#  ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
#   pragma message("The use of the symbol _STLSOFT_NO_NAMESPACES is deprecated, and will be an error in a future version of STLSoft. Instead, use the symbol STLSOFT_NO_NAMESPACES")
#  endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT */
# endif /* __cplusplus */
# ifndef STLSOFT_NO_NAMESPACES
#  define STLSOFT_NO_NAMESPACES
# endif /* !STLSOFT_NO_NAMESPACES */
#endif /* _STLSOFT_NO_NAMESPACES */

#ifdef _STLSOFT_NO_NAMESPACE
# ifdef __cplusplus
#  ifdef STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
#   pragma message("The use of the symbol _STLSOFT_NO_NAMESPACE is deprecated, and will be an error in a future version of STLSoft. Instead, use the symbol STLSOFT_NO_NAMESPACE")
#  endif /* STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT */
# endif /* __cplusplus */
# ifndef STLSOFT_NO_NAMESPACE
#  define STLSOFT_NO_NAMESPACE
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT_1_10 */

/* ///////////////////////////// end of file //////////////////////////// */
