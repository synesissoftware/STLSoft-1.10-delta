
/*
 *
 * Updated: 14th September 2014
 */

#ifndef WINSTL_INCL_WINSTL_REGISTRY_util_HPP_key_functions
#define WINSTL_INCL_WINSTL_REGISTRY_util_HPP_key_functions

# include <winstl/registry/util/key_functions.h>

namespace stlsoft
{
namespace winstl_project
{
	using ::winstl_C_registry_key_open_a;

inline
LONG
key_open(
	HKEY		hkeyRoot
,	LPCSTR		subkeyName
,   REGSAM      desiredAccessRights
,	HKEY*		phkeyResult
)
{
	STLSOFT_ASSERT(NULL != phkeyResult);

	return ::winstl::winstl_C_registry_key_open_a(hkeyRoot, subkeyName, desiredAccessRights, phkeyResult);
}

inline
LONG
key_open(
	HKEY		hkeyRoot
,	LPCSTR		subkeyName
,	HKEY*		phkeyResult
)
{
	STLSOFT_ASSERT(NULL != phkeyResult);

	return ::winstl::winstl_C_registry_key_open_a(hkeyRoot, subkeyName, KEY_ALL_ACCESS, phkeyResult);
}


} /* namespace winstl_project */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_REGISTRY_util_HPP_key_functions */

/* ///////////////////////////// end of file //////////////////////////// */
