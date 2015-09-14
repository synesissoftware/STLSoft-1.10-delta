/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.iterator.associative_eraser_iterator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.iterator.associative_eraser_iterator project.
 *
 * Created:     17th June 2010
 * Updated:     12th August 2010
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

#define _SCL_SECURE_NO_WARNINGS

#include <stlsoft/iterator/associative_eraser_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/algorithm/literal_copy.hpp>
#include <stlsoft/iterator/string_concatenator_iterator.hpp>
#include <stlsoft/iterators/associative_select_iterator.hpp>
#include <stlsoft/meta/is_same_type.hpp>
#include <stlsoft/util/dimensionof.h>

/* Standard C++ Header Files */
#include <map>
#include <set>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_set_1(void);
    static void test_set_2(void);
    static void test_set_3(void);
    static void test_set_4(void);
    static void test_map_1(void);
    static void test_map_2(void);
    static void test_map_3(void);
    static void test_map_4(void);
    static void test_multimap_1(void);
    static void test_multimap_2(void);
    static void test_multimap_3(void);
    static void test_multimap_4(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.iterator.associative_eraser_iterator", verbosity))
    {
        XTESTS_RUN_CASE(test_set_1);
        XTESTS_RUN_CASE(test_set_2);
        XTESTS_RUN_CASE(test_set_3);
        XTESTS_RUN_CASE(test_set_4);
        XTESTS_RUN_CASE(test_map_1);
        XTESTS_RUN_CASE(test_map_2);
        XTESTS_RUN_CASE(test_map_3);
        XTESTS_RUN_CASE(test_map_4);
        XTESTS_RUN_CASE(test_multimap_1);
        XTESTS_RUN_CASE(test_multimap_2);
        XTESTS_RUN_CASE(test_multimap_3);
        XTESTS_RUN_CASE(test_multimap_4);

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
    typedef char                            char_t;
    typedef std::basic_string<char_t>       string_t;


    static char const* CONTAINED_STRINGS[] =
    {
        "abc",
        "def",
        "ghi",
        "jkl",
    };

    static char const* ERASED_STRINGS[] =
    {
        "abc",
        "ghi",
        "mno",
    };

    template <typename I>
    string_t cat(I from, I to)
    {
        string_t r;

        std::copy(from, to, stlsoft::string_concatenator(r, ""));

        return r;
    }

static void test_set_1()
{
    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::set<string_t>  c;

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::copy(  r.begin(), r.end()
            ,   stlsoft::assoc_eraser(c, NULL, NULL));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defjkl", cat(c.begin(), c.end()));
}

static void test_set_2()
{
    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::set<string_t>  c;

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijkl", cat(c.begin(), c.end()));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::vector<string_t>   r;

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    size_t  hits;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::assoc_eraser(c, &hits, NULL));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(2u, hits);
}

static void test_set_3()
{
    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::set<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::assoc_eraser(c, NULL, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}

static void test_set_4()
{
    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::set<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  hits;
    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::assoc_eraser(c, &hits, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(2u, hits);
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}

static void test_map_1()
{
    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::map<string_t, int> c;

    { for(size_t i = 0; i != dimensionof(CONTAINED_STRINGS); ++i)
    {
        c[CONTAINED_STRINGS[i]] = int(i);
    }}

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));


    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    typedef std::map<string_t, int>::value_type     value_t;
    typedef stlsoft::select_first_const<value_t>    function_t;

#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcdefghijkl"
    ,   cat(
            stlsoft::assoc_select_first(c.begin())
        ,   stlsoft::assoc_select_first(c.end())
        )
    );
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcdefghijkl"
    ,   cat(
            stlsoft::associative_select(c.begin(), function_t())
        ,   stlsoft::associative_select(c.end(),   function_t())
        )
    );
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::vector<string_t>   r;

    r.push_back("def");
    r.push_back("mno");

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::copy(  r.begin(), r.end()
            ,   stlsoft::assoc_eraser(c, NULL, NULL));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcghijkl"
    ,   cat(
            stlsoft::assoc_select_first(c.begin())
        ,   stlsoft::assoc_select_first(c.end())
        )
    );
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcghijkl"
    ,   cat(
            stlsoft::associative_select(c.begin(), function_t())
        ,   stlsoft::associative_select(c.end(),   function_t())
        )
    );
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

}

static void test_map_2()
{
}

static void test_map_3()
{
}

static void test_map_4()
{
    std::map<string_t, int> c;

    { for(size_t i = 0; i != dimensionof(CONTAINED_STRINGS); ++i)
    {
        c[CONTAINED_STRINGS[i]] = int(i);
    }}

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, c.size()));

    typedef std::map<string_t, int>::value_type     value_t;
    typedef stlsoft::select_first_const<value_t>    function_t;

#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcdefghijkl"
    ,   cat(
            stlsoft::assoc_select_first(c.begin())
        ,   stlsoft::assoc_select_first(c.end())
        )
    );
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcdefghijkl"
    ,   cat(
            stlsoft::associative_select(c.begin(), function_t())
        ,   stlsoft::associative_select(c.end(),   function_t())
        )
    );
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    std::vector<string_t>   r;

    r.push_back("def");
    r.push_back("mno");

    size_t  hits;
    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::assoc_eraser(c, &hits, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));

#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcghijkl"
    ,   cat(
            stlsoft::assoc_select_first(c.begin())
        ,   stlsoft::assoc_select_first(c.end())
        )
    );
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcghijkl"
    ,   cat(
            stlsoft::associative_select(c.begin(), function_t())
        ,   stlsoft::associative_select(c.end(),   function_t())
        )
    );
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    XTESTS_TEST_INTEGER_EQUAL(1u, hits);
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}

static void test_multimap_1()
{
}

static void test_multimap_2()
{
}

static void test_multimap_3()
{
}

static void test_multimap_4()
{
    std::multimap<string_t, int> c;

    { for(size_t i = 0; i != dimensionof(CONTAINED_STRINGS); ++i)
    {
        c.insert(std::make_pair(CONTAINED_STRINGS[i], int(i)));
        c.insert(std::make_pair(CONTAINED_STRINGS[i], int(i) + 1));
    }}

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(8u, c.size()));

    typedef std::multimap<string_t, int>::value_type    value_t;
    typedef stlsoft::select_first_const<value_t>        function_t;

#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcabcdefdefghighijkljkl"
    ,   cat(
            stlsoft::assoc_select_first(c.begin())
        ,   stlsoft::assoc_select_first(c.end())
        )
    );
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcabcdefdefghighijkljkl"
    ,   cat(
            stlsoft::associative_select(c.begin(), function_t())
        ,   stlsoft::associative_select(c.end(),   function_t())
        )
    );
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */

    std::vector<string_t>   r;

    r.push_back("def");
    r.push_back("mno");

    size_t  hits;
    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::assoc_eraser(c, &hits, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));

#if defined(STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT) && \
    !defined(STLSOFT_COMPILER_IS_BORLAND)
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcabcghighijkljkl"
    ,   cat(
            stlsoft::assoc_select_first(c.begin())
        ,   stlsoft::assoc_select_first(c.end())
        )
    );
#else /* ? STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        "abcabcghighijkljkl"
    ,   cat(
            stlsoft::associative_select(c.begin(), function_t())
        ,   stlsoft::associative_select(c.end(),   function_t())
        )
    );
#endif /* !STLSOFT_CF_TEMPLATE_PARTIAL_SPECIALISATION_SUPPORT */
    XTESTS_TEST_INTEGER_EQUAL(2u, hits);
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
