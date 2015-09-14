/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.container.circular_queue_static.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.container.circular_queue_static project.
 *
 * Created:     23rd May 2014
 * Updated:     24th May 2014
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

#include <stlsoft/container/circular_queue_static.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <numeric>
#include <string>

/* Standard C header files */
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_types_exist(void);
    static void test_int_specialisation_construction_default(void);
    static void test_std_string_specialisation_construction_default(void);
    static void test_int_specialisation_construction_default_and_attributes(void);
    static void test_std_string_specialisation_construction_default_and_attributes(void);
    static void test_int_specialisation_construction_default_and_push_back_two_elements(void);
    static void test_int_specialisation_construction_default_and_push_back_five_elements(void);
    static void test_1_5(void);
    static void test_copy_construction_1(void);
    static void test_copy_construction_2(void);
    static void test_copy_construction_3(void);
    static void test_copy_assignment_1(void);
    static void test_copy_assignment_2(void);
    static void test_1_7(void);
    static void test_push_back_and_pop_front_without_wrapping_1(void);
    static void test_std_string_push_back_and_pop_front_without_wrapping_1(void);
    static void test_push_back_and_pop_front_without_wrapping_2(void);
    static void test_std_string_push_back_and_pop_front_without_wrapping_2(void);
    static void test_push_back_and_pop_front_with_wrapping_1(void);
    static void test_std_string_push_back_and_pop_front_with_wrapping_1(void);
    static void test_1_9(void);
    static void test_std_string_huge_volume_and_copy_construct(void);
    static void test_1_11(void);
    static void test_iteration_1(void);
    static void test_iteration_2(void);
    static void test_iteration_3(void);
    static void test_iteration_4(void);
    static void test_iteration_5(void);
    static void test_iteration_6(void);
    static void test_iteration_7(void);
    static void test_iteration_8(void);
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

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    ms;
    _CrtMemCheckpoint(&ms);
#endif

    XTESTS_COMMANDLINE_PARSEVERBOSITY_DEFAULT(argc, argv, &verbosity, 3);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.container.circular_queue_static", verbosity))
    {
        XTESTS_RUN_CASE(test_types_exist);
        XTESTS_RUN_CASE(test_int_specialisation_construction_default);
        XTESTS_RUN_CASE(test_std_string_specialisation_construction_default);
        XTESTS_RUN_CASE(test_int_specialisation_construction_default_and_attributes);
        XTESTS_RUN_CASE(test_std_string_specialisation_construction_default_and_attributes);
        XTESTS_RUN_CASE(test_int_specialisation_construction_default_and_push_back_two_elements);
        XTESTS_RUN_CASE(test_int_specialisation_construction_default_and_push_back_five_elements);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_copy_construction_1);
        XTESTS_RUN_CASE(test_copy_construction_2);
        XTESTS_RUN_CASE(test_copy_construction_3);
        XTESTS_RUN_CASE(test_copy_assignment_1);
        XTESTS_RUN_CASE(test_copy_assignment_2);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_push_back_and_pop_front_without_wrapping_1);
        XTESTS_RUN_CASE(test_std_string_push_back_and_pop_front_without_wrapping_1);
        XTESTS_RUN_CASE(test_push_back_and_pop_front_without_wrapping_2);
        XTESTS_RUN_CASE(test_std_string_push_back_and_pop_front_without_wrapping_2);
        XTESTS_RUN_CASE(test_push_back_and_pop_front_with_wrapping_1);
        XTESTS_RUN_CASE(test_std_string_push_back_and_pop_front_with_wrapping_1);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_std_string_huge_volume_and_copy_construct);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_iteration_1);
        XTESTS_RUN_CASE(test_iteration_2);
        XTESTS_RUN_CASE(test_iteration_3);
        XTESTS_RUN_CASE(test_iteration_4);
        XTESTS_RUN_CASE(test_iteration_5);
        XTESTS_RUN_CASE(test_iteration_6);
        XTESTS_RUN_CASE(test_iteration_7);
        XTESTS_RUN_CASE(test_iteration_8);
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

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&ms);
#endif

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

