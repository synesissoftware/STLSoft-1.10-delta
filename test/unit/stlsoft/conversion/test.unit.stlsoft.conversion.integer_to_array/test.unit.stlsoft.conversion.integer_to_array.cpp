/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.conversion.integer_to_array.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.conversion.integer_to_array project.
 *
 * Created:     13th May 2009
 * Updated:     13th May 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/conversion/integer_to_array.hpp>

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

    static void test_specialisations(void);
    static void test_split_on_256(void);
    static void test_split_on_64(void);
    static void test_split_on_32(void);
    static void test_split_on_16(void);
    static void test_split_on_8(void);
    static void test_split_on_4(void);
    static void test_split_on_2(void);
    static void test_split_on_1(void);
    static void test_split_on_5(void);
    static void test_split_on_7(void);
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.conversion.integer_to_array", verbosity))
    {
        XTESTS_RUN_CASE(test_specialisations);
        XTESTS_RUN_CASE(test_split_on_256);
        XTESTS_RUN_CASE(test_split_on_64);
        XTESTS_RUN_CASE(test_split_on_32);
        XTESTS_RUN_CASE(test_split_on_16);
        XTESTS_RUN_CASE(test_split_on_8);
        XTESTS_RUN_CASE(test_split_on_4);
        XTESTS_RUN_CASE(test_split_on_2);
        XTESTS_RUN_CASE(test_split_on_1);
        XTESTS_RUN_CASE(test_split_on_5);
        XTESTS_RUN_CASE(test_split_on_7);
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

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/integer_to_array.hpp", NULL);
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
    stlsoft::sint8_t    si8     =   static_cast<stlsoft::sint8_t>(0x3c);        //                            00111100
    stlsoft::uint8_t    ui8     =   static_cast<stlsoft::uint8_t>(0x3c);        //                            00111100
    stlsoft::sint16_t   si16    =   static_cast<stlsoft::sint16_t>(0x5a3c);     //                   01011010 00111100
    stlsoft::uint16_t   ui16    =   static_cast<stlsoft::uint16_t>(0x5a3c);     //                   01011010 00111100
    stlsoft::sint32_t   si32    =   static_cast<stlsoft::sint32_t>(0x7f000001); // 01111111 00000000 00000000 00000001
    stlsoft::uint32_t   ui32    =   static_cast<stlsoft::uint32_t>(0x7f000001); // 01111111 00000000 00000000 00000001

static void test_specialisations()
{
    stlsoft::integer_to_array(si8, 1);
    stlsoft::integer_to_array(si8, 4);
    stlsoft::integer_to_array(si8, 8);

    stlsoft::integer_to_array(ui8, 1);
    stlsoft::integer_to_array(ui8, 4);
    stlsoft::integer_to_array(ui8, 8);

    stlsoft::integer_to_array(si16, 1);
    stlsoft::integer_to_array(si16, 4);
    stlsoft::integer_to_array(si16, 8);
    stlsoft::integer_to_array(si16, 16);

    stlsoft::integer_to_array(ui16, 1);
    stlsoft::integer_to_array(ui16, 4);
    stlsoft::integer_to_array(ui16, 8);
    stlsoft::integer_to_array(ui16, 16);

    XTESTS_TEST_PASSED();
}

static void test_split_on_256()
{
    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 256);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x00005a3c, r[0]);
    }

    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(ui32, 256);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x7f000001, r[0]);
    }
}

static void test_split_on_64()
{
    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 64);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x00005a3c, r[0]);
    }

    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(ui32, 64);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x7f000001, r[0]);
    }
}

static void test_split_on_32()
{
    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 32);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x00005a3c, r[0]);
    }

    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(ui32, 32);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x7f000001, r[0]);
    }
}

static void test_split_on_16()
{
    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 16);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x5a3c, r[0]);
    }

    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(ui32, 16);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x0001, r[0]);
        XTESTS_TEST_INTEGER_EQUAL(0x7f00, r[1]);
    }
}

