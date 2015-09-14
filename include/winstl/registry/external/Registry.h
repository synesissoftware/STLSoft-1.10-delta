
/*
 * Created: 1st April 2014
 * Updated: 6th November 2014
 */

#ifndef WINSTL_INCL_WINSTL_REGISTRY_external_h_Registry
#define WINSTL_INCL_WINSTL_REGISTRY_external_h_Registry

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_REGISTRY_external_RegCloseKey
# define WINSTL_REGISTRY_external_RegCloseKey                   STLSOFT_NS_GLOBAL(RegCloseKey)
#endif /* !WINSTL_REGISTRY_external_RegCloseKey */

#ifndef WINSTL_REGISTRY_external_RegConnectRegistryA
# define WINSTL_REGISTRY_external_RegConnectRegistryA           STLSOFT_NS_GLOBAL(RegConnectRegistryA)
#endif /* !WINSTL_REGISTRY_external_RegConnectRegistryA */
#ifndef WINSTL_REGISTRY_external_RegConnectRegistryW
# define WINSTL_REGISTRY_external_RegConnectRegistryW           STLSOFT_NS_GLOBAL(RegConnectRegistryW)
#endif /* !WINSTL_REGISTRY_external_RegConnectRegistryW */
#ifndef WINSTL_REGISTRY_external_RegConnectRegistry
# define WINSTL_REGISTRY_external_RegConnectRegistry            STLSOFT_NS_GLOBAL(RegConnectRegistry)
#endif /* !WINSTL_REGISTRY_external_RegConnectRegistry */

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegCopyTreeA
# define WINSTL_REGISTRY_external_RegCopyTreeA                  STLSOFT_NS_GLOBAL(RegCopyTreeA)
#endif /* !WINSTL_REGISTRY_external_RegCopyTreeA */
#ifndef WINSTL_REGISTRY_external_RegCopyTreeW
# define WINSTL_REGISTRY_external_RegCopyTreeW                  STLSOFT_NS_GLOBAL(RegCopyTreeW)
#endif /* !WINSTL_REGISTRY_external_RegCopyTreeW */
#ifndef WINSTL_REGISTRY_external_RegCopyTree
# define WINSTL_REGISTRY_external_RegCopyTree                   STLSOFT_NS_GLOBAL(RegCopyTree)
#endif /* !WINSTL_REGISTRY_external_RegCopyTree */
#endif

#ifndef WINSTL_REGISTRY_external_RegCreateKeyA
# define WINSTL_REGISTRY_external_RegCreateKeyA                 STLSOFT_NS_GLOBAL(RegCreateKeyA)
#endif /* !WINSTL_REGISTRY_external_RegCreateKeyA */
#ifndef WINSTL_REGISTRY_external_RegCreateKeyW
# define WINSTL_REGISTRY_external_RegCreateKeyW                 STLSOFT_NS_GLOBAL(RegCreateKeyW)
#endif /* !WINSTL_REGISTRY_external_RegCreateKeyW */
#ifndef WINSTL_REGISTRY_external_RegCreateKey
# define WINSTL_REGISTRY_external_RegCreateKey                  STLSOFT_NS_GLOBAL(RegCreateKey)
#endif /* !WINSTL_REGISTRY_external_RegCreateKey */

#ifndef WINSTL_REGISTRY_external_RegCreateKeyExA
# define WINSTL_REGISTRY_external_RegCreateKeyExA               STLSOFT_NS_GLOBAL(RegCreateKeyExA)
#endif /* !WINSTL_REGISTRY_external_RegCreateKeyExA */
#ifndef WINSTL_REGISTRY_external_RegCreateKeyExW
# define WINSTL_REGISTRY_external_RegCreateKeyExW               STLSOFT_NS_GLOBAL(RegCreateKeyExW)
#endif /* !WINSTL_REGISTRY_external_RegCreateKeyExW */
#ifndef WINSTL_REGISTRY_external_RegCreateKeyEx
# define WINSTL_REGISTRY_external_RegCreateKeyEx                STLSOFT_NS_GLOBAL(RegCreateKeyEx)
#endif /* !WINSTL_REGISTRY_external_RegCreateKeyEx */

