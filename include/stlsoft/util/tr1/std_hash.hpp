
/*
 * File:        stlsoft/util/tr1/std_hash.hpp
 *
 *
 * Created:     27th May 2010
 * Updated:     12th August 2010
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_TR1_HPP_STD_HASH
#define STLSOFT_INCL_STLSOFT_UTIL_TR1_HPP_STD_HASH

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#include <stlsoft/stlsoft.h>
#include <stlsoft/util/limit_traits.h>

#include <functional>
#include <string>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{

/* /////////////////////////////////////////////////////////////////////////
 * Helper classes
 */

namespace ximpl_std_hash
{
    struct std_hash_root
    {
    public: // Constants
        static ss_uint16_t get_mask_16()
        {
            return 0x8005;
        }

        static ss_uint32_t get_mask_32()
        {
            return 0x04C11DB7;
        }

        static ss_uint64_t get_mask_64()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(0x04C11DB710218005);
        }

        //template <ss_typename_param_k T>
        //static
        //  ss_typename_type_k stlsoft_ns_qual(int_size_traits)<sizeof(T)>::unsigned_type
        //      get_mask()
        //{
        //  typedef ss_typename_type_k stlsoft_ns_qual(int_size_traits)<sizeof(T)>::unsigned_type   uint_t_;

        //  return get_mask_<T>(static_cast<uint_t_ const*>(0));
        //}
    };

    template <ss_typename_param_k T>
    struct std_hash_root_mask_traits;

    STLSOFT_TEMPLATE_SPECIALISATION
    struct std_hash_root_mask_traits<ss_uint8_t>
    {
    public:
        static ss_uint8_t get_mask()
        {
            return static_cast<ss_uint8_t>(std_hash_root::get_mask_16() & 0xff);
        }
    };

    STLSOFT_TEMPLATE_SPECIALISATION
    struct std_hash_root_mask_traits<ss_uint16_t>
    {
    public:
        static ss_uint16_t get_mask()
        {
            return std_hash_root::get_mask_16();
        }
    };

    STLSOFT_TEMPLATE_SPECIALISATION
    struct std_hash_root_mask_traits<ss_uint32_t>
    {
    public:
        static ss_uint32_t get_mask()
        {
            return std_hash_root::get_mask_32();
        }
    };

    STLSOFT_TEMPLATE_SPECIALISATION
    struct std_hash_root_mask_traits<ss_uint64_t>
    {
    public:
        static ss_uint64_t get_mask()
        {
            return std_hash_root::get_mask_64();
        }
    };


    template <ss_typename_param_k T>
    struct std_hash_base
        : public std_hash_root
        , public stlsoft_ns_qual_std(unary_function)<T, ss_size_t>
    {
    public: // Member Types
        typedef stlsoft_ns_qual_std(unary_function)<T, ss_size_t>   parent_class_type;
        typedef ss_typename_type_k parent_class_type::argument_type argument_type;
        typedef ss_typename_type_k parent_class_type::result_type   result_type;
    };

    template <ss_typename_param_k T>
    struct std_hash_integer_base
        : public ximpl_std_hash::std_hash_base<T>
    {
    public: // Member Types
        typedef ximpl_std_hash::std_hash_base<T>                    parent_class_type;
        typedef ss_typename_type_k parent_class_type::argument_type argument_type;
        typedef ss_typename_type_k parent_class_type::result_type   result_type;
    public:
        result_type operator ()(int value) const stlsoft_throw_0()
        {
            typedef ss_typename_type_k int_size_traits<sizeof(argument_type)>::unsigned_type    mask_t_;

            return result_type(value) ^ std_hash_root_mask_traits<mask_t_>::get_mask();
        }
    };

} /* namespace ximpl_std_hash */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

template <ss_typename_param_k T>
struct std_hash;


STLSOFT_TEMPLATE_SPECIALISATION
struct std_hash<bool>
    : public ximpl_std_hash::std_hash_base<bool>
{
public:
    result_type operator ()(bool value) const stlsoft_throw_0()
    {
        return result_type(value);
    }
};

STLSOFT_TEMPLATE_SPECIALISATION
struct std_hash<short>
    : public ximpl_std_hash::std_hash_integer_base<short>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct std_hash<unsigned short>
    : public ximpl_std_hash::std_hash_base<unsigned short>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct std_hash<int>
    : public ximpl_std_hash::std_hash_integer_base<int>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct std_hash<unsigned int>
    : public ximpl_std_hash::std_hash_base<unsigned int>
{};

STLSOFT_TEMPLATE_SPECIALISATION
struct std_hash< stlsoft_ns_qual_std(string)>
    : public ximpl_std_hash::std_hash_base< stlsoft_ns_qual_std(string)>
{
public:
    result_type operator ()( stlsoft_ns_qual_std(string) const& value) const stlsoft_throw_0()
    {
        result_type     r = 0;
        std_hash<int>   h;
        char const*     p = value.data();
        char const*     q = p + value.size();

        { for(; p != q; ++p)
        {
            r ^= h(*p);
        }}

        return r;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Non-member functions
 */

template <ss_typename_param_k T>
inline void swap(
    std_hash<T>&
,   std_hash<T>&
)
{}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

namespace std
{

} /* namespace std */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_TR1_HPP_STD_HASH */

/* ///////////////////////////// end of file //////////////////////////// */
