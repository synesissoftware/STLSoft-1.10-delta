/* /////////////////////////////////////////////////////////////////////////
 * File:        mmap.cpp
 *
 * Purpose:     Implementation file for the mmap project.
 *
 * Created:     27th August 2010
 * Updated:     31st August 2010
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


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS

/* FastFormat Header Files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

/* Pantheios Header Files */
#include <pantheios/pan.hpp>
#include <pantheios/inserters/args.hpp>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <winstl/filesystem/file_creation_functions.h>
#include <winstl/filesystem/file_seek_functions.h>
#include <winstl/filesystem/file_size_functions.h>
#include <winstl/filesystem/memory_map_functions.h>
#include <winstl/system/system_info.hpp>
#include <platformstl/platformstl.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#endif /* 0 */

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

extern "C" const char PANTHEIOS_FE_PROCESS_IDENTITY[]    =   "mmap";

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

using winstl::ws_uint32_t;
using winstl::ws_uint64_t;
using winstl::ws_uintptr_t;

static int main_(int /* argc */, char** /*argv*/)
{
	winstl::system_info::allocation_granularity();

	// Create a 3kB file, read-map it, then check size
	{
		char const TEST_FILE_NAME[] = "test-file-1";

		stlsoft::scoped_handle<char const*> scoper(TEST_FILE_NAME, ::DeleteFile);

		{
			HANDLE	h1	=	winstl::file_create_always(TEST_FILE_NAME, GENERIC_WRITE, 0, 0);

			winstl::file_set_size_by_handle_64(h1, 3072);

			::CloseHandle(h1);
		}

		{
			HANDLE	h1	=	winstl::file_open_existing(TEST_FILE_NAME, GENERIC_READ, 0, 0);
			DWORD	e1	=	::GetLastError();
			HANDLE	h2	=	::CreateFileMapping(h1, NULL, PAGE_READONLY, 0, 3072, NULL);
			DWORD	e2	=	::GetLastError();
			void*	v1	=	::MapViewOfFile(h2, FILE_MAP_READ, 0, 0, 0);
			DWORD	e3	=	::GetLastError();

			::CloseHandle(h1);
			::CloseHandle(h2);
			::UnmapViewOfFile(v1);
		}

		{
			ws_uint64_t size;

			winstl::file_get_size_by_name_64(TEST_FILE_NAME, &size);

			size = size;
		}
	}

	// Create a 3kB file, read/write-map it, then check size
	{
		char const TEST_FILE_NAME[] = "test-file-2";

		stlsoft::scoped_handle<char const*> scoper(TEST_FILE_NAME, ::DeleteFile);

		{
			HANDLE	h1	=	winstl::file_create_always(TEST_FILE_NAME, GENERIC_WRITE, 0, 0);

			winstl::file_set_size_by_handle_64(h1, 3072);

			::CloseHandle(h1);
		}

#if 1
		{
			HANDLE			h1		=	winstl::file_open_existing(TEST_FILE_NAME, GENERIC_READ | GENERIC_WRITE, 0, 0);
			ws_uintptr_t	viewSize;
			void*			memory	=	winstl::map_readwrite_view_of_file_by_handle(
											h1
										,	0
										,	4096
										,	&viewSize);

			::CloseHandle(h1);
			winstl::unmap_view_of_file(memory);
		}
#else /* ? 0 */
		{
			HANDLE	h1	=	winstl::file_open_existing(TEST_FILE_NAME, GENERIC_READ | GENERIC_WRITE, 0, 0);
			DWORD	e1	=	::GetLastError();
			HANDLE	h2	=	::CreateFileMapping(h1, NULL, PAGE_READWRITE, 0, 4096, NULL);
			DWORD	e2	=	::GetLastError();
			void*	v1	=	::MapViewOfFile(h2, FILE_MAP_WRITE, 0, 0, 0);
			DWORD	e3	=	::GetLastError();

			::CloseHandle(h1);
			::CloseHandle(h2);
			::UnmapViewOfFile(v1);
		}
#endif /* 0 */

		{
			ws_uint64_t size;

			winstl::file_get_size_by_name_64(TEST_FILE_NAME, &size);

			size = size;
		}
	}

	// Create a 3kB file, write-map it, then check size
	{
		char const TEST_FILE_NAME[] = "test-file-3";

		stlsoft::scoped_handle<char const*> scoper(TEST_FILE_NAME, ::DeleteFile);

		{
			HANDLE	h1	=	winstl::file_create_always(TEST_FILE_NAME, GENERIC_WRITE, 0, 0);

			winstl::file_set_size_by_handle_64(h1, 3072);

			::CloseHandle(h1);
		}

		{
			HANDLE	h1	=	winstl::file_open_existing(TEST_FILE_NAME, GENERIC_WRITE, 0, 0);
			DWORD	e1	=	::GetLastError();
			HANDLE	h2	=	::CreateFileMapping(h1, NULL, PAGE_WRITECOPY, 0, 4096, NULL);
			DWORD	e2	=	::GetLastError();
			void*	v1	=	::MapViewOfFile(h2, FILE_MAP_WRITE, 0, 0, 0);
			DWORD	e3	=	::GetLastError();

			::CloseHandle(h1);
			::CloseHandle(h2);
			::UnmapViewOfFile(v1);
		}

		{
			ws_uint64_t size;

			winstl::file_get_size_by_name_64(TEST_FILE_NAME, &size);

			size = size;
		}
	}

#if 0
	{
		HANDLE	h1	=	winstl::file_create_always("f1", GENERIC_WRITE, 0, 0);

		HANDLE	h2	=	winstl::file_create_always("f2", GENERIC_READ, 0, 0);

		HANDLE	h3	=	winstl::file_create_always("f3", GENERIC_WRITE | GENERIC_READ, 0, 0);

		winstl::set_file_size_by_handle_64(h1, 3072);
		winstl::set_file_size_by_handle_64(h2, 3072);
		winstl::set_file_size_by_handle_64(h3, 3072);

		ws_uintptr_t	n1;
		void*			p1	=	winstl::map_readonly_view_of_file_by_handle(h1, &n1);

		if(NULL != p1)
		{
			winstl::unmap_view_of_file(p1);
		}

		ws_uintptr_t	n2;
		void*			p2	=	winstl::map_readonly_view_of_file_by_handle(h2, &n2);

		if(NULL != p2)
		{
			winstl::unmap_view_of_file(p2);
		}

		ws_uintptr_t	n3;
		void*			p3	=	winstl::map_readonly_view_of_file_by_handle(h3, &n3);

		if(NULL != p3)
		{
			winstl::unmap_view_of_file(p3);
		}

		::CloseHandle(h1);
		::CloseHandle(h2);
		::CloseHandle(h3);

		::DeleteFile("f1");
		::DeleteFile("f2");
		::DeleteFile("f3");
	}

	{
		HANDLE	h1	=	winstl::file_create_always("f1", GENERIC_WRITE, 0, 0);

		HANDLE	h2	=	winstl::file_create_always("f2", GENERIC_READ, 0, 0);

		HANDLE	h3	=	winstl::file_create_always("f3", GENERIC_WRITE | GENERIC_READ, 0, 0);

		winstl::set_file_size_by_handle_64(h1, 3072);
		winstl::set_file_size_by_handle_64(h2, 3072);
		winstl::set_file_size_by_handle_64(h3, 3072);

		ws_uintptr_t	n1;
		void*			p1	=	winstl::map_readonly_view_of_file_by_handle(h1, 0, 3072, &n1);

		if(NULL != p1)
		{
			winstl::unmap_view_of_file(p1);
		}
		else
		{
			p1 = winstl::map_readonly_view_of_file_by_handle(h1, 0, 4096, &n1);

			if(NULL != p1)
			{
				winstl::unmap_view_of_file(p1);
			}
		}

		ws_uintptr_t	n2;
		void*			p2	=	winstl::map_readonly_view_of_file_by_handle(h2, 0, 3072, &n2);

		if(NULL != p2)
		{
			winstl::unmap_view_of_file(p2);
		}

		ws_uintptr_t	n3;
		void*			p3	=	winstl::map_readonly_view_of_file_by_handle(h3, 0, 3072, &n3);

		if(NULL != p3)
		{
			winstl::unmap_view_of_file(p3);
		}

		::CloseHandle(h1);
		::CloseHandle(h2);
		::CloseHandle(h3);

		::DeleteFile("f1");
		::DeleteFile("f2");
		::DeleteFile("f3");
	}

	{
		HANDLE	h1	=	winstl::file_create_always("f1", GENERIC_WRITE, 0, 0);

		HANDLE	h2	=	winstl::file_create_always("f2", GENERIC_READ, 0, 0);

		HANDLE	h3	=	winstl::file_create_always("f3", GENERIC_WRITE | GENERIC_READ, 0, 0);

		winstl::set_file_size_by_handle_64(h1, 65536);
		winstl::set_file_size_by_handle_64(h2, 65536);
		winstl::set_file_size_by_handle_64(h3, 65536);

		ws_uintptr_t	n1;
		void*			p1	=	winstl::map_readonly_view_of_file_by_handle(h1, 16384, 4096, &n1);

		if(NULL != p1)
		{
			winstl::unmap_view_of_file(p1);
		}

		ws_uintptr_t	n2;
		void*			p2	=	winstl::map_readonly_view_of_file_by_handle(h2, 16384, 4096, &n2);

		if(NULL != p2)
		{
			winstl::unmap_view_of_file(p2);
		}

		ws_uintptr_t	n3;
		void*			p3	=	winstl::map_readonly_view_of_file_by_handle(h3, 16384, 4096, &n3);

		if(NULL != p3)
		{
			winstl::unmap_view_of_file(p3);
		}

		::CloseHandle(h1);
		::CloseHandle(h2);
		::CloseHandle(h3);

		::DeleteFile("f1");
		::DeleteFile("f2");
		::DeleteFile("f3");
	}
#endif /* 0 */

    return EXIT_SUCCESS;
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
        puts("mmap: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        pantheios::log_ALERT("Unexpected general error: ", x, ". Application terminating");

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        pantheios::logputs(pantheios::emergency, "Unhandled unknown error");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
