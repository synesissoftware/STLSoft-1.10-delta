/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.container.insert_ordered_set.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.container.insert_ordered_set project.
 *
 * Created:     29th May 2009
 * Updated:     15th July 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/container/insert_ordered_set.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/algorithm/literal_copy.hpp>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C++ Header Files */
#include <algorithm>
#include <deque>
#include <numeric>
#include <set>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_ios_default_ctor(void);
    static void test_ios_size(void);
    static void test_ios_empty(void);
    static void test_ios_push_front(void);
    static void test_ios_push_back(void);
    static void test_ios_push_front_2(void);
    static void test_ios_push_back_2(void);
    static void test_ios_backinserter(void);
    static void test_ios_find_1(void);
    static void test_ios_erase_1(void);
    static void test_ios_erase_2(void);
    static void test_ios_erase_3(void);
    static void test_ios_erase_4(void);
    static void test_ios_clear_1(void);
    static void test_ios_clear_2(void);
    static void test_push_front_bulk(void);
    static void test_1_09(void);
    static void test_1_10(void);
    static void test_1_11(void);
    static void test_swap(void);
    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);
    static void test_1_20(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    ms;
    _CrtMemCheckpoint(&ms);
#endif

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.container.insert_ordered_set", verbosity))
    {
        XTESTS_RUN_CASE(test_ios_default_ctor);
        XTESTS_RUN_CASE(test_ios_size);
        XTESTS_RUN_CASE(test_ios_empty);
        XTESTS_RUN_CASE(test_ios_push_front);
        XTESTS_RUN_CASE(test_ios_push_back);
        XTESTS_RUN_CASE(test_ios_push_front_2);
        XTESTS_RUN_CASE(test_ios_push_back_2);
        XTESTS_RUN_CASE(test_ios_backinserter);
        XTESTS_RUN_CASE(test_ios_find_1);
        XTESTS_RUN_CASE(test_ios_erase_1);
        XTESTS_RUN_CASE(test_ios_erase_2);
        XTESTS_RUN_CASE(test_ios_erase_3);
        XTESTS_RUN_CASE(test_ios_erase_4);
        XTESTS_RUN_CASE(test_ios_clear_1);
        XTESTS_RUN_CASE(test_ios_clear_2);
        XTESTS_RUN_CASE(test_push_front_bulk);
        XTESTS_RUN_CASE(test_1_09);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_swap);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_1_20);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&ms);
#endif

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

static void test_ios_default_ctor()
{
    stlsoft::insert_ordered_set<int>    set;

    STLSOFT_SUPPRESS_UNUSED(set);

    XTESTS_TEST_PASSED();
}

static void test_ios_size()
{
    stlsoft::insert_ordered_set<int>    set;

    XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
}

static void test_ios_empty()
{
    stlsoft::insert_ordered_set<int>    set;

    XTESTS_TEST_BOOLEAN_TRUE(set.empty());
}

static void test_ios_push_front()
{
    stlsoft::insert_ordered_set<int>    set;

    set.push_front(-1);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

    set.push_front(-1);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

    set.push_front(-1);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.back());
}

static void test_ios_push_back()
{
    stlsoft::insert_ordered_set<int>    set;

    set.push_back(-1);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

    set.push_back(-1);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

    set.push_back(-1);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.back());
}

static void test_ios_push_front_2()
{
    {
        stlsoft::insert_ordered_set<int>    set;

        set.push_front(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

        set.push_front(-2);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

        set.push_front(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.back());
    }

    {
        stlsoft::insert_ordered_set<int>    set;

        set.push_front(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

        set.push_front(-2);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

        set.push_front(-3);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-3, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

        set.push_front(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.back());
    }
}

static void test_ios_push_back_2()
{
    {
        stlsoft::insert_ordered_set<int>    set;

        set.push_back(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

        set.push_back(-2);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.back());

        set.push_back(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());
    }

    {
        stlsoft::insert_ordered_set<int>    set;

        set.push_back(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

        set.push_back(-2);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.back());

        set.push_back(-3);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-3, set.back());

        set.push_back(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());
    }
}

static void test_ios_backinserter()
{
    stlsoft::insert_ordered_set<int>    set;

    set.push_back(-1);
    set.push_back(-2);
    set.push_back(-3);
    set.push_back(-4);

    std::vector<int> results;

    stlsoft::literal_copy(-1, -2, -3, -4, std::back_inserter(results));

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(results.size(), set.size()));
    XTESTS_TEST_BOOLEAN_TRUE(std::equal(set.begin(), set.end(), results.begin()));

    std::vector<int> results1;
    std::copy(  set.begin(), set.end()
            ,   std::back_inserter(results1));
    XTESTS_TEST_BOOLEAN_TRUE(results == results1);

    std::vector<int> results2;
    std::copy(  set.rbegin(), set.rend()
            ,   std::back_inserter(results2));
    std::reverse(results2.begin(), results2.end());
    XTESTS_TEST_BOOLEAN_TRUE(results == results2);
}

