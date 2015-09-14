/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.string_lookup.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.string_lookup project.
 *
 * Created:     8th September 2014
 * Updated:     8th September 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/string/string_lookup.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/string/string_slice.h>
#include <stlsoft/util/dimensionof.h>

/* Standard C++ header files */
#include <map>
#include <string>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_null_input_and_no_lookups(void);
	static void test_null_input_and_several_mappings(void);
	static void test_empty_input_and_several_mappings(void);
	static void test_several_nonmatching_inputs_with_several_lookups(void);
	static void test_several_matching_inputs_with_several_lookups(void);
	static void test_empty_input_and_no_lookups_2(void);
	static void test_empty_input_and_several_mappings_2(void);
	static void test_several_nonmatching_inputs_with_several_lookups_2(void);
	static void test_several_matching_inputs_with_several_lookups_2(void);
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
	static void test_1_20(void);
	static void test_1_21(void);
	static void test_1_22(void);
	static void test_1_23(void);
	static void test_1_24(void);
	static void test_1_25(void);
	static void test_1_26(void);
	static void test_1_27(void);
	static void test_1_28(void);
	static void test_1_29(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.string.string_lookup", verbosity))
	{
		XTESTS_RUN_CASE(test_null_input_and_no_lookups);
		XTESTS_RUN_CASE(test_null_input_and_several_mappings);
		XTESTS_RUN_CASE(test_empty_input_and_several_mappings);
		XTESTS_RUN_CASE(test_several_nonmatching_inputs_with_several_lookups);
		XTESTS_RUN_CASE(test_several_matching_inputs_with_several_lookups);
		XTESTS_RUN_CASE(test_empty_input_and_no_lookups_2);
		XTESTS_RUN_CASE(test_empty_input_and_several_mappings_2);
		XTESTS_RUN_CASE(test_several_nonmatching_inputs_with_several_lookups_2);
		XTESTS_RUN_CASE(test_several_matching_inputs_with_several_lookups_2);
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
		XTESTS_RUN_CASE(test_1_20);
		XTESTS_RUN_CASE(test_1_21);
		XTESTS_RUN_CASE(test_1_22);
		XTESTS_RUN_CASE(test_1_23);
		XTESTS_RUN_CASE(test_1_24);
		XTESTS_RUN_CASE(test_1_25);
		XTESTS_RUN_CASE(test_1_26);
		XTESTS_RUN_CASE(test_1_27);
		XTESTS_RUN_CASE(test_1_28);
		XTESTS_RUN_CASE(test_1_29);

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
    using ::stlsoft::string_lookup;

    using ::stlsoft::string_slice_a_t;
    using ::stlsoft::string_slice_w_t;

    typedef std::string     string_a_t;

    inline
    string_slice_a_t
    make_slice(
        char const* s
    )
    {
        return string_slice_a_t(s, ::strlen(s));
    }


static void test_null_input_and_no_lookups()
{
    string_slice_a_t const* fromMappings    =   NULL;
    string_slice_a_t const* toMappings      =   NULL;

    char const*             input           =   NULL;
    string_slice_a_t const* output;

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup(input, &output, 0, fromMappings, toMappings));
    XTESTS_TEST_POINTER_EQUAL(NULL, output);
}

static void test_null_input_and_several_mappings()
{
    string_slice_a_t const  fromMappings[] =
    {
            make_slice("LocalService")
        ,   make_slice("LocalSystem")
        ,   make_slice("NetworkService")
    };
    string_slice_a_t const  toMappings[] =
    {
            make_slice("NT Authority\\LocalService")
        ,   make_slice("NT Authority\\LocalSystem")
        ,   make_slice("NT Authority\\NetworkService")
    };

    char const*             input   =   NULL;
    string_slice_a_t const* output;

    STLSOFT_STATIC_ASSERT(dimensionof(fromMappings) == dimensionof(toMappings));

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup(input, &output, dimensionof(fromMappings), fromMappings, toMappings));
    XTESTS_TEST_POINTER_EQUAL(NULL, output);
}

static void test_empty_input_and_several_mappings()
{
    string_slice_a_t const  fromMappings[] =
    {
            make_slice("LocalService")
        ,   make_slice("LocalSystem")
        ,   make_slice("NetworkService")
    };
    string_slice_a_t const  toMappings[] =
    {
            make_slice("NT Authority\\LocalService")
        ,   make_slice("NT Authority\\LocalSystem")
        ,   make_slice("NT Authority\\NetworkService")
    };

    char const*             input   =   "";
    string_slice_a_t const* output;

    STLSOFT_STATIC_ASSERT(dimensionof(fromMappings) == dimensionof(toMappings));

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup(input, &output, dimensionof(fromMappings), fromMappings, toMappings));
    XTESTS_TEST_POINTER_EQUAL(NULL, output);
}

