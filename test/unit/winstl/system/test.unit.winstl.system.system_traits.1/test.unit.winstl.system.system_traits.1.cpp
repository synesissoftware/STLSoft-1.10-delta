/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.system.system_traits.1.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.system.system_traits.1 project.
 *
 * Created:     31st December 2008
 * Updated:     11th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/system/system_traits.hpp>

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
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_types(void);
    static void test_str_copy(void);
    static void test_str_n_copy(void);
#if 0
    static void test_str_cat(void);
    static void test_str_n_cat(void);
#endif /* 0 */
    static void test_str_compare(void);
    static void test_str_compare_no_case(void);
    static void test_str_n_compare(void);
    static void test_str_n_compare_no_case(void);
    static void test_str_len(void);
    static void test_str_end(void);
    static void test_str_chr(void);
    static void test_str_rchr(void);
    static void test_str_str(void);
    static void test_str_pbrk(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.system.system_traits.1", verbosity))
    {
        XTESTS_RUN_CASE(test_types);
        XTESTS_RUN_CASE(test_str_copy);
        XTESTS_RUN_CASE(test_str_n_copy);
#if 0
        XTESTS_RUN_CASE(test_str_cat);
        XTESTS_RUN_CASE(test_str_n_cat);
#endif /* 0 */
        XTESTS_RUN_CASE(test_str_compare);
        XTESTS_RUN_CASE(test_str_compare_no_case);
        XTESTS_RUN_CASE(test_str_n_compare);
        XTESTS_RUN_CASE(test_str_n_compare_no_case);
        XTESTS_RUN_CASE(test_str_len);
        XTESTS_RUN_CASE(test_str_end);
        XTESTS_RUN_CASE(test_str_chr);
        XTESTS_RUN_CASE(test_str_rchr);
        XTESTS_RUN_CASE(test_str_str);
        XTESTS_RUN_CASE(test_str_pbrk);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/system_traits.hpp", NULL);
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

    typedef winstl::system_traits<char>         system_traits_m_t;
    typedef winstl::system_traits<wchar_t>      system_traits_w_t;

    typedef std::basic_string<char>             string_m_t;
    typedef std::basic_string<wchar_t>          string_w_t;

    static const char       alphabet_m[]        =   "abcdefghijklmnopqrstuvwxyz";
    static const wchar_t    alphabet_w[]        =   L"abcdefghijklmnopqrstuvwxyz";

    static const char       hundred_and_one_m[] =   "101";
    static const wchar_t    hundred_and_one_w[] =   L"101";




static void test_types()
{
    {
        system_traits_m_t::char_type*       p0  =   NULL;
        system_traits_m_t::size_type*       p1  =   NULL;
        system_traits_m_t::difference_type* p2  =   NULL;
        system_traits_m_t::class_type*      p3  =   NULL;
        system_traits_m_t::int_type*        p4  =   NULL;
        system_traits_m_t::bool_type*       p5  =   NULL;
        system_traits_m_t::module_type*     p6  =   NULL;
        system_traits_m_t::handle_type*     p7  =   NULL;
        system_traits_m_t::error_type*      p8  =   NULL;

        STLSOFT_SUPPRESS_UNUSED(p0);
        STLSOFT_SUPPRESS_UNUSED(p1);
        STLSOFT_SUPPRESS_UNUSED(p2);
        STLSOFT_SUPPRESS_UNUSED(p3);
        STLSOFT_SUPPRESS_UNUSED(p4);
        STLSOFT_SUPPRESS_UNUSED(p5);
        STLSOFT_SUPPRESS_UNUSED(p6);
        STLSOFT_SUPPRESS_UNUSED(p7);
        STLSOFT_SUPPRESS_UNUSED(p8);

        XTESTS_TEST_PASSED();
    }

    {
        system_traits_w_t::char_type*       p0  =   NULL;
        system_traits_w_t::size_type*       p1  =   NULL;
        system_traits_w_t::difference_type* p2  =   NULL;
        system_traits_w_t::class_type*      p3  =   NULL;
        system_traits_w_t::int_type*        p4  =   NULL;
        system_traits_w_t::bool_type*       p5  =   NULL;
        system_traits_w_t::module_type*     p6  =   NULL;
        system_traits_w_t::handle_type*     p7  =   NULL;
        system_traits_w_t::error_type*      p8  =   NULL;

        STLSOFT_SUPPRESS_UNUSED(p0);
        STLSOFT_SUPPRESS_UNUSED(p1);
        STLSOFT_SUPPRESS_UNUSED(p2);
        STLSOFT_SUPPRESS_UNUSED(p3);
        STLSOFT_SUPPRESS_UNUSED(p4);
        STLSOFT_SUPPRESS_UNUSED(p5);
        STLSOFT_SUPPRESS_UNUSED(p6);
        STLSOFT_SUPPRESS_UNUSED(p7);
        STLSOFT_SUPPRESS_UNUSED(p8);

        XTESTS_TEST_PASSED();
    }
}

static void test_str_copy()
{
    {
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet_m); ++i)
        {
            char    buff[STLSOFT_NUM_ELEMENTS(alphabet_m)];
            char*   p;

            p = system_traits_m_t::char_copy(&buff[0], &alphabet_m[0] + (STLSOFT_NUM_ELEMENTS(alphabet_m) - i), 1u + system_traits_m_t::str_len(&alphabet_m[0] + (STLSOFT_NUM_ELEMENTS(alphabet_m) - i)));
            XTESTS_TEST_POINTER_EQUAL(&buff[0], p);
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL(&alphabet_m[0] + (STLSOFT_NUM_ELEMENTS(alphabet_m) - i), buff);
        }}
    }

    {
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet_w); ++i)
        {
            wchar_t     buff[STLSOFT_NUM_ELEMENTS(alphabet_w)];
            wchar_t*    p;

            p = system_traits_w_t::char_copy(&buff[0], &alphabet_w[0] + (STLSOFT_NUM_ELEMENTS(alphabet_w) - i), 1u + system_traits_w_t::str_len(&alphabet_w[0] + (STLSOFT_NUM_ELEMENTS(alphabet_w) - i)));
            XTESTS_TEST_POINTER_EQUAL(&buff[0], p);
            XTESTS_TEST_WIDE_STRING_EQUAL(&alphabet_w[0] + (STLSOFT_NUM_ELEMENTS(alphabet_w) - i), buff);
        }}
    }
}

