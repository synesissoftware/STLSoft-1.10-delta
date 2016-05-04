
/*
 *
 * Updated: 9th October 2015
 */

#ifndef WINSTL_INCL_WINSTL_REGISTRY_util_h_value_functions
#define WINSTL_INCL_WINSTL_REGISTRY_util_h_value_functions

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

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_H_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.h>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_H_AUTO_BUFFER */

#ifndef STLSOFT_INCL_H_ERRNO
# define STLSOFT_INCL_H_ERRNO
# include <errno.h>
#endif /* !STLSOFT_INCL_H_ERRNO */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#ifdef ERROR_DATATYPE_MISMATCH
# define WINSTL_REGISTRY_UTIL_VALUE_FUNCTIONS_ERROR_DATATYPE_MISMATCH_      ERROR_DATATYPE_MISMATCH
#else
# define WINSTL_REGISTRY_UTIL_VALUE_FUNCTIONS_ERROR_DATATYPE_MISMATCH_      (1629L)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

STLSOFT_INLINE
LONG
winstl_C_standard_errno_to_Windows_LastErrorCode(
    int e
)
{
    switch(e)
    {
        case    ENOMEM:
            return ERROR_OUTOFMEMORY;
        default:
            return ~ERROR_SUCCESS;
    }
}

STLSOFT_INLINE
LONG
winstl_C_registry_value_read_and_expand_string_a_(
    HKEY        key
,   LPCSTR      name
,   LPSTR       value
,   LPDWORD     pcchValue
)
{
#ifdef STLSOFT_DEBUG
    STLSOFT_C_AUTO_BUFFER_DECLARE(CHAR, 8, buff);
    STLSOFT_C_AUTO_BUFFER_DECLARE(CHAR, 32, buff2);
#else
    STLSOFT_C_AUTO_BUFFER_DECLARE(CHAR, 200, buff);
    STLSOFT_C_AUTO_BUFFER_DECLARE(CHAR, 800, buff2);
#endif
    LONG    result = ERROR_SUCCESS;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != pcchValue);

    STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL(buff);
    STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL(buff2);

    for(;;)
    {
        DWORD   cbValue;
        DWORD   type;
        int     r;

        cbValue = STLSOFT_STATIC_CAST(DWORD, buff.size / buff.elementSize);

        result = WINSTL_REGISTRY_external_RegQueryValueExA(key, name, NULL, &type, STLSOFT_REINTERPRET_CAST(LPBYTE, buff.ptr), &cbValue);

        if(ERROR_MORE_DATA == result)
        {
            /* add 1, because possible to store data without terminating nul character */
            size_t const nextSize = (cbValue / sizeof(CHAR)) + 1;

            if(0 != (r = STLSOFT_C_AUTO_BUFFER_RESIZE(buff, nextSize)))
            {
                result = winstl_C_standard_errno_to_Windows_LastErrorCode(r);

                goto do_return;
            }
        }
        else
        if(ERROR_SUCCESS == result)
        {
            size_t  cch;
            LPCSTR  s;
/* TODO: verify type - it might have changed between caller and this */
            if(NULL == STLSOFT_NS_GLOBAL(strchr)(buff.ptr, '%'))
            {
                s   =   buff.ptr;
                cch =   cbValue / sizeof(CHAR);

                if('\0' == s[cch - 1])
                {
                    --cch;
                }
            }
            else
            {
                CHAR    dummy;
                DWORD   exr = STLSOFT_NS_GLOBAL(ExpandEnvironmentStringsA)(buff.ptr, &dummy, 0u);

// TODO: loop here, because environment can change (by other thread)

                if(0 == exr)
                {
                    result = STLSOFT_STATIC_CAST(DWORD, STLSOFT_NS_GLOBAL(GetLastError()));

                    goto do_return;
                }

                cch = exr - 1;

                if(*pcchValue < cch)
                {
                    *pcchValue = STLSOFT_STATIC_CAST(DWORD, cch);

                    result = ERROR_MORE_DATA;

                    break;
                }

                if(0 != (r = STLSOFT_C_AUTO_BUFFER_RESIZE(buff2, exr)))
                {
                    result = winstl_C_standard_errno_to_Windows_LastErrorCode(r);

                    goto do_return;
                }
                else
                {
                    exr = STLSOFT_NS_GLOBAL(ExpandEnvironmentStringsA)(buff.ptr, buff2.ptr, STLSOFT_STATIC_CAST(DWORD, buff2.size));

                    if(0 == exr)
                    {
                        result = STLSOFT_STATIC_CAST(DWORD, STLSOFT_NS_GLOBAL(GetLastError()));

                        goto do_return;
                    }

                    s   =   buff2.ptr;
                    cch =   exr;
                }
            }

            if(cch <= *pcchValue)
            {
                memcpy(value, s, cch);

                if(cch < *pcchValue)
                {
                    value[cch] = '\0';
                }
            }

            *pcchValue = STLSOFT_STATIC_CAST(DWORD, cch);

            break;
        }
        else
        {
            goto do_return;
        }
    }

