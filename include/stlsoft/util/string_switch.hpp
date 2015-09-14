/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/string_switch.hpp
 *
 * Purpose:     String-switch functions.
 *
 * Created:     10th May 2010
 * Updated:     12th May 2014
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


/** \file stlsoft/util/string_switch.hpp
 *
 * \brief [C++ only] String-switch functions
 *   (\ref group__library__utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH
#define STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH_MAJOR    1
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH_MINOR    2
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH_REVISION 4
# define STLSOFT_VER_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH_EDIT     20
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

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS
# include <stlsoft/string/char_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_CHAR_TRAITS */

#ifndef STLSOFT_INCL_H_STRING
# define STLSOFT_INCL_H_STRING
# include <string.h>
#endif /* !STLSOFT_INCL_H_STRING */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

namespace ximpl
{

    template<
        ss_typename_param_k C
    ,   ss_typename_param_k E
    >
    struct string_case_item_t
    {
        C const*   name;
        E          value;
    };

    template<
        ss_typename_param_k C
    ,   ss_typename_param_k E
    ,   ss_size_t           N
    >
    struct string_case_item_array_t
    {
    public:
        typedef string_case_item_array_t<C, E, N>   class_type;

    public:
        string_case_item_array_t(string_case_item_t<C, E> const* p, ss_size_t n)
            : len(n)
        {
            STLSOFT_ASSERT(N == n);

            STLSOFT_COVER_MARK_LINE();

            { for(ss_size_t i = 0; i != n; ++i, ++p)
            {
                STLSOFT_COVER_MARK_LINE();

                ptr[i].name   = p->name;
                ptr[i].value  = p->value;
            }}
        }
    protected:
        void operator =(class_type const&);

    public:
        ss_size_t size() const
        {
            STLSOFT_COVER_MARK_LINE();

            return N;
        }

        string_case_item_t<C, E> const& operator [](ss_size_t i) const
        {
            STLSOFT_ASSERT(i < N);

            STLSOFT_COVER_MARK_LINE();

            return ptr[i];
        }

    private:
        ss_size_t const             len;
        string_case_item_t<C, E>    ptr[N];
    };

} /* namespace ximpl */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** Defines a set of one string-switch case, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 1>
  string_cases(
    C const*  name0
,   E         value0
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
      { name0, value0 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of two string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 2>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    {
        { name0, value0 }
      , { name1, value1 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of three string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 3>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    { 
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of four string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 4>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    { 
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of five string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 5>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    { 
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of six string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 6>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    { 
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of seven string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 7>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    { 
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of eight string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 8>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    { 
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of nine string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 9>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    { 
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Defines a set of ten string-switch cases, to be consumed by string_switch()
 *
 * \param name0 The name of the first case
 * \param value0 The value of the first case
 * \param name1 The name of the second case
 * \param value1 The value of the second case
 * \param name2 The name of the third case
 * \param value2 The value of the third case
 * \param name3 The name of the fourth case
 * \param value3 The value of the fourth case
 * \param name4 The name of the fifth case
 * \param value4 The value of the fifth case
 * \param name5 The name of the sixth case
 * \param value5 The value of the sixth case
 * \param name6 The name of the seventh case
 * \param value6 The value of the seventh case
 * \param name7 The name of the eighth case
 * \param value7 The value of the eighth case
 * \param name8 The name of the ninth case
 * \param value8 The value of the ninth case
 * \param name9 The name of the tenth case
 * \param value9 The value of the tenth case
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k E
>
inline ximpl::string_case_item_array_t<C, E, 10>
  string_cases(
    C const*  name0
,   E         value0
,   C const*  name1
,   E         value1
,   C const*  name2
,   E         value2
,   C const*  name3
,   E         value3
,   C const*  name4
,   E         value4
,   C const*  name5
,   E         value5
,   C const*  name6
,   E         value6
,   C const*  name7
,   E         value7
,   C const*  name8
,   E         value8
,   C const*  name9
,   E         value9
)
{
    STLSOFT_COVER_MARK_LINE();

    ximpl::string_case_item_t<C, E> items[] =
    { 
        { name0, value0 }
      , { name1, value1 }
      , { name2, value2 }
      , { name3, value3 }
      , { name4, value4 }
      , { name5, value5 }
      , { name6, value6 }
      , { name7, value7 }
      , { name8, value8 }
      , { name9, value9 }
    };

    return ximpl::string_case_item_array_t<C, E, STLSOFT_NUM_ELEMENTS(items)>(items, STLSOFT_NUM_ELEMENTS(items));
}

/** Conducts a string-switch over the given string \c s, according to the
 * given cases, putting the matching value into the given \c result
 *
 * \param s The string whose value is to be tested
 * \param result Pointer to the variable to receive the result, if any of
 *   the cases are matched
 * \param cases The sequence of cases, created via string_cases(), to be
 *   tested against
 * \param resultBase The value to which the result is set before being
 *   combined with the result, if any, of the matched cases. This allows
 *   the function to act as 
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k R
,   ss_size_t           N
,   ss_typename_param_k V
>
inline bool string_switch(
    C const*                                        s
,   R*                                              result
,   ximpl::string_case_item_array_t<C, V, N> const& cases
,   R                                               resultBase = R()
)
{
    STLSOFT_ASSERT(NULL != s);

    STLSOFT_COVER_MARK_LINE();

    typedef stlsoft_char_traits<C> char_traits_t;

    size_t const len = char_traits_t::length(s);

    { for(ss_size_t i = 0; i != cases.size(); ++i)
    {
        STLSOFT_COVER_MARK_LINE();

        ximpl::string_case_item_t<C, V> const&  case_   =   cases[i];
        size_t const                            caselen =   char_traits_t::length(case_.name);

        if( caselen == len &&
            0 == char_traits_t::compare(case_.name, s, len))
        {
            STLSOFT_COVER_MARK_LINE();

            *result = static_cast<R>(resultBase | case_.value);
            return true;
        }
    }}

    STLSOFT_COVER_MARK_LINE();

    return false;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* STLSOFT_INCL_STLSOFT_UTIL_INCL_HPP_STRING_SWITCH */

/* ///////////////////////////// end of file //////////////////////////// */
