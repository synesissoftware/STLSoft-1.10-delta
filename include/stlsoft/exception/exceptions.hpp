/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/exception/exceptions.hpp
 *
 * Purpose:     Contains the exception_string limited functionality string class.
 *
 * Created:     13th May 2010
 * Updated:     18th July 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2010-2014, Matthew Wilson and Synesis Software
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



#ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_EXCEPTIONS
#define STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_EXCEPTIONS

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#include <stlsoft/util/exception_string.hpp>

#include <errno.h>

#if 0

namespace std
{
    class bad_alloc
    class bad_cast
    class bad_exception
    class bad_typeid
    class logic_error
        class domain_error
        class invalid_argument
        class length_error
        class out_of_range
    class runtime_error
        class range_error
        class overflow_error
        class underflow_error
    class ios_base::failure
}

// 1.9:

std::exception
    project_exception
        os_exception
            platform_exception
    std::bad_alloc

// 1.10:

std::runtime_error
    root_exception
        os_exception
            platform_exception
                filesystem_exception
                    file_not_found_exception
                    access_denied_exception
    std::bad_alloc
        out_of_memory_exception





stlsoft::chained_exception<> - CRTP



std::bad_alloc
    out_of_memory_exception



#endif /* 0 */


#include <stdexcept>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{

/* /////////////////////////////////////////////////////////////////////////
 * Helper types
 */

#if 0

struct exception_state
{
    union
    {
        int                 i;
        stlsoft::uint64_t   ui64;

    } status;

    exception_string        xs;

public:
    exception_state(
        exception_string const& xs
    )
        : xs(xs)
    {}

};

