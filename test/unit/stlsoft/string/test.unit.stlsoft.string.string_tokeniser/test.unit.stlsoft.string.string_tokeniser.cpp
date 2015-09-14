/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.string_tokeniser.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.string_tokeniser project.
 *
 * Created:     11th August 2010
 * Updated:     11th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/string/string_tokeniser.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xCover Header Files */
#ifdef STLSOFT_USE_XCOVER
# include <xcover/xcover.h>
#endif /* STLSOFT_USE_XCOVER */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/iterator/string_concatenator.hpp>
#include <stlsoft/string/string_view.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#include <stlsoft/internal/safestr.h>
#if defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) && \
    defined(STLSOFT_COMPILER_IS_MSVC)
# include <stlsoft/algorithms/std/alt.hpp>

namespace std
{
    using ::stlsoft::std_copy;

# define copy   std_copy
}
#endif // compiler

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_tokeniser_string_skip(void);
    static void test_tokeniser_string(void);
    static void test_tokeniser_string_noskip(void);

    static void test_tokeniser_stringview_skip(void);
    static void test_tokeniser_stringview(void);
    static void test_tokeniser_stringview_noskip(void);


} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.string.string_tokeniser", verbosity))
    {
        XTESTS_RUN_CASE(test_tokeniser_string);
        XTESTS_RUN_CASE(test_tokeniser_string_skip);
        XTESTS_RUN_CASE(test_tokeniser_string_noskip);

        XTESTS_RUN_CASE(test_tokeniser_stringview);
        XTESTS_RUN_CASE(test_tokeniser_stringview_skip);
        XTESTS_RUN_CASE(test_tokeniser_stringview_noskip);


#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_ALIAS_COVERAGE("string_tokeniser", NULL);
#endif /* STLSOFT_USE_XCOVER */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

    typedef std::string             string_t;
    typedef std::wstring            wstring_t;

    typedef stlsoft::string_view    string_v_t;
    typedef stlsoft::wstring_view   wstring_v_t;


static void test_tokeniser_string()
{
    typedef stlsoft::string_tokeniser<
        string_t
    ,   char
    ,   stlsoft::skip_blank_tokens<true>
    >                           tokeniser_t;

    {
        string_t    src = "";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = " ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "  ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "   ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "    ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "                              abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "abc def";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "   abc  def                      ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "a b c";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c", r);
    }

    {
        string_t    src = "a a a";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a", r);
    }

    {
        string_t    src = " a a a a a a a a a a a a a a a a a a a a a a a a a a a ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a", r);
    }

    {
        string_t    src1(1000u, 'a');
        string_t    src2(10000u, 'b');
        string_t    src = ' ' + src1 + ' ' + src2 + ' ';
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(src1 + '|' + src2, r);
    }
}

static void test_tokeniser_string_skip()
{
    typedef stlsoft::string_tokeniser<
        string_t
    ,   char
    ,   stlsoft::skip_blank_tokens<true>
    >                           tokeniser_t;

    {
        string_t    src = "";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = " ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "  ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "   ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "    ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "                              abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "abc def";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "   abc  def                      ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "a b c";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c", r);
    }

    {
        string_t    src = "a a a";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a", r);
    }

    {
        string_t    src = " a a a a a a a a a a a a a a a a a a a a a a a a a a a ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a", r);
    }

    {
        string_t    src1(1000u, 'a');
        string_t    src2(10000u, 'b');
        string_t    src = ' ' + src1 + ' ' + src2 + ' ';
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(src1 + '|' + src2, r);
    }
}

