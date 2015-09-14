/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.comstl.shims.access.string.VARIANT.cpp
 *
 * Purpose:     Implementation file for the test.unit.comstl.shims.access.string.VARIANT project.
 *
 * Created:     15th October 2008
 * Updated:     21st June 2010
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

#include <comstl/shims/access/string/VARIANT.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <comstl/auto/functions.h>
#include <comstl/util/creation_functions.hpp>
#include <comstl/util/variant.hpp>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <winstl/error/error_desc.hpp>
#include <winstl/shims/access/string/time.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <float.h>
#include <limits.h>
#include <stdlib.h>
#include <tchar.h>

/* /////////////////////////////////////////////////////////////////////////
 * Features
 */

#define FIXED_SEED      (101)

#ifdef UNICODE
# define XTESTS_TEST_T_STRING_EQUAL_            XTESTS_TEST_WIDE_STRING_EQUAL
# define XTESTS_TEST_T_STRING_EQUAL_APPROX_     XTESTS_TEST_WIDE_STRING_EQUAL_APPROX
# define XTESTS_TEST_T_STRING_CONTAIN_          XTESTS_TEST_WIDE_STRING_CONTAIN
#else /* ? UNICODE */
# define XTESTS_TEST_T_STRING_EQUAL_            XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_T_STRING_EQUAL_APPROX_     XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX
# define XTESTS_TEST_T_STRING_CONTAIN_          XTESTS_TEST_MULTIBYTE_STRING_CONTAIN
#endif /* UNICODE */


