/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/comstl/util/test.unit.comstl.util.GUID_functions.c
 *
 * Purpose:     Implementation file for the test.unit.comstl.util.GUID_functions project.
 *
 * Created:     12th May 2010
 * Updated:     18th June 2010
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

#include <comstl/util/GUID_functions.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <comstl/auto/functions.h>
#include <platformstl/platformstl.h>

/* Standard C Header Files */
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void test_equal(void);
static void test_compare(void);
static void test_binary_compare(void);
static void test_to_string(void);
static void test_from_string(void);
static void test_0_5(void);
static void test_0_6(void);

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    OleInitialize(NULL);

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.comstl.util.GUID_functions.GUID_equal", verbosity))
    {
        XTESTS_RUN_CASE(test_equal);
        XTESTS_RUN_CASE(test_compare);
        XTESTS_RUN_CASE(test_binary_compare);
        XTESTS_RUN_CASE(test_to_string);
        XTESTS_RUN_CASE(test_from_string);
        XTESTS_RUN_CASE(test_0_5);
        XTESTS_RUN_CASE(test_0_6);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

// {F4864792-D0D2-4005-ABCA-F67994C2FFA6}
static const GUID s_guid1 = 
{ 0xf4864792, 0xd0d2, 0x4005, { 0xab, 0xca, 0xf6, 0x79, 0x94, 0xc2, 0xff, 0xa6 } };

#if 0
// {B7AF66FA-B56C-4249-831C-647230297058}
static const GUID s_guid2 = 
{ 0xb7af66fa, 0xb56c, 0x4249, { 0x83, 0x1c, 0x64, 0x72, 0x30, 0x29, 0x70, 0x58 } };

// {74A72AB6-7396-4d16-80C4-0E099097158E}
static const GUID s_guid3 = 
{ 0x74a72ab6, 0x7396, 0x4d16, { 0x80, 0xc4, 0xe, 0x9, 0x90, 0x97, 0x15, 0x8e } };
#endif /* 0 */


static void test_equal(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(comstl_C_GUID_equal(&IID_IUnknown, &IID_IUnknown));
    XTESTS_TEST_BOOLEAN_FALSE(comstl_C_GUID_equal(&GUID_NULL, &IID_IUnknown));
}

static void test_compare(void)
{
    XTESTS_TEST_INTEGER_EQUAL(0, comstl_C_GUID_compare(&IID_IUnknown, &IID_IUnknown, NULL));
    XTESTS_TEST_INTEGER_LESS(0, comstl_C_GUID_compare(&GUID_NULL, &IID_IUnknown, NULL));
    XTESTS_TEST_INTEGER_GREATER(0, comstl_C_GUID_compare(&IID_IUnknown, &GUID_NULL, NULL));
}

static void test_binary_compare(void)
{
#if defined(PLATFORMSTL_ARCH_IS_X86) || \
	defined(PLATFORMSTL_ARCH_IS_X64)

    XTESTS_TEST_INTEGER_EQUAL(0, comstl_C_GUID_binary_compare(&IID_IUnknown, &IID_IUnknown));
    XTESTS_TEST_INTEGER_LESS(0, comstl_C_GUID_binary_compare(&GUID_NULL, &IID_IUnknown));
    XTESTS_TEST_INTEGER_GREATER(0, comstl_C_GUID_binary_compare(&IID_IUnknown, &GUID_NULL));

#endif
}

static void test_to_string(void)
{
    wchar_t ws1[39];
    char    mbs1[39];
    HRESULT hr;

    hr = comstl_C_GUID_to_string_w(&s_guid1, &ws1);
    XTESTS_TEST_INTEGER_EQUAL(S_OK, hr);
    XTESTS_TEST_WIDE_STRING_EQUAL(L"{F4864792-D0D2-4005-ABCA-F67994C2FFA6}", ws1);

    hr = comstl_C_GUID_to_string_a(&s_guid1, &mbs1);
    XTESTS_TEST_INTEGER_EQUAL(S_OK, hr);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("{F4864792-D0D2-4005-ABCA-F67994C2FFA6}", mbs1);

}

static void test_from_string(void)
{
    GUID    guid1;
    GUID    guid2;
    HRESULT hr;

    hr = comstl_C_GUID_from_string_w(L"{F4864792-D0D2-4005-ABCA-F67994C2FFA6}", &guid1);
    XTESTS_TEST_INTEGER_EQUAL(S_OK, hr);

    hr = comstl_C_GUID_from_string_a("{F4864792-D0D2-4005-ABCA-F67994C2FFA6}", &guid2);
    XTESTS_TEST_INTEGER_EQUAL(S_OK, hr);

    XTESTS_TEST_BOOLEAN_TRUE(comstl_C_GUID_equal(&guid1, &guid2));
}

static void test_0_5(void)
{
}

static void test_0_6(void)
{
}

/* ///////////////////////////// end of file //////////////////////////// */