static void test_tokeniser_string_noskip()
{
    typedef stlsoft::string_tokeniser<
        string_t
    ,   char
    ,   stlsoft::skip_blank_tokens<false>
    >                           tokeniser_t;

    {
        string_t    src = "";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = " ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", r);
    }

    {
        string_t    src = "  ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|", r);
    }

    {
        string_t    src = "   ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("||", r);
    }

    {
        string_t    src = "    ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|||", r);
    }

    {
        string_t    src = "abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|abc", r);
    }

    {
        string_t    src = "abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|abc", r);
    }

    {
        string_t    src = "                              abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("||||||||||||||||||||||||||||||abc", r);
    }

    {
        string_t    src = "abc def";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "   abc  def                      ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|||abc||def|||||||||||||||||||||", r);
    }

    {
        string_t    src = "a b c";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c", r);
    }

    {
        string_t    src = "a a a";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a", r);
    }

    {
        string_t    src = " a a a a a a a a a a a a a a a a a a a a a a a a a a a ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a", r);
    }

    {
        string_t    src1(1000u, 'a');
        string_t    src2(10000u, 'b');
        string_t    src = ' ' + src1 + ' ' + src2 + ' ';
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL('|' + src1 + '|' + src2, r);
    }
}



static void test_tokeniser_stringview()
{
    typedef stlsoft::string_tokeniser<
        string_v_t
    ,   char
    ,   stlsoft::skip_blank_tokens<true>
    >                           tokeniser_t;

    {
        string_t    src = "";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = " ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "  ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "   ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "    ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "                              abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "abc def";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "   abc  def                      ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "a b c";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c", r);
    }

    {
        string_t    src = "a a a";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a", r);
    }

    {
        string_t    src = " a a a a a a a a a a a a a a a a a a a a a a a a a a a ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a", r);
    }

    {
        string_t    src1(1000u, 'a');
        string_t    src2(10000u, 'b');
        string_t    src = ' ' + src1 + ' ' + src2 + ' ';
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(src1 + '|' + src2, r);
    }
}

static void test_tokeniser_stringview_skip()
{
    typedef stlsoft::string_tokeniser<
        string_v_t
    ,   char
    ,   stlsoft::skip_blank_tokens<true>
    >                           tokeniser_t;

    {
        string_t    src = "";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = " ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "  ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "   ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "    ";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = "abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "                              abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = "abc def";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "   abc  def                      ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "a b c";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c", r);
    }

    {
        string_t    src = "a a a";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a", r);
    }

    {
        string_t    src = " a a a a a a a a a a a a a a a a a a a a a a a a a a a ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a", r);
    }

    {
        string_t    src1(1000u, 'a');
        string_t    src2(10000u, 'b');
        string_t    src = ' ' + src1 + ' ' + src2 + ' ';
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(src1 + '|' + src2, r);
    }
}

static void test_tokeniser_stringview_noskip()
{
    typedef stlsoft::string_tokeniser<
        string_v_t
    ,   char
    ,   stlsoft::skip_blank_tokens<false>
    >                           tokeniser_t;

    {
        string_t    src = "";
        tokeniser_t tokens(src, ' ');

        XTESTS_TEST_BOOLEAN_TRUE(tokens.empty());
    }

    {
        string_t    src = " ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", r);
    }

    {
        string_t    src = "  ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|", r);
    }

    {
        string_t    src = "   ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("||", r);
    }

    {
        string_t    src = "    ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|||", r);
    }

    {
        string_t    src = "abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|abc", r);
    }

    {
        string_t    src = "abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", r);
    }

    {
        string_t    src = " abc ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|abc", r);
    }

    {
        string_t    src = "                              abc";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("||||||||||||||||||||||||||||||abc", r);
    }

    {
        string_t    src = "abc def";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc|def", r);
    }

    {
        string_t    src = "   abc  def                      ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|||abc||def|||||||||||||||||||||", r);
    }

    {
        string_t    src = "a b c";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|b|c", r);
    }

    {
        string_t    src = "a a a";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a|a|a", r);
    }

    {
        string_t    src = " a a a a a a a a a a a a a a a a a a a a a a a a a a a ";
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a|a", r);
    }

    {
        string_t    src1(1000u, 'a');
        string_t    src2(10000u, 'b');
        string_t    src = ' ' + src1 + ' ' + src2 + ' ';
        tokeniser_t tokens(src, ' ');
        string_t    r;

        XTESTS_TEST_BOOLEAN_FALSE(tokens.empty());

        std::copy(  tokens.begin()
                ,   tokens.end()
                ,   stlsoft::string_concatenator(r, "|", stlsoft::string_concatenation_flags::AlwaysSeparate));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL('|' + src1 + '|' + src2, r);
    }
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
