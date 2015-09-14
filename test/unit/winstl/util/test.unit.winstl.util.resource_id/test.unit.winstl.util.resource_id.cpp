/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.util.resource_id.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.util.resource_id project.
 *
 * Created:     30th August 2014
 * Updated:     30th August 2014
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

#include <winstl/util/resource_id.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_type_exists(void);
    static void test_construct_from_literal(void);
    static void test_construct_from_int_resource(void);
    static void test_copy_construct_from_literal(void);
    static void test_copy_construct_from_int_resource(void);
    static void test_from_number_1(void);
    static void test_from_number_2(void);
    static void test_from_number_3(void);
    static void test_from_number_4(void);
    static void test_parse_as_number_1(void);
    static void test_parse_as_number_2(void);
    static void test_parse_as_number_3(void);
    static void test_less_than_1(void);
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

    if(XTESTS_START_RUNNER("test.unit.winstl.util.resource_id", verbosity))
    {
        XTESTS_RUN_CASE(test_type_exists);
        XTESTS_RUN_CASE(test_construct_from_literal);
        XTESTS_RUN_CASE(test_construct_from_int_resource);
        XTESTS_RUN_CASE(test_copy_construct_from_literal);
        XTESTS_RUN_CASE(test_copy_construct_from_int_resource);
        XTESTS_RUN_CASE(test_from_number_1);
        XTESTS_RUN_CASE(test_from_number_2);
        XTESTS_RUN_CASE(test_from_number_3);
        XTESTS_RUN_CASE(test_from_number_4);
        XTESTS_RUN_CASE(test_parse_as_number_1);
        XTESTS_RUN_CASE(test_parse_as_number_2);
        XTESTS_RUN_CASE(test_parse_as_number_3);
        XTESTS_RUN_CASE(test_less_than_1);
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

static void test_type_exists()
{
    typeid(winstl::resource_id);
    typeid(winstl::resource_id::representation);
}

static void test_construct_from_literal()
{
    winstl::resource_id rid1("MYRESOURCE");

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("MYRESOURCE", rid1);
    XTESTS_TEST_POINTER_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(10u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("MYRESOURCE", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("MYRESOURCE", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_Name, rid1.repr());
}

static void test_construct_from_int_resource()
{
    winstl::resource_id rid1(MAKEINTRESOURCE(33));
    LPCTSTR const       id = reinterpret_cast<LPCTSTR>(33);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1);
    XTESTS_TEST_POINTER_NOT_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(2u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_DecimalString, rid1.repr());
}

static void test_copy_construct_from_literal()
{
    winstl::resource_id rid1("MYRESOURCE");
    winstl::resource_id rid2(rid1);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("MYRESOURCE", rid2);
    XTESTS_TEST_POINTER_EQUAL(rid2.c_str(), rid2.id());
    XTESTS_TEST_INTEGER_EQUAL(10u, rid2.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("MYRESOURCE", rid2.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("MYRESOURCE", rid2.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_Name, rid1.repr());
}

static void test_copy_construct_from_int_resource()
{
    winstl::resource_id rid1(MAKEINTRESOURCE(33));
    winstl::resource_id rid2(rid1);
    LPCTSTR const       id = reinterpret_cast<LPCTSTR>(33);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid2);
    XTESTS_TEST_POINTER_EQUAL(rid2.c_str(), rid2.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(2u, rid2.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid2.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid2.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_DecimalString, rid1.repr());
}

static void test_from_number_1()
{
    winstl::resource_id rid1    =   winstl::resource_id::from_number(33);
    LPCTSTR const       id      =   reinterpret_cast<LPCTSTR>(33);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1);
    XTESTS_TEST_POINTER_NOT_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(2u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_DecimalString, rid1.repr());
}

static void test_from_number_2()
{
    winstl::resource_id rid1    =   winstl::resource_id::from_number(33, winstl::resource_id::Representation_DecimalString);
    LPCTSTR const       id      =   reinterpret_cast<LPCTSTR>(33);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1);
    XTESTS_TEST_POINTER_NOT_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(2u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_DecimalString, rid1.repr());
}

static void test_from_number_3()
{
    winstl::resource_id rid1    =   winstl::resource_id::from_number(33, winstl::resource_id::Representation_HexadecimalString);
    LPCTSTR const       id      =   reinterpret_cast<LPCTSTR>(33);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0x0021", rid1);
    XTESTS_TEST_POINTER_NOT_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(6u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0x0021", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0x0021", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_HexadecimalString, rid1.repr());
}

static void test_from_number_4()
{
    winstl::resource_id rid1    =   winstl::resource_id::from_number(33, winstl::resource_id::Representation_DecimalStringInParentheses);
    LPCTSTR const       id      =   reinterpret_cast<LPCTSTR>(33);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("(33)", rid1);
    XTESTS_TEST_POINTER_NOT_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(4u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("(33)", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("(33)", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_DecimalStringInParentheses, rid1.repr());
}

static void test_parse_as_number_1()
{
    winstl::resource_id::representation repr;
    winstl::resource_id                 rid1    =   winstl::resource_id::parse_as_number("33", &repr);
    LPCTSTR const                       id      =   reinterpret_cast<LPCTSTR>(33);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1);
    XTESTS_TEST_POINTER_NOT_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(2u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("33", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_DecimalString, rid1.repr());
}

static void test_parse_as_number_2()
{
    winstl::resource_id::representation repr;
    winstl::resource_id                 rid1    =   winstl::resource_id::parse_as_number("(234)", &repr);
    LPCTSTR const                       id      =   reinterpret_cast<LPCTSTR>(234);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("(234)", rid1);
    XTESTS_TEST_POINTER_NOT_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(5u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("(234)", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("(234)", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_DecimalStringInParentheses, rid1.repr());
}

static void test_parse_as_number_3()
{
    winstl::resource_id::representation repr;
    winstl::resource_id                 rid1    =   winstl::resource_id::parse_as_number("0x7f34", &repr);
    LPCTSTR const                       id      =   reinterpret_cast<LPCTSTR>(32564);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("0x7f34", rid1);
    XTESTS_TEST_POINTER_NOT_EQUAL(rid1.c_str(), rid1.id());
    XTESTS_TEST_POINTER_EQUAL(id, rid1.id());
    XTESTS_TEST_INTEGER_EQUAL(6u, rid1.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("0x7f34", rid1.c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("0x7f34", rid1.data());
    XTESTS_TEST_ENUM_EQUAL(winstl::resource_id::Representation_HexadecimalString, rid1.repr());
}

static void test_less_than_1()
{
    winstl::resource_id::representation repr1;
    winstl::resource_id::representation repr2;
    winstl::resource_id::representation repr3;

    winstl::resource_id     by_name_1("ABC");
    winstl::resource_id     by_name_2("XYZ");
    winstl::resource_id     by_id_1     =   winstl::resource_id::parse_as_number("24", &repr1);
    winstl::resource_id     by_id_2_a   =   winstl::resource_id::parse_as_number("0x7f34", &repr2);
    winstl::resource_id     by_id_2_b   =   winstl::resource_id::parse_as_number("(32564)", &repr3);

    // name vs name

    XTESTS_TEST_BOOLEAN_TRUE(by_name_1 < by_name_2);
    XTESTS_TEST_BOOLEAN_FALSE(by_name_2 < by_name_1);
    XTESTS_TEST_BOOLEAN_TRUE(by_name_2 > by_name_1);
    XTESTS_TEST_BOOLEAN_FALSE(by_name_1 > by_name_2);

    // id vs id : diff

    XTESTS_TEST_BOOLEAN_TRUE(by_id_1 < by_id_2_a);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_2_a < by_id_1);
    XTESTS_TEST_BOOLEAN_TRUE(by_id_2_a > by_id_1);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_1 > by_id_2_a);

    // id vs id : diff

    XTESTS_TEST_BOOLEAN_TRUE(by_id_1 < by_id_2_b);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_2_b < by_id_1);
    XTESTS_TEST_BOOLEAN_TRUE(by_id_2_b > by_id_1);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_1 > by_id_2_b);

    // id vs id : same

    XTESTS_TEST_BOOLEAN_FALSE(by_id_2_a < by_id_2_b);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_2_b < by_id_2_a);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_2_b > by_id_2_a);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_2_a > by_id_2_b);

    // id vs name

    XTESTS_TEST_BOOLEAN_TRUE(by_id_1 < by_name_2);
    XTESTS_TEST_BOOLEAN_FALSE(by_name_2 < by_id_1);
    XTESTS_TEST_BOOLEAN_TRUE(by_name_2 > by_id_1);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_1 > by_name_2);

    XTESTS_TEST_BOOLEAN_TRUE(by_id_2_a < by_name_1);
    XTESTS_TEST_BOOLEAN_FALSE(by_name_1 < by_id_2_a);
    XTESTS_TEST_BOOLEAN_TRUE(by_name_1 > by_id_2_a);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_2_a > by_name_1);

    XTESTS_TEST_BOOLEAN_TRUE(by_id_2_b < by_name_1);
    XTESTS_TEST_BOOLEAN_FALSE(by_name_1 < by_id_2_b);
    XTESTS_TEST_BOOLEAN_TRUE(by_name_1 > by_id_2_b);
    XTESTS_TEST_BOOLEAN_FALSE(by_id_2_b > by_name_1);

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
