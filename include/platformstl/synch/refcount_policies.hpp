/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/synch/refcount_policies.hpp
 *
 * Purpose:     Reference-counting policies.
 *
 * Created:     31st May 2009
 * Updated:     6th July 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2009-2010, Matthew Wilson and Synesis Software
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


/** \file platformstl/synch/refcount_policies.hpp
 *
 * \brief [C++ only] Reference-counting policies
 *   (\ref group__library__synch "Synchronisation" Library).
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES
#define PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES_MAJOR      1
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES_MINOR      0
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES_REVISION   3
# define PLATFORMSTL_VER_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES_EDIT       8
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <platformstl/platformstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICY_SINGLE_THREADED
# include <platformstl/synch/refcount_policy_single_threaded.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICY_SINGLE_THREADED */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_HPP_REFCOUNT_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */
