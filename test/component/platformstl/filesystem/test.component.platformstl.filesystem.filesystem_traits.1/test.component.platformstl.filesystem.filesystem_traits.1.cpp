/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.platformstl.filesystem.filesystem_traits.1.cpp
 *
 * Purpose:     Implementation file for the test.component.platformstl.filesystem.filesystem_traits.1 project.
 *
 * Created:     22nd February 2009
 * Updated:     11th August 2010
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

#include <platformstl/filesystem/filesystem_traits.hpp>

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
#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/file_path_buffer.hpp>
#include <platformstl/filesystem/path.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

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

    if(XTESTS_START_RUNNER("test.component.platformstl.filesystem.filesystem_traits.1", verbosity))
    {
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*platformstl/*/filesystem_traits.hpp", NULL);
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

    typedef std::basic_string<char>                     string_m_t;
    typedef platformstl::filesystem_traits<char>        traits_m_t;
    typedef platformstl::basic_file_path_buffer<char>   buffer_m_t;
    typedef platformstl::basic_path<char>               path_m_t;

static void test_1_17()
{
#if 0
    {
        path_m_t    path("H:/a/");

        string_m_t  dir(243, 'a');

        path.push(dir.c_str());

        traits_m_t::create_directory(path.c_str());

        ::GetLastError();
    }
#endif /* 0 */

    path_m_t    path("/");

    { for(size_t i = 0; ; ++i)
    {
        string_m_t  dir(1 + (i % 4), 'a' + (i % 4));

        path.push(dir.c_str());

        if(!traits_m_t::create_directory(path.c_str()))
        {
            path.pop();

            for(;;)
            {
                path.push("a");

                if(!traits_m_t::create_directory(path.c_str()))
                {
                    path.pop();
                    break;
                }
            }

            break;
        }
        else
        {
        }
    }}

    // Now we have the path, we need to start 
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
