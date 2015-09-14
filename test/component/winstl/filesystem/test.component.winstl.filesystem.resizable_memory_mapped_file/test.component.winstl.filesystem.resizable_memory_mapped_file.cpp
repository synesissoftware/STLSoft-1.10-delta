/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.winstl.filesystem.resizable_memory_mapped_file.cpp
 *
 * Purpose:     Implementation file for the test.component.winstl.filesystem.resizable_memory_mapped_file project.
 *
 * Created:     1st May 2014
 * Updated:     3rd June 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Preprocessor control
 */

#define WINSTL_RESIZABLE_MEMORY_MAPPED_FILE_USE_CRT_HEAP

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/filesystem/resizable_memory_mapped_file.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>
#if _XTESTS_VER < 0x001201ff
# error This file requires xTests 1.18.1 or later
#endif /* _XTESTS_VER */
#include <xtests/util/temp_file.hpp>

/* FastFormat header files */
#include <fastformat/ff.hpp>
#include <fastformat/inserters/to_X.hpp>
#include <fastformat/sinks/FILE.hpp>
#include <fastformat/sinks/OutputDebugString.hpp>

/* STLSoft header files */
#include <winstl/diagnostics/output_debug_line.h>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

#ifndef INVALID_FILE_ATTRIBUTES
# define INVALID_FILE_ATTRIBUTES	(~static_cast<DWORD>(0))
#endif /* !INVALID_FILE_ATTRIBUTES */

/* Visual C++ header files */
#if defined(_MSC_VER) && \
    defined( _DEBUG )
# include <crtdbg.h>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_type_exists(void);
    static void test_constructor_exists(void);
    static void test_constructor_throws_on_file_not_exist(void);
    static void test_constructor_throws_on_empty_file(void);
    static void test_expansion_to_1MB_in_1K_increments_1(void);
    static void test_expansion_to_10MB_in_1K_incremements_and_check_contents(void);
    static void test_expansion_to_10MB_in_1MB_incremements_and_check_contents(void);
    static void test_expansion_to_1GB_in_1K_incremements_and_check_contents(void);
    static void test_1_7(void);
    static void test_1_8(void);
    static void test_1_9(void);
    static void test_1_10(void);
    static void test_1_11(void);
    static void test_1_12(void);
    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Statics
 */

namespace
{
    static char			s_arg0[1024 + 1];


} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

#if defined(_MSC_VER) && \
    defined( _DEBUG )
static
int main_(int argc, char **argv);

