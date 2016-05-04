/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception/special/thread_completion_exception.hpp
 *
 * Purpose:     Defines the thread_completion_exception exception class,
 *              which is used to transfer control from a lower to a higher
 *              scope, utilising the frame cleanup mechanism.
 *
 * Created:     23rd July 2009
 * Updated:     14th February 2016
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2009-2016, Matthew Wilson and Synesis Software
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


/** \file stlsoft/exception/special/thread_completion_exception.hpp
 *
 * \brief [C++] Defines the thread_completion_exception exception class
 *   (\ref group__library__exception "Exception" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_EXCEPTIONS_SPECIAL_HPP_THREAD_COMPLETION_EXCEPTION
#define STLSOFT_INCL_STLSOFT_EXCEPTIONS_SPECIAL_HPP_THREAD_COMPLETION_EXCEPTION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_SPECIAL_HPP_THREAD_COMPLETION_EXCEPTION_MAJOR       1
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_SPECIAL_HPP_THREAD_COMPLETION_EXCEPTION_MINOR       0
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_SPECIAL_HPP_THREAD_COMPLETION_EXCEPTION_REVISION    1
# define STLSOFT_VER_STLSOFT_EXCEPTIONS_SPECIAL_HPP_THREAD_COMPLETION_EXCEPTION_EDIT        3
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

#ifndef STLSOFT_INCL_EXCEPTION
# define STLSOFT_INCL_EXCEPTION
# include <exception>                       // for std::runtime_error
#endif /* !STLSOFT_INCL_EXCEPTION */

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

class thread_completion_exception
    : public std::exception
{
public: // Types
    typedef std::exception                  parent_class_type;
    typedef thread_completion_exception     class_type;

public: // Construction
    /// Constructs an instance from the given errno value
    ss_explicit_k
    thread_completion_exception(int completionCode)
        : parent_class_type()
        , CompletionCode(completionCode)
    {}
private:
    class_type& operator =(class_type const&);

public: // Overrides
    /* virtual */ char const* what() const stlsoft_throw_0()
    {
        return "thread completed";
    }

private: // Implementation

public: // Fields
    int const   CompletionCode;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTIONS_SPECIAL_HPP_THREAD_COMPLETION_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */
