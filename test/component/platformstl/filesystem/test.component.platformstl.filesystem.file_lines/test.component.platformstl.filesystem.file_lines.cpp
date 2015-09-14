/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.platformstl.filesystem.file_lines.cpp
 *
 * Purpose:     Implementation file for the test.component.platformstl.filesystem.file_lines project.
 *
 * Created:     10th July 2010
 * Updated:     25th November 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/stlsoft.h>
#if defined(STLSOFT_COMPILER_IS_GCC)
# include <platformstl/filesystem/path.hpp>
#endif

#include <platformstl/filesystem/file_lines.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
# pragma warning(disable : 4996)
#endif

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
#ifdef _STLSOFT_1_10_VER
# include <stlsoft/filesystem/FILE_stream.hpp>
#endif
#include <stlsoft/string/simple_string.hpp>
#include <stlsoft/string/string_view.hpp>
#include <platformstl/filesystem/current_directory.hpp>
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

    static void test_one_line_0(void);
    static void test_one_line_1(void);
    static void test_one_line_2(void);
    static void test_one_line_3(void);
    static void test_one_line_4(void);
    static void test_one_line_5(void);
    static void test_one_line_6(void);
    static void test_one_line_7(void);
    static void test_one_line_8(void);
    static void test_one_line_9(void);

#ifdef _STLSOFT_1_10_VER
    static void test_three_lines_CR_0(void);
    static void test_three_lines_CR_1(void);
    static void test_three_lines_CR_2(void);
    static void test_three_lines_CR_3(void);
    static void test_three_lines_CR_4(void);
    static void test_three_lines_CR_5(void);
    static void test_three_lines_CR_6(void);
    static void test_three_lines_CR_7(void);
    static void test_three_lines_CR_8(void);
    static void test_three_lines_CR_9(void);
#endif // _STLSOFT_1_10_VER

#ifdef _STLSOFT_1_10_VER
    static void test_three_lines_LF_0(void);
    static void test_three_lines_LF_1(void);
    static void test_three_lines_LF_2(void);
    static void test_three_lines_LF_3(void);
    static void test_three_lines_LF_4(void);
    static void test_three_lines_LF_5(void);
    static void test_three_lines_LF_6(void);
    static void test_three_lines_LF_7(void);
    static void test_three_lines_LF_8(void);
    static void test_three_lines_LF_9(void);
#endif // _STLSOFT_1_10_VER

    static void test_three_lines_CRLF_0(void);
    static void test_three_lines_CRLF_1(void);
    static void test_three_lines_CRLF_2(void);
    static void test_three_lines_CRLF_3(void);
    static void test_three_lines_CRLF_4(void);
    static void test_three_lines_CRLF_5(void);
    static void test_three_lines_CRLF_6(void);
    static void test_three_lines_CRLF_7(void);
    static void test_three_lines_CRLF_8(void);
    static void test_three_lines_CRLF_9(void);

#ifdef _STLSOFT_1_10_VER
    static void test_mixed_lines_CR_LF_0(void);
    static void test_mixed_lines_CR_LF_1(void);
    static void test_mixed_lines_CR_LF_2(void);
    static void test_mixed_lines_CR_LF_3(void);
    static void test_mixed_lines_CR_LF_4(void);
    static void test_mixed_lines_CR_LF_5(void);
    static void test_mixed_lines_CR_LF_6(void);
    static void test_mixed_lines_CR_LF_7(void);
    static void test_mixed_lines_CR_LF_8(void);
    static void test_mixed_lines_CR_LF_9(void);
