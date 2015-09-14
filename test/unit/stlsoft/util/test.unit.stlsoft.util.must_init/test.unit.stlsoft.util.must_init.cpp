/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.util.must_init.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.util.must_init project.
 *
 * Created:     17th January 2009
 * Updated:     17th January 2009
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

#include <stlsoft/util/must_init.hpp>

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

    static void test_specialisations(void);
    static void test_int_ctor(void);
    static void test_short_ctor(void);
    static void test_ushort_ctor(void);
    static void test_int_arithmetic_unary(void);
    static void test_int_arithmetic_binary(void);
    static void test_int_bitwise_unary(void);
    static void test_int_bitwise_binary(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.util.must_init", verbosity))
    {
        XTESTS_RUN_CASE(test_specialisations);
        XTESTS_RUN_CASE(test_int_ctor);
        XTESTS_RUN_CASE(test_short_ctor);
        XTESTS_RUN_CASE(test_ushort_ctor);
        XTESTS_RUN_CASE(test_int_arithmetic_unary);
        XTESTS_RUN_CASE(test_int_arithmetic_binary);
        XTESTS_RUN_CASE(test_int_bitwise_unary);
		XTESTS_RUN_CASE(test_int_bitwise_binary);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/must_init.hpp", NULL);
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
	using stlsoft::bool_init_t;
	using stlsoft::char_init_t;
	using stlsoft::wchar_t_init_t;
	using stlsoft::signed_char_init_t;
	using stlsoft::unsigned_char_init_t;
	using stlsoft::short_init_t;
	using stlsoft::unsigned_short_init_t;
	using stlsoft::int_init_t;
	using stlsoft::unsigned_int_init_t;
	using stlsoft::long_init_t;
	using stlsoft::unsigned_long_init_t;
	using stlsoft::sint64_init_t;
	using stlsoft::uint64_init_t;
	using stlsoft::float_init_t;
	using stlsoft::double_init_t;
	using stlsoft::long_double_init_t;

static void test_specialisations()
{
    {
        bool_init_t     v(false);

        XTESTS_TEST_PASSED();
    }

    {
        char_init_t     v('\0');

        XTESTS_TEST_PASSED();
    }

    {
        wchar_t_init_t      v(0);

        XTESTS_TEST_PASSED();
    }

    {
        signed_char_init_t      v(0);

        XTESTS_TEST_PASSED();
    }

    {
        unsigned_char_init_t        v(0);

        XTESTS_TEST_PASSED();
    }

    {
        short_init_t        v(0);

        XTESTS_TEST_PASSED();
    }

    {
        unsigned_short_init_t       v(0);

        XTESTS_TEST_PASSED();
    }

    {
        int_init_t      v(0);

        XTESTS_TEST_PASSED();
    }

    {
        unsigned_int_init_t     v(0);

        XTESTS_TEST_PASSED();
    }

    {
        long_init_t     v(0);

        XTESTS_TEST_PASSED();
    }

    {
        unsigned_long_init_t        v(0);

        XTESTS_TEST_PASSED();
    }

    {
        sint64_init_t       v(0);

        XTESTS_TEST_PASSED();
    }

    {
        uint64_init_t       v(0);

        XTESTS_TEST_PASSED();
    }

    {
        float_init_t        v(0.0f);

        XTESTS_TEST_PASSED();
    }

    {
        double_init_t       v(0.0);

        XTESTS_TEST_PASSED();
    }

    {
        long_double_init_t      v(0.0);

        XTESTS_TEST_PASSED();
    }
}

static void test_int_ctor()
{
    const int values[] = { INT_MIN, -43434534, -20000, -3000, -400, -50, -6, -1, 0, 3, 10, 99, 271, 7871, 3434534, INT_MAX };

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
	{
		int_init_t		v(values[i]);

		XTESTS_TEST_INTEGER_EQUAL(values[i], v.get());
	}}
}

static void test_short_ctor()
{
    const short values[] = { SHRT_MIN, -20000, -3000, -400, -50, -6, -1, 0, 3, 10, 99, 271, 7871, SHRT_MAX };

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
	{
		short_init_t		v(values[i]);

		XTESTS_TEST_INTEGER_EQUAL(values[i], v.get());
	}}
}

static void test_ushort_ctor()
{
    const unsigned short values[] = { 0, 3, 10, 99, 271, 7871, 20000, USHRT_MAX };

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
	{
		unsigned_short_init_t		v(values[i]);

		XTESTS_TEST_INTEGER_EQUAL(values[i], v.get());
	}}
}

static void test_int_arithmetic_unary()
{
	int_init_t		v(0);

	XTESTS_TEST_INTEGER_EQUAL(0, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0);

	v += 1;

	XTESTS_TEST_INTEGER_EQUAL(1, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(1 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 1);

	v -= 1;

	XTESTS_TEST_INTEGER_EQUAL(0, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0);

	v += 1;
	v += 1;

	XTESTS_TEST_INTEGER_EQUAL(2, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(2 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 2);

	v += v;

	XTESTS_TEST_INTEGER_EQUAL(4, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(4 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 4);

	v *= 1;

	XTESTS_TEST_INTEGER_EQUAL(4, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(4 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 4);

	v /= 1;

	XTESTS_TEST_INTEGER_EQUAL(4, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(4 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 4);

	v %= 8;

	XTESTS_TEST_INTEGER_EQUAL(4, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(4 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 4);
}

static void test_int_arithmetic_binary()
{
	int_init_t		v(0);

	XTESTS_TEST_INTEGER_EQUAL(0, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0);

	v = v + 1;

	XTESTS_TEST_INTEGER_EQUAL(1, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(1 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 1);

	v = v - 1;

	XTESTS_TEST_INTEGER_EQUAL(0, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0);

	v = v + 1;
	v = 1 + v;

	XTESTS_TEST_INTEGER_EQUAL(2, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(2 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 2);

	v = v + v;

	XTESTS_TEST_INTEGER_EQUAL(4, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(4 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 4);

	v = v * 1;

	XTESTS_TEST_INTEGER_EQUAL(4, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(4 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 4);

	v = v / 1;

	XTESTS_TEST_INTEGER_EQUAL(4, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(4 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 4);

	v = v % 8;

	XTESTS_TEST_INTEGER_EQUAL(4, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(4 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 4);
}

static void test_int_bitwise_unary()
{
	int_init_t	v(0x0000);

	XTESTS_TEST_INTEGER_EQUAL(0x0000, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0000 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0000);

	v |= 0x0011;

	XTESTS_TEST_INTEGER_EQUAL(0x0011, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0011 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0011);

	v &= 0x000f;

	XTESTS_TEST_INTEGER_EQUAL(0x0001, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0001 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0001);

	v <<= 8;

	XTESTS_TEST_INTEGER_EQUAL(0x0100, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0100 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0100);

	v >>= 4;

	XTESTS_TEST_INTEGER_EQUAL(0x0010, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0010 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0010);

	v ^= 0xffff;
	v &= 0xffff;

	XTESTS_TEST_INTEGER_EQUAL(0xffef, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0xffef == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0xffef);
}

static void test_int_bitwise_binary()
{
	int_init_t	v(0x0000);

	XTESTS_TEST_INTEGER_EQUAL(0x0000, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0000 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0000);

	v = v | 0x0011;

	XTESTS_TEST_INTEGER_EQUAL(0x0011, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0011 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0011);

	v = v & 0x000f;

	XTESTS_TEST_INTEGER_EQUAL(0x0001, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0001 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0001);

	v = v << 8;

	XTESTS_TEST_INTEGER_EQUAL(0x0100, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0100 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0100);

	v = v >> 4;

	XTESTS_TEST_INTEGER_EQUAL(0x0010, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0x0010 == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0x0010);

	v = v ^ 0xffff;
	v = v & 0xffff;

	XTESTS_TEST_INTEGER_EQUAL(0xffef, v.get());
	XTESTS_TEST_BOOLEAN_TRUE(0xffef == v);
	XTESTS_TEST_BOOLEAN_TRUE(v == 0xffef);
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