int main(int argc, char **argv)
{
    int             res;
    _CrtMemState    memState;

    _CrtMemCheckpoint(&memState);

    try
    {
        res = main_(argc, argv);
    }
    catch(std::exception& /* x */)
    {
        res = EXIT_FAILURE;
    }
    catch(...)
    {
        res = EXIT_FAILURE;
    }

    _CrtMemDumpAllObjectsSince(&memState);

    return res;
}
static
int main_(int argc, char **argv)
#else
int main(int argc, char **argv)
#endif
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    ::memcpy(s_arg0, argv[0], sizeof(char) * ::strlen(argv[0]));

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.winstl.filesystem.resizable_memory_mapped_file", verbosity))
    {
        XTESTS_RUN_CASE(test_type_exists);
        XTESTS_RUN_CASE(test_constructor_exists);
#if STLSOFT_LEAD_VER < 0x010b0000
        XTESTS_RUN_CASE_THAT_THROWS(test_constructor_throws_on_file_not_exist, winstl::windows_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_constructor_throws_on_empty_file, winstl::windows_exception);
#else /* ? STLSOFT_LEAD_VER < 1.11 */
# error Get the exception right!
#endif /* STLSOFT_LEAD_VER < 1.11 */
        XTESTS_RUN_CASE(test_expansion_to_1MB_in_1K_increments_1);
        XTESTS_RUN_CASE(test_expansion_to_10MB_in_1K_incremements_and_check_contents);
        XTESTS_RUN_CASE(test_expansion_to_10MB_in_1MB_incremements_and_check_contents);
        XTESTS_RUN_CASE(test_expansion_to_1GB_in_1K_incremements_and_check_contents);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

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
    using winstl::ws_uintptr_t;

#ifdef _DEBUG
	template <typename R>
	void
	dump_records_(
		R const& records
	)
	{
		ff::fmtln(
			ff::to_sink(stdout)
		,	FASTFORMAT_LITERAL_STRING("\t{0} record(s):")
		,	records.size()
		);

		{ for(size_t i = 0; records.size() != i; ++i)
		{
			ff::fmtln(
				ff::to_sink(stdout)
			,	FASTFORMAT_LITERAL_STRING("\t\t[{0}]\t{{{1,10} / {2,10}}}")
			,	i
			,	ff::to_X(records[i].offset)
			,	ff::to_X(records[i].size)
			);
		}}
	}
#endif /* _DEBUG */

	void
	dump_records(
		winstl::resizable_memory_mapped_file const&	mmf
	,	ff::ff_char_t const*						prompt
	)
	{
#ifdef _DEBUG
		ff::fmtln(
			ff::to_sink(stdout)
		,	FASTFORMAT_LITERAL_STRING("{0}:")
		,	prompt
		);
		dump_records_(mmf.get_records());
		ff::writeln(
			ff::to_sink(stdout)
		);
#endif /* _DEBUG */
	}


static void test_type_exists()
{
	typeid(winstl::resizable_memory_mapped_file);

    XTESTS_TEST_PASSED();
}

static void test_constructor_exists()
{
    if(0)
    {
		winstl::resizable_memory_mapped_file instance("some non-existent path", 0);

        STLSOFT_SUPPRESS_UNUSED(instance);
    }

    XTESTS_TEST_PASSED();
}

static void test_constructor_throws_on_file_not_exist()
{
	using namespace xtests::cpp;

	temp_file tp(temp_file::DeleteOnClose | temp_file::DeleteOnOpen);

	// Now we attempt to open the non-existent file

	winstl::resizable_memory_mapped_file mmf(tp.c_str(), 0);

	XTESTS_TEST_FAIL("should not get here!");
}

static void test_constructor_throws_on_empty_file()
{
	using namespace xtests::cpp;

	temp_file tp(temp_file::DeleteOnClose);

	winstl::resizable_memory_mapped_file mmf(tp.c_str(), 0);

	XTESTS_TEST_FAIL("should not get here!");
}

static void test_expansion_to_1MB_in_1K_increments_1()
{
	using namespace xtests::cpp;

	temp_file tp(temp_file::DeleteOnClose, NULL, 1);

	winstl::resizable_memory_mapped_file mmf(tp.c_str(), 0);

	dump_records(mmf, FASTFORMAT_LITERAL_STRING("after construction"));

	{ for(unsigned i = 1; i != 1024; ++i)
	{
		winstl::resizable_memory_mapped_file::offset_type const r = mmf.expand_to(i * 1024);

		XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(i * 1024, r);
	}}

	dump_records(mmf, FASTFORMAT_LITERAL_STRING("after expansion"));

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024u * 1024u, mmf.size());
}

static void test_expansion_to_10MB_in_1K_incremements_and_check_contents()
{
	using namespace xtests::cpp;

	temp_file tp(temp_file::DeleteOnClose, NULL, 1);

	winstl::resizable_memory_mapped_file mmf(tp.c_str(), 0);

	dump_records(mmf, FASTFORMAT_LITERAL_STRING("after construction"));

#if 0
    winstl::resizable_memory_mapped_file::expand_control const control = winstl::resizable_memory_mapped_file::ExpandViaNewView;
#else /* ? 0 */
    winstl::resizable_memory_mapped_file::expand_control const control = winstl::resizable_memory_mapped_file::ExpandViaCoalescedViews;
#endif /* 0 */

	{ for(unsigned i = 0; i != 10 * 1024; ++i)
	{
		winstl::resizable_memory_mapped_file::offset_type const r = mmf.expand_to((i + 1) * 1024, control);

		XTESTS_TEST_INTEGER_GREATER_OR_EQUAL((i + 1) * 1024, r);
	}}

	dump_records(mmf, FASTFORMAT_LITERAL_STRING("after expansion"));

    winstl::resizable_memory_mapped_file::offset_type   b = 0;
    int                                                 s = 0;

    for(; b < mmf.size(); ++s)
    {
        size_t largestN = 0;

        { for(size_t n = 4096; ; n += 4096)
        {
            void* const pv = mmf.get_pointer_to(b, n);

            if(NULL != pv)
            {
                largestN = n;
            }
            else
            {
                break;
            }
        }}

        void* const pv2 = mmf.get_pointer_to(b, largestN);

        ::memset(pv2, s, largestN);

        b += largestN;
    }

#ifdef _DEBUG
    ff::fmtln(
        ff::sinks::OutputDebugString_sink()
    ,   FASTFORMAT_LITERAL_STRING("{0} bytes, in {1} split(s)")
    ,   mmf.size()
    ,   s
    );
#endif

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10 * 1024u * 1024u, mmf.size());
}

