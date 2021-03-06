/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.filesystem.is_valid_path.C.c
 *
 * Purpose:     Implementation file for the test.unit.winstl.filesystem.is_valid_path.C project.
 *
 * Created:     1st March 2012
 * Updated:     2nd March 2012
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2012, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/filesystem/path_functions.h>

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
static void test_1_20(void);
static void test_1_21(void);
static void test_1_22(void);
static void test_1_23(void);
static void test_1_24(void);
static void test_1_25(void);
static void test_1_26(void);
static void test_1_27(void);
static void test_1_28(void);
static void test_1_29(void);
static void test_1_30(void);
static void test_1_31(void);
static void test_1_32(void);
static void test_1_33(void);
static void test_1_34(void);
static void test_1_35(void);
static void test_1_36(void);
static void test_1_37(void);
static void test_1_38(void);
static void test_1_39(void);

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.winstl.filesystem.is_valid_path.C", verbosity))
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
		XTESTS_RUN_CASE(test_1_20);
		XTESTS_RUN_CASE(test_1_21);
		XTESTS_RUN_CASE(test_1_22);
		XTESTS_RUN_CASE(test_1_23);
		XTESTS_RUN_CASE(test_1_24);
		XTESTS_RUN_CASE(test_1_25);
		XTESTS_RUN_CASE(test_1_26);
		XTESTS_RUN_CASE(test_1_27);
		XTESTS_RUN_CASE(test_1_28);
		XTESTS_RUN_CASE(test_1_29);
		XTESTS_RUN_CASE(test_1_30);
		XTESTS_RUN_CASE(test_1_31);
		XTESTS_RUN_CASE(test_1_32);
		XTESTS_RUN_CASE(test_1_33);
		XTESTS_RUN_CASE(test_1_34);
		XTESTS_RUN_CASE(test_1_35);
		XTESTS_RUN_CASE(test_1_36);
		XTESTS_RUN_CASE(test_1_37);
		XTESTS_RUN_CASE(test_1_38);
		XTESTS_RUN_CASE(test_1_39);

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
	}

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

static void test_1_0()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a(stlsoft_static_cast(char*, 0), NULL, NULL));

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a(stlsoft_static_cast(char*, 0), &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsNull, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_1()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("", NULL, NULL));

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsEmpty, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_2()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("|", NULL, NULL));

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("|", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathContainsInvalidCharacters, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_3()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("H:\\abc\\def|.ghi", NULL, NULL));

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("H:\\abc\\def|.ghi", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathContainsInvalidCharacters, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(11, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(10, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_4()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\abc\\def.ghi", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\abc\\def.ghi", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 7, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(11, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(14, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_5()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\abc\\", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\abc\\", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 7, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.hasTrailingSeparator);
}

static void test_1_6()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\abc", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\abc", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 3, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 6, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_7()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\a", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\a", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 3, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 4, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_8()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:\\", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 3, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.hasTrailingSeparator);
}

static void test_1_9()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_10()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:abc", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:abc", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 5, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_11()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:a", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:a", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 3, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_12()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:abc\\def", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:abc\\def", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 6, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 9, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_13()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:abc\\", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:abc\\", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 6, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.hasTrailingSeparator);
}

static void test_1_14()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("abc", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("abc", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 3, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_15()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("a", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("a", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_16()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("abc.def", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("abc.def", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL( 4, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 7, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_17()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("a.c", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("a.c", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 3, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_18()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("abc\\a.c", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("abc\\a.c", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 4, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL( 6, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 7, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_19()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("a\\a.c", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("a\\a.c", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL( 4, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 5, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_20()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("a/a.c", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("a/a.c", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL( 4, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 5, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_21()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:/abc/def.ghi", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("H:/abc/def.ghi", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 7, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(11, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(14, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_22()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\dir\\file.ext", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\dir\\file.ext", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(11, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(16, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(21, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(24, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_23()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\v\\h\\d\\f.x", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\v\\h\\d\\f.x", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 5, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 8, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(10, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(11, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_24()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\dir/file.ext", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\dir/file.ext", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(11, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(16, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(21, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(24, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_25()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\dir/", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\dir/", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(11, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(16, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.hasTrailingSeparator);
}

static void test_1_26()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\dir", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\dir", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(11, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(12, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(15, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_27()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\\\svr\\share\\", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL(11, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL(12, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.hasTrailingSeparator);
}

static void test_1_28()
{
	winstl_C_IsValidPath_Reason_t	reason;

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("\\\\svr\\share", NULL, NULL));

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("\\\\svr\\share", &reason, NULL));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_IncompleteUncShare, reason);

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("\\\\svr\\s", &reason, NULL));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_IncompleteUncShare, reason);

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("\\\\svr\\", &reason, NULL));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_IncompleteUncShare, reason);

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("\\\\svr", &reason, NULL));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_IncompleteUncShare, reason);

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("\\\\s", &reason, NULL));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_IncompleteUncShare, reason);

	XTESTS_TEST_BOOLEAN_FALSE(winstl_C_is_path_valid_a("\\\\", &reason, NULL));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_IncompleteUncShare, reason);
}

static void test_1_29()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("\\", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.hasTrailingSeparator);
}

static void test_1_30()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("/", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("/", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.hasTrailingSeparator);
}

static void test_1_31()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("/a", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("/a", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 2, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_32()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("/abc/", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("/abc/", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 5, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 1, results.hasTrailingSeparator);
}

static void test_1_33()
{
	winstl_C_IsValidPath_Reason_t	reason;
	winstl_C_IsValidPath_Results_t	results;

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("/abc/f.x", NULL, NULL));

	XTESTS_TEST_BOOLEAN_TRUE(winstl_C_is_path_valid_a("/abc/f.x", &reason, &results));
	XTESTS_TEST_ENUM_EQUAL(WinSTL_IsValidPath_Reason_PathIsValid, reason);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfVolume);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.offsetOfDirectory);
	XTESTS_TEST_INTEGER_EQUAL( 5, results.offsetOfFileBaseName);
	XTESTS_TEST_INTEGER_EQUAL( 7, results.offsetOfFileExtension);
	XTESTS_TEST_INTEGER_EQUAL( 8, results.parsedLength);
	XTESTS_TEST_INTEGER_EQUAL(-1, results.offsetOfFirstBadCharacter);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isRelativePath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isFullPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.isUncPath);
	XTESTS_TEST_INTEGER_EQUAL( 0, results.hasTrailingSeparator);
}

static void test_1_34()
{
}

static void test_1_35()
{
}

static void test_1_36()
{
}

static void test_1_37()
{
}

static void test_1_38()
{
}

static void test_1_39()
{
}

/* ///////////////////////////// end of file //////////////////////////// */