static void test_str_n_copy()
{
    {
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet_m) - 1; ++i)
        {
            char    buff[STLSOFT_NUM_ELEMENTS(alphabet_m)];
            char*   p;

            p = system_traits_m_t::char_copy(&buff[0], &alphabet_m[0], i);
            buff[i] = '\0';
            XTESTS_TEST_POINTER_EQUAL(&buff[0], p);
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL(string_m_t(alphabet_m, i), buff);
        }}
    }

    {
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet_w) - 1; ++i)
        {
            wchar_t     buff[STLSOFT_NUM_ELEMENTS(alphabet_w)];
            wchar_t*    p;

            p = system_traits_w_t::char_copy(&buff[0], &alphabet_w[0], i);
            buff[i] = '\0';
            XTESTS_TEST_POINTER_EQUAL(&buff[0], p);
            XTESTS_TEST_WIDE_STRING_EQUAL(string_w_t(alphabet_w, i), buff);
        }}
    }
}

#if 0
static void test_str_cat()
{
    static const size_t increments[] = { 1, 2, 13, 26 };

    {
        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(increments); ++j)
        {
            const size_t increment = increments[j];

            STLSOFT_ASSERT(0 == (26 % increment));

            char    buff[STLSOFT_NUM_ELEMENTS(alphabet_m)] = "";

            { for(size_t i = 0; i != 26; )
            {
                char*   p = system_traits_m_t::str_cat(buff, string_m_t(&alphabet_m[0] + i, increment).c_str());

                i += increment;

                buff[i] = '\0';

                XTESTS_TEST_POINTER_EQUAL(&buff[0], p);
                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(string_m_t(alphabet_m, i), buff);
            }}
        }}
    }

    {
        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(increments); ++j)
        {
            const size_t increment = increments[j];

            STLSOFT_ASSERT(0 == (26 % increment));

            wchar_t buff[STLSOFT_NUM_ELEMENTS(alphabet_w)] = L"";

            { for(size_t i = 0; i != 26; )
            {
                wchar_t*    p = system_traits_w_t::str_cat(buff, string_w_t(&alphabet_w[0] + i, increment).c_str());

                i += increment;

                buff[i] = '\0';

                XTESTS_TEST_POINTER_EQUAL(&buff[0], p);
                XTESTS_TEST_WIDE_STRING_EQUAL(string_w_t(alphabet_w, i), buff);
            }}
        }}
    }
}

