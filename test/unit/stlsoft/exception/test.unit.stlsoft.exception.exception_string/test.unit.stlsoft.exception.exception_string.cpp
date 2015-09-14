/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.exception.exception_string.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.exception.exception_string project.
 *
 * Created:     4th May 2010
 * Updated:     16th January 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/util/exception_string.hpp>
#include <stlsoft/exception/exceptions.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Constants
 */

#ifdef _DEBUG
size_t const NUM_ITERATIONS	=	1000u;
#else /* ? _DEBUG */
size_t const NUM_ITERATIONS	=	1000000u;
#endif /* _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_default_instance(void);
    static void test_default_ctor_and_length(void);
    static void test_default_ctor_and_size(void);
    static void test_c_string_ctor_1(void);
    static void test_c_string_ctor_2(void);
    static void test_copy_ctor_1(void);
    static void test_copy_ctor_2(void);
    static void test_slice_ctor_1(void);
    static void test_slice_ctor_2(void);
    static void test_string_concatenation_1(void);
    static void test_string_concatenation_2(void);
    static void test_swap_1(void);
    static void test_swap_2(void);
    static void test_swap_3(void);
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.exception.exception_string", verbosity))
    {
        XTESTS_RUN_CASE(test_default_instance);
        XTESTS_RUN_CASE(test_default_ctor_and_length);
        XTESTS_RUN_CASE(test_default_ctor_and_size);
        XTESTS_RUN_CASE(test_c_string_ctor_1);
        XTESTS_RUN_CASE(test_c_string_ctor_2);
        XTESTS_RUN_CASE(test_copy_ctor_1);
        XTESTS_RUN_CASE(test_copy_ctor_2);
        XTESTS_RUN_CASE(test_slice_ctor_1);
        XTESTS_RUN_CASE(test_slice_ctor_2);
        XTESTS_RUN_CASE(test_string_concatenation_1);
        XTESTS_RUN_CASE(test_string_concatenation_2);
        XTESTS_RUN_CASE(test_swap_1);
        XTESTS_RUN_CASE(test_swap_2);
        XTESTS_RUN_CASE(test_swap_3);
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
 * Macros
 */

#define XTESTS_TEST_X_STRING_EQUAL          XTESTS_TEST_MULTIBYTE_STRING_EQUAL

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

static void test_default_instance()
{
    stlsoft::exception_string xs;

    STLSOFT_SUPPRESS_UNUSED(xs);

    XTESTS_TEST_PASSED();
}

static void test_default_ctor_and_length()
{
    stlsoft::exception_string xs;

    XTESTS_TEST_BOOLEAN_TRUE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, xs.length());
}

static void test_default_ctor_and_size()
{
    stlsoft::exception_string xs;

    XTESTS_TEST_BOOLEAN_TRUE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, xs.size());
}

static void test_c_string_ctor_1()
{
    stlsoft::exception_string xs("a");

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs);
}

static void test_c_string_ctor_2()
{
    { for(size_t i = 1u; i != NUM_ITERATIONS; i *= 10u)
    {
        std::string s(i, '*');

        stlsoft::exception_string xs(s.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs);
    }}
}

static void test_copy_ctor_1()
{
    stlsoft::exception_string xs1("a");

    XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs1.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs1);

    stlsoft::exception_string xs2(xs1);

    XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs2.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs2);
    XTESTS_TEST_X_STRING_EQUAL(xs1, xs2);
}

static void test_copy_ctor_2()
{
    { for(size_t i = 1u; i != NUM_ITERATIONS; i *= 10u)
    {
        std::string s(i, '*');

        stlsoft::exception_string xs1(s.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs1);

        stlsoft::exception_string xs2(xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs2);
    }}
}

static void test_slice_ctor_1()
{
    stlsoft::exception_string xs("a", 1u);

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs);
}

static void test_slice_ctor_2()
{
    stlsoft::exception_string xs("ab", 1u);

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs);
}