#ifndef WINSTL_REGISTRY_external_RegCreateKeyTransactedA
# define WINSTL_REGISTRY_external_RegCreateKeyTransactedA       STLSOFT_NS_GLOBAL(RegCreateKeyTransactedA)
#endif /* !WINSTL_REGISTRY_external_RegCreateKeyTransactedA */
#ifndef WINSTL_REGISTRY_external_RegCreateKeyTransactedW
# define WINSTL_REGISTRY_external_RegCreateKeyTransactedW       STLSOFT_NS_GLOBAL(RegCreateKeyTransactedW)
#endif /* !WINSTL_REGISTRY_external_RegCreateKeyTransactedW */
#ifndef WINSTL_REGISTRY_external_RegCreateKeyTransacted
# define WINSTL_REGISTRY_external_RegCreateKeyTransacted        STLSOFT_NS_GLOBAL(RegCreateKeyTransacted)
#endif /* !WINSTL_REGISTRY_external_RegCreateKeyTransacted */

#ifndef WINSTL_REGISTRY_external_RegDeleteKeyA
# define WINSTL_REGISTRY_external_RegDeleteKeyA                 STLSOFT_NS_GLOBAL(RegDeleteKeyA)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyA */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyW
# define WINSTL_REGISTRY_external_RegDeleteKeyW                 STLSOFT_NS_GLOBAL(RegDeleteKeyW)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyW */
#ifndef WINSTL_REGISTRY_external_RegDeleteKey
# define WINSTL_REGISTRY_external_RegDeleteKey                  STLSOFT_NS_GLOBAL(RegDeleteKey)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKey */

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyExA
# define WINSTL_REGISTRY_external_RegDeleteKeyExA               STLSOFT_NS_GLOBAL(RegDeleteKeyExA)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyExA */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyExW
# define WINSTL_REGISTRY_external_RegDeleteKeyExW               STLSOFT_NS_GLOBAL(RegDeleteKeyExW)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyExW */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyEx
# define WINSTL_REGISTRY_external_RegDeleteKeyEx                STLSOFT_NS_GLOBAL(RegDeleteKeyEx)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyEx */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyTransactedA
# define WINSTL_REGISTRY_external_RegDeleteKeyTransactedA       STLSOFT_NS_GLOBAL(RegDeleteKeyTransactedA)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyTransactedA */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyTransactedW
# define WINSTL_REGISTRY_external_RegDeleteKeyTransactedW       STLSOFT_NS_GLOBAL(RegDeleteKeyTransactedW)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyTransactedW */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyTransacted
# define WINSTL_REGISTRY_external_RegDeleteKeyTransacted        STLSOFT_NS_GLOBAL(RegDeleteKeyTransacted)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyTransacted */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyValueA
# define WINSTL_REGISTRY_external_RegDeleteKeyValueA            STLSOFT_NS_GLOBAL(RegDeleteKeyValueA)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyValueA */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyValueW
# define WINSTL_REGISTRY_external_RegDeleteKeyValueW            STLSOFT_NS_GLOBAL(RegDeleteKeyValueW)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyValueW */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyValue
# define WINSTL_REGISTRY_external_RegDeleteKeyValue             STLSOFT_NS_GLOBAL(RegDeleteKeyValue)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyValue */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyTreeA
# define WINSTL_REGISTRY_external_RegDeleteKeyTreeA             STLSOFT_NS_GLOBAL(RegDeleteKeyTreeA)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyTreeA */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyTreeW
# define WINSTL_REGISTRY_external_RegDeleteKeyTreeW             STLSOFT_NS_GLOBAL(RegDeleteKeyTreeW)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyTreeW */
#ifndef WINSTL_REGISTRY_external_RegDeleteKeyTree
# define WINSTL_REGISTRY_external_RegDeleteKeyTree              STLSOFT_NS_GLOBAL(RegDeleteKeyTree)
#endif /* !WINSTL_REGISTRY_external_RegDeleteKeyTree */
#endif

