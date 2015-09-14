/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.functional.bit_operations.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.functional.bit_operations project.
 *
 * Created:     19th March 2010
 * Updated:     9th June 2010
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

#include <stlsoft/functional/bit_operations.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.functional.bit_operations", verbosity))
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

    using stlsoft::sint8_t;
    using stlsoft::uint8_t;
    using stlsoft::sint16_t;
    using stlsoft::uint16_t;
    using stlsoft::sint32_t;
    using stlsoft::uint32_t;
    using stlsoft::sint64_t;
    using stlsoft::uint64_t;

static void test_1_0()
{
    stlsoft::and_with<uint32_t> f;

    XTESTS_TEST_INTEGER_EQUAL(0u, f(0u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0u, f(1u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0u, f(0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(1u, f(1u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(1u, f(1u, ~0u));
    XTESTS_TEST_INTEGER_EQUAL(1u, f(~0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(~0u, f(~0u, ~0u));
    XTESTS_TEST_INTEGER_EQUAL(0x00000000u, f(0x00000001, 0x00000000));
    XTESTS_TEST_INTEGER_EQUAL(0x00000000u, f(0x00000000, 0x00000001));

    XTESTS_TEST_INTEGER_EQUAL(0x00000000u, f(0x10101010, 0x01010101));
    XTESTS_TEST_INTEGER_EQUAL(0x10101010u, f(0x10101010, 0x10101010));
}

static void test_1_1()
{
    stlsoft::or_with<uint32_t>  f;

    XTESTS_TEST_INTEGER_EQUAL(0u, f(0u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(1u, f(1u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(1u, f(0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(1u, f(1u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(~0u, f(1u, ~0u));
    XTESTS_TEST_INTEGER_EQUAL(~0u, f(~0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(~0u, f(~0u, ~0u));
    XTESTS_TEST_INTEGER_EQUAL(0x00000001u, f(0x00000001, 0x00000000));
    XTESTS_TEST_INTEGER_EQUAL(0x00000001u, f(0x00000000, 0x00000001));

    XTESTS_TEST_INTEGER_EQUAL(0x11111111u, f(0x10101010, 0x01010101));
    XTESTS_TEST_INTEGER_EQUAL(0x10101010u, f(0x10101010, 0x10101010));
}

static void test_1_2()
{
    stlsoft::xor_with<uint32_t> f;

    XTESTS_TEST_INTEGER_EQUAL(0u, f(0u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(1u, f(1u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(1u, f(0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0u, f(1u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(~0u - 1u, f(1u, ~0u));
    XTESTS_TEST_INTEGER_EQUAL(~0u - 1u, f(~0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0u, f(~0u, ~0u));
    XTESTS_TEST_INTEGER_EQUAL(0x00000001u, f(0x00000001, 0x00000000));
    XTESTS_TEST_INTEGER_EQUAL(0x00000001u, f(0x00000000, 0x00000001));

    XTESTS_TEST_INTEGER_EQUAL(0x11111111u, f(0x10101010, 0x01010101));
    XTESTS_TEST_INTEGER_EQUAL(0x00000000u, f(0x10101010, 0x10101010));
}

static void test_1_3()
{
}

static void test_1_4()
{
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
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
