/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.memory.auto_buffer.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.memory.auto_buffer project.
 *
 * Created:     25th February 2009
 * Updated:     26th August 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/memory/auto_buffer.hpp>

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
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_01(void);
    static void test_1_02(void);
    static void test_1_03(void);
    static void test_1_04(void);
    static void test_1_05(void);
    static void test_1_06(void);
    static void test_1_07(void);
    static void test_1_08(void);
    static void test_1_09(void);
    static void test_1_10(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.memory.auto_buffer", verbosity))
    {
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);
        XTESTS_RUN_CASE(test_1_06);
        XTESTS_RUN_CASE(test_1_07);
        XTESTS_RUN_CASE(test_1_08);
        XTESTS_RUN_CASE(test_1_09);
        XTESTS_RUN_CASE(test_1_10);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/auto_buffer.hpp", NULL);
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

static void test_1_01()
{
    stlsoft::auto_buffer<char>      buff(0);

    XTESTS_TEST_INTEGER_EQUAL(0u, buff.size());
    XTESTS_TEST_INTEGER_NOT_EQUAL(0u, buff.internal_size());
}

static void test_1_02()
{
    stlsoft::auto_buffer<char, 10>      buff(0);

    XTESTS_TEST_INTEGER_EQUAL(0u, buff.size());
    XTESTS_TEST_INTEGER_EQUAL(10u, buff.internal_size());
}

static void test_1_03()
{
    stlsoft::auto_buffer<char, 10>      buff(10);

    XTESTS_TEST_INTEGER_EQUAL(10u, buff.size());
    XTESTS_TEST_INTEGER_EQUAL(10u, buff.internal_size());
}

static void test_1_04()
{
    stlsoft::auto_buffer<char, 10>      buff(1u);

    char* const first = buff.data();

    { for(size_t i = 0; i != buff.internal_size(); ++i)
    {
        buff.resize(i);

        XTESTS_TEST_INTEGER_EQUAL(i, buff.size());
        XTESTS_TEST_POINTER_EQUAL(first, buff.data());
    }}

    { for(size_t i = 1u + buff.internal_size(); i != 10000; ++i)
    {
        buff.resize(i);

        XTESTS_TEST_INTEGER_EQUAL(i, buff.size());
        XTESTS_TEST_POINTER_NOT_EQUAL(first, buff.data());
    }}
}

static void test_1_05()
{
    stlsoft::auto_buffer<char, 10>::allocator_type  ator;
    stlsoft::auto_buffer<char, 10>                  buff(0);

    std::vector<char*>  buffers;

    size_t  size = 1;

    { for(size_t i = 0; i != 32; ++i, size <<= 1)
    {
        try
        {
            char* p = ator.allocate(size, NULL);

            if(NULL != p)
            {
                buffers.push_back(p);
            }
        }
        catch(std::bad_alloc&)
        {}
    }}

    // Now we're close to exhaustion
    size = 1;

    { for(size_t i = 0; i != 32; ++i, size <<= 1)
    {
#ifdef STLSOFT_CF_THROW_BAD_ALLOC
        try
        {
            XTESTS_TEST_BOOLEAN_TRUE(buff.resize(size));
        }
        catch(std::bad_alloc&)
        {}
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
    }}

    { for(std::vector<char*>::iterator b = buffers.begin(); b != buffers.end(); ++b)
    {
        ator.deallocate(*b, 0u);
    }}
}

static void test_1_06()
{

}

static void test_1_07()
{
    // ab1.swap(ab2)
    {
        stlsoft::auto_buffer<int, 10>   ab1(10);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(10u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab1.swap(ab2);

        XTESTS_TEST_INTEGER_EQUAL(8u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(10u,  ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }

    // ab2.swap(ab1)
    {
        stlsoft::auto_buffer<int, 10>   ab1(10);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(10u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab2.swap(ab1);

        XTESTS_TEST_INTEGER_EQUAL(8u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(10u,  ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }
}

static void test_1_08()
{
    // ab1.swap(ab2)
    {
        stlsoft::auto_buffer<int, 10>   ab1(50);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(50u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab1.swap(ab2);

        XTESTS_TEST_INTEGER_EQUAL(8u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(50u,  ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }

    // ab2.swap(ab1)
    {
        stlsoft::auto_buffer<int, 10>   ab1(10);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(10u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab2.swap(ab1);

        XTESTS_TEST_INTEGER_EQUAL(8u,  ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(10u, ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }
}

static void test_1_09()
{
    // ab1.swap(ab2)
    {
        stlsoft::auto_buffer<int, 10>   ab1(50);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(50u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab1.swap(ab2);

        XTESTS_TEST_INTEGER_EQUAL(8u,  ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(50u, ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }

    // ab2.swap(ab1)
    {
        stlsoft::auto_buffer<int, 10>   ab1(10);
        stlsoft::auto_buffer<int, 10>   ab2(18);

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(10u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(18u, ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab2.swap(ab1);

        XTESTS_TEST_INTEGER_EQUAL(18u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(10u, ab2.size());

        { for(size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for(size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }
}

static void test_1_10()
{

}




} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
