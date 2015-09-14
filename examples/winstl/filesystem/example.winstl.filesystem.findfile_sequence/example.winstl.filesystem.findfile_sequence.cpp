
#include <stlsoft/iterators/ostream_iterator.hpp>
#include <winstl/filesystem/findfile_sequence.hpp>

#include <iostream>

#include <stdlib.h>

int main()
{
    typedef winstl::findfile_sequence seq_t;

    {  // 1. enumerate all contents (except dots dirs)

        seq_t  entries("*.*");

        std::cout << "\n1:\n";
        std::copy(  entries.begin(), entries.end()
                ,   stlsoft::ostream_iterator<seq_t::value_type>(std::cout, "\t", "\n"));
    }

    { // 2. enumerate all contents (including dots dirs)

        seq_t  entries("*.*", seq_t::includeDots);

        std::cout << "\n2:\n";
        std::copy(  entries.begin(), entries.end()
                ,   stlsoft::ostream_iterator<seq_t::value_type>(std::cout, "\t", "\n"));
    }

    {  // 3. enumerate all files, displaying only the relative path

        seq_t  files("*.*", seq_t::files | seq_t::relativePath);

        std::cout << "\n3:\n";
        std::copy(  files.begin(), files.end()
                ,   stlsoft::ostream_iterator<seq_t::value_type>(std::cout, "\t", "\n"));
    }

    {  // 4. enumerate all directories

        seq_t  directories("*.*", seq_t::directories);

        std::cout << "\n4:\n";
        std::copy(  directories.begin(), directories.end()
                ,   stlsoft::ostream_iterator<seq_t::value_type>(std::cout, "\t", "\n"));
    }

    {  // 5. enumerate all files beginning with 'f' and with either extension .h or .hpp

        seq_t  files("f*.h|f*.hpp", '|', seq_t::files);

        std::cout << "\n5:\n";
        std::copy(  files.begin(), files.end()
                ,   stlsoft::ostream_iterator<seq_t::value_type>(std::cout, "\t", "\n"));
    }

    {  // 6. enumerate all .exe files in the windows directory and all dlls in the system directory that begin with 'm', skipping any hidden files

        seq_t  files("C:\\windows", "*.exe;system32/m*.dll", ';', seq_t::files | seq_t::skipHiddenFiles);

        std::cout << "\n6:\n";
        std::copy(  files.begin(), files.end()
                ,   stlsoft::ostream_iterator<seq_t::value_type>(std::cout, "\t", "\n"));
    }

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */
