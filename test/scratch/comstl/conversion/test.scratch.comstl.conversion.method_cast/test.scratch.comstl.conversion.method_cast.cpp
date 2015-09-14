/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.comstl.conversion.method_cast.cpp
 *
 * Purpose:     Implementation file for the test.scratch.comstl.conversion.method_cast project.
 *
 * Created:     29th November 2008
 * Updated:     9th December 2013
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2013, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* STLSoft Header Files */
#include <stlsoft/smartptr/ref_ptr.hpp>
#include <comstl/conversion/method_cast.hpp>
#include <comstl/error/errorinfo_desc.hpp>
#include <comstl/util/creation_functions.hpp>
#include <comstl/util/initialisers.hpp>
#include <comstl/util/variant.hpp>
#include <winstl/error/error_desc.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */


/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */

extern "C" const char PANTHEIOS_FE_PROCESS_IDENTITY[]    =   "test.scratch.comstl.conversion.method_cast";

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

class Class1
{
public:
    HRESULT STDAPICALLTYPE get_short(short* pVal)
    {
        *pVal = 10101;

        return S_OK;
    }
    HRESULT STDAPICALLTYPE get_long(long* pVal)
    {
        *pVal = 101010101;

        return S_OK;
    }
    HRESULT STDAPICALLTYPE get_float(float* pVal)
    {
        *pVal = 10101.0101f;

        return S_OK;
    }
    HRESULT STDAPICALLTYPE get_double(double* pVal)
    {
        *pVal = 10101.0101;

        return S_OK;
    }
    HRESULT STDAPICALLTYPE get_BSTR(BSTR* pVal)
    {
        *pVal = ::SysAllocString(L"abc");

        return S_OK;
    }
    HRESULT STDAPICALLTYPE get_VARIANT(VARIANT* pVal)
    {
        pVal->vt        =   VT_BSTR;
        pVal->bstrVal   =   ::SysAllocString(L"def");

        return S_OK;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Function declarations
 */

namespace stlsoft
{
namespace comstl_project
{

    inline variant& transfer_resource(variant& dest, VARIANT& src)
    {
        COMSTL_ASSERT(VT_EMPTY == dest.vt);

        dest = src;

        ::VariantClear(&src);

        return dest;
    }

} /* namespace comstl_project */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    Class1  instance;

    short   sVal    =   comstl::method_cast<short>(&instance, &Class1::get_short);
    long    lVal    =   comstl::method_cast<long>(&instance, &Class1::get_long);
    float   fVal    =   comstl::method_cast<float>(&instance, &Class1::get_float);
    double  dVal    =   comstl::method_cast<double>(&instance, &Class1::get_double);

    BSTR    bstrVal =   comstl::method_cast<BSTR>(&instance, &Class1::get_BSTR);

#if !defined(STLSOFT_COMPILER_IS_GCC) || \
    __GNUC__ > 3
    comstl::variant varVal  =   comstl::method_cast<comstl::variant>(&instance, &Class1::get_VARIANT);
#endif

    STLSOFT_SUPPRESS_UNUSED(sVal);
    STLSOFT_SUPPRESS_UNUSED(lVal);
    STLSOFT_SUPPRESS_UNUSED(fVal);
    STLSOFT_SUPPRESS_UNUSED(dVal);
    STLSOFT_SUPPRESS_UNUSED(bstrVal);

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
        comstl::com_initialiser coinit;

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        std::cerr << "Unexpected general error: " << x.what() << ". Application terminating" << std::endl;

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Unhandled unknown error" << std::endl;

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
