/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.util.has_bom.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.util.has_bom project.
 *
 * Created:     19th March 2010
 * Updated:     19th March 2010
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

#include <stlsoft/util/has_bom.hpp>

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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.util.has_bom", verbosity))
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
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/has_bom.hpp", NULL);
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
    using stlsoft::byte_t;

static void test_1_0()
{
    byte_t          bytes[1];
    byte_t const*   from    =   bytes;
    byte_t const*   to      =   bytes;

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::has_bom(0x00, 0x00, 0xfe, 0xff, from, to));
}

static void test_1_1()
{
    byte_t          bytes[] =   { 0x00 };
    byte_t const*   from    =   bytes;
    byte_t const*   to      =   bytes + sizeof(bytes);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::has_bom(0x00, 0x00, 0xfe, 0xff, from, to));
}

static void test_1_2()
{
    byte_t          bytes[] =   { 0x00, 0x00 };
    byte_t const*   from    =   bytes;
    byte_t const*   to      =   bytes + sizeof(bytes);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::has_bom(0x00, 0x00, 0xfe, 0xff, from, to));
}

static void test_1_3()
{
    byte_t          bytes[] =   { 0x00, 0x00, 0xfe };
    byte_t const*   from    =   bytes;
    byte_t const*   to      =   bytes + sizeof(bytes);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::has_bom(0x00, 0x00, 0xfe, 0xff, from, to));
}

static void test_1_4()
{
    byte_t          bytes[] =   { 0x00, 0x00, 0xfe, 0xff };
    byte_t const*   from    =   bytes;
    byte_t const*   to      =   bytes + sizeof(bytes);

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::has_bom(0x00, 0x00, 0xfe, 0xff, from, to));
}

static void test_1_5()
{
    byte_t          bytes[] =   { 0x00, 0x00, 0xfe, 0xff, 0x00 };
    byte_t const*   from    =   bytes;
    byte_t const*   to      =   bytes + sizeof(bytes);

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::has_bom(0x00, 0x00, 0xfe, 0xff, from, to));
}

static void test_1_6()
{
}

static void test_1_7()
{
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
