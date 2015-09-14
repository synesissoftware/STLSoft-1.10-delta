/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.container.insert_ordered_map.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.container.insert_ordered_map project.
 *
 * Created:     8th July 2010
 * Updated:     10th August 2010
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

#include <stlsoft/container/insert_ordered_map.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/algorithm/literal_copy.hpp>
#include <stlsoft/iterators/associative_select_iterator.hpp>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C++ Header Files */
#include <algorithm>
#include <deque>
#include <map>
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
    static void test_1_12(void);
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.container.insert_ordered_map", verbosity))
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
        XTESTS_RUN_CASE(test_1_12);
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

    typedef std::string     string_t;


static void test_ios_default_ctor()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    STLSOFT_SUPPRESS_UNUSED(iom);

    XTESTS_TEST_PASSED();
}

static void test_ios_size()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
}

static void test_ios_empty()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
}

static void test_ios_push_front()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    iom.push_front(std::make_pair<int, string_t>(-1, "-1"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

    iom.push_front(std::make_pair<int, string_t>(-1, "-1"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

    iom.push_front(std::make_pair<int, string_t>(-1, "-1"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);
}

static void test_ios_push_back()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

    iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

    iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);
}

static void test_ios_push_front_2()
{
    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        iom.push_front(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

        iom.push_front(std::make_pair<int, string_t>(-2, "-2"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

        iom.push_front(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.back().first);
    }

    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        iom.push_front(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

        iom.push_front(std::make_pair<int, string_t>(-2, "-2"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

        iom.push_front(std::make_pair<int, string_t>(-3, "-3"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-3, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

        iom.push_front(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.back().first);
    }
}

static void test_ios_push_back_2()
{
    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

        iom.push_back(std::make_pair<int, string_t>(-2, "-2"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.back().first);

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);
    }

    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

        iom.push_back(std::make_pair<int, string_t>(-2, "-2"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.back().first);

        iom.push_back(std::make_pair<int, string_t>(-3, "-3"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-3, iom.back().first);

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);
    }
}

static void test_ios_backinserter()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    iom.push_back(std::make_pair<int, string_t>(-1, "-1"));
    iom.push_back(std::make_pair<int, string_t>(-2, "-2"));
    iom.push_back(std::make_pair<int, string_t>(-3, "-3"));
    iom.push_back(std::make_pair<int, string_t>(-4, "-4"));

    std::map<int, string_t> results;

    stlsoft::literal_copy(
        std::make_pair<int, string_t>(-1, "-1")
    ,   std::make_pair<int, string_t>(-2, "-2")
    ,   std::make_pair<int, string_t>(-3, "-3")
    ,   std::make_pair<int, string_t>(-4, "-4")
    ,   std::inserter(results, results.end())
    );

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(results.size(), iom.size()));
    XTESTS_TEST_BOOLEAN_TRUE(std::equal(iom.begin(), iom.end(), results.rbegin()));

    std::map<int, string_t> results1;
#ifndef _DEBUG
    std::copy(  iom.begin(), iom.end()
            ,   std::inserter(results1, results1.end()));
    XTESTS_TEST_BOOLEAN_TRUE(results == results1);
#endif /* !_DEBUG */

    std::map<int, string_t> results2;
#ifndef _DEBUG
    std::copy(  iom.rbegin(), iom.rend()
            ,   std::inserter(results2, results2.end()));
    std::reverse(results2.begin(), results2.end());
    XTESTS_TEST_BOOLEAN_TRUE(results == results2);
#endif /* !_DEBUG */
}

static void test_ios_find_1()
{
    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() == iom.begin());
        XTESTS_TEST_BOOLEAN_TRUE(iom.end() == iom.find(-2));

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != iom.begin());
        XTESTS_TEST_BOOLEAN_TRUE(iom.end() == iom.find(-2));

        iom.push_back(std::make_pair<int, string_t>(-2, "-2"));

        XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_FALSE(iom.end() == iom.find(-2)));
        XTESTS_TEST_INTEGER_EQUAL(-2, (*iom.find(-2)).first);
    }
}

static void test_ios_erase_1()
{
    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.erase(1));
        XTESTS_TEST_INTEGER_EQUAL(0u, iom.erase(-1));

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.back().first);

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.erase(1));
        XTESTS_TEST_INTEGER_EQUAL(1u, iom.erase(-1));

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
    }
}

static void test_ios_erase_2()
{
    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));
        iom.push_back(std::make_pair<int, string_t>(-2, "-2"));
        iom.push_back(std::make_pair<int, string_t>(-3, "-3"));
        iom.push_back(std::make_pair<int, string_t>(-4, "-4"));
        iom.push_back(std::make_pair<int, string_t>(-5, "-5"));
        iom.push_back(std::make_pair<int, string_t>(-6, "-6"));
        iom.push_back(std::make_pair<int, string_t>(-7, "-7"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(7u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-7, iom.back().first);

        stlsoft::insert_ordered_map<int, string_t>::const_iterator i = iom.begin();

        std::advance(i, 2);

        iom.erase(i, iom.end());

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.back().first);
    }

    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));
        iom.push_back(std::make_pair<int, string_t>(-2, "-2"));
        iom.push_back(std::make_pair<int, string_t>(-3, "-3"));
        iom.push_back(std::make_pair<int, string_t>(-4, "-4"));
        iom.push_back(std::make_pair<int, string_t>(-5, "-5"));
        iom.push_back(std::make_pair<int, string_t>(-6, "-6"));
        iom.push_back(std::make_pair<int, string_t>(-7, "-7"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(7u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-7, iom.back().first);

        iom.erase(iom.begin(), iom.end());

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
    }
}

