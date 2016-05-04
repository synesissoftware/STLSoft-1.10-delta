/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/time/timespan.hpp
 *
 * Purpose:     Definition of the stlsoft::timespan class.
 *
 * Created:     9th May 2014
 * Updated:     14th February 2016
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


/** \file stlsoft/time/timespan.hpp
 *
 * \brief [C++] Definition of the stlsoft::timespan class
 *   (\ref group__library__time "Time" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_TIME_HPP_TIMESPAN
#define STLSOFT_INCL_STLSOFT_TIME_HPP_TIMESPAN

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_TIME_HPP_TIMESPAN_MAJOR    0
# define STLSOFT_VER_STLSOFT_TIME_HPP_TIMESPAN_MINOR    0
# define STLSOFT_VER_STLSOFT_TIME_HPP_TIMESPAN_REVISION 2
# define STLSOFT_VER_STLSOFT_TIME_HPP_TIMESPAN_EDIT     3
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

#ifndef STLSOFT_INCL_H_TIME
# define STLSOFT_INCL_H_TIME
# include <time.h>
#endif /* !STLSOFT_INCL_H_TIME */

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

class timespan
{
public: // Types
    typedef timespan        class_type;
    typedef ss_sint64_t     span_type;

public: // Construction
    ss_explicit_k
    timespan(
        span_type microseconds
    );

private:
    class_type& operator =(class_type const&); // proscribed

public: // Generators
    static
    timespan
    seconds(
        span_type seconds
    );

    static
    timespan
    milliseconds(
        span_type seconds
    );

    static
    timespan
    microseconds(
        span_type seconds
    );

public: // Comparison
    span_type
    compare(
        class_type const& rhs
    ) const;

public: // Fields
    span_type const     Microseconds;
};

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

inline
bool
operator ==(
    timespan const& lhs
,   timespan const& rhs
)
{
    return 0 == lhs.compare(rhs);
}

inline
bool
operator !=(
    timespan const& lhs
,   timespan const& rhs
)
{
    return 0 != lhs.compare(rhs);
}

inline
bool
operator <(
    timespan const& lhs
,   timespan const& rhs
)
{
    return lhs.compare(rhs) < 0;
}

inline
bool
operator <=(
    timespan const& lhs
,   timespan const& rhs
)
{
    return lhs.compare(rhs) <= 0;
}

inline
bool
operator >(
    timespan const& lhs
,   timespan const& rhs
)
{
    return lhs.compare(rhs) > 0;
}

inline
bool
operator >=(
    timespan const& lhs
,   timespan const& rhs
)
{
    return lhs.compare(rhs) >= 0;
}

inline
timespan
operator +(
    timespan const& lhs
,   timespan const& rhs
)
{
    return timespan(lhs.Microseconds + rhs.Microseconds);
}

inline
timespan
operator -(
    timespan const& lhs
,   timespan const& rhs
)
{
    return timespan(lhs.Microseconds - rhs.Microseconds);
}

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline
timespan::timespan(
    timespan::span_type microseconds
)
    : Microseconds(microseconds)
{}

inline
/* static */
timespan
timespan::seconds(
    timespan::span_type seconds
)
{
    return timespan(seconds * 1000000);
}

inline
/* static */
timespan
timespan::milliseconds(
    timespan::span_type seconds
)
{
    return timespan(seconds * 1000);
}

inline
/* static */
timespan
timespan::microseconds(
    timespan::span_type seconds
)
{
    return timespan(seconds);
}

inline
timespan::span_type
timespan::compare(
    timespan const& rhs
) const
{
    return Microseconds - rhs.Microseconds;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_TIME_HPP_TIMESPAN */

/* ///////////////////////////// end of file //////////////////////////// */
