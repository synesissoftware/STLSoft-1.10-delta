/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.conversion.truncation_test.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.conversion.truncation_test project.
 *
 * Created:     7th November 2008
 * Updated:     18th June 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#ifdef __BORLANDC__
# pragma warn -8004
# pragma warn -8008
# pragma warn -8066
#endif /* compiler */

#if 0
# include <stlsoft/conversion/truncation_test.hpp>
#else /* ? 0 */

# include <stlsoft/stlsoft.h>
# include <stlsoft/meta/is_integral_type.hpp>
# include <stlsoft/meta/is_same_type.hpp>
# include <stlsoft/meta/is_signed_type.hpp>
# include <stlsoft/meta/yesno.hpp>
# include <stlsoft/util/limit_traits.h>
# if defined(_DEBUG)
#  include <typeinfo>
# endif /* STLSOFT_UNITTEST || _DEBUG */

namespace stlsoft
{
    // The permutations are:
    //
    // 1a FROM signed | TO signed | sizeof(FROM) < sizeof(TO)       =>  Always yes
    // 1b FROM signed | TO signed | sizeof(FROM) = sizeof(TO)       =>  Always yes
    // 1c FROM signed | TO signed | sizeof(FROM) > sizeof(TO)       =>  Runtime test
    //
    // 2a FROM unsigned | TO signed | sizeof(FROM) < sizeof(TO)     =>  Always yes
    // 2b FROM unsigned | TO signed | sizeof(FROM) = sizeof(TO)     =>  Runtime test
    // 2c FROM unsigned | TO signed | sizeof(FROM) > sizeof(TO)     =>  Runtime test
    //
    // 3a FROM signed | TO unsigned | sizeof(FROM) < sizeof(TO)     =>  Runtime test
    // 3b FROM signed | TO unsigned | sizeof(FROM) = sizeof(TO)     =>  Runtime test
    // 3c FROM signed | TO unsigned | sizeof(FROM) > sizeof(TO)     =>  Runtime test
    //
    // 4a FROM unsigned | TO unsigned | sizeof(FROM) < sizeof(TO)   =>  Always yes
    // 4b FROM unsigned | TO unsigned | sizeof(FROM) = sizeof(TO)   =>  Always yes
    // 4c FROM unsigned | TO unsigned | sizeof(FROM) > sizeof(TO)   =>  Runtime test



    template<   typename TO
            ,   typename FROM
            >
    bool truncation_test_v2_is_statically_determined(FROM, TO, yes_type)
    {
        return true;
    }

