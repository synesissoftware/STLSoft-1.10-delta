/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.util.bit_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.util.bit_functions project.
 *
 * Created:     19th March 2010
 * Updated:     2nd June 2010
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

#include <stlsoft/util/bit_functions.h>

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
#include <platformstl/performance/performance_counter.hpp>

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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.util.bit_functions", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/bit_functions.h", NULL);
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
    using stlsoft::sint8_t;
    using stlsoft::uint8_t;
    using stlsoft::sint16_t;
    using stlsoft::uint16_t;
    using stlsoft::sint32_t;
    using stlsoft::uint32_t;
    using stlsoft::sint64_t;
    using stlsoft::uint64_t;

    using platformstl::performance_counter;

static void test_1_0()
{
    performance_counter counter;

    counter.start();

    XTESTS_TEST_INTEGER_EQUAL(0u,  stlsoft::count_bits_Kernighan(uint32_t(0)));
    XTESTS_TEST_INTEGER_EQUAL(0u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000000)));

    XTESTS_TEST_INTEGER_EQUAL(32u, stlsoft::count_bits_Kernighan(uint32_t(0xffffffff)));

    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_Kernighan(uint32_t(0x33333333)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_Kernighan(uint32_t(0x55555555)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_Kernighan(uint32_t(0x66666666)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_Kernighan(uint32_t(0x99999999)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_Kernighan(uint32_t(0xaaaaaaaa)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_Kernighan(uint32_t(0xcccccccc)));

    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_Kernighan(uint32_t(0x000000ff)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_Kernighan(uint32_t(0x0000ff00)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_Kernighan(uint32_t(0x00ff0000)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_Kernighan(uint32_t(0xff000000)));

    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000001)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000010)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000100)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00001000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00010000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00100000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x01000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x10000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000002)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000020)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000200)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00002000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00020000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00200000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x02000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x20000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000002)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000020)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00000200)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00002000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00020000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x00200000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x02000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_Kernighan(uint32_t(0x20000000)));

    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_Kernighan(uint32_t(0x00001001)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_Kernighan(uint32_t(0x00001010)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_Kernighan(uint32_t(0x00001100)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_Kernighan(uint32_t(0x01001000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_Kernighan(uint32_t(0x00011000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_Kernighan(uint32_t(0x00101000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_Kernighan(uint32_t(0x01001000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_Kernighan(uint32_t(0x10001000)));

    counter.stop();

    fprintf(stdout, "t: %luus\n", static_cast<unsigned long>(counter.get_microseconds()));
}

static void test_1_1()
{
    performance_counter counter;

    counter.start();

    XTESTS_TEST_INTEGER_EQUAL(0u,  stlsoft::count_bits_8bit_table(uint32_t(0)));
    XTESTS_TEST_INTEGER_EQUAL(0u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000000)));

    XTESTS_TEST_INTEGER_EQUAL(32u, stlsoft::count_bits_8bit_table(uint32_t(0xffffffff)));

    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_8bit_table(uint32_t(0x33333333)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_8bit_table(uint32_t(0x55555555)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_8bit_table(uint32_t(0x66666666)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_8bit_table(uint32_t(0x99999999)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_8bit_table(uint32_t(0xaaaaaaaa)));
    XTESTS_TEST_INTEGER_EQUAL(16u, stlsoft::count_bits_8bit_table(uint32_t(0xcccccccc)));

    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_8bit_table(uint32_t(0x000000ff)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_8bit_table(uint32_t(0x0000ff00)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_8bit_table(uint32_t(0x00ff0000)));
    XTESTS_TEST_INTEGER_EQUAL(8u,  stlsoft::count_bits_8bit_table(uint32_t(0xff000000)));

    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000001)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000010)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000100)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00001000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00010000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00100000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x01000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x10000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000002)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000020)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000200)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00002000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00020000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00200000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x02000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x20000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000002)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000020)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00000200)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00002000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00020000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x00200000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x02000000)));
    XTESTS_TEST_INTEGER_EQUAL(1u,  stlsoft::count_bits_8bit_table(uint32_t(0x20000000)));

    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_8bit_table(uint32_t(0x00001001)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_8bit_table(uint32_t(0x00001010)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_8bit_table(uint32_t(0x00001100)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_8bit_table(uint32_t(0x01001000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_8bit_table(uint32_t(0x00011000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_8bit_table(uint32_t(0x00101000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_8bit_table(uint32_t(0x01001000)));
    XTESTS_TEST_INTEGER_EQUAL(2u,  stlsoft::count_bits_8bit_table(uint32_t(0x10001000)));

    counter.stop();

    fprintf(stdout, "t: %luus\n", static_cast<unsigned long>(counter.get_microseconds()));
}

static void test_1_2()
{
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



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