static void test_several_nonmatching_inputs_with_several_lookups()
{
    string_slice_a_t const  fromMappings[] =
    {
            make_slice("LocalService")
        ,   make_slice("LocalSystem")
        ,   make_slice("NetworkService")
    };
    string_slice_a_t const  toMappings[] =
    {
            make_slice("NT Authority\\LocalService")
        ,   make_slice("NT Authority\\LocalSystem")
        ,   make_slice("NT Authority\\NetworkService")
    };

    string_slice_a_t const* output;

    STLSOFT_STATIC_ASSERT(dimensionof(fromMappings) == dimensionof(toMappings));

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup("abc", &output, dimensionof(fromMappings), fromMappings, toMappings));
    XTESTS_TEST_POINTER_EQUAL(NULL, output);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup("localservice", &output, dimensionof(fromMappings), fromMappings, toMappings));
    XTESTS_TEST_POINTER_EQUAL(NULL, output);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup("networkservice", &output, dimensionof(fromMappings), fromMappings, toMappings));
    XTESTS_TEST_POINTER_EQUAL(NULL, output);
}

static void test_several_matching_inputs_with_several_lookups()
{
    string_slice_a_t const  fromMappings[] =
    {
            make_slice("LocalService")
        ,   make_slice("LocalSystem")
        ,   make_slice("NetworkService")
    };
    string_slice_a_t const  toMappings[] =
    {
            make_slice("NT Authority\\LocalService")
        ,   make_slice("NT Authority\\LocalSystem")
        ,   make_slice("NT Authority\\NetworkService")
    };

    string_slice_a_t const* output;

    STLSOFT_STATIC_ASSERT(dimensionof(fromMappings) == dimensionof(toMappings));

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::string_lookup("LocalService", &output, dimensionof(fromMappings), fromMappings, toMappings)));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("NT Authority\\LocalService", output->ptr, output->len);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::string_lookup("LocalSystem", &output, dimensionof(fromMappings), fromMappings, toMappings)));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("NT Authority\\LocalSystem", output->ptr, output->len);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::string_lookup("NetworkService", &output, dimensionof(fromMappings), fromMappings, toMappings)));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("NT Authority\\NetworkService", output->ptr, output->len);
}

static void test_empty_input_and_no_lookups_2(void)
{
    string_a_t const    input       =   "";
    string_a_t const    expected    =   "";
    string_a_t          output;

    std::map<
        string_a_t
    ,   string_a_t
    >                   mappings;

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup(input, output, mappings));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(expected, output);
}

static void test_empty_input_and_several_mappings_2(void)
{
    string_a_t const    input       =   "";
    string_a_t          output;

    std::map<
        string_a_t
    ,   string_a_t
    >                   mappings;

    mappings["LocalService"]    =   "NT Authority\\LocalService";
    mappings["LocalSystem"]     =   "NT Authority\\LocalSystem";
    mappings["NetworkService"]  =   "NT Authority\\NetworkService";

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup(input, output, mappings));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", output);
}

static void test_several_nonmatching_inputs_with_several_lookups_2(void)
{
    string_a_t          output;

    std::map<
        string_a_t
    ,   string_a_t
    >                   mappings;

    mappings["LocalService"]    =   "NT Authority\\LocalService";
    mappings["LocalSystem"]     =   "NT Authority\\LocalSystem";
    mappings["NetworkService"]  =   "NT Authority\\NetworkService";

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup("abc", output, mappings));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", output);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup("localservice", output, mappings));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", output);

    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::string_lookup("networkservice", output, mappings));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", output);
}

static void test_several_matching_inputs_with_several_lookups_2()
{
    string_a_t const    input       =   "LocalService";
    string_a_t const    expected    =   "NT Authority\\LocalService";
    string_a_t          output;

    std::map<
        string_a_t
    ,   string_a_t
    >                   mappings;

    mappings["LocalService"]    =   "NT Authority\\LocalService";
    mappings["LocalSystem"]     =   "NT Authority\\LocalSystem";
    mappings["NetworkService"]  =   "NT Authority\\NetworkService";

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::string_lookup("LocalService", output, mappings)));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("NT Authority\\LocalService", output);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::string_lookup("LocalSystem", output, mappings)));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("NT Authority\\LocalSystem", output);

    XTESTS_REQUIRE(XTESTS_TEST_BOOLEAN_TRUE(stlsoft::string_lookup("NetworkService", output, mappings)));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("NT Authority\\NetworkService", output);
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

static void test_1_20()
{
}

static void test_1_21()
{
}

static void test_1_22()
{
}

static void test_1_23()
{
}

static void test_1_24()
{
}

static void test_1_25()
{
}

static void test_1_26()
{
}

static void test_1_27()
{
}

static void test_1_28()
{
}

static void test_1_29()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
