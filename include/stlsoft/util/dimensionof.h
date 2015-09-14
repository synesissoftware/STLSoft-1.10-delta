/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/dimensionof.h
 *
 * Purpose:     Definition of the macro dimensionof().
 *
 * Created:     10th February 2010
 * Updated:     2nd June 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2010, Matthew Wilson and Synesis Software
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


/** \file stlsoft/util/dimensionof.h
 *
 * \brief [C++ only] Definition of the macro dimensionof()
 *   (\ref group__library__conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_INCL_H_RAND
#define STLSOFT_INCL_STLSOFT_UTIL_INCL_H_RAND

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_RAND_MAJOR       1
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_RAND_MINOR       0
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_RAND_REVISION    2
# define STLSOFT_VER_STLSOFT_UTIL_INCL_H_RAND_EDIT        5
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
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
 * Macros
 */

/** \def dimensionof(ar)
 *
 * \brief Evaluates, at compile time, to the number of elements within the
 *   given vector entity, but rejects application to pointers and (in C++
 *   compilation) instances of types that define the subscript operator.
 *
 * \param ar The literal array whose size is to be determined
 *
 * Is it used as follows:
 *
\htmlonly
<pre>
int               ai[20];
int               i     = 32;
int               *pi   = &i;
std::vector<int>  vi;
size_t            s_ai  = dimensionof(ai);   // Ok
size_t            s_i   = dimensionof(i);    // Error
size_t            s_pi  = dimensionof(pi);   // Error
size_t            s_vi  = dimensionof(vi);   // Error
</pre>
\endhtmlonly
 *
 * \note This macro is equivalent to STLSOFT_NUM_ELEMENTS(). It is defined
 *   in an explicit way, by inclusion of stlsoft/util/dimensionof.h, to
 *   avoid conflict with any macros (or other symbols) that may share the
 *   same name.
 */   
#define dimensionof(ar)             STLSOFT_NUM_ELEMENTS(ar)

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_UTIL_INCL_H_RAND */

/* ///////////////////////////// end of file //////////////////////////// */
