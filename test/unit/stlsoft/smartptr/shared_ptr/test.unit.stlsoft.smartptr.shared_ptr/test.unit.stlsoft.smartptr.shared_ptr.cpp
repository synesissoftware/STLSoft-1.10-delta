/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.smartptr.shared_ptr.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.smartptr.shared_ptr project.
 *
 * Created:     19th April 2009
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

#include <stlsoft/smartptr/shared_ptr.hpp>

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

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_ctor(void);
	static void test_swap_1(void);
	static void test_swap_2(void);
	static void test_shim_get_ptr(void);
	static void test_detach(void);
#if 0
	static void test_reset_1(void);
#endif /* 0 */
	static void test_deref_pointer(void);
	static void test_deref_reference(void);
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

	if(XTESTS_START_RUNNER("test.unit.stlsoft.smartptr.shared_ptr", verbosity))
	{
		XTESTS_RUN_CASE(test_ctor);
		XTESTS_RUN_CASE(test_swap_1);
		XTESTS_RUN_CASE(test_swap_2);
		XTESTS_RUN_CASE(test_shim_get_ptr);
		XTESTS_RUN_CASE(test_detach);
#if 0
		XTESTS_RUN_CASE(test_reset_1);
#endif /* 0 */
		XTESTS_RUN_CASE(test_deref_pointer);
		XTESTS_RUN_CASE(test_deref_reference);
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

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_ALIAS_COVERAGE("shared_ptr", NULL);
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

	class Class
	{
	public:
		Class()
		{
			++NumCtors;
		}
		~Class()
		{
			++NumDtors;
		}

	public:
		void ResetCounters()
		{
			NumCtors	=	0;
			NumDtors	=	0;
		}

	public:
		static int NumCtors;
		static int NumDtors;
	};

	/* static */ int Class::NumCtors = 0;
	/* static */ int Class::NumDtors = 0;



static void test_ctor()
{
	Class::NumCtors	=	0;
	Class::NumDtors	=	0;

	{
		stlsoft::shared_ptr<Class>	scoper(new Class());

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);

		if(NULL != scoper.get())
		{
			XTESTS_TEST_PASSED();
		}
		else
		{
			XTESTS_TEST_FAIL("shared_ptr<>::operator bool_type failed");
		}

		XTESTS_TEST_BOOLEAN_FALSE(NULL == scoper.get());
	}

	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumDtors);
}

static void test_swap_1()
{
	{
		Class::NumCtors	=	0;
		Class::NumDtors	=	0;

		{
			stlsoft::shared_ptr<Class>	scoper2(new Class());

			XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
			XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);
		}

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumDtors);
	}

	{
		Class::NumCtors	=	0;
		Class::NumDtors	=	0;

		stlsoft::shared_ptr<Class>	scoper1(NULL);

		{
			stlsoft::shared_ptr<Class>	scoper2(new Class());

			scoper1.swap(scoper2);

			XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
			XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);
		}

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);
	}

	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumDtors);
}

static void test_swap_2()
{
	{
		Class::NumCtors	=	0;
		Class::NumDtors	=	0;

		{
			stlsoft::shared_ptr<Class>	scoper2(new Class());

			XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
			XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);
		}

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumDtors);
	}

	{
		Class::NumCtors	=	0;
		Class::NumDtors	=	0;

		stlsoft::shared_ptr<Class>	scoper1(NULL);

		{
			stlsoft::shared_ptr<Class>	scoper2(new Class());

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
	_MSC_VER <= 1200
			using stlsoft::swap;
#endif

			swap(scoper1, scoper2);

			XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
			XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);
		}

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);
	}

	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumDtors);
}

static void test_shim_get_ptr()
{
	Class::NumCtors	=	0;
	Class::NumDtors	=	0;

	{
		stlsoft::shared_ptr<Class>	scoper(new Class());

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);

		Class* cls = stlsoft::get_ptr(scoper);

		STLSOFT_SUPPRESS_UNUSED(cls);
	}

	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumDtors);
}

static void test_detach()
{
	Class::NumCtors	=	0;
	Class::NumDtors	=	0;

	Class* cls = NULL;

    STLSOFT_SUPPRESS_UNUSED(cls);

	{
		stlsoft::shared_ptr<Class>	scoper(new Class());

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);

		cls = scoper.detach();
	}

	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
	XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);

	delete cls;
}

#if 0
static void test_reset_1()
{
	Class::NumCtors	=	0;
	Class::NumDtors	=	0;

	Class* cls = NULL;

	{
		stlsoft::shared_ptr<Class>	scoper(new Class());

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);

		cls = scoper.reset();
	}

	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
	XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);

	delete cls;
}
#endif /* 0 */

static void test_deref_pointer()
{
	Class::NumCtors	=	0;
	Class::NumDtors	=	0;

	{
		stlsoft::shared_ptr<Class>	scoper(new Class());

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);

		scoper->ResetCounters();

		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);
	}

	XTESTS_TEST_INTEGER_EQUAL(0, Class::NumCtors);
	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumDtors);
}


static void test_deref_reference()
{
	Class::NumCtors	=	0;
	Class::NumDtors	=	0;

	{
		stlsoft::shared_ptr<Class>	scoper(new Class());

		XTESTS_TEST_INTEGER_EQUAL(1, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);

		(*scoper).ResetCounters();

		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumCtors);
		XTESTS_TEST_INTEGER_EQUAL(0, Class::NumDtors);
	}

	XTESTS_TEST_INTEGER_EQUAL(0, Class::NumCtors);
	XTESTS_TEST_INTEGER_EQUAL(1, Class::NumDtors);
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
