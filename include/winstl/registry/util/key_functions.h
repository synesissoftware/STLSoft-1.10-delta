
/*
 *
 * Updated: 6th November 2014
 */

#ifndef WINSTL_INCL_WINSTL_REGISTRY_util_h_key_functions
#define WINSTL_INCL_WINSTL_REGISTRY_util_h_key_functions

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#ifndef WINSTL_INCL_WINSTL_REGISTRY_external_h_Registry
# include <winstl/registry/external/registry.h>
#endif /* !WINSTL_INCL_WINSTL_REGISTRY_external_h_Registry */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

STLSOFT_INLINE
LONG
winstl_C_registry_key_create_a(
    HKEY        rootKey
,   LPCSTR      keyPath
,   REGSAM      desiredAccessRights
,   HKEY*       createdOrOpenedKey
,   LPDWORD     disposition /* = NULL */
)
{
    WINSTL_ASSERT(NULL != rootKey);
    WINSTL_ASSERT(NULL != createdOrOpenedKey);

    return WINSTL_REGISTRY_external_RegCreateKeyExA(rootKey, keyPath, 0, NULL, REG_OPTION_NON_VOLATILE, desiredAccessRights, NULL, createdOrOpenedKey, disposition);
}

STLSOFT_INLINE
LONG
winstl_C_registry_key_open_a(
    HKEY        rootKey
,   LPCSTR      keyPath
,   REGSAM      desiredAccessRights
,   HKEY*       createdOrOpenedKey
)
{
    WINSTL_ASSERT(NULL != rootKey);
    WINSTL_ASSERT(NULL != createdOrOpenedKey);

    return WINSTL_REGISTRY_external_RegOpenKeyExA(rootKey, keyPath, 0, desiredAccessRights, createdOrOpenedKey);
}

STLSOFT_INLINE
LONG
winstl_C_registry_key_open_w(
    HKEY        rootKey
,   LPCWSTR     keyPath
,   REGSAM      desiredAccessRights
,   HKEY*       createdOrOpenedKey
)
{
    WINSTL_ASSERT(NULL != rootKey);
    WINSTL_ASSERT(NULL != createdOrOpenedKey);

    return WINSTL_REGISTRY_external_RegOpenKeyExW(rootKey, keyPath, 0, desiredAccessRights, createdOrOpenedKey);
}

STLSOFT_INLINE
LONG
winstl_C_registry_key_close(
    HKEY        rootKey
)
{
    return WINSTL_REGISTRY_external_RegCloseKey(rootKey);
}

STLSOFT_INLINE
LONG
winstl_C_registry_key_count_keys(
    HKEY        rootKey
,   DWORD*      count
)
{
    WINSTL_ASSERT(NULL != count);

    return WINSTL_REGISTRY_external_RegQueryInfoKey(rootKey, NULL, NULL, NULL, count, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

STLSOFT_INLINE
LONG
winstl_C_registry_key_count_values(
    HKEY        rootKey
,   DWORD*      count
)
{
    WINSTL_ASSERT(NULL != count);

    return WINSTL_REGISTRY_external_RegQueryInfoKey(rootKey, NULL, NULL, NULL, NULL, NULL, NULL, count, NULL, NULL, NULL, NULL);
}

STLSOFT_INLINE
LONG
winstl_C_registry_key_delete_a(
    HKEY        rootKey
,   LPCSTR      keyPath
)
{
    return WINSTL_REGISTRY_external_RegDeleteKeyA(rootKey, keyPath);
}

STLSOFT_INLINE
LONG
winstl_C_registry_key_delete_recursively_a(
    HKEY        rootKey
,   LPCSTR      keyPath
,   LPDWORD     numSubkeysDeleted /* = NULL */
)
{
    /* Algorithm:
     *
     * 1. Iterate through sub-keys, and invoke on each
     * 2. Delete the named sub-key (if specified)
     */

    HKEY    subKey;
    LONG    result  =   WINSTL_REGISTRY_external_RegOpenKeyExA(rootKey, keyPath, 0, KEY_READ, &subKey);

    if(ERROR_SUCCESS == result)
    {
        for(; ERROR_SUCCESS == result; )
        {
            CHAR    name[255 + 1]; /* 255 limit is given in MSDN */
            DWORD   cchName = STLSOFT_NUM_ELEMENTS(name);

            result = WINSTL_REGISTRY_external_RegEnumKeyExA(subKey, 0, name, &cchName, NULL, NULL, NULL, NULL);

            if(ERROR_SUCCESS != result)
            {
                if(ERROR_NO_MORE_ITEMS == result)
                {
                    /* The enumeration is complete, so break main
                     * loop, but indicate success.
                     */
                    result = ERROR_SUCCESS;
                    break;
                }
            }
            else
            {
                /* Recursively delete this child. */
                result = winstl_C_registry_key_delete_recursively_a(subKey, name, numSubkeysDeleted);
            }
        }

        WINSTL_REGISTRY_external_RegCloseKey(subKey);
    }

    if( ERROR_SUCCESS == result &&
        NULL != keyPath &&
        '\0' != keyPath[0])
    {
        result = WINSTL_REGISTRY_external_RegDeleteKeyA(rootKey, keyPath);
    }

    return result;
}

#ifdef UNICODE
# define winstl_C_registry_key_create               winstl_C_registry_key_create_w
# define winstl_C_registry_key_delete               winstl_C_registry_key_delete_w
# define winstl_C_registry_key_delete_recursively   winstl_C_registry_key_delete_recursively_w
# define winstl_C_registry_key_open                 winstl_C_registry_key_open_w
#else /* ? UNICODE */
# define winstl_C_registry_key_create               winstl_C_registry_key_create_a
# define winstl_C_registry_key_delete               winstl_C_registry_key_delete_a
# define winstl_C_registry_key_delete_recursively   winstl_C_registry_key_delete_recursively_a
# define winstl_C_registry_key_open                 winstl_C_registry_key_open_a
#endif /* UNICODE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_REGISTRY_util_h_key_functions */

/* ///////////////////////////// end of file //////////////////////////// */