static void test_ios_find_1()
{
    {
        stlsoft::insert_ordered_set<int>    set;

        XTESTS_TEST_BOOLEAN_TRUE(set.end() == set.begin());
        XTESTS_TEST_BOOLEAN_TRUE(set.end() == set.find(-2));

        set.push_back(-1);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != set.begin());
        XTESTS_TEST_BOOLEAN_TRUE(set.end() == set.find(-2));

        set.push_back(-2);

        XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(set.end() == set.find(-2)));
        XTESTS_TEST_INTEGER_EQUAL(-2, *set.find(-2));
    }
}

static void test_ios_erase_1()
{
    {
        stlsoft::insert_ordered_set<int>    set;

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());

        XTESTS_TEST_INTEGER_EQUAL(0u, set.erase(1));
        XTESTS_TEST_INTEGER_EQUAL(0u, set.erase(-1));

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());

        set.push_back(-1);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.back());

        XTESTS_TEST_INTEGER_EQUAL(0u, set.erase(1));
        XTESTS_TEST_INTEGER_EQUAL(1u, set.erase(-1));

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());
    }
}

static void test_ios_erase_2()
{
    {
        stlsoft::insert_ordered_set<int>    set;

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());

        set.push_back(-1);
        set.push_back(-2);
        set.push_back(-3);
        set.push_back(-4);
        set.push_back(-5);
        set.push_back(-6);
        set.push_back(-7);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(7u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-7, set.back());

        stlsoft::insert_ordered_set<int>::const_iterator i = set.begin();

        std::advance(i, 2);

        set.erase(i, set.end());

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.back());
    }

    {
        stlsoft::insert_ordered_set<int>    set;

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());

        set.push_back(-1);
        set.push_back(-2);
        set.push_back(-3);
        set.push_back(-4);
        set.push_back(-5);
        set.push_back(-6);
        set.push_back(-7);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(7u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-7, set.back());

        set.erase(set.begin(), set.end());

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());
    }
}

