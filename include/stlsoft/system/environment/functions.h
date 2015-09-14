
/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/internal/safestr.h>

/* Standard C Header Files */
#include <errno.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * C Functions
 */

STLSOFT_INLINE int stlsoft_C_environment_variable_exists(
    char const* name
)
{
#if defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) && \
    defined(STLSOFT_COMPILER_IS_MSVC)

    char    buff[1];
    size_t  n;
    errno_t e = STLSOFT_NS_GLOBAL(getenv_s)(&n, &buff[0], STLSOFT_NUM_ELEMENTS(buff), name);

    if(0 == e)
    {
        if('\0' == buff[0])
        {
            // variable doesn't exist
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(ERANGE == e)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

#else

    return NULL != STLSOFT_NS_GLOBAL(getenv)(name);

#endif
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ Functions
 */

#ifdef __cplusplus

inline
int
environment_variable_exists(
    char const* name
)
{
    return stlsoft_C_environment_variable_exists(name);
}

#endif /* __cplusplus */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */


/* ///////////////////////////// end of file //////////////////////////// */
