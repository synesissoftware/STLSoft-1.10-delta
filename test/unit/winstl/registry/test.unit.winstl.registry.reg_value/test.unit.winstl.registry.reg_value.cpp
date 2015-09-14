/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.registry.reg_value.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.registry.reg_value project.
 *
 * Created:     23rd February 2009
 * Updated:     21st June 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#ifdef __GNUC__
# include <comstl/util/guid.hpp>
#endif

#include <winstl/registry/reg_value.hpp>

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
#include <stlsoft/conversion/integer_to_string.hpp>
#include <comstl/util/guid.hpp>
#include <winstl/registry/reg_key.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

#if 0
    static void test_missing_value(void);
#endif /* 0 */
    static void test_none_value(void);
    static void test_0_dword(void);
    static void test_empty_string(void);
    static void test_many_dwords(void);
    static void test_many_strings(void);
    static void test_empty_multistring(void);
    static void test_multistring_multibyte(void);
	static void test_multistring_wide(void);
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
 * Helper functions
 */

namespace
{
    static winstl::reg_key* rootKey;
}

static int setup(void* /* arg */)
{
    try
    {
        rootKey = new winstl::reg_key(winstl::reg_key::create_key(HKEY_CURRENT_USER, "SOFTWARE\\Synesis Software\\freelibs\\STLSoft\\test\\test.unit.winstl.registry.reg_value"));

        return 0;
    }
    catch(winstl::registry_exception& x)
    {
        fprintf(stderr, "setup() failed to create registry key: %s: %d\n", x.what(), x.get_error_code());

        return -1;
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "setup() failed to create registry key: %s\n", x.what());

        return -1;
    }
}

static int teardown(void* /* arg */)
{
    winstl::reg_traits<char>::reg_delete_tree(rootKey->get(), "");

    delete rootKey;
    rootKey = NULL;

    return 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.unit.winstl.registry.reg_value", verbosity, setup, teardown, NULL))
    {
#if 0
        XTESTS_RUN_CASE_THAT_THROWS(test_missing_value, winstl::registry_exception);
#endif /* 0 */
        XTESTS_RUN_CASE(test_none_value);
        XTESTS_RUN_CASE(test_0_dword);
        XTESTS_RUN_CASE(test_empty_string);
        XTESTS_RUN_CASE(test_many_dwords);
        XTESTS_RUN_CASE(test_many_strings);
        XTESTS_RUN_CASE(test_empty_multistring);
        XTESTS_RUN_CASE(test_multistring_multibyte);
		XTESTS_RUN_CASE(test_multistring_wide);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/reg_value.hpp", NULL);
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

    std::string get_value_name(char const* root, size_t n)
    {
        char    buff[21];

        return std::string(root) + "-" + stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), n);
    }


#if 0
static void test_missing_value()
{
#if 0
    {
        char    key_class[100];
        size_t  cch_key_class = STLSOFT_NUM_ELEMENTS(key_class);
        LONG    res;

        res = winstl::reg_traits<char>::reg_query_info(rootKey->get(), &key_class[0], &cch_key_class, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

        res = winstl::reg_traits<char>::reg_query_info(rootKey->get(), &key_class[0], NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }
#endif /* 0 */

    const comstl::guid  guid;

    rootKey->get_value(guid).value_sz();
}
#endif /* 0 */

static void test_none_value()
{
    const comstl::guid  guid;

    ::RegSetValueEx(rootKey->get(), stlsoft::c_str_ptr(guid), 0, REG_NONE, NULL, 0);

    XTESTS_TEST_INTEGER_EQUAL(DWORD(REG_NONE), rootKey->get_value(guid).type());
}

static void test_0_dword()
{
    const comstl::guid  guid;
    const DWORD         value = 0u;

    rootKey->set_value(guid, value);

    XTESTS_TEST_INTEGER_EQUAL(DWORD(REG_DWORD), rootKey->get_value(guid).type());
    XTESTS_TEST_INTEGER_EQUAL(value, rootKey->get_value(guid).value_dword());
}

static void test_empty_string()
{
    const comstl::guid  guid;
    char const* const   value = "";

    rootKey->set_value(guid, value);

    XTESTS_TEST_INTEGER_EQUAL(DWORD(REG_SZ), rootKey->get_value(guid).type());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(value, rootKey->get_value(guid).value_sz());
}

static void test_many_dwords()
{
    const DWORD values[] = { 0, 3, 10, 30, 100, 300, 1000, 3000, 10000, 30000, 100000, 300000, 1000000, 3000000, 10000000, 30000000, 100000000, 300000000, 1000000000, 3000000000u, };

    { for(unsigned i = 0; i != 10; ++i)
    {
        const comstl::guid  guid;

        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(values); ++j)
        {
            const DWORD value = values[j];

            rootKey->set_value(get_value_name(stlsoft::c_str_ptr(guid), j), value);
        }}

        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(values); ++j)
        {
            const DWORD value = values[j];

            XTESTS_TEST_INTEGER_EQUAL(DWORD(REG_DWORD), rootKey->get_value(get_value_name(stlsoft::c_str_ptr(guid), j)).type());
            XTESTS_TEST_INTEGER_EQUAL(value, rootKey->get_value(get_value_name(stlsoft::c_str_ptr(guid), j)).value_dword());
        }}
    }}
}

