/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/comstl/util/test.unit.comstl.util.VARIANT_functions.c
 *
 * Purpose:     Implementation file for the test.unit.comstl.util.VARIANT_functions project.
 *
 * Created:     26th October 2008
 * Updated:     19th May 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <comstl/util/VARIANT_functions.h>

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

static void test_VARIANT_equal_VT_EMPTY(void);
static void test_VARIANT_equal_VT_NULL(void);
static void test_VARIANT_equal_VT_I4(void);
static void test_VARIANT_equal_VT_BSTR(void);
static void test_VARIANT_equal_VT_R8(void);
static void test_VARIANT_equal_VT_DECIMAL(void);

static void test_VARIANT_change_type_VT_I4(void);
static void test_VARIANT_change_type_VT_R8(void);
static void test_VARIANT_change_type_VT_BSTR(void);

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    OleInitialize(NULL);

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.comstl.util.VARIANT_functions.VARIANT_equal", verbosity))
    {
        XTESTS_RUN_CASE(test_VARIANT_equal_VT_EMPTY);
        XTESTS_RUN_CASE(test_VARIANT_equal_VT_NULL);
        XTESTS_RUN_CASE(test_VARIANT_equal_VT_I4);
        XTESTS_RUN_CASE(test_VARIANT_equal_VT_BSTR);
        XTESTS_RUN_CASE(test_VARIANT_equal_VT_R8);
        XTESTS_RUN_CASE(test_VARIANT_equal_VT_DECIMAL);

        XTESTS_RUN_CASE(test_VARIANT_change_type_VT_I4);
        XTESTS_RUN_CASE(test_VARIANT_change_type_VT_R8);
        XTESTS_RUN_CASE(test_VARIANT_change_type_VT_BSTR);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Constants
 */

const CLSID clsidSynesisValue = { 0xE79E9900, 0x59DB, 0x4B94, { 0xAF, 0xE6, 0xD8, 0x8E, 0x23, 0x4D, 0xDD, 0xDA } };

#define VT_I4_VALUE             -123
#define VT_BSTR_VALUE           L"-123.456"
#define VT_R8_VALUE             -123.456
#define VT_DECIMAL_VALUE        12345
#define VT_DISPATCH_VALUE       -10101
#define VT_UNKNOWN_VALUE        L"-20202"

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

void init_VARIANTS(VARIANT* pvarEMPTY, VARIANT* pvarNULL, VARIANT* pvarI4, VARIANT* pvarBSTR, VARIANT* pvarR8, VARIANT* pvarDECIMAL, VARIANT* pvarDISPATCH, VARIANT* pvarUNKNOWN);
HRESULT setup_VARIANTs(VARIANT* pvarEMPTY, VARIANT* pvarNULL, VARIANT* pvarI4, VARIANT* pvarBSTR, VARIANT* pvarR8, VARIANT* pvarDECIMAL, VARIANT* pvarDISPATCH, VARIANT* pvarUNKNOWN);
void release_VARIANTS(VARIANT* pvarEMPTY, VARIANT* pvarNULL, VARIANT* pvarI4, VARIANT* pvarBSTR, VARIANT* pvarR8, VARIANT* pvarDECIMAL, VARIANT* pvarDISPATCH, VARIANT* pvarUNKNOWN);

void init_VARIANTS(VARIANT* pvarEMPTY, VARIANT* pvarNULL, VARIANT* pvarI4, VARIANT* pvarBSTR, VARIANT* pvarR8, VARIANT* pvarDECIMAL, VARIANT* pvarDISPATCH, VARIANT* pvarUNKNOWN)
{
    VariantInit(pvarEMPTY);
    VariantInit(pvarNULL);
    VariantInit(pvarI4);
    VariantInit(pvarBSTR);
    VariantInit(pvarR8);
    VariantInit(pvarDECIMAL);
    VariantInit(pvarDISPATCH);
    VariantInit(pvarUNKNOWN);
}

HRESULT setup_VARIANTs(VARIANT* pvarEMPTY, VARIANT* pvarNULL, VARIANT* pvarI4, VARIANT* pvarBSTR, VARIANT* pvarR8, VARIANT* pvarDECIMAL, VARIANT* pvarDISPATCH, VARIANT* pvarUNKNOWN)
{
    HRESULT hr;

    init_VARIANTS(pvarEMPTY, pvarNULL, pvarI4, pvarBSTR, pvarR8, pvarDECIMAL, pvarDISPATCH, pvarUNKNOWN);

    COMSTL_ACCESS_VARIANT_vt_BYPTR(pvarNULL)            =   VT_NULL;

    COMSTL_ACCESS_VARIANT_vt_BYPTR(pvarI4)              =   VT_I4;
    COMSTL_ACCESS_VARIANT_MEM_BYPTR(pvarI4, lVal)       =   VT_I4_VALUE;

    COMSTL_ACCESS_VARIANT_vt_BYPTR(pvarBSTR)            =   VT_BSTR;
    COMSTL_ACCESS_VARIANT_MEM_BYPTR(pvarBSTR, bstrVal)  =   SysAllocString(VT_BSTR_VALUE);

    if(NULL == COMSTL_ACCESS_VARIANT_MEM_BYPTR(pvarBSTR, bstrVal))
    {
        hr = E_OUTOFMEMORY;
    }
    else
    {
        VARIANT varDecimal_;

        VariantInit(&varDecimal_);
        COMSTL_ACCESS_VARIANT_vt_BYREF(varDecimal_)			=   VT_I4;
        COMSTL_ACCESS_VARIANT_MEM_BYREF(varDecimal_, lVal)	=   VT_DECIMAL_VALUE;

        COMSTL_ACCESS_VARIANT_vt_BYPTR(pvarR8)          =   VT_R8;
        COMSTL_ACCESS_VARIANT_MEM_BYPTR(pvarR8, dblVal) =   VT_R8_VALUE;

        hr = VariantChangeType(pvarDECIMAL, &varDecimal_, 0, VT_DECIMAL);

        if(SUCCEEDED(hr))
        {
            hr = CoCreateInstance(&clsidSynesisValue, NULL, CLSCTX_ALL, &IID_IDispatch, (void**)&COMSTL_ACCESS_VARIANT_MEM_BYPTR(pvarDISPATCH, pdispVal));

            if(FAILED(hr))
            {
                hr = S_FALSE;
            }
            else
            {
                VARIANT varDISPATCH_;

                VariantInit(&varDISPATCH_);

                COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH_)		=   VT_I4;
                COMSTL_ACCESS_VARIANT_MEM_BYREF(varDISPATCH_, lVal)	=   VT_DISPATCH_VALUE;

                hr = comstl_C_IDispatch_put_property(COMSTL_ACCESS_VARIANT_MEM_BYPTR(pvarDISPATCH, pdispVal), 1, 1, &varDISPATCH_, NULL, NULL, LOCALE_USER_DEFAULT);

                if(SUCCEEDED(hr))
                {
                    COMSTL_ACCESS_VARIANT_vt_BYPTR(pvarDISPATCH) = VT_DISPATCH;

                    if(SUCCEEDED(hr))
                    {
                        LPDISPATCH  pdispUnk;

                        hr = CoCreateInstance(&clsidSynesisValue, NULL, CLSCTX_ALL, &IID_IUnknown, (void**)&pdispUnk);

                        if(FAILED(hr))
                        {
                            hr = S_FALSE;
                        }
                        else
                        {
                            VARIANT varUNKNOWN_;

                            VariantInit(&varUNKNOWN_);

                            COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN_)				=   VT_BSTR;
                            COMSTL_ACCESS_VARIANT_MEM_BYREF(varUNKNOWN_, bstrVal)	=   SysAllocString(VT_UNKNOWN_VALUE);

                            COMSTL_ACCESS_VARIANT_MEM_BYPTR(pvarUNKNOWN, punkVal)	=	(LPUNKNOWN)pdispUnk;

                            if(NULL == COMSTL_ACCESS_VARIANT_MEM_BYREF(varUNKNOWN_, bstrVal))
                            {
                                hr = E_OUTOFMEMORY;
                            }
                            else
                            {
                                hr = comstl_C_IDispatch_put_property(pdispUnk, 1, 1, &varUNKNOWN_, NULL, NULL, LOCALE_USER_DEFAULT);

                                VariantClear(&varUNKNOWN_);

                                COMSTL_ACCESS_VARIANT_vt_BYPTR(pvarUNKNOWN) = VT_UNKNOWN;
                            }
                        }
                    }
                }
            }
        }
    }

    if(FAILED(hr))
    {
        VariantClear(pvarEMPTY);
        VariantClear(pvarNULL);
        VariantClear(pvarI4);
        VariantClear(pvarBSTR);
        VariantClear(pvarR8);
        VariantClear(pvarDECIMAL);
        VariantClear(pvarDISPATCH);
        VariantClear(pvarUNKNOWN);
    }

    return hr;
}

