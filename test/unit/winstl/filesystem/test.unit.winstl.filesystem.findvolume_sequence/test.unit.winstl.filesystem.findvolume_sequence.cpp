/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.winstl.filesystem.findvolume_sequence.cpp
 *
 * Purpose:     Implementation file for the test.unit.winstl.filesystem.findvolume_sequence project.
 *
 * Created:     28th January 2009
 * Updated:     6th May 2009
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

#include <winstl/filesystem/findvolume_sequence.hpp>

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
#include <stlsoft/algorithms/std/alt.hpp>
#include <stlsoft/iterators/null_output_iterator.hpp>
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <algorithm>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_14(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * FindVolume() API
 */

#ifdef WINSTL_FINDVOLUME_API_NOT_DECLARED

# include <winstl/dl/dl_call.hpp>

HANDLE WINAPI FindFirstVolumeA(
  LPSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
)
{
    try
    {
        return winstl::dl_call<HANDLE>("kernel32", "S:FindFirstVolumeA", lpszVolumeName, cchBufferLength);
    }
    catch(winstl::missing_entry_point_exception&)
    {
        return INVALID_HANDLE_VALUE;
    }
}

HANDLE WINAPI FindFirstVolumeW(
  LPWSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
);

BOOL WINAPI FindNextVolumeA(
  HANDLE hFindVolume,      // volume search handle
  LPSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
)
{
    try
    {
        return winstl::dl_call<BOOL>("kernel32", "S:FindNextVolumeA", hFindVolume, lpszVolumeName, cchBufferLength);
    }
    catch(winstl::missing_entry_point_exception&)
    {
        return FALSE;
    }
}

BOOL WINAPI FindNextVolumeW(
  HANDLE hFindVolume,      // volume search handle
  LPWSTR lpszVolumeName,   // output buffer
  DWORD cchBufferLength    // size of output buffer
);

BOOL WINAPI FindVolumeClose(
    HANDLE hFindVolume
    )
{
    try
    {
        return winstl::dl_call<BOOL>("kernel32", "S:FindVolumeClose", hFindVolume);
    }
    catch(winstl::missing_entry_point_exception&)
    {
        return FALSE;
    }
}



#endif /* WINSTL_FINDVOLUME_API_NOT_DECLARED */

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.winstl.filesystem.findvolume_sequence", verbosity))
    {
        XTESTS_RUN_CASE(test_1_14);


#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*winstl/*/findvolume_sequence.hpp", NULL);
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
    typedef winstl::basic_findvolume_sequence<char>     fvs_m_t;
    typedef winstl::basic_findvolume_sequence<wchar_t>  fvs_w_t;

static void test_1_14()
{
    fvs_m_t volumes;

    stlsoft::std_copy(  volumes.begin(), volumes.end()
                    ,   stlsoft::null_output_iterator<fvs_m_t::value_type>());
}



} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