static void test_types_exist()
{
    typeid(stlsoft::circular_queue_static<1, int>);
    typeid(stlsoft::circular_queue_static<1, std::string>);

    XTESTS_TEST_PASSED();
}

static void test_int_specialisation_construction_default()
{
    stlsoft::circular_queue_static<1, int>  instance;

    XTESTS_TEST_PASSED();
}

static void test_std_string_specialisation_construction_default()
{
    stlsoft::circular_queue_static<1, std::string>  instance;

    XTESTS_TEST_PASSED();
}

static void test_int_specialisation_construction_default_and_attributes()
{
    stlsoft::circular_queue_static<1, int>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());
}

static void test_std_string_specialisation_construction_default_and_attributes()
{
    stlsoft::circular_queue_static<1, std::string>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());
}

static void test_int_specialisation_construction_default_and_push_back_two_elements()
{
    stlsoft::circular_queue_static<2, int>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back(101);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, instance.size()));
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(202);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, instance.size()));
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);

    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
}

static void test_int_specialisation_construction_default_and_push_back_five_elements()
{
    stlsoft::circular_queue_static<2, int>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back(101);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, instance.size()));
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(202);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, instance.size()));
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);

    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(303);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, instance.size()));
    XTESTS_TEST_INTEGER_EQUAL(303, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[0]);

    instance.push_back(404);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, instance.size()));
    XTESTS_TEST_INTEGER_EQUAL(404, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[0]);

    instance.push_back(505);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, instance.size()));
    XTESTS_TEST_INTEGER_EQUAL(505, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(404, instance[0]);
}

static void test_1_5()
{
}

static void test_copy_construction_1()
{
    stlsoft::circular_queue_static<5, int>  instance;

    stlsoft::circular_queue_static<5, int>  instance2(instance);

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());
}

