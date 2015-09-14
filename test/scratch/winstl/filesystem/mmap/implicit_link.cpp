/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the mmap project.
 *
 * Created:     27th August 2010
 * Updated:     27th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat Header Files */
#include <fastformat/implicit_link.h>

/* Pantheios Header Files */
#include <platformstl/platformstl.h>
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.simple.h>
#include <pantheios/implicit_link/be.N.h>
#include <pantheios/implicit_link/bec.console.h>
#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <pantheios/implicit_link/be.syslog.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <pantheios/implicit_link/bec.WindowsDebugger.h>
# include <pantheios/implicit_link/bec.WindowsSysLog.h>
#endif /* operating system */

/* UNIXem Header Files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* operating system */

/* ////////////////////////////////////////////////////////////////////// */

/* Pantheios Header Files */
#include <pantheios/backends/be.N.h>
#include <pantheios/backends/bec.console.h>
#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <pantheios/backends/bec.syslog.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <pantheios/backends/bec.WindowsDebugger.h>
# include <pantheios/backends/bec.WindowsSyslog.h>
#endif /* operating system */

pan_be_N_t  PAN_BE_N_BACKEND_LIST[] =
{
    PANTHEIOS_BE_N_FILTERED_ENTRY(1, pantheios_be_console, PANTHEIOS_SEV_WARNING, 0),
#if defined(PLATFORMSTL_OS_IS_UNIX)
    PANTHEIOS_BE_N_STDFORM_ENTRY(3, pantheios_be_syslog, PANTHEIOS_BE_N_F_IGNORE_INIT_FAILURE),
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
    PANTHEIOS_BE_N_STDFORM_ENTRY(2, pantheios_be_WindowsDebugger, 0),
    PANTHEIOS_BE_N_STDFORM_ENTRY(3, pantheios_be_WindowsSyslog, PANTHEIOS_BE_N_F_IGNORE_INIT_FAILURE),
#endif /* operating system */
  
    PANTHEIOS_BE_N_TERMINATOR_ENTRY
};

/* ///////////////////////////// end of file //////////////////////////// */
