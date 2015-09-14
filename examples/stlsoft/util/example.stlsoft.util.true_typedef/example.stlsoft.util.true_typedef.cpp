/* /////////////////////////////////////////////////////////////////////////
 * File:        example.stlsoft.util.true_typedef.cpp
 *
 * Purpose:     Implementation file for the example.stlsoft.util.true_typedef project.
 *
 * Created:     17th June 2009
 * Updated:     17th June 2009
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


/* STLSoft Header Files */
#include <stlsoft/util/true_typedef.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <string>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

class File
{
    STLSOFT_GEN_OPAQUE(pathname_u_);
public:
    typedef stlsoft::true_typedef<std::string, pathname_u_>     pathname_type;

public:
    File(pathname_type const& pathname)
        : m_pathname(pathname.base_type_value())
//      : m_pathname(pathname)
    {}

private:
    std::string     m_pathname;
//  pathname_type   m_pathname;
};

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    File::pathname_type path("C:\\temp");

    File                file1(path);

//  File                file2("C:\\temp");				// Does not compile: correct!

//  File                file3(std::string("C:\\temp"));	// Does not compile: correct!

    File                file4(File::pathname_type("C:\\temp"));

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

/* ////////////////////////////////////////////////////////////////////// */

STLSOFT_GEN_OPAQUE(path_type);
typedef stlsoft::true_typedef<std::string, path_type> Pathname;

class Rdi {
private:
Rdi(void);
public:
Rdi(Pathname const& pathname)
: m_Pathname(pathname)
{}

private:
Pathname m_Pathname;
};

void fn()
{
Rdi works(Pathname("C:\\path"));

std::string const path = "C:\\path";
Rdi doesnotwork(Pathname(path)); //Get an error about an incorrect function prototype.

//Workaround
//std::string const path = "C:\\path";
//Pathname const pathTemp(path);
//Rdi doesnotwork(pathTemp);
}