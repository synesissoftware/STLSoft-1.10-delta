/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.system.os_version.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.system.os_version project.
 *
 * Created:     5th November 2014
 * Updated:     5th November 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Mock declarations
 */

#include <winstl/winstl.h>

extern "C"
BOOL
WINAPI
my_GetVersionExA(
    LPOSVERSIONINFOA lpVersionInformation
);

extern "C"
void
my_GetSystemInfo(
    LPSYSTEM_INFO lpSystemInfo
);
extern "C"
void
WINAPI
my_GetNativeSystemInfo(
    LPSYSTEM_INFO lpSystemInfo
);

extern "C"
int
WINAPI
my_GetSystemMetrics(
    int nIndex);

#if !defined(_WIN32_WINNT) || \
	_WIN32_WINNT < 0x0501
# undef _WIN32_WINNT
# define _WIN32_WINNT           (0x0501)
#endif

#define GetVersionExA           my_GetVersionExA
#define GetNativeSystemInfo     my_GetNativeSystemInfo
#define GetSystemMetrics        my_GetSystemMetrics

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <winstl/system/os_version.h>

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
#include <iterator>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#ifndef PROCESSOR_ARCHITECTURE_AMD64
# define PROCESSOR_ARCHITECTURE_AMD64   (9)
#endif
#ifndef PROCESSOR_ARCHITECTURE_ARM
# define PROCESSOR_ARCHITECTURE_ARM     (5)
#endif
#ifndef PROCESSOR_ARCHITECTURE_IA64
# define PROCESSOR_ARCHITECTURE_IA64    (6)
#endif
#ifndef PROCESSOR_ARCHITECTURE_INTEL
# define PROCESSOR_ARCHITECTURE_INTEL   (0)
#endif

#ifndef VER_NT_WORKSTATION
# define VER_NT_WORKSTATION             (1)
#endif

#ifndef VER_SUITE_WH_SERVER
# define VER_SUITE_WH_SERVER            (0x00008000)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_Invalid_because_GetVersionEx_fails(void);
    static void test_Unknown_1_0_0(void);
    static void test_Windows_95(void);
    static void test_Windows_98(void);
    static void test_Windows_ME(void);
    static void test_Windows_NT4(void);
    static void test_Windows_2000(void);
    static void test_Windows_XP(void);
    static void test_Windows_XP_Professional_x64(void);
    static void test_Windows_Home_Server(void);
    static void test_Windows_Server_2003(void);
    static void test_Windows_Server_2003_R2(void);
    static void test_Windows_Vista(void);
    static void test_Windows_Server_2008(void);
    static void test_Windows_Server_2008_R2(void);
    static void test_Windows_7(void);
    static void test_Windows_Server_2012(void);
    static void test_Windows_8(void);
    static void test_Windows_Server_2012_R2(void);
    static void test_Windows_8_1(void);

    static void test_1_02(void);
    static void test_1_03(void);
    static void test_1_04(void);
    static void test_1_05(void);

    static int setup(void*);
    static int teardown(void*);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.unit.winstl.system.os_version", verbosity, setup, teardown, NULL))
    {
        XTESTS_RUN_CASE(test_Invalid_because_GetVersionEx_fails);
        XTESTS_RUN_CASE(test_Unknown_1_0_0);
        XTESTS_RUN_CASE(test_Windows_95);
        XTESTS_RUN_CASE(test_Windows_98);
        XTESTS_RUN_CASE(test_Windows_ME);
        XTESTS_RUN_CASE(test_Windows_NT4);
        XTESTS_RUN_CASE(test_Windows_2000);
        XTESTS_RUN_CASE(test_Windows_XP);
        XTESTS_RUN_CASE(test_Windows_XP_Professional_x64);
        XTESTS_RUN_CASE(test_Windows_Home_Server);
        XTESTS_RUN_CASE(test_Windows_Server_2003);
        XTESTS_RUN_CASE(test_Windows_Server_2003_R2);
        XTESTS_RUN_CASE(test_Windows_Vista);
        XTESTS_RUN_CASE(test_Windows_Server_2008);
        XTESTS_RUN_CASE(test_Windows_Server_2008_R2);
        XTESTS_RUN_CASE(test_Windows_7);
        XTESTS_RUN_CASE(test_Windows_Server_2012);
        XTESTS_RUN_CASE(test_Windows_8);
        XTESTS_RUN_CASE(test_Windows_Server_2012_R2);
        XTESTS_RUN_CASE(test_Windows_8_1);

        XTESTS_RUN_CASE(test_1_02);
        XTESTS_RUN_CASE(test_1_03);
        XTESTS_RUN_CASE(test_1_04);
        XTESTS_RUN_CASE(test_1_05);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Mock implementations
 */

#undef GetVersionExA
#undef GetNativeSystemInfo
#undef GetSystemMetrics

namespace
{

    OSVERSIONINFOEX s_osvi        =   { -1 };
    bool            s_osSucceeds  =   false;

    SYSTEM_INFO     s_si          =   { -1 };

    int             s_sm          =   0;
    bool            s_smOverride  =   false;

} /* anonymous namespace */

extern "C"
BOOL
WINAPI
my_GetVersionExA(
    LPOSVERSIONINFOA lpVersionInformation
)
{
    if(!s_osSucceeds)
    {
        return false;
    }
    else
    {
        memcpy(lpVersionInformation, &s_osvi, lpVersionInformation->dwOSVersionInfoSize);

        return true;
    }
}

extern "C"
void
WINAPI
my_GetNativeSystemInfo(
    LPSYSTEM_INFO lpSystemInfo
)
{
    memcpy(lpSystemInfo, &s_si, sizeof(s_si));
}

extern "C"
int
WINAPI
my_GetSystemMetrics(
    int nIndex)
{
    if(s_smOverride)
    {
        return s_sm;
    }

    return ::GetSystemMetrics(nIndex);
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

#if 0
    using namespace ::winstl::os_version_constants;
#endif /* 0 */


static int setup(void*)
{
    ::memset(&s_osvi, -1, sizeof(s_osvi));
    s_osSucceeds  =   false;

    ::memset(&s_si, -1, sizeof(s_si));

    s_sm          =   0;
    s_smOverride  =   false;

    return 0;
}

static int teardown(void*)
{
    return 0;
}


static void test_Invalid_because_GetVersionEx_fails()
{
    s_osSucceeds            =   false;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Invalid, winstl::identify_operating_system());
}

static void test_Unknown_1_0_0()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   0;
    s_osvi.dwMinorVersion   =   0;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Unknown, winstl::identify_operating_system());
}