do_return:
    STLSOFT_C_AUTO_BUFFER_FREE(buff2);
    STLSOFT_C_AUTO_BUFFER_FREE(buff);

    return result;
}


STLSOFT_INLINE
LONG
winstl_C_registry_value_create_DWORD_a(
    HKEY        key
,   LPCSTR      name
,   DWORD       value
)
{
    WINSTL_ASSERT(NULL != key);

    return WINSTL_REGISTRY_external_RegSetValueExA(key, name, 0, REG_DWORD, STLSOFT_REINTERPRET_CAST(CONST BYTE*, &value), sizeof(value));
}

STLSOFT_INLINE
LONG
winstl_C_registry_value_read_DWORD_a(
    HKEY        key
,   LPCSTR      name
,   DWORD*      value
)
{
    DWORD   type;
    DWORD   cbValue;
    LONG    result;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != value);

    cbValue =   sizeof(*value);
    result  =   WINSTL_REGISTRY_external_RegQueryValueExA(key, name, NULL, &type, STLSOFT_REINTERPRET_CAST(LPBYTE, value), &cbValue);

    if(ERROR_SUCCESS == result)
    {
        switch(type)
        {
            case    REG_DWORD:
                break;
            default:
                result = WINSTL_REGISTRY_UTIL_VALUE_FUNCTIONS_ERROR_DATATYPE_MISMATCH_;
                break;
        }
    }

    return result;
}

STLSOFT_INLINE
LONG
winstl_C_registry_value_read_DWORD_w(
    HKEY        key
,   LPCWSTR     name
,   DWORD*      value
)
{
    DWORD   type;
    DWORD   cbValue;
    LONG    result;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != value);

    cbValue =   sizeof(*value);
    result  =   WINSTL_REGISTRY_external_RegQueryValueExW(key, name, NULL, &type, STLSOFT_REINTERPRET_CAST(LPBYTE, value), &cbValue);

    if(ERROR_SUCCESS == result)
    {
        switch(type)
        {
            case    REG_DWORD:
                break;
            default:
                result = WINSTL_REGISTRY_UTIL_VALUE_FUNCTIONS_ERROR_DATATYPE_MISMATCH_;
                break;
        }
    }

    return result;
}


STLSOFT_INLINE
LONG
winstl_C_registry_value_create_string_a(
    HKEY        key
,   LPCSTR      name
,   LPCSTR      value
)
{
    size_t const cchValue = (NULL == value) ? 0 : STLSOFT_NS_GLOBAL(strlen)(value);

    WINSTL_ASSERT(NULL != key);

    return WINSTL_REGISTRY_external_RegSetValueExA(key, name, 0, REG_SZ, STLSOFT_REINTERPRET_CAST(CONST BYTE*, value), STLSOFT_STATIC_CAST(DWORD, (0 + cchValue) * sizeof(CHAR)));
}

