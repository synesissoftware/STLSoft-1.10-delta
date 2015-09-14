/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.filesystem.path_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.filesystem.path_functions project.
 *
 * Created:     31st December 2008
 * Updated:     24th February 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/filesystem/path_functions.hpp>

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
//#include <winstl/filesystem/current_directory.hpp>
//#include <winstl/system/windows_directory.hpp>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_1_01(void);
	static void test_1_02(void);
	static void test_1_03(void);
	static void test_1_04(void);
	static void test_1_05(void);
	static void test_1_06(void);
	static void test_1_07(void);
	static void test_1_08(void);
	static void test_1_09(void);
	static void test_1_10(void);
	static void test_1_11(void);
	static void test_1_12(void);
	static void test_1_13(void);
	static void test_1_14(void);

	static void test_2_01(void);
	static void test_2_02(void);
	static void test_2_03(void);
	static void test_2_04(void);
	static void test_2_05(void);
	static void test_2_06(void);
	static void test_2_07(void);
	static void test_2_08(void);
	static void test_2_09(void);
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
	static void test_2_20(void);
	static void test_2_21(void);
	static void test_2_22(void);
	static void test_2_23(void);
	static void test_2_24(void);
	static void test_2_25(void);
	static void test_2_26(void);
	static void test_2_27(void);
	static void test_2_28(void);
	static void test_2_29(void);

	static void test_3_00(void);
	static void test_3_01(void);
	static void test_3_02(void);
	static void test_3_03(void);
	static void test_3_04(void);
	static void test_3_05(void);
	static void test_3_06(void);
	static void test_3_07(void);
	static void test_3_08(void);
	static void test_3_09(void);
	static void test_3_10(void);
	static void test_3_11(void);
	static void test_3_12(void);
	static void test_3_13(void);
	static void test_3_14(void);
	static void test_3_15(void);
	static void test_3_16(void);
	static void test_3_17(void);
	static void test_3_18(void);
	static void test_3_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER_WITH_FLAGS("test.unit.winstl.filesystem.path_functions", verbosity, xtests::c::xtestsReportOnlyNonEmptyCases))
	{
		XTESTS_RUN_CASE(test_1_01);
		XTESTS_RUN_CASE(test_1_02);
		XTESTS_RUN_CASE(test_1_03);
		XTESTS_RUN_CASE(test_1_04);
		XTESTS_RUN_CASE(test_1_05);
		XTESTS_RUN_CASE(test_1_06);
		XTESTS_RUN_CASE(test_1_07);
		XTESTS_RUN_CASE(test_1_08);
		XTESTS_RUN_CASE(test_1_09);
		XTESTS_RUN_CASE(test_1_10);
		XTESTS_RUN_CASE(test_1_11);
		XTESTS_RUN_CASE(test_1_12);
		XTESTS_RUN_CASE(test_1_13);
		XTESTS_RUN_CASE(test_1_14);

		XTESTS_RUN_CASE(test_2_01);
		XTESTS_RUN_CASE(test_2_02);
		XTESTS_RUN_CASE(test_2_03);
		XTESTS_RUN_CASE(test_2_04);
		XTESTS_RUN_CASE(test_2_05);
		XTESTS_RUN_CASE(test_2_06);
		XTESTS_RUN_CASE(test_2_07);
		XTESTS_RUN_CASE(test_2_08);
		XTESTS_RUN_CASE(test_2_09);
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
		XTESTS_RUN_CASE(test_2_20);
		XTESTS_RUN_CASE(test_2_21);
		XTESTS_RUN_CASE(test_2_22);
		XTESTS_RUN_CASE(test_2_23);
		XTESTS_RUN_CASE(test_2_24);
		XTESTS_RUN_CASE(test_2_25);
		XTESTS_RUN_CASE(test_2_26);
		XTESTS_RUN_CASE(test_2_27);
		XTESTS_RUN_CASE(test_2_28);
		XTESTS_RUN_CASE(test_2_29);

		XTESTS_RUN_CASE(test_3_00);
		XTESTS_RUN_CASE(test_3_01);
		XTESTS_RUN_CASE(test_3_02);
		XTESTS_RUN_CASE(test_3_03);
		XTESTS_RUN_CASE(test_3_04);
		XTESTS_RUN_CASE(test_3_05);
		XTESTS_RUN_CASE(test_3_06);
		XTESTS_RUN_CASE(test_3_07);
		XTESTS_RUN_CASE(test_3_08);
		XTESTS_RUN_CASE(test_3_09);
#if 0
		XTESTS_RUN_CASE(test_3_10);
		XTESTS_RUN_CASE(test_3_11);
		XTESTS_RUN_CASE(test_3_12);
		XTESTS_RUN_CASE(test_3_13);
		XTESTS_RUN_CASE(test_3_14);
		XTESTS_RUN_CASE(test_3_15);
		XTESTS_RUN_CASE(test_3_16);
		XTESTS_RUN_CASE(test_3_17);
		XTESTS_RUN_CASE(test_3_18);
		XTESTS_RUN_CASE(test_3_19);
#endif /* 0 */

#ifdef STLSOFT_USE_XCOVER
		XCOVER_REPORT_FILE_COVERAGE("*winstl/*/path_functions.hpp", NULL);
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

static void test_1_01()
{
	size_t	cch = winstl::path_squeeze("abcdef.ghi", static_cast<char*>(NULL), 0);

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
}

static void test_1_02()
{
	char	buffer[1];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, 0);

	XTESTS_TEST_INTEGER_EQUAL(0u, cch);
}

