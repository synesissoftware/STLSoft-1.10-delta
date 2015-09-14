/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.iterator.transform_iterator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.iterator.transform_iterator project.
 *
 * Created:     2nd September 2010
 * Updated:     13th October 2010
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


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define _SCL_SECURE_NO_WARNINGS

#include <stlsoft/iterator/transformer.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/algorithm/literal_copy.hpp>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/iterator/string_concatenator_iterator.hpp>
#include <stlsoft/meta/is_same_type.hpp>
#include <stlsoft/util/dimensionof.h>

/* Standard C++ Header Files */
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_deque_1(void);
    static void test_deque_2(void);
    static void test_deque_3(void);
    static void test_deque_4(void);
    static void test_list_1(void);
    static void test_list_2(void);
    static void test_list_3(void);
    static void test_list_4(void);
    static void test_vector_1(void);
    static void test_vector_2(void);
    static void test_vector_3(void);
    static void test_vector_4(void);
    static void test_map_1(void);
    static void test_map_2(void);
    static void test_map_3(void);
    static void test_map_4(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.iterator.transform_iterator", verbosity))
    {
        XTESTS_RUN_CASE(test_deque_1);
        XTESTS_RUN_CASE(test_deque_2);
        XTESTS_RUN_CASE(test_deque_3);
        XTESTS_RUN_CASE(test_deque_4);
        XTESTS_RUN_CASE(test_list_1);
        XTESTS_RUN_CASE(test_list_2);
        XTESTS_RUN_CASE(test_list_3);
        XTESTS_RUN_CASE(test_list_4);
        XTESTS_RUN_CASE(test_vector_1);
        XTESTS_RUN_CASE(test_vector_2);
        XTESTS_RUN_CASE(test_vector_3);
        XTESTS_RUN_CASE(test_vector_4);
        XTESTS_RUN_CASE(test_map_1);
        XTESTS_RUN_CASE(test_map_2);
        XTESTS_RUN_CASE(test_map_3);
        XTESTS_RUN_CASE(test_map_4);

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
    typedef char                            char_t;
    typedef std::basic_string<char_t>       string_t;

    using stlsoft::uint64_t;

#if 0
    static char const* CONTAINED_STRINGS[] =
    {
        "def",
        "jkl",
        "abc",
        "ghi",
        "def",
        "abc",
    };

    static char const* ERASED_STRINGS[] =
    {
        "ghi",
        "abc",
        "mno",
    };
#endif /* 0 */

    template <typename I>
    string_t cat(I from, I to)
    {
        string_t r;

        std::copy(from, to, stlsoft::string_concatenator(r, ""));

        return r;
    }

	int int_to_int(int i)
	{
		return i;
	}
	long int_to_long(int i)
	{
		return i;
	}
	uint64_t int_to_ulonglong(int i)
	{
		return static_cast<uint64_t>(i);
	}
	string_t int_to_string(int i)
	{
		char sz[21];
		return stlsoft::integer_to_string(sz, STLSOFT_NUM_ELEMENTS(sz), i);
	}

	int int_string_pair_first_to_int(std::pair<int, string_t> const& i)
	{
		return i.first;
	}
	string_t int_string_pair_first_to_string(std::pair<int, string_t> const& i)
	{
		return int_to_string(i.first);
	}

static void test_deque_1()
{
    std::deque<int> c;

	{ for(int i = 0; i != 10; ++i)
	{
		c.push_back(i);
	}}

	{
		int result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_int))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_int))
		,	int(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		long result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_long))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_long))
		,	long(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		uint64_t result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_ulonglong))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_ulonglong))
		,	uint64_t(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		string_t result;

		std::copy(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_string))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_string))
		,	stlsoft::string_concatenator(result, "")
		);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0123456789", result);
	}
}

static void test_deque_2()
{
}

static void test_deque_3()
{
}

static void test_deque_4()
{
}

static void test_list_1()
{
    std::list<int> c;

	{ for(int i = 0; i != 10; ++i)
	{
		c.push_back(i);
	}}

	{
		int result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_int))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_int))
		,	int(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		long result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_long))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_long))
		,	long(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		uint64_t result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_ulonglong))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_ulonglong))
		,	uint64_t(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		string_t result;

		std::copy(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_string))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_string))
		,	stlsoft::string_concatenator(result, "")
		);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0123456789", result);
	}
}

static void test_list_2()
{
}

static void test_list_3()
{
}

static void test_list_4()
{
}

static void test_vector_1()
{
    std::vector<int> c;

	{ for(int i = 0; i != 10; ++i)
	{
		c.push_back(i);
	}}

	{
		int result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_int))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_int))
		,	int(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		long result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_long))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_long))
		,	long(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		uint64_t result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_ulonglong))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_ulonglong))
		,	uint64_t(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		string_t result;

		std::copy(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_to_string))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_to_string))
		,	stlsoft::string_concatenator(result, "")
		);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0123456789", result);
	}
}

static void test_vector_2()
{
}

static void test_vector_3()
{
}

static void test_vector_4()
{
}

static void test_map_1()
{
    std::map<int, string_t> c;

	{ for(int i = 0; i != 10; ++i)
	{
		c.insert(std::make_pair(i, int_to_string(i)));
	}}

	{
		int result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_string_pair_first_to_int))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_string_pair_first_to_int))
		,	int(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		string_t result;

		std::copy(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_string_pair_first_to_string))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_string_pair_first_to_string))
		,	stlsoft::string_concatenator(result, "")
		);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0123456789", result);
	}

#if 0
	{
		long result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_pair_to_long))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_pair_to_long))
		,	long(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		uint64_t result = std::accumulate(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_pair_to_ulonglong))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_pair_to_ulonglong))
		,	uint64_t(0)
		);

		XTESTS_TEST_INTEGER_EQUAL(45, result);
	}

	{
		string_t result;

		std::copy(
			stlsoft::transformer(c.begin(), std::ptr_fun(int_pair_to_string))
		,	stlsoft::transformer(c.end(), std::ptr_fun(int_pair_to_string))
		,	stlsoft::string_concatenator(result, "")
		);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0123456789", result);
	}
#endif
}

static void test_map_2()
{
}

static void test_map_3()
{
}

static void test_map_4()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