#endif // _STLSOFT_1_10_VER

    static void test_large_file_0(void);
    static void test_large_file_1(void);
    static void test_large_file_2(void);
    static void test_large_file_3(void);
    static void test_large_file_4(void);
    static void test_large_file_5(void);
    static void test_large_file_6(void);
    static void test_large_file_7(void);
    static void test_large_file_8(void);
    static void test_large_file_9(void);

    static void test_all_empty_lines_0(void);
    static void test_all_empty_lines_1(void);
    static void test_all_empty_lines_2(void);
    static void test_all_empty_lines_3(void);
    static void test_all_empty_lines_4(void);
    static void test_all_empty_lines_5(void);
    static void test_all_empty_lines_6(void);
    static void test_all_empty_lines_7(void);
    static void test_all_empty_lines_8(void);
    static void test_all_empty_lines_9(void);

    static void test_some_empty_lines_0(void);
    static void test_some_empty_lines_1(void);
    static void test_some_empty_lines_2(void);
    static void test_some_empty_lines_3(void);
    static void test_some_empty_lines_4(void);
    static void test_some_empty_lines_5(void);
    static void test_some_empty_lines_6(void);
    static void test_some_empty_lines_7(void);
    static void test_some_empty_lines_8(void);
    static void test_some_empty_lines_9(void);

    static int setup(void* arg);
    static int teardown(void* arg);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.platformstl.filesystem.file_lines", verbosity, setup, teardown, NULL))
    {

        XTESTS_RUN_CASE(test_one_line_0);
        XTESTS_RUN_CASE(test_one_line_1);
        XTESTS_RUN_CASE(test_one_line_2);
        XTESTS_RUN_CASE(test_one_line_3);
        XTESTS_RUN_CASE(test_one_line_4);
        XTESTS_RUN_CASE(test_one_line_5);
        XTESTS_RUN_CASE(test_one_line_6);
        XTESTS_RUN_CASE(test_one_line_7);
        XTESTS_RUN_CASE(test_one_line_8);
        XTESTS_RUN_CASE(test_one_line_9);

#ifdef _STLSOFT_1_10_VER
        XTESTS_RUN_CASE(test_three_lines_CR_0);
        XTESTS_RUN_CASE(test_three_lines_CR_1);
        XTESTS_RUN_CASE(test_three_lines_CR_2);
        XTESTS_RUN_CASE(test_three_lines_CR_3);
        XTESTS_RUN_CASE(test_three_lines_CR_4);
        XTESTS_RUN_CASE(test_three_lines_CR_5);
        XTESTS_RUN_CASE(test_three_lines_CR_6);
        XTESTS_RUN_CASE(test_three_lines_CR_7);
        XTESTS_RUN_CASE(test_three_lines_CR_8);
        XTESTS_RUN_CASE(test_three_lines_CR_9);
#endif // _STLSOFT_1_10_VER

#ifdef _STLSOFT_1_10_VER
        XTESTS_RUN_CASE(test_three_lines_LF_0);
        XTESTS_RUN_CASE(test_three_lines_LF_1);
        XTESTS_RUN_CASE(test_three_lines_LF_2);
        XTESTS_RUN_CASE(test_three_lines_LF_3);
        XTESTS_RUN_CASE(test_three_lines_LF_4);
        XTESTS_RUN_CASE(test_three_lines_LF_5);
        XTESTS_RUN_CASE(test_three_lines_LF_6);
        XTESTS_RUN_CASE(test_three_lines_LF_7);
        XTESTS_RUN_CASE(test_three_lines_LF_8);
        XTESTS_RUN_CASE(test_three_lines_LF_9);
#endif // _STLSOFT_1_10_VER

        XTESTS_RUN_CASE(test_three_lines_CRLF_0);
        XTESTS_RUN_CASE(test_three_lines_CRLF_1);
        XTESTS_RUN_CASE(test_three_lines_CRLF_2);
        XTESTS_RUN_CASE(test_three_lines_CRLF_3);
        XTESTS_RUN_CASE(test_three_lines_CRLF_4);
        XTESTS_RUN_CASE(test_three_lines_CRLF_5);
        XTESTS_RUN_CASE(test_three_lines_CRLF_6);
        XTESTS_RUN_CASE(test_three_lines_CRLF_7);
        XTESTS_RUN_CASE(test_three_lines_CRLF_8);
        XTESTS_RUN_CASE(test_three_lines_CRLF_9);

#ifdef _STLSOFT_1_10_VER
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_0);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_1);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_2);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_3);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_4);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_5);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_6);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_7);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_8);
        XTESTS_RUN_CASE(test_mixed_lines_CR_LF_9);
