/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.iterator.preferential_insert_iterator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.iterator.preferential_insert_iteratortor project.
 *
 * Created:     16th June 2010
 * Updated:     16th June 2010
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

//#include <stlsoft/iterator/insert_prefer_back_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/algorithm/literal_copy.hpp>
#include <stlsoft/meta/detector/has_key_type.hpp>
#include <stlsoft/meta/detector/has_value_type.hpp>
#include <stlsoft/meta/is_same_type.hpp>

/* Standard C++ Header Files */
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_1_0(void);
	static void test_1_1(void);
	static void test_1_2(void);
	static void test_1_3(void);
	static void test_1_4(void);
	static void test_1_5(void);
	static void test_1_6(void);
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
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.iterator.preferential_insert_iteratortor", verbosity))
	{
		XTESTS_RUN_CASE(test_1_0);
		XTESTS_RUN_CASE(test_1_1);
		XTESTS_RUN_CASE(test_1_2);
		XTESTS_RUN_CASE(test_1_3);
		XTESTS_RUN_CASE(test_1_4);
		XTESTS_RUN_CASE(test_1_5);
		XTESTS_RUN_CASE(test_1_6);
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

namespace stlsoft
{


} /* namespace stlsoft */

template<
	typename	C
,	bool		HAS_key_type
,	bool		HAS_value_type
>
struct are_key_type_and_value_type_the_same
{
	enum { value = 0 };
};

template<typename C>
struct are_key_type_and_value_type_the_same<C, true, true>
{
	enum { value = stlsoft::is_same_type<typename C::key_type, typename C::value_type>::value };
};

template <
	typename	C
,	bool		IS_SET_TYPE
,	bool		IS_SEQUENCE_TYPE
>
struct container_insert_helper;

template <typename C>
struct container_insert_helper<C, true, false>
{
	static void do_insert(C& container, typename C::const_reference value)
	{
		container.insert(value);
	}
};

template <typename C>
struct container_insert_helper<C, false, true>
{
	static void do_insert(C& container, typename C::const_reference value)
	{
		container.push_back(value);
	}
};


template <typename C>
struct container_insert_traits
{
	typedef C										container_type;
	typedef ss_typename_type_k C::iterator			iterator;
	typedef ss_typename_type_k C::const_reference	const_reference;

	enum { HAS_key_type		=	stlsoft::has_key_type<C>::value };
	enum { HAS_value_type	=	stlsoft::has_value_type<C>::value };
	enum { ARE_key_type_AND_value_type_THE_SAME	=	are_key_type_and_value_type_the_same<C, HAS_key_type, HAS_value_type>::value };

	enum { IS_ASSOCIATIVE_TYPE	=	HAS_key_type };
	enum { IS_SEQUENCE_TYPE		=	!HAS_key_type };
	enum { IS_SET_TYPE			=	IS_ASSOCIATIVE_TYPE && ARE_key_type_AND_value_type_THE_SAME };
	enum { IS_MAPPING_TYPE		=	IS_ASSOCIATIVE_TYPE && !ARE_key_type_AND_value_type_THE_SAME };

private:

public:
	static void insert_into(container_type& container, const_reference value)
	{
		bool has_key_type							=	HAS_key_type;
		bool has_value_type							=	HAS_value_type;
		bool are_key_type_and_value_type_the_same	=	ARE_key_type_AND_value_type_THE_SAME;

		STLSOFT_SUPPRESS_UNUSED(has_key_type);
		STLSOFT_SUPPRESS_UNUSED(has_value_type);
		STLSOFT_SUPPRESS_UNUSED(are_key_type_and_value_type_the_same);

		container_insert_helper<C, IS_SET_TYPE, IS_SEQUENCE_TYPE>::do_insert(container, value);

#if 1
//		insert_into_(container_type& container, iterator (container_type::*)(iterator, const_reference), const_reference value)
//		container.insert(container.end(), value);
#else /* ? 0 */
//		container.insert(value);
#endif /* 0 */
	}

private:

	static void insert_into_(container_type& container, iterator (container_type::*)(iterator, const_reference), const_reference value)
	{
		container.insert(container.end(), value);
	}
	static void insert_into_(container_type& container, void (container_type::*)(const_reference), const_reference value)
	{
		container.pus(value);
	}

};

namespace
{

	typedef std::string						string_t;
	typedef std::deque<string_t>			string_deque_t;
	typedef std::vector<string_t>			strings_t;
	typedef std::set<string_t>				stringset_t;
	typedef std::map<string_t, string_t>	string_to_string_map_t;

static void test_1_0()
{
	strings_t			src;

	stlsoft::literal_copy("abc", "def", "abc", "ghi", std::back_inserter(src));

	strings_t			dest1;
	stringset_t			dest2;

	container_insert_traits<strings_t>::insert_into(dest1, "abc");
	container_insert_traits<stringset_t>::insert_into(dest2, "abc");

	string_to_string_map_t	map;

//	container_insert_traits<string_to_string_map_t>::insert_into(map, std::make_pair("abc", "abc"));

	string_deque_t			deq;

	container_insert_traits<string_deque_t>::insert_into(deq, "abc");

#if 0
	std::copy(	src.begin(), src.end()
			,	stlsoft::preferential_insert_iterator(dest), dest.end());
#endif /* 0 */
}

static void test_1_1()
{
}

static void test_1_2()
{
}

static void test_1_3()
{
}

static void test_1_4()
{
}

static void test_1_5()
{
}

static void test_1_6()
{
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
