/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.filesystem.memory_mapped_file_view_handle.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.filesystem.memory_mapped_file_view_handle project.
 *
 * Created:     30th August 2010
 * Updated:     30th August 2010
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

#include <winstl/filesystem/handles/memory_mapped_file_view_handle.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/synch/refcount_policies/refcount_policy_single_threaded.hpp>
#include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
#include <winstl/filesystem/memory_map_functions.h>

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
 * Statics
 */

namespace
{

    static char s_arg0[1024 + 1];

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    ::strcpy(s_arg0, argv[0]);

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.winstl.filesystem.memory_mapped_file_view_handle", verbosity))
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
    using winstl::ws_uintptr_t;

    typedef winstl::memory_mapped_file_view_handle<stlsoft::refcount_policy_single_threaded>    handle_st_t;
    typedef winstl::memory_mapped_file_view_handle<platformstl::refcount_policy_multi_threaded> handle_mt_t;

static void test_1_0()
{
    if(0)
    {
        handle_st_t::Ref instance = handle_st_t::create(NULL, 0);

        STLSOFT_SUPPRESS_UNUSED(instance);
    }

    XTESTS_TEST_PASSED();
}

static void test_1_1()
{
    if(0)
    {
        handle_mt_t::Ref instance = handle_mt_t::create(NULL, 0);

        STLSOFT_SUPPRESS_UNUSED(instance);
    }

    XTESTS_TEST_PASSED();
}

static void test_1_2()
{
    ws_uintptr_t    viewSize;
    void* const     memory = winstl::map_readonly_view_of_file_by_name(s_arg0, GENERIC_READ, 0, &viewSize);

    handle_mt_t::Ref instance = handle_mt_t::create(memory, viewSize);

    XTESTS_TEST_POINTER_EQUAL(memory, instance->handle.memory);
    XTESTS_TEST_INTEGER_EQUAL(viewSize, instance->handle.size);
}

static void test_1_3()
{
    ws_uintptr_t    viewSize;
    void* const     memory = winstl::map_readonly_view_of_file_by_name(s_arg0, GENERIC_READ, 0, &viewSize);

    handle_mt_t::Ref instance = handle_mt_t::create(memory, viewSize);

    XTESTS_TEST_POINTER_EQUAL(memory, instance->handle.memory);
    XTESTS_TEST_INTEGER_EQUAL(viewSize, instance->handle.size);

    handle_mt_t::Ref instance2 = instance;

    XTESTS_TEST_POINTER_EQUAL(memory, instance2->handle.memory);
    XTESTS_TEST_INTEGER_EQUAL(viewSize, instance2->handle.size);
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