#ifndef WINSTL_REGISTRY_external_RegDeleteValueA
# define WINSTL_REGISTRY_external_RegDeleteValueA               STLSOFT_NS_GLOBAL(RegDeleteValueA)
#endif /* !WINSTL_REGISTRY_external_RegDeleteValueA */
#ifndef WINSTL_REGISTRY_external_RegDeleteValueW
# define WINSTL_REGISTRY_external_RegDeleteValueW               STLSOFT_NS_GLOBAL(RegDeleteValueW)
#endif /* !WINSTL_REGISTRY_external_RegDeleteValueW */
#ifndef WINSTL_REGISTRY_external_RegDeleteValue
# define WINSTL_REGISTRY_external_RegDeleteValue                STLSOFT_NS_GLOBAL(RegDeleteValue)
#endif /* !WINSTL_REGISTRY_external_RegDeleteValue */

#ifndef WINSTL_REGISTRY_external_RegDisablePredefinedCache
# define WINSTL_REGISTRY_external_RegDisablePredefinedCache     STLSOFT_NS_GLOBAL(RegDisablePredefinedCache)
#endif /* !WINSTL_REGISTRY_external_RegDisablePredefinedCache */

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegDisablePredefinedCacheEx
# define WINSTL_REGISTRY_external_RegDisablePredefinedCacheEx   STLSOFT_NS_GLOBAL(RegDisablePredefinedCacheEx)
#endif /* !WINSTL_REGISTRY_external_RegDisablePredefinedCacheEx */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegDisableReflectionKey
# define WINSTL_REGISTRY_external_RegDisableReflectionKey       STLSOFT_NS_GLOBAL(RegDisableReflectionKey)
#endif /* !WINSTL_REGISTRY_external_RegDisableReflectionKey */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegEnableReflectionKey
# define WINSTL_REGISTRY_external_RegEnableReflectionKey        STLSOFT_NS_GLOBAL(RegEnableReflectionKey)
#endif /* !WINSTL_REGISTRY_external_RegEnableReflectionKey */
#endif

#ifndef WINSTL_REGISTRY_external_RegEnumKeyA
# define WINSTL_REGISTRY_external_RegEnumKeyA                   STLSOFT_NS_GLOBAL(RegEnumKeyA)
#endif /* !WINSTL_REGISTRY_external_RegEnumKeyA */
#ifndef WINSTL_REGISTRY_external_RegEnumKeyW
# define WINSTL_REGISTRY_external_RegEnumKeyW                   STLSOFT_NS_GLOBAL(RegEnumKeyW)
#endif /* !WINSTL_REGISTRY_external_RegEnumKeyW */
#ifndef WINSTL_REGISTRY_external_RegEnumKey
# define WINSTL_REGISTRY_external_RegEnumKey                    STLSOFT_NS_GLOBAL(RegEnumKey)
#endif /* !WINSTL_REGISTRY_external_RegEnumKey */

#ifndef WINSTL_REGISTRY_external_RegEnumKeyExA
# define WINSTL_REGISTRY_external_RegEnumKeyExA                 STLSOFT_NS_GLOBAL(RegEnumKeyExA)
#endif /* !WINSTL_REGISTRY_external_RegEnumKeyExA */
#ifndef WINSTL_REGISTRY_external_RegEnumKeyExW
# define WINSTL_REGISTRY_external_RegEnumKeyExW                 STLSOFT_NS_GLOBAL(RegEnumKeyExW)
#endif /* !WINSTL_REGISTRY_external_RegEnumKeyExW */
#ifndef WINSTL_REGISTRY_external_RegEnumKeyEx
# define WINSTL_REGISTRY_external_RegEnumKeyEx                  STLSOFT_NS_GLOBAL(RegEnumKeyEx)
#endif /* !WINSTL_REGISTRY_external_RegEnumKeyEx */