void release_VARIANTS(VARIANT* pvarEMPTY, VARIANT* pvarNULL, VARIANT* pvarI4, VARIANT* pvarBSTR, VARIANT* pvarR8, VARIANT* pvarDECIMAL, VARIANT* pvarDISPATCH, VARIANT* pvarUNKNOWN)
{
    VariantClear(pvarEMPTY);
    VariantClear(pvarNULL);
    VariantClear(pvarI4);
    VariantClear(pvarBSTR);
    VariantClear(pvarR8);
    VariantClear(pvarDECIMAL);
    VariantClear(pvarDISPATCH);
    VariantClear(pvarUNKNOWN);
}

static void test_VARIANT_equal_VT_EMPTY()
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        XTESTS_TEST_BOOLEAN_EQUAL(1, comstl_C_VARIANT_equal(&varEMPTY, &varEMPTY, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varNULL, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varI4, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varBSTR, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varR8, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varDECIMAL, NULL));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varDISPATCH, NULL));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varUNKNOWN, NULL));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

static void test_VARIANT_equal_VT_NULL()
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varNULL, &varEMPTY, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(1, comstl_C_VARIANT_equal(&varNULL, &varNULL, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varNULL, &varI4, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varNULL, &varBSTR, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varNULL, &varR8, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varNULL, &varDECIMAL, NULL));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varDISPATCH, NULL));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varUNKNOWN, NULL));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