static void test_copy_construction_2()
{
    stlsoft::circular_queue_static<5, int>  instance;

    instance.push_back(101);
    instance.push_back(202);
    instance.push_back(303);
    instance.push_back(404);
    instance.push_back(505);
    instance.push_back(606);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(202, instance[0]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(404, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(505, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(606, instance[4]);

    stlsoft::circular_queue_static<5, int>  instance2(instance);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(202, instance[0]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(404, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(505, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(606, instance[4]);
}

static void test_copy_construction_3()
{
    stlsoft::circular_queue_static<5, std::string>  instance;

    instance.push_back("101");
    instance.push_back("202");
    instance.push_back("303");
    instance.push_back("404");
    instance.push_back("505");
    instance.push_back("606");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("404", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("505", instance[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("606", instance[4]);

    stlsoft::circular_queue_static<5, std::string>  instance2(instance);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("404", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("505", instance[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("606", instance[4]);
}

static void test_copy_assignment_1()
{
    stlsoft::circular_queue_static<5, int>  instance;
    stlsoft::circular_queue_static<5, int>  instance2;

    instance2 = instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());
}

static void test_copy_assignment_2()
{
    stlsoft::circular_queue_static<5, int>  instance;
    stlsoft::circular_queue_static<5, int>  instance2;

    instance.push_back(101);
    instance.push_back(202);
    instance.push_back(303);
    instance.push_back(404);
    instance.push_back(505);
    instance.push_back(606);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(202, instance[0]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(404, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(505, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(606, instance[4]);

    instance2 = instance;

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(202, instance[0]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(404, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(505, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(606, instance[4]);
}

static void test_1_7()
{
}

static void test_push_back_and_pop_front_without_wrapping_1()
{
    stlsoft::circular_queue_static<5, int>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back(101);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.pop_front();

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());
}

static void test_std_string_push_back_and_pop_front_without_wrapping_1()
{
    stlsoft::circular_queue_static<5, std::string>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back("101");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.pop_front();

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());
}

static void test_push_back_and_pop_front_without_wrapping_2()
{
    stlsoft::circular_queue_static<5, int>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back(101);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.pop_front();

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back(101);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(202);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(303);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(303, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(404);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(4u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(404, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(505);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(505, instance[4]);
    XTESTS_TEST_INTEGER_EQUAL(404, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);
}

static void test_std_string_push_back_and_pop_front_without_wrapping_2()
{
    stlsoft::circular_queue_static<5, std::string>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back("101");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.pop_front();

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back("101");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("202");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("303");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("404");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(4u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("404", instance[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("505");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("505", instance[4]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("404", instance[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);
}

static void test_push_back_and_pop_front_with_wrapping_1()
{
    stlsoft::circular_queue_static<5, int>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back(101);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.pop_front();

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back(101);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(202);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(303);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(303, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(404);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(4u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(404, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(505);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(505, instance[4]);
    XTESTS_TEST_INTEGER_EQUAL(404, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(101, instance[0]);

    instance.push_back(606);

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_INTEGER_EQUAL(606, instance[4]);
    XTESTS_TEST_INTEGER_EQUAL(505, instance[3]);
    XTESTS_TEST_INTEGER_EQUAL(404, instance[2]);
    XTESTS_TEST_INTEGER_EQUAL(303, instance[1]);
    XTESTS_TEST_INTEGER_EQUAL(202, instance[0]);
}

static void test_std_string_push_back_and_pop_front_with_wrapping_1()
{
    stlsoft::circular_queue_static<5, std::string>  instance;

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back("101");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.pop_front();

    XTESTS_TEST_BOOLEAN_TRUE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, instance.size());

    instance.push_back("101");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("202");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("303");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("404");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(4u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("404", instance[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("505");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("505", instance[4]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("404", instance[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("101", instance[0]);

    instance.push_back("606");

    XTESTS_TEST_BOOLEAN_FALSE(instance.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, instance.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("606", instance[4]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("505", instance[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("404", instance[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("303", instance[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("202", instance[0]);
}

static void test_1_9()
{
}

static void test_std_string_huge_volume_and_copy_construct()
{
    stlsoft::circular_queue_static<100, std::string>    q;

    { for(size_t i = 0; i != 10000; ++i)
    {
        char                num[21];
        size_t              n;
        char const* const   s = ::stlsoft::integer_to_decimal_string(&num[0], STLSOFT_NUM_ELEMENTS(num), i, &n);

        std::string const   v(s, n);

        q.push_back(v);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(v, q.back());
    }}

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(q.max_size(), q.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("9900", q.front());
    { for(size_t i = 9900; 10000 != i; ++i)
    {
        char                num[21];
        size_t              n;
        char const* const   s = ::stlsoft::integer_to_decimal_string(&num[0], STLSOFT_NUM_ELEMENTS(num), i, &n);

        std::string const   v(s, n);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(v, q[i - 9900]);
    }}
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("9999", q.back());
}

static void test_1_11()
{
}

static void test_iteration_1()
{
    stlsoft::circular_queue_static<10, int> q;

    XTESTS_TEST_BOOLEAN_TRUE(q.end() == q.begin());
    XTESTS_TEST_BOOLEAN_FALSE(q.end() != q.begin());
    XTESTS_TEST_BOOLEAN_FALSE(q.end() < q.begin());
    XTESTS_TEST_BOOLEAN_FALSE(q.end() > q.begin());
    XTESTS_TEST_BOOLEAN_TRUE(q.end() <= q.begin());
    XTESTS_TEST_BOOLEAN_TRUE(q.end() >= q.begin());
    XTESTS_TEST_INTEGER_EQUAL(0, q.end() - q.begin());
}

static void test_iteration_2()
{
    stlsoft::circular_queue_static<10, int> q;

    q.push_back(101);

    XTESTS_TEST_BOOLEAN_FALSE(q.end() == q.begin());
    XTESTS_TEST_BOOLEAN_TRUE(q.end() != q.begin());
    XTESTS_TEST_BOOLEAN_FALSE(q.end() < q.begin());
    XTESTS_TEST_BOOLEAN_TRUE(q.end() > q.begin());
    XTESTS_TEST_BOOLEAN_FALSE(q.end() <= q.begin());
    XTESTS_TEST_BOOLEAN_TRUE(q.end() >= q.begin());
    XTESTS_TEST_INTEGER_EQUAL(1, q.end() - q.begin());

    XTESTS_TEST_INTEGER_EQUAL(101, *q.begin());
}

static void test_iteration_3()
{
    stlsoft::circular_queue_static<10, int> q;

    q.push_back(101);
    q.push_back(202);
    q.push_back(303);

    XTESTS_TEST_INTEGER_EQUAL(606, std::accumulate(q.begin(), q.end(), 0));
}

static void test_iteration_4()
{
    stlsoft::circular_queue_static<10, int> q;

    q.push_back(101);
    q.push_back(202);
    q.push_back(303);

    stlsoft::circular_queue_static<10, int>::const_iterator         b = q.begin();
    stlsoft::circular_queue_static<10, int>::const_iterator const   e = q.end();

    XTESTS_TEST_INTEGER_EQUAL(606, std::accumulate(b, e, 0));
}

static void test_iteration_5()
{
    stlsoft::circular_queue_static<10, int> q;

    q.push_back(101);
    q.push_back(202);
    q.push_back(303);

    stlsoft::circular_queue_static<10, int>::const_iterator         b = q.begin();
    stlsoft::circular_queue_static<10, int>::const_iterator         e = q.end();

    int total = 0;

    total += *b++;
    total += *b++;
    total += *b++;

    XTESTS_TEST_INTEGER_EQUAL(606, total);

    int rtotal = 0;

    rtotal += *--e;
    rtotal += *--e;
    rtotal += *--e;

    XTESTS_TEST_INTEGER_EQUAL(606, total);
}

static void test_iteration_6()
{
    stlsoft::circular_queue_static<10, int> q;

    q.push_back(101);
    q.push_back(202);
    q.push_back(303);

    stlsoft::circular_queue_static<10, int>::const_iterator         b = q.begin();
    stlsoft::circular_queue_static<10, int>::const_iterator         e = q.end();

    int total = 0;

    total   +=  *b;
    b       +=  1;
    total   +=  *b;
    b       +=  1;
    total   +=  *b;
    b       +=  1;

    XTESTS_TEST_INTEGER_EQUAL(606, total);
    XTESTS_TEST_BOOLEAN_TRUE(q.end() == b);

    int rtotal = 0;

    e       -=  1;
    rtotal  +=  *e;
    e       -=  1;
    rtotal  +=  *e;
    e       -=  1;
    rtotal  +=  *e;

    XTESTS_TEST_INTEGER_EQUAL(606, total);
    XTESTS_TEST_BOOLEAN_TRUE(q.begin() == e);
}

static void test_iteration_7()
{
    stlsoft::circular_queue_static<10, int> q;

    q.push_back(101);
    q.push_back(202);
    q.push_back(303);

    stlsoft::circular_queue_static<10, int>::const_iterator         b = q.begin();
    stlsoft::circular_queue_static<10, int>::const_iterator         e = q.end();

    int total = 0;

    total   +=  *(b + 0);
    total   +=  *(b + 1);
    total   +=  *(b + 2);

    XTESTS_TEST_INTEGER_EQUAL(606, total);

    int rtotal = 0;

    rtotal  +=  *(e - 1);
    rtotal  +=  *(e - 2);
    rtotal  +=  *(e - 3);

    XTESTS_TEST_INTEGER_EQUAL(606, total);
}

static void test_iteration_8()
{
    stlsoft::circular_queue_static<10, int> q;

    q.push_back(101);
    q.push_back(202);
    q.push_back(303);

    stlsoft::circular_queue_static<10, int>::const_iterator         b = q.begin();
    stlsoft::circular_queue_static<10, int>::const_iterator         e = q.end();

    int total = 0;

    total   +=  b[0];
    total   +=  b[1];
    total   +=  b[2];

    XTESTS_TEST_INTEGER_EQUAL(606, total);

    int rtotal = 0;

    rtotal  +=  e[-1];
    rtotal  +=  e[-2];
    rtotal  +=  e[-3];

    XTESTS_TEST_INTEGER_EQUAL(606, total);
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
