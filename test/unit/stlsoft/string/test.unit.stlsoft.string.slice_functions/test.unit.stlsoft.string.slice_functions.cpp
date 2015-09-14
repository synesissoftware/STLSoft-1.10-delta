/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.string.slice_functions.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.string.slice_functions project.
 *
 * Created:     12th October 2010
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

#include <stlsoft/string/slice_functions.hpp>

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
#include <stlsoft/string/string_view.hpp>

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

  static void test_4_00(void);
  static void test_4_01(void);
  static void test_4_02(void);
  static void test_4_03(void);
  static void test_4_04(void);
  static void test_4_05(void);
  static void test_4_06(void);
  static void test_4_07(void);
  static void test_4_08(void);
  static void test_4_09(void);
  static void test_4_10(void);
  static void test_4_11(void);
  static void test_4_12(void);
  static void test_4_13(void);
  static void test_4_14(void);
  static void test_4_15(void);
  static void test_4_16(void);
  static void test_4_17(void);
  static void test_4_18(void);
  static void test_4_19(void);

  static void test_5_00(void);
  static void test_5_01(void);
  static void test_5_02(void);
  static void test_5_03(void);
  static void test_5_04(void);
  static void test_5_05(void);
  static void test_5_06(void);
  static void test_5_07(void);
  static void test_5_08(void);
  static void test_5_09(void);
  static void test_5_10(void);
  static void test_5_11(void);
  static void test_5_12(void);
  static void test_5_13(void);
  static void test_5_14(void);
  static void test_5_15(void);
  static void test_5_16(void);
  static void test_5_17(void);
  static void test_5_18(void);
  static void test_5_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
  int retCode = EXIT_SUCCESS;
  int verbosity = 2;

  XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

  if(XTESTS_START_RUNNER("test.unit.stlsoft.string.slice_functions", verbosity))
  {
    XTESTS_RUN_CASE(test_1_00);
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

    XTESTS_RUN_CASE(test_4_00);
    XTESTS_RUN_CASE(test_4_01);
    XTESTS_RUN_CASE(test_4_02);
    XTESTS_RUN_CASE(test_4_03);
    XTESTS_RUN_CASE(test_4_04);
    XTESTS_RUN_CASE(test_4_05);
    XTESTS_RUN_CASE(test_4_06);
    XTESTS_RUN_CASE(test_4_07);
    XTESTS_RUN_CASE(test_4_08);
    XTESTS_RUN_CASE(test_4_09);
    XTESTS_RUN_CASE(test_4_10);
    XTESTS_RUN_CASE(test_4_11);
    XTESTS_RUN_CASE(test_4_12);
    XTESTS_RUN_CASE(test_4_13);
    XTESTS_RUN_CASE(test_4_14);
    XTESTS_RUN_CASE(test_4_15);
    XTESTS_RUN_CASE(test_4_16);
    XTESTS_RUN_CASE(test_4_17);
    XTESTS_RUN_CASE(test_4_18);
    XTESTS_RUN_CASE(test_4_19);

    XTESTS_RUN_CASE(test_5_00);
    XTESTS_RUN_CASE(test_5_01);
    XTESTS_RUN_CASE(test_5_02);
    XTESTS_RUN_CASE(test_5_03);
    XTESTS_RUN_CASE(test_5_04);
    XTESTS_RUN_CASE(test_5_05);
    XTESTS_RUN_CASE(test_5_06);
    XTESTS_RUN_CASE(test_5_07);
    XTESTS_RUN_CASE(test_5_08);
    XTESTS_RUN_CASE(test_5_09);
    XTESTS_RUN_CASE(test_5_10);
    XTESTS_RUN_CASE(test_5_11);
    XTESTS_RUN_CASE(test_5_12);
    XTESTS_RUN_CASE(test_5_13);
    XTESTS_RUN_CASE(test_5_14);
    XTESTS_RUN_CASE(test_5_15);
    XTESTS_RUN_CASE(test_5_16);
    XTESTS_RUN_CASE(test_5_17);
    XTESTS_RUN_CASE(test_5_18);
    XTESTS_RUN_CASE(test_5_19);

#ifdef STLSOFT_USE_XCOVER
    XCOVER_REPORT_ALIAS_COVERAGE("slice_functions", NULL);
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
#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
  {
    char const source[] = "";

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(source, 0u).empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(source, 0u).size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::left_view(source, 0u));
  }
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
# if !defined(STLSOFT_COMPILER_IS_GCC) && \
     !defined(STLSOFT_COMPILER_IS_MWERKS)
  {
    char source[] = "";

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(source, 0u).empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(source, 0u).size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::left_view(source, 0u));
  }
