/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/bitwise_zero_init.hpp
 *
 * Purpose:     Simplifies bitwise zero-initialisation of user-defined
 *              types.
 *
 * Created:     11th May 2011
 * Updated:     24th July 2012
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2011-2012, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/rand.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::bitwise_zero_init<> function
 *   template
 *   (\ref group__library__utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_BITWISE_ZERO_INIT
#define STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_BITWISE_ZERO_INIT

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_BITWISE_ZERO_INIT_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_BITWISE_ZERO_INIT_MINOR    0
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_BITWISE_ZERO_INIT_REVISION 3
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_BITWISE_ZERO_INIT_EDIT     4
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

/** This class template may be used along with the CRTP to zero-initialise
 * types that are entirely comprised of types that can be initialised via
 * <code>memset()</code>.
 */
template <typename T>
struct bitwise_zero_init
{
protected:
    bitwise_zero_init()
    {
        T* pt = static_cast<T*>(this);

        ::memset(pt, 0, sizeof(T));
    }
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_BITWISE_ZERO_INIT */

/* ///////////////////////////// end of file //////////////////////////// */