#endif // _STLSOFT_1_10_VER

        XTESTS_RUN_CASE(test_large_file_0);
        XTESTS_RUN_CASE(test_large_file_1);
        XTESTS_RUN_CASE(test_large_file_2);
        XTESTS_RUN_CASE(test_large_file_3);
        XTESTS_RUN_CASE(test_large_file_4);
        XTESTS_RUN_CASE(test_large_file_5);
        XTESTS_RUN_CASE(test_large_file_6);
        XTESTS_RUN_CASE(test_large_file_7);
        XTESTS_RUN_CASE(test_large_file_8);
        XTESTS_RUN_CASE(test_large_file_9);

        XTESTS_RUN_CASE(test_all_empty_lines_0);
        XTESTS_RUN_CASE(test_all_empty_lines_1);
        XTESTS_RUN_CASE(test_all_empty_lines_2);
        XTESTS_RUN_CASE(test_all_empty_lines_3);
        XTESTS_RUN_CASE(test_all_empty_lines_4);
        XTESTS_RUN_CASE(test_all_empty_lines_5);
        XTESTS_RUN_CASE(test_all_empty_lines_6);
        XTESTS_RUN_CASE(test_all_empty_lines_7);
        XTESTS_RUN_CASE(test_all_empty_lines_8);
        XTESTS_RUN_CASE(test_all_empty_lines_9);

        XTESTS_RUN_CASE(test_some_empty_lines_0);
        XTESTS_RUN_CASE(test_some_empty_lines_1);
        XTESTS_RUN_CASE(test_some_empty_lines_2);
        XTESTS_RUN_CASE(test_some_empty_lines_3);
        XTESTS_RUN_CASE(test_some_empty_lines_4);
        XTESTS_RUN_CASE(test_some_empty_lines_5);
        XTESTS_RUN_CASE(test_some_empty_lines_6);
        XTESTS_RUN_CASE(test_some_empty_lines_7);
        XTESTS_RUN_CASE(test_some_empty_lines_8);
        XTESTS_RUN_CASE(test_some_empty_lines_9);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*platformstl/*/file_lines.hpp", NULL);
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
    typedef stlsoft::basic_simple_string<char>          sstring_m_t;
    typedef stlsoft::basic_string_view<char>            stringv_m_t;

    typedef platformstl::basic_file_lines<
        char
    >                                                   buffer_0_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   string_m_t
    ,   string_m_t
    >                                                   buffer_1_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   sstring_m_t
    ,   string_m_t
    >                                                   buffer_2_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   stringv_m_t
    ,   string_m_t
    >                                                   buffer_3_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   string_m_t
    ,   sstring_m_t
    >                                                   buffer_4_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   sstring_m_t
    ,   sstring_m_t
    >                                                   buffer_5_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   stringv_m_t
    ,   sstring_m_t
    >                                                   buffer_6_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   string_m_t
    ,   stringv_m_t
    >                                                   buffer_7_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   sstring_m_t
    ,   stringv_m_t
    >                                                   buffer_8_m_t;

    typedef platformstl::basic_file_lines<
        char
    ,   stringv_m_t
    ,   stringv_m_t
    >                                                   buffer_9_m_t;

    typedef platformstl::basic_path<char>               path_m_t;



    char const TEST_FILE_one_line[]             =   "TEST_FILE_one_line";
    char const TEST_FILE_three_lines_CR[]       =   "TEST_FILE_three_lines_CR";
    char const TEST_FILE_three_lines_LF[]       =   "TEST_FILE_three_lines_LF";
    char const TEST_FILE_three_lines_CRLF[]     =   "TEST_FILE_three_lines_CRLF";
    char const TEST_FILE_mixed_lines_CR_LF[]    =   "TEST_FILE_mixed_lines_CR_LF";
    char const TEST_FILE_large_file[]           =   "TEST_FILE_large_file";
    char const TEST_FILE_all_empty_lines[]      =   "TEST_FILE_all_empty_lines";
    char const TEST_FILE_some_empty_lines[]     =   "TEST_FILE_some_empty_lines";

#ifdef _DEBUG
    size_t const    NUM_large_file_LINES        =   100u;
    size_t const    NUM_all_empty_LINES         =   10u;
    size_t const    NUM_some_empty_LINE_PAIRS   =   10u;
#else /* ? _DEBUG */
    size_t const    NUM_large_file_LINES        =   100000u;
    size_t const    NUM_all_empty_LINES         =   1000u;
    size_t const    NUM_some_empty_LINE_PAIRS   =   1000u;