static void test_str_n_cat()
{
    static const size_t increments[] = { 1, 2, 13, 26 };

    {
        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(increments); ++j)
        {
            const size_t increment = increments[j];

            STLSOFT_ASSERT(0 == (26 % increment));

            char    buff[STLSOFT_NUM_ELEMENTS(alphabet_m)] = "";

            { for(size_t i = 0; i != 26; )
            {
                char*   p = system_traits_m_t::str_n_cat(buff, &alphabet_m[0] + i, increment);

                i += increment;

                buff[i] = '\0';

                XTESTS_TEST_POINTER_EQUAL(&buff[0], p);
                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(string_m_t(alphabet_m, i), buff);
            }}
        }}
    }

    {
        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(increments); ++j)
        {
            const size_t increment = increments[j];

            STLSOFT_ASSERT(0 == (26 % increment));

            wchar_t buff[STLSOFT_NUM_ELEMENTS(alphabet_w)] = L"";

            { for(size_t i = 0; i != 26; )
            {
                wchar_t*    p = system_traits_w_t::str_n_cat(buff, &alphabet_w[0] + i, increment);

                i += increment;

                buff[i] = '\0';

                XTESTS_TEST_POINTER_EQUAL(&buff[0], p);
                XTESTS_TEST_WIDE_STRING_EQUAL(string_w_t(alphabet_w, i), buff);
            }}
        }}
    }
}
#endif /* 0 */

static void test_str_compare()
{
    {
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare("", ""));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare("a", "a"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare(alphabet_m, alphabet_m));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare(alphabet_m, "abcdefghijklmnopqrstuvwxyz"));

        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare("a", "b"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare("a", "ab"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare("ab", "abc"));

        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare("b", "a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare("ab", "a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare("abc", "ab"));
    }

#ifndef __BORLANDC__
    {
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare(L"", L""));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare(L"a", L"a"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare(alphabet_w, alphabet_w));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare(alphabet_w, L"abcdefghijklmnopqrstuvwxyz"));

        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare(L"a", L"b"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare(L"a", L"ab"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare(L"ab", L"abc"));

        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare(L"b", L"a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare(L"ab", L"a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare(L"abc", L"ab"));
    }
#endif /* compiler */
}

