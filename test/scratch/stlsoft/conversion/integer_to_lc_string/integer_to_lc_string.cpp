/* /////////////////////////////////////////////////////////////////////////
 * File:        integer_to_lc_string.cpp
 *
 * Purpose:     Implementation file for the integer_to_lc_string project.
 *
 * Created:     1st November 2011
 * Updated:     2nd September 2012
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011-2012, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/conversion/integer_to_string/integer_to_lc_string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compiler warning suppression
 */

#if defined(_MSC_VER) && \
    _MSC_VER >= 1310
# pragma warning(disable : 4702)
#endif

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

	if(XTESTS_START_RUNNER("integer_to_lc_string", verbosity))
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

	struct item
	{
		int			value;
		char const*	result;
	};


static void test_1_0()
{
#if 0
	{
		char	abc[] = "abc";
		char	num[10];
		char	def[] = "def";

		char const*	s = stlsoft::integer_to_decimal_string(num, STLSOFT_NUM_ELEMENTS(num), INT_MAX);

		puts(s);
		puts(abc);
		puts(num);
		puts(def);

		exit(0);
	}
#endif /* 0 */


	static item const	items[] =
	{
		{	0,				"0"				},
		{	1,				"1"				},
		{	10,				"10"			},
		{	100,			"100"			},
		{	1000,			"1000"			},
		{	10000,			"10000"			},
		{	100000,			"100000"		},
		{	1000000,		"1000000"		},
		{	10000000,		"10000000"		},
		{	100000000,		"100000000"		},
		{	1000000000,		"1000000000"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		num[41];
		char const*	s = stlsoft::integer_to_decimal_string(&num[0], STLSOFT_NUM_ELEMENTS(num), items[i].value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_1()
{
	static char const	grouping[]		=	"\0";
	static char const	thousands_sep[]	=	",";
	static item const	items[] =
	{
		{	0,				"0"				},
		{	1,				"1"				},
		{	10,				"10"			},
		{	100,			"100"			},
		{	1000,			"1000"			},
		{	10000,			"10000"			},
		{	100000,			"100000"		},
		{	1000000,		"1000000"		},
		{	10000000,		"10000000"		},
		{	100000000,		"100000000"		},
		{	1000000000,		"1000000000"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		num[41];
		char const*	s = stlsoft::integer_to_lc_string(grouping, *thousands_sep, &num[0], STLSOFT_NUM_ELEMENTS(num), items[i].value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_2()
{
	// Australia, UK, US, ...
	static char const	grouping[]		=	"\3";
	static char const	thousands_sep[]	=	",";
	static item const	items[] =
	{
		{	0,				"0"				},
		{	1,				"1"				},
		{	10,				"10"			},
		{	100,			"100"			},
		{	1000,			"1,000"			},
		{	10000,			"10,000"		},
		{	100000,			"100,000"		},
		{	1000000,		"1,000,000"		},
		{	10000000,		"10,000,000"	},
		{	100000000,		"100,000,000"	},
		{	1000000000,		"1,000,000,000"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		num[41];
		char const*	s = stlsoft::integer_to_lc_string(grouping, *thousands_sep, &num[0], STLSOFT_NUM_ELEMENTS(num), items[i].value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_3()
{
	static char const	grouping[]		=	{ char(3), char(CHAR_MAX), char(0) };
	static char const	thousands_sep[]	=	",";
	static item const	items[] =
	{
		{	0,				"0"				},
		{	1,				"1"				},
		{	10,				"10"			},
		{	100,			"100"			},
		{	1000,			"1,000"			},
		{	10000,			"10,000"		},
		{	100000,			"100,000"		},
		{	1000000,		"1000,000"		},
		{	10000000,		"10000,000"		},
		{	100000000,		"100000,000"	},
		{	1000000000,		"1000000,000"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		num[41];
		char const*	s = stlsoft::integer_to_lc_string(grouping, *thousands_sep, &num[0], STLSOFT_NUM_ELEMENTS(num), items[i].value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_4()
{
	static char const	grouping[]		=	{ char(2), char(3), char(0) };
	static char const	thousands_sep[]	=	",";
	static item const	items[] =
	{
		{	0,				"0"				},
		{	1,				"1"				},
		{	10,				"10"			},
		{	100,			"1,00"			},
		{	1000,			"10,00"			},
		{	10000,			"100,00"		},
		{	100000,			"1,000,00"		},
		{	1000000,		"10,000,00"		},
		{	10000000,		"100,000,00"	},
		{	100000000,		"1,000,000,00"	},
		{	1000000000,		"10,000,000,00"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		num[41];
		char const*	s = stlsoft::integer_to_lc_string(grouping, *thousands_sep, &num[0], STLSOFT_NUM_ELEMENTS(num), items[i].value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_5()
{
	static char const	grouping[]		=	{ char(2), char(3), char(CHAR_MAX), char(0) };
	static char const	thousands_sep[]	=	",";
	static item const	items[] =
	{
		{	0,				"0"				},
		{	1,				"1"				},
		{	10,				"10"			},
		{	100,			"1,00"			},
		{	1000,			"10,00"			},
		{	10000,			"100,00"		},
		{	100000,			"1,000,00"		},
		{	1000000,		"10,000,00"		},
		{	10000000,		"100,000,00"	},
		{	100000000,		"1000,000,00"	},
		{	1000000000,		"10000,000,00"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		num[41];
		char const*	s = stlsoft::integer_to_lc_string(grouping, *thousands_sep, &num[0], STLSOFT_NUM_ELEMENTS(num), items[i].value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_6()
{
	// Nepal
	static char const	grouping[]		=	{ char(3), char(2), char(0) };
	static char const	thousands_sep[]	=	",";
	static item const	items[] =
	{
		{	0,				"0"					},
		{	1,				"1"					},
		{	10,				"10"				},
		{	100,			"100"				},
		{	1000,			"1,000"				},
		{	10000,			"10,000"			},
		{	100000,			"1,00,000"			},
		{	1000000,		"10,00,000"			},
		{	10000000,		"1,00,00,000"		},
		{	100000000,		"10,00,00,000"		},
		{	1000000000,		"1,00,00,00,000"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		num[41];
		char const*	s = stlsoft::integer_to_lc_string(grouping, *thousands_sep, &num[0], STLSOFT_NUM_ELEMENTS(num), items[i].value);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
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
