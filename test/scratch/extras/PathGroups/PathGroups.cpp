
/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft.h>
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
# pragma warning(disable : 4996)
#endif

#include <../extras/path_groups/path_groups.hpp>

#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/iterators/format_iterator.hpp>

#include <pantheios/pan.hpp>
#include <pantheios/inserters/args.hpp>

#include <stlsoft/smartptr/shared_ptr.hpp>
#include <stlsoft/string/string_tokeniser.hpp>
#include <platformstl/filesystem/file_lines.hpp>

#include <iostream>
#include <map>
#include <vector>

PANTHEIOS_EXTERN_C PAN_CHAR_T const PANTHEIOS_FE_PROCESS_IDENTITY[] = PANTHEIOS_LITERAL_STRING("PathGroups");

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

#include <platformstl/filesystem/file_lines.hpp>
#include <stlsoft/iterator/transformer.hpp>
#include <stlsoft/memory/allocator_selector.hpp>
#include <stlsoft/string/char_traits.hpp>
#include <stlsoft/string/simple_string.hpp>
#include <stlsoft/string/string_tokeniser.hpp>
#include <stlsoft/string/trim_functions.hpp>
#include <stlsoft/smartptr/shared_ptr.hpp>

#include <map>
#include <vector>

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char** argv)
{
    pan::log_DEBUG("main(", pan::args(argc, argv, pan::args::arg0FileOnly), ")");

    if(2 != argc)
    {
        ff::writeln(
            std::cerr
        ,	"USAGE: PathGroups <file>"
        );

        return EXIT_FAILURE;
    }
    else
    {
		stlsoft::extras::file_groups groups(argv[1]);

        ff::writeln(std::cout, "by items:");
        { for(stlsoft::extras::file_groups::item_const_iterator i = groups.begin_item(); i != groups.end_item(); ++i)
        {
            stlsoft::extras::file_groups::group_type group;

            groups.lookup((*i).first, group);

            if((*i).first == group.front())
            {
                ff::fmtln(
                    std::cout
                ,	"\t{0} items"
                ,	group.size()
                );
                std::copy(
                    group.begin()
                ,	group.end()
                ,	ff::format_iterator(std::cout, "\t\t{0}\n")
                );
            }
        }}

        ff::writeln(std::cout, "by groups:");
        { for(stlsoft::extras::file_groups::group_const_iterator i = groups.begin_group(); i != groups.end_group(); ++i)
        {
            stlsoft::extras::file_groups::group_type const& group = *i;

            ff::fmtln(
                std::cout
            ,	"\t{0} items"
            ,	group.size()
            );
            std::copy(
                group.begin()
            ,	group.end()
            ,	ff::format_iterator(std::cout, "\t\t{0}\n")
            );
        }}

        return EXIT_SUCCESS;
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