static void test_str_compare_no_case()
{
    {
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case("", ""));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case("a", "a"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case("a", "A"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case("A", "a"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case("A", "A"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case(alphabet_m, alphabet_m));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case(alphabet_m, "abcdefghijklmnopqrstuvwxyz"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case(alphabet_m, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_compare_no_case("ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet_m));

        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("a", "b"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("a", "B"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("A", "b"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("A", "B"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("a", "ab"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("a", "Ab"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("a", "aB"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("a", "AB"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("A", "Ab"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("A", "aB"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("A", "AB"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("ab", "Abc"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("ab", "aBc"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("ab", "abC"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("AB", "Abc"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("AB", "aBc"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_compare_no_case("AB", "abC"));

        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("b", "a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("b", "A"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("B", "a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("B", "A"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("Ab", "a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("ab", "A"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("aB", "a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("Abc", "ab"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("aBc", "ab"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("abC", "ab"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("Abc", "AB"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("aBc", "AB"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_compare_no_case("abC", "AB"));
    }

#ifndef __BORLANDC__
    {
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(L"", L""));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(L"a", L"a"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(L"a", L"A"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(L"A", L"a"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(L"A", L"A"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(alphabet_w, alphabet_w));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(alphabet_w, L"abcdefghijklmnopqrstuvwxyz"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(alphabet_w, L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_compare_no_case(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet_w));

        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"a", L"b"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"a", L"B"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"A", L"b"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"A", L"B"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"a", L"ab"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"a", L"Ab"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"a", L"aB"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"a", L"AB"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"A", L"Ab"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"A", L"aB"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"A", L"AB"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"ab", L"Abc"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"ab", L"aBc"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"ab", L"abC"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"AB", L"Abc"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"AB", L"aBc"));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_compare_no_case(L"AB", L"abC"));

        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"b", L"a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"b", L"A"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"B", L"a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"B", L"A"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"Ab", L"a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"ab", L"A"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"aB", L"a"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"Abc", L"ab"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"aBc", L"ab"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"abC", L"ab"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"Abc", L"AB"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"aBc", L"AB"));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_compare_no_case(L"abC", L"AB"));
    }
#endif /* compiler */
}

static void test_str_n_compare()
{
    {
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare("", "", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare("a", "a", 1u));
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet_m) - 1; ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare(alphabet_m, alphabet_m, i));
            XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare(alphabet_m, "abcdefghijklmnopqrstuvwxyz", i));
        }}

        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_n_compare("a", "b", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare("a", "ab", 1u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_n_compare("a", "ab", 2u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_n_compare("ab", "abc", 3u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare("ab", "abc", 2u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_n_compare("ab", "abc", 3u));

        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_n_compare("b", "a", 1u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_n_compare("ab", "a", 2u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_n_compare("abc", "ab", 3u));
    }

#ifndef __BORLANDC__
    {
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare(L"", L"", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare(L"a", L"a", 1u));
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet_w) - 1; ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare(alphabet_w, alphabet_w, i));
            XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare(alphabet_w, L"abcdefghijklmnopqrstuvwxyz", i));
        }}

        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_n_compare(L"a", L"b", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare(L"a", L"ab", 1u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_n_compare(L"a", L"ab", 2u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_n_compare(L"ab", L"abc", 3u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare(L"ab", L"abc", 2u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_n_compare(L"ab", L"abc", 3u));

        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_n_compare(L"b", L"a", 1u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_n_compare(L"ab", L"a", 2u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_n_compare(L"abc", L"ab", 3u));
    }
#endif /* compiler */
}

static void test_str_n_compare_no_case()
{
    {
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("", "", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("a", "a", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("a", "A", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("A", "a", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("A", "A", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case(alphabet_m, alphabet_m, 26u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case(alphabet_m, "abcdefghijklmnopqrstuvwxyz", 26u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case(alphabet_m, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet_m, 26u));

        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_n_compare_no_case("a", "b", 1u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_n_compare_no_case("a", "B", 1u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_n_compare_no_case("A", "b", 1u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_m_t::str_n_compare_no_case("A", "B", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("a", "ab", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("a", "Ab", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("a", "aB", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("a", "AB", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("A", "Ab", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("A", "aB", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("A", "AB", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("ab", "Abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("ab", "aBc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("ab", "abC", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("AB", "Abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("AB", "aBc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("AB", "abC", 2u));

        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_n_compare_no_case("b", "a", 1u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_n_compare_no_case("b", "A", 1u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_n_compare_no_case("B", "a", 1u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_m_t::str_n_compare_no_case("B", "A", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("Ab", "a", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("ab", "A", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("aB", "a", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("Abc", "ab", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("aBc", "ab", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("abC", "ab", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("Abc", "AB", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("aBc", "AB", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_m_t::str_n_compare_no_case("abC", "AB", 2u));
    }

#ifndef __BORLANDC__
    {
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"", L"", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"a", L"a", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"a", L"A", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"A", L"a", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"A", L"A", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(alphabet_w, alphabet_w, 26u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(alphabet_w, L"abcdefghijklmnopqrstuvwxyz", 26u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(alphabet_w, L"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet_w, 26u));

        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_n_compare_no_case(L"a", L"b", 1u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_n_compare_no_case(L"a", L"B", 1u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_n_compare_no_case(L"A", L"b", 1u));
        XTESTS_TEST_INTEGER_LESS(0, system_traits_w_t::str_n_compare_no_case(L"A", L"B", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"a", L"ab", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"a", L"Ab", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"a", L"aB", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"a", L"AB", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"A", L"Ab", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"A", L"aB", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"A", L"AB", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"ab", L"Abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"ab", L"aBc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"ab", L"abC", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"AB", L"Abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"AB", L"aBc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"AB", L"abC", 2u));

        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_n_compare_no_case(L"b", L"a", 1u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_n_compare_no_case(L"b", L"A", 1u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_n_compare_no_case(L"B", L"a", 1u));
        XTESTS_TEST_INTEGER_GREATER(0, system_traits_w_t::str_n_compare_no_case(L"B", L"A", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"Ab", L"a", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"ab", L"A", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"aB", L"a", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"Abc", L"ab", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"aBc", L"ab", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"abC", L"ab", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"Abc", L"AB", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"aBc", L"AB", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0, system_traits_w_t::str_n_compare_no_case(L"abC", L"AB", 2u));
    }
#endif /* compiler */
}

static void test_str_len()
{
    {
        XTESTS_TEST_INTEGER_EQUAL(0u, system_traits_m_t::str_len(""));

        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet_m) - 1; ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(i, system_traits_m_t::str_len(&alphabet_m[0] + (STLSOFT_NUM_ELEMENTS(alphabet_m) - 1) - i));
        }}

        const string_m_t    thousandSpaces(1000u, ' ');

        XTESTS_TEST_INTEGER_EQUAL(thousandSpaces.size(), system_traits_m_t::str_len(thousandSpaces.c_str()));
    }

#ifndef __BORLANDC__
    {
        XTESTS_TEST_INTEGER_EQUAL(0u, system_traits_w_t::str_len(L""));

        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(alphabet_w) - 1; ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(i, system_traits_w_t::str_len(&alphabet_w[0] + (STLSOFT_NUM_ELEMENTS(alphabet_w) - 1) - i));
        }}

        const string_w_t    thousandSpaces(1000u, ' ');

        XTESTS_TEST_INTEGER_EQUAL(thousandSpaces.size(), system_traits_w_t::str_len(thousandSpaces.c_str()));
    }
#endif /* compiler */
}

static void test_str_end()
{
    {
        const char  str1[]  =   "";
        char const* str2    =   alphabet_m;

        XTESTS_TEST_POINTER_EQUAL(str1, system_traits_m_t::str_end(str1));
        XTESTS_TEST_POINTER_EQUAL(str2 + 26, system_traits_m_t::str_end(str2));
    }

#ifndef __BORLANDC__
    {
        const wchar_t   str1[]  =   L"";
        wchar_t const*  str2    =   alphabet_w;

        XTESTS_TEST_POINTER_EQUAL(str1, system_traits_w_t::str_end(str1));
        XTESTS_TEST_POINTER_EQUAL(str2 + 26, system_traits_w_t::str_end(str2));
    }
#endif /* compiler */
}

static void test_str_chr()
{
    {
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_chr(alphabet_m, 'a'));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 3, system_traits_m_t::str_chr(alphabet_m, 'd'));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 25, system_traits_m_t::str_chr(alphabet_m, 'z'));

        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_chr(alphabet_m, 'A'));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_chr(alphabet_m, 'D'));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_chr(alphabet_m, 'Z'));
    }

    {
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_chr(alphabet_w, 'a'));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 3, system_traits_w_t::str_chr(alphabet_w, 'd'));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 25, system_traits_w_t::str_chr(alphabet_w, 'z'));

        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_chr(alphabet_w, 'A'));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_chr(alphabet_w, 'D'));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_chr(alphabet_w, 'Z'));
    }
}

static void test_str_rchr()
{
    {
        XTESTS_TEST_POINTER_EQUAL(hundred_and_one_m + 1, system_traits_m_t::str_rchr(hundred_and_one_m, '0'));
        XTESTS_TEST_POINTER_EQUAL(hundred_and_one_m + 2, system_traits_m_t::str_rchr(hundred_and_one_m, '1'));

        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_rchr(alphabet_m, '2'));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_rchr(alphabet_m, '3'));
    }

    {
        XTESTS_TEST_POINTER_EQUAL(hundred_and_one_w + 1, system_traits_w_t::str_rchr(hundred_and_one_w, '0'));
        XTESTS_TEST_POINTER_EQUAL(hundred_and_one_w + 2, system_traits_w_t::str_rchr(hundred_and_one_w, '1'));

        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_rchr(alphabet_w, '2'));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_rchr(alphabet_w, '3'));
    }
}

static void test_str_str()
{
    {
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_str(alphabet_m, ""));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_str(alphabet_m, "a"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_str(alphabet_m, "abc"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_str(alphabet_m, "abcdefghijklm"));

        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 1, system_traits_m_t::str_str(alphabet_m, "bcd"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 2, system_traits_m_t::str_str(alphabet_m, "cde"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 3, system_traits_m_t::str_str(alphabet_m, "defghijklm"));

        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_str(alphabet_m, "A"));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_str(alphabet_m, "Abc"));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_str(alphabet_m, "abC"));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_str(alphabet_m, "abd"));
    }

    {
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_str(alphabet_w, L""));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_str(alphabet_w, L"a"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_str(alphabet_w, L"abc"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_str(alphabet_w, L"abcdefghijklm"));

        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 1, system_traits_w_t::str_str(alphabet_w, L"bcd"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 2, system_traits_w_t::str_str(alphabet_w, L"cde"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 3, system_traits_w_t::str_str(alphabet_w, L"defghijklm"));

        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_str(alphabet_w, L"A"));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_str(alphabet_w, L"Abc"));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_str(alphabet_w, L"abC"));
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_str(alphabet_w, L"abd"));
    }
}

static void test_str_pbrk()
{
    {
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_pbrk(alphabet_m, ""));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_pbrk(alphabet_m, "a"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_pbrk(alphabet_m, "abc"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_pbrk(alphabet_m, "cba"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_pbrk(alphabet_m, "cab"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_pbrk(alphabet_m, "abcdefghijklm"));

        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 1, system_traits_m_t::str_pbrk(alphabet_m, "bcd"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 1, system_traits_m_t::str_pbrk(alphabet_m, "bcd"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 2, system_traits_m_t::str_pbrk(alphabet_m, "cde"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 2, system_traits_m_t::str_pbrk(alphabet_m, "edc"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 3, system_traits_m_t::str_pbrk(alphabet_m, "defghijklm"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 3, system_traits_m_t::str_pbrk(alphabet_m, "mlkjihgfed"));

        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_m_t::str_pbrk(alphabet_m, "A"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 1, system_traits_m_t::str_pbrk(alphabet_m, "Abc"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_pbrk(alphabet_m, "abC"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_m + 0, system_traits_m_t::str_pbrk(alphabet_m, "abd"));
    }

    {
        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_pbrk(alphabet_w, L""));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_pbrk(alphabet_w, L"a"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_pbrk(alphabet_w, L"abc"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_pbrk(alphabet_w, L"cba"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_pbrk(alphabet_w, L"cab"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_pbrk(alphabet_w, L"abcdefghijklm"));

        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 1, system_traits_w_t::str_pbrk(alphabet_w, L"bcd"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 1, system_traits_w_t::str_pbrk(alphabet_w, L"bcd"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 2, system_traits_w_t::str_pbrk(alphabet_w, L"cde"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 2, system_traits_w_t::str_pbrk(alphabet_w, L"edc"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 3, system_traits_w_t::str_pbrk(alphabet_w, L"defghijklm"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 3, system_traits_w_t::str_pbrk(alphabet_w, L"mlkjihgfed"));

        XTESTS_TEST_POINTER_EQUAL(NULL, system_traits_w_t::str_pbrk(alphabet_w, L"A"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 1, system_traits_w_t::str_pbrk(alphabet_w, L"Abc"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_pbrk(alphabet_w, L"abC"));
        XTESTS_TEST_POINTER_EQUAL(alphabet_w + 0, system_traits_w_t::str_pbrk(alphabet_w, L"abd"));
    }
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
