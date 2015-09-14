/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.error.error_desc.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.error.error_desc project.
 *
 * Created:     23rd May 2009
 * Updated:     12th August 2010
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


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/error/error_desc.hpp>

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
#include <stlsoft/stlsoft.h>
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/memory/auto_buffer.hpp>

/* Standard C Header Files */
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_01(void);
    static void test_1_02(void);
    static void test_1_03(void);

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
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.error.error_desc", verbosity))
    {
        XTESTS_RUN_CASE(test_1_01);
        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);

        XTESTS_RUN_CASE(test_2_01);
        XTESTS_RUN_CASE(test_2_02);
        XTESTS_RUN_CASE(test_2_03);

#ifdef STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_
        XTESTS_RUN_CASE(test_3_01);
        XTESTS_RUN_CASE(test_3_02);
        XTESTS_RUN_CASE(test_3_03);
#endif /* STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_ */

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/error_desc.hpp", NULL);
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

	static std::string lookup_error_a(int code)
	{
#ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS

		char	buff[2001]; // A likely guess, but still no guarantee

		if(0 != ::strerror_s(&buff[0], STLSOFT_NUM_ELEMENTS(buff), code))
		{
			buff[0] = '\0';
		}

		return buff;
#else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
		return ::strerror(code);
#endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
	}

	static std::wstring lookup_error_w(int code)
	{
		return stlsoft::m2w(lookup_error_a(code).c_str()).c_str();
	}

	static int errors[] = 
	{
		ENOMEM,
		EPERM,
		ENOENT,
		EINTR,
		EIO,
		EBADF,
		EAGAIN,
		EACCES,
		E2BIG,
		ENOEXEC,
		ENAMETOOLONG,
	};


static void test_1_01()
{
	stlsoft::error_desc ed(0);

	XTESTS_TEST_PASSED();
}

static void test_1_02()
{
	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
	{
		const int error = errors[i];

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(error), stlsoft::error_desc(error));
	}}
}

static void test_1_03()
{
	int error = 987654;

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(error), stlsoft::error_desc(error));

	STLSOFT_SUPPRESS_UNUSED(error);
}


static void test_2_01()
{
	stlsoft::error_desc_a ed(0);

	XTESTS_TEST_PASSED();
}

static void test_2_02()
{
	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
	{
		const int error = errors[i];

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(error), stlsoft::error_desc_a(error));
	}}
}

static void test_2_03()
{
	int error = 987654;

	XTESTS_TEST_MULTIBYTE_STRING_EQUAL(lookup_error_a(error), stlsoft::error_desc_a(error));

	STLSOFT_SUPPRESS_UNUSED(error);
}


#ifdef STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_
static void test_3_01()
{
	stlsoft::error_desc_w ed(0);

	XTESTS_TEST_PASSED();
}

static void test_3_02()
{
	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(errors); ++i)
	{
		const int error = errors[i];

		XTESTS_TEST_WIDE_STRING_EQUAL(lookup_error_w(error), stlsoft::error_desc_w(error));
	}}
}

static void test_3_03()
{
	const int error = 987654;

	XTESTS_TEST_WIDE_STRING_EQUAL(lookup_error_w(error), stlsoft::error_desc_w(error));
}
#endif /* STLSOFT_ERROR_DESC_WIDE_STRING_SUPPORT_ */



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