static void test_1_03()
{
	char	buffer[1];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(1u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", buffer);
}

static void test_1_04()
{
	char	buffer[2];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(2u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", buffer);
}

static void test_1_05()
{
	char	buffer[3];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(3u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", buffer);
}

static void test_1_06()
{
	char	buffer[4];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(4u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", buffer);
}

static void test_1_07()
{
	char	buffer[5];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(5u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcd", buffer);
}

static void test_1_08()
{
	char	buffer[6];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(6u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a...i", buffer);
}

static void test_1_09()
{
	char	buffer[7];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(7u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a...hi", buffer);
}

static void test_1_10()
{
	char	buffer[8];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(8u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab...hi", buffer);
}

static void test_1_11()
{
	char	buffer[9];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(9u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab...ghi", buffer);
}

static void test_1_12()
{
	char	buffer[10];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(10u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc...ghi", buffer);
}

static void test_1_13()
{
	char	buffer[11];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}

static void test_1_14()
{
	char	buffer[12];
	size_t	cch = winstl::path_squeeze("abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}


static void test_2_01()
{
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", static_cast<char*>(NULL), 0);

	XTESTS_TEST_INTEGER_EQUAL(22u, cch);
}

static void test_2_02()
{
	char	buffer[1];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, 0);

	XTESTS_TEST_INTEGER_EQUAL(0u, cch);
}

static void test_2_03()
{
	char	buffer[1];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(1u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", buffer);
}

static void test_2_04()
{
	char	buffer[2];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(2u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", buffer);
}

static void test_2_05()
{
	char	buffer[3];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(3u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", buffer);
}

static void test_2_06()
{
	char	buffer[4];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(4u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", buffer);
}

static void test_2_07()
{
	char	buffer[5];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(5u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcd", buffer);
}

static void test_2_08()
{
	char	buffer[6];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(6u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a...i", buffer);
}

static void test_2_09()
{
	char	buffer[7];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(7u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a...hi", buffer);
}

static void test_2_10()
{
	char	buffer[8];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(8u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab...hi", buffer);
}

static void test_2_11()
{
	char	buffer[9];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(9u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab...ghi", buffer);
}

static void test_2_12()
{
	char	buffer[10];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(10u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc...ghi", buffer);
}

static void test_2_13()
{
	char	buffer[11];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}

static void test_2_14()
{
	char	buffer[12];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}

static void test_2_15()
{
	char	buffer[13];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}

static void test_2_16()
{
	char	buffer[14];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}

static void test_2_17()
{
	char	buffer[15];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}

static void test_2_18()
{
	char	buffer[16];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}

static void test_2_19()
{
	char	buffer[17];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(11u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef.ghi", buffer);
}

static void test_2_20()
{
	char	buffer[18];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(buffer), cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/.../abcdef.ghi", buffer);
}

static void test_2_21()
{
	char	buffer[19];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(buffer), cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/x.../abcdef.ghi", buffer);
}

static void test_2_22()
{
	char	buffer[20];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(buffer), cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/xy.../abcdef.ghi", buffer);
}

static void test_2_23()
{
	char	buffer[21];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(buffer), cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/xyz.../abcdef.ghi", buffer);
}

static void test_2_24()
{
	char	buffer[22];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(buffer), cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/xyz/mno/abcdef.ghi", buffer);
}

static void test_2_25()
{
	char	buffer[23];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/abcdef.ghi", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(22u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("H:/xyz/mno/abcdef.ghi", buffer);
}

static void test_2_26()
{
}

static void test_2_27()
{
}

static void test_2_28()
{
}

static void test_2_29()
{
}


static void test_3_00()
{
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", static_cast<char*>(NULL), 0);

	XTESTS_TEST_INTEGER_EQUAL(15u, cch);
}

static void test_3_01()
{
	char	buffer[1];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, 0);

	XTESTS_TEST_INTEGER_EQUAL(0u, cch);
}

static void test_3_02()
{
	char	buffer[1];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(1u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", buffer);
}

static void test_3_03()
{
	char	buffer[2];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(2u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x", buffer);
}

static void test_3_04()
{
	char	buffer[3];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(3u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x.", buffer);
}

static void test_3_05()
{
	char	buffer[4];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(4u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x.y", buffer);
}

static void test_3_06()
{
	char	buffer[5];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(4u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x.y", buffer);
}

static void test_3_07()
{
	char	buffer[6];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(4u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x.y", buffer);
}

static void test_3_08()
{
	char	buffer[7];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(4u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x.y", buffer);
}

static void test_3_09()
{
	char	buffer[8];
	size_t	cch = winstl::path_squeeze("H:/xyz/mno/x.y", buffer, STLSOFT_NUM_ELEMENTS(buffer));

	XTESTS_TEST_INTEGER_EQUAL(4u, cch);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x.y", buffer);
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