    template<   typename TO
            ,   typename FROM
            >
    bool truncation_test_v2_is_statically_determined(FROM from, TO, no_type)
    {
#ifdef _DEBUG
        char const  *TO_    =   typeid(TO).name();
        char const  *FROM_  =   typeid(FROM).name();

        STLSOFT_SUPPRESS_UNUSED(TO_);
        STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

        enum { fromIsSigned =   stlsoft::is_signed_type<FROM>::value    };
        enum { toIsSigned   =   stlsoft::is_signed_type<TO>::value      };

        STLSOFT_STATIC_ASSERT(sizeof(FROM) >= sizeof(TO) || fromIsSigned);

        if(fromIsSigned)
        {
            if(toIsSigned)
            {
                if(sizeof(FROM) <= sizeof(TO))
                {
                    return true; // 1a, 1b
                }
                else
                {
                    // 1c

                    // FROM is larger than TO, so have to test value

                    FROM    toMin   =   static_cast<FROM>(stlsoft::limit_traits<TO>::minimum());
                    FROM    toMax   =   static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

                    if( from < toMin ||
                        from > toMax)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            else
            {
                // 3a, 3b, 3c

                if(from < 0)
                {
                    return false;
                }
                else
                {
                    if(sizeof(FROM) <= sizeof(TO))
                    {
                        return true; // 3a, 3b
                    }
                    else
                    {
                        FROM toMax = static_cast<FROM>(stlsoft::limit_traits<TO>::maximum()); // 3c

                        return from <= toMax;
                    }
                }
            }
        }
        else
        {
            if(toIsSigned)
            {
                if(sizeof(FROM) < sizeof(TO))
                {
                    return true; // 2a
                }
                else
                {
                    FROM toMax = static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

                    return from <= toMax; // 2b, 2c
                }
            }
            else
            {
                if(sizeof(FROM) <= sizeof(TO))
                {
                    return true; // 4a, 4b
                }
                else
                {
                    // 4c

                    FROM toMax = static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

                    return from <= toMax;
                }
            }
        }
    }



    template<   typename TO
            ,   typename FROM
            >
    bool truncation_test_v2(FROM from, TO dummy)
    {
#ifdef _DEBUG
        char const  *TO_    =   typeid(TO).name();
        char const  *FROM_  =   typeid(FROM).name();

        STLSOFT_SUPPRESS_UNUSED(TO_);
        STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

        enum { fromIsSigned =   stlsoft::is_signed_type<FROM>::value    };
        enum { toIsSigned   =   stlsoft::is_signed_type<TO>::value      };

        enum
        {
            is_statically_determined =  
                (   int(fromIsSigned) == int(toIsSigned) &&
                    sizeof(FROM) <= sizeof(TO)) ||
                (   !fromIsSigned &&
                    toIsSigned &&
                    sizeof(FROM) < sizeof(TO))
        };

        typedef ss_typename_type_k value_to_yesno_type<is_statically_determined>::type  yesno_t;

        return truncation_test_v2_is_statically_determined(from, dummy, yesno_t());
    }

    template<   typename TO
            ,   typename FROM
            >
    bool truncation_test_v1(FROM from, TO)
    {
#ifdef _DEBUG
        char const  *TO_    =   typeid(TO).name();
        char const  *FROM_  =   typeid(FROM).name();

        STLSOFT_SUPPRESS_UNUSED(TO_);
        STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

        const int   fromIsSigned    =   stlsoft::is_signed_type<FROM>::value;
        const int   toIsSigned      =   stlsoft::is_signed_type<TO>::value;

        if(fromIsSigned)
        {
            if(toIsSigned)
            {
                if(sizeof(FROM) <= sizeof(TO))
                {
                    return true; // 1a, 1b
                }
                else
                {
                    // 1c

                    // FROM is larger than TO, so have to test value

                    FROM    toMin   =   static_cast<FROM>(stlsoft::limit_traits<TO>::minimum());
                    FROM    toMax   =   static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

                    if( from < toMin ||
                        from > toMax)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            else
            {
                // 3a, 3b, 3c

                if(from < 0)
                {
                    return false;
                }
                else
                {
                    if(sizeof(FROM) <= sizeof(TO))
                    {
                        return true; // 3a, 3b
                    }
                    else
                    {
                        FROM toMax = static_cast<FROM>(stlsoft::limit_traits<TO>::maximum()); // 3c

                        return from <= toMax;
                    }
                }
            }
        }
        else
        {
            if(toIsSigned)
            {
                if(sizeof(FROM) < sizeof(TO))
                {
                    return true; // 2a
                }
                else
                {
                    FROM toMax = static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

                    return from <= toMax; // 2b, 2c
                }
            }
            else
            {
                if(sizeof(FROM) <= sizeof(TO))
                {
                    return true; // 4a, 4b
                }
                else
                {
                    // 4c

                    FROM toMax = static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

                    return from <= toMax;
                }
            }
        }
    }

    template<   typename TO
            ,   typename FROM
            >
    bool truncation_test(FROM from, TO dummy = TO())
    {
#ifdef _DEBUG
        char const  *TO_    =   typeid(TO).name();
        char const  *FROM_  =   typeid(FROM).name();

        STLSOFT_SUPPRESS_UNUSED(TO_);
        STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

//      return truncation_test_v1<TO, FROM>(from, dummy);
        return truncation_test_v2<TO, FROM>(from, dummy);
    }
};

#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_performance(void);
    static void test_12(void);
#if 1
    static void test_zero(void);
    static void test_sign(void);
    static void test_range_signed(void);
    static void test_range_unsigned(void);
    static void test_edge_to_sint8(void);
    static void test_to_sint8(void);
    static void test_to_uint8(void);
    static void test_to_sint16(void);
    static void test_1_3(void);
    static void test_1_9(void);
    static void test_1_10(void);
    static void test_1_11(void);
    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);
#endif /* 0 */

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.conversion.truncation_test", verbosity))
    {
        XTESTS_RUN_CASE(test_performance);
        XTESTS_RUN_CASE(test_12);
#if 1
        XTESTS_RUN_CASE(test_zero);
        XTESTS_RUN_CASE(test_sign);
        XTESTS_RUN_CASE(test_range_signed);
        XTESTS_RUN_CASE(test_range_unsigned);
        XTESTS_RUN_CASE(test_edge_to_sint8);
        XTESTS_RUN_CASE(test_to_sint8);
        XTESTS_RUN_CASE(test_to_uint8);
        XTESTS_RUN_CASE(test_to_sint16);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);
#endif /* 0 */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

    using stlsoft::sint8_t;
    using stlsoft::uint8_t;
    using stlsoft::sint16_t;
    using stlsoft::uint16_t;
    using stlsoft::sint32_t;
    using stlsoft::uint32_t;
    using stlsoft::sint64_t;
    using stlsoft::uint64_t;

static void test_performance()
{
    platformstl::performance_counter counter;

    int total = 0;

    { for(int WARMUPS = 2; 0 != --WARMUPS; )
    {
        counter.start();

        { for(int i = 0; i != 1000000; ++i)
        {
            total += stlsoft::truncation_test<sint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::minimum()));
            total += stlsoft::truncation_test<sint16_t>(sint8_t(0));
            total += stlsoft::truncation_test<sint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::maximum()));

            // 1b
            total += stlsoft::truncation_test<sint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::minimum()));
            total += stlsoft::truncation_test<sint16_t>(sint16_t(0));
            total += stlsoft::truncation_test<sint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::maximum()));

            // 1c
            total += stlsoft::truncation_test<sint16_t>(sint64_t(stlsoft::limit_traits<sint64_t>::minimum()));
            total += stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::minimum()));
            total += stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum()));
            total += stlsoft::truncation_test<sint16_t>(sint32_t(0));
            total += stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum()));
            total += stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::maximum()));
            total += stlsoft::truncation_test<sint16_t>(sint64_t(stlsoft::limit_traits<sint64_t>::maximum()));


            // 2a
            total += stlsoft::truncation_test<sint16_t>(uint8_t(0));
            total += stlsoft::truncation_test<sint16_t>(uint8_t(stlsoft::limit_traits<uint8_t>::maximum()));

            // 2b
            total += stlsoft::truncation_test<sint16_t>(uint16_t(0));
            total += stlsoft::truncation_test<sint16_t>(uint16_t(stlsoft::limit_traits<sint16_t>::maximum()));
            total += stlsoft::truncation_test<sint16_t>(uint16_t(stlsoft::limit_traits<uint16_t>::maximum()));

            // 2c
            total += stlsoft::truncation_test<sint16_t>(uint32_t(0));
            total += stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<sint16_t>::maximum()));
            total += stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<uint16_t>::maximum()));
            total += stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<uint32_t>::maximum()));


            // 3a
            total += stlsoft::truncation_test<uint16_t>(sint8_t(0));
            total += stlsoft::truncation_test<uint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::maximum()));

            // 3b
            total += stlsoft::truncation_test<uint16_t>(sint16_t(0));
            total += stlsoft::truncation_test<uint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::maximum()));

            // 3c
            total += stlsoft::truncation_test<uint16_t>(sint32_t(0));
            total += stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum()));
            total += stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<uint16_t>::maximum()));
            total += stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::maximum()));


            // 4a
            total += stlsoft::truncation_test<uint16_t>(uint8_t(0));
            total += stlsoft::truncation_test<uint16_t>(uint8_t(stlsoft::limit_traits<uint8_t>::maximum()));

            // 4b
            total += stlsoft::truncation_test<uint16_t>(uint16_t(0));
            total += stlsoft::truncation_test<uint16_t>(uint16_t(stlsoft::limit_traits<uint16_t>::maximum()));

            // 4c
            total += stlsoft::truncation_test<uint16_t>(uint32_t(0));
            total += stlsoft::truncation_test<uint16_t>(uint32_t(stlsoft::limit_traits<uint16_t>::maximum()));
            total += stlsoft::truncation_test<uint16_t>(uint32_t(stlsoft::limit_traits<uint32_t>::maximum()));
            total += stlsoft::truncation_test<uint16_t>(uint64_t(stlsoft::limit_traits<uint64_t>::maximum()));
        }}

        counter.stop();
    }}