static void test_many_strings()
{
    char const* values[] = { "0", "3", "10", "30", "100", "300", "1000", "3000", "10000", "30000", "100000", "300000", "1000000", "3000000", "10000000", "30000000", "100000000", "300000000", "1000000000", "3000000000", };

    { for(unsigned i = 0; i != 10; ++i)
    {
        const comstl::guid  guid;

        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(values); ++j)
        {
            char const* value = values[j];

            rootKey->set_value(get_value_name(stlsoft::c_str_ptr(guid), j), value);
        }}

        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(values); ++j)
        {
            char const* value = values[j];

            XTESTS_TEST_INTEGER_EQUAL(DWORD(REG_SZ), rootKey->get_value(get_value_name(stlsoft::c_str_ptr(guid), j)).type());
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL(value, rootKey->get_value(get_value_name(stlsoft::c_str_ptr(guid), j)).value_sz());
        }}
    }}
}


static void test_empty_multistring()
{
    const comstl::guid  guid;
    char const**        value = NULL;

    rootKey->set_value(guid, value, 0);

    XTESTS_TEST_INTEGER_EQUAL(DWORD(REG_MULTI_SZ), rootKey->get_value(guid).type());
    XTESTS_TEST_INTEGER_EQUAL(0u, rootKey->get_value(guid).value_multi_sz().size());
}

static void test_multistring_multibyte()
{
    char const* values[] = { "0", "3", "10", "30", "100", "300", "1000", "3000", "10000", "30000", "100000", "300000", "1000000", "3000000", "10000000", "30000000", "100000000", "300000000", "1000000000", "3000000000", };

    const comstl::guid  guid;

    rootKey->set_value(guid, values, STLSOFT_NUM_ELEMENTS(values));

    XTESTS_TEST_INTEGER_EQUAL(DWORD(REG_MULTI_SZ), rootKey->get_value(guid).type());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(values), rootKey->get_value(guid).value_multi_sz().size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(values[i], rootKey->get_value(guid).value_multi_sz()[i]);
    }}
}

static void test_multistring_wide()
{
    wchar_t const* values[] = { L"0", L"3", L"10", L"30", L"100", L"300", L"1000", L"3000", L"10000", L"30000", L"100000", L"300000", L"1000000", L"3000000", L"10000000", L"30000000", L"100000000", L"300000000", L"1000000000", L"3000000000", };

    const comstl::guid  guid;

	winstl::reg_key_w	key(rootKey->get(), L"");

    key.set_value(stlsoft::c_str_ptr_w(guid), values, STLSOFT_NUM_ELEMENTS(values));

    XTESTS_TEST_INTEGER_EQUAL(DWORD(REG_MULTI_SZ), key.get_value(stlsoft::c_str_ptr_w(guid)).type());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(values), key.get_value(stlsoft::c_str_ptr_w(guid)).value_multi_sz().size()));
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        XTESTS_TEST_WIDE_STRING_EQUAL(values[i], key.get_value(stlsoft::c_str_ptr_w(guid)).value_multi_sz()[i]);
    }}
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
