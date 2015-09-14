/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.iterator.sorted_eraser_iterator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.iterator.sorted_eraser_iterator project.
 *
 * Created:     18th June 2010
 * Updated:     23rd June 2010
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

#include <stlsoft/iterator/sorted_eraser_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/algorithm/literal_copy.hpp>
#include <stlsoft/iterator/string_concatenator_iterator.hpp>
#include <stlsoft/meta/is_same_type.hpp>
#include <stlsoft/util/dimensionof.h>

/* Standard C++ Header Files */
#include <deque>
#include <list>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_deque_1(void);
    static void test_deque_2(void);
    static void test_deque_3(void);
    static void test_deque_4(void);
    static void test_list_1(void);
    static void test_list_2(void);
    static void test_list_3(void);
    static void test_list_4(void);
    static void test_vector_1(void);
    static void test_vector_2(void);
    static void test_vector_3(void);
    static void test_vector_4(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.iterator.sorted_eraser_iterator", verbosity))
    {
#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER >= 1300
        XTESTS_RUN_CASE(test_deque_1);
#else
        STLSOFT_SUPPRESS_UNUSED(test_deque_1);
#endif
        XTESTS_RUN_CASE(test_deque_2);
        XTESTS_RUN_CASE(test_deque_3);
        XTESTS_RUN_CASE(test_deque_4);
        XTESTS_RUN_CASE(test_list_1);
        XTESTS_RUN_CASE(test_list_2);
        XTESTS_RUN_CASE(test_list_3);
        XTESTS_RUN_CASE(test_list_4);
        XTESTS_RUN_CASE(test_vector_1);
        XTESTS_RUN_CASE(test_vector_2);
        XTESTS_RUN_CASE(test_vector_3);
        XTESTS_RUN_CASE(test_vector_4);

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
        "def",
        "ghi",
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

static void test_deque_1()
{
    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::deque<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, NULL, NULL));

    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
}

static void test_deque_2()
{
    //puts(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) ")");

    std::deque<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  hits;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, &hits, NULL));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(3u, hits);
}

static void test_deque_3()
{
    std::deque<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, NULL, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}

static void test_deque_4()
{
    std::deque<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  hits;
    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, &hits, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(3u, hits);
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}

static void test_list_1()
{
    std::list<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
}

static void test_list_2()
{
    std::list<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  hits;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, &hits, NULL));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(3u, hits);
}

static void test_list_3()
{
    std::list<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, NULL, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}

static void test_list_4()
{
    std::list<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  hits;
    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, &hits, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(3u, hits);
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}

static void test_vector_1()
{
    std::vector<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
}

static void test_vector_2()
{
    std::vector<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  hits;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, &hits, NULL));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(3u, hits);
}

static void test_vector_3()
{
    std::vector<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, NULL, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}

static void test_vector_4()
{
    std::vector<string_t>  c;

    std::copy(  CONTAINED_STRINGS, CONTAINED_STRINGS + dimensionof(CONTAINED_STRINGS)
            ,   std::inserter(c, c.end()));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefdefghighijkl", cat(c.begin(), c.end()));

    std::vector<string_t>   r;

    std::copy(  ERASED_STRINGS, ERASED_STRINGS + dimensionof(ERASED_STRINGS)
            ,   std::inserter(r, r.end()));

    size_t  hits;
    size_t  misses;

    std::copy(  r.begin(), r.end()
            ,   stlsoft::sorted_eraser(c, &hits, &misses));

    XTESTS_TEST_BOOLEAN_FALSE(c.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, c.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("defdefjkl", cat(c.begin(), c.end()));
    XTESTS_TEST_INTEGER_EQUAL(3u, hits);
    XTESTS_TEST_INTEGER_EQUAL(1u, misses);
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
