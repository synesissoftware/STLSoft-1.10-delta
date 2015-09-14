/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.unit.platformstl.time.datetime project.
 *
 * Created:     7th May 2014
 * Updated:     8th May 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/implicit_link.h>

/* UNIXEM header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
	defined(_WIN32)
# include <unixem/implicit_link.h>
#endif

/* ///////////////////////////// end of file //////////////////////////// */
