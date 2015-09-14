
/*
 *
 * Created: 11th May 2010
 * Updated: 12th August 2010
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_REPLACE_FUNCTIONS
#define STLSOFT_INCL_STLSOFT_STRING_HPP_REPLACE_FUNCTIONS

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

# include <stlsoft/shims/access/string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

template<
    typename S0
,   typename C1
,   typename C2
>
inline S0& replace_impl(
    S0&         str
,   C1 const*   f
,   ss_size_t   lf
,   C2 const*   r
,   ss_size_t   lr
)
{
    size_t const lenOrig = str.size();

    if(lf <= lenOrig)
    {
        ss_typename_type_k S0::size_type p;

        { for(p = str.find(f, 0, lf); p < str.size(); p = str.find(f, p, lf))
        {
            str.replace(str.begin() + p, str.begin() + p + lf, r, lr);
            p = p + lr - lf + 1;
        }}
    }

    return str;
}

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

template<
    typename S0
,   typename S1
,   typename S2
>
inline S0& replace(
    S0&         str
,   S1 const&   findString
,   S2 const&   replaceString
)
{
    return replace_impl(
                str
            ,   stlsoft::c_str_data(findString)
            ,   stlsoft::c_str_len(findString)
            ,   stlsoft::c_str_data(replaceString)
            ,   stlsoft::c_str_len(replaceString)
            );
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_REPLACE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