static void test_expansion_to_10MB_in_1MB_incremements_and_check_contents()
{
	using namespace xtests::cpp;

	temp_file tp(temp_file::DeleteOnClose, NULL, 1);

	winstl::resizable_memory_mapped_file mmf(tp.c_str(), 0);

	dump_records(mmf, FASTFORMAT_LITERAL_STRING("after construction"));

#if 0
    winstl::resizable_memory_mapped_file::expand_control const control = winstl::resizable_memory_mapped_file::ExpandViaNewView;
#else /* ? 0 */
    winstl::resizable_memory_mapped_file::expand_control const control = winstl::resizable_memory_mapped_file::ExpandViaCoalescedViews;
#endif /* 0 */

	{ for(unsigned i = 0; i != 10; ++i)
	{
		winstl::resizable_memory_mapped_file::offset_type const r = mmf.expand_to((i + 1) * 1024 * 1024, control);

		XTESTS_TEST_INTEGER_GREATER_OR_EQUAL((i + 1) * 1024 * 1024, r);
	}}

	dump_records(mmf, FASTFORMAT_LITERAL_STRING("after expansion"));

    winstl::resizable_memory_mapped_file::offset_type   b = 0;
    int                                                 s = 0;

    for(; b < mmf.size(); ++s)
    {
        size_t largestN = 0;

        { for(size_t n = 4096; ; n += 4096)
        {
            void* const pv = mmf.get_pointer_to(b, n);

            if(NULL != pv)
            {
                largestN = n;
            }
            else
            {
                break;
            }
        }}

        void* const pv2 = mmf.get_pointer_to(b, largestN);

        ::memset(pv2, s, largestN);

        b += largestN;
    }

#ifdef _DEBUG
    ff::fmtln(
        ff::sinks::OutputDebugString_sink()
    ,   FASTFORMAT_LITERAL_STRING("{0} bytes, in {1} split(s)")
    ,   mmf.size()
    ,   s
    );
#endif

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10 * 1024u * 1024u, mmf.size());
}

static void test_expansion_to_1GB_in_1K_incremements_and_check_contents()
{
	using namespace xtests::cpp;

	temp_file tp(temp_file::DeleteOnClose, NULL, 1);

	winstl::resizable_memory_mapped_file mmf(tp.c_str(), 0);

	dump_records(mmf, FASTFORMAT_LITERAL_STRING("after construction"));

#if 0
    winstl::resizable_memory_mapped_file::expand_control const control = winstl::resizable_memory_mapped_file::ExpandViaNewView;
#else /* ? 0 */
    winstl::resizable_memory_mapped_file::expand_control const control = winstl::resizable_memory_mapped_file::ExpandViaCoalescedViews;
#endif /* 0 */

	{ for(unsigned i = 0; i != 1024 * 1024; ++i)
	{
		winstl::resizable_memory_mapped_file::offset_type const r = mmf.expand_to((i + 1) * 1024, control);

		XTESTS_TEST_INTEGER_GREATER_OR_EQUAL((i + 1) * 1024, r);
	}}

	dump_records(mmf, FASTFORMAT_LITERAL_STRING("after expansion"));

    winstl::resizable_memory_mapped_file::offset_type   b = 0;
    int                                                 s = 0;

    for(; b < mmf.size(); ++s)
    {
        size_t largestN = 0;

        { for(size_t n = 4096; ; n += 4096)
        {
            void* const pv = mmf.get_pointer_to(b, n);

            if(NULL != pv)
            {
                largestN = n;
            }
            else
            {
                break;
            }
        }}

        void* const pv2 = mmf.get_pointer_to(b, largestN);

        ::memset(pv2, s, largestN);

        b += largestN;
    }

#ifdef _DEBUG
    ff::fmtln(
        ff::sinks::OutputDebugString_sink()
    ,   FASTFORMAT_LITERAL_STRING("{0} bytes, in {1} split(s)")
    ,   mmf.size()
    ,   s
    );
#endif

	XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1024 * 1024 * 1024u, mmf.size());
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
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
