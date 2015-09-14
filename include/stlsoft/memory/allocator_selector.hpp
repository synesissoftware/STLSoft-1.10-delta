
#include <stlsoft/stlsoft.h>

#ifdef STLSOFT_NO_PRE_1_10_BAGGAGE
# error This file stlsoft/memory/allocator_selector.hpp is obsolete as of STLSoft version 1.12; instead include stlsoft/memory/util/allocator_selector.hpp
#else /* ? STLSOFT_NO_PRE_1_10_BAGGAGE */
# include <stlsoft/memory/util/allocator_selector.hpp>
# if (   defined(_STLSOFT_VER) && \
         _STLSOFT_VER >= 0x010c0000) || \
     (   defined(STLSOFT_VER) && \
         STLSOFT_VER >= 0x010c0000)

#  if defined(STLSOFT_PPF_pragma_message_SUPPORT)
#   pragma message(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) "): " "This file stlsoft/memory/allocator_selector.hpp is obsolete as of STLSoft version 1.12; instead include stlsoft/memory/util/allocator_selector.hpp")
#  endif
# endif
#endif /* STLSOFT_NO_PRE_1_10_BAGGAGE */

