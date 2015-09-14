/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.stlsoft.shims.access.string.type_info.cpp
 *
 * Purpose:     Implementation file for the test.scratch.stlsoft.shims.access.string.type_info project.
 *
 * Created:     19th December 2011
 * Updated:     19th December 2011
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


/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* STLSoft Header Files */
#include <stlsoft/shims/access/string/std/type_info.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if 0
typedef char                        char_t;
typedef std::basic_string<char_t>   string_t;
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * Function definitions
 */

template <typename S>
void call_c_str_ptr_a(S const& s)
{
	char const* p = stlsoft::c_str_ptr_a(s);
}

template <typename S>
void call_c_str_ptr_w(S const& s)
{
	wchar_t const* p = stlsoft::c_str_ptr_w(s);
}

template <typename S>
void call_c_str_ptr(S const& s)
{
	char const* p = stlsoft::c_str_ptr(s);
}


template <typename S>
void call_c_str_ptr_null_a(S const& s)
{
	char const* p = stlsoft::c_str_ptr_null_a(s);
}

template <typename S>
void call_c_str_ptr_null_w(S const& s)
{
	wchar_t const* p = stlsoft::c_str_ptr_null_w(s);
}

template <typename S>
void call_c_str_ptr_null(S const& s)
{
	char const* p = stlsoft::c_str_ptr_null(s);
}


void call_c_str_pair_a_(
	char const* s
,	size_t		n
)
{}
void call_c_str_pair_w_(
	wchar_t const*	s
,	size_t			n
)
{}

template <typename S>
void call_c_str_pair_a(S const& s)
{
	call_c_str_pair_a_(stlsoft::c_str_data_a(s), stlsoft::c_str_len_a(s));
}

template <typename S>
void call_c_str_pair_w(S const& s)
{
	call_c_str_pair_w_(stlsoft::c_str_data_w(s), stlsoft::c_str_len_w(s));
}

template <typename S>
void call_c_str_pair(S const& s)
{
	call_c_str_pair_a_(stlsoft::c_str_data(s), stlsoft::c_str_len(s));
}

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int /* argc */, char** /*argv*/)
{
	call_c_str_ptr(typeid(int));
	call_c_str_ptr_null(typeid(int));
	call_c_str_pair(typeid(int));
	call_c_str_ptr(typeid(std::string()));
	call_c_str_ptr_null(typeid(std::string()));
	call_c_str_pair(typeid(std::string()));

	call_c_str_ptr_a(typeid(int));
	call_c_str_ptr_null_a(typeid(int));
	call_c_str_pair_a(typeid(int));
	call_c_str_ptr_a(typeid(std::string()));
	call_c_str_ptr_null_a(typeid(std::string()));
	call_c_str_pair_a(typeid(std::string()));

#if !defined(xSTLSOFT_COMPILER_IS_MSVC) || \
	_MSC_VER >= 1310
	call_c_str_ptr_w(typeid(int));
	call_c_str_ptr_null_w(typeid(int));
	call_c_str_pair_w(typeid(int));
	call_c_str_ptr_w(typeid(std::string()));
	call_c_str_ptr_null_w(typeid(std::string()));
	call_c_str_pair_w(typeid(std::string()));
#endif

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
        return main_(argc, argv);
    }
    catch(std::bad_alloc&)
    {
        std::cerr << "out of memory" << std::endl;
    }
    catch(std::exception& x)
    {
        std::cerr << "Unhandled error: " << x.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unhandled unknown error" << std::endl;
    }

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
