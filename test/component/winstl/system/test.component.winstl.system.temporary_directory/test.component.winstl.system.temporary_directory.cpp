/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.system.temporary_directory.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.system.temporary_directory project.
 *
 * Created:     31st December 2008
 * Updated:     12th August 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/system/temporary_directory.hpp>

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

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Character encoding
 */

#ifdef UNICODE

# define XTESTS_TEST_STRING_EQUAL       XTESTS_TEST_WIDE_STRING_EQUAL

#else /* ? UNICODE */

# define XTESTS_TEST_STRING_EQUAL       XTESTS_TEST_MULTIBYTE_STRING_EQUAL

#endif /* UNICODE */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);
    static void test_1_20(void);
    static void test_1_21(void);
    static void test_1_22(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.winstl.system.temporary_directory", verbosity))
    {
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/temporary_directory.hpp", NULL);
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

    typedef std::basic_string<TCHAR>        string_t;

    static string_t get_temp_dir()
    {
        TCHAR   path[1 + _MAX_PATH];
        DWORD   dw = ::GetTempPath(STLSOFT_NUM_ELEMENTS(path), path); 

        return string_t(path, dw);
    }


static void test_1_17()
{
    winstl::temporary_directory t;

#if defined(STLSOFT_COMPILER_IS_BORLAND)
    XTESTS_TEST_STRING_EQUAL(get_temp_dir(), t.c_str());
#else /* ? compiler */
    XTESTS_TEST_STRING_EQUAL(get_temp_dir(), t);
#endif /* compiler */
}

static void test_1_18()
{
}

static void test_1_19()
{
}

static void test_1_20()
{
}

static void test_1_21()
{
}

static void test_1_22()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