typedef std::string                             string_t;
typedef std::wstring                            wstring_t;
#ifdef UNICODE
typedef std::wstring                            tstring_t;
#else /* ? UNICODE */
typedef std::string                             tstring_t;
#endif /* UNICODE */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_calls_possible(void);
    static void test_VT_EMPTY(void);
    static void test_VT_NULL(void);
    static void test_VT_BOOL(void);
    static void test_VT_I1(void);
    static void test_VT_I2(void);
    static void test_VT_I4(void);
    static void test_VT_UI1(void);
    static void test_VT_UI2(void);
    static void test_VT_UI4(void);
    static void test_VT_DATE(void);
    static void test_VT_BSTR(void);
    static void test_VT_DISPATCH(void);
    static void test_VT_LPUNKNOWN(void);
    static void test_VT_DECIMAL(void);
    static void test_VT_VARIANT(void);
    static void test_VT_CY(void);
    static void test_VT_R4(void);
    static void test_VT_R8(void);
    static void test_VT_ERROR(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    ::OleInitialize(NULL);

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.comstl.shims.access.string.VARIANT", verbosity))
    {
        XTESTS_RUN_CASE(test_calls_possible);
        XTESTS_RUN_CASE(test_VT_EMPTY);
        XTESTS_RUN_CASE(test_VT_NULL);
        XTESTS_RUN_CASE(test_VT_BOOL);
        XTESTS_RUN_CASE(test_VT_I1);
        XTESTS_RUN_CASE(test_VT_I2);
        XTESTS_RUN_CASE(test_VT_I4);
        XTESTS_RUN_CASE(test_VT_UI1);
        XTESTS_RUN_CASE(test_VT_UI2);
        XTESTS_RUN_CASE(test_VT_UI4);
        XTESTS_RUN_CASE(test_VT_DATE);
        XTESTS_RUN_CASE(test_VT_BSTR);
        XTESTS_RUN_CASE(test_VT_DISPATCH);
        XTESTS_RUN_CASE(test_VT_LPUNKNOWN);
        XTESTS_RUN_CASE(test_VT_DECIMAL);
        XTESTS_RUN_CASE(test_VT_VARIANT);
        XTESTS_RUN_CASE(test_VT_CY);
        XTESTS_RUN_CASE(test_VT_R4);
        XTESTS_RUN_CASE(test_VT_R8);
        XTESTS_RUN_CASE(test_VT_ERROR);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

namespace
{
    // Multibyte

    string_t invoke_c_str_data_a_(char const* s, size_t len)
    {
        if(NULL == s)
        {
            return string_t();
        }
        else
        {
            return string_t(s, len);
        }
    }
    string_t invoke_c_str_data_a(VARIANT const& var)
    {
        return invoke_c_str_data_a_(::stlsoft::c_str_data_a(var), ::stlsoft::c_str_len_a(var));
    }


    // Wide

    wstring_t invoke_c_str_data_w_(wchar_t const* s, size_t len)
    {
        if(NULL == s)
        {
            return wstring_t();
        }
        else
        {
            return wstring_t(s, len);
        }
    }
    wstring_t invoke_c_str_data_w(VARIANT const& var)
    {
        return invoke_c_str_data_w_(::stlsoft::c_str_data_w(var), ::stlsoft::c_str_len_w(var));
    }


    // Ambient

    tstring_t invoke_c_str_data_(TCHAR const* s, size_t len)
    {
        if(NULL == s)
        {
            return tstring_t();
        }
        else
        {
            return tstring_t(s, len);
        }
    }
    tstring_t invoke_c_str_data(VARIANT const& var)
    {
        return invoke_c_str_data_(::stlsoft::c_str_data(var), ::stlsoft::c_str_len(var));
    }


} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

static void test_calls_possible()
{
    VARIANT var;

    ::VariantInit(&var);

    stlsoft::c_str_data_a(var);
    stlsoft::c_str_data_w(var);
    stlsoft::c_str_data(var);

    stlsoft::c_str_len_a(var);
    stlsoft::c_str_len_w(var);
    stlsoft::c_str_len(var);

    stlsoft::c_str_ptr_a(var);
    stlsoft::c_str_ptr_w(var);
    stlsoft::c_str_ptr(var);

    stlsoft::c_str_ptr_null_a(var);
    stlsoft::c_str_ptr_null_w(var);
    stlsoft::c_str_ptr_null(var);

    XTESTS_TEST_PASSED();
}

static void test_VT_EMPTY()
{
    VARIANT var;

    ::VariantInit(&var);

    XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_EMPTY), var.vt);

    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_a(var));
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_w(var));
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len(var));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", invoke_c_str_data_a(var));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"", invoke_c_str_data_w(var));
    XTESTS_TEST_T_STRING_EQUAL_(TEXT(""), invoke_c_str_data(var));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_ptr_a(var));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_ptr_w(var));
    XTESTS_TEST_T_STRING_EQUAL_(TEXT(""), stlsoft::c_str_ptr(var));

    XTESTS_TEST_POINTER_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
    XTESTS_TEST_POINTER_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
    XTESTS_TEST_POINTER_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));
}

static void test_VT_NULL()
{
    VARIANT var;

    ::VariantInit(&var);

    var.vt = VT_NULL;

    XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_NULL), var.vt);

    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_a(var));
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_w(var));
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len(var));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", invoke_c_str_data_a(var));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"", invoke_c_str_data_w(var));
    XTESTS_TEST_T_STRING_EQUAL_(TEXT(""), invoke_c_str_data(var));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_ptr_a(var));
    XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_ptr_w(var));
    XTESTS_TEST_T_STRING_EQUAL_(TEXT(""), stlsoft::c_str_ptr(var));

    XTESTS_TEST_POINTER_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
    XTESTS_TEST_POINTER_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
    XTESTS_TEST_POINTER_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));
}

