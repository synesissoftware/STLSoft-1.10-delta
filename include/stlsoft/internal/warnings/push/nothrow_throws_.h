/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/internal/warnings/push/nothrow_throws_.h
 *
 * Purpose:     Pushes warning suppression for "throwing an exception from a
 *              function marked nothrow()".
 *
 * Created:     18th November 2008
 * Updated:     13th January 2011
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2008-2011, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Refer to stlsoft/stlsoft.h for license conditions
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error Requires stlsoft/stlsoft.h
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifdef STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_NOTHROW_THROWS_
# error stlsoft/internal/warnings/push/nothrow_throws_.h already included without matching pop
#else /* ? STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_NOTHROW_THROWS_ */
# define STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_NOTHROW_THROWS_
#endif /* STLSOFT_INCL_STLSOFT_INTERNAL_WARNINGS_PUSH_H_NOTHROW_THROWS_ */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(push)
# pragma warning(disable: 4297)
#endif /* VC++ 8+ */

/* ///////////////////////////// end of file //////////////////////////// */