static void test_ios_erase_3()
{
    {
        stlsoft::insert_ordered_set<int>    set;

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());

        { for(int i = 0; i != 10; ++i)
        {
            set.push_front(i);
        }}

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(9, set.front());
        XTESTS_TEST_INTEGER_EQUAL(0, set.back());

        { for(int i = 0; i != 10; ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(9, set.front());

            set.erase(i);

            XTESTS_TEST_INTEGER_EQUAL(10u - (size_t(i) + 1), set.size());
        }}

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());
    }

    {
        stlsoft::insert_ordered_set<int>    set;

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());

        { for(int i = 0; i != 10; ++i)
        {
            set.push_back(i);
        }}

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(0, set.front());
        XTESTS_TEST_INTEGER_EQUAL(9, set.back());

        { for(int i = 0; i != 10; ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(9, set.back());

            set.erase(i);

            XTESTS_TEST_INTEGER_EQUAL(10u - (size_t(i) + 1), set.size());
        }}

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());
    }

    {
        stlsoft::insert_ordered_set<int>    set;

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());

        set.push_back(-1);
        set.push_back(-2);
        set.push_back(-3);
        set.push_back(-4);
        set.push_back(-5);
        set.push_back(-6);
        set.push_back(-7);
        set.push_back(-8);
        set.push_back(-9);
        set.push_front(0);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(0, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        std::vector<int> numbers;

        { for(int i = -1000; i != 1000; ++i)
        {
            numbers.push_back(i);
            set.push_front(i);
        }}

        std::random_shuffle(numbers.begin(), numbers.end());

        { for(int i = 0; !numbers.empty(); ++i)
        {
            set.erase(numbers.front());
            numbers.erase(numbers.begin());

            STLSOFT_SUPPRESS_UNUSED(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());
    }
}

static void test_ios_erase_4()
{
    {
        stlsoft::insert_ordered_set<int> set;

        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());

        set.push_back(-1);
        set.push_back(-2);
        set.push_back(-3);
        set.push_back(-4);
        set.push_back(-5);
        set.push_back(-6);
        set.push_back(-7);
        set.push_back(-8);
        set.push_back(-9);
        set.push_front(0);

        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(0, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        stlsoft::insert_ordered_set<int>::const_iterator it = set.erase(set.begin());

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-1, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(9u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-2, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(8u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-3, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(7u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-3, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-4, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(6u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-4, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-5, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(5u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-5, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-6, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(4u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-6, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-7, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-7, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-8, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-8, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-9, *it);
        XTESTS_TEST_BOOLEAN_FALSE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, set.size());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.front());
        XTESTS_TEST_INTEGER_EQUAL(-9, set.back());

        it = set.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(set.end() == it);
        XTESTS_TEST_BOOLEAN_TRUE(set.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
    }
}

static void test_ios_clear_1()
{
    stlsoft::insert_ordered_set<int>    set;

    XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
    XTESTS_TEST_BOOLEAN_TRUE(set.empty());

    set.clear();

    XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
    XTESTS_TEST_BOOLEAN_TRUE(set.empty());
}

static void test_ios_clear_2()
{
    stlsoft::insert_ordered_set<int>    set;

    XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
    XTESTS_TEST_BOOLEAN_TRUE(set.empty());

    set.push_back(-1);
    set.push_back(-2);
    set.push_back(-3);
    set.push_back(-4);
    set.push_back(-5);
    set.push_back(-6);
    set.push_back(-7);

    set.clear();

    XTESTS_TEST_INTEGER_EQUAL(0u, set.size());
    XTESTS_TEST_BOOLEAN_TRUE(set.empty());
}

static void test_push_front_bulk()
{
    stlsoft::insert_ordered_set<int>    set;

    { for(int i = -1000; i != 1000; ++i)
    {
        set.push_front(i);
    }}

    XTESTS_TEST_INTEGER_EQUAL(2000u, set.size());

    { for(int i = -1000; i != 1000; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(i, *set.find(i));
    }}
}

static void test_1_09()
{
    stlsoft::insert_ordered_set<int>    set;

    XTESTS_TEST_BOOLEAN_TRUE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, set.size());

    set.push_back(0);
    set.push_back(2);
    set.push_back(3);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(0, set.front());
    XTESTS_TEST_INTEGER_EQUAL(3, set.back());

    stlsoft::insert_ordered_set<int>::const_iterator i = set.find(2);

    set.insert(i, 1);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(4u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(0, set.front());
    XTESTS_TEST_INTEGER_EQUAL(3, set.back());

    set.insert(set.end(), 4);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(0, set.front());
    XTESTS_TEST_INTEGER_EQUAL(4, set.back());

    set.insert(set.begin(), -1);

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(6u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, set.front());
    XTESTS_TEST_INTEGER_EQUAL(4, set.back());
}

static void test_1_10()
{
    std::deque<int> d;

    stlsoft::literal_copy(10, 2, 0, -5, -2000, std::back_inserter(d));

    stlsoft::insert_ordered_set<int>    set;

    XTESTS_TEST_BOOLEAN_TRUE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, set.size());

    set.insert(d.begin(), d.end());

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(10, set.front());
    XTESTS_TEST_INTEGER_EQUAL(-2000, set.back());
    XTESTS_TEST_INTEGER_EQUAL(-1993, std::accumulate(set.begin(), set.end(), 0));
}

static void test_1_11()
{
    std::deque<int> d;

    stlsoft::literal_copy(10, 2, 0, -5, -2000, std::back_inserter(d));

    stlsoft::insert_ordered_set<int>    set(d.begin(), d.end());

    XTESTS_TEST_BOOLEAN_FALSE(set.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, set.size());
    XTESTS_TEST_INTEGER_EQUAL(10, set.front());
    XTESTS_TEST_INTEGER_EQUAL(-2000, set.back());
    XTESTS_TEST_INTEGER_EQUAL(-1993, std::accumulate(set.begin(), set.end(), 0));
}

struct X
{
public:
    int i;

public:
    X()
    {}
};

union Y
{
    int i;
    X*  x;
};

static void test_swap()
{
    std::deque<int> d;

    stlsoft::literal_copy(10, 2, 0, -5, -2000, std::back_inserter(d));

    stlsoft::insert_ordered_set<int>    s1(d.begin(), d.end());
    stlsoft::insert_ordered_set<int>    s2;

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, s1.size());
    XTESTS_TEST_INTEGER_EQUAL(10, s1.front());
    XTESTS_TEST_INTEGER_EQUAL(-2000, s1.back());
    XTESTS_TEST_INTEGER_EQUAL(-1993, std::accumulate(s1.begin(), s1.end(), 0));

    XTESTS_TEST_INTEGER_EQUAL(0u, s2.size());
    XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

    s1.swap(s2);

    XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, s2.size());
    XTESTS_TEST_INTEGER_EQUAL(10, s2.front());
    XTESTS_TEST_INTEGER_EQUAL(-2000, s2.back());
    XTESTS_TEST_INTEGER_EQUAL(-1993, std::accumulate(s2.begin(), s2.end(), 0));

    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
}

static void test_1_13()
{
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

static void test_1_20()
{
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