#if 0
    fprintf(stderr, "test_performance: %ldus\n", long(counter.get_microseconds()), total);
#endif /* 0 */
}

static void test_12()
{
    // 1a
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::minimum())));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint8_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::maximum())));

    // 1b
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::minimum())));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint16_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::maximum())));

    // 1c
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(sint64_t(stlsoft::limit_traits<sint64_t>::minimum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::minimum())));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum())));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(sint64_t(stlsoft::limit_traits<sint64_t>::maximum())));


    // 2a
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(uint8_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(uint8_t(stlsoft::limit_traits<uint8_t>::maximum())));

    // 2b
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(uint16_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(uint16_t(stlsoft::limit_traits<sint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(uint16_t(stlsoft::limit_traits<uint16_t>::maximum())));

    // 2c
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(uint32_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<sint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<uint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<uint32_t>::maximum())));


    // 3a
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(sint8_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::maximum())));

    // 3b
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(sint16_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::maximum())));

    // 3c
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(sint32_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<uint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::maximum())));


    // 4a
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(uint8_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(uint8_t(stlsoft::limit_traits<uint8_t>::maximum())));

    // 4b
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(uint16_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(uint16_t(stlsoft::limit_traits<uint16_t>::maximum())));

    // 4c
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(uint32_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(uint32_t(stlsoft::limit_traits<uint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint16_t>(uint32_t(stlsoft::limit_traits<uint32_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint16_t>(uint64_t(stlsoft::limit_traits<uint64_t>::maximum())));

}

#if 1
static void test_zero()
{
    // int
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(0));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint8_t>(0));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(0));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(0));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(0));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(0));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(0));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(0));

    // uint64_t
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(uint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint8_t>(uint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(uint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(uint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(uint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(uint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(uint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(uint64_t(0)));

    // sint64_t
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(sint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint8_t>(sint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(sint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(sint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(sint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(sint64_t(0)));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(sint64_t(0)));
}

static void test_sign()
{
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(-10));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint8_t>(-10));

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(-10));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint16_t>(-10));

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-10));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint32_t>(-10));

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-10));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint32_t>(-10));
}

