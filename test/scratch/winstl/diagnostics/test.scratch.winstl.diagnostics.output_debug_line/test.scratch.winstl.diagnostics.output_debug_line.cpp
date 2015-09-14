/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.winstl.diagnostics.output_debug_line.cpp
 *
 * Purpose:     Implementation file for the test.scratch.winstl.diagnostics.output_debug_line project.
 *
 * Created:     5th January 2011
 * Updated:     5th June 2011
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
#include <winstl/diagnostics/output_debug_line.hpp>
#include <winstl/error/error_desc.hpp>

/* Standard C++ Header Files */
#include <exception>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
	winstl::diagnostics::output_debug_line("line-1");
	winstl::diagnostics::output_debug_line("line number 1");

	winstl::diagnostics::output_debug_line("line-", "1");
	winstl::diagnostics::output_debug_line("line number ", "1");

	winstl::diagnostics::output_debug_line("abcdefgh");
	winstl::diagnostics::output_debug_line("a", "bcdefgh");
	winstl::diagnostics::output_debug_line("a", "b", "cdefgh");
	winstl::diagnostics::output_debug_line("a", "b", "c", "defgh");
	winstl::diagnostics::output_debug_line("a", "b", "c", "d", "efgh");
	winstl::diagnostics::output_debug_line("a", "b", "c", "d", "e", "fgh");
	winstl::diagnostics::output_debug_line("a", "b", "c", "d", "e", "f", "gh");
	winstl::diagnostics::output_debug_line("a", "b", "c", "d", "e", "f", "g", "h");

	winstl::diagnostics::output_debug_line("aaaabbbbccccddddeeeeffffgggghhhh");
	winstl::diagnostics::output_debug_line("aaaa", "bbbbccccddddeeeeffffgggghhhh");
	winstl::diagnostics::output_debug_line("aaaa", "bbbb", "ccccddddeeeeffffgggghhhh");
	winstl::diagnostics::output_debug_line("aaaa", "bbbb", "cccc", "ddddeeeeffffgggghhhh");
	winstl::diagnostics::output_debug_line("aaaa", "bbbb", "cccc", "dddd", "eeeeffffgggghhhh");
	winstl::diagnostics::output_debug_line("aaaa", "bbbb", "cccc", "dddd", "eeee", "ffffgggghhhh");
	winstl::diagnostics::output_debug_line("aaaa", "bbbb", "cccc", "dddd", "eeee", "ffff", "gggghhhh");
	winstl::diagnostics::output_debug_line("aaaa", "bbbb", "cccc", "dddd", "eeee", "ffff", "gggg", "hhhh");

	return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
  try
  {
    return main_(argc, argv);
  }
  catch(std::exception& x)
  {
    fprintf(stderr, "Unhandled error: %s\n", x.what());
  }
  catch(...)
  {
    fprintf(stderr, "Unhandled unknown error\n");
  }

  return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