# endif /* compiler */
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
}

static void test_1_01()
{
  {
    char const source_[] = "";
    char const* source = source_;

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(source, 0u).empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(source, 0u).size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::left_view(source, 0u));
  }

//# if !defined(STLSOFT_COMPILER_IS_MSVC) || \ 
//     _MSC_VER >= 1310
//  {
//    char source_[] = "";
//    char* source = source_;
//
//    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(source, 0u).empty());
//    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(source, 0u).size());
//    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::left_view(source, 0u));
//  }
//# endif /* compiler */
}

static void test_1_02()
{
}

static void test_1_03()
{
}

static void test_1_04()
{
}

static void test_1_05()
{
}

static void test_1_06()
{
}

static void test_1_07()
{
}

static void test_1_08()
{
}

static void test_1_09()
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




static void test_2_00()
{
  XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(std::string(), 0u).empty());
  XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(std::string(), 0u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::left_view(std::string(), 0u));
}

static void test_2_01()
{
  XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(std::string("abc"), 0u).empty());
  XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(std::string("abc"), 0u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::left_view(std::string("abc"), 0u));
}

static void test_2_02()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(std::string("abc"), 1u).empty());
  XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::left_view(std::string("abc"), 1u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", stlsoft::left_view(std::string("abc"), 1u));
}

static void test_2_03()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(std::string("abc"), 2u).empty());
  XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::left_view(std::string("abc"), 2u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", stlsoft::left_view(std::string("abc"), 2u));
}

static void test_2_04()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(std::string("abc"), 3u).empty());
  XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::left_view(std::string("abc"), 3u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", stlsoft::left_view(std::string("abc"), 3u));
}

static void test_2_05()
{
  { for(size_t i = 4; i != 20; ++i)
  {
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(std::string("abc"), i).empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::left_view(std::string("abc"), i).size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", stlsoft::left_view(std::string("abc"), i));
  }}
}

static void test_2_06()
{
}

static void test_2_07()
{
}

static void test_2_08()
{
}

static void test_2_09()
{
}

static void test_2_10()
{
}

static void test_2_11()
{
}

static void test_2_12()
{
}

static void test_2_13()
{
}

static void test_2_14()
{
}

static void test_2_15()
{
}

static void test_2_16()
{
}

static void test_2_17()
{
}

static void test_2_18()
{
}

static void test_2_19()
{
}



static void test_3_00()
{
  XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(stlsoft::simple_string(), 0u).empty());
  XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(stlsoft::simple_string(), 0u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::left_view(stlsoft::simple_string(), 0u));
}

static void test_3_01()
{
  XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(stlsoft::simple_string("abc"), 0u).empty());
  XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(stlsoft::simple_string("abc"), 0u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::left_view(stlsoft::simple_string("abc"), 0u));
}

static void test_3_02()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(stlsoft::simple_string("abc"), 1u).empty());
  XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::left_view(stlsoft::simple_string("abc"), 1u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", stlsoft::left_view(stlsoft::simple_string("abc"), 1u));
}

static void test_3_03()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(stlsoft::simple_string("abc"), 2u).empty());
  XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::left_view(stlsoft::simple_string("abc"), 2u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", stlsoft::left_view(stlsoft::simple_string("abc"), 2u));
}

static void test_3_04()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(stlsoft::simple_string("abc"), 3u).empty());
  XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::left_view(stlsoft::simple_string("abc"), 3u).size());
  XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", stlsoft::left_view(stlsoft::simple_string("abc"), 3u));
}

