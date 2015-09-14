/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.stlsoft.iterator.associative_select_iterator.cpp
 *
 * Purpose:     Implementation file for the test.scratch.stlsoft.iterator.associative_select_iterator project.
 *
 * Created:     7th November 2010
 * Updated:     11th August 2010
 *
 * Thanks:      To Manfred Ehrhart, for supplying the test program.
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* STLSoft Header Files */
#include <stlsoft/iterators/associative_select_iterator.hpp>
#include <stlsoft/tr1/nullptr.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

/* Standard C Header Files */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Types
 */

struct Something
{
    Something(const std::string& name)
        : name_(name)
    {}
    Something()
        : name_("nothing")
    {}

    friend std::ostream& operator<<(std::ostream& out, const Something& some)
    {
        out << some.name_.c_str();
        return out;
    }

    std::string name_;
};

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    typedef std::map<int, Something*> map_ptr;
    typedef std::map<int, Something> map_obj;

    {
        typedef stlsoft::associative_select_iterator<
                map_obj::const_iterator,
                stlsoft::select_first<map_obj::value_type>
            > key_const_iterator;

        typedef stlsoft::associative_select_iterator<
                map_obj::const_iterator,
                stlsoft::select_second_const<map_obj::value_type>
            > obj_const_iterator;

        typedef stlsoft::associative_select_iterator<
                map_obj::iterator,
                stlsoft::select_second<map_obj::value_type>
            > obj_iterator;

        map_obj objects;
        objects[0] = Something("zero");
        objects[1] = Something("one");
        objects[2] = Something("two");

        std::ostringstream dump;

        key_const_iterator key      = objects.begin();
        key_const_iterator last_key = objects.end();

        for(; key != last_key; ++key)
        {
            dump << *key << ',';
        }
        std::cout << dump.str() << std::endl;
        STLSOFT_ASSERT(dump.str() == "0,1,2,");

        obj_const_iterator const_obj        =   objects.begin();
        obj_const_iterator last_const_obj   =   objects.end();

        dump.str("");
        for(; const_obj != last_const_obj; ++const_obj)
        {
            dump << *const_obj << ',';
        }
        std::cout << dump.str() << std::endl;
        STLSOFT_ASSERT(dump.str() == "zero,one,two,");

        obj_iterator obj        =   objects.begin();
        obj_iterator last_obj   =   objects.end();

        dump.str("");
        for(; obj != last_obj; ++obj)
        {
            (*obj).name_[0] = char(::toupper((*obj).name_[0]));
        }
        for(obj = obj_iterator(objects.begin()) ; obj != last_obj; ++obj)
        {
            dump << *obj << ',';
        }
        std::cout << dump.str() << std::endl;
        STLSOFT_ASSERT(dump.str() == "Zero,One,Two,");
    }

    {
        typedef stlsoft::associative_select_iterator<
                map_ptr::const_iterator,
                stlsoft::select_first<map_ptr::value_type>
            > key_const_iterator;

        typedef stlsoft::associative_select_iterator<
                map_ptr::const_iterator,
                stlsoft::select_second_const<map_ptr::value_type>
            > obj_const_iterator;

        typedef stlsoft::associative_select_iterator<
                map_ptr::iterator,
                stlsoft::select_second<map_ptr::value_type>
            > obj_iterator;

        map_ptr objects_ptr;
        objects_ptr[0] = new Something("zero");
        objects_ptr[1] = new Something("one");
        objects_ptr[2] = new Something("two");

        std::ostringstream dump;

        key_const_iterator key      =   objects_ptr.begin();
        key_const_iterator last_key =   objects_ptr.end();

        for(; key != last_key; ++key)
        {
            dump << *key << ',';
        }
        std::cout << dump.str() << std::endl;
        STLSOFT_ASSERT(dump.str() == "0,1,2,");

        obj_const_iterator const_obj        =   objects_ptr.begin();
        obj_const_iterator last_const_obj   =   objects_ptr.end();

        dump.str("");
        for(; const_obj != last_const_obj; ++const_obj)
        {
            dump << **const_obj << ',';
        }
        std::cout << dump.str() << std::endl;
        STLSOFT_ASSERT(dump.str() == "zero,one,two,");

        obj_iterator obj        =   objects_ptr.begin();
        obj_iterator last_obj   =   objects_ptr.end();

        dump.str("");
        for(; obj != last_obj; ++obj)
        {
            (*obj)->name_[0] = char(::toupper((*obj)->name_[0]));
        }
        for(obj = obj_iterator(objects_ptr.begin()) ; obj != last_obj; ++obj)
        {
            dump << **obj << ',';
        }
        std::cout << dump.str() << std::endl;
        STLSOFT_ASSERT(dump.str() == "Zero,One,Two,");

        for(obj = obj_iterator(objects_ptr.begin()) ; obj != last_obj; ++obj)
        {
            delete *obj;
        }
    }

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
        puts("test.scratch.stlsoft.iterator.associative_select_iterator: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