static void test_ios_erase_3()
{
    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

        { for(int i = 0; i != 10; ++i)
        {
            iom.push_front(std::make_pair<int, string_t>(i, "i"));
        }}

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(9, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(0, iom.back().first);

        { for(int i = 0; i != 10; ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(9, iom.front().first);

            iom.erase(i);

            XTESTS_TEST_INTEGER_EQUAL(10u - (size_t(i) + 1), iom.size());
        }}

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
    }

    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

        { for(int i = 0; i != 10; ++i)
        {
            iom.push_back(std::make_pair<int, string_t>(i, "i"));
        }}

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(0, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(9, iom.back().first);

        { for(int i = 0; i != 10; ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(9, iom.back().first);

            iom.erase(i);

            XTESTS_TEST_INTEGER_EQUAL(10u - (size_t(i) + 1), iom.size());
        }}

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
    }

    {
        stlsoft::insert_ordered_map<int, string_t>    iom;

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));
        iom.push_back(std::make_pair<int, string_t>(-2, "-2"));
        iom.push_back(std::make_pair<int, string_t>(-3, "-3"));
        iom.push_back(std::make_pair<int, string_t>(-4, "-4"));
        iom.push_back(std::make_pair<int, string_t>(-5, "-5"));
        iom.push_back(std::make_pair<int, string_t>(-6, "-6"));
        iom.push_back(std::make_pair<int, string_t>(-7, "-7"));
        iom.push_back(std::make_pair<int, string_t>(-8, "-8"));
        iom.push_back(std::make_pair<int, string_t>(-9, "-9"));
        iom.push_front(std::make_pair<int, string_t>(0, "0"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(0, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        std::vector<int> numbers;

        { for(int i = -1000; i != 1000; ++i)
        {
            numbers.push_back(i);
            iom.push_front(std::make_pair<int, string_t>(i, "i"));
        }}

        std::random_shuffle(numbers.begin(), numbers.end());

        { for(int i = 0; !numbers.empty(); ++i)
        {
            iom.erase(numbers.front());
            numbers.erase(numbers.begin());

            STLSOFT_SUPPRESS_UNUSED(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
    }
}

static void test_ios_erase_4()
{
    {
        stlsoft::insert_ordered_map<int, string_t> iom;

        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

        iom.push_back(std::make_pair<int, string_t>(-1, "-1"));
        iom.push_back(std::make_pair<int, string_t>(-2, "-2"));
        iom.push_back(std::make_pair<int, string_t>(-3, "-3"));
        iom.push_back(std::make_pair<int, string_t>(-4, "-4"));
        iom.push_back(std::make_pair<int, string_t>(-5, "-5"));
        iom.push_back(std::make_pair<int, string_t>(-6, "-6"));
        iom.push_back(std::make_pair<int, string_t>(-7, "-7"));
        iom.push_back(std::make_pair<int, string_t>(-8, "-8"));
        iom.push_back(std::make_pair<int, string_t>(-9, "-9"));
        iom.push_front(std::make_pair<int, string_t>(0, "0"));

        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(10u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(0, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        stlsoft::insert_ordered_map<int, string_t>::const_iterator it = iom.erase(iom.begin());

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-1, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(9u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-2, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(8u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-2, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-3, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(7u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-3, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-4, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(6u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-4, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-5, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(5u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-5, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-6, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(4u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-6, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-7, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-7, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-8, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(2u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-8, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() != it);
        XTESTS_TEST_INTEGER_EQUAL(-9, (*it).first);
        XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(1u, iom.size());
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.front().first);
        XTESTS_TEST_INTEGER_EQUAL(-9, iom.back().first);

        it = iom.erase(it);

        XTESTS_TEST_BOOLEAN_TRUE(iom.end() == it);
        XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
    }
}

static void test_ios_clear_1()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
    XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

    iom.clear();

    XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
    XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
}

static void test_ios_clear_2()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
    XTESTS_TEST_BOOLEAN_TRUE(iom.empty());

    iom.push_back(std::make_pair<int, string_t>(-1, "-1"));
    iom.push_back(std::make_pair<int, string_t>(-2, "-2"));
    iom.push_back(std::make_pair<int, string_t>(-3, "-3"));
    iom.push_back(std::make_pair<int, string_t>(-4, "-4"));
    iom.push_back(std::make_pair<int, string_t>(-5, "-5"));
    iom.push_back(std::make_pair<int, string_t>(-6, "-6"));
    iom.push_back(std::make_pair<int, string_t>(-7, "-7"));

    iom.clear();

    XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());
    XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
}

static void test_push_front_bulk()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    { for(int i = -1000; i != 1000; ++i)
    {
        iom.push_front(std::make_pair<int, string_t>(i, "i"));
    }}

    XTESTS_TEST_INTEGER_EQUAL(2000u, iom.size());

    { for(int i = -1000; i != 1000; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(i, (*iom.find(i)).first);
    }}
}

static void test_1_09()
{
    stlsoft::insert_ordered_map<int, string_t>    iom;

    XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());

    iom.push_back(std::make_pair<int, string_t>(0, "0"));
    iom.push_back(std::make_pair<int, string_t>(2, "2"));
    iom.push_back(std::make_pair<int, string_t>(3, "3"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(0, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(3, iom.back().first);

    stlsoft::insert_ordered_map<int, string_t>::const_iterator i = iom.find(2);

    iom.insert(i, std::make_pair<int, string_t>(1, "1"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(4u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(0, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(3, iom.back().first);

    iom.insert(iom.end(), std::make_pair<int, string_t>(4, "4"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(0, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(4, iom.back().first);

    iom.insert(iom.begin(), std::make_pair<int, string_t>(-1, "-1"));

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(6u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(-1, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(4, iom.back().first);
}

static void test_1_10()
{
    std::map<int, string_t> d;

    stlsoft::literal_copy(
        std::make_pair<int, string_t>(10, "10")
    ,   std::make_pair<int, string_t>(2, "2")
    ,   std::make_pair<int, string_t>(0, "0")
    ,   std::make_pair<int, string_t>(-5, "-5")
    ,   std::make_pair<int, string_t>(-2000, "-2000")
    ,   std::inserter(d, d.end())
    );

    stlsoft::insert_ordered_map<int, string_t>    iom;

    XTESTS_TEST_BOOLEAN_TRUE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, iom.size());

#if 0
    iom.insert(d.begin(), d.end());

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(10, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(-2000, iom.back().first);
    XTESTS_TEST_INTEGER_EQUAL(-1993, std::accumulate(iom.begin(), iom.end(), 0));
#endif /* 0 */
}

static void test_1_11()
{
    std::deque<int> d;

    stlsoft::literal_copy(10, 2, 0, -5, -2000, std::back_inserter(d));

#if 0
    stlsoft::insert_ordered_map<int, string_t>    iom(d.begin(), d.end());

    XTESTS_TEST_BOOLEAN_FALSE(iom.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, iom.size());
    XTESTS_TEST_INTEGER_EQUAL(10, iom.front().first);
    XTESTS_TEST_INTEGER_EQUAL(-2000, iom.back().first);
    XTESTS_TEST_INTEGER_EQUAL(-1993, std::accumulate(iom.begin(), iom.end(), 0));
#endif /* 0 */
}

static void test_1_12()
{
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
#ifndef _DEBUG
#endif /* !_DEBUG */