static void test_3_05()
{
  { for(size_t i = 4; i != 20; ++i)
  {
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(stlsoft::simple_string("abc"), i).empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::left_view(stlsoft::simple_string("abc"), i).size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", stlsoft::left_view(stlsoft::simple_string("abc"), i));
  }}
}

static void test_3_06()
{
}

static void test_3_07()
{
}

static void test_3_08()
{
}

static void test_3_09()
{
}

static void test_3_10()
{
}

static void test_3_11()
{
}

static void test_3_12()
{
}

static void test_3_13()
{
}

static void test_3_14()
{
}

static void test_3_15()
{
}

static void test_3_16()
{
}

static void test_3_17()
{
}

static void test_3_18()
{
}

static void test_3_19()
{
}



static void test_4_00()
{
  XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(std::wstring(), 0u).empty());
  XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(std::wstring(), 0u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::left_view(std::wstring(), 0u));
}

static void test_4_01()
{
  XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(std::wstring(L"abc"), 0u).empty());
  XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(std::wstring(L"abc"), 0u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::left_view(std::wstring(L"abc"), 0u));
}

static void test_4_02()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(std::wstring(L"abc"), 1u).empty());
  XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::left_view(std::wstring(L"abc"), 1u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"a", stlsoft::left_view(std::wstring(L"abc"), 1u));
}

static void test_4_03()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(std::wstring(L"abc"), 2u).empty());
  XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::left_view(std::wstring(L"abc"), 2u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"ab", stlsoft::left_view(std::wstring(L"abc"), 2u));
}

static void test_4_04()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(std::wstring(L"abc"), 3u).empty());
  XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::left_view(std::wstring(L"abc"), 3u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", stlsoft::left_view(std::wstring(L"abc"), 3u));
}

static void test_4_05()
{
  { for(size_t i = 4; i != 20; ++i)
  {
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(std::wstring(L"abc"), i).empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::left_view(std::wstring(L"abc"), i).size());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", stlsoft::left_view(std::wstring(L"abc"), i));
  }}
}

static void test_4_06()
{
}

static void test_4_07()
{
}

static void test_4_08()
{
}

static void test_4_09()
{
}

static void test_4_10()
{
}

static void test_4_11()
{
}

static void test_4_12()
{
}

static void test_4_13()
{
}

static void test_4_14()
{
}

static void test_4_15()
{
}

static void test_4_16()
{
}

static void test_4_17()
{
}

static void test_4_18()
{
}

static void test_4_19()
{
}



static void test_5_00()
{
  XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(stlsoft::simple_wstring(), 0u).empty());
  XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(stlsoft::simple_wstring(), 0u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::left_view(stlsoft::simple_wstring(), 0u));
}

static void test_5_01()
{
  XTESTS_TEST_BOOLEAN_TRUE(stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 0u).empty());
  XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 0u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 0u));
}

static void test_5_02()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 1u).empty());
  XTESTS_TEST_INTEGER_EQUAL(1u, stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 1u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"a", stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 1u));
}

static void test_5_03()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 2u).empty());
  XTESTS_TEST_INTEGER_EQUAL(2u, stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 2u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"ab", stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 2u));
}

static void test_5_04()
{
  XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 3u).empty());
  XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 3u).size());
  XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", stlsoft::left_view(stlsoft::simple_wstring(L"abc"), 3u));
}

static void test_5_05()
{
  { for(size_t i = 4; i != 20; ++i)
  {
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::left_view(stlsoft::simple_wstring(L"abc"), i).empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft::left_view(stlsoft::simple_wstring(L"abc"), i).size());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", stlsoft::left_view(stlsoft::simple_wstring(L"abc"), i));
  }}
}

static void test_5_06()
{
}

static void test_5_07()
{
}

static void test_5_08()
{
}

static void test_5_09()
{
}

static void test_5_10()
{
}

static void test_5_11()
{
}

static void test_5_12()
{
}

static void test_5_13()
{
}

static void test_5_14()
{
}

static void test_5_15()
{
}

static void test_5_16()
{
}

static void test_5_17()
{
}

static void test_5_18()
{
}

static void test_5_19()
{
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