static void test_split_on_8()
{
    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 8);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x3c, r[0]);
        XTESTS_TEST_INTEGER_EQUAL(0x5a, r[1]);
    }

    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(ui32, 8);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(1, r[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, r[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, r[2]);
        XTESTS_TEST_INTEGER_EQUAL(127, r[3]);
    }
}

static void test_split_on_4()
{
    stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 4);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, r.size()));

    XTESTS_TEST_INTEGER_EQUAL(0xc, r[0]);
    XTESTS_TEST_INTEGER_EQUAL(0x3, r[1]);
    XTESTS_TEST_INTEGER_EQUAL(0xa, r[2]);
    XTESTS_TEST_INTEGER_EQUAL(0x5, r[3]);
}

static void test_split_on_2()
{
    stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 2);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(8u, r.size()));

    XTESTS_TEST_INTEGER_EQUAL(0x0, r[0]);
    XTESTS_TEST_INTEGER_EQUAL(0x3, r[1]);
    XTESTS_TEST_INTEGER_EQUAL(0x3, r[2]);
    XTESTS_TEST_INTEGER_EQUAL(0x0, r[3]);
    XTESTS_TEST_INTEGER_EQUAL(0x2, r[4]);
    XTESTS_TEST_INTEGER_EQUAL(0x2, r[5]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[6]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[7]);
}

static void test_split_on_1()
{
    stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 1);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(16u, r.size()));

    XTESTS_TEST_INTEGER_EQUAL(0x0, r[0]);
    XTESTS_TEST_INTEGER_EQUAL(0x0, r[1]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[2]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[3]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[4]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[5]);
    XTESTS_TEST_INTEGER_EQUAL(0x0, r[6]);
    XTESTS_TEST_INTEGER_EQUAL(0x0, r[7]);
    XTESTS_TEST_INTEGER_EQUAL(0x0, r[8]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[9]);
    XTESTS_TEST_INTEGER_EQUAL(0x0, r[10]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[11]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[12]);
    XTESTS_TEST_INTEGER_EQUAL(0x0, r[13]);
    XTESTS_TEST_INTEGER_EQUAL(0x1, r[14]);
    XTESTS_TEST_INTEGER_EQUAL(0x0, r[15]);
}

static void test_split_on_5()
{
    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 5);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(4u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x1c, r[0]);
        XTESTS_TEST_INTEGER_EQUAL(0x11, r[1]);
        XTESTS_TEST_INTEGER_EQUAL(0x16, r[2]);
        XTESTS_TEST_INTEGER_EQUAL(0x00, r[3]);
    }

    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(ui32, 5);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(7u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x01, r[0]);
        XTESTS_TEST_INTEGER_EQUAL(0x00, r[1]);
        XTESTS_TEST_INTEGER_EQUAL(0x00, r[2]);
        XTESTS_TEST_INTEGER_EQUAL(0x00, r[3]);
        XTESTS_TEST_INTEGER_EQUAL(0x10, r[4]);
        XTESTS_TEST_INTEGER_EQUAL(0x1f, r[5]);
        XTESTS_TEST_INTEGER_EQUAL(0x01, r[6]);
    }
}

static void test_split_on_7()
{
    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(si16, 7);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x3c, r[0]);
        XTESTS_TEST_INTEGER_EQUAL(0x34, r[1]);
        XTESTS_TEST_INTEGER_EQUAL(0x01, r[2]);
    }

    {
        stlsoft::integer_array  r = stlsoft::integer_to_array(ui32, 7);

        XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(5u, r.size()));

        XTESTS_TEST_INTEGER_EQUAL(0x01, r[0]);
        XTESTS_TEST_INTEGER_EQUAL(0x00, r[1]);
        XTESTS_TEST_INTEGER_EQUAL(0x00, r[2]);
        XTESTS_TEST_INTEGER_EQUAL(0x78, r[3]);
        XTESTS_TEST_INTEGER_EQUAL(0x07, r[4]);
    }
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