#endif /* _DEBUG */

    int debug_()
    {
        return NUM_large_file_LINES;
    }


static int setup(void* /* arg */)
{
    path_m_t    cwd = path_m_t(platformstl::current_directory());
    path_m_t    path_TEST_FILE_one_line             =   cwd / TEST_FILE_one_line;
    path_m_t    path_TEST_FILE_three_lines_CR       =   cwd / TEST_FILE_three_lines_CR;
    path_m_t    path_TEST_FILE_three_lines_LF       =   cwd / TEST_FILE_three_lines_LF;
    path_m_t    path_TEST_FILE_three_lines_CRLF     =   cwd / TEST_FILE_three_lines_CRLF;
    path_m_t    path_TEST_FILE_mixed_lines_CR_LF    =   cwd / TEST_FILE_mixed_lines_CR_LF;
    path_m_t    path_TEST_FILE_large_file           =   cwd / TEST_FILE_large_file;
    path_m_t    path_TEST_FILE_all_empty_lines      =   cwd / TEST_FILE_all_empty_lines;
    path_m_t    path_TEST_FILE_some_empty_lines     =   cwd / TEST_FILE_some_empty_lines;


#ifdef _STLSOFT_1_10_VER
    {
        stlsoft::FILE_stream file(path_TEST_FILE_one_line, "w");

        file.write_line("abc");
    }
#else /* ? _STLSOFT_1_10_VER */
    {
        FILE* f = ::fopen(path_TEST_FILE_one_line.c_str(), "w");

        ::fprintf(f, "abc\n");

        ::fclose(f);
    }
#endif /* _STLSOFT_1_10_VER */

    {
        FILE* f = ::fopen(path_TEST_FILE_three_lines_CR.c_str(), "wb");

        ::fprintf(f, "abc\r");
        ::fprintf(f, "def\r");
        ::fprintf(f, "ghi\r");

        ::fclose(f);
    }

    {
        FILE* f = ::fopen(path_TEST_FILE_three_lines_LF.c_str(), "wb");

        ::fprintf(f, "abc\n");
        ::fprintf(f, "def\n");
        ::fprintf(f, "ghi\n");

        ::fclose(f);
    }

    {
        FILE* f = ::fopen(path_TEST_FILE_three_lines_CRLF.c_str(), "wb");

        ::fprintf(f, "abc\r\n");
        ::fprintf(f, "def\r\n");
        ::fprintf(f, "ghi\r\n");

        ::fclose(f);
    }

    {
        FILE* f = ::fopen(path_TEST_FILE_mixed_lines_CR_LF.c_str(), "wb");

        ::fprintf(f, "abc\r\n");
        ::fprintf(f, "def\n");
        ::fprintf(f, "ghi\r");
        ::fprintf(f, "jkl\r\n");
        ::fprintf(f, "mn\n");
        ::fprintf(f, "o\r");
        ::fprintf(f, "\r");
        ::fprintf(f, "p\n");
        ::fprintf(f, "\n");
        ::fprintf(f, "qrstuvwxyz");

        ::fclose(f);
    }

#ifdef _STLSOFT_1_10_VER
    {
        stlsoft::FILE_stream file(path_TEST_FILE_large_file, "w");

        { for(size_t i = 0; i != NUM_large_file_LINES; ++i)
        {
            file.write_line("abc");
        }}
    }
#else /* ? _STLSOFT_1_10_VER */
    {
        FILE* f = ::fopen(path_TEST_FILE_large_file.c_str(), "w");

        { for(size_t i = 0; i != NUM_large_file_LINES; ++i)
        {
            ::fprintf(f, "abc\n");
        }}

        ::fclose(f);
    }
#endif /* _STLSOFT_1_10_VER */

#ifdef _STLSOFT_1_10_VER
    {
        stlsoft::FILE_stream file(path_TEST_FILE_all_empty_lines, "w");

        { for(size_t i = 0; i != NUM_all_empty_LINES; ++i)
        {
            file.write_line();
        }}
    }
#else /* ? _STLSOFT_1_10_VER */
    {
        FILE* f = ::fopen(path_TEST_FILE_all_empty_lines.c_str(), "w");

        { for(size_t i = 0; i != NUM_all_empty_LINES; ++i)
        {
            ::fprintf(f, "\n");
        }}

        ::fclose(f);
    }
#endif /* _STLSOFT_1_10_VER */

#ifdef _STLSOFT_1_10_VER
    {
        stlsoft::FILE_stream file(path_TEST_FILE_some_empty_lines, "w");

        { for(size_t i = 0; i != NUM_some_empty_LINE_PAIRS; ++i)
        {
            file.write_line();
            file.write_line("abc");
        }}
    }
#else /* ? _STLSOFT_1_10_VER */
    {
        FILE* f = ::fopen(path_TEST_FILE_some_empty_lines.c_str(), "w");

        { for(size_t i = 0; i != NUM_some_empty_LINE_PAIRS; ++i)
        {
            ::fprintf(f, "\n");
            ::fprintf(f, "abc\n");
        }}

        ::fclose(f);
    }
#endif /* _STLSOFT_1_10_VER */

    return 0;
}

