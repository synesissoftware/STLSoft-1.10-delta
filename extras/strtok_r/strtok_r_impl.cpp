/* ////////////////////////////////////////////////////////////////////////////
 * File:        strtok_r_impl.cpp
 *
 * Purpose:     Implementation of strtok_r() using string view.
 *
 * Created:     18th June 2005
 * Updated:     20th February 2006
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2005-2006, Matthew Wilson and Synesis Software
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
 * ////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////////
 * Implementation Options
 */

//#define USE_CHARSET_TOKENISER
//#define USE_STRING_TOKENISER

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifdef USE_CHARSET_TOKENISER
# include <stlsoft/tokenising/charset_tokeniser.hpp>
#elif defined(USE_STRING_TOKENISER)
# include <stlsoft/string_tokeniser.hpp>
# include <algorithm>
#else /* ? impl */
# include <string.h>
#endif /* impl */
#include <stlsoft/string_view.hpp>

/* /////////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#if defined(USE_STRING_TOKENISER)
namespace
{
    template <ss_typename_param_k S>
    struct range_comparator
    {
        typedef S                   delimiter_type;

        template <ss_typename_param_k const_iterator>
        static bool not_equal(delimiter_type const &delim, const_iterator &it)
        {
            return delim.end() == std::find(delim.begin(), delim.end(), *it);
        }

        static size_t length(delimiter_type const &delim)
        {
            return 1;
        }
    };

} // anonymous namespace
#endif /* impl */


extern "C" char *strtok_r(char *str, const char *delims, char **last_s)
{
#if !defined(USE_CHARSET_TOKENISER) && \
    !defined(USE_STRING_TOKENISER)

    if(NULL == str)
    {
        str = *last_s + 1;
    }

    size_t  n;

    for(; '\0' != *str && 0 == (n = ::strcspn(str, delims)); ++str)
    {}

    if('\0' != *str)
    {
        *last_s = str + n;
        **last_s = '\0';
    }
    else
    {
        str = NULL;
    }

    return str;

#else /* ? impl */

    // Tokenise with a string_view, so there's no allocation whatsoever
    typedef stlsoft::basic_string_view<char>    string_t;
    // Specialise the string_tokeniser with:
#if defined(USE_CHARSET_TOKENISER)
    typedef stlsoft::charset_tokeniser<string_t>    tokeniser_t;
#elif defined(USE_STRING_TOKENISER)
    //  string     type = string_t (a string view)
    //  delims     type = string_t (a string view)
    //  ignore     type = true, since strtok_r() semantics are to 
    //                     skip blanks
    //  traits     type = 'normal' specialisation of 
    //                     string_tokeniser_type_traits<string_t, string_t>
    //  comparator type = range_comparator<string_t>. range_comparator is 
    //                     defined above (will later be added to STLSoft libs)
    typedef stlsoft::string_tokeniser<  string_t
                                    ,   string_t
                                    ,   stlsoft::string_tokeniser_ignore_blanks<true>
                                    ,   string_t
                                    ,   stlsoft::string_tokeniser_type_traits<string_t, string_t>
                                    ,   range_comparator<string_t>
                                    >           tokeniser_t;
#else /* ? impl */
# error Invalid impl
#endif /* impl */

    // Deduce the start from either the real start, or the 
    char const *const                   start = (NULL != str) ? str : *last_s;
    tokeniser_t                         tokens(start, delims);

    // Get the half-open range -  [b, e) - of the contents
    tokeniser_t::const_iterator         b   =   tokens.begin();
    const tokeniser_t::const_iterator   e   =   tokens.end();

    // Has tokenisation completed?
    if(b == e)
    {
        return NULL;
    }
    else
    {
        // Take a copy of the current element, to get its ptr and length.
        // Remember that all these strings are string views, so it's not a
        // copy of any data.
        const string_t  s(*b);
        char *const     r   =   const_cast<char*>(s.base());
        const size_t    n   =   s.length();

        // Because the elements can be separated by multiple delimiters, i.e
        // there can be blanks in the search string, the calculation of last_s
        // must be done from the next element, rather than just adding on the
        // length of the current item and the delimiter.
        //
        // Because one should never dereference the off-the-end iterator, the
        // following if() block is correct (even though the string_tokeniser
        // end() iterator happens to be dereferencable in STLSoft 1.8.4).

        // The last element in the search?
        if(++b == e)
        {
            // If so, then set last_s to point to the first character after
            // the current element (which will be nul'd below)
            *last_s = r + n;
        }
        else
        {
            // If not, then set last_s to point to the start of the next
            // element
            char *const r2  =   const_cast<char*>((*b).base());

            *last_s = r2;
        }

        r[n] = '\0';

        return r;
    }
#endif /* impl */
}

/* ////////////////////////////////////////////////////////////////////////// */