#ifndef WINSTL_REGISTRY_external_RegEnumValueA
# define WINSTL_REGISTRY_external_RegEnumValueA                 STLSOFT_NS_GLOBAL(RegEnumValueA)
#endif /* !WINSTL_REGISTRY_external_RegEnumValueA */
#ifndef WINSTL_REGISTRY_external_RegEnumValueW
# define WINSTL_REGISTRY_external_RegEnumValueW                 STLSOFT_NS_GLOBAL(RegEnumValueW)
#endif /* !WINSTL_REGISTRY_external_RegEnumValueW */
#ifndef WINSTL_REGISTRY_external_RegEnumValue
# define WINSTL_REGISTRY_external_RegEnumValue                  STLSOFT_NS_GLOBAL(RegEnumValue)
#endif /* !WINSTL_REGISTRY_external_RegEnumValue */

#ifndef WINSTL_REGISTRY_external_RegFlushKey
# define WINSTL_REGISTRY_external_RegFlushKey                   STLSOFT_NS_GLOBAL(RegFlushKey)
#endif /* !WINSTL_REGISTRY_external_RegFlushKey */

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegGetValueA
# define WINSTL_REGISTRY_external_RegGetValueA                  STLSOFT_NS_GLOBAL(RegGetValueA)
#endif /* !WINSTL_REGISTRY_external_RegGetValueA */
#ifndef WINSTL_REGISTRY_external_RegGetValueW
# define WINSTL_REGISTRY_external_RegGetValueW                  STLSOFT_NS_GLOBAL(RegGetValueW)
#endif /* !WINSTL_REGISTRY_external_RegGetValueW */
#ifndef WINSTL_REGISTRY_external_RegGetValue
# define WINSTL_REGISTRY_external_RegGetValue                   STLSOFT_NS_GLOBAL(RegGetValue)
#endif /* !WINSTL_REGISTRY_external_RegGetValue */
#endif

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegLoadAppKeyA
# define WINSTL_REGISTRY_external_RegLoadAppKeyA                STLSOFT_NS_GLOBAL(RegLoadAppKeyA)
#endif /* !WINSTL_REGISTRY_external_RegLoadAppKeyA */
#ifndef WINSTL_REGISTRY_external_RegLoadAppKeyW
# define WINSTL_REGISTRY_external_RegLoadAppKeyW                STLSOFT_NS_GLOBAL(RegLoadAppKeyW)
#endif /* !WINSTL_REGISTRY_external_RegLoadAppKeyW */
#ifndef WINSTL_REGISTRY_external_RegLoadAppKey
# define WINSTL_REGISTRY_external_RegLoadAppKey                 STLSOFT_NS_GLOBAL(RegLoadAppKey)
#endif /* !WINSTL_REGISTRY_external_RegLoadAppKey */
#endif

#ifndef WINSTL_REGISTRY_external_RegLoadKeyA
# define WINSTL_REGISTRY_external_RegLoadKeyA                   STLSOFT_NS_GLOBAL(RegLoadKeyA)
#endif /* !WINSTL_REGISTRY_external_RegLoadKeyA */
#ifndef WINSTL_REGISTRY_external_RegLoadKeyW
# define WINSTL_REGISTRY_external_RegLoadKeyW                   STLSOFT_NS_GLOBAL(RegLoadKeyW)
#endif /* !WINSTL_REGISTRY_external_RegLoadKeyW */
#ifndef WINSTL_REGISTRY_external_RegLoadKey
# define WINSTL_REGISTRY_external_RegLoadKey                    STLSOFT_NS_GLOBAL(RegLoadKey)
#endif /* !WINSTL_REGISTRY_external_RegLoadKey */

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegLoadMUIStringA
# define WINSTL_REGISTRY_external_RegLoadMUIStringA             STLSOFT_NS_GLOBAL(RegLoadMUIStringA)
#endif /* !WINSTL_REGISTRY_external_RegLoadMUIStringA */
#ifndef WINSTL_REGISTRY_external_RegLoadMUIStringW
# define WINSTL_REGISTRY_external_RegLoadMUIStringW             STLSOFT_NS_GLOBAL(RegLoadMUIStringW)
#endif /* !WINSTL_REGISTRY_external_RegLoadMUIStringW */
#ifndef WINSTL_REGISTRY_external_RegLoadMUIString
# define WINSTL_REGISTRY_external_RegLoadMUIString              STLSOFT_NS_GLOBAL(RegLoadMUIString)
#endif /* !WINSTL_REGISTRY_external_RegLoadMUIString */
#endif

