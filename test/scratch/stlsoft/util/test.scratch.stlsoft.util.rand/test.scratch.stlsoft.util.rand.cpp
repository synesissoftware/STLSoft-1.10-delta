/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.stlsoft.util.rand.cpp
 *
 * Purpose:     Implementation file for the test.scratch.stlsoft.util.rand project.
 *
 * Created:     5th September 2010
 * Updated:     5th September 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <stlsoft/util/rand.hpp>

/* FastFormat Header Files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

/* STLSoft Header Files */
#include <stlsoft/container/frequency_map.hpp>
#include <stlsoft/util/limit_traits.h>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

/* Standard C Header Files */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */

/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

using stlsoft::uint16_t;
using stlsoft::uint32_t;
using stlsoft::uint64_t;

/* /////////////////////////////////////////////////////////////////////////
 * Function definitions
 */

unsigned nibble_index(uint16_t const& i)
{
         if(i > 0xfff)
    {
        return 3;
    }
    else if(i > 0xff)
    {
        return 2;
    }
    else if(i > 0xf)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
unsigned nibble_index(uint32_t const& i)
{
         if(i > 0xfffffff)
    {
        return 7;
    }
    else if(i > 0xffffff)
    {
        return 6;
    }
    else if(i > 0xfffff)
    {
        return 5;
    }
    else if(i > 0xffff)
    {
        return 4;
    }
    else if(i > 0xfff)
    {
        return 3;
    }
    else if(i > 0xff)
    {
        return 2;
    }
    else if(i > 0xf)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
unsigned nibble_index(uint64_t const& i)
{
         if(i > STLSOFT_GEN_UINT64_SUFFIX(0xfffffffffffffff))
    {
        return 15;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xffffffffffffff))
    {
        return 14;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xfffffffffffff))
    {
        return 6;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xffffffffffff))
    {
        return 12;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xfffffffffff))
    {
        return 11;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xffffffffff))
    {
        return 10;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xfffffffff))
    {
        return 9;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xffffffff))
    {
        return 8;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xfffffff))
    {
        return 7;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xffffff))
    {
        return 6;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xfffff))
    {
        return 5;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xffff))
    {
        return 4;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xfff))
    {
        return 3;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xff))
    {
        return 2;
    }
    else if(i > STLSOFT_GEN_UINT64_SUFFIX(0xf))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    // Do nibble frequency analyses

    typedef stlsoft::frequency_map<unsigned>    fmap_t;

    fmap_t freqsRAND_MAX;
    fmap_t freqs16;
    fmap_t freqs32;
    fmap_t freqs64;

#ifdef _DEBUG
    { for(unsigned i = 0; i != 2; ++i)
#else
    { for(unsigned i = 0; i != 10000000; ++i)
#endif
    {
        freqsRAND_MAX.push(nibble_index(static_cast<uint64_t>(::rand())));
        freqs16.push(nibble_index(stlsoft::rand<uint16_t>()));
        freqs32.push(nibble_index(stlsoft::rand<uint32_t>()));
        freqs64.push(nibble_index(stlsoft::rand<uint64_t>()));
    }}

    ff::writeln(std::cout, "16:");
    { for(unsigned i = 0; 4 != i; ++i)
    {
        ff::fmtln(
            std::cout
        ,   "{0}\t{1}"
        ,   i
        ,   freqs16[i]
        );
    }}
    ff::writeln(std::cout);

    ff::writeln(std::cout, "RAND_MAX:");
    { for(unsigned i = 0; 4 != i; ++i)
    {
        ff::fmtln(
            std::cout
        ,   "{0}\t{1}"
        ,   i
        ,   freqsRAND_MAX[i]
        );
    }}
    ff::writeln(std::cout);

    ff::writeln(std::cout, "32:");
    { for(unsigned i = 0; 8 != i; ++i)
    {
        ff::fmtln(
            std::cout
        ,   "{0}\t{1}"
        ,   i
        ,   freqs32[i]
        );
    }}
    ff::writeln(std::cout);

    ff::writeln(std::cout, "64:");
    { for(unsigned i = 0; 16 != i; ++i)
    {
        ff::fmtln(
            std::cout
        ,   "{0}\t{1}"
        ,   i
        ,   freqs64[i]
        );
    }}
    ff::writeln(std::cout);

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.stlsoft.util.rand: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        std::cerr << "Unhandled error: " << x.what() << std::endl;

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Unhandled unknown error" << std::endl;

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