/**
 *
 *
 * \param value Pointer to a buffer to receive the data. May be NULL, in
 *   which case the required buffer size is returned in *pcchValue if the
 *   given value exists and its contents are retrievable.
 * \param pcchValue Pointer to a variable that specifies the amount of
 *   storage available in the buffer pointed to by value, and receives the
 *   length of the required buffer or the length of the retrieved value. The
 *   length of the required buffer is returned if <code>*pcchValue</code> is
 *   less than the total required to store the result and will include 1 for
 *   the terminating nul character. The length of the retrieved value will
 *   be returned if <code>*pcchValue</code> is greater than or equal to the
 *   total required to store the result and its terminating nul character.
 *
 * \retval ERROR_MORE_DATA If <code>NULL==value</code> or
 *   if <code>NULL!=value</code> and <code>*pcchValue</code> is less than
 *   the amount of storage required.
 *
 * \pre (NULL != pcchValue)
 */
STLSOFT_INLINE
LONG
winstl_C_registry_value_read_string_a(
    HKEY        key
,   LPCSTR      name
,   LPSTR       value
,   LPDWORD     pcchValue
)
{
    DWORD   type;
    DWORD   cbValue;
    LONG    result;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != pcchValue);

    if(NULL == value)
    {
        *pcchValue = 0;
    }

    cbValue = *pcchValue * sizeof(CHAR);

    result = WINSTL_REGISTRY_external_RegQueryValueExA(key, name, NULL, &type, STLSOFT_REINTERPRET_CAST(LPBYTE, value), &cbValue);

    if( NULL == value &&
        ERROR_SUCCESS == result &&
        REG_EXPAND_SZ != type)
    {
        result = ERROR_MORE_DATA;
    }
    else
    if( ERROR_SUCCESS == result ||
        ERROR_MORE_DATA == result)
    {
        switch(type)
        {
            case    REG_SZ:
                break;
            case    REG_EXPAND_SZ:
                return winstl_C_registry_value_read_and_expand_string_a_(key, name, value, pcchValue);
            default:
                result = WINSTL_REGISTRY_UTIL_VALUE_FUNCTIONS_ERROR_DATATYPE_MISMATCH_;
                break;
        }
    }

    *pcchValue = cbValue / sizeof(CHAR);

    return result;
}

STLSOFT_INLINE
LONG
winstl_C_registry_value_create_expand_string_a(
    HKEY        key
,   LPCSTR      name
,   LPCSTR      value
)
{
    size_t const cchValue = (NULL == value) ? 0 : STLSOFT_NS_GLOBAL(strlen)(value);

    WINSTL_ASSERT(NULL != key);

    return WINSTL_REGISTRY_external_RegSetValueExA(key, name, 0, REG_EXPAND_SZ, STLSOFT_REINTERPRET_CAST(CONST BYTE*, value), STLSOFT_STATIC_CAST(DWORD, (0 + cchValue) * sizeof(CHAR)));
}

/**
 *
 *
 *
 * \param pcchValue The length of the required buffer or the length of the
 *   retrieved value. The length of the required buffer is returned if
 *   <code>*pcchValue</code> is less than the total required to store the
 *   result and will include 1 for the terminating nul character. The
 *   length of the retrieved value will be returned if
 *   <code>*pcchValue</code> is greater than or equal to the total required
 *   to store the result and its terminating nul character.
 */
STLSOFT_INLINE
LONG
winstl_C_registry_value_read_expand_string_a(
    HKEY        key
,   LPCSTR      name
,   LPSTR       value
,   LPDWORD     pcchValue
)
{
    DWORD   type;
    DWORD   cbValue;
    LONG    result;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != pcchValue);

    if(NULL == value)
    {
        *pcchValue = 0;
    }

    cbValue = *pcchValue * sizeof(CHAR);

    result = WINSTL_REGISTRY_external_RegQueryValueExA(key, name, NULL, &type, STLSOFT_REINTERPRET_CAST(LPBYTE, value), &cbValue);

    if(ERROR_SUCCESS == result)
    {
        if(NULL == value)
        {
            result = ERROR_MORE_DATA;
        }
        else
        switch(type)
        {
            case    REG_SZ:
            case    REG_EXPAND_SZ:
                break;
            default:
                result = WINSTL_REGISTRY_UTIL_VALUE_FUNCTIONS_ERROR_DATATYPE_MISMATCH_;
                break;
        }
    }

    *pcchValue = cbValue / sizeof(CHAR);

    return result;
}