static int teardown(void* /* arg */)
{
    path_m_t    cwd = path_m_t(platformstl::current_directory());

    ::remove((cwd / TEST_FILE_one_line).c_str());
    ::remove((cwd / TEST_FILE_three_lines_CR).c_str());
    ::remove((cwd / TEST_FILE_three_lines_LF).c_str());
    ::remove((cwd / TEST_FILE_three_lines_CRLF).c_str());
    ::remove((cwd / TEST_FILE_mixed_lines_CR_LF).c_str());
    ::remove((cwd / TEST_FILE_large_file).c_str());
    ::remove((cwd / TEST_FILE_all_empty_lines).c_str());
    ::remove((cwd / TEST_FILE_some_empty_lines).c_str());

    return 0;
}



template<
    typename C
,   typename V
,   typename B
>
void test_one_line_(platformstl::basic_file_lines<C, V, B> const*)
{
    typedef platformstl::basic_file_lines<C, V, B>  file_lines_t;

    path_m_t        cwd = path_m_t(platformstl::current_directory());
    debug_();
    file_lines_t    lines(cwd / TEST_FILE_one_line);

    XTESTS_TEST_BOOLEAN_FALSE(lines.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1u, lines.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0]);
}

static void test_one_line_0(void){test_one_line_(static_cast<buffer_0_m_t const*>(0));}
static void test_one_line_1(void){test_one_line_(static_cast<buffer_1_m_t const*>(0));}
static void test_one_line_2(void){test_one_line_(static_cast<buffer_2_m_t const*>(0));}
static void test_one_line_3(void){test_one_line_(static_cast<buffer_3_m_t const*>(0));}
static void test_one_line_4(void){test_one_line_(static_cast<buffer_4_m_t const*>(0));}
static void test_one_line_5(void){test_one_line_(static_cast<buffer_5_m_t const*>(0));}
static void test_one_line_6(void){test_one_line_(static_cast<buffer_6_m_t const*>(0));}
static void test_one_line_7(void){test_one_line_(static_cast<buffer_7_m_t const*>(0));}
static void test_one_line_8(void){test_one_line_(static_cast<buffer_8_m_t const*>(0));}
static void test_one_line_9(void){test_one_line_(static_cast<buffer_9_m_t const*>(0));}

#ifdef _STLSOFT_1_10_VER
template<
    typename C
,   typename V
,   typename B
>
void test_three_lines_CR_(platformstl::basic_file_lines<C, V, B> const*)
{
    typedef platformstl::basic_file_lines<C, V, B>  file_lines_t;

    path_m_t        cwd = path_m_t(platformstl::current_directory());
    debug_();
    file_lines_t    lines(cwd / TEST_FILE_three_lines_CR);

    XTESTS_TEST_BOOLEAN_FALSE(lines.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, lines.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", lines[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", lines[2]);
}

