/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.winstl.performance.threadtimes_counter.cpp
 *
 * Purpose:     Implementation file for the test.scratch.winstl.performance.threadtimes_counter project.
 *
 * Created:     4th September 2009
 * Updated:     25th April 2010
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


/* STLSoft Header Files */
#include <winstl/performance/performance_counter.hpp>
#include <winstl/performance/threadtimes_counter.hpp>

#include <winstl/winstl.h>

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
 * Macros and definitions
 */


/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if 0
typedef std::string     string_t;
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(...)
{
#if 1
    winstl::threadtimes_counter counter;
#else /* ? 0 */
    winstl::performance_counter counter;
#endif /* 0 */

    counter.start();
    ::Sleep(1000);
    counter.stop();

#if 0
    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_microseconds());

# if 1
    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_kernel_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_kernel_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_kernel_microseconds());

    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_user_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_user_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_user_microseconds());
# endif /* 0 */

    fputs("\n", stdout);
#endif /* 0 */


    counter.start();
    { for(size_t i = 0; i != 10000; ++i)
    {
        HANDLE h = CreateMutex(NULL, false, "abc.def");

        ::CloseHandle(h);
    }}
    counter.stop();

#if 0
    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_microseconds());

# if 1
    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_kernel_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_kernel_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_kernel_microseconds());

    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_user_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_user_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_user_microseconds());
# endif /* 0 */

    fputs("\n", stdout);
#endif /* 0 */


    counter.start();
    { for(size_t i = 0; i != 1000; ++i)
    {
        { for(size_t j = 0; j != 1000000; ++j)
        {
        }}
    }}
    counter.stop();

#if 0
    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_microseconds());

# if 1
    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_kernel_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_kernel_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_kernel_microseconds());

    fprintf(stdout, "t: %lus\n", (unsigned long)counter.get_user_seconds());
    fprintf(stdout, "t: %lums\n", (unsigned long)counter.get_user_milliseconds());
    fprintf(stdout, "t: %luus\n", (unsigned long)counter.get_user_microseconds());
# endif /* 0 */

    fputs("\n", stdout);
#endif /* 0 */


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

    try
    {
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
