/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.iterator.filter_iterator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.iterator.filter_iterator project.
 *
 * Created:     17th June 2010
 * Updated:     17th June 2010
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

#include <stlsoft/iterator/filter_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/dimensionof.h>

/* Standard C++ Header Files */
#include <deque>
#include <map>
#include <set>
#include <string>
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.iterator.filter_iterator", verbosity))
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

    typedef std::string                     string_t;
    typedef std::deque<string_t>            string_deque_t;
    typedef std::vector<string_t>           strings_t;
    typedef std::set<string_t>              stringset_t;
    typedef std::map<string_t, string_t>    string_to_string_map_t;

    static char const* LINES[] =
    {
        "# title line",
        "abc",
        "def",
        "# comment line",
        "ghi",
        "jkl",
    };

    struct is_comment
        : public std::unary_function<string_t, bool>
    {
        bool operator ()(string_t const& line) const
        {
            return !line.empty() && '#' == line[0];
        }
    };

static void test_1_0()
{
    strings_t   lines(LINES, LINES + dimensionof(LINES));

    XTESTS_TEST_PASSED();
}

static void test_1_1()
{
    strings_t   lines(LINES, LINES + dimensionof(LINES));

    strings_t   filteredLines(
                    stlsoft::filter(lines.begin(), lines.end(), std::not1(is_comment()))
                ,   stlsoft::filter(lines.end(),   lines.end(), std::not1(is_comment()))
                );

    XTESTS_TEST_INTEGER_EQUAL(4u, filteredLines.size());
}

static void test_1_2()
{
    strings_t   lines(LINES, LINES + dimensionof(LINES));

    strings_t   filteredLines(
                    stlsoft::filter(lines.begin(), lines.end(), std::not1(is_comment()))
                ,   stlsoft::filter_end(lines.end(), std::not1(is_comment()))
                );

    XTESTS_TEST_INTEGER_EQUAL(4u, filteredLines.size());
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