#ifndef WINSTL_REGISTRY_external_RegNotifyChangeKeyValue
# define WINSTL_REGISTRY_external_RegNotifyChangeKeyValue       STLSOFT_NS_GLOBAL(RegNotifyChangeKeyValue)
#endif /* !WINSTL_REGISTRY_external_RegNotifyChangeKeyValue */

#ifndef WINSTL_REGISTRY_external_RegOpenCurrentUser
# define WINSTL_REGISTRY_external_RegOpenCurrentUser            STLSOFT_NS_GLOBAL(RegOpenCurrentUser)
#endif /* !WINSTL_REGISTRY_external_RegOpenCurrentUser */

#ifndef WINSTL_REGISTRY_external_RegOpenKeyA
# define WINSTL_REGISTRY_external_RegOpenKeyA                   STLSOFT_NS_GLOBAL(RegOpenKeyA)
#endif /* !WINSTL_REGISTRY_external_RegOpenKeyA */
#ifndef WINSTL_REGISTRY_external_RegOpenKeyW
# define WINSTL_REGISTRY_external_RegOpenKeyW                   STLSOFT_NS_GLOBAL(RegOpenKeyW)
#endif /* !WINSTL_REGISTRY_external_RegOpenKeyW */
#ifndef WINSTL_REGISTRY_external_RegOpenKey
# define WINSTL_REGISTRY_external_RegOpenKey                    STLSOFT_NS_GLOBAL(RegOpenKey)
#endif /* !WINSTL_REGISTRY_external_RegOpenKey */

#ifndef WINSTL_REGISTRY_external_RegOpenKeyExA
# define WINSTL_REGISTRY_external_RegOpenKeyExA                 STLSOFT_NS_GLOBAL(RegOpenKeyExA)
#endif /* !WINSTL_REGISTRY_external_RegOpenKeyExA */
#ifndef WINSTL_REGISTRY_external_RegOpenKeyExW
# define WINSTL_REGISTRY_external_RegOpenKeyExW                 STLSOFT_NS_GLOBAL(RegOpenKeyExW)
#endif /* !WINSTL_REGISTRY_external_RegOpenKeyExW */
#ifndef WINSTL_REGISTRY_external_RegOpenKeyEx
# define WINSTL_REGISTRY_external_RegOpenKeyEx                  STLSOFT_NS_GLOBAL(RegOpenKeyEx)
#endif /* !WINSTL_REGISTRY_external_RegOpenKeyEx */

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegOpenKeyTransactedA
# define WINSTL_REGISTRY_external_RegOpenKeyTransactedA         STLSOFT_NS_GLOBAL(RegOpenKeyTransactedA)
#endif /* !WINSTL_REGISTRY_external_RegOpenKeyTransactedA */
#ifndef WINSTL_REGISTRY_external_RegOpenKeyTransactedW
# define WINSTL_REGISTRY_external_RegOpenKeyTransactedW         STLSOFT_NS_GLOBAL(RegOpenKeyTransactedW)
#endif /* !WINSTL_REGISTRY_external_RegOpenKeyTransactedW */
#ifndef WINSTL_REGISTRY_external_RegOpenKeyTransacted
# define WINSTL_REGISTRY_external_RegOpenKeyTransacted          STLSOFT_NS_GLOBAL(RegOpenKeyTransacted)
#endif /* !WINSTL_REGISTRY_external_RegOpenKeyTransacted */
#endif

