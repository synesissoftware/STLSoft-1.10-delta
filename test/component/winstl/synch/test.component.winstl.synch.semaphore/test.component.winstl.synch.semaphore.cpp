/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.synch.semaphore.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.synch.semaphore project.
 *
 * Created:     24th August 2010
 * Updated:     24th August 2010
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

#include <winstl/synch/semaphore.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/limit_traits.h>
#include <stlsoft/util/sign_traits.hpp>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2a(void);
    static void test_1_2b(void);
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

    if(XTESTS_START_RUNNER("test.component.winstl.synch.semaphore", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_2a, winstl::windows_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_2b, winstl::windows_exception);
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

  typedef stlsoft::limit_traits<winstl::semaphore::count_type>  limits_t;


static void test_1_0()
{
    winstl::semaphore instance(1, 1);

    XTESTS_TEST_PASSED();
}

static void test_1_1()
{
    winstl::semaphore instance(0, 1);

    XTESTS_TEST_PASSED();
}

static void test_1_2a()
{
    winstl::semaphore instance(0, 0);

    XTESTS_TEST_PASSED();
}

static void test_1_2b()
{
    winstl::semaphore instance(1, 0);

    XTESTS_TEST_PASSED();
}

static void test_1_3()
{
    winstl::semaphore instance(winstl::semaphore::maxCountValue, winstl::semaphore::maxCountValue);

    XTESTS_TEST_PASSED();
}

static void test_1_4()
{
    { for(winstl::semaphore::count_type i = winstl::semaphore::maxCountValue; ; i >>= 1)
    {
        if(0 == i)
        {
            break;
        }

        { for(winstl::semaphore::count_type j = i; ; j >>= 1)
        {
            winstl::semaphore   instance(j, i);

            XTESTS_TEST_PASSED();

            if(0 == j)
            {
                break;
            }
        }}
    }}

}

static void test_1_5()
{
    winstl::semaphore   sem(2, 4);

    sem.unlock();
    sem.lock();
    sem.unlock();
    sem.unlock();
    sem.lock();
    sem.lock();

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
