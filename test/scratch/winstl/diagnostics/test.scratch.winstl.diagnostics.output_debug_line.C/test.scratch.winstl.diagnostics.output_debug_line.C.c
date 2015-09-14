/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.winstl.diagnostics.output_debug_line.C.c
 *
 * Purpose:     Implementation file for the test.scratch.winstl.diagnostics.output_debug_line.C project.
 *
 * Created:     5th January 2011
 * Updated:     4th June 2011
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* STLSoft Header Files */
#include <winstl/diagnostics/output_debug_line.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
	winstl_C_diagnostics_output_debug_line_1_m("line #1");
	winstl_C_diagnostics_output_debug_line_1_m("line number 2");

	winstl_C_diagnostics_output_debug_line_2_m("line ", "#3");

	winstl_C_diagnostics_output_debug_line_3_m("line ", "number ", "4");

  return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
  return main_(argc, argv);
}

/* ///////////////////////////// end of file //////////////////////////// */