static void test_VT_BOOL()
{
    VARIANT var;
    VARIANT copy;

    ::VariantInit(&var);
    ::VariantInit(&copy);

    var.vt  =   VT_BOOL;

    HRESULT hr;

    // True
    var.boolVal =   VARIANT_TRUE;

    hr = ::VariantChangeType(&copy, &var, VARIANT_ALPHABOOL, VT_BSTR);
    if(FAILED(hr))
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("failed to convert source variant", winstl::error_desc_a(hr).c_str());
    }
    else
    {
        stlsoft::scoped_handle<VARIANT*> scoper(&copy, ::VariantClear);

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_BOOL), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(4u, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(4u, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(4u, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("true", invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"true", invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_APPROX_(TEXT("true"), invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("true", stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"true", stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_APPROX_(TEXT("true"), stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_POINTER_NOT_EQUAL("true", stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(L"true", stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(TEXT("true"), stlsoft::c_str_ptr_null(var));
    }

    // False
    var.boolVal = VARIANT_FALSE;

    hr = ::VariantChangeType(&copy, &var, VARIANT_ALPHABOOL, VT_BSTR);
    if(FAILED(hr))
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("failed to convert source variant", winstl::error_desc_a(hr).c_str());
    }
    else
    {
        stlsoft::scoped_handle<VARIANT*> scoper(&copy, ::VariantClear);

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_BOOL), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(5u, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(5u, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(5u, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("false", invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"false", invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_APPROX_(TEXT("false"), invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("false", stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"false", stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_APPROX_(TEXT("false"), stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_POINTER_NOT_EQUAL("false", stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(L"false", stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(TEXT("false"), stlsoft::c_str_ptr_null(var));
    }
}

static void test_VT_I1()
{
    VARIANT var;

    ::VariantInit(&var);

    const signed char values[] = { SCHAR_MIN, -100, -50, -6, -1, 0, 3, 10, 99, 101, SCHAR_MAX };

    var.vt = VT_I1;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var.cVal    =   CHAR(values[i]);

        char            num_a[21];
        wchar_t         num_w[21];
        TCHAR           num[21];
        size_t          cch_a;
        size_t          cch_w;
        size_t          cch;
        char const*     s_a = stlsoft::integer_to_string(&num_a[0], STLSOFT_NUM_ELEMENTS(num_a), values[i], cch_a);
        wchar_t const*  s_w = stlsoft::integer_to_string(&num_w[0], STLSOFT_NUM_ELEMENTS(num_w), values[i], cch_w);
        TCHAR const*    s   = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), values[i], cch);

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_I1), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(cch_a, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(cch_w, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(cch, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(s_a, stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s_w, stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s, stlsoft::c_str_ptr_null(var));
    }}
}

static void test_VT_I2()
{
    VARIANT var;

    ::VariantInit(&var);

    const short values[] = { SHRT_MIN, -20000, -3000, -400, -50, -6, -1, 0, 3, 10, 99, 271, 7871, SHRT_MAX };

    var.vt = VT_I2;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var.iVal    =   values[i];

        char            num_a[21];
        wchar_t         num_w[21];
        TCHAR           num[21];
        size_t          cch_a;
        size_t          cch_w;
        size_t          cch;
        char const*     s_a = stlsoft::integer_to_string(&num_a[0], STLSOFT_NUM_ELEMENTS(num_a), values[i], cch_a);
        wchar_t const*  s_w = stlsoft::integer_to_string(&num_w[0], STLSOFT_NUM_ELEMENTS(num_w), values[i], cch_w);
        TCHAR const*    s   = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), values[i], cch);

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_I2), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(cch_a, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(cch_w, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(cch, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(s_a, stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s_w, stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s, stlsoft::c_str_ptr_null(var));
    }}
}

static void test_VT_I4()
{
    VARIANT var;

    ::VariantInit(&var);

    const int values[] = { INT_MIN, -43434534, -20000, -3000, -400, -50, -6, -1, 0, 3, 10, 99, 271, 7871, 3434534, INT_MAX };

    var.vt = VT_I4;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var.lVal    =   values[i];

        char            num_a[21];
        wchar_t         num_w[21];
        TCHAR           num[21];
        size_t          cch_a;
        size_t          cch_w;
        size_t          cch;
        char const*     s_a = stlsoft::integer_to_string(&num_a[0], STLSOFT_NUM_ELEMENTS(num_a), values[i], cch_a);
        wchar_t const*  s_w = stlsoft::integer_to_string(&num_w[0], STLSOFT_NUM_ELEMENTS(num_w), values[i], cch_w);
        TCHAR const*    s   = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), values[i], cch);

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_I4), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(cch_a, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(cch_w, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(cch, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(s_a, stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s_w, stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s, stlsoft::c_str_ptr_null(var));
    }}
}

static void test_VT_UI1()
{
    VARIANT var;

    ::VariantInit(&var);

    const unsigned char values[] = { 0, 3, 10, 99, 101, UCHAR_MAX };

    var.vt = VT_UI1;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var.cVal    =   CHAR(values[i]);

        char            num_a[21];
        wchar_t         num_w[21];
        TCHAR           num[21];
        size_t          cch_a;
        size_t          cch_w;
        size_t          cch;
        char const*     s_a = stlsoft::integer_to_string(&num_a[0], STLSOFT_NUM_ELEMENTS(num_a), values[i], cch_a);
        wchar_t const*  s_w = stlsoft::integer_to_string(&num_w[0], STLSOFT_NUM_ELEMENTS(num_w), values[i], cch_w);
        TCHAR const*    s   = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), values[i], cch);

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_UI1), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(cch_a, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(cch_w, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(cch, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(s_a, stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s_w, stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s, stlsoft::c_str_ptr_null(var));
    }}
}

static void test_VT_UI2()
{
    VARIANT var;

    ::VariantInit(&var);

    const unsigned short values[] = { 0, 3, 10, 99, 271, 7871, 20000, USHRT_MAX };

    var.vt = VT_UI2;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var.uiVal = values[i];

        char            num_a[21];
        wchar_t         num_w[21];
        TCHAR           num[21];
        size_t          cch_a;
        size_t          cch_w;
        size_t          cch;
        char const*     s_a = stlsoft::integer_to_string(&num_a[0], STLSOFT_NUM_ELEMENTS(num_a), values[i], cch_a);
        wchar_t const*  s_w = stlsoft::integer_to_string(&num_w[0], STLSOFT_NUM_ELEMENTS(num_w), values[i], cch_w);
        TCHAR const*    s   = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), values[i], cch);

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_UI2), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(cch_a, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(cch_w, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(cch, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(s_a, stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s_w, stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s, stlsoft::c_str_ptr_null(var));
    }}
}

static void test_VT_UI4()
{
    VARIANT var;

    ::VariantInit(&var);

    const unsigned int values[] = { 0, 1, 3, 6, 10, 50, 99, 271, 400, 7871, 3000, 20000, 3434534, 43434534, UINT_MAX };

    var.vt = VT_UI4;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var.ulVal = values[i];

        char            num_a[21];
        wchar_t         num_w[21];
        TCHAR           num[21];
        size_t          cch_a;
        size_t          cch_w;
        size_t          cch;
        char const*     s_a = stlsoft::integer_to_string(&num_a[0], STLSOFT_NUM_ELEMENTS(num_a), values[i], cch_a);
        wchar_t const*  s_w = stlsoft::integer_to_string(&num_w[0], STLSOFT_NUM_ELEMENTS(num_w), values[i], cch_w);
        TCHAR const*    s   = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), values[i], cch);

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_UI4), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(cch_a, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(cch_w, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(cch, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(s_w, stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(s, stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(s_a, stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s_w, stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(s, stlsoft::c_str_ptr_null(var));
    }}
}

static void test_VT_DATE()
{
    SYSTEMTIME  now;
    DATE        varTime;

    ::GetLocalTime(&now);
    if(0 == ::SystemTimeToVariantTime(&now, &varTime))
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("Failed to convert current time to variant time", winstl::error_desc_a(::GetLastError()).c_str());
    }
    else
    {
        VARIANT var;

        ::VariantInit(&var);

        var.vt      =   VT_DATE;
        var.date    =   varTime;

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_DATE), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(winstl::c_str_len_a(now), stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(winstl::c_str_len_w(now), stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(winstl::c_str_len(now), stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(winstl::c_str_data_a(now), invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(winstl::c_str_data_w(now), invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(winstl::c_str_data(now), invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(winstl::c_str_ptr_a(now), stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(winstl::c_str_ptr_w(now), stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(winstl::c_str_ptr(now), stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(winstl::c_str_ptr_null_a(now), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(winstl::c_str_ptr_null_w(now), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(winstl::c_str_ptr_null(now), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(winstl::c_str_ptr_null_a(now), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(winstl::c_str_ptr_null_w(now), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(winstl::c_str_ptr_null(now), stlsoft::c_str_ptr_null(var));
    }
}

static void test_VT_BSTR()
{
    typedef char const* ccs_t;

    static const ccs_t strings[] =
    {
        "", "a", "ab", "abc", "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 
    };

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(strings); ++i)
    {
        VARIANT var;

        ::VariantInit(&var);

        var.vt      =   VT_BSTR;
        var.bstrVal =   comstl::bstr_create_a(strings[i]);

        if(NULL == var.bstrVal)
        {
            XTESTS_TEST_FAIL("failed to allocate BSTR");
        }
        else
        {
            stlsoft::scoped_handle<VARIANT*>    scoper(&var, ::VariantClear);

            XTESTS_TEST_INTEGER_EQUAL(::strlen(strings[i]), stlsoft::c_str_len_a(var));
        }
    }}
}

static void test_VT_DISPATCH()
{
    stlsoft::ref_ptr<IDispatch>     autobj;
    HRESULT                         hr = comstl::co_create_instance(L"SynesisSoftware.CoTest.Value", autobj);

    if(FAILED(hr))
    {
//      XTESTS_TEST_ISSUE_WARNING("failed to create CoClass \"SynesisSoftware.CoTest.Value\"" - get an updated version from http://synesis.com.au/software");
    }
    else
    {
        // Succeeded, so set its value and 

        const comstl::variant   value(-1.2345);

        hr = comstl::IDispatch_put_property(autobj.get(), 1, value);

        if(FAILED(hr))
        {
//          XTESTS_TEST_ISSUE_WARNING("failed to set property 1 of CoClass \"SynesisSoftware.CoTest.Value\"" - get an updated version from http://synesis.com.au/software");
        }
        else
        {
            VARIANT var;

            var.vt          =   VT_DISPATCH;
            var.pdispVal    =   autobj.get();

            var.pdispVal->AddRef();

            stlsoft::scoped_handle<VARIANT*>    scoper(&var, ::VariantClear);

            XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len_a(var));
            XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len_w(var));
            XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len(var));

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("-1.2345", invoke_c_str_data_a(var));
            XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"-1.2345", invoke_c_str_data_w(var));
            XTESTS_TEST_T_STRING_EQUAL_APPROX_(TEXT("-1.2345"), invoke_c_str_data(var));

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("-1.2345", stlsoft::c_str_ptr_a(var));
            XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"-1.2345", stlsoft::c_str_ptr_w(var));
            XTESTS_TEST_T_STRING_EQUAL_APPROX_(TEXT("-1.2345"), stlsoft::c_str_ptr(var));

            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

            XTESTS_TEST_POINTER_NOT_EQUAL("-1.2345", stlsoft::c_str_ptr_null_a(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(L"-1.2345", stlsoft::c_str_ptr_null_w(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(TEXT("-1.2345"), stlsoft::c_str_ptr_null(var));
        }
    }
}

static void test_VT_LPUNKNOWN()
{
    stlsoft::ref_ptr<IDispatch>     autobj;
    HRESULT                         hr = comstl::co_create_instance(L"SynesisSoftware.CoTest.Value", autobj);

    if(FAILED(hr))
    {
//      XTESTS_TEST_ISSUE_WARNING("failed to create CoClass \"SynesisSoftware.CoTest.Value\"" - get an updated version from http://synesis.com.au/software");
    }
    else
    {
        // Succeeded, so set its value and 

        const comstl::variant   value(-1.2345);

        hr = comstl::IDispatch_put_property(autobj.get(), 1, value);

        if(FAILED(hr))
        {
//          XTESTS_TEST_ISSUE_WARNING("failed to set property 1 of CoClass \"SynesisSoftware.CoTest.Value\"" - get an updated version from http://synesis.com.au/software");
        }
        else
        {
            VARIANT var;

            var.vt      =   VT_UNKNOWN;
            var.punkVal =   autobj.get();

            var.punkVal->AddRef();

            stlsoft::scoped_handle<VARIANT*>    scoper(&var, ::VariantClear);

            XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len_a(var));
            XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len_w(var));
            XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len(var));

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("-1.2345", invoke_c_str_data_a(var));
            XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"-1.2345", invoke_c_str_data_w(var));
            XTESTS_TEST_T_STRING_EQUAL_APPROX_(TEXT("-1.2345"), invoke_c_str_data(var));

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX("-1.2345", stlsoft::c_str_ptr_a(var));
            XTESTS_TEST_WIDE_STRING_EQUAL_APPROX(L"-1.2345", stlsoft::c_str_ptr_w(var));
            XTESTS_TEST_T_STRING_EQUAL_APPROX_(TEXT("-1.2345"), stlsoft::c_str_ptr(var));

            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

            XTESTS_TEST_POINTER_NOT_EQUAL("-1.2345", stlsoft::c_str_ptr_null_a(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(L"-1.2345", stlsoft::c_str_ptr_null_w(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(TEXT("-1.2345"), stlsoft::c_str_ptr_null(var));
        }
    }
}

static void test_VT_DECIMAL()
{
    VARIANT var0;

    ::VariantInit(&var0);

    const int values[] = { INT_MIN, -1020304050, -65536, -65535, -201, -1, 0, 3, 10, 99, 271, 7871, 20000, 1020304050, INT_MAX };

    var0.vt = VT_I4;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var0.lVal = values[i];

        VARIANT var;

        ::VariantInit(&var);

        HRESULT hr = ::VariantChangeTypeEx(&var, &var0, LOCALE_USER_DEFAULT, 0, VT_DECIMAL);

        if(SUCCEEDED(hr))
        {
            char            num_a[21];
            wchar_t         num_w[21];
            TCHAR           num[21];
            size_t          cch_a;
            size_t          cch_w;
            size_t          cch;
            char const*     s_a = stlsoft::integer_to_string(&num_a[0], STLSOFT_NUM_ELEMENTS(num_a), values[i], cch_a);
            wchar_t const*  s_w = stlsoft::integer_to_string(&num_w[0], STLSOFT_NUM_ELEMENTS(num_w), values[i], cch_w);
            TCHAR const*    s   = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), values[i], cch);

            XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_DECIMAL), var.vt);

            XTESTS_TEST_INTEGER_EQUAL(cch_a, stlsoft::c_str_len_a(var));
            XTESTS_TEST_INTEGER_EQUAL(cch_w, stlsoft::c_str_len_w(var));
            XTESTS_TEST_INTEGER_EQUAL(cch, stlsoft::c_str_len(var));

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, invoke_c_str_data_a(var));
            XTESTS_TEST_WIDE_STRING_EQUAL(s_w, invoke_c_str_data_w(var));
            XTESTS_TEST_T_STRING_EQUAL_(s, invoke_c_str_data(var));

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, stlsoft::c_str_ptr_a(var));
            XTESTS_TEST_WIDE_STRING_EQUAL(s_w, stlsoft::c_str_ptr_w(var));
            XTESTS_TEST_T_STRING_EQUAL_(s, stlsoft::c_str_ptr(var));

            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
            XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

            XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s_a, stlsoft::c_str_ptr_null_a(var));
            XTESTS_TEST_WIDE_STRING_EQUAL(s_w, stlsoft::c_str_ptr_null_w(var));
            XTESTS_TEST_T_STRING_EQUAL_(s, stlsoft::c_str_ptr_null(var));
        }
    }}
}

static void test_VT_VARIANT()
{
    VARIANT var0;

    ::VariantInit(&var0);

    const int values[] = { INT_MIN, -43434534, -20000, -3000, -400, -50, -6, -1, 0, 3, 10, 99, 271, 7871, 3434534, INT_MAX };

    var0.vt = VT_I4;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var0.lVal    =   values[i];

        VARIANT var;

        var.vt      =   VT_VARIANT;
        var.pvarVal =   &var0;

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_VARIANT), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"", invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(TEXT(""), invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(TEXT(""), stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));
    }}
}

static void test_VT_CY()
{
    VARIANT var0;

    ::VariantInit(&var0);

    var0.vt     =   VT_R8;
    var0.dblVal =   -123.99;

    VARIANT var;

    ::VariantInit(&var);

    HRESULT hr = ::VariantChangeTypeEx(&var, &var0, LOCALE_USER_DEFAULT, 0, VT_CY);

    if(SUCCEEDED(hr))
    {
        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_CY), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(7u, stlsoft::c_str_len(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-123.99", invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"-123.99", invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(TEXT("-123.99"), invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-123.99", stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"-123.99", stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(TEXT("-123.99"), stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-123.99", stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"-123.99", stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(TEXT("-123.99"), stlsoft::c_str_ptr_null(var));
    }
}

static void test_VT_R4()
{
    VARIANT var;

    ::VariantInit(&var);

    const float values[] = { -1.2345E-20f, -434345.34f, -2000.0f, -300.0f, -40.04f,  -5.05f,  -2.0f,  -1.11f,  0.0f,  3.3f,  10.0f,  99.99f,  271.271f,  7871.7871f,  34345.34f,  1.2345E+20f };

    var.vt = VT_R4;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var.fltVal    =   values[i];

        // Automation's floating point representation is slightly different to
        // sprintf(), so we instead convert to and from string, and verify the
        // floating-point values

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_R4), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(::strlen(invoke_c_str_data_a(var).c_str()), stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(::wcslen(invoke_c_str_data_w(var).c_str()), stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(::_tcslen(invoke_c_str_data(var).c_str()), stlsoft::c_str_len(var));

        double  to_a;
        double  to_w;
        double  to;

        to_a    =   ::strtod(invoke_c_str_data_a(var).c_str(), NULL);
        to_w    =   ::wcstod(invoke_c_str_data_w(var).c_str(), NULL);
        to      =   ::_tcstod(invoke_c_str_data(var).c_str(), NULL);

        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to_a);
        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to_w);
        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to);

        to_a    =   ::strtod(stlsoft::c_str_ptr_a(var), NULL);
        to_w    =   ::wcstod(stlsoft::c_str_ptr_w(var), NULL);
        to      =   ::_tcstod(stlsoft::c_str_ptr(var), NULL);

        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to_a);
        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to_w);
        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to);

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