#endif /* 0 */


    template <typename X, typename E>
    class qualified_exception
        : public X
    {
    public:
        typedef X                           parent_class_type;
        typedef E                           error_code_type;
        typedef qualified_exception<X, E>   class_type;
    private:

    protected:
        qualified_exception(error_code_type code)
            : parent_class_type()
            , m_errorCode(code)
        {}
        qualified_exception(char const* message, error_code_type code)
            : parent_class_type(message)
            , m_errorCode(code)
        {}
        qualified_exception(class_type const& rhs)
            : parent_class_type(rhs)
            , m_errorCode(rhs.m_errorCode)
        {}
    private:
        class_type& operator =(class_type const& rhs);

    public:
        error_code_type get_error_code() const
        {
            return m_errorCode;
        }

    private:
#if 0
        error_code_type         m_errorCode;
#else /* ? 0 */
        error_code_type const   m_errorCode;
#endif /* 0 */
    };

    template <typename X, typename C>
    class chained_exception
        : public X
    {
    public: // Member Types
        typedef X                       parent_class_type;
        typedef C                       chainee_type;
        typedef chained_exception<X, C> class_type;
    private:
        struct chainee_handle
        {
        public:
            chainee_type    chainee;
        private:
            ss_sint32_t     refCount;

        public:
            chainee_handle(chainee_type const& chainee)
                : chainee(chainee)
                , refCount(1)
            {}
            ~chainee_handle() stlsoft_throw_0()
            {
                STLSOFT_ASSERT(0 == refCount || 1 == refCount);
            }

        public:
            void AddRef()
            {
                ++refCount;
            }
            void Release()
            {
                if(0 == --refCount)
                {
                    delete this;
                }
            }
        };

    protected: // Construction
        chained_exception()
            : m_chainee(NULL)
        {}
        chained_exception(C const& chainee)
            : m_chainee(create_chainee_(chainee))
        {}
    protected:
        chained_exception(class_type const& rhs)
            : m_chainee(rhs.m_chainee)
        {
            if(NULL != rhs.m_chainee)
            {
                rhs.m_chainee->AddRef();
            }
        }
#if 0
        class_type& operator =(class_type const& rhs)
        {
            if(NULL != rhs.m_chainee)
            {
                rhs.m_chainee->AddRef();
            }
            if(NULL != m_chainee)
            {
                m_chainee->Release();
            }

            m_chainee = rhs.m_chainee;

            return *this;
        }
#else /* ? 0 */
    private:
        class_type& operator =(class_type const& rhs);
#endif /* 0 */

    private:
        static chainee_handle* create_chainee_(C const& chainee)
        {
            return new chainee_handle(chainee);
        }

    private:
#if 0
        chainee_handle* m_chainee;
#else /* ? 0 */
        chainee_handle* const m_chainee;
#endif /* 0 */
    };

    class root_exception
        : public stlsoft_ns_qual_std(runtime_error)
    {
    public: // Member Types
        typedef stlsoft_ns_qual_std(runtime_error)  parent_class_type;
        typedef root_exception                      class_type;
        typedef stlsoft_ns_qual(exception_string)   string_type;

    public:
        root_exception(string_type const& message)
            : parent_class_type(message.c_str())
        {}
        root_exception(char const* message)
            : parent_class_type(message)
        {}
        virtual ~root_exception() stlsoft_throw_0() = 0;
    };

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    inline root_exception::~root_exception() stlsoft_throw_0()
    {}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


    class out_of_memory_exception
        : public qualified_exception<stlsoft_ns_qual_std(bad_alloc), int>
    {
    public: // Member Types
        typedef qualified_exception<stlsoft_ns_qual_std(bad_alloc), int>    parent_class_type;
        typedef out_of_memory_exception                                     class_type;

    public: // Construction
        out_of_memory_exception()
            : parent_class_type(ENOMEM)
        {}
        out_of_memory_exception(error_code_type code)
            : parent_class_type(code)
        {}

    private:
    };
    

} /* namespace stlsoft */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{
    class api_root_exception
        : public qualified_exception<root_exception, int>
    {
    public: // Member Types
        typedef qualified_exception<root_exception, int>    parent_class_type;
        typedef api_root_exception                          class_type;

    public: // Construction
        api_root_exception(string_type const& message, error_code_type code)
            : parent_class_type(message.c_str(), code)
        {}
        ~api_root_exception() stlsoft_throw_0()
        {}
    };
    

} /* namespace stlsoft */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{
    class operating_environment_exception
        : public qualified_exception<root_exception, int>
    {
    public: // Member Types
        typedef qualified_exception<root_exception, int>    parent_class_type;
        typedef operating_environment_exception             class_type;

    public: // Construction
        operating_environment_exception(char const* message, error_code_type code)
            : parent_class_type(message, code)
        {}
        operating_environment_exception(string_type const& message, error_code_type code)
            : parent_class_type(message.c_str(), code)
        {}
        ~operating_environment_exception() stlsoft_throw_0()
        {}
    };

    class filesystem_exception
        : public operating_environment_exception
    {
    public: // Member Types
        typedef operating_environment_exception     parent_class_type;
        typedef filesystem_exception                class_type;

    public: // Construction
        filesystem_exception(string_type const& message, error_code_type code)
            : parent_class_type(message, code)
            , m_item()
        {}
        filesystem_exception(char const* message, error_code_type code)
            : parent_class_type(message, code)
            , m_item()
        {}
        filesystem_exception(string_type const& message, error_code_type code, string_type const& item)
            : parent_class_type(message, code)
            , m_item(item)
        {}
        filesystem_exception(char const* message, error_code_type code, string_type const& item)
            : parent_class_type(message, code)
            , m_item(item)
        {}
        filesystem_exception(char const* message, error_code_type code, char const* item)
            : parent_class_type(message, code)
            , m_item(item)
        {}
        ~filesystem_exception() stlsoft_throw_0()
        {}
    private:
        class_type& operator =(class_type const& rhs);

    public:
        string_type const& get_item() const
        {
            return m_item;
        }

    private:
        string_type const m_item;
    };

    class access_denied_exception
        : public filesystem_exception
    {
    public: // Member Types
        typedef filesystem_exception                parent_class_type;
        typedef access_denied_exception             class_type;

    public: // Construction
        access_denied_exception(string_type const& message, error_code_type code)
            : parent_class_type(message, code)
        {}
        access_denied_exception(char const* message, error_code_type code)
            : parent_class_type(message, code)
        {}
        access_denied_exception(string_type const& message, error_code_type code, string_type const& item)
            : parent_class_type(message, code, item)
        {}
        access_denied_exception(char const* message, error_code_type code, string_type const& item)
            : parent_class_type(message, code, item)
        {}
        access_denied_exception(char const* message, error_code_type code, char const* item)
            : parent_class_type(message, code, item)
        {}
        ~access_denied_exception() stlsoft_throw_0()
        {}
    private:
        class_type& operator =(class_type const& rhs);
    };

    class file_not_found_exception
        : public filesystem_exception
    {
    public: // Member Types
        typedef filesystem_exception                parent_class_type;
        typedef file_not_found_exception            class_type;

    public: // Construction
        file_not_found_exception(string_type const& message, error_code_type code)
            : parent_class_type(message, code)
        {}
        file_not_found_exception(char const* message, error_code_type code)
            : parent_class_type(message, code)
        {}
        file_not_found_exception(string_type const& message, error_code_type code, string_type const& item)
            : parent_class_type(message, code, item)
        {}
        file_not_found_exception(char const* message, error_code_type code, string_type const& item)
            : parent_class_type(message, code, item)
        {}
        file_not_found_exception(char const* message, error_code_type code, char const* item)
            : parent_class_type(message, code, item)
        {}
        ~file_not_found_exception() stlsoft_throw_0()
        {}
    private:
        class_type& operator =(class_type const& rhs);
    };

    class invalid_file_type_exception
        : public filesystem_exception
    {
    public: // Member Types
        typedef filesystem_exception                parent_class_type;
        typedef invalid_file_type_exception         class_type;

    public: // Construction
        invalid_file_type_exception(string_type const& message, error_code_type code)
            : parent_class_type(message, code)
        {}
        invalid_file_type_exception(string_type const& message, error_code_type code, string_type const& item)
            : parent_class_type(message, code, item)
        {}
        ~invalid_file_type_exception() stlsoft_throw_0()
        {}
    private:
        class_type& operator =(class_type const& rhs);
    };

/* ////////////////////////////////////////////////////////////////////// */

} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_EXCEPTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