#ifndef WINSTL_REGISTRY_external_RegOpenUserClassesRoot
# define WINSTL_REGISTRY_external_RegOpenUserClassesRoot        STLSOFT_NS_GLOBAL(RegOpenUserClassesRoot)
#endif /* !WINSTL_REGISTRY_external_RegOpenUserClassesRoot */

#ifndef WINSTL_REGISTRY_external_RegOverridePredefKey
# define WINSTL_REGISTRY_external_RegOverridePredefKey          STLSOFT_NS_GLOBAL(RegOverridePredefKey)
#endif /* !WINSTL_REGISTRY_external_RegOverridePredefKey */

#ifndef WINSTL_REGISTRY_external_RegQueryInfoKeyA
# define WINSTL_REGISTRY_external_RegQueryInfoKeyA              STLSOFT_NS_GLOBAL(RegQueryInfoKeyA)
#endif /* !WINSTL_REGISTRY_external_RegQueryInfoKeyA */
#ifndef WINSTL_REGISTRY_external_RegQueryInfoKeyW
# define WINSTL_REGISTRY_external_RegQueryInfoKeyW              STLSOFT_NS_GLOBAL(RegQueryInfoKeyW)
#endif /* !WINSTL_REGISTRY_external_RegQueryInfoKeyW */
#ifndef WINSTL_REGISTRY_external_RegQueryInfoKey
# define WINSTL_REGISTRY_external_RegQueryInfoKey               STLSOFT_NS_GLOBAL(RegQueryInfoKey)
#endif /* !WINSTL_REGISTRY_external_RegQueryInfoKey */

#ifndef WINSTL_REGISTRY_external_RegQueryMultipleValuesA
# define WINSTL_REGISTRY_external_RegQueryMultipleValuesA       STLSOFT_NS_GLOBAL(RegQueryMultipleValuesA)
#endif /* !WINSTL_REGISTRY_external_RegQueryMultipleValuesA */
#ifndef WINSTL_REGISTRY_external_RegQueryMultipleValuesW
# define WINSTL_REGISTRY_external_RegQueryMultipleValuesW       STLSOFT_NS_GLOBAL(RegQueryMultipleValuesW)
#endif /* !WINSTL_REGISTRY_external_RegQueryMultipleValuesW */
#ifndef WINSTL_REGISTRY_external_RegQueryMultipleValues
# define WINSTL_REGISTRY_external_RegQueryMultipleValues        STLSOFT_NS_GLOBAL(RegQueryMultipleValues)
#endif /* !WINSTL_REGISTRY_external_RegQueryMultipleValues */

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegQueryReflectionKey
# define WINSTL_REGISTRY_external_RegQueryReflectionKey         STLSOFT_NS_GLOBAL(RegQueryReflectionKey)
#endif /* !WINSTL_REGISTRY_external_RegQueryReflectionKey */
#endif

#ifndef WINSTL_REGISTRY_external_RegQueryValueA
# define WINSTL_REGISTRY_external_RegQueryValueA                STLSOFT_NS_GLOBAL(RegQueryValueA)
#endif /* !WINSTL_REGISTRY_external_RegQueryValueA */
#ifndef WINSTL_REGISTRY_external_RegQueryValueW
# define WINSTL_REGISTRY_external_RegQueryValueW                STLSOFT_NS_GLOBAL(RegQueryValueW)
#endif /* !WINSTL_REGISTRY_external_RegQueryValueW */
#ifndef WINSTL_REGISTRY_external_RegQueryValue
# define WINSTL_REGISTRY_external_RegQueryValue                 STLSOFT_NS_GLOBAL(RegQueryValue)
#endif /* !WINSTL_REGISTRY_external_RegQueryValue */

