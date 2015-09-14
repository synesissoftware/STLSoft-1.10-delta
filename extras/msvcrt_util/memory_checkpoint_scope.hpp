/* /////////////////////////////////////////////////////////////////////////
 * File:        extras/msvcrt_util/memory_checkpoint_scope.hpp (formerly MWMCkScp.h)
 *
 * Purpose:     Microsoft Visual C++ Runtime Library debug flags scoping
 *              class.
 *
 * Created:     21st October 1994
 * Updated:     12th January 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2009, Matthew Wilson and Synesis Software
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


#ifndef STLSOFT_EXTRAS_INCL_MSVCUTIL_CRT_HPP_MEMORY_CHECKPOINT_SCOPE
#define STLSOFT_EXTRAS_INCL_MSVCUTIL_CRT_HPP_MEMORY_CHECKPOINT_SCOPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_MSVCUTIL_CRT_HPP_MEMORY_CHECKPOINT_SCOPE_MAJOR     2
# define STLSOFT_VER_MSVCUTIL_CRT_HPP_MEMORY_CHECKPOINT_SCOPE_MINOR     0
# define STLSOFT_VER_MSVCUTIL_CRT_HPP_MEMORY_CHECKPOINT_SCOPE_REVISION  1
# define STLSOFT_VER_MSVCUTIL_CRT_HPP_MEMORY_CHECKPOINT_SCOPE_EDIT      18
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

#include <stlsoft/stlsoft.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#ifndef __cplusplus
# error Can only be included in C++ compilation units
#endif /* !__cplusplus */

#if defined(STLSOFT_COMPILER_IS_MSVC)
# if _MSC_VER < 1000
#  error Requires Visual C++ version 4.0 or later
# endif /* _MSC_VER */
#elif defined(STLSOFT_COMPILER_IS_INTEL)
# if __INTEL_COMPILER < 700
#  error Requires Intel C/C++ version 7 or later
# endif /* __INTEL_COMPILER */
#elif defined(STLSOFT_COMPILER_IS_BORLAND)
# if __BORLANDC__ < 0x0550
#  error Requires Intel C/C++ version 5.5 or later
# endif /* __BORLANDC__ */
#elif defined(STLSOFT_COMPILER_IS_MWERKS)
# if (__MWERKS__ & 0xFF00) < 0x2400
#  error Requires Metrowerks CodeWarrior version 7.0 or later
# endif /* __MWERKS__ */
#elif defined(STLSOFT_COMPILER_IS_DMC)
# if __DMC__ < 0x0800
#  error Requires Digital Mars C/C++ version 8.0 or later
# endif /* __DMC__ */
#elif defined(STLSOFT_COMPILER_IS_WATCOM)
# if __WATCOMC__ < 1210
#  error Requires Open Watcom C/C++ version 1.1 or later
# endif /* __DMC__ */
#else
# error Requires Visual C++, Intel C/C++, Borland C/C++, Metrowerks CodeWarrior, Digital Mars C/C++, or Watcom C/C++ compilers
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 2
 */

#include <crtdbg.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{
namespace msvcrt_util
{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** This class scopes memory checkpoint differences.
 * 
 * The constructor takes a checkpoint, and the destructor takes a second and
 * assigns the difference to the memory-state variable passed to the
 * constructor.
 */
class memory_checkpoint_scope
{
public: /// Member Types
    typedef memory_checkpoint_scope class_type;

public: /// Construction
    ss_explicit_k memory_checkpoint_scope(_CrtMemState* diffState)
        : m_diffState(diffState)
    {
        STLSOFT_ASSERT(NULL != diffState);

        _CrtMemCheckpoint(&m_startState);
        m_endState = m_startState;
    }
    ~memory_checkpoint_scope() stlsoft_throw_0()
    {
        _CrtMemCheckpoint(&m_endState);
        _CrtMemDifference(m_diffState, &m_startState, &m_endState);
    }
private:
    memory_checkpoint_scope(class_type const&);
    class_type& operator =(class_type const&);

private:
    _CrtMemState    m_startState;
    _CrtMemState    m_endState;
    _CrtMemState*   m_diffState;
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace msvcrt_util */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_EXTRAS_INCL_MSVCUTIL_CRT_HPP_MEMORY_CHECKPOINT_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */


