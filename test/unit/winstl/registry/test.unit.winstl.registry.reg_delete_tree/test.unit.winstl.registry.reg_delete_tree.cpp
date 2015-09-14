/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.registry.reg_delete_tree.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.registry.reg_delete_tree project.
 *
 * Created:     13th May 2009
 * Updated:     12th August 2010
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

#include <winstl/registry/reg_traits.hpp>

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
#include <winstl/registry/reg_key.hpp>
#include <winstl/synch/process_mutex.hpp>
#include <winstl/synch/semaphore.hpp>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

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

    if(XTESTS_START_RUNNER("test.unit.winstl.registry.reg_delete_tree", verbosity))
    {
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

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/reg_traits.hpp", NULL);
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
    typedef winstl::reg_traits<char>    traits_m_t;
    typedef winstl::reg_traits<wchar_t> traits_w_t;


static void test_1_4()
{
    XTESTS_TEST_INTEGER_EQUAL(ERROR_INVALID_HANDLE, traits_m_t::reg_delete_tree(NULL, NULL));
}

static void test_1_5()
{
    winstl::reg_key::create_key(HKEY_CURRENT_USER, "test\\abc\\def\\ghi\\jkl\\mno");
    winstl::reg_key::create_key(HKEY_CURRENT_USER, "test\\abc\\def\\pqr\\stu\\vwx");

    XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, traits_m_t::reg_delete_tree(HKEY_CURRENT_USER, "test\\abc\\def"));
}

static void test_1_6()
{
    XTESTS_TEST_INTEGER_EQUAL(ERROR_INVALID_HANDLE, traits_w_t::reg_delete_tree(NULL, NULL));
}

static void test_1_7()
{
    winstl::reg_key::create_key(HKEY_CURRENT_USER, "test\\abc\\def\\ghi\\jkl\\mno");
    winstl::reg_key::create_key(HKEY_CURRENT_USER, "test\\abc\\def\\pqr\\stu\\vwx");

#ifndef __BORLANDC__
    XTESTS_TEST_INTEGER_EQUAL(ERROR_SUCCESS, traits_w_t::reg_delete_tree(HKEY_CURRENT_USER, L"test\\abc\\def"));
#endif /* compiler */
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
