/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.conversion.string_to_bool.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.conversion.string_to_bool project.
 *
 * Created:     6th September 2014
 * Updated:     6th September 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define STLSOFT_MINIMUM_SAS_INCLUDES
#include <stlsoft/conversion/string_to_bool.hpp>

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

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 */

#ifdef STLSOFT_COMPILER_IS_BORLAND
# undef NULL
# define NULL   0
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_0(void);
    static void test_1(void);
    static void test_2(void);
    static void test_3(void);
    static void test_4(void);
    static void test_5(void);
    static void test_6(void);
    static void test_7(void);
    static void test_8(void);
    static void test_9(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.conversion.string_to_bool", verbosity))
    {
        XTESTS_RUN_CASE(test_0);
        XTESTS_RUN_CASE(test_1);
        XTESTS_RUN_CASE(test_2);
        XTESTS_RUN_CASE(test_3);
        XTESTS_RUN_CASE(test_4);
        XTESTS_RUN_CASE(test_5);
        XTESTS_RUN_CASE(test_6);
        XTESTS_RUN_CASE(test_7);
        XTESTS_RUN_CASE(test_8);
        XTESTS_RUN_CASE(test_9);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/string_to_bool.hpp", NULL);
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
    using stlsoft::uint64_t;


static void test_0()
{
    bool    b;

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to_bool("true", &b));
    XTESTS_TEST_BOOLEAN_TRUE(b);

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to_bool("false", &b));
    XTESTS_TEST_BOOLEAN_FALSE(b);

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to_bool(L"true", &b));
    XTESTS_TEST_BOOLEAN_TRUE(b);

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to_bool(L"false", &b));
    XTESTS_TEST_BOOLEAN_FALSE(b);
}

static void test_1()
{
    bool    b;

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to_bool("yellow", &b));
    XTESTS_TEST_BOOLEAN_FALSE(b);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to_bool("blue", &b));
    XTESTS_TEST_BOOLEAN_FALSE(b);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to_bool(L"yellow", &b));
    XTESTS_TEST_BOOLEAN_FALSE(b);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::try_parse_to_bool(L"blue", &b));
    XTESTS_TEST_BOOLEAN_FALSE(b);
}

static void test_2()
{
    bool            b;
    char const*     ep_a;
    wchar_t const*  ep_w;

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to_bool("trueish", &b, &ep_a));
    XTESTS_TEST_BOOLEAN_TRUE(b);
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ep_a);
    XTESTS_TEST_CHARACTER_EQUAL('i', *ep_a);

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to_bool("falseish", &b, &ep_a));
    XTESTS_TEST_BOOLEAN_FALSE(b);
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ep_a);
    XTESTS_TEST_CHARACTER_EQUAL('i', *ep_a);

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to_bool(L"trueish", &b, &ep_w));
    XTESTS_TEST_BOOLEAN_TRUE(b);
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ep_w);
    XTESTS_TEST_CHARACTER_EQUAL(L'i', *ep_w);

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::try_parse_to_bool(L"falseish", &b, &ep_w));
    XTESTS_TEST_BOOLEAN_FALSE(b);
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ep_w);
    XTESTS_TEST_CHARACTER_EQUAL(L'i', *ep_w);
}

static void test_3()
{
}

static void test_4()
{
}

static void test_5()
{
}

static void test_6()
{
}

static void test_7()
{
}

static void test_8()
{
}

static void test_9()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
