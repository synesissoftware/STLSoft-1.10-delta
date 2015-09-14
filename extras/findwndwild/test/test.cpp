/* /////////////////////////////////////////////////////////////////////////////
 * File:        findwndwild.cpp
 *
 * Purpose:     Implementation file for the findwndwild project.
 *
 * Created:     4th August 2006
 * Updated:     11th March 2007
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2007, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////////// */


#include <cstring/implicit_link.h>
#include <shwild/implicit_link.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL Header Files */
#include <platformstl/platformstl.hpp>


/* Standard C++ Header Files */
#include <exception>

#if !defined(__WATCOMC__) && \
    (   !defined(_MSC_VER) || \
        _MSC_VER >= 1100)

#else /* ? __WATCOMC__ */
namespace std
{
    using ::exception;
}
#endif /* __WATCOMC__ */

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */


/* /////////////////////////////////////////////////////////////////////////////
 * Globals
 */

#if defined(_DEBUG) || \
    defined(_SYB_DEBUG)
static int  s_bDebugging                =   true;
#else /* ? debug */
static int  s_bDebugging                =   false;
#endif /* debug */
//extern "C" const char FE_SIMPLE_PROCESS_IDENTITY[]    =   "findwndwild";

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if 0
typedef std::string     string_t;
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv);

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char *argv[])
{
    int                 iRet        =   EXIT_SUCCESS;
    int                 bVerbose    =   true;

    { for(int i = 1; i < argc; ++i)
    {
        char const  *const  arg =   argv[i];

        if(arg[0] == '-')
        {
            if(arg[1] == '-')
            {
                /* -- arguments */
                usage(1, "Invalid argument(s) specified", i, argc, argv);
            }
            else
            {
                /* - arguments */
                switch(arg[1])
                {
                    case    '?':
                        usage(1, NULL, -1, argc, argv);
                        break;
                    case    's':
                        bVerbose    =   false;
                        break;
                    case    'v':
                        bVerbose    =   true;
                        break;
                    default:
                        usage(1, "Invalid argument(s) specified", i, argc, argv);
                        break;
                }
            }
        }
        else
        {
            /* other arguments */
            usage(1, "Invalid argument(s) specified", i, argc, argv);
        }
    }}

    /* . */
    return iRet;
}

int main(int argc, char *argv[])
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
        puts("findwndwild: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception &x)
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

/* ////////////////////////////////////////////////////////////////////////// */

static void usage(int bExit, char const *reason, int invalidArg, int argc, char **argv)
{
    FILE    *stm    =   (NULL == reason) ? stdout : stderr;


    fprintf(stm, "\n");
    fprintf(stm, "  findwndwild\n\n");
    fprintf(stm, "\n");

    if(NULL != reason)
    {
        fprintf(stm, "  Error: %s\n", reason);
        fprintf(stm, "\n");
    }

    if(0 < invalidArg)
    {
        fprintf(stm, "  First invalid argument #%d: %s\n", invalidArg, argv[invalidArg]);
        fprintf(stm, "  Arguments were (first bad marked *):\n\n");
        { int i; for(i = 1; i < argc; ++i)
        {
            fprintf(stm, "  %s%s\n", (i == invalidArg) ? "* " : "  ", argv[i]);
        }}
        fprintf(stm, "\n");
    }

#if 0
    fprintf(stm, "  USAGE: findwndwild [{-w | -p<root-paths> | -h}] [-u] [-d] [{-v | -s}] <search-spec>\n");
    fprintf(stm, "    where:\n\n");
    fprintf(stm, "    -w             - searches from the current working directory. The default\n");
    fprintf(stm, "    -p<root-paths> - searches from the given root path(s), separated by \';\',\n");
    fprintf(stm, "                     eg.\n");
    fprintf(stm, "                       -p\"c:\\windows;x:\\bin\"\n");
    fprintf(stm, "    -r             - deletes readonly files\n");
    fprintf(stm, "    -h             - searches from the roots of all drives on the system\n");
    fprintf(stm, "    -d             - displays the path(s) searched\n");
    fprintf(stm, "    -u             - do not act recursively\n");
    fprintf(stm, "    -v             - verbose output. Prints time, attributes, size and path. (default)\n");
    fprintf(stm, "    -s             - succinct output. Prints path only\n");
    fprintf(stm, "    <search-spec>  - one or more file search specifications, separated by \';\',\n");
    fprintf(stm, "                     eg.\n");
    fprintf(stm, "                       \"*.exe\"\n");
    fprintf(stm, "                       \"myfile.ext\"\n");
    fprintf(stm, "                       \"*.exe;*.dll\"\n");
    fprintf(stm, "                       \"*.xl?;report.*\"\n");
    fprintf(stm, "\n");
    fprintf(stm, "  Contact %s\n", _nameSynesisSoftware);
    fprintf(stm, "    at \"%s\",\n", _wwwSynesisSoftware_SystemTools);
    fprintf(stm, "    or, via email, at \"%s\"\n", _emailSynesisSoftware_SystemTools);
    fprintf(stm, "\n");
#endif /* 0 */

    if(bExit)
    {
        exit(EXIT_FAILURE);
    }
}

/* ////////////////////////////////////////////////////////////////////////// */
