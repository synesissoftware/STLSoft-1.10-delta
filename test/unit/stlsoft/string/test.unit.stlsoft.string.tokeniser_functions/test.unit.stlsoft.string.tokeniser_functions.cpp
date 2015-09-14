/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.tokeniser_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.tokeniser_functions project.
 *
 * Created:     24th January 2009
 * Updated:     19th May 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/string/tokeniser_functions.hpp>

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

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_1_00(void);
	static void test_1_01(void);
	static void test_1_02(void);
	static void test_1_03(void);
	static void test_1_04(void);
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

	static void test_2_00(void);
	static void test_2_01(void);
	static void test_2_02(void);
	static void test_2_03(void);
	static void test_2_04(void);
	static void test_2_10(void);
	static void test_2_11(void);
	static void test_2_12(void);
	static void test_2_13(void);
	static void test_2_14(void);
	static void test_2_15(void);
	static void test_2_16(void);
	static void test_2_17(void);
	static void test_2_18(void);
	static void test_2_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.string.tokeniser_functions", verbosity))
	{
		XTESTS_RUN_CASE(test_1_00);
		XTESTS_RUN_CASE(test_1_01);
		XTESTS_RUN_CASE(test_1_02);
		XTESTS_RUN_CASE(test_1_03);
		XTESTS_RUN_CASE(test_1_04);
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

		XTESTS_RUN_CASE(test_2_00);
		XTESTS_RUN_CASE(test_2_01);
		XTESTS_RUN_CASE(test_2_02);
		XTESTS_RUN_CASE(test_2_03);
		XTESTS_RUN_CASE(test_2_04);
		XTESTS_RUN_CASE(test_2_10);
		XTESTS_RUN_CASE(test_2_11);
		XTESTS_RUN_CASE(test_2_12);
		XTESTS_RUN_CASE(test_2_13);
		XTESTS_RUN_CASE(test_2_14);
		XTESTS_RUN_CASE(test_2_15);
		XTESTS_RUN_CASE(test_2_16);
		XTESTS_RUN_CASE(test_2_17);
		XTESTS_RUN_CASE(test_2_18);
		XTESTS_RUN_CASE(test_2_19);

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_ALIAS_COVERAGE("tokeniser_functions", NULL);
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

static void test_1_00()
{
	{
		const char			str[]	=	"";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);
	}

	{
		const char			str[]	=	",";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);
	}

	{
		const char			str[]	=	",,";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);
	}

	{
		const char			str[]	=	"abc";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_INTEGER_EQUAL(0, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(3, p1 - str);
		XTESTS_TEST_POINTER_EQUAL(str, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(end, p);
	}

	{
		const char			str[]	=	"abc,";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_INTEGER_EQUAL(0, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(3, p1 - str);
		XTESTS_TEST_POINTER_EQUAL(str, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(end, p);
	}

	{
		const char			str[]	=	",abc";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_INTEGER_EQUAL(1, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(1, p1 - str);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_INTEGER_EQUAL(1, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(4, p1 - str);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(end, p);
	}

	{
		const char			str[]	=	",abc,";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_INTEGER_EQUAL(1, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(1, p1 - str);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_INTEGER_EQUAL(1, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(4, p1 - str);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(end, p);
	}
}

static void test_1_01()
{
	{
		const char			str[]	=	"";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p);
	}
}

static void test_1_02()
{
	{
		const char			str[]	=	",";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);
	}

	{
		const char			str[]	=	",,";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);
	}
}

static void test_1_03()
{
	{
		const char			str[]	=	",,";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);
	}
}

static void test_1_04()
{
	{
		const char			str[]	=	",,,";
		char const*			p0		=	str;
		char const*			p1		=	str;
		char const* const	end		=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);

		char const*			p;

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 2, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 2, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);

		p = stlsoft::find_next_token(p0, p1, end, ',');

		XTESTS_TEST_POINTER_EQUAL(end, p0);
		XTESTS_TEST_POINTER_EQUAL(end, p1);
		XTESTS_TEST_POINTER_EQUAL(p0, p);
	}
}

static void test_1_10()
{
	const char	str[]		=	"abc";
	const char*	tokens[]	=
	{
			"abc"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	char const* const	end	=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);
	size_t				i	=	0;

	for(; end != stlsoft::find_next_token(p0, p1, end, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_1_11()
{
	const char	str[]		=	"abc,def";
	const char*	tokens[]	=
	{
			"abc"
		,	"def"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	char const* const	end	=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);
	size_t				i	=	0;

	for(; end != stlsoft::find_next_token(p0, p1, end, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_1_12()
{
	const char	str[]		=	"abc,def,ghi";
	const char*	tokens[]	=
	{
			"abc"
		,	"def"
		,	"ghi"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	char const* const	end	=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);
	size_t				i	=	0;

	for(; end != stlsoft::find_next_token(p0, p1, end, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_1_13()
{
	const char	str[]		=	"abc,def,ghi,jkl";
	const char*	tokens[]	=
	{
			"abc"
		,	"def"
		,	"ghi"
		,	"jkl"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	char const* const	end	=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);
	size_t				i	=	0;

	for(; end != stlsoft::find_next_token(p0, p1, end, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_1_14()
{
	const char	str[]		=	",abc,def,ghi,jkl,";
	const char*	tokens[]	=
	{
			""
		,	"abc"
		,	"def"
		,	"ghi"
		,	"jkl"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	char const* const	end	=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);
	size_t				i	=	0;

	for(; end != stlsoft::find_next_token(p0, p1, end, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
	const char	str[]		=	",abc,,def,ghi,,,jkl";
	const char*	tokens[]	=
	{
			""
		,	"abc"
		,	""
		,	"def"
		,	"ghi"
		,	""
		,	""
		,	"jkl"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	char const* const	end	=	str + (STLSOFT_NUM_ELEMENTS(str) - 1);
	size_t				i	=	0;

	for(; end != stlsoft::find_next_token(p0, p1, end, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_1_18()
{
}

static void test_1_19()
{
}


static void test_2_00()
{
	{
		const char			str[]	=	"";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 0, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 0, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 0, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 0, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}

	{
		const char			str[]	=	",";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}

	{
		const char			str[]	=	",,";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 2, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 2, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 2, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 2, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}

	{
		const char			str[]	=	"abc";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_INTEGER_EQUAL(0, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(3, p1 - str);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 3, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 3, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}

	{
		const char			str[]	=	"abc,";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_INTEGER_EQUAL(0, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(3, p1 - str);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 4, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 4, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}

	{
		const char			str[]	=	",abc";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_INTEGER_EQUAL(1, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(1, p1 - str);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_INTEGER_EQUAL(1, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(4, p1 - str);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 4, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 4, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}

	{
		const char			str[]	=	",abc,";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_INTEGER_EQUAL(1, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(1, p1 - str);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_INTEGER_EQUAL(1, p0 - str);
		XTESTS_TEST_INTEGER_EQUAL(4, p1 - str);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 5, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 5, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}
}

static void test_2_01()
{
	{
		const char			str[]	=	"";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 0, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 0, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 0, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 0, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}
}

static void test_2_02()
{
	{
		const char			str[]	=	",";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}

	{
		const char			str[]	=	",,";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 2, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 2, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 2, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 2, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}
}

static void test_2_03()
{
	{
		const char			str[]	=	",,";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 2, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 2, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 2, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 2, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}
}

static void test_2_04()
{
	{
		const char			str[]	=	",,,";
		char const*			p0		=	str;
		char const*			p1		=	str;

		bool				b;

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 1, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 1, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 2, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 2, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 3, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 3, p1);
		XTESTS_TEST_BOOLEAN_TRUE(b);

		b = stlsoft::find_next_token(p0, p1, ',');

		XTESTS_TEST_POINTER_EQUAL(str + 3, p0);
		XTESTS_TEST_POINTER_EQUAL(str + 3, p1);
		XTESTS_TEST_BOOLEAN_FALSE(b);
	}
}

static void test_2_10()
{
	const char	str[]		=	"abc";
	const char*	tokens[]	=
	{
			"abc"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	size_t				i	=	0;

	for(; stlsoft::find_next_token(p0, p1, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_2_11()
{
	const char	str[]		=	"abc,def";
	const char*	tokens[]	=
	{
			"abc"
		,	"def"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	size_t				i	=	0;

	for(; stlsoft::find_next_token(p0, p1, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_2_12()
{
	const char	str[]		=	"abc,def,ghi";
	const char*	tokens[]	=
	{
			"abc"
		,	"def"
		,	"ghi"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	size_t				i	=	0;

	for(; stlsoft::find_next_token(p0, p1, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_2_13()
{
	const char	str[]		=	"abc,def,ghi,jkl";
	const char*	tokens[]	=
	{
			"abc"
		,	"def"
		,	"ghi"
		,	"jkl"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	size_t				i	=	0;

	for(; stlsoft::find_next_token(p0, p1, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_2_14()
{
	const char	str[]		=	",abc,def,ghi,jkl,";
	const char*	tokens[]	=
	{
			""
		,	"abc"
		,	"def"
		,	"ghi"
		,	"jkl"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	size_t				i	=	0;

	for(; stlsoft::find_next_token(p0, p1, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_2_15()
{
}

static void test_2_16()
{
}

static void test_2_17()
{
	const char	str[]		=	",abc,,def,ghi,,,jkl";
	const char*	tokens[]	=
	{
			""
		,	"abc"
		,	""
		,	"def"
		,	"ghi"
		,	""
		,	""
		,	"jkl"
	};

	char const*			p0	=	str;
	char const*			p1	=	str;
	size_t				i	=	0;

	for(; stlsoft::find_next_token(p0, p1, ','); ++i)
	{
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(tokens[i], p0, (p1 - p0));
	}

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(tokens), i);
}

static void test_2_18()
{
}

static void test_2_19()
{
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