STLSOFT_INLINE
LONG
winstl_C_registry_value_create_binary_a(
    HKEY        key
,   LPCSTR      name
,   LPCVOID     data
,   DWORD       cbData
)
{
    WINSTL_ASSERT(NULL != key);

    return WINSTL_REGISTRY_external_RegSetValueExA(key, name, 0, REG_BINARY, STLSOFT_REINTERPRET_CAST(CONST BYTE*, data), cbData);
}

/** Reads a registry value in binary format
 *
 * \param key The registry key whose value is to be read
 * \param name The name of the value to read
 * \param value Pointer to a buffer into which to read. May be NULL
 * \param pcbValue The size of the required buffer or the size of the
 *   retrieved value. The size of the required buffer is returned if
 *   <code>*pcbValue</code> is less than the total required to store the
 *   result. The size of the retrieved value will be returned if
 *   <code>*pcbValue</code> is greater than or equal to the total required
 *   to store the result.
 * \param pdwType Pointer to a variable to receive the actual type of the
 *   data. May be NULL, in which case the function will return the status
 *   code <code>ERROR_DATATYPE_MISMATCH</code> if the stored type is not
 *   <code>REG_BINARY</code>; otherwise, the data is retrieved and the
 *   actual type stored into <code>*pdwType</code>.
 *
 */
STLSOFT_INLINE
LONG
winstl_C_registry_value_read_binary_a(
    HKEY        key
,   LPCSTR      name
,   LPVOID      value
,   LPDWORD     pcbValue
,   LPDWORD     pdwType /* = NULL */
)
{
    DWORD   type;
    LONG    result;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != pcbValue);

    if(NULL == value)
    {
        *pcbValue = 0;
    }

    result = WINSTL_REGISTRY_external_RegQueryValueExA(key, name, NULL, &type, STLSOFT_REINTERPRET_CAST(LPBYTE, value), pcbValue);

    if(ERROR_SUCCESS == result)
    {
        if( REG_BINARY != type &&
            NULL == pdwType)
        {
            result = WINSTL_REGISTRY_UTIL_VALUE_FUNCTIONS_ERROR_DATATYPE_MISMATCH_;
        }
    }

    if(NULL != pdwType)
    {
        *pdwType = type;
    }

    return result;
}


struct stlsoft_string_slice_m_t
{
    size_t  len;
    char*   ptr;
};
#ifndef __cplusplus
typedef struct stlsoft_string_slice_m_t stlsoft_string_slice_m_t;
#endif

/**
 *
 * \param valueLines Pointer to an array (of length \c numLines) of string
 *   slices whose values will be read (but not modified)
 *
 */
STLSOFT_INLINE
LONG
winstl_C_registry_value_create_multi_string_from_string_slice_array_a(
    HKEY                            key
,   LPCSTR                          name
,   stlsoft_string_slice_m_t const* valueLines
,   DWORD                           numLines
)
{
    STLSOFT_C_AUTO_BUFFER_DECLARE(char, 200, buff);

    LONG    result;
    DWORD   i;
    size_t  total;
    int     r;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != valueLines || 0 == numLines);

    STLSOFT_C_AUTO_BUFFER_INITIALISE_FROM_INTERNAL(buff);

    for(i = 0, total = 0; i != numLines; ++i)
    {
        total += valueLines[i].len;
        total += 1;
    }
    total += 1;

    if(0 != (r = STLSOFT_C_AUTO_BUFFER_RESIZE(buff, total)))
    {
        result = winstl_C_standard_errno_to_Windows_LastErrorCode(r);

        goto do_return;
    }
    else
    {
        LPSTR p = buff.ptr;

        for(i = 0; i != numLines; ++i)
        {
            memcpy(p, valueLines[i].ptr, valueLines[i].len * sizeof(CHAR));
            p += valueLines[i].len;
            *p++ = '\0';
        }
        *p++ = '\0';

        result = WINSTL_REGISTRY_external_RegSetValueExA(key, name, 0, REG_MULTI_SZ, STLSOFT_REINTERPRET_CAST(CONST BYTE*, buff.ptr), STLSOFT_STATIC_CAST(DWORD, total * sizeof(CHAR)));
    }

