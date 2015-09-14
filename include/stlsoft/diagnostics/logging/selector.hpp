/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/diagnostics/logging/selector.hpp
 *
 * Purpose:     Diagnostic logging abstraction header.
 *
 * Created:     6th June 2011
 * Updated:     15th July 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2000-2014, Matthew Wilson and Synesis Software
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


/** \file stlsoft/diagnostics/logging/selector.hpp
 *
 * \brief [C++ only] Diagnostic logging abstraction header
 *   (\ref group__library__diagnostics__logging "Diagnostic Logging" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_DIAGNOSTICS_LOGGING_HPP_SELECTOR
#define STLSOFT_INCL_STLSOFT_DIAGNOSTICS_LOGGING_HPP_SELECTOR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_LOGGING_HPP_SELECTOR_MAJOR     1
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_LOGGING_HPP_SELECTOR_MINOR     0
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_LOGGING_HPP_SELECTOR_REVISION  1
# define STLSOFT_VER_STLSOFT_DIAGNOSTICS_LOGGING_HPP_SELECTOR_EDIT      2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#if defined(PANTHEIOS_VER) && \
    !defined(STLSOFT_DIAGNOSTICS_NO_USE_PANTHEIOS)
# define STLSOFT_DIAGNOSTICS_USE_PANTHEIOS
#endif /* PANTHEIOS_VER && !STLSOFT_DIAGNOSTICS_NO_USE_PANTHEIOS */

#ifdef STLSOFT_DIAGNOSTICS_USE_PANTHEIOS
# include <pantheios/pantheios.h>
#endif /* STLSOFT_DIAGNOSTICS_USE_PANTHEIOS */

#ifndef STLSOFT_INCL_H_STDARG
# define STLSOFT_INCL_H_STDARG
# include <stdarg.h>
#endif /* !STLSOFT_INCL_H_STDARG */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

namespace diagnostics
{
namespace logging
{

#ifdef STLSOFT_DIAGNOSTICS_USE_PANTHEIOS

using ::pantheios::emergency;
using ::pantheios::alert;
using ::pantheios::critical;
using ::pantheios::error;
using ::pantheios::warning;
using ::pantheios::notice;
using ::pantheios::informational;
using ::pantheios::debug;

using ::pantheios::logprintf;
using ::pantheios::logvprintf;
using ::pantheios::logputs;

#else /* ? STLSOFT_DIAGNOSTICS_USE_PANTHEIOS */

namespace ximpl_diagnostics_logging
{

    template <int L>
    struct level_t
    {
        operator int() const
        {
            return L;
        }
    };

} /* namespace ximpl_diagnostics_logging */

static ximpl_diagnostics_logging::level_t<0> emergency;
static ximpl_diagnostics_logging::level_t<1> alert;
static ximpl_diagnostics_logging::level_t<2> critical;
static ximpl_diagnostics_logging::level_t<3> error;
static ximpl_diagnostics_logging::level_t<4> warning;
static ximpl_diagnostics_logging::level_t<5> notice;
static ximpl_diagnostics_logging::level_t<6> informational;
static ximpl_diagnostics_logging::level_t<7> debug;

void logputs(
    int         severity
,   char const* message
);
void logprintf(
    int         severity
,   char const* fmt
,   ...
);
void logvprintf(
    int         severity
,   char const* fmt
,   va_list     args
);

#endif /* STLSOFT_DIAGNOSTICS_USE_PANTHEIOS */

} /* namespace logging */
} /* namespace diagnostics */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
namespace stlsoftlog = ::stlsoft::diagnostics::logging;
#else /* ? !STLSOFT_NO_NAMESPACE */
namespace stlsoftlog = diagnostics::logging;
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_DIAGNOSTICS_LOGGING_HPP_SELECTOR */

/* ///////////////////////////// end of file //////////////////////////// */
