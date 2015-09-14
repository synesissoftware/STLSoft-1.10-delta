/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.smartptr.scoped_method.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.smartptr.scoped_method project.
 *
 * Created:     16th October 2008
 * Updated:     18th November 2008
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/smartptr/scoped_method.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.smartptr.scoped_method", verbosity))
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

namespace
{

	class Class0
	{
	public:
		Class0()
			: value(0)
		{}

	public:
		void method()
		{
			++value;
		}

	public:
		int value;
	};


	class Class1
	{
	public:
		Class1()
			: value(0)
		{}

	public:
		void method(int addedValue)
		{
			value += addedValue;
		}

	public:
		int value;
	};


	class Class2
	{
	public:
		Class2()
			: value(0)
		{}

	public:
#if 0
		void method(int addedValue, char const* num)
		{
			value += addedValue;

			value *= ::atoi(num);
		}
#else /* ? 0 */
		void method(int addedValue, int num)
		{
			value += addedValue;

			value *= num;
		}
#endif /* 0 */

	public:
		int value;
	};

	class Class1_RefParam
	{
	public:
		Class1_RefParam()
			: value(0)
		{}

	public:
		void method(int* num)
		{
			std::swap(*num, value);
		}

	public:
		int value;
	};


static void test_1_0()
{
	Class0	instance;

	XTESTS_TEST_INTEGER_EQUAL(0, instance.value);

	{
		stlsoft::scoped_method<Class0>	scoper(instance, &Class0::method);

		XTESTS_TEST_INTEGER_EQUAL(0, instance.value);
	}

	XTESTS_TEST_INTEGER_EQUAL(1, instance.value);
}

static void test_1_1()
{
	Class1	instance;

	XTESTS_TEST_INTEGER_EQUAL(0, instance.value);

	{
		stlsoft::scoped_method<Class1>	scoper(&instance, &Class1::method, 10);

		XTESTS_TEST_INTEGER_EQUAL(0, instance.value);
	}

	XTESTS_TEST_INTEGER_EQUAL(10, instance.value);
}

static void test_1_2()
{
#ifndef STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT

	Class2	instance;

	XTESTS_TEST_INTEGER_EQUAL(0, instance.value);

	{
#if 0
		stlsoft::scoped_method<Class2>	scoper(instance, &Class2::method, 3, "100");
#else /* ? 0 */
		stlsoft::scoped_method<Class2>	scoper(instance, &Class2::method, 3, 100);
#endif /* 0 */

		XTESTS_TEST_INTEGER_EQUAL(0, instance.value);
	}

	XTESTS_TEST_INTEGER_EQUAL(300, instance.value);

#endif /* !STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT */
}

static void test_1_3()
{
}

static void test_1_4()
{
	Class1_RefParam	instance;

	XTESTS_TEST_INTEGER_EQUAL(0, instance.value);

	int	num = 10;

	{
		stlsoft::scoped_method<Class1_RefParam>	scoper(&instance, &Class1_RefParam::method, &num);

		XTESTS_TEST_INTEGER_EQUAL(0, instance.value);
		XTESTS_TEST_INTEGER_EQUAL(10, num);
	}

	XTESTS_TEST_INTEGER_EQUAL(10, instance.value);
	XTESTS_TEST_INTEGER_EQUAL(0, num);
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