static void test_range_signed()
{
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(-1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(-10));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(-100));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(stlsoft::limit_traits<sint8_t>::minimum() + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(stlsoft::limit_traits<sint8_t>::minimum()));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::minimum()) + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::minimum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::minimum()) - 1));

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(-1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(-10));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(-100));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(-1000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(-10000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(stlsoft::limit_traits<sint16_t>::minimum() + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(stlsoft::limit_traits<sint16_t>::minimum()));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum()) + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum()) - 1));

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-10));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-100));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-1000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-10000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-100000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-1000000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(-10000000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(stlsoft::limit_traits<sint32_t>::minimum() + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(stlsoft::limit_traits<sint32_t>::minimum()));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::minimum()) + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::minimum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::minimum()) - 1));
}

static void test_range_unsigned()
{
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint8_t>(1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint8_t>(10));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint8_t>(100));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint8_t>(stlsoft::limit_traits<uint8_t>::maximum()));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint8_t>(uint16_t(stlsoft::limit_traits<uint8_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint8_t>(uint16_t(stlsoft::limit_traits<uint8_t>::maximum()) + 1));

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(10));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(100));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(1000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(10000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(stlsoft::limit_traits<uint16_t>::maximum()));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint16_t>(uint32_t(stlsoft::limit_traits<uint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint16_t>(uint32_t(stlsoft::limit_traits<uint16_t>::maximum()) + 1));

    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(10));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(100));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(1000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(10000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(100000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(1000000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(10000000));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(stlsoft::limit_traits<uint32_t>::maximum()));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<uint32_t>(uint64_t(stlsoft::limit_traits<uint32_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<uint32_t>(uint64_t(stlsoft::limit_traits<uint32_t>::maximum()) + 1));
}

static void test_edge_to_sint8()
{
    // sint8_t
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(stlsoft::limit_traits<sint8_t>::minimum()));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(stlsoft::limit_traits<sint8_t>::minimum() + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(stlsoft::limit_traits<sint8_t>::maximum() - 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(stlsoft::limit_traits<sint8_t>::maximum()));

    // sint16_t
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::minimum()) - 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::minimum())));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::minimum()) + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::maximum()) - 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint8_t>(sint16_t(stlsoft::limit_traits<sint8_t>::maximum()) + 1));

    // sint32_t
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum()) - 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum())));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum()) + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum()) - 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum()) + 1));

    // sint64_t
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::minimum()) - 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::minimum())));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::minimum()) + 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::maximum()) - 1));
    XTESTS_TEST_BOOLEAN_TRUE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::maximum())));
    XTESTS_TEST_BOOLEAN_FALSE(stlsoft::truncation_test<sint32_t>(sint64_t(stlsoft::limit_traits<sint32_t>::maximum()) + 1));

    // uint8_t
    ;
}

