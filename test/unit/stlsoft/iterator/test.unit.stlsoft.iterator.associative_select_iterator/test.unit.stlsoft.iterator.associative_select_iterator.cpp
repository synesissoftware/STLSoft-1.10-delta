/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.iterator.associative_select_iterator.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.iterator.associative_select_iterator project.
 *
 * Created:     9th November 2008
 * Updated:     18th June 2010
 *
 * Thanks:      To Manfred Ehrhart, for supplying some of the test cases.
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

#include <stlsoft/iterators/associative_select_iterator.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <algorithm>
#include <map>
#include <numeric>
#include <sstream>
#include <string>

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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.iterator.associative_select_iterator", verbosity))
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

#if 0
# include <stlsoft/iterators/adapted_iterator_traits.hpp>
//# include <stlsoft/collections/associative_key_sequence.hpp>

namespace stlsoft
{
# if 0
	template<	ss_typename_param_k I
			,	ss_typename_param_k T = stlsoft::adapted_iterator_traits<I>
			>
	class associative_key_iterator
	{
	public:
		typedef	T				traits_type;
		typedef ss_typename_type_k T::
	};

	template<	ss_typename_param_k A
			>
	class associative_key_sequence
	{
	public: /// Member Types
		typedef A			adapted_container_type;
		typedef 
	};
# endif /* 0 */


# if 0
	template<   ss_typename_param_k I
			,   ss_typename_param_k F
			>
	associative_select_iterator<I, F> associative_select(I it, F fn)
	{
		return associative_select_iterator<I, F>(it, fn);
	}
# endif

} // namespace stlsoft
#endif /* 0 */

namespace
{
	typedef char						char_t;
	typedef std::basic_string<char_t>	string_t;

	struct Something 
	{
		Something(const std::string& name)
			: name_(name)
		{}
		Something()
			: name_("nothing")
		{}

		friend std::ostream& operator<<(std::ostream& out, const Something& some)
		{
			out << some.name_.c_str();
			return out;
		}

		string_t name_;
	};

//	typedef std::map<int, int>			int_int_map_t;

static void test_1_0()
{
	typedef std::map<int, Something> map_obj;

    typedef stlsoft::associative_select_iterator< 
            map_obj::const_iterator, 
            stlsoft::select_first<map_obj::value_type>
        > key_const_iterator; 

    typedef stlsoft::associative_select_iterator< 
            map_obj::const_iterator, 
            stlsoft::select_second_const<map_obj::value_type>
        > obj_const_iterator; 

    typedef stlsoft::associative_select_iterator< 
            map_obj::iterator, 
            stlsoft::select_second<map_obj::value_type>
        > obj_iterator; 

    map_obj objects;
    objects[0] = Something("zero");
    objects[1] = Something("one");
    objects[2] = Something("two");

    std::ostringstream dump;

    key_const_iterator key		(objects.begin());
    key_const_iterator last_key (objects.end());

    for(; key != last_key; ++key)
	{
		dump << *key << ',';
	}
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0,1,2,", dump.str());

    obj_const_iterator const_obj		(objects.begin());
    obj_const_iterator last_const_obj	(objects.end());

    dump.str("");
    for(; const_obj != last_const_obj; ++const_obj)
	{
		dump << *const_obj << ',';
	}
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("zero,one,two,", dump.str());

    obj_iterator obj		(objects.begin());
    obj_iterator last_obj	(objects.end());

    dump.str("");
    for(; obj != last_obj; ++obj) 
	{
        (*obj).name_[0] = char(::toupper((*obj).name_[0]));
	}
    for(obj = obj_iterator(objects.begin()) ; obj != last_obj; ++obj) 
	{
        dump << *obj << ',';
	}
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Zero,One,Two,", dump.str());
}

static void test_1_1()
{
	typedef std::map<int, Something*> map_ptr;

    typedef stlsoft::associative_select_iterator< 
            map_ptr::const_iterator,
            stlsoft::select_first<map_ptr::value_type>
        > key_const_iterator; 

    typedef stlsoft::associative_select_iterator< 
            map_ptr::const_iterator, 
            stlsoft::select_second_const<map_ptr::value_type>
        > obj_const_iterator; 

    typedef stlsoft::associative_select_iterator< 
            map_ptr::iterator,
            stlsoft::select_second<map_ptr::value_type>
        > obj_iterator; 

    map_ptr objects_ptr;
    objects_ptr[0] = new Something("zero");
    objects_ptr[1] = new Something("one");
    objects_ptr[2] = new Something("two");

    std::ostringstream dump;

    key_const_iterator key		(objects_ptr.begin());
    key_const_iterator last_key	(objects_ptr.end());

    for(; key != last_key; ++key)
	{
		dump << *key << ',';
	}
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0,1,2,", dump.str());

    obj_const_iterator const_obj		(objects_ptr.begin());
    obj_const_iterator last_const_obj	(objects_ptr.end());

    dump.str("");
    for(; const_obj != last_const_obj; ++const_obj)
	{
		dump << **const_obj << ',';
	}
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("zero,one,two,", dump.str());

    obj_iterator obj		(objects_ptr.begin());
    obj_iterator last_obj	(objects_ptr.end());

    dump.str("");
    for(; obj != last_obj; ++obj) 
	{
        (*obj)->name_[0] = char(::toupper((*obj)->name_[0]));
	}
    for(obj = obj_iterator(objects_ptr.begin()) ; obj != last_obj; ++obj) 
	{
        dump << **obj << ',';
	}
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("Zero,One,Two,", dump.str());

    for(obj = obj_iterator(objects_ptr.begin()) ; obj != last_obj; ++obj) 
	{
        delete *obj;
	}
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
