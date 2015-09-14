
#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

namespace stlsoft
{

    inline
    ss_uint8_t
    to_unsigned(
        ss_sint8_t v
    )
    {
        return stlsoft_static_cast(ss_uint8_t, v);
    }

    inline
    ss_uint8_t
    to_unsigned(
        ss_uint8_t v
    )
    {
        return v;
    }


    inline
    ss_sint16_t
    to_unsigned(
        ss_sint16_t v
    )
    {
        return stlsoft_static_cast(ss_uint16_t, v);
    }

    inline
    ss_uint16_t
    to_unsigned(
        ss_uint16_t v
    )
    {
        return v;
    }


    inline
    ss_uint32_t
    to_unsigned(
        ss_sint32_t v
    )
    {
        return stlsoft_static_cast(ss_uint32_t, v);
    }

    inline
    ss_uint32_t
    to_unsigned(
        ss_uint32_t v
    )
    {
        return v;
    }


    inline
    ss_uint64_t
    to_unsigned(
        ss_sint64_t v
    )
    {
        return stlsoft_static_cast(ss_uint64_t, v);
    }

    inline
    ss_uint64_t
    to_unsigned(
        ss_uint64_t v
    )
    {
        return v;
    }

} /* namespace stlsoft */