static void test_to_sint8()
{
    // All in range
    { for(sint8_t from = stlsoft::limit_traits<sint8_t>::minimum(); ; ++from)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(true, stlsoft::truncation_test<sint8_t>(from));

        if(stlsoft::limit_traits<sint8_t>::maximum() == from)
        {
            break;
        }
    }}

    // < lower bound
    { for(sint16_t from = stlsoft::limit_traits<sint16_t>::minimum(); from != stlsoft::limit_traits<sint8_t>::minimum(); ++from)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(false, stlsoft::truncation_test<sint8_t>(from));
    }}

    // > upper bound
    { for(sint16_t from = sint16_t(1 + stlsoft::limit_traits<sint8_t>::maximum()); from != stlsoft::limit_traits<sint16_t>::maximum(); ++from)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(false, stlsoft::truncation_test<sint8_t>(from));
    }}
}

static void test_to_uint8()
{
    // All in range
    { for(uint8_t from = stlsoft::limit_traits<uint8_t>::minimum(); ; ++from)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(true, stlsoft::truncation_test<uint8_t>(from));

        if(stlsoft::limit_traits<uint8_t>::maximum() == from)
        {
            break;
        }
    }}

    // < lower bound
    { for(sint16_t from = stlsoft::limit_traits<sint16_t>::minimum(); from != stlsoft::limit_traits<uint8_t>::minimum(); ++from)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(false, stlsoft::truncation_test<uint8_t>(from));
    }}

    // > upper bound
    { for(sint16_t from = sint16_t(1 + stlsoft::limit_traits<uint8_t>::maximum()); from != stlsoft::limit_traits<sint16_t>::maximum(); ++from)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(false, stlsoft::truncation_test<uint8_t>(from));
    }}
}

static void test_to_sint16()
{
    // All in range
    { for(sint16_t from = stlsoft::limit_traits<sint16_t>::minimum(); ; ++from)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(true, stlsoft::truncation_test<sint16_t>(from));

        if(stlsoft::limit_traits<sint16_t>::maximum() == from)
        {
            break;
        }
    }}

    // < lower bound
    { for(sint32_t from = stlsoft::limit_traits<sint32_t>::minimum(); from < stlsoft::limit_traits<sint16_t>::minimum(); from /= 10)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(false, stlsoft::truncation_test<sint16_t>(from));
    }}

    // > upper bound
    { for(sint32_t from = 1 + sint32_t(stlsoft::limit_traits<sint16_t>::maximum()); from > stlsoft::limit_traits<sint32_t>::maximum(); from *= 10)
    {
        XTESTS_TEST_BOOLEAN_EQUAL(false, stlsoft::truncation_test<sint16_t>(from));
    }}
}

static void test_1_3()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}
#endif /* 0 */


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
