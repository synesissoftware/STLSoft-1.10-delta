
#include <platformstl/platformstl.h>
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <unixstl/system/temporary_directory.hpp>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <winstl/system/temporary_directory.hpp>
#else
# error Platform not discriminated
#endif

namespace stlsoft
{
namespace platformstl_project
{

#if defined(PLATFORMSTL_OS_IS_UNIX)

	using unixstl::temporary_directory;

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

	using winstl::temporary_directory;

#else
# error Platform not discriminated
#endif

} /* namespace platformstl_project */
} /* namespace stlsoft */

