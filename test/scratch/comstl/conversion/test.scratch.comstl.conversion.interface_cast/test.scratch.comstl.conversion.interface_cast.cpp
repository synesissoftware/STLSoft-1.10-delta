/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.comstl.conversion.interface_cast.cpp
 *
 * Purpose:     Implementation file for the test.scratch.comstl.conversion.interface_cast project.
 *
 * Created:     1st December 2008
 * Updated:     7th May 2009
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


/* STLSoft Header Files */
#include <stlsoft/smartptr/ref_ptr.hpp>
#include <comstl/conversion/interface_cast.hpp>
#include <comstl/error/errorinfo_desc.hpp>
#include <comstl/util/creation_functions.hpp>
#include <comstl/util/initialisers.hpp>
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
 * Typedefs
 */

class Thing
	: public IUnknown
{
public:
	Thing()
		: m_rc(1)
	{
#ifdef _DEBUG
		std::cout << "Thing(); rc=" << m_rc << std::endl;
#endif /* _DEBUG */
	}
	~Thing()
	{
#ifdef _DEBUG
		std::cout << "~Thing()" << std::endl;
#endif /* _DEBUG */
	}

public:
	STDMETHOD_(ULONG, AddRef)()
	{
#ifdef _DEBUG
		std::cout << "AddRef(); rc=" << (m_rc + 1) << std::endl;
#endif /* _DEBUG */

		return ++m_rc;
	}
	STDMETHOD_(ULONG, Release)()
	{
#ifdef _DEBUG
		std::cout << "Release(); rc=" << (m_rc - 1) << std::endl;
#endif /* _DEBUG */

		if(0 == --m_rc)
		{
			delete this;

			return 0;
		}

		return m_rc;
	}
	STDMETHOD(QueryInterface)(REFIID riid, void** ppv)
	{
#ifdef _DEBUG
		std::cout << "QueryInterface()" << std::endl;
#endif /* _DEBUG */

		if(IID_IUnknown == riid)
		{
			(*ppv) = this;

			AddRef();

			return S_OK;
		}

		return E_NOINTERFACE;
	}

private:
	ULONG	m_rc;
};

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
#ifdef _DEBUG
	std::cout << std::endl << "1" << std::endl;
#endif /* _DEBUG */
	{
		stlsoft::ref_ptr<IUnknown>	p1(new Thing(), false);
	}

#ifdef _DEBUG
	std::cout << std::endl << "2" << std::endl;
#endif /* _DEBUG */
	{
		stlsoft::ref_ptr<IUnknown>	p1(new Thing(), false);

		comstl::interface_cast_test<IUnknown>(p1);
	}

#ifdef _DEBUG
	std::cout << std::endl << "3" << std::endl;
#endif /* _DEBUG */
	{
		stlsoft::ref_ptr<IUnknown>	p1(new Thing(), false);

//		comstl::interface_cast_addref<IUnknown*> p2(p1);
	}

#ifdef _DEBUG
	std::cout << std::endl << "4" << std::endl;
#endif /* _DEBUG */
	{
		stlsoft::ref_ptr<IUnknown>	p1(new Thing(), false);

		stlsoft::ref_ptr<IUnknown>	p2 = comstl::try_interface_cast<IUnknown>(p1);
	}

#ifdef _DEBUG
	std::cout << std::endl << "5" << std::endl;
#endif /* _DEBUG */
	{
		stlsoft::ref_ptr<IUnknown>	p1(new Thing(), false);

		stlsoft::ref_ptr<IUnknown>	p2 = comstl::interface_cast<IUnknown>(p1);
	}

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
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.comstl.conversion.interface_cast: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        comstl::com_initialiser coinit;

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ////////////////////////////////////////////////////////////////////// */
