/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/util/resource_id.hpp
 *
 * Purpose:     Abstraction of Windows' API resource identifier.
 *
 * Created:     30th August 2014
 * Updated:     31st August 2014
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2014, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/util/resource_id.hpp
 *
 * \brief [C++ only] Definition of winstl::resource_id class
 *   (\ref group__library__util "Utility" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_RESOURCE_ID
#define WINSTL_INCL_WINSTL_SYNCH_HPP_RESOURCE_ID

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_RESOURCE_ID_MAJOR      1
# define WINSTL_VER_WINSTL_SYNCH_HPP_RESOURCE_ID_MINOR      0
# define WINSTL_VER_WINSTL_SYNCH_HPP_RESOURCE_ID_REVISION   1
# define WINSTL_VER_WINSTL_SYNCH_HPP_RESOURCE_ID_EDIT       3
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <winstl/winstl_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER
# include <stlsoft/conversion/string_to_integer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_STRING_TO_INTEGER */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP
# include <stlsoft/util/std_swap.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_STD_SWAP */

#ifndef STLSOFT_INCL_STRING
# define STLSOFT_INCL_STRING
# include <string>
#endif /* !STLSOFT_INCL_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
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
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

// class resource_id
/** This class is an abstraction over Windows' overloaded interpretation of
 * the C-style string pointer types a both a string - the resource name -
 * and a (string cast as) number - the resource numeric identifier.
 *
 * \ingroup group__library__util
 */
class resource_id
{
public: // Member Types
    typedef resource_id                                     class_type;
    typedef TCHAR                                           char_type;
    typedef ws_size_t                                       size_type;
    typedef stlsoft_ns_qual_std(basic_string)<char_type>    string_type;
private:

public: // Member Values
    enum representation
    {
            Representation_Name                         =   -1
        ,   Representation_DecimalString                =   0
        ,   Representation_HexadecimalString
        ,   Representation_DecimalStringInParentheses
    };

public: // Construction
private:
    /// \exception std::out_of_range
    explicit
    resource_id(
        UINT            id
    ,   representation  repr
    );
public:
    /// Initialises an instance from the given name
    ///
    /// \param name The name of the resource which may be an actual string
    ///  representing the resource name or a <code>MAKEINTRESOURCE</code>-d
    ///  number.
    ///
    /// \see from_number()
    explicit
    resource_id(
        LPCTSTR name
    );
    /// Initialises an instance as a copy of the given instance
    resource_id(
        class_type const& rhs
    );
private:
    class_type& operator =(class_type const&); // proscribed
public:

    /// Creates an instance from the given numeric identifier
    ///
    /// \param id The resource identifier
    /// \param repr The desired string representation of the human-readable
    ///   string attributes
    ///
    /// \note This is the recommended means of creating an instance from a
    ///   numberic identifier, provided as a construction class method, as
    ///   opposed to a constructor overload, to reduce the possibility of
    ///   ambiguity.
    ///
    /// \return An instance representing the numeric identifier
    ///
    /// \exception std::out_of_range If \c id is too large
    static
    class_type
    from_number(
        UINT            id
    ,   representation  repr
    );

    /// Creates an instance from the given numeric identifier, which will
    /// have decimal representation human-readable string attributes
    ///
    /// \param id The resource identifier
    ///
    /// \note This is the recommended means of creating an instance from a
    ///   numberic identifier, provided as a construction class method, as
    ///   opposed to a constructor overload, to reduce the possibility of
    ///   ambiguity.
    ///
    /// \return An instance representing the numeric identifier
    static
    class_type
    from_number(
        UINT id
    );

    /// Creates an instance from a string that contains a recognised
    /// representation of a numeric resource identifier:
    /// - decimal string, e.g. "12"
    /// - hexadecimal string, e.g. "0x000c"
    /// - decimal string surrounded by parentheses, e.g. "(12)"
    ///
    /// \param number A string containing the numeric form of the resource
    ///   identifier
    /// \param prepr An optional pointer to a variable to receive the
    ///   parsed representation of the numeric resource identifier
    ///
    /// \return An instance representing the numeric identifier
    ///
    /// \exception ??TBD?? Thrown if the
    ///   string does not contain a recognisable numeric identifier
    ///
    /// \exception std::out_of_range If the number is too large
    static
    class_type
    parse_as_number(
        LPCTSTR         number
    ,   representation* prepr = NULL
    );

    /// Indicates whether the method <code>parse_as_number()</code>
    /// will succeed
    ///
    /// \param number A string containing the numeric form of the resource
    ///   identifier
    /// \param prepr An optional pointer to a variable to receive the
    ///   parsed representation of the numeric resource identifier
    ///
    /// \exception std::out_of_range If the number is too large
    static
    bool
    try_parse_number(
        LPCTSTR         number
    ,   representation* prepr = NULL
    );

    void
    swap(
        class_type& other
    );

public: // Accessors

    /// Returns the API-valid resource identifier value
    ///
    /// \warning The value returned from this method may not be a valid
    ///   string and <strong>MUST NOT</strong> be passed to any function
    ///   that requires a valid C-style string pointer; instead use the
    ///   <code>c_str()</code> method, or the <code>data()</code> and
    ///   <code>size()</code> method pair
    LPCTSTR
    id() const;

    /// The representation of the human-readable form of the string
    representation
    repr() const;

    /// (Non-null pointer to a C-style string representing) the
    /// human-readable form of the string
    TCHAR const*
    c_str() const;

    /// (Non-null pointer to a C-style string representing) the
    /// human-readable form of the string
    TCHAR const*
    data() const;

    /// The length of the human-readable form of the string
    size_type
    size() const;

public: // Comparison
    bool
    equal(
        class_type const& rhs
    ) const;

    int
    compare(
        class_type const& rhs
    ) const;

private: // Implementation
    bool
    is_valid_() const;

    static
    bool
    is_int_out_of_range_(
        UINT            id
    );

    static
    bool
    is_int_resource_(
        LPCTSTR         name
    ,   ws_uintptr_t*   pn
    );

    static
    bool
    try_parse_number_(
        LPCTSTR         number
    ,   representation* prepr
    ,   ws_uintptr_t*   pn
    );

private: // Fields
    representation  m_repr;
    LPCTSTR         m_ptr;
    string_type     m_str;
};

/* /////////////////////////////////////////////////////////////////////////
 * Operators
 */

inline
bool
operator ==(
    resource_id const&  lhs
,   resource_id const&  rhs
)
{
    return lhs.equal(rhs);
}

inline
bool
operator !=(
    resource_id const&  lhs
,   resource_id const&  rhs
)
{
    return !lhs.equal(rhs);
}


inline
bool
operator <(
    resource_id const&  lhs
,   resource_id const&  rhs
)
{
    return lhs.compare(rhs) < 0;
}

inline
bool
operator <=(
    resource_id const&  lhs
,   resource_id const&  rhs
)
{
    return lhs.compare(rhs) <= 0;
}

inline
bool
operator >(
    resource_id const&  lhs
,   resource_id const&  rhs
)
{
    return lhs.compare(rhs) > 0;
}

inline
bool
operator >=(
    resource_id const&  lhs
,   resource_id const&  rhs
)
{
    return lhs.compare(rhs) >= 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

inline
TCHAR const*
c_str_ptr(
    resource_id const&  rid
)
{
    return rid.c_str();
}

inline
TCHAR const*
c_str_data(
    resource_id const&  rid
)
{
    return rid.data();
}

inline
ws_size_t
c_str_len(
    resource_id const&  rid
)
{
    return rid.size();
}

inline
#ifdef UNICODE
ws_char_w_t const*
c_str_ptr_w
#else /* ? UNICODE */
ws_char_a_t const*
c_str_ptr_a
#endif /* UNICODE */
(
    resource_id const&  rid
)
{
    return rid.c_str();
}

inline
#ifdef UNICODE
ws_char_w_t const*
c_str_data_w
#else /* ? UNICODE */
ws_char_a_t const*
c_str_data_a
#endif /* UNICODE */
(
    resource_id const&  rid
)
{
    return rid.data();
}

inline
ws_size_t
#ifdef UNICODE
c_str_len_w
#else /* ? UNICODE */
c_str_len_a
#endif /* UNICODE */
(
    resource_id const&  rid
)
{
    return rid.size();
}

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

// Implementation

inline
/* static */
bool
resource_id::is_int_out_of_range_(
    UINT id
)
{
    if(0 == id)
    {
        return true;
    }

    if(0 != (id & ~ws_uintptr_t(0xffff)))
    {
        return true;
    }

    return false;
}

inline
/* static */
bool
resource_id::is_int_resource_(
    LPCTSTR         name
,   ws_uintptr_t*   pn
)
{
    *pn = 0;

    union
    {
        ws_uintptr_t    i;
        LPCTSTR         s;
    } u;

    u.i = 0;
    u.s = name;

    if(!is_int_out_of_range_(u.i))
    {
        *pn = u.i;

        return true;
    }

    return false;
}

inline
/* static */
bool
resource_id::try_parse_number_(
    LPCTSTR         number
,   representation* prepr
,   ws_uintptr_t*   pn
)
{
    size_t const    len = lstrlen(number);

    representation  dummy1;
    ws_uintptr_t    dummy2;

    if(NULL == prepr)
    {
        prepr = &dummy1;
    }
    if(NULL == pn)
    {
        pn = &dummy2;
    }

    if(0 != len)
    {
        representation  repr    =   Representation_DecimalString;

        TCHAR const*    first   =   number;
        TCHAR const*    last    =   number + len;

        if( '(' == *first &&
            ')' == *(last - 1))
        {
            if(len < 3)
            {
                return false;
            }
            else
            {
                repr = Representation_DecimalStringInParentheses;

                ++first;
                --last;
            }
        }
        else
        if( '0' == first[0] &&
            (   'x' == first[1] ||
                'X' == first[1]))
        {
            if(len < 3)
            {
                return false;
            }
            else
            {
                repr = Representation_HexadecimalString;
            }
        }

        if(stlsoft_ns_qual(try_parse_to<ws_uintptr_t>(first, static_cast<ws_size_t>(last - first), pn)))
        {
            *prepr = repr;

            return true;
        }
    }

    return false;
}

inline
bool
resource_id::is_valid_() const
{
    if(NULL == m_ptr)
    {
        return false;
    }

    ws_uintptr_t n;

    if(!is_int_resource_(m_ptr, &n))
    {
        if(m_ptr != m_str.c_str())
        {
            return false;
        }

        if(Representation_Name != m_repr)
        {
            return false;
        }
    }
    else
    {
        if(m_ptr == m_str.c_str())
        {
            return false;
        }

        if(Representation_Name == m_repr)
        {
            return false;
        }
    }

    return true;
}

// Construction

inline
/* explicit */
resource_id::resource_id(
    UINT            id
,   representation  repr
)
    : m_repr(repr)
    , m_ptr()
    , m_str()
{
    if(is_int_out_of_range_(id))
    {
        throw std::out_of_range("numeric resource identifier is too large");
    }
    else
    {
        TCHAR const*    fmt;

        switch(repr)
        {
            default:
            case    Representation_Name:
                STLSOFT_ASSERT(0);
                fmt = TEXT("contract violation");
                break;
            case    Representation_DecimalString:
                fmt = TEXT("%d");
                break;
            case    Representation_HexadecimalString:
                fmt = TEXT("0x%04X");
                break;
            case    Representation_DecimalStringInParentheses:
                fmt = TEXT("(%d)");
                break;
        }

        TCHAR       num[21];
        int const   cch = ::wsprintf(num, fmt, id);

        union
        {
            ws_uintptr_t    i;
            LPCTSTR         s;
        } u;

        u.i = id;

        m_str.assign(num, cch);

        m_ptr   =   u.s;
    }
}

inline
/* explicit */
resource_id::resource_id(
    LPCTSTR name
)
    : m_repr()
    , m_ptr()
    , m_str()
{
    ws_uintptr_t n;

    if(is_int_resource_(name, &n))
    {
        TCHAR       num[21];
        int const   cch = ::wsprintf(num, TEXT("%u"), n);

        union
        {
            ws_uintptr_t    i;
            LPCTSTR         s;
        } u;

        u.i = n;

        m_repr  =   Representation_DecimalString;

        m_str.assign(num, cch);

        m_ptr   =   u.s;
    }
    else
    {
        m_repr  =   Representation_Name;

        m_str   =   name;

        m_ptr   =   m_str.c_str();
    }

    WINSTL_ASSERT(is_valid_());
}

inline
resource_id::resource_id(
    resource_id::class_type const& rhs
)
    : m_repr(rhs.m_repr)
    , m_ptr(rhs.m_ptr)
    , m_str(rhs.m_str)
{
    ws_uintptr_t n;

    if(!is_int_resource_(rhs.m_ptr, &n))
    {
        m_ptr = m_str.c_str();
    }
}

inline
/* static */
resource_id::class_type
resource_id::from_number(
    UINT                        id
,   resource_id::representation repr
)
{
    return resource_id(id, repr);
}

inline
/* static */
resource_id::class_type
resource_id::from_number(
    UINT id
)
{
    return from_number(id, Representation_DecimalString);
}

inline
/* static */
resource_id::class_type
resource_id::parse_as_number(
    LPCTSTR                         number
,   resource_id::representation*    prepr /* = NULL */
)
{
    ws_uintptr_t    n = static_cast<ws_uintptr_t>(-1);
    representation  dummy;

    if(NULL == prepr)
    {
        prepr = &dummy;
    }

    if(!try_parse_number_(number, prepr, &n))
    {
        throw std::invalid_argument("string could not be parsed as compatible numeric identifier");
    }

    return resource_id(n, *prepr);
}

inline
/* static */
bool
resource_id::try_parse_number(
    LPCTSTR                         number
,   resource_id::representation*    prepr /* = NULL */
)
{
    return try_parse_number_(number, prepr, NULL);
}

inline
void
resource_id::swap(
    resource_id::class_type& other
)
{
    std_swap(m_str, other.m_str);
    std_swap(m_ptr, other.m_ptr);
    std_swap(m_repr, other.m_repr);

    if(Representation_Name == m_repr)
    {
        WINSTL_ASSERT(m_ptr == m_str.c_str());
    }
    if(Representation_Name == other.m_repr)
    {
        WINSTL_ASSERT(other.m_ptr == other.m_str.c_str());
    }
}


// Accessors

inline
LPCTSTR
resource_id::id() const
{
    return m_ptr;
}

inline
resource_id::representation
resource_id::repr() const
{
    return m_repr;
}

inline
TCHAR const*
resource_id::c_str() const
{
    return m_str.c_str();
}

inline
TCHAR const*
resource_id::data() const
{
    return m_str.data();
}

inline
resource_id::size_type
resource_id::size() const
{
    return m_str.size();
}

bool
resource_id::equal(
    class_type const& rhs
) const
{
    class_type const& lhs = *this;

    if(lhs.repr() != rhs.repr())
    {
        return false;
    }

    if(Representation_Name == lhs.repr())
    {
        return lhs.m_str == rhs.m_str;
    }

    return lhs.m_ptr == rhs.m_ptr;
}

int
resource_id::compare(
    class_type const& rhs
) const
{
    class_type const& lhs = *this;

    if(Representation_Name == lhs.repr())
    {
        if(Representation_Name == rhs.repr())
        {
            return lhs.m_str.compare(rhs.m_str);
        }
        else
        {
            return +1;
        }
    }
    else
    {
        if(Representation_Name == rhs.repr())
        {
            return -1;
        }
        else
        {
            if(lhs.id() < rhs.id())
            {
                return -1;
            }
            else
            if(rhs.id() < lhs.id())
            {
                return +1;
            }
            else
            {
                return 0;
            }
        }
    }
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */

namespace stlsoft
{
    using ::winstl::c_str_ptr;
#ifndef UNICODE
    using ::winstl::c_str_ptr_a;
#else /* ? !UNICODE */
    using ::winstl::c_str_ptr_w;
#endif /* !UNICODE */

    using ::winstl::c_str_data;
#ifndef UNICODE
    using ::winstl::c_str_data_a;
#else /* ? !UNICODE */
    using ::winstl::c_str_data_w;
#endif /* !UNICODE */

    using ::winstl::c_str_len;
#ifndef UNICODE
    using ::winstl::c_str_len_a;
#else /* ? !UNICODE */
    using ::winstl::c_str_len_w;
#endif /* !UNICODE */

} /* namespace stlsoft */

#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_RESOURCE_ID */

/* ///////////////////////////// end of file //////////////////////////// */