static void test_Windows_95()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   4;
    s_osvi.dwMinorVersion       =   0;
    s_osvi.dwPlatformId         =   1;

    s_si.wProcessorArchitecture =   PROCESSOR_ARCHITECTURE_INTEL;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_95, winstl::identify_operating_system());
}

static void test_Windows_98()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   4;
    s_osvi.dwMinorVersion       =   10;
    s_osvi.dwPlatformId         =   1;

    s_si.wProcessorArchitecture =   PROCESSOR_ARCHITECTURE_INTEL;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_98, winstl::identify_operating_system());
}

static void test_Windows_ME()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   4;
    s_osvi.dwMinorVersion       =   90;
    s_osvi.dwPlatformId         =   1;

    s_si.wProcessorArchitecture =   PROCESSOR_ARCHITECTURE_INTEL;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_ME, winstl::identify_operating_system());
}

static void test_Windows_NT4()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   4;
    s_osvi.dwMinorVersion       =   0;
    s_osvi.dwPlatformId         =   2;

    s_si.wProcessorArchitecture =   PROCESSOR_ARCHITECTURE_INTEL;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_NT4, winstl::identify_operating_system());
}

static void test_Windows_2000()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   5;
    s_osvi.dwMinorVersion       =   0;

    s_si.wProcessorArchitecture =   PROCESSOR_ARCHITECTURE_INTEL;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_2000, winstl::identify_operating_system());
}

static void test_Windows_XP()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   5;
    s_osvi.dwMinorVersion       =   1;

    s_si.wProcessorArchitecture =   PROCESSOR_ARCHITECTURE_INTEL;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_XP, winstl::identify_operating_system());
}

static void test_Windows_XP_Professional_x64()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   5;
    s_osvi.dwMinorVersion       =   2;

    ::memset(&s_osvi.wReserved, 0, 2 * sizeof(WORD));
    BYTE* const pyProductType   =   (BYTE*)(&s_osvi.wServicePackMinor + 2);

    *pyProductType              =   VER_NT_WORKSTATION;

    s_si.wProcessorArchitecture =   PROCESSOR_ARCHITECTURE_AMD64;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_XP_Professional_x64, winstl::identify_operating_system());
}