do_return:
    STLSOFT_C_AUTO_BUFFER_FREE(buff);

    return result;
}


STLSOFT_INLINE
LONG
winstl_C_registry_value_create_multi_string_from_Cstyle_string_array_a(
    HKEY        key
,   LPCSTR      name
,   LPCSTR*     valueLines
,   DWORD       numLines
)
{
    STLSOFT_C_AUTO_BUFFER_DECLARE(stlsoft_string_slice_m_t, 16, buff);

    int r;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != valueLines || 0 == numLines);

    if(0 != (r = STLSOFT_C_AUTO_BUFFER_INITIALISE(buff, numLines)))
    {
        return winstl_C_standard_errno_to_Windows_LastErrorCode(r);
    }
    else
    {
        LONG    result;
        DWORD   i;

        for(i = 0; i != numLines; ++i)
        {
            buff.ptr[i].ptr =   STLSOFT_CONST_CAST(LPSTR, valueLines[i]);
            buff.ptr[i].len =   (NULL == valueLines[i]) ? 0u : STLSOFT_NS_GLOBAL(strlen)(valueLines[i]);
        }

        result = winstl_C_registry_value_create_multi_string_from_string_slice_array_a(key, name, buff.ptr, STLSOFT_STATIC_CAST(DWORD, buff.size));

        STLSOFT_C_AUTO_BUFFER_FREE(buff);

        return result;
    }
}

STLSOFT_INLINE
LONG
winstl_C_registry_value_read_multi_string_as_string_slice_array_a(
    HKEY                        key
,   LPCSTR                      name
,   stlsoft_string_slice_m_t*   valueLines
,   LPDWORD                     pnumLines
)
{
    LONG    result;
    DWORD   cbValue;
    DWORD   type;

    WINSTL_ASSERT(NULL != key);
    WINSTL_ASSERT(NULL != pnumLines);

    if(NULL == valueLines)
    {
        *pnumLines = 0;
    }

    result = WINSTL_REGISTRY_external_RegQueryValueExA(key, name, NULL, &type, NULL, &cbValue);

    if(ERROR_SUCCESS == result)
    {
        STLSOFT_C_AUTO_BUFFER_DECLARE(CHAR, 30, buff);

        int     r;
        DWORD   cchValue    =   cbValue / sizeof(CHAR);

        if(0 != (r = STLSOFT_C_AUTO_BUFFER_INITIALISE(buff, cchValue)))
        {
            result = winstl_C_standard_errno_to_Windows_LastErrorCode(r);
        }
        else
        {
            do
            {
                cbValue = STLSOFT_STATIC_CAST(DWORD, buff.size / sizeof(CHAR));

                result = WINSTL_REGISTRY_external_RegQueryValueExA(key, name, NULL, &type, STLSOFT_REINTERPRET_CAST(LPBYTE, buff.ptr), &cbValue);

                cchValue = cbValue / sizeof(CHAR);

                if(ERROR_MORE_DATA == result)
                {
                    if(0 != (r = STLSOFT_C_AUTO_BUFFER_RESIZE(buff, cchValue)))
                    {
                        result = winstl_C_standard_errno_to_Windows_LastErrorCode(r);

                        goto do_cleanup;
                    }
                }
                else
                if(ERROR_SUCCESS == result)
                {
                    DWORD           numLines    =   0;
                    LPCSTR const    end         =   buff.ptr + cchValue;
                    LPCSTR          p1          =   buff.ptr;
                    LPCSTR          p2          =   buff.ptr;

                    for(; p1 != end - 1; ++p1)
                    {
                        if('\0' == *p1)
                        {
                            if(NULL != valueLines)
                            {
                                if(numLines < *pnumLines)
                                {
                                    size_t const n = p1 - p2;

                                    if( NULL != valueLines[numLines].ptr &&
                                        valueLines[numLines].len > n)
                                    {
                                        memcpy(valueLines[numLines].ptr, p2, (n + 1) * sizeof(CHAR));
                                    }
                                    valueLines[numLines].len = n;
                                }
                            }

                            ++numLines;
                            p2 = NULL;
                        }
                        else
                        {
                            if(NULL == p2)
                            {
                                p2 = p1;
                            }
                        }
                    }

                    *pnumLines = numLines;

                    /* now parse */
                }

            } while(ERROR_MORE_DATA == result);

do_cleanup:
            STLSOFT_C_AUTO_BUFFER_FREE(buff);
        }
    }

    return result;
}


