/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.util.minmax.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.util.minmax project.
 *
 * Created:     10th August 2010
 * Updated:     10th August 2010
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

#include <stlsoft/util/minmax.hpp>

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

    static void test_maximum_2(void);
    static void test_minimum_2(void);

    static void test_maximum_3(void);
    static void test_minimum_3(void);
    static void test_maximum_4(void);
    static void test_minimum_4(void);
    static void test_maximum_5(void);
    static void test_minimum_5(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.util.minmax", verbosity))
    {
        XTESTS_RUN_CASE(test_maximum_2);
        XTESTS_RUN_CASE(test_minimum_2);

        XTESTS_RUN_CASE(test_maximum_3);
        XTESTS_RUN_CASE(test_minimum_3);

        XTESTS_RUN_CASE(test_maximum_4);
        XTESTS_RUN_CASE(test_minimum_4);

        XTESTS_RUN_CASE(test_maximum_5);
        XTESTS_RUN_CASE(test_minimum_5);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/minmax.hpp", NULL);
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

static void test_maximum_2()
{
    {
        int i1  =   1;
        int i2  =   2;
        int r   =   stlsoft::maximum(i1, i2);

        XTESTS_TEST_INTEGER_EQUAL(2, r);
    }

    {
        std::string i1  =   "1";
        std::string i2  =   "2";
        std::string r   =   stlsoft::maximum(i1, i2);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("2", r);
    }

}

static void test_minimum_2()
{
    {
        int i1  =   1;
        int i2  =   2;
        int r   =   stlsoft::minimum(i1, i2);

        XTESTS_TEST_INTEGER_EQUAL(1, r);
    }

    {
        std::string i1  =   "1";
        std::string i2  =   "2";
        std::string r   =   stlsoft::minimum(i1, i2);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1", r);
    }

}

static void test_maximum_3()
{
    {
        int i1  =   1;
        int i2  =   2;
        int i3  =   3;
        int r   =   stlsoft::maximum(i1, i2, i3);

        XTESTS_TEST_INTEGER_EQUAL(3, r);
    }

    {
        std::string i1  =   "1";
        std::string i2  =   "2";
        std::string i3  =   "3";
        std::string r   =   stlsoft::maximum(i1, i2, i3);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("3", r);
    }
}

static void test_minimum_3()
{
    {
        int i1  =   1;
        int i2  =   2;
        int i3  =   3;
        int r   =   stlsoft::minimum(i1, i2, i3);

        XTESTS_TEST_INTEGER_EQUAL(1, r);
    }

    {
        std::string i1  =   "1";
        std::string i2  =   "2";
        std::string i3  =   "3";
        std::string r   =   stlsoft::minimum(i1, i2, i3);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1", r);
    }
}

static void test_maximum_4()
{
    {
        int i1  =   1;
        int i2  =   2;
        int i3  =   3;
        int i4  =   4;
        int r   =   stlsoft::maximum(i1, i2, i3, i4);

        XTESTS_TEST_INTEGER_EQUAL(4, r);
    }

    {
        std::string i1  =   "1";
        std::string i2  =   "2";
        std::string i3  =   "3";
        std::string i4  =   "4";
        std::string r   =   stlsoft::maximum(i1, i2, i3, i4);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("4", r);
    }
}

static void test_minimum_4()
{
    {
        int i1  =   1;
        int i2  =   2;
        int i3  =   3;
        int i4  =   4;
        int r   =   stlsoft::minimum(i1, i2, i3, i4);

        XTESTS_TEST_INTEGER_EQUAL(1, r);
    }

    {
        std::string i1  =   "1";
        std::string i2  =   "2";
        std::string i3  =   "3";
        std::string i4  =   "4";
        std::string r   =   stlsoft::minimum(i1, i2, i3, i4);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1", r);
    }
}

static void test_maximum_5()
{
    {
        int i1  =   1;
        int i2  =   2;
        int i3  =   3;
        int i4  =   4;
        int i5  =   5;
        int r   =   stlsoft::maximum(i1, i2, i3, i4, i5);

        XTESTS_TEST_INTEGER_EQUAL(5, r);
    }

    {
        std::string i1  =   "1";
        std::string i2  =   "2";
        std::string i3  =   "3";
        std::string i4  =   "4";
        std::string i5  =   "5";
        std::string r   =   stlsoft::maximum(i1, i2, i3, i4, i5);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("5", r);
    }
}

static void test_minimum_5()
{
    {
        int i1  =   1;
        int i2  =   2;
        int i3  =   3;
        int i4  =   4;
        int i5  =   5;
        int r   =   stlsoft::minimum(i1, i2, i3, i4, i5);

        XTESTS_TEST_INTEGER_EQUAL(1, r);
    }

    {
        std::string i1  =   "1";
        std::string i2  =   "2";
        std::string i3  =   "3";
        std::string i4  =   "4";
        std::string i5  =   "5";
        std::string r   =   stlsoft::minimum(i1, i2, i3, i4, i5);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("1", r);
    }
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