static void test_Windows_Home_Server()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   5;
    s_osvi.dwMinorVersion       =   2;

    ::memset(&s_osvi.wReserved, 0, 2 * sizeof(WORD));
    WORD* const pwSuiteMask     =   &s_osvi.wServicePackMinor + 1;

    *pwSuiteMask                =   VER_SUITE_WH_SERVER;

    s_si.wProcessorArchitecture =   PROCESSOR_ARCHITECTURE_AMD64;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_Home_Server, winstl::identify_operating_system());
}

static void test_Windows_Server_2003()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   5;
    s_osvi.dwMinorVersion       =   2;

    s_sm                        =   0;
    s_smOverride                =   true;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_Server_2003, winstl::identify_operating_system());
}

static void test_Windows_Server_2003_R2()
{
    s_osSucceeds                =   true;

    s_osvi.dwMajorVersion       =   5;
    s_osvi.dwMinorVersion       =   2;

    s_sm                        =   1;
    s_smOverride                =   true;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_Server_2003_R2, winstl::identify_operating_system());
}

static void test_Windows_Vista()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   6;
    s_osvi.dwMinorVersion   =   0;

    ::memset(&s_osvi.wReserved, 0, 2 * sizeof(WORD));
    BYTE* const pyProductType   =   (BYTE*)(&s_osvi.wServicePackMinor + 2);

    *pyProductType              =   VER_NT_WORKSTATION;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_Vista, winstl::identify_operating_system());
}

static void test_Windows_Server_2008()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   6;
    s_osvi.dwMinorVersion   =   0;

    ::memset(&s_osvi.wReserved, 0, 2 * sizeof(WORD));
    BYTE* const pyProductType   =   (BYTE*)(&s_osvi.wServicePackMinor + 2);

    *pyProductType              =   ~VER_NT_WORKSTATION;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_Server_2008, winstl::identify_operating_system());
}

static void test_Windows_Server_2008_R2()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   6;
    s_osvi.dwMinorVersion   =   1;

    ::memset(&s_osvi.wReserved, 0, 2 * sizeof(WORD));
    BYTE* const pyProductType   =   (BYTE*)(&s_osvi.wServicePackMinor + 2);

    *pyProductType              =   ~VER_NT_WORKSTATION;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_Server_2008_R2, winstl::identify_operating_system());
}

static void test_Windows_7()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   6;
    s_osvi.dwMinorVersion   =   1;

    ::memset(&s_osvi.wReserved, 0, 2 * sizeof(WORD));
    BYTE* const pyProductType   =   (BYTE*)(&s_osvi.wServicePackMinor + 2);

    *pyProductType              =   VER_NT_WORKSTATION;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_7, winstl::identify_operating_system());
}

static void test_Windows_Server_2012()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   6;
    s_osvi.dwMinorVersion   =   2;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_Server_2012, winstl::identify_operating_system());
}

static void test_Windows_8()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   6;
    s_osvi.dwMinorVersion   =   2;

    ::memset(&s_osvi.wReserved, 0, 2 * sizeof(WORD));
    BYTE* const pyProductType   =   (BYTE*)(&s_osvi.wServicePackMinor + 2);

    *pyProductType              =   VER_NT_WORKSTATION;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_8, winstl::identify_operating_system());
}

static void test_Windows_Server_2012_R2()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   6;
    s_osvi.dwMinorVersion   =   3;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_Server_2012_R2, winstl::identify_operating_system());
}

static void test_Windows_8_1()
{
    s_osSucceeds            =   true;

    s_osvi.dwMajorVersion   =   6;
    s_osvi.dwMinorVersion   =   3;

    ::memset(&s_osvi.wReserved, 0, 2 * sizeof(WORD));
    BYTE* const pyProductType   =   (BYTE*)(&s_osvi.wServicePackMinor + 2);

    *pyProductType              =   VER_NT_WORKSTATION;

    XTESTS_TEST_ENUM_EQUAL(winstl::WinSTL_OperatingSystemIdentifier_Windows_8_1, winstl::identify_operating_system());
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