#if 0
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(values[i], stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));
#endif /* 0 */
    }}
}

static void test_VT_R8()
{
    VARIANT var;

    ::VariantInit(&var);

    const double values[] = { FLT_MIN, -434345.34, -2000.0, -300.0, -40.04,  -5.05,  -2.0,  -1.11,  0.0,  3.3,  10.0,  99.99,  271.271,  7871.7871,  34345.34,  FLT_MAX };

    var.vt = VT_R8;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        var.dblVal    =   values[i];

        // Automation's floating point representation is slightly different to
        // sprintf(), so we instead convert to and from string, and verify the
        // floating-point values

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_R8), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(::strlen(invoke_c_str_data_a(var).c_str()), stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(::wcslen(invoke_c_str_data_w(var).c_str()), stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(::_tcslen(invoke_c_str_data(var).c_str()), stlsoft::c_str_len(var));

        double  to_a;
        double  to_w;
        double  to;

        to_a    =   ::strtod(invoke_c_str_data_a(var).c_str(), NULL);
        to_w    =   ::wcstod(invoke_c_str_data_w(var).c_str(), NULL);
        to      =   ::_tcstod(invoke_c_str_data(var).c_str(), NULL);

        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to_a);
        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to_w);
        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to);

        to_a    =   ::strtod(stlsoft::c_str_ptr_a(var), NULL);
        to_w    =   ::wcstod(stlsoft::c_str_ptr_w(var), NULL);
        to      =   ::_tcstod(stlsoft::c_str_ptr(var), NULL);

        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to_a);
        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to_w);
        XTESTS_TEST_FLOATINGPOINT_EQUAL(values[i], to);

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

