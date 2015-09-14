/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/tr1/smartptr/scoped_ptr.hpp (adapted from stlsoft/memory/auto_destructor.hpp)
 *
 * Purpose:     Defines the scoped_ptr class template.
 *
 * Created:     1st November 1994
 * Updated:     31st May 2010
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 1994-2010, Matthew Wilson and Synesis Software
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


/** \file stlsoft/tr1/smartptr/scoped_ptr.hpp
 *
 * \brief [C++ only] Defines the scoped_ptr class template.
 *   (\ref group__library__smart_pointer "Smart Pointer" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_TR1_SMARTPTR_HPP_SCOPED_PTR
#define STLSOFT_INCL_STLSOFT_TR1_SMARTPTR_HPP_SCOPED_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_TR1_SMARTPTR_HPP_SCOPED_PTR_MAJOR      6
# define STLSOFT_VER_STLSOFT_TR1_SMARTPTR_HPP_SCOPED_PTR_MINOR      1
# define STLSOFT_VER_STLSOFT_TR1_SMARTPTR_HPP_SCOPED_PTR_REVISION   2
# define STLSOFT_VER_STLSOFT_TR1_SMARTPTR_HPP_SCOPED_PTR_EDIT       82
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

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL
# include <stlsoft/util/operator_bool.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_OPERATOR_BOOL */

/* /////////////////////////////////////////////////////////////////////////
 * Code Coverage
 */

#ifdef STLSOFT_USE_XCOVER
namespace
{
    class register_with_xcover
    {
    public:
        register_with_xcover()
        {
            XCOVER_CREATE_FILE_ALIAS("scoped_ptr");
        }

    } instance;
}
#endif 

/* /////////////////////////////////////////////////////////////////////////
 * Warnings
 */

#include <stlsoft/internal/warnings/push/nothrow_throws_.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
namespace tr1
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class scoped_ptr
/** This class acts as an automatic frame scope variable that manages
 * heap-allocated object instances.
 *
 * \ingroup group__library__smart_pointer
 *
 * \param T The value type
 *
 * A heap-allocated resource to be managed is placed into an instance of
 * \link stlsoft::scoped_ptr scoped_ptr\endlink
 * in its constructor, as in:
\code
  {
    stlsoft::scoped_ptr<MyClass>  scoper(new MyClass(1, 2));

    . . .
  } // The MyClass instance is deleted here
\endcode
 *
 * The horrendous, and widely lamented, problems with
 * <code>std::auto_ptr</code> are avoided by proscribing copy
 * operations. Hence:
\code
    stlsoft::scoped_ptr<MyClass>  scoper(new MyClass(1, 2));
    stlsoft::scoped_ptr<MyClass>  scoper2(scoper); // Compile error!
\endcode
 */
template <ss_typename_param_k T>
class scoped_ptr
{
public: // Member Types
    /// The value type
    typedef T               value_type;
    /// The value type
    typedef T               element_type;
    /// This type
    typedef scoped_ptr<T>   class_type;

public: // Construction
    /// Constructs an instance between 
    ///
    /// \param value The value to be scoped
    ss_explicit_k scoped_ptr(T* value) stlsoft_throw_0()
        : m_value(value)
    {
        STLSOFT_COVER_MARK_LINE();
    }

    ~scoped_ptr() stlsoft_throw_0()
    {
        STLSOFT_COVER_MARK_LINE();

        try
        {
            STLSOFT_COVER_MARK_LINE();

            delete m_value;
        }
        catch(...)
        {
            STLSOFT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_API("scoped type destructor threw an exception");

            /* NOTE: rethrowing this exception is most certainly wrong,
             * but so too is not rethrowing it. Hopefully, the contract
             * enforcement above will have caused the process to stop.
             * If not, then it's 51-49 as to whether to throw or not
             * throw is preferred, so we go with throw.
             */
            throw;
        }
    }

private: // Construction: Proscribed
    scoped_ptr(class_type const&);
    scoped_ptr& operator =(class_type const&);

public: // Operations
    /// Replaces the scoped instance with another instance, returning the
    /// previous instance to the caller
    ///
    /// \note The caller becomes responsible for destroying the instance.
    value_type *reset(T* value = NULL) stlsoft_throw_0()
    {
        STLSOFT_COVER_MARK_LINE();

        value_type *oldValue = m_value;

        m_value = value;

        return oldValue;
    }
    /// Detaches the scoped instance from the scoped_ptr and returns a
    /// pointer to it to the caller
    ///
    /// \note The caller becomes responsible for destroying the instance.
    value_type *detach() stlsoft_throw_0()
    {
        STLSOFT_COVER_MARK_LINE();

        return reset(NULL);
    }

    /// Swaps the scoped instances between two scoped_ptr instances
    void swap(class_type& rhs) stlsoft_throw_0()
    {
        STLSOFT_COVER_MARK_LINE();

        value_type* value       =   rhs.m_value;
                    rhs.m_value =   m_value;
                    m_value     =   value;
    }

public: // Accessors
    /// Dereference operator
    ///
    /// \pre NULL != get()
    T* operator ->() const stlsoft_throw_0()
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_API(NULL != m_value, "no scoped instance: cannot dereference null pointer");

        return m_value;
    }

    /// Dereference operator
    ///
    /// \pre NULL != get()
    T& operator *() const stlsoft_throw_0()
    {
        STLSOFT_COVER_MARK_LINE();

        STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_API(NULL != m_value, "no scoped instance: cannot dereference null pointer");

        return *m_value;
    }

    T* get() const stlsoft_throw_0()
    {
        STLSOFT_COVER_MARK_LINE();

        return m_value;
    }

private: // State
    STLSOFT_DEFINE_OPERATOR_BOOL_TYPES_T(class_type, operator_bool_generator_type, operator_bool_type);
public:
    /// Indicates whether an instance is being scoped
    ///
    /// \retval true get() will return non-NULL
    /// \retval false get() will return NULL
    operator operator_bool_type() const
    {
        STLSOFT_COVER_MARK_LINE();

        return operator_bool_generator_type::translate(NULL != m_value);
    }
    /// Indicates whether an instance is not being scoped
    ///
    /// \retval true get() will return NULL
    /// \retval false get() will return non-NULL
    ss_bool_t operator !() const
    {
        STLSOFT_COVER_MARK_LINE();

        return NULL == m_value;
    }

private: // Member Variables
    T*  m_value;
};

template <ss_typename_param_k T>
void swap(scoped_ptr<T>& lhs, scoped_ptr<T>& rhs)
{
    STLSOFT_COVER_MARK_LINE();

    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/** Attribute shim to retrieve the scoped instance of the given scoped_ptr
 *
 * \ingroup group__concept__shim__pointer_attribute__get_ptr
 */
template <ss_typename_param_k T>
inline T* get_ptr(scoped_ptr<T> const& ptr)
{
    STLSOFT_COVER_MARK_LINE();

    return ptr.get();
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace tr1 */

using ::stlsoft::tr1::get_ptr;

} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Warnings
 */

#include <stlsoft/internal/warnings/pop/nothrow_throws_.h>

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_TR1_SMARTPTR_HPP_SCOPED_PTR */

/* ///////////////////////////// end of file //////////////////////////// */
