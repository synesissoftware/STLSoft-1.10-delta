/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.container.partially_initialised_array.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.container.partially_initialised_array project.
 *
 * Created:     23rd May 2010
 * Updated:     18th June 2010
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

#include <stlsoft/container/partially_initialised_array.hpp>

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

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_00(void);
    static void test_1_01(void);
    static void test_1_02(void);
    static void test_1_03(void);
    static void test_1_04(void);
    static void test_1_05(void);
    static void test_1_06(void);
    static void test_1_07(void);
    static void test_1_08(void);
    static void test_1_09(void);
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.container.partially_initialised_array", verbosity))
    {
        XTESTS_RUN_CASE(test_1_00);
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);
        XTESTS_RUN_CASE(test_1_06);
        XTESTS_RUN_CASE(test_1_07);
        XTESTS_RUN_CASE(test_1_08);
        XTESTS_RUN_CASE(test_1_09);
        XTESTS_RUN_CASE(test_1_10);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/partially_initialised_array.hpp", NULL);
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

static void test_1_00()
{
    stlsoft::partially_initialised_array<int, 10>       array(0u, 0);

    XTESTS_TEST_INTEGER_EQUAL(10u, array.size());
}

static void test_1_01()
{
    stlsoft::partially_initialised_array<int, 10>       array(0u, 1);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(10u, array.size()));
}

static void test_1_02()
{
    stlsoft::partially_initialised_array<int, 10>       array(1u, 1);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(10u, array.size()));
    XTESTS_TEST_INTEGER_EQUAL(1, array[0]);
}

static void test_1_03()
{
    stlsoft::partially_initialised_array<int, 10>       array(10u, -1);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(10u, array.size()));
    XTESTS_TEST_INTEGER_EQUAL(-1, array[0]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[2]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[3]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[4]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[5]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[6]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[7]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[8]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[9]);
}

static void test_1_04()
{
    stlsoft::partially_initialised_array<int, 10>       array(5u, -1);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(10u, array.size()));
    XTESTS_TEST_INTEGER_EQUAL(-1, array[0]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[1]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[2]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[3]);
    XTESTS_TEST_INTEGER_EQUAL(-1, array[4]);
}

static void test_1_05()
{
}

static void test_1_06()
{
}

static void test_1_07()
{
}

static void test_1_08()
{
}

static void test_1_09()
{
}

static void test_1_10()
{
}




} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