#ifdef UNICODE
# define winstl_C_registry_value_create_DWORD                                   winstl_C_registry_value_create_DWORD_w
# define winstl_C_registry_value_read_DWORD                                     winstl_C_registry_value_read_DWORD_w
# define winstl_C_registry_value_create_string                                  winstl_C_registry_value_create_string_w
# define winstl_C_registry_value_read_string                                    winstl_C_registry_value_read_string_w
# define winstl_C_registry_value_create_expand_string                           winstl_C_registry_value_create_expand_string_w
# define winstl_C_registry_value_read_expand_string                             winstl_C_registry_value_read_expand_string_w
# define winstl_C_registry_value_create_binary                                  winstl_C_registry_value_create_binary_w
# define winstl_C_registry_value_read_binary                                    winstl_C_registry_value_read_binary_w
# define winstl_C_registry_value_create_multi_string_from_string_slice_array    winstl_C_registry_value_create_multi_string_from_string_slice_array_w
# define winstl_C_registry_value_create_multi_string_from_Cstyle_string_array   winstl_C_registry_value_create_multi_string_from_Cstyle_string_array_w
# define winstl_C_registry_value_read_multi_string_as_string_slice_array        winstl_C_registry_value_read_multi_string_as_string_slice_array_w
#else /* ? UNICODE */
# define winstl_C_registry_value_create_DWORD                                   winstl_C_registry_value_create_DWORD_a
# define winstl_C_registry_value_read_DWORD                                     winstl_C_registry_value_read_DWORD_a
# define winstl_C_registry_value_create_string                                  winstl_C_registry_value_create_string_a
# define winstl_C_registry_value_read_string                                    winstl_C_registry_value_read_string_a
# define winstl_C_registry_value_create_expand_string                           winstl_C_registry_value_create_expand_string_a
# define winstl_C_registry_value_read_expand_string                             winstl_C_registry_value_read_expand_string_a
# define winstl_C_registry_value_create_binary                                  winstl_C_registry_value_create_binary_a
# define winstl_C_registry_value_read_binary                                    winstl_C_registry_value_read_binary_a
# define winstl_C_registry_value_create_multi_string_from_string_slice_array    winstl_C_registry_value_create_multi_string_from_string_slice_array_a
# define winstl_C_registry_value_create_multi_string_from_Cstyle_string_array   winstl_C_registry_value_create_multi_string_from_Cstyle_string_array_a
# define winstl_C_registry_value_read_multi_string_as_string_slice_array        winstl_C_registry_value_read_multi_string_as_string_slice_array_a
#endif /* UNICODE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_REGISTRY_util_h_value_functions */

/* ///////////////////////////// end of file //////////////////////////// */