static void test_VARIANT_equal_VT_I4()
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varI4, &varEMPTY, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varI4, &varNULL, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(1, comstl_C_VARIANT_equal(&varI4, &varI4, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varI4, &varBSTR, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varI4, &varR8, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varI4, &varDECIMAL, NULL));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varDISPATCH, NULL));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varUNKNOWN, NULL));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

static void test_VARIANT_equal_VT_BSTR()
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varBSTR, &varEMPTY, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varBSTR, &varNULL, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varBSTR, &varI4, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(1, comstl_C_VARIANT_equal(&varBSTR, &varBSTR, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varBSTR, &varR8, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varBSTR, &varDECIMAL, NULL));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varDISPATCH, NULL));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varUNKNOWN, NULL));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

static void test_VARIANT_equal_VT_R8()
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varR8, &varEMPTY, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varR8, &varNULL, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varR8, &varI4, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varR8, &varBSTR, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(1, comstl_C_VARIANT_equal(&varR8, &varR8, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varR8, &varDECIMAL, NULL));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varDISPATCH, NULL));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varUNKNOWN, NULL));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

static void test_VARIANT_equal_VT_DECIMAL()
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varDECIMAL, &varEMPTY, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varDECIMAL, &varNULL, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varDECIMAL, &varI4, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varDECIMAL, &varBSTR, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varDECIMAL, &varR8, NULL));
        XTESTS_TEST_BOOLEAN_EQUAL(1, comstl_C_VARIANT_equal(&varDECIMAL, &varDECIMAL, NULL));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varDISPATCH, NULL));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(0, comstl_C_VARIANT_equal(&varEMPTY, &varUNKNOWN, NULL));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

