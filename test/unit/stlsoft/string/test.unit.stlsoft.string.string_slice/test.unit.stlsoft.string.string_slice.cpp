/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.string_slice.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.string_slice project.
 *
 * Created:     19th February 2010
 * Updated:     5th May 2010
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

#include <stlsoft/string/string_slice.hpp>

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
    static void test_1_a(void);
    static void test_1_b(void);
    static void test_1_c(void);
    static void test_1_d(void);
    static void test_1_e(void);
    static void test_1_f(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.string.string_slice", verbosity))
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
        XTESTS_RUN_CASE(test_1_a);
        XTESTS_RUN_CASE(test_1_b);
        XTESTS_RUN_CASE(test_1_c);
        XTESTS_RUN_CASE(test_1_d);
        XTESTS_RUN_CASE(test_1_e);
        XTESTS_RUN_CASE(test_1_f);

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
    static char const   alphabet[] = "abcdefghijklmnopqrstuvwxyz";

static void test_1_0()
{
    stlsoft::string_slice<char> slice;

    STLSOFT_SUPPRESS_UNUSED(slice);

    XTESTS_TEST_PASSED();
}

static void test_1_1()
{
    stlsoft::string_slice<char> slice;

    XTESTS_TEST_INTEGER_EQUAL(0u, slice.len);
    XTESTS_TEST_POINTER_EQUAL(NULL, slice.ptr);

    XTESTS_TEST_INTEGER_EQUAL(0u, ::stlsoft::c_str_len_a(slice));
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ::stlsoft::c_str_data_a(slice));

    XTESTS_TEST_INTEGER_EQUAL(0u, ::stlsoft::c_str_len(slice));
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ::stlsoft::c_str_data(slice));

    XTESTS_TEST_INTEGER_EQUAL(0u, ::stlsoft::c_str_len_a(&slice));
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ::stlsoft::c_str_data_a(&slice));

    XTESTS_TEST_INTEGER_EQUAL(0u, ::stlsoft::c_str_len(&slice));
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ::stlsoft::c_str_data(&slice));
}

static void test_1_2()
{
    stlsoft::string_slice<char> slice(alphabet, 3u);

    XTESTS_TEST_INTEGER_EQUAL(3u, slice.len);
    XTESTS_TEST_POINTER_EQUAL(alphabet, slice.ptr);
}

static void test_1_3()
{
    stlsoft::string_slice<char> slice(alphabet);

    XTESTS_TEST_INTEGER_EQUAL(26u, slice.len);
    XTESTS_TEST_POINTER_EQUAL(alphabet, slice.ptr);
}

static void test_1_4()
{
    stlsoft::string_slice<char> slice(alphabet, 3u);
    stlsoft::string_slice<char> slice2(slice);

    XTESTS_TEST_INTEGER_EQUAL(3u, slice2.len);
    XTESTS_TEST_POINTER_EQUAL(alphabet, slice2.ptr);
}

static void test_1_5()
{
    stlsoft::string_slice<char> slice(alphabet, 3u);

    stlsoft::string_slice<char> slice2;

    slice2 = slice;

    XTESTS_TEST_INTEGER_EQUAL(3u, slice2.len);
    XTESTS_TEST_POINTER_EQUAL(alphabet, slice2.ptr);
}

static void test_1_6()
{
    stlsoft::string_slice<char> slice(alphabet, 3u);

    size_t      len = stlsoft::c_str_len(slice);
    char const* ptr = stlsoft::c_str_data(slice);

    XTESTS_TEST_INTEGER_EQUAL(3u, len);
    XTESTS_TEST_POINTER_EQUAL(alphabet, ptr);
}

static void test_1_7()
{
    stlsoft::string_slice<char> slice(alphabet, 3u);

    size_t      len = stlsoft::c_str_len_a(slice);
    char const* ptr = stlsoft::c_str_data_a(slice);

    XTESTS_TEST_INTEGER_EQUAL(3u, len);
    XTESTS_TEST_POINTER_EQUAL(alphabet, ptr);
}

static void test_1_8()
{
    stlsoft::string_slice<char> slice(alphabet, 3u);

    size_t      len = stlsoft::c_str_len(&slice);
    char const* ptr = stlsoft::c_str_data(&slice);

    XTESTS_TEST_INTEGER_EQUAL(3u, len);
    XTESTS_TEST_POINTER_EQUAL(alphabet, ptr);
}

static void test_1_9()
{
    stlsoft::string_slice<char> slice(alphabet, 3u);

    size_t      len = stlsoft::c_str_len_a(&slice);
    char const* ptr = stlsoft::c_str_data_a(&slice);

    XTESTS_TEST_INTEGER_EQUAL(3u, len);
    XTESTS_TEST_POINTER_EQUAL(alphabet, ptr);
}

static void test_1_a()
{
    stlsoft::string_slice<char> const*  slice = NULL;

    size_t      len = stlsoft::c_str_len_a(slice);
    char const* ptr = stlsoft::c_str_data_a(slice);

    XTESTS_TEST_INTEGER_EQUAL(0u, len);
    XTESTS_TEST_POINTER_NOT_EQUAL(NULL, ptr);
}

static void test_1_b()
{
	stlsoft::string_slice<char>		slice1(alphabet, 3u);
	stlsoft::string_slice<char>		slice2(alphabet, 3u);

	XTESTS_TEST_BOOLEAN_TRUE(slice1 == slice1);
	XTESTS_TEST_BOOLEAN_TRUE(slice1 == slice2);
	XTESTS_TEST_BOOLEAN_FALSE(slice1 != slice2);
}

static void test_1_c()
{
	stlsoft::string_slice<char>		slice1(alphabet, 3u);
	stlsoft::string_slice<char>		slice2(alphabet + 1, 3u);

	XTESTS_TEST_BOOLEAN_TRUE(slice1 < slice2);
	XTESTS_TEST_BOOLEAN_FALSE(slice1 > slice2);
}

static void test_1_d()
{
	stlsoft::string_slice<char>		slice1(alphabet, 3u);
	stlsoft::string_slice<char>		slice2(alphabet, 4u);

	XTESTS_TEST_BOOLEAN_TRUE(slice1 < slice2);
	XTESTS_TEST_BOOLEAN_FALSE(slice1 > slice2);
}

static void test_1_e()
{
	stlsoft::string_slice<char>		slice1(alphabet, 3u);
	stlsoft::string_slice<char>		slice2(alphabet, 3u);

	XTESTS_TEST_BOOLEAN_TRUE(slice1 <= slice1);
	XTESTS_TEST_BOOLEAN_TRUE(slice1 >= slice1);
	XTESTS_TEST_BOOLEAN_TRUE(slice1 <= slice2);
	XTESTS_TEST_BOOLEAN_TRUE(slice1 >= slice2);
}

static void test_1_f()
{
	stlsoft::string_slice<char>		slice1(alphabet, 3u);
	stlsoft::string_slice<char>		slice2(alphabet + 1, 3u);

	XTESTS_TEST_BOOLEAN_TRUE(slice1 <= slice2);
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
