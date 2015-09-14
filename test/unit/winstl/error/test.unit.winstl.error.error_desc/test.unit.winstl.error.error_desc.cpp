/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.error.error_desc.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.error.error_desc project.
 *
 * Created:     16th February 2011
 * Updated:     9th December 2013
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011-2013, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/error/error_desc.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xCover Header Files */
#ifdef STLSOFT_USE_XCOVER
# include <xcover/xcover.h>
#endif /* STLSOFT_USE_XCOVER */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <winstl/dl/module.hpp>
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/memory/auto_buffer.hpp>

/* Standard C++ Header Files */
#include <string>
#include <vector>

/* Standard C Header Files */
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_implicit_invocation_of_GetLastError(void);

    static void test_invocation_with_argument_of_literal_0(void);

    static void test_named_instance_1_LONG_argument(void);
    static void test_named_instance_1_DWORD_argument(void);
    static void test_temporary_instance_1_LONG_argument(void);
    static void test_temporary_instance_1_DWORD_argument(void);
    static void test_temporary_instance_1_LONG_and_1_ccs_argument(void);
    static void test_temporary_instance_1_DWORD_and_1_ccs_argument(void);
    static void test_temporary_instance_1_LONG_and_1_modules_argument(void);

    static void test_2_01(void);
    static void test_2_02(void);
    static void test_2_03(void);

#ifdef STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_
    static void test_3_01(void);
    static void test_3_02(void);
    static void test_3_03(void);
#endif /* STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_ */

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Encoding
 */

#ifdef UNICODE
# define XTESTS_TEST_STRING_EQUAL			XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? UNICODE */
# define XTESTS_TEST_STRING_EQUAL			XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* UNICODE */

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.error.error_desc", verbosity))
    {
        XTESTS_RUN_CASE(test_implicit_invocation_of_GetLastError);

        XTESTS_RUN_CASE(test_invocation_with_argument_of_literal_0);

        XTESTS_RUN_CASE(test_named_instance_1_LONG_argument);
        XTESTS_RUN_CASE(test_named_instance_1_DWORD_argument);
        XTESTS_RUN_CASE(test_temporary_instance_1_LONG_argument);
        XTESTS_RUN_CASE(test_temporary_instance_1_DWORD_argument);
        XTESTS_RUN_CASE(test_temporary_instance_1_LONG_and_1_ccs_argument);
        XTESTS_RUN_CASE(test_temporary_instance_1_DWORD_and_1_ccs_argument);
        XTESTS_RUN_CASE(test_temporary_instance_1_LONG_and_1_modules_argument);

        XTESTS_RUN_CASE(test_2_01);
        XTESTS_RUN_CASE(test_2_02);
        XTESTS_RUN_CASE(test_2_03);

#ifdef STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_
        XTESTS_RUN_CASE(test_3_01);
        XTESTS_RUN_CASE(test_3_02);
        XTESTS_RUN_CASE(test_3_03);
#endif /* STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_ */

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/error_desc.hpp", NULL);
#endif /* STLSOFT_USE_XCOVER */

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

    static std::string lookup_error_a(int code, HMODULE hModule = NULL)
    {
		DWORD	flags	=	0;
		LPSTR	buff;

		flags |= FORMAT_MESSAGE_ALLOCATE_BUFFER;
		flags |= FORMAT_MESSAGE_IGNORE_INSERTS;
		flags |= FORMAT_MESSAGE_FROM_SYSTEM;
		if(NULL != hModule)
		{
			flags |= FORMAT_MESSAGE_FROM_HMODULE;
		}

		DWORD	r = ::FormatMessageA(
			flags
		,	hModule
		,	code
		,	MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
		,	(LPSTR)&buff
		,	0
		,	NULL
		);

		std::string s(buff, r);

		::LocalFree(buff);

		for(;!s.empty();)
		{
			switch(s[s.size() - 1])
			{
				case	'.':
					if(s.size() - 1 == s.find('.'))
					{
				case	' ':
				case	'\t':
				case	'\r':
				case	'\n':
					s.resize(s.size() - 1);
					break;
					}
					else
					{
				default:
					return s;
					}
			}
		}

		return s;
    }

#ifdef UNICODE
    static std::wstring lookup_error_w(int code)
    {
        return stlsoft::m2w(lookup_error_a(code).c_str()).c_str();
    }

# define lookup_error			lookup_error_w
#else /* ? UNICODE */
# define lookup_error			lookup_error_a
#endif /* UNICODE */


    static DWORD errors[] = 
    {
        ERROR_SUCCESS,
        ERROR_INVALID_FUNCTION,
		ERROR_SERIAL_NO_DEVICE,
		ERROR_FILE_NOT_FOUND,
		ERROR_BAD_ENVIRONMENT,
		ERROR_OUTOFMEMORY,
		ERROR_WRITE_PROTECT,
		ERROR_OUT_OF_PAPER,
		ERROR_LOCK_VIOLATION,
		ERROR_INVALID_MODULETYPE,
    };


static void test_implicit_invocation_of_GetLastError()
{
    ::SetLastError(ERROR_OUTOFMEMORY);

    winstl::error_desc ed;

    XTESTS_TEST_STRING_EQUAL(lookup_error(ERROR_OUTOFMEMORY), ed);
}


static void test_invocation_with_argument_of_literal_0()
{
    winstl::error_desc ed(0);

    XTESTS_TEST_STRING_EQUAL(lookup_error(0), ed);
}


static void test_named_instance_1_LONG_argument()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
    {
        LONG const e = stlsoft_static_cast(LONG, errors[i]);

        winstl::error_desc ed(e);

        XTESTS_TEST_STRING_EQUAL(lookup_error(e), ed);
    }}
}