#ifndef WINSTL_REGISTRY_external_RegQueryValueExA
# define WINSTL_REGISTRY_external_RegQueryValueExA              STLSOFT_NS_GLOBAL(RegQueryValueExA)
#endif /* !WINSTL_REGISTRY_external_RegQueryValueExA */
#ifndef WINSTL_REGISTRY_external_RegQueryValueExW
# define WINSTL_REGISTRY_external_RegQueryValueExW              STLSOFT_NS_GLOBAL(RegQueryValueExW)
#endif /* !WINSTL_REGISTRY_external_RegQueryValueExW */
#ifndef WINSTL_REGISTRY_external_RegQueryValueEx
# define WINSTL_REGISTRY_external_RegQueryValueEx               STLSOFT_NS_GLOBAL(RegQueryValueEx)
#endif /* !WINSTL_REGISTRY_external_RegQueryValueEx */

#ifndef WINSTL_REGISTRY_external_RegReplaceKeyA
# define WINSTL_REGISTRY_external_RegReplaceKeyA                STLSOFT_NS_GLOBAL(RegReplaceKeyA)
#endif /* !WINSTL_REGISTRY_external_RegReplaceKeyA */
#ifndef WINSTL_REGISTRY_external_RegReplaceKeyW
# define WINSTL_REGISTRY_external_RegReplaceKeyW                STLSOFT_NS_GLOBAL(RegReplaceKeyW)
#endif /* !WINSTL_REGISTRY_external_RegReplaceKeyW */
#ifndef WINSTL_REGISTRY_external_RegReplaceKey
# define WINSTL_REGISTRY_external_RegReplaceKey                 STLSOFT_NS_GLOBAL(RegReplaceKey)
#endif /* !WINSTL_REGISTRY_external_RegReplaceKey */

#ifndef WINSTL_REGISTRY_external_RegRestoreKeyA
# define WINSTL_REGISTRY_external_RegRestoreKeyA                STLSOFT_NS_GLOBAL(RegRestoreKeyA)
#endif /* !WINSTL_REGISTRY_external_RegRestoreKeyA */
#ifndef WINSTL_REGISTRY_external_RegRestoreKeyW
# define WINSTL_REGISTRY_external_RegRestoreKeyW                STLSOFT_NS_GLOBAL(RegRestoreKeyW)
#endif /* !WINSTL_REGISTRY_external_RegRestoreKeyW */
#ifndef WINSTL_REGISTRY_external_RegRestoreKey
# define WINSTL_REGISTRY_external_RegRestoreKey                 STLSOFT_NS_GLOBAL(RegRestoreKey)
#endif /* !WINSTL_REGISTRY_external_RegRestoreKey */

#ifndef WINSTL_REGISTRY_external_RegSaveKeyA
# define WINSTL_REGISTRY_external_RegSaveKeyA                   STLSOFT_NS_GLOBAL(RegSaveKeyA)
#endif /* !WINSTL_REGISTRY_external_RegSaveKeyA */
#ifndef WINSTL_REGISTRY_external_RegSaveKeyW
# define WINSTL_REGISTRY_external_RegSaveKeyW                   STLSOFT_NS_GLOBAL(RegSaveKeyW)
#endif /* !WINSTL_REGISTRY_external_RegSaveKeyW */
#ifndef WINSTL_REGISTRY_external_RegSaveKey
# define WINSTL_REGISTRY_external_RegSaveKey                    STLSOFT_NS_GLOBAL(RegSaveKey)
#endif /* !WINSTL_REGISTRY_external_RegSaveKey */

#ifndef WINSTL_REGISTRY_external_RegSaveKeyExA
# define WINSTL_REGISTRY_external_RegSaveKeyExA                 STLSOFT_NS_GLOBAL(RegSaveKeyExA)
#endif /* !WINSTL_REGISTRY_external_RegSaveKeyExA */
#ifndef WINSTL_REGISTRY_external_RegSaveKeyExW
# define WINSTL_REGISTRY_external_RegSaveKeyExW                 STLSOFT_NS_GLOBAL(RegSaveKeyExW)
#endif /* !WINSTL_REGISTRY_external_RegSaveKeyExW */
#ifndef WINSTL_REGISTRY_external_RegSaveKeyEx
# define WINSTL_REGISTRY_external_RegSaveKeyEx                  STLSOFT_NS_GLOBAL(RegSaveKeyEx)
#endif /* !WINSTL_REGISTRY_external_RegSaveKeyEx */

