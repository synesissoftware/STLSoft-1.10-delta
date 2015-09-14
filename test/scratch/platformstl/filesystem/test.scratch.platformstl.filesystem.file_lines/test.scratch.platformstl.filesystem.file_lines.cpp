/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.platformstl.filesystem.file_lines.cpp
 *
 * Purpose:     Implementation file for the test.scratch.platformstl.filesystem.file_lines project.
 *
 * Created:     3rd September 2010
 * Updated:     3rd September 2010
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
#include <stlsoft/util/minmax.hpp>
#include <platformstl/filesystem/file_lines.hpp>

/* UNIXem Header Files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/unixem.h>
#endif /* Win32 || Win64 */

/* STLSoft Header Files */
#include <winstl/error/error_desc.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <set>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#endif /* 0 */

/* Standard C Header Files */
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

static int main_(int argc, char** argv)
{
	if(2 != argc)
	{
		fprintf(stderr, "USAGE: %s <file>\n", "test.scratch.platformstl.filesystem.file_lines");

		return EXIT_FAILURE;
	}
	else
	{
#if 0
		{
			char const*	path	=	argv[1];
			HANDLE		hFile	=	::CreateFile(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);

			if(INVALID_HANDLE_VALUE != hFile)
			{
				stlsoft::scoped_handle<HANDLE> scoper1(hFile, ::CloseHandle, INVALID_HANDLE_VALUE);

				HANDLE hMap = ::CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);

				if(NULL != hMap)
				{
					stlsoft::scoped_handle<HANDLE> scoper2(hMap, ::CloseHandle);

					ULARGE_INTEGER size;

					size.LowPart = ::GetFileSize(hFile, &size.HighPart);

					fprintf(stdout, "mapping from %s, of %lu bytes\n", path, static_cast<unsigned long>(size.QuadPart));

					std::set<DWORD> errors;

					{ for(size_t i = 0; i != stlsoft::minimum(0xFFFFF800, static_cast<size_t>(size.QuadPart)); i += 2048u)
					{
						void* pv = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, i);

						if(NULL != pv)
						{
							UnmapViewOfFile(pv);
						}
						else
						{
							DWORD				e = ::GetLastError();
							winstl::error_desc	ed(e);

							if(errors.end() == errors.find(e))
							{
								fprintf(stderr, "failed at 0x%08x: %d: %s\n", i, e, ed.c_str());

								errors.insert(e);
							}
						}
					}}
				}
			}
		}
#endif /* 0 */


		{
			platformstl::file_lines lines(argv[1]);
		}

	    return EXIT_SUCCESS;
	}
}

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _DEBUG */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _DEBUG */

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
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
        fputs("Unhandled unknown error\n", stderr);

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