#if 0
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_WIDE_STRING_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_T_STRING_EQUAL_(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));
#endif /* 0 */
    }}
}

static void test_VT_ERROR()
{
    VARIANT var;

    ::VariantInit(&var);

    const LONG errors[] = {
		ERROR_SUCCESS
	,	ERROR_OUTOFMEMORY
	,	E_FAIL
	,	E_UNEXPECTED
	,	E_OUTOFMEMORY
	,	DISP_E_BADINDEX
	,	0x80092001L
	,	0x800B010AL
	,	0x800B010BL
	,	0x800B010CL
	,	0x800B010DL
	};

    var.vt = VT_ERROR;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
    {
        var.scode = errors[i];

        XTESTS_TEST_INTEGER_EQUAL(USHORT(VT_ERROR), var.vt);

        XTESTS_TEST_INTEGER_EQUAL(::strlen(invoke_c_str_data_a(var).c_str()), stlsoft::c_str_len_a(var));
        XTESTS_TEST_INTEGER_EQUAL(::wcslen(invoke_c_str_data_w(var).c_str()), stlsoft::c_str_len_w(var));
        XTESTS_TEST_INTEGER_EQUAL(::_tcslen(invoke_c_str_data(var).c_str()), stlsoft::c_str_len(var));

        winstl::error_desc_a    desc_a(errors[i]);
        winstl::error_desc_w    desc_w(errors[i]);
        winstl::error_desc      desc(errors[i]);

        XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(desc_a, invoke_c_str_data_a(var));
        XTESTS_TEST_WIDE_STRING_CONTAIN(desc_w, invoke_c_str_data_w(var));
        XTESTS_TEST_T_STRING_CONTAIN_(desc, invoke_c_str_data(var));

        XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(desc_a, stlsoft::c_str_ptr_a(var));
        XTESTS_TEST_WIDE_STRING_CONTAIN(desc_w, stlsoft::c_str_ptr_w(var));
        XTESTS_TEST_T_STRING_CONTAIN_(desc, stlsoft::c_str_ptr(var));

        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<char const*>(NULL), stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<wchar_t const*>(NULL), stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_POINTER_NOT_EQUAL(static_cast<TCHAR const*>(NULL), stlsoft::c_str_ptr_null(var));

        XTESTS_TEST_MULTIBYTE_STRING_CONTAIN(desc_a, stlsoft::c_str_ptr_null_a(var));
        XTESTS_TEST_WIDE_STRING_CONTAIN(desc_w, stlsoft::c_str_ptr_null_w(var));
        XTESTS_TEST_T_STRING_CONTAIN_(desc, stlsoft::c_str_ptr_null(var));
    }}
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