#if WINSTL_WIN32_WINNT >= 0x0600
#ifndef WINSTL_REGISTRY_external_RegSetKeyValueA
# define WINSTL_REGISTRY_external_RegSetKeyValueA               STLSOFT_NS_GLOBAL(RegSetKeyValueA)
#endif /* !WINSTL_REGISTRY_external_RegSetKeyValueA */
#ifndef WINSTL_REGISTRY_external_RegSetKeyValueW
# define WINSTL_REGISTRY_external_RegSetKeyValueW               STLSOFT_NS_GLOBAL(RegSetKeyValueW)
#endif /* !WINSTL_REGISTRY_external_RegSetKeyValueW */
#ifndef WINSTL_REGISTRY_external_RegSetKeyValue
# define WINSTL_REGISTRY_external_RegSetKeyValue                STLSOFT_NS_GLOBAL(RegSetKeyValue)
#endif /* !WINSTL_REGISTRY_external_RegSetKeyValue */
#endif

#ifndef WINSTL_REGISTRY_external_RegSetValueA
# define WINSTL_REGISTRY_external_RegSetValueA                  STLSOFT_NS_GLOBAL(RegSetValueA)
#endif /* !WINSTL_REGISTRY_external_RegSetValueA */
#ifndef WINSTL_REGISTRY_external_RegSetValueW
# define WINSTL_REGISTRY_external_RegSetValueW                  STLSOFT_NS_GLOBAL(RegSetValueW)
#endif /* !WINSTL_REGISTRY_external_RegSetValueW */
#ifndef WINSTL_REGISTRY_external_RegSetValue
# define WINSTL_REGISTRY_external_RegSetValue                   STLSOFT_NS_GLOBAL(RegSetValue)
#endif /* !WINSTL_REGISTRY_external_RegSetValue */

#ifndef WINSTL_REGISTRY_external_RegSetValueExA
# define WINSTL_REGISTRY_external_RegSetValueExA                STLSOFT_NS_GLOBAL(RegSetValueExA)
#endif /* !WINSTL_REGISTRY_external_RegSetValueExA */
#ifndef WINSTL_REGISTRY_external_RegSetValueExW
# define WINSTL_REGISTRY_external_RegSetValueExW                STLSOFT_NS_GLOBAL(RegSetValueExW)
#endif /* !WINSTL_REGISTRY_external_RegSetValueExW */
#ifndef WINSTL_REGISTRY_external_RegSetValueEx
# define WINSTL_REGISTRY_external_RegSetValueEx                 STLSOFT_NS_GLOBAL(RegSetValueEx)
#endif /* !WINSTL_REGISTRY_external_RegSetValueEx */

#ifndef WINSTL_REGISTRY_external_RegUnloadKeyA
# define WINSTL_REGISTRY_external_RegUnloadKeyA                 STLSOFT_NS_GLOBAL(RegUnloadKeyA)
#endif /* !WINSTL_REGISTRY_external_RegUnloadKeyA */
#ifndef WINSTL_REGISTRY_external_RegUnloadKeyW
# define WINSTL_REGISTRY_external_RegUnloadKeyW                 STLSOFT_NS_GLOBAL(RegUnloadKeyW)
#endif /* !WINSTL_REGISTRY_external_RegUnloadKeyW */
#ifndef WINSTL_REGISTRY_external_RegUnloadKey
# define WINSTL_REGISTRY_external_RegUnloadKey                  STLSOFT_NS_GLOBAL(RegUnloadKey)
#endif /* !WINSTL_REGISTRY_external_RegUnloadKey */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_REGISTRY_external_h_Registry */

/* ///////////////////////////// end of file //////////////////////////// */