static void test_VARIANT_change_type_VT_I4(void)
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        VARIANT varEMPTYX;
        VARIANT varNULLX;
        VARIANT varI4X;
        VARIANT varBSTRX;
        VARIANT varR8X;
        VARIANT varDECIMALX;
        VARIANT varDISPATCHX;
        VARIANT varUNKNOWNX;

        init_VARIANTS(&varEMPTYX, &varNULLX, &varI4X, &varBSTRX, &varR8X, &varDECIMALX, &varDISPATCHX, &varUNKNOWNX);

        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varEMPTYX, &varEMPTY, LOCALE_USER_DEFAULT, 0, VT_I4)));
        XTESTS_TEST_BOOLEAN_EQUAL(1, FAILED(comstl_C_VARIANT_change_type(&varNULLX, &varNULL, LOCALE_USER_DEFAULT, 0, VT_I4)));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varI4X, &varI4, LOCALE_USER_DEFAULT, 0, VT_I4)));
        XTESTS_TEST_INTEGER_EQUAL(VT_I4_VALUE, COMSTL_ACCESS_VARIANT_MEM_BYREF(varI4X, lVal));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varBSTRX, &varBSTR, LOCALE_USER_DEFAULT, 0, VT_I4)));
        XTESTS_TEST_INTEGER_EQUAL(wcstol(VT_BSTR_VALUE, NULL, 0), COMSTL_ACCESS_VARIANT_MEM_BYREF(varBSTRX, lVal));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varR8X, &varR8, LOCALE_USER_DEFAULT, 0, VT_I4)));
        XTESTS_TEST_INTEGER_EQUAL(ceil(VT_R8_VALUE), COMSTL_ACCESS_VARIANT_MEM_BYREF(varR8X, lVal));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varDECIMALX, &varDECIMAL, LOCALE_USER_DEFAULT, 0, VT_I4)));
        XTESTS_TEST_INTEGER_EQUAL(VT_DECIMAL_VALUE, COMSTL_ACCESS_VARIANT_MEM_BYREF(varDECIMALX, lVal));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varDISPATCHX, &varDISPATCH, LOCALE_USER_DEFAULT, 0, VT_I4)));
            XTESTS_TEST_INTEGER_EQUAL(VT_DISPATCH_VALUE, COMSTL_ACCESS_VARIANT_MEM_BYREF(varDISPATCHX, lVal));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varUNKNOWNX, &varUNKNOWN, LOCALE_USER_DEFAULT, 0, VT_I4)));
            XTESTS_TEST_INTEGER_EQUAL(wcstol(VT_UNKNOWN_VALUE, NULL, 0), COMSTL_ACCESS_VARIANT_MEM_BYREF(varUNKNOWNX, lVal));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

static void test_VARIANT_change_type_VT_R8(void)
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        VARIANT varEMPTYX;
        VARIANT varNULLX;
        VARIANT varI4X;
        VARIANT varBSTRX;
        VARIANT varR8X;
        VARIANT varDECIMALX;
        VARIANT varDISPATCHX;
        VARIANT varUNKNOWNX;

        init_VARIANTS(&varEMPTYX, &varNULLX, &varI4X, &varBSTRX, &varR8X, &varDECIMALX, &varDISPATCHX, &varUNKNOWNX);

        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varEMPTYX, &varEMPTY, LOCALE_USER_DEFAULT, 0, VT_R8)));
        XTESTS_TEST_BOOLEAN_EQUAL(1, FAILED(comstl_C_VARIANT_change_type(&varNULLX, &varNULL, LOCALE_USER_DEFAULT, 0, VT_R8)));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varI4X, &varI4, LOCALE_USER_DEFAULT, 0, VT_R8)));
        XTESTS_TEST_FLOATINGPOINT_EQUAL(ceil(VT_I4_VALUE), ceil(COMSTL_ACCESS_VARIANT_MEM_BYREF(varI4X, dblVal)));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varBSTRX, &varBSTR, LOCALE_USER_DEFAULT, 0, VT_R8)));
        XTESTS_TEST_FLOATINGPOINT_EQUAL(wcstod(VT_BSTR_VALUE, NULL), COMSTL_ACCESS_VARIANT_MEM_BYREF(varBSTRX, dblVal));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varR8X, &varR8, LOCALE_USER_DEFAULT, 0, VT_R8)));
        XTESTS_TEST_FLOATINGPOINT_EQUAL(VT_R8_VALUE, COMSTL_ACCESS_VARIANT_MEM_BYREF(varR8X, dblVal));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varDECIMALX, &varDECIMAL, LOCALE_USER_DEFAULT, 0, VT_R8)));
        XTESTS_TEST_FLOATINGPOINT_EQUAL((double)VT_DECIMAL_VALUE, COMSTL_ACCESS_VARIANT_MEM_BYREF(varDECIMALX, dblVal));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varDISPATCHX, &varDISPATCH, LOCALE_USER_DEFAULT, 0, VT_R8)));
            XTESTS_TEST_FLOATINGPOINT_EQUAL((double)VT_DISPATCH_VALUE, COMSTL_ACCESS_VARIANT_MEM_BYREF(varDISPATCHX, dblVal));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varUNKNOWNX, &varUNKNOWN, LOCALE_USER_DEFAULT, 0, VT_R8)));
            XTESTS_TEST_FLOATINGPOINT_EQUAL((double)wcstol(VT_UNKNOWN_VALUE, NULL, 0), COMSTL_ACCESS_VARIANT_MEM_BYREF(varUNKNOWNX, dblVal));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

