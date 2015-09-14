/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.system.searchpath_sequence.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.system.searchpath_sequence project.
 *
 * Created:     28th January 2009
 * Updated:     9th June 2010
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

#include <winstl/system/searchpath_sequence.hpp>

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
#include <stlsoft/string/string_tokeniser.hpp>
#include <winstl/filesystem/current_directory.hpp>
#include <winstl/filesystem/filesystem_traits.hpp>
#include <winstl/system/environment_variable.hpp>
#include <winstl/system/module_directory.hpp>
#include <winstl/system/system_directory.hpp>
#include <winstl/system/system_version.hpp>
#include <winstl/system/windows_directory.hpp>

/* Standard C++ Header Files */
#include <iterator>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.system.searchpath_sequence", verbosity))
    {
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/searchpath_sequence.hpp", NULL);
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

    typedef winstl::filesystem_traits<char>     traits_m_t;
    typedef winstl::filesystem_traits<wchar_t>  traits_w_t;

    typedef std::basic_string<char>             string_m_t;
    typedef std::basic_string<wchar_t>          string_w_t;

    typedef std::vector<string_m_t>             strings_m_t;
    typedef std::vector<string_w_t>             strings_w_t;

static void test_1_14()
{
    winstl::searchpath_sequence_a   searchpaths;

    XTESTS_TEST_PASSED();
}

static void test_1_15()
{
    winstl::searchpath_sequence_a   searchpaths;
    strings_m_t                     results;

    std::copy(  searchpaths.begin(), searchpaths.end()
            ,   std::back_inserter(results));

    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(5u, results.size());
}

static void test_1_16()
{
    winstl::searchpath_sequence_a   searchpaths;
    strings_m_t                     results;
    strings_m_t                     expected;

    std::copy(  searchpaths.begin(), searchpaths.end()
            ,   std::back_inserter(results));

    expected.push_back(stlsoft::c_str_ptr(winstl::module_directory(NULL)));

    expected.push_back(stlsoft::c_str_ptr(winstl::current_directory()));

    expected.push_back(stlsoft::c_str_ptr(winstl::system_directory()));

    if(winstl::system_version::winnt())
    {
        CHAR    system16[_MAX_PATH + 1];
        CHAR*   file_part;

        traits_m_t::get_full_path_name(winstl::system_directory().c_str(), STLSOFT_NUM_ELEMENTS(system16), system16, &file_part);
        traits_m_t::char_copy(file_part, "SYSTEM", 7);

        expected.push_back(system16);
    }

    expected.push_back(stlsoft::c_str_ptr(winstl::windows_directory()));

    string_m_t                      PATH(winstl::environment_variable("PATH"));

    stlsoft::string_tokeniser<string_m_t, char> PATHs(PATH, ';');

    { for(stlsoft::string_tokeniser<string_m_t, char>::const_iterator b = PATHs.begin(); b != PATHs.end(); ++b)
    {
        expected.push_back((*b));
    }}

//  std::for_each(PATHs.begin(), PATHs.end()
//          ,   std::back_inserter(expected));

    XTESTS_TEST_INTEGER_EQUAL(expected.size(), results.size());
    if(expected.size() == results.size())
    {
        { for(size_t i = 0; i != expected.size(); ++i)
        {
            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX(expected[i], results[i]);
        }}
    }
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
