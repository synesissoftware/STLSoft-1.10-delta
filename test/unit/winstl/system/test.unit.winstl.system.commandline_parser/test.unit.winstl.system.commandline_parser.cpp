/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.system.commandline_parser.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.system.commandline_parser project.
 *
 * Created:     28th January 2009
 * Updated:     6th May 2009
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

#include <winstl/system/commandline_parser.hpp>

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
#include <iterator>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_ctor(void);
    static void test_empty_and_null(void);
    static void test_empty(void);
    static void test_empty_in_quotes(void);
    static void test_1_01(void);
    static void test_1_02(void);
    static void test_1_03(void);
    static void test_1_04(void);
    static void test_1_05(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.system.commandline_parser", verbosity))
    {
        XTESTS_RUN_CASE(test_ctor);
        XTESTS_RUN_CASE(test_empty_and_null);
        XTESTS_RUN_CASE(test_empty);
        XTESTS_RUN_CASE(test_empty_in_quotes);
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);

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
    using winstl::commandline_parser_a;

static void test_ctor()
{
    commandline_parser_a args("", 0);

    XTESTS_TEST_PASSED();
}

static void test_empty_and_null()
{
    commandline_parser_a args(NULL, 0);

    XTESTS_TEST_INTEGER_EQUAL(0u, args.size());
}

static void test_empty()
{
    commandline_parser_a args("", 0);

    XTESTS_TEST_INTEGER_EQUAL(0u, args.size());
}

static void test_empty_in_quotes()
{
    commandline_parser_a args("\"\"", 2);

    XTESTS_TEST_INTEGER_EQUAL(0u, args.size());
}

static void test_1_01()
{
    commandline_parser_a args("abc");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, args.size()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", args[0]);
}

static void test_1_02()
{
    commandline_parser_a args("abc def");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, args.size()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", args[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", args[1]);
}

static void test_1_03()
{
    commandline_parser_a args("a b c d e f g h i j k l m n o p q r s t u v w x y z");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(26u, args.size()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", args[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("b", args[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("c", args[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("d", args[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("e", args[4]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("f", args[5]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("g", args[6]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("h", args[7]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("i", args[8]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("j", args[9]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("k", args[10]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("l", args[11]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("m", args[12]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("n", args[13]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("o", args[14]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("p", args[15]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("q", args[16]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("r", args[17]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("s", args[18]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("t", args[19]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("u", args[20]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("v", args[21]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("w", args[22]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x", args[23]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("y", args[24]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("z", args[25]);
}

static void test_1_04()
{
    commandline_parser_a args("a \"b\" c \"d\" e \"f\" g \"h\" i \"j\" k \"l\" m \"n\" o \"p\" q \"r\" s \"t\" u \"v\" w \"x\" y \"z\"");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(26u, args.size()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", args[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("b", args[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("c", args[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("d", args[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("e", args[4]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("f", args[5]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("g", args[6]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("h", args[7]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("i", args[8]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("j", args[9]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("k", args[10]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("l", args[11]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("m", args[12]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("n", args[13]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("o", args[14]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("p", args[15]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("q", args[16]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("r", args[17]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("s", args[18]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("t", args[19]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("u", args[20]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("v", args[21]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("w", args[22]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x", args[23]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("y", args[24]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("z", args[25]);
}

static void test_1_05()
{
    commandline_parser_a args("a \"b c d\" e \"f g h\" i \"j k l\" m \"n o p\" q \"r s t\" u \"v w x\" y \"z\"");

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(14u, args.size()));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", args[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("b c d", args[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("e", args[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("f g h", args[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("i", args[4]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("j k l", args[5]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("m", args[6]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("n o p", args[7]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("q", args[8]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("r s t", args[9]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("u", args[10]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("v w x", args[11]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("y", args[12]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("z", args[13]);
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