static void test_three_lines_CR_0(void){test_three_lines_CR_(static_cast<buffer_0_m_t const*>(0));}
static void test_three_lines_CR_1(void){test_three_lines_CR_(static_cast<buffer_1_m_t const*>(0));}
static void test_three_lines_CR_2(void){test_three_lines_CR_(static_cast<buffer_2_m_t const*>(0));}
static void test_three_lines_CR_3(void){test_three_lines_CR_(static_cast<buffer_3_m_t const*>(0));}
static void test_three_lines_CR_4(void){test_three_lines_CR_(static_cast<buffer_4_m_t const*>(0));}
static void test_three_lines_CR_5(void){test_three_lines_CR_(static_cast<buffer_5_m_t const*>(0));}
static void test_three_lines_CR_6(void){test_three_lines_CR_(static_cast<buffer_6_m_t const*>(0));}
static void test_three_lines_CR_7(void){test_three_lines_CR_(static_cast<buffer_7_m_t const*>(0));}
static void test_three_lines_CR_8(void){test_three_lines_CR_(static_cast<buffer_8_m_t const*>(0));}
static void test_three_lines_CR_9(void){test_three_lines_CR_(static_cast<buffer_9_m_t const*>(0));}
#endif // _STLSOFT_1_10_VER

#ifdef _STLSOFT_1_10_VER
template<
    typename C
,   typename V
,   typename B
>
void test_three_lines_LF_(platformstl::basic_file_lines<C, V, B> const*)
{
    typedef platformstl::basic_file_lines<C, V, B>  file_lines_t;

    path_m_t        cwd = path_m_t(platformstl::current_directory());
    debug_();
    file_lines_t    lines(cwd / TEST_FILE_three_lines_LF);

    XTESTS_TEST_BOOLEAN_FALSE(lines.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, lines.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", lines[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", lines[2]);
}

static void test_three_lines_LF_0(void){test_three_lines_LF_(static_cast<buffer_0_m_t const*>(0));}
static void test_three_lines_LF_1(void){test_three_lines_LF_(static_cast<buffer_1_m_t const*>(0));}
static void test_three_lines_LF_2(void){test_three_lines_LF_(static_cast<buffer_2_m_t const*>(0));}
static void test_three_lines_LF_3(void){test_three_lines_LF_(static_cast<buffer_3_m_t const*>(0));}
static void test_three_lines_LF_4(void){test_three_lines_LF_(static_cast<buffer_4_m_t const*>(0));}
static void test_three_lines_LF_5(void){test_three_lines_LF_(static_cast<buffer_5_m_t const*>(0));}
static void test_three_lines_LF_6(void){test_three_lines_LF_(static_cast<buffer_6_m_t const*>(0));}
static void test_three_lines_LF_7(void){test_three_lines_LF_(static_cast<buffer_7_m_t const*>(0));}
static void test_three_lines_LF_8(void){test_three_lines_LF_(static_cast<buffer_8_m_t const*>(0));}
static void test_three_lines_LF_9(void){test_three_lines_LF_(static_cast<buffer_9_m_t const*>(0));}
#endif // _STLSOFT_1_10_VER

template<
    typename C
,   typename V
,   typename B
>
void test_three_lines_CRLF_(platformstl::basic_file_lines<C, V, B> const*)
{
    typedef platformstl::basic_file_lines<C, V, B>  file_lines_t;

    path_m_t        cwd = path_m_t(platformstl::current_directory());
    debug_();
    file_lines_t    lines(cwd / TEST_FILE_three_lines_CRLF);

    XTESTS_TEST_BOOLEAN_FALSE(lines.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3u, lines.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", lines[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", lines[2]);
}

static void test_three_lines_CRLF_0(void){test_three_lines_CRLF_(static_cast<buffer_0_m_t const*>(0));}
static void test_three_lines_CRLF_1(void){test_three_lines_CRLF_(static_cast<buffer_1_m_t const*>(0));}
static void test_three_lines_CRLF_2(void){test_three_lines_CRLF_(static_cast<buffer_2_m_t const*>(0));}
static void test_three_lines_CRLF_3(void){test_three_lines_CRLF_(static_cast<buffer_3_m_t const*>(0));}
static void test_three_lines_CRLF_4(void){test_three_lines_CRLF_(static_cast<buffer_4_m_t const*>(0));}
static void test_three_lines_CRLF_5(void){test_three_lines_CRLF_(static_cast<buffer_5_m_t const*>(0));}
static void test_three_lines_CRLF_6(void){test_three_lines_CRLF_(static_cast<buffer_6_m_t const*>(0));}
static void test_three_lines_CRLF_7(void){test_three_lines_CRLF_(static_cast<buffer_7_m_t const*>(0));}
static void test_three_lines_CRLF_8(void){test_three_lines_CRLF_(static_cast<buffer_8_m_t const*>(0));}
static void test_three_lines_CRLF_9(void){test_three_lines_CRLF_(static_cast<buffer_9_m_t const*>(0));}

