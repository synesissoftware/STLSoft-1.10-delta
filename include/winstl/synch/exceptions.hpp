/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/exceptions.hpp
 *
 * Purpose:     Synchronisation API Library exception(s).
 *
 * Created:     30th May 2006
 * Updated:     31st May 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2006-2010, Matthew Wilson and Synesis Software
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


/** \file winstl/synch/exceptions.hpp
 *
 * \brief [C++ only] Definition of winstl::synchronisation_exception class
 *   (\ref group__library__synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS
#define WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_EXCEPTIONS_MAJOR     2
# define WINSTL_VER_WINSTL_SYNCH_HPP_EXCEPTIONS_MINOR     1
# define WINSTL_VER_WINSTL_SYNCH_HPP_EXCEPTIONS_REVISION  2
# define WINSTL_VER_WINSTL_SYNCH_HPP_EXCEPTIONS_EDIT      17
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/*
[DocumentationStatus:Ready]
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_HPP_ERROR_WINDOWS_EXCEPTIONS
# include <winstl/error/exceptions.hpp>
#endif /* !WINSTL_INCL_WINSTL_HPP_ERROR_WINDOWS_EXCEPTIONS */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** Root exception thrown by
 *   the \ref group__library__synch "Synchronisation" library.
 */
class synchronisation_exception
    : public windows_exception
{
public: // Member Types
    /// The parent exception type
    typedef windows_exception                   parent_class_type;
    /// This type
    typedef synchronisation_exception           class_type;
    /// [DEPRECATED] The condition code type
    ///
    /// \deprecated This will be removed in a future release
    typedef parent_class_type::error_code_type  error_code_type;
    /// The condition code type
    typedef parent_class_type::error_code_type  condition_code_type;

public: // Construction
    synchronisation_exception(ws_char_a_t const* message, condition_code_type error)
        : parent_class_type(message, error)
    {};
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate invalid wait handle(s)
 */
class invalid_wait_handle_exception
    : public synchronisation_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_exception               parent_class_type;
    /// This type
    typedef invalid_wait_handle_exception           class_type;
    /// The condition code type
    typedef parent_class_type::condition_code_type  condition_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param message The message associated with the exception
    /// \param code The condition code associated with the exception
    /// \param waitIndex The index of the handle in a vector wait
    ///   operation. Specify -1 if scalar wait
    invalid_wait_handle_exception(ws_char_a_t const* message, condition_code_type error, int waitIndex)
        : parent_class_type(message, error)
        , waitIndex(waitIndex)
    {};
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);

public: // Fields
    /// The index of the handle in a vector wait operation. -1 if scalar
    /// wait operation
    const int waitIndex;
};

/** Exception thrown to indicate NULL wait handle
 */
class null_wait_handle_exception
    : public invalid_wait_handle_exception
{
public: // Member Types
    /// The parent exception type
    typedef invalid_wait_handle_exception           parent_class_type;
    /// This type
    typedef null_wait_handle_exception              class_type;
    /// The condition code type
    typedef parent_class_type::condition_code_type  condition_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param message The message associated with the exception
    /// \param code The condition code associated with the exception
    /// \param waitIndex The index of the handle in a vector wait
    ///   operation. Specify -1 if scalar wait
    null_wait_handle_exception(ws_char_a_t const* message, condition_code_type error, int waitIndex)
        : parent_class_type(message, error, waitIndex)
    {};
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate invalid wait handle(s)
 */
class duplicate_wait_handle_exception
    : public synchronisation_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_exception               parent_class_type;
    /// This type
    typedef duplicate_wait_handle_exception         class_type;
    /// The condition code type
    typedef parent_class_type::condition_code_type  condition_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param message The message associated with the exception
    /// \param code The condition code associated with the exception
    /// \param firstIndex The first index of the first duplicated handle in
    ///   a vector wait operation
    /// \param secondIndex The second index of the first duplicated handle
    ///   in a vector wait operation
    duplicate_wait_handle_exception(ws_char_a_t const* message, condition_code_type error, ws_size_t firstIndex, ws_size_t secondIndex)
        : parent_class_type(message, error)
        , firstIndex(firstIndex)
        , secondIndex(secondIndex)
    {};
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);

public: // Fields
    /// The first index of the first duplicated handle in a vector wait
    /// operation
    const ws_size_t firstIndex;
    /// The second index of the first duplicated handle in a vector wait
    /// operation
    const ws_size_t secondIndex;
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
