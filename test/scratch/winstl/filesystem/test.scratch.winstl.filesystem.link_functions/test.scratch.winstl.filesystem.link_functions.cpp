/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.winstl.filesystem.link_functions.cpp
 *
 * Purpose:     Implementation file for the test.scratch.winstl.filesystem.link_functions project.
 *
 * Created:     14th February 2011
 * Updated:     14th February 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/synch/concepts.hpp>

/* STLSoft Header Files */
#include <winstl/filesystem/link_functions.h>

#include <winstl/error/error_desc.hpp>
#include <winstl/filesystem/file_creation_functions.h>
#include <winstl/filesystem/path.hpp>
#include <winstl/system/temporary_directory.hpp>

/* Standard C++ Header Files */
#include <exception>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#endif /* 0 */

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if 0
typedef char                        char_t;
typedef std::basic_string<char_t>   string_t;
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char** argv)
{
    { for(int i = 1; i < argc; ++i)
    {
        char const* const arg = argv[i];

    }}

	winstl::temporary_directory dir;

	winstl::path path1(dir);
	winstl::path path2(dir);

	path1 /= "abc";
	path2 /= "def";

	stlsoft::scoped_handle<char const*> scoper3(path1.c_str(), ::remove);
	stlsoft::scoped_handle<char const*> scoper4(path2.c_str(), ::remove);

	HANDLE hFile = winstl::file_create_always(path1.c_str(), GENERIC_WRITE, 0, 0);

	if(INVALID_HANDLE_VALUE == hFile)
	{
		fprintf(stderr, "could not open %s: %s\n", path1.c_str(), winstl::error_desc().c_str());

		return EXIT_FAILURE;
	}
	else
	{
		stlsoft::scoped_handle<HANDLE> scoper1(hFile, ::CloseHandle, INVALID_HANDLE_VALUE);

		;
	}

	DWORD numLinks1;
	DWORD numLinks2;

	winstl::hard_link_count_links(path1.c_str(), &numLinks1);

	if(!winstl::hard_link_create(path2.c_str(), path1.c_str()))
	{
		fprintf(stderr, "failed: %s\n", winstl::error_desc().c_str());
	}

	winstl::hard_link_count_links(path1.c_str(), &numLinks2);

//		tmpnam

    /* . */
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.winstl.filesystem.link_functions: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        return main_(argc, argv);
    }
    catch(std::bad_alloc&)
    {
        fputs("out of memory\n", stderr);
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());
    }
    catch(...)
    {
        fputs("Unhandled unknown error\n", stderr);
    }

    return EXIT_FAILURE;
}

/* ////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////// end of file //////////////////////////// */