#ifdef _STLSOFT_1_10_VER
template<
    typename C
,   typename V
,   typename B
>
void test_mixed_lines_CR_LF_(platformstl::basic_file_lines<C, V, B> const*)
{
    typedef platformstl::basic_file_lines<C, V, B>  file_lines_t;

    path_m_t        cwd = path_m_t(platformstl::current_directory());
    debug_();
    file_lines_t    lines(cwd / TEST_FILE_mixed_lines_CR_LF);

    XTESTS_TEST_BOOLEAN_FALSE(lines.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(10u, lines.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", lines[1]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", lines[2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("jkl", lines[3]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("mn", lines[4]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("o", lines[5]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", lines[6]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("p", lines[7]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", lines[8]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("qrstuvwxyz", lines[9]);
}

static void test_mixed_lines_CR_LF_0(void){test_mixed_lines_CR_LF_(static_cast<buffer_0_m_t const*>(0));}
static void test_mixed_lines_CR_LF_1(void){test_mixed_lines_CR_LF_(static_cast<buffer_1_m_t const*>(0));}
static void test_mixed_lines_CR_LF_2(void){test_mixed_lines_CR_LF_(static_cast<buffer_2_m_t const*>(0));}
static void test_mixed_lines_CR_LF_3(void){test_mixed_lines_CR_LF_(static_cast<buffer_3_m_t const*>(0));}
static void test_mixed_lines_CR_LF_4(void){test_mixed_lines_CR_LF_(static_cast<buffer_4_m_t const*>(0));}
static void test_mixed_lines_CR_LF_5(void){test_mixed_lines_CR_LF_(static_cast<buffer_5_m_t const*>(0));}
static void test_mixed_lines_CR_LF_6(void){test_mixed_lines_CR_LF_(static_cast<buffer_6_m_t const*>(0));}
static void test_mixed_lines_CR_LF_7(void){test_mixed_lines_CR_LF_(static_cast<buffer_7_m_t const*>(0));}
static void test_mixed_lines_CR_LF_8(void){test_mixed_lines_CR_LF_(static_cast<buffer_8_m_t const*>(0));}
static void test_mixed_lines_CR_LF_9(void){test_mixed_lines_CR_LF_(static_cast<buffer_9_m_t const*>(0));}
#endif // _STLSOFT_1_10_VER

template<
    typename C
,   typename V
,   typename B
>
void test_large_file_(platformstl::basic_file_lines<C, V, B> const*)
{
    typedef platformstl::basic_file_lines<C, V, B>  file_lines_t;

    path_m_t        cwd = path_m_t(platformstl::current_directory());
    debug_();
    file_lines_t    lines(cwd / TEST_FILE_large_file);

    XTESTS_TEST_BOOLEAN_FALSE(lines.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(NUM_large_file_LINES, lines.size()));
    { for(size_t i = 0; i != NUM_large_file_LINES; ++i)
    {
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[i]);
    }}
}

static void test_large_file_0(void){test_large_file_(static_cast<buffer_0_m_t const*>(0));}
static void test_large_file_1(void){test_large_file_(static_cast<buffer_1_m_t const*>(0));}
static void test_large_file_2(void){test_large_file_(static_cast<buffer_2_m_t const*>(0));}
static void test_large_file_3(void){test_large_file_(static_cast<buffer_3_m_t const*>(0));}
static void test_large_file_4(void){test_large_file_(static_cast<buffer_4_m_t const*>(0));}
static void test_large_file_5(void){test_large_file_(static_cast<buffer_5_m_t const*>(0));}
static void test_large_file_6(void){test_large_file_(static_cast<buffer_6_m_t const*>(0));}
static void test_large_file_7(void){test_large_file_(static_cast<buffer_7_m_t const*>(0));}
static void test_large_file_8(void){test_large_file_(static_cast<buffer_8_m_t const*>(0));}
static void test_large_file_9(void){test_large_file_(static_cast<buffer_9_m_t const*>(0));}

template<
    typename C
,   typename V
,   typename B
>
void test_all_empty_lines_(platformstl::basic_file_lines<C, V, B> const*)
{
    typedef platformstl::basic_file_lines<C, V, B>  file_lines_t;

    path_m_t        cwd = path_m_t(platformstl::current_directory());
    debug_();
    file_lines_t    lines(cwd / TEST_FILE_all_empty_lines);

    XTESTS_TEST_BOOLEAN_FALSE(lines.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(NUM_all_empty_LINES, lines.size()));
    { for(size_t i = 0; i != NUM_all_empty_LINES; ++i)
    {
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", lines[i]);
    }}
}

static void test_all_empty_lines_0(void){test_all_empty_lines_(static_cast<buffer_0_m_t const*>(0));}
static void test_all_empty_lines_1(void){test_all_empty_lines_(static_cast<buffer_1_m_t const*>(0));}
static void test_all_empty_lines_2(void){test_all_empty_lines_(static_cast<buffer_2_m_t const*>(0));}
static void test_all_empty_lines_3(void){test_all_empty_lines_(static_cast<buffer_3_m_t const*>(0));}
static void test_all_empty_lines_4(void){test_all_empty_lines_(static_cast<buffer_4_m_t const*>(0));}
static void test_all_empty_lines_5(void){test_all_empty_lines_(static_cast<buffer_5_m_t const*>(0));}
static void test_all_empty_lines_6(void){test_all_empty_lines_(static_cast<buffer_6_m_t const*>(0));}
static void test_all_empty_lines_7(void){test_all_empty_lines_(static_cast<buffer_7_m_t const*>(0));}
static void test_all_empty_lines_8(void){test_all_empty_lines_(static_cast<buffer_8_m_t const*>(0));}
static void test_all_empty_lines_9(void){test_all_empty_lines_(static_cast<buffer_9_m_t const*>(0));}

template<
    typename C
,   typename V
,   typename B
>
void test_some_empty_lines_(platformstl::basic_file_lines<C, V, B> const*)
{
    typedef platformstl::basic_file_lines<C, V, B>  file_lines_t;

    path_m_t        cwd = path_m_t(platformstl::current_directory());
    debug_();
    file_lines_t    lines(cwd / TEST_FILE_some_empty_lines);

    XTESTS_TEST_BOOLEAN_FALSE(lines.empty());
    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(NUM_some_empty_LINE_PAIRS * 2, lines.size()));
    { for(size_t i = 0; i != NUM_some_empty_LINE_PAIRS; ++i)
    {
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", lines[i * 2]);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[i * 2 + 1]);
    }}
}

static void test_some_empty_lines_0(void){test_some_empty_lines_(static_cast<buffer_0_m_t const*>(0));}
static void test_some_empty_lines_1(void){test_some_empty_lines_(static_cast<buffer_1_m_t const*>(0));}
static void test_some_empty_lines_2(void){test_some_empty_lines_(static_cast<buffer_2_m_t const*>(0));}
static void test_some_empty_lines_3(void){test_some_empty_lines_(static_cast<buffer_3_m_t const*>(0));}
static void test_some_empty_lines_4(void){test_some_empty_lines_(static_cast<buffer_4_m_t const*>(0));}
static void test_some_empty_lines_5(void){test_some_empty_lines_(static_cast<buffer_5_m_t const*>(0));}
static void test_some_empty_lines_6(void){test_some_empty_lines_(static_cast<buffer_6_m_t const*>(0));}
static void test_some_empty_lines_7(void){test_some_empty_lines_(static_cast<buffer_7_m_t const*>(0));}
static void test_some_empty_lines_8(void){test_some_empty_lines_(static_cast<buffer_8_m_t const*>(0));}
static void test_some_empty_lines_9(void){test_some_empty_lines_(static_cast<buffer_9_m_t const*>(0));}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
