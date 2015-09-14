/* /////////////////////////////////////////////////////////////////////////
 * File:        test.performance.stlsoft.string.string_registry.cpp
 *
 * Purpose:     Implementation file for the test.performance.stlsoft.string.string_registry project.
 *
 * Created:     22nd February 2011
 * Updated:     22nd February 2011
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
 * Pre-processor control
 */

#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS

//#define STLSOFT_STRING_REGISTRY_USE_IOM
//#define STLSOFT_STRING_REGISTRY_USE_VC1500_HASH_MAP
//#define STLSOFT_STRING_REGISTRY_USE_STD_MAP

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft.h>
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER >= 1400
# pragma warning(push)
# pragma warning(disable : 4996)
# include <winstl/error/error_desc.hpp>
# pragma warning(pop)
#endif

/* Pantheios Header Files - 1 */
#include <pantheios/pan.hpp>

/* STLSoft Header Files - 1 */
#include <stlsoft/string/string_registry.hpp>

/* FastFormat Header Files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

/* Pantheios Header Files - 2 */
#include <pantheios/inserters/integer.hpp>

/* Pantheios::Extras::DiagUtil Header Files */
#include <pantheios/extras/diagutil.hpp>

/* Pantheios::Extras::Main Header Files */
#include <pantheios/extras/main.hpp>

/* recls Header Files */
#include <recls/recls.hpp>

/* STLSoft Header Files - 2 */
#include <stlsoft/string/string_tokeniser.hpp>
#include <platformstl/filesystem/file_lines.hpp>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C++ Header Files */
#include <algorithm>
#include <exception>
#include <iostream>
#include <numeric>
#if 0
#include <iterator>
#include <list>
#include <map>
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

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("test.performance.stlsoft.string.string_registry");

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if 0
typedef char                        char_t;
typedef std::basic_string<char_t>   string_t;
#endif /* 0 */

using platformstl::performance_counter;

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static int usage();

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char** argv)
{
	char const* directory	=	NULL;
	char const* patterns	=	NULL;

	switch(argc)
	{
		case	0:
			STLSOFT_ASSERT(false);
		case	1:
		default:
			return usage();
		case	3:
			patterns	=	argv[2];
		case	2:
			directory	=	argv[1];
			break;
	}

    performance_counter counter;

    // Algorithm:
	//
	// - create two string registries
	// - load the first from the tokenised contents of all files matching
	//   the search specification(s)
	// - time the population of the second from the first

	stlsoft::string_registry source;

	recls::search_sequence files(directory, patterns, recls::RECURSIVE | recls::FILES);

	{ for(recls::search_sequence::const_iterator it = files.begin(); files.end() != it; ++it)
	{
		platformstl::file_lines lines(*it);

		{ for(size_t i = 0; lines.size() != i; ++i)
		{
			platformstl::file_lines::value_type const& line = lines[i];

			source.add(line);

			typedef stlsoft::string_tokeniser<
				platformstl::file_lines::value_type
			,	char
			>				tokeniser_t;

			tokeniser_t tokens(line, ' ');

			{ for(tokeniser_t::const_iterator j = tokens.begin(); tokens.end() != j; ++j)
			{
				source.add(*j);
			}}
		}}
	}}

	std::vector<performance_counter::interval_type> times(11);

	{ for(size_t i = 0; times.size() != i; ++i)
	{
		stlsoft::string_registry dest;

		counter.start();
		{ for(stlsoft::string_registry::const_iterator i = source.begin(); source.end() != i; ++i)
		{
			dest.add(*i);
		}}
		counter.stop();

		times[i] = counter.get_microseconds();
	}}

	std::sort(times.begin(), times.end());

	times.erase(times.end() - 1);
	times.erase(times.end() - 1);
	times.erase(times.begin());

	performance_counter::interval_type total = std::accumulate(times.begin(), times.end(), performance_counter::interval_type(0));

	ff::fmtln(
		std::cout
	,	"{0}\t{1}"
	,	source.size()
	,	total / times.size()
	);

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
        puts("test.performance.stlsoft.string.string_registry: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        return main_(argc, argv);
    }
    catch(std::bad_alloc&)
    {
        pan::logputs(pan::alert, "out of memory");
        std::cerr << "out of memory" << std::endl;
    }
    catch(std::exception& x)
    {
        pan::log_ALERT("Unexpected general error: ", x, ". Application terminating");
        std::cerr << "Unhandled error: " << x.what() << std::endl;
    }
    catch(...)
    {
        pan::logputs(pan::emergency, "Unhandled unknown error");
        std::cerr << "Unhandled unknown error" << std::endl;
    }

    return EXIT_FAILURE;
}

/* ////////////////////////////////////////////////////////////////////// */

static int usage()
{
	std::cerr << "USAGE: <directory> [<patterns>]" << std::endl;

	return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