static void test_string_concatenation_1()
{
    stlsoft::exception_string xs1("a");

    XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs1.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs1);

    stlsoft::exception_string xs2 = xs1 + 'b';

    XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, xs2.size());
    XTESTS_TEST_X_STRING_EQUAL("ab", xs2);

    stlsoft::exception_string xs3 = xs1 + "b";

    XTESTS_TEST_BOOLEAN_FALSE(xs3.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, xs3.size());
    XTESTS_TEST_X_STRING_EQUAL("ab", xs3);

    stlsoft::exception_string xs4 = 'b' + xs1;

    XTESTS_TEST_BOOLEAN_FALSE(xs4.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, xs4.size());
    XTESTS_TEST_X_STRING_EQUAL("ba", xs4);

    stlsoft::exception_string xs5 = "b" + xs1;

    XTESTS_TEST_BOOLEAN_FALSE(xs5.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, xs5.size());
    XTESTS_TEST_X_STRING_EQUAL("ba", xs5);
}

static void test_string_concatenation_2()
{
    { for(size_t i = 1u; i != NUM_ITERATIONS; i *= 10u)
    {
        std::string s(i, '*');

        stlsoft::exception_string xs1(s.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs1);

        stlsoft::exception_string xs2 = xs1 + 'b';

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(i + 1u, xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s + "b", xs2);

        stlsoft::exception_string xs3 = xs1 + "b";

        XTESTS_TEST_BOOLEAN_FALSE(xs3.empty());
        XTESTS_TEST_INTEGER_EQUAL(i + 1u, xs3.size());
        XTESTS_TEST_X_STRING_EQUAL(s + "b", xs3);

        stlsoft::exception_string xs4 = 'b' + xs1;

        XTESTS_TEST_BOOLEAN_FALSE(xs4.empty());
        XTESTS_TEST_INTEGER_EQUAL(i + 1u, xs4.size());
        XTESTS_TEST_X_STRING_EQUAL("b" + s, xs4);

        stlsoft::exception_string xs5 = "b" + xs1;

        XTESTS_TEST_BOOLEAN_FALSE(xs5.empty());
        XTESTS_TEST_INTEGER_EQUAL(i + 1u, xs5.size());
        XTESTS_TEST_X_STRING_EQUAL("b" + s, xs5);
    }}
}

static void test_swap_1()
{
    { for(size_t i = 1u; i != NUM_ITERATIONS; i *= 10u)
    {
        std::string s(i, '*');

        stlsoft::exception_string xs1(s.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs1);

        stlsoft::exception_string xs2;

        XTESTS_TEST_BOOLEAN_TRUE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, xs2.size());

        xs2.swap(xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(i, xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s, xs2);

        XTESTS_TEST_BOOLEAN_TRUE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, xs1.size());
    }}
}

static void test_swap_2()
{
        std::string s1("abc");
        std::string s2(2000, '~');

        stlsoft::exception_string xs1(s1.c_str());
        stlsoft::exception_string xs2(s2.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(s1.size(), xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s1, xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(s2.size(), xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s2, xs2);

        stlsoft::swap(xs1, xs2);

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(s2.size(), xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s2, xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(s1.size(), xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s1, xs2);
}

static void test_swap_3()
{
        std::string s1("abc");
        std::string s2(2000, '~');

        stlsoft::exception_string xs1(s1.c_str());
        stlsoft::exception_string xs2(s2.c_str());

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(s1.size(), xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s1, xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(s2.size(), xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s2, xs2);

        std::swap(xs1, xs2);

        XTESTS_TEST_BOOLEAN_FALSE(xs1.empty());
        XTESTS_TEST_INTEGER_EQUAL(s2.size(), xs1.size());
        XTESTS_TEST_X_STRING_EQUAL(s2, xs1);

        XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
        XTESTS_TEST_INTEGER_EQUAL(s1.size(), xs2.size());
        XTESTS_TEST_X_STRING_EQUAL(s1, xs2);
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
#if 0
    stlsoft::exception_string xs("a");

    XTESTS_TEST_BOOLEAN_FALSE(xs.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, xs.size());
    XTESTS_TEST_X_STRING_EQUAL("a", xs);

    stlsoft::exception_string xs2 = xs + "bcdefghijklmnopqrstuvwxyz";

    XTESTS_TEST_BOOLEAN_FALSE(xs2.empty());
    XTESTS_TEST_INTEGER_EQUAL(26u, xs2.size());
    XTESTS_TEST_X_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", xs2);
#endif /* 0 */
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