static void test_named_instance_1_DWORD_argument()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
    {
        DWORD const e = stlsoft_static_cast(DWORD, errors[i]);

        winstl::error_desc ed(e);

        XTESTS_TEST_STRING_EQUAL(lookup_error(e), ed);
    }}
}

static void test_temporary_instance_1_LONG_argument()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
    {
        LONG const e = stlsoft_static_cast(LONG, errors[i]);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(e), winstl::error_desc(e));
    }}
}

static void test_temporary_instance_1_DWORD_argument()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
    {
        DWORD const e = stlsoft_static_cast(DWORD, errors[i]);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(e), winstl::error_desc(e));
    }}
}

static void test_temporary_instance_1_LONG_and_1_ccs_argument()
{
#if _STLSOFT_VER < 0x010a0000
# define dl_exception	windows_exception
#endif

	try
	{
		winstl::module panCom("PANTHEIOS.COM.DLL");

        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
        {
            LONG const e = stlsoft_static_cast(LONG, errors[i]);

		    winstl::error_desc ed(e, "PANTHEIOS.COM.DLL");

		    XTESTS_TEST_STRING_EQUAL(lookup_error(e, panCom.get()), ed);
        }}
	}
	catch(winstl::dl_exception& )
	{
	}
}

static void test_temporary_instance_1_DWORD_and_1_ccs_argument(void)
{
#if _STLSOFT_VER < 0x010a0000
# define dl_exception	windows_exception
#endif

	try
	{
		winstl::module panCom("PANTHEIOS.COM.DLL");

        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
        {
            DWORD const e = stlsoft_static_cast(DWORD, errors[i]);

		    winstl::error_desc ed(e, "PANTHEIOS.COM.DLL");

		    XTESTS_TEST_STRING_EQUAL(lookup_error(e, panCom.get()), ed);
        }}
	}
	catch(winstl::dl_exception& )
	{
	}
}

static void test_temporary_instance_1_LONG_and_1_modules_argument()
{
	std::vector<std::string> modulePaths;

	modulePaths.push_back("user32");
	modulePaths.push_back("advapi32");
	modulePaths.push_back("kernel32");
	modulePaths.push_back("PANTHEIOS.COM.DLL");

	winstl::error_desc ed(987654, modulePaths);

    int error = 987654;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(error), winstl::error_desc(error));

    STLSOFT_SUPPRESS_UNUSED(error);
}


static void test_2_01()
{
    winstl::error_desc_a ed(0);

    XTESTS_TEST_PASSED();
}

static void test_2_02()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
    {
        const int error = errors[i];

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(error), winstl::error_desc_a(error));
    }}
}

static void test_2_03()
{
    int error = 987654;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(error), winstl::error_desc_a(error));

    STLSOFT_SUPPRESS_UNUSED(error);
}


#ifdef STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_
static void test_3_01()
{
    winstl::error_desc_w ed(0);

    XTESTS_TEST_PASSED();
}

static void test_3_02()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
    {
        const int error = errors[i];

        XTESTS_TEST_WIDE_STRING_EQUAL(lookup_error_w(error), winstl::error_desc_w(error));
    }}
}

static void test_3_03()
{
    const int error = 987654;

    XTESTS_TEST_WIDE_STRING_EQUAL(lookup_error_w(error), winstl::error_desc_w(error));
}
#endif /* STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_ */


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
