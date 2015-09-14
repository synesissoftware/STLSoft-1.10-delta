/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/comstl/util/test.unit.comstl.util.variant.c
 *
 * Purpose:     Implementation file for the test.unit.comstl.util.variant project.
 *
 * Created:     26th October 2008
 * Updated:     18th June 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <comstl/util/variant.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <comstl/auto/functions.h>

/* Standard C Header Files */
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void test_ctor_default();
static void test_ctor_bool();
static void test_ctor_sint8();
static void test_ctor_uint8();
static void test_ctor_sint16();
static void test_ctor_uint16();
static void test_ctor_sint32();
static void test_ctor_uint32();
static void test_ctor_short();
static void test_ctor_ushort();
static void test_ctor_int();
static void test_ctor_uint();
static void test_ctor_long();
static void test_ctor_ulong();
static void test_ctor_float();
static void test_ctor_double();
static void test_ctor_cy();
static void test_ctor_decimal();

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    OleInitialize(NULL);

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.comstl.util.variant.VARIANT_equal", verbosity))
    {
        XTESTS_RUN_CASE(test_ctor_default);
        XTESTS_RUN_CASE(test_ctor_bool);
        XTESTS_RUN_CASE(test_ctor_sint8);
        XTESTS_RUN_CASE(test_ctor_uint8);
        XTESTS_RUN_CASE(test_ctor_sint16);
        XTESTS_RUN_CASE(test_ctor_uint16);
        XTESTS_RUN_CASE(test_ctor_sint32);
        XTESTS_RUN_CASE(test_ctor_uint32);
        XTESTS_RUN_CASE(test_ctor_short);
        XTESTS_RUN_CASE(test_ctor_ushort);
        XTESTS_RUN_CASE(test_ctor_int);
        XTESTS_RUN_CASE(test_ctor_uint);
        XTESTS_RUN_CASE(test_ctor_long);
        XTESTS_RUN_CASE(test_ctor_ulong);
        XTESTS_RUN_CASE(test_ctor_float);
        XTESTS_RUN_CASE(test_ctor_double);
        XTESTS_RUN_CASE(test_ctor_cy);
        XTESTS_RUN_CASE(test_ctor_decimal);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Constants
 */

#if 0
const CLSID clsidSynesisValue = { 0xE79E9900, 0x59DB, 0x4B94, { 0xAF, 0xE6, 0xD8, 0x8E, 0x23, 0x4D, 0xDD, 0xDA } };
#endif /* 0 */

#define VT_I4_VALUE             -123
#define VT_BSTR_VALUE           L"-123.456"
#define VT_R8_VALUE             -123.456
#define VT_DECIMAL_VALUE        12345
#define VT_DISPATCH_VALUE       -10101
#define VT_UNKNOWN_VALUE        L"-20202"

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

static void test_ctor_default()
{
    comstl::variant     v;

    XTESTS_TEST_ENUM_EQUAL(VT_EMPTY, v.vt);
}

static void test_ctor_bool()
{
    comstl::variant     v(false);

    XTESTS_TEST_ENUM_EQUAL(VT_BOOL, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(VARIANT_FALSE, v.boolVal);
}

static void test_ctor_sint8()
{
    comstl::variant     v(stlsoft::sint8_t(8));

    XTESTS_TEST_ENUM_EQUAL(VT_I1, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(8, int(v.cVal));
}

static void test_ctor_uint8()
{
    comstl::variant     v(stlsoft::uint8_t(9));

    XTESTS_TEST_ENUM_EQUAL(VT_UI1, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(UCHAR(9), v.bVal);
}

static void test_ctor_sint16()
{
    comstl::variant     v(stlsoft::sint16_t(16));

    XTESTS_TEST_ENUM_EQUAL(VT_I2, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(SHORT(16), v.iVal);
}

static void test_ctor_uint16()
{
    comstl::variant     v(stlsoft::uint16_t(17));

    XTESTS_TEST_ENUM_EQUAL(VT_UI2, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(USHORT(17), v.uiVal);
}

static void test_ctor_sint32()
{
    comstl::variant     v(stlsoft::sint32_t(32));

    XTESTS_TEST_ENUM_EQUAL(VT_I4, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(LONG(32), v.lVal);
}

static void test_ctor_uint32()
{
    comstl::variant     v(stlsoft::uint32_t(33));

    XTESTS_TEST_ENUM_EQUAL(VT_UI4, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(ULONG(33), v.ulVal);
}

static void test_ctor_short()
{
    comstl::variant     v(short(1));

    XTESTS_TEST_ENUM_EQUAL(VT_I2, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(SHORT(1), v.iVal);
}

static void test_ctor_ushort()
{
    comstl::variant     v(static_cast<unsigned short>(2));

    XTESTS_TEST_ENUM_EQUAL(VT_UI2, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(USHORT(2), v.iVal);
}

static void test_ctor_int()
{
    comstl::variant     v(int(3));

    XTESTS_TEST_ENUM_EQUAL(VT_I4, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(LONG(3), v.lVal);
}

static void test_ctor_uint()
{
    comstl::variant     v(static_cast<unsigned int>(4));

    XTESTS_TEST_ENUM_EQUAL(VT_UI4, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(ULONG(4), v.ulVal);
}

static void test_ctor_long()
{
    comstl::variant     v(long(5));

    XTESTS_TEST_ENUM_EQUAL(VT_I4, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(LONG(5), v.lVal);
}

static void test_ctor_ulong()
{
    comstl::variant     v(static_cast<unsigned long>(6));

    XTESTS_TEST_ENUM_EQUAL(VT_UI4, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(ULONG(6), v.ulVal);
}

static void test_ctor_float()
{
    comstl::variant     v(float(1.2));

    XTESTS_TEST_ENUM_EQUAL(VT_R4, v.vt);
    XTESTS_TEST_FLOATINGPOINT_EQUAL(float(1.2), v.fltVal);
}

static void test_ctor_double()
{
    comstl::variant     v(double(1.234));

    XTESTS_TEST_ENUM_EQUAL(VT_R8, v.vt);
    XTESTS_TEST_FLOATINGPOINT_EQUAL(double(1.234), v.dblVal);
}

static void test_ctor_cy()
{
    CY                  cy; cy.Hi = 9; cy.Lo = 99;
    comstl::variant     v(cy);

    XTESTS_TEST_ENUM_EQUAL(VT_CY, v.vt);
    XTESTS_TEST_INTEGER_EQUAL(9, v.cyVal.Hi);
    XTESTS_TEST_INTEGER_EQUAL(99u, v.cyVal.Lo);
}

static void test_ctor_decimal()
{
    DECIMAL const       dec = DECIMAL();
    comstl::variant     v(dec);

    XTESTS_TEST_ENUM_EQUAL(VT_DECIMAL, v.vt);
}

/* ///////////////////////////// end of file //////////////////////////// */
