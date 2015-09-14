/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.algorithm.literal_copy.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.algorithm.literal_copy project.
 *
 * Created:     17th March 2010
 * Updated:     18th March 2010
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

#include <stlsoft/algorithm/literal_copy.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <iterator>
#include <vector>

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
    static void test_1_11(void);
    static void test_1_12(void);
    static void test_1_13(void);
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.algorithm.literal_copy", verbosity))
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
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

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

static void test_1_0()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
}

static void test_1_1()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
}

static void test_1_2()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, -1, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, ints[2]);
}

static void test_1_3()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, -1, 99, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, ints[2]);
    XTESTS_TEST_INTEGER_EQUAL(99, ints[3]);
}

static void test_1_4()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, -1, 99, 303, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(5u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, ints[2]);
    XTESTS_TEST_INTEGER_EQUAL(99, ints[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, ints[4]);
}

static void test_1_5()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, -1, 99, 303, 71717, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(6u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, ints[2]);
    XTESTS_TEST_INTEGER_EQUAL(99, ints[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, ints[4]);
    XTESTS_TEST_INTEGER_EQUAL(71717, ints[5]);
}

static void test_1_6()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, -1, 99, 303, 71717, -88, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(7u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, ints[2]);
    XTESTS_TEST_INTEGER_EQUAL(99, ints[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, ints[4]);
    XTESTS_TEST_INTEGER_EQUAL(71717, ints[5]);
    XTESTS_TEST_INTEGER_EQUAL(-88, ints[6]);
}

static void test_1_7()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, -1, 99, 303, 71717, -88, 2, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(8u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, ints[2]);
    XTESTS_TEST_INTEGER_EQUAL(99, ints[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, ints[4]);
    XTESTS_TEST_INTEGER_EQUAL(71717, ints[5]);
    XTESTS_TEST_INTEGER_EQUAL(-88, ints[6]);
    XTESTS_TEST_INTEGER_EQUAL(2, ints[7]);
}

static void test_1_8()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, -1, 99, 303, 71717, -88, 2, 13, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(9u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, ints[2]);
    XTESTS_TEST_INTEGER_EQUAL(99, ints[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, ints[4]);
    XTESTS_TEST_INTEGER_EQUAL(71717, ints[5]);
    XTESTS_TEST_INTEGER_EQUAL(-88, ints[6]);
    XTESTS_TEST_INTEGER_EQUAL(2, ints[7]);
    XTESTS_TEST_INTEGER_EQUAL(13, ints[8]);
}

static void test_1_9()
{
    std::vector<int>        ints;

    stlsoft::literal_copy(0, 1, -1, 99, 303, 71717, -88, 2, 13, -2, std::back_inserter(ints));

    XTESTS_TEST_BOOLEAN_FALSE(ints.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(10u, ints.size()));
    XTESTS_TEST_INTEGER_EQUAL(0, ints[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, ints[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, ints[2]);
    XTESTS_TEST_INTEGER_EQUAL(99, ints[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, ints[4]);
    XTESTS_TEST_INTEGER_EQUAL(71717, ints[5]);
    XTESTS_TEST_INTEGER_EQUAL(-88, ints[6]);
    XTESTS_TEST_INTEGER_EQUAL(2, ints[7]);
    XTESTS_TEST_INTEGER_EQUAL(13, ints[8]);
    XTESTS_TEST_INTEGER_EQUAL(-2, ints[9]);
}

static void test_1_10()
{
}

static void test_1_11()
{
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
