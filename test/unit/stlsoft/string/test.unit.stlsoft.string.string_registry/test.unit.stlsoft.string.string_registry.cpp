/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.string_registry.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.string_registry project.
 *
 * Created:     19th February 2010
 * Updated:     5th March 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/string/string_registry.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

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

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2(void);
    static void test_1_3(void);
    static void test_1_4(void);
    static void test_1_5(void);
    static void test_1_6(void);
    static void test_1_7(void);
    static void test_1_8(void);
    static void test_1_9(void);
    static void test_1_10(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

#if 0
    std::map<int, int>              m;
    std::map<int, int>::iterator    it1;
    std::map<int, int>::iterator    it2;
    std::map<int, int>::iterator    it3;
    std::map<int, int>::iterator    it;

    it1 = m.insert(std::make_pair(1, 1)).first;

    int const*      pk1 =   &(*it1).first;
    int const*      pm1 =   &(*it1).second;

    it2 = m.insert(std::make_pair(2, 2)).first;

    int const*      pk2 =   &(*it2).first;
    int const*      pm2 =   &(*it2).second;

    it3 = m.insert(std::make_pair(3, 3)).first;

    int const*      pk3 =   &(*it3).first;
    int const*      pm3 =   &(*it3).second;

    m.erase(2);
    it = m.find(1);

    int const*      pk  =   &(*it).first;
    int const*      pm  =   &(*it).second;

    STLSOFT_ASSERT(pk == pk1);
    STLSOFT_ASSERT(pm == pm1);

    m.erase(3);
    it = m.find(1);

    pk  =   &(*it).first;
    pm  =   &(*it).second;

    STLSOFT_ASSERT(pk == pk1);
    STLSOFT_ASSERT(pm == pm1);
#endif /* 0 */


    if(XTESTS_START_RUNNER("test.unit.stlsoft.string.string_registry", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);

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

#if 0
    static char const       alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    static wchar_t const    walphabet[] = L"abcdefghijklmnopqrstuvwxyz";
#endif /* 0 */

    typedef std::basic_string<char>         string_t;


static void test_1_0()
{
    stlsoft::string_registry    registry;

    STLSOFT_SUPPRESS_UNUSED(registry);

    XTESTS_TEST_PASSED();
}

static void test_1_1()
{
    stlsoft::string_registry    registry;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
}

static void test_1_2()
{
    stlsoft::string_registry    registry;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());
}

static void test_1_3()
{
    stlsoft::string_registry    registry;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());

    registry.add("abc");

    XTESTS_TEST_BOOLEAN_TRUE(!registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());

    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
}

static void test_1_4()
{
    stlsoft::string_registry                    registry;
    stlsoft::string_registry::slice_type const* slice;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());

    registry.add("abc", &slice);

    XTESTS_TEST_BOOLEAN_TRUE(!registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());

    XTESTS_TEST_INTEGER_EQUAL(3u, slice->len);

    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
}

static void test_1_5()
{
    static char const alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    static char const ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    stlsoft::string_registry    registry;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());

    { for(size_t j = 0; j != 100; ++j)
    {
        { for(size_t i = 0; i != 27; ++i)
        {
            string_t s(alphabet, i);

            registry.add(s);
        }}
    }}

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(27u, registry.size());

    { for(size_t i = 0; i != 27; ++i)
    {
        string_t s(alphabet, i);
        string_t S(ALPHABET, i);

        XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered(s));
        if(0 != i)
        {
            XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered(S));
        }
    }}

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(27u, registry.size());

    { for(size_t j = 0; j != 100; ++j)
    {
        { for(size_t i = 0; i != 27; ++i)
        {
            string_t const                              s(alphabet, i);
            stlsoft::string_registry::slice_type const* slice = NULL;

            XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered(s, &slice)));
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, slice->ptr);

            XTESTS_TEST_INTEGER_EQUAL(100u - (1u + j), registry.remove(slice));
        }}
    }}

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());
}

static void test_1_6()
{
    stlsoft::string_registry    registry;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());

    registry.add("abc");
    registry.add("def");
    registry.add("ghi");
    registry.add("abc");
    registry.add("def");
    registry.add("abc");

    XTESTS_TEST_BOOLEAN_TRUE(!registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, registry.size());

    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("def"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("ghi"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("jkl"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("ab"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("de"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("gh"));
}

static void test_1_7()
{
}

static void test_1_8()
{
    stlsoft::string_registry                    registry;
    stlsoft::string_registry::slice_type const* slice1;
    stlsoft::string_registry::slice_type const* slice2;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());

    registry.add("abc", &slice1);

    XTESTS_TEST_BOOLEAN_TRUE(!registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());

    registry.add("abc", &slice2);

    XTESTS_TEST_BOOLEAN_TRUE(!registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());

    XTESTS_TEST_INTEGER_EQUAL(3u, slice1->len);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("abc", slice2->ptr, 3u);
    XTESTS_TEST_INTEGER_EQUAL(slice1->len, slice2->len);
    XTESTS_TEST_POINTER_EQUAL(slice1->ptr, slice2->ptr);

    registry.remove(slice2);

    XTESTS_TEST_BOOLEAN_TRUE(!registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());

    registry.remove(slice1);

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());
}

static void test_1_9()
{
    stlsoft::string_registry                    registry;
    stlsoft::string_registry::slice_type const* slice;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));

    registry.add("abc", &slice);

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));

    registry.add("abc");
    registry.add("def");

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("def"));

    XTESTS_TEST_INTEGER_EQUAL(1u, registry.remove_below_count(2u));

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));

    registry.remove(slice);

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));

    XTESTS_TEST_INTEGER_EQUAL(1u, registry.remove_below_count(2u));

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));
}

static void test_1_10()
{
    stlsoft::string_registry                    registry;
    stlsoft::string_registry::slice_type const* slice;
    stlsoft::string_registry::slice_type const* slice2;

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));

    registry.add("abc", &slice);

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));

    registry.add("abc");
    registry.add("def");

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("def"));

    registry.add("abc");
    registry.add("ghi");

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("def"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("ghi"));

    registry.add("ghi", &slice2);

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("def"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("ghi"));

    XTESTS_TEST_INTEGER_EQUAL(1u, registry.remove_below_count(2u));

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("ghi"));

    registry.remove(slice);

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("ghi"));

    registry.remove(slice);

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, registry.size());
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("ghi"));

    XTESTS_TEST_INTEGER_EQUAL(1u, registry.remove_below_count(2u));

    XTESTS_TEST_BOOLEAN_FALSE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, registry.size());
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));
    XTESTS_TEST_BOOLEAN_TRUE(registry.is_registered("ghi"));

    registry.remove(slice2);
    registry.remove(slice2);

    XTESTS_TEST_BOOLEAN_TRUE(registry.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, registry.size());
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("abc"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("def"));
    XTESTS_TEST_BOOLEAN_FALSE(registry.is_registered("ghi"));
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
