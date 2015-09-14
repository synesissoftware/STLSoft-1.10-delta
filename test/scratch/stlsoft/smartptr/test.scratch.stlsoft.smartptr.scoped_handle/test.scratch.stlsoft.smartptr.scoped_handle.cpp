/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.stlsoft.smartptr.scoped_handle.cpp
 *
 * Purpose:     Implementation file for the test.scratch.stlsoft.smartptr.scoped_handle project.
 *
 * Created:     28th April 2010
 * Updated:     11th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* STLSoft Header Files */
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <stlsoft/tr1/nullptr.hpp>

/* Standard C++ Header Files */
#include <exception>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

namespace
{

char const* String_Init()
{
	return "";
}
void String_Uninit(char const*)
{}


void Void_Init()
{}
void Void_Uninit()
{}

void Reserved_Init(void*)
{}
void Reserved_Uninit(void*)
{}

} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    {
		char const* h = String_Init();

		stlsoft::scoped_handle<char const*>	scoper(h, String_Uninit);
	}

# if !defined(STLSOFT_COMPILER_IS_GCC) || \
     __GNUC__ > 4 || \
     (   __GNUC__ == 3 && \
         __GNUC_MINOR__ > 4)

    {
		Void_Init();

		stlsoft::scoped_handle<void>	scoper(Void_Uninit);
	}

    {
		Reserved_Init(NULL);

		stlsoft::scoped_handle<void*>	scoper(NULL, Reserved_Uninit);
	}

    {
		Reserved_Init(nullptr);

		stlsoft::scoped_handle<void*>	scoper(nullptr, Reserved_Uninit);
	}

# endif /* compiler */

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
        puts("test.scratch.stlsoft.smartptr.scoped_handle: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

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

/* ///////////////////////////// end of file //////////////////////////// */