static void test_VARIANT_change_type_VT_BSTR(void)
{
    VARIANT varEMPTY;
    VARIANT varNULL;
    VARIANT varI4;
    VARIANT varBSTR;
    VARIANT varR8;
    VARIANT varDECIMAL;
    VARIANT varDISPATCH;
    VARIANT varUNKNOWN;
    HRESULT hr = setup_VARIANTs(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);

    if(FAILED(hr))
    {
        ; /* Issue warning */
    }
    else
    {
        VARIANT varEMPTYX;
        VARIANT varNULLX;
        VARIANT varI4X;
        VARIANT varBSTRX;
        VARIANT varR8X;
        VARIANT varDECIMALX;
        VARIANT varDISPATCHX;
        VARIANT varUNKNOWNX;

        init_VARIANTS(&varEMPTYX, &varNULLX, &varI4X, &varBSTRX, &varR8X, &varDECIMALX, &varDISPATCHX, &varUNKNOWNX);

        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varEMPTYX, &varEMPTY, LOCALE_USER_DEFAULT, 0, VT_BSTR)));
        XTESTS_TEST_BOOLEAN_EQUAL(1, FAILED(comstl_C_VARIANT_change_type(&varNULLX, &varNULL, LOCALE_USER_DEFAULT, 0, VT_BSTR)));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varI4X, &varI4, LOCALE_USER_DEFAULT, 0, VT_BSTR)));
        XTESTS_TEST_WIDE_STRING_EQUAL(STLSOFT_STRINGIZE_w(VT_I4_VALUE), COMSTL_ACCESS_VARIANT_MEM_BYREF(varI4X, bstrVal));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varBSTRX, &varBSTR, LOCALE_USER_DEFAULT, 0, VT_BSTR)));
        XTESTS_TEST_WIDE_STRING_EQUAL(VT_BSTR_VALUE, COMSTL_ACCESS_VARIANT_MEM_BYREF(varBSTRX, bstrVal));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varR8X, &varR8, LOCALE_USER_DEFAULT, 0, VT_BSTR)));
        XTESTS_TEST_WIDE_STRING_EQUAL(STLSOFT_STRINGIZE_w(VT_R8_VALUE), COMSTL_ACCESS_VARIANT_MEM_BYREF(varBSTRX, bstrVal));
        XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varDECIMALX, &varDECIMAL, LOCALE_USER_DEFAULT, 0, VT_BSTR)));
        XTESTS_TEST_WIDE_STRING_EQUAL(STLSOFT_STRINGIZE_w(VT_DECIMAL_VALUE), COMSTL_ACCESS_VARIANT_MEM_BYREF(varDECIMALX, bstrVal));
        if(VT_DISPATCH == COMSTL_ACCESS_VARIANT_vt_BYREF(varDISPATCH))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varDISPATCHX, &varDISPATCH, LOCALE_USER_DEFAULT, 0, VT_BSTR)));
            XTESTS_TEST_WIDE_STRING_EQUAL(STLSOFT_STRINGIZE_w(VT_DISPATCH_VALUE), COMSTL_ACCESS_VARIANT_MEM_BYREF(varDISPATCHX, bstrVal));
        }
        if(VT_UNKNOWN == COMSTL_ACCESS_VARIANT_vt_BYREF(varUNKNOWN))
        {
            XTESTS_TEST_BOOLEAN_EQUAL(1, SUCCEEDED(comstl_C_VARIANT_change_type(&varUNKNOWNX, &varUNKNOWN, LOCALE_USER_DEFAULT, 0, VT_BSTR)));
            XTESTS_TEST_WIDE_STRING_EQUAL(VT_UNKNOWN_VALUE, COMSTL_ACCESS_VARIANT_MEM_BYREF(varUNKNOWNX, bstrVal));
        }

        release_VARIANTS(&varEMPTY, &varNULL, &varI4, &varBSTR, &varR8, &varDECIMAL, &varDISPATCH, &varUNKNOWN);
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
