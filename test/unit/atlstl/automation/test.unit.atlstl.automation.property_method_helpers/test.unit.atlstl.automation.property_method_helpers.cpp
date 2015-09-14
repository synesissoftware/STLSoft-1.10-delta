/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.atlstl.automation.property_method_helpers.cpp
 *
 * Purpose:     Implementation file for the test.unit.atlstl.automation.property_method_helpers project.
 *
 * Created:     29th October 2008
 * Updated:     29th October 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <atlstl/automation/property_method_helpers.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <comstl/string/bstr.hpp>
#include <comstl/util/variant.hpp>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_BSTR_empty(void);
    static void test_BSTR(void);
    static void test_BOOL_empty(void);
    static void test_BOOL(void);
    static void test_bool_empty(void);
    static void test_bool(void);
    static void test_VARIANT_empty(void);
    static void test_VARIANT(void);
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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.atlstl.automation.property_method_helpers", verbosity))
    {
        XTESTS_RUN_CASE(test_BSTR_empty);
        XTESTS_RUN_CASE(test_BSTR);
        XTESTS_RUN_CASE(test_BOOL_empty);
        XTESTS_RUN_CASE(test_BOOL);
        XTESTS_RUN_CASE(test_bool_empty);
        XTESTS_RUN_CASE(test_bool);
        XTESTS_RUN_CASE(test_VARIANT_empty);
        XTESTS_RUN_CASE(test_VARIANT);
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

    class Class_With_BSTR
    {
    public:
        typedef Class_With_BSTR class_type;

    public:
        STDMETHOD(put_BSTR)(BSTR newVal)
        {
            return atlstl::put_MemberValue(this, newVal, &class_type::m_value);
        }
        STDMETHOD(get_BSTR)(BSTR* retVal)
        {
            return atlstl::get_MemberValue(this, retVal, &class_type::m_value);
        }

    private:
        CComBSTR    m_value;
    };

    class Class_With_BOOL
    {
    public:
        typedef Class_With_BOOL class_type;

    public:
        Class_With_BOOL()
            : m_value(false)
        {}

    public:
        STDMETHOD(put_BOOL)(BOOL newVal)
        {
            return atlstl::put_MemberValue(this, newVal, &class_type::m_value);
        }
        STDMETHOD(get_BOOL)(BOOL* retVal)
        {
            return atlstl::get_MemberValue(this, retVal, &class_type::m_value);
        }

    private:
        BOOL    m_value;
    };

    class Class_With_bool
    {
    public:
        typedef Class_With_bool class_type;

    public:
        Class_With_bool()
            : m_value(false)
        {}

    public:
        STDMETHOD(put_bool)(BOOL newVal)
        {
            return atlstl::put_MemberValue(this, newVal, &class_type::m_value);
        }
        STDMETHOD(get_bool)(BOOL* retVal)
        {
            return atlstl::get_MemberValue(this, retVal, &class_type::m_value);
        }

    private:
        bool    m_value;
    };

    class Class_With_VARIANT
    {
    public:
        typedef Class_With_VARIANT class_type;

    public:
        STDMETHOD(put_VARIANT)(VARIANT newVal)
        {
            return atlstl::put_MemberValue(this, newVal, &class_type::m_value);
        }
        STDMETHOD(get_VARIANT)(VARIANT* retVal)
        {
            return atlstl::get_MemberValue(this, retVal, &class_type::m_value);
        }

    private:
        CComVariant m_value;
    };

static void test_BSTR_empty()
{
    Class_With_BSTR instance;

    BSTR    value;
    HRESULT hr;

    hr = instance.get_BSTR(&value);

    if(FAILED(hr))
    {
#ifdef XTESTS_TEST_WARNING
        XTESTS_TEST_WARNING("Failed to get BSTR value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
    }
    else
    {
        stlsoft::scoped_handle<BSTR>    scoper(value, ::SysFreeString);

        XTESTS_TEST_WIDE_STRING_EQUAL(static_cast<BSTR>(NULL), value);
    }
}

static void test_BSTR()
{
    Class_With_BSTR instance;

    comstl::bstr    newValue(L"abcdef");
    HRESULT         hr;

    hr = instance.put_BSTR(newValue.get());

    if(FAILED(hr))
    {
#ifdef XTESTS_TEST_WARNING
            XTESTS_TEST_WARNING("Failed to set BSTR value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
    }
    else
    {
        BSTR    value;

        hr = instance.get_BSTR(&value);

        if(FAILED(hr))
        {
#ifdef XTESTS_TEST_WARNING
            XTESTS_TEST_WARNING("Failed to get BSTR value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
        }
        else
        {
            stlsoft::scoped_handle<BSTR>    scoper(value, ::SysFreeString);

            XTESTS_TEST_WIDE_STRING_EQUAL(newValue, value);
        }
    }
}
static void test_BOOL_empty()
{
    Class_With_BOOL instance;

    BOOL    value;
    HRESULT hr;

    hr = instance.get_BOOL(&value);

    if(FAILED(hr))
    {
#ifdef XTESTS_TEST_WARNING
        XTESTS_TEST_WARNING("Failed to get BOOL value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
    }
    else
    {
        XTESTS_TEST_BOOLEAN_EQUAL(static_cast<BOOL>(false), value);
    }
}

static void test_BOOL()
{
    Class_With_BOOL instance;

    BOOL    newValue = true;
    HRESULT hr;

    hr = instance.put_BOOL(newValue);

    if(FAILED(hr))
    {
#ifdef XTESTS_TEST_WARNING
            XTESTS_TEST_WARNING("Failed to set BOOL value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
    }
    else
    {
        BOOL    value;

        hr = instance.get_BOOL(&value);

        if(FAILED(hr))
        {
#ifdef XTESTS_TEST_WARNING
            XTESTS_TEST_WARNING("Failed to get BOOL value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
        }
        else
        {
            XTESTS_TEST_BOOLEAN_EQUAL(newValue, value);
        }
    }
}

static void test_bool_empty()
{
    Class_With_bool instance;

    BOOL    value;
    HRESULT hr;

    hr = instance.get_bool(&value);

    if(FAILED(hr))
    {
#ifdef XTESTS_TEST_WARNING
        XTESTS_TEST_WARNING("Failed to get bool value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
    }
    else
    {
        XTESTS_TEST_BOOLEAN_EQUAL(static_cast<BOOL>(false), value);
    }
}

static void test_bool()
{
    Class_With_bool instance;

    BOOL    newValue = true;
    HRESULT hr;

    hr = instance.put_bool(newValue);

    if(FAILED(hr))
    {
#ifdef XTESTS_TEST_WARNING
            XTESTS_TEST_WARNING("Failed to set bool value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
    }
    else
    {
        BOOL    value;

        hr = instance.get_bool(&value);

        if(FAILED(hr))
        {
#ifdef XTESTS_TEST_WARNING
            XTESTS_TEST_WARNING("Failed to get bool value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
        }
        else
        {
            XTESTS_TEST_BOOLEAN_EQUAL(newValue, value);
        }
    }
}

static void test_VARIANT_empty()
{
    Class_With_VARIANT instance;

    VARIANT value;
    HRESULT hr;

    ::VariantInit(&value);

    hr = instance.get_VARIANT(&value);

    if(FAILED(hr))
    {
#ifdef XTESTS_TEST_WARNING
        XTESTS_TEST_WARNING("Failed to get VARIANT value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
    }
    else
    {
        stlsoft::scoped_handle<VARIANT*>    scoper(&value, ::VariantClear);

        XTESTS_TEST_WIDE_STRING_EQUAL(static_cast<BSTR>(NULL), value);
    }
}

static void test_VARIANT()
{
    Class_With_VARIANT instance;

    comstl::variant newValue(L"abcdef");
    HRESULT         hr;

    hr = instance.put_VARIANT(newValue);

    if(FAILED(hr))
    {
#ifdef XTESTS_TEST_WARNING
            XTESTS_TEST_WARNING("Failed to set VARIANT value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
    }
    else
    {
        VARIANT value;

        ::VariantInit(&value);

        hr = instance.get_VARIANT(&value);

        if(FAILED(hr))
        {
#ifdef XTESTS_TEST_WARNING
            XTESTS_TEST_WARNING("Failed to get VARIANT value", winstl::error_desc_a(hr));
#endif /* XTESTS_TEST_WARNING */
        }
        else
        {
            stlsoft::scoped_handle<VARIANT*>    scoper(&value, ::VariantClear);

            XTESTS_TEST_WIDE_STRING_EQUAL(newValue, value);
        }
    }
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
