/* /////////////////////////////////////////////////////////////////////////
 * File:        test.performance.stlsoft.conversion.truncation_test.cpp
 *
 * Purpose:     Implementation file for the test.performance.stlsoft.conversion.truncation_test project.
 *
 * Created:     7th November 2008
 * Updated:     25th April 2010
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

#if 1
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


	////////////////////////////////////////////////////////
	// Version 3

	template<	typename TO
			,	typename FROM
			>
	bool truncation_test_v3_is_statically_determined(FROM, TO, yes_type)
	{
		return true;
	}

	template<	typename TO
			,	typename FROM
			>
	bool truncation_test_v3_is_statically_determined(FROM from, TO, no_type)
	{
#ifdef _DEBUG
		char const  *TO_    =   typeid(TO).name();
		char const  *FROM_  =   typeid(FROM).name();

		STLSOFT_SUPPRESS_UNUSED(TO_);
		STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

		enum { fromIsSigned	=	stlsoft::is_signed_type<FROM>::value	};
		enum { toIsSigned	=	stlsoft::is_signed_type<TO>::value		};

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

					FROM	toMin	=	static_cast<FROM>(stlsoft::limit_traits<TO>::minimum());
					FROM	toMax	=	static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

					if(	from < toMin ||
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

				if(from < 0) // GCC: comparison is always false due to limited range of data type
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



	template<	typename TO
			,	typename FROM
			>
	bool truncation_test_v3(FROM from, TO dummy)
	{
#ifdef _DEBUG
		char const  *TO_    =   typeid(TO).name();
		char const  *FROM_  =   typeid(FROM).name();

		STLSOFT_SUPPRESS_UNUSED(TO_);
		STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

		enum { fromIsSigned	=	stlsoft::is_signed_type<FROM>::value	};
		enum { toIsSigned	=	stlsoft::is_signed_type<TO>::value		};

		enum
		{
			is_statically_determined =	
				(	int(fromIsSigned) == int(toIsSigned) &&
					sizeof(FROM) <= sizeof(TO)) ||
				(	!fromIsSigned &&
					toIsSigned &&
					sizeof(FROM) < sizeof(TO))
		};

		typedef ss_typename_type_k value_to_yesno_type<is_statically_determined>::type	yesno_t;

		return truncation_test_v3_is_statically_determined(from, dummy, yesno_t());
	}


	////////////////////////////////////////////////////////
	// Version 2

	template<	typename TO
			,	typename FROM
			>
	bool truncation_test_v2_is_statically_determined(FROM, TO, yes_type)
	{
		return true;
	}

	template<	typename TO
			,	typename FROM
			>
	bool truncation_test_v2_is_statically_determined(FROM from, TO, no_type)
	{
#ifdef _DEBUG
		char const  *TO_    =   typeid(TO).name();
		char const  *FROM_  =   typeid(FROM).name();

		STLSOFT_SUPPRESS_UNUSED(TO_);
		STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

		enum { fromIsSigned	=	stlsoft::is_signed_type<FROM>::value	};
		enum { toIsSigned	=	stlsoft::is_signed_type<TO>::value		};

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

					FROM	toMin	=	static_cast<FROM>(stlsoft::limit_traits<TO>::minimum());
					FROM	toMax	=	static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

					if(	from < toMin ||
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

				if(from < 0) // GCC: comparison is always false due to limited range of data type
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



	template<	typename TO
			,	typename FROM
			>
	bool truncation_test_v2(FROM from, TO dummy)
	{
#ifdef _DEBUG
		char const  *TO_    =   typeid(TO).name();
		char const  *FROM_  =   typeid(FROM).name();

		STLSOFT_SUPPRESS_UNUSED(TO_);
		STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

		enum { fromIsSigned	=	stlsoft::is_signed_type<FROM>::value	};
		enum { toIsSigned	=	stlsoft::is_signed_type<TO>::value		};

		enum
		{
			is_statically_determined =	
				(	int(fromIsSigned) == int(toIsSigned) &&
					sizeof(FROM) <= sizeof(TO)) ||
				(	!fromIsSigned &&
					toIsSigned &&
					sizeof(FROM) < sizeof(TO))
		};

		typedef ss_typename_type_k value_to_yesno_type<is_statically_determined>::type	yesno_t;

		return truncation_test_v2_is_statically_determined(from, dummy, yesno_t());
	}


	////////////////////////////////////////////////////////
	// Version 1

	template<	typename TO
			,	typename FROM
			>
	bool truncation_test_v1(FROM from, TO)
	{
#ifdef _DEBUG
		char const  *TO_    =   typeid(TO).name();
		char const  *FROM_  =   typeid(FROM).name();

		STLSOFT_SUPPRESS_UNUSED(TO_);
		STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

		const int	fromIsSigned	=	stlsoft::is_signed_type<FROM>::value;
		const int	toIsSigned		=	stlsoft::is_signed_type<TO>::value;

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

					FROM	toMin	=	static_cast<FROM>(stlsoft::limit_traits<TO>::minimum());
					FROM	toMax	=	static_cast<FROM>(stlsoft::limit_traits<TO>::maximum());

					if(	from < toMin ||
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

				if(from < 0) // GCC: comparison is always false due to limited range of data type
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

	template<	typename TO
			,	typename FROM
			>
	bool truncation_test(FROM from, TO dummy = TO())
	{
#ifdef _DEBUG
		char const  *TO_    =   typeid(TO).name();
		char const  *FROM_  =   typeid(FROM).name();

		STLSOFT_SUPPRESS_UNUSED(TO_);
		STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* _DEBUG */

#if 0
		return truncation_test_v1<TO, FROM>(from, dummy);
#elif 0
		return truncation_test_v2<TO, FROM>(from, dummy);
#elif 1
		return truncation_test_v3<TO, FROM>(from, dummy);
#endif /* 0 */
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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.performance.stlsoft.conversion.truncation_test", verbosity))
	{
		XTESTS_RUN_CASE(test_performance);

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

	::srand(reinterpret_cast<unsigned int>(&total));

	{ for(int WARMUPS = 2; 0 != --WARMUPS; )
	{
		counter.start();

		{ for(int i = 0; i != 1000000; ++i)
		{
			if(0 == (rand() % 4))
			{
				total += stlsoft::truncation_test<sint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::minimum()));
				total += stlsoft::truncation_test<sint16_t>(sint8_t(0));
				total += stlsoft::truncation_test<sint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::maximum()));
			}

			if(0 == (rand() % 4))
			{
				// 1b
				total += stlsoft::truncation_test<sint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::minimum()));
				total += stlsoft::truncation_test<sint16_t>(sint16_t(0));
				total += stlsoft::truncation_test<sint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::maximum()));
			}

			if(0 == (rand() % 4))
			{
				// 1c
				total += stlsoft::truncation_test<sint16_t>(sint64_t(stlsoft::limit_traits<sint64_t>::minimum()));
				total += stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::minimum()));
				total += stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::minimum()));
				total += stlsoft::truncation_test<sint16_t>(sint32_t(0));
				total += stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum()));
				total += stlsoft::truncation_test<sint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::maximum()));
				total += stlsoft::truncation_test<sint16_t>(sint64_t(stlsoft::limit_traits<sint64_t>::maximum()));
			}


			if(0 == (rand() % 4))
			{
				// 2a
				total += stlsoft::truncation_test<sint16_t>(uint8_t(0));
				total += stlsoft::truncation_test<sint16_t>(uint8_t(stlsoft::limit_traits<uint8_t>::maximum()));
			}

			if(0 == (rand() % 4))
			{
				// 2b
				total += stlsoft::truncation_test<sint16_t>(uint16_t(0));
				total += stlsoft::truncation_test<sint16_t>(uint16_t(stlsoft::limit_traits<sint16_t>::maximum()));
				total += stlsoft::truncation_test<sint16_t>(uint16_t(stlsoft::limit_traits<uint16_t>::maximum()));
			}

			if(0 == (rand() % 4))
			{
				// 2c
				total += stlsoft::truncation_test<sint16_t>(uint32_t(0));
				total += stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<sint16_t>::maximum()));
				total += stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<uint16_t>::maximum()));
				total += stlsoft::truncation_test<sint16_t>(uint32_t(stlsoft::limit_traits<uint32_t>::maximum()));
			}


			if(0 == (rand() % 4))
			{
				// 3a
				total += stlsoft::truncation_test<uint16_t>(sint8_t(0));
				total += stlsoft::truncation_test<uint16_t>(sint8_t(stlsoft::limit_traits<sint8_t>::maximum()));
			}

			if(0 == (rand() % 4))
			{
				// 3b
				total += stlsoft::truncation_test<uint16_t>(sint16_t(0));
				total += stlsoft::truncation_test<uint16_t>(sint16_t(stlsoft::limit_traits<sint16_t>::maximum()));
			}

			if(0 == (rand() % 4))
			{
				// 3c
				total += stlsoft::truncation_test<uint16_t>(sint32_t(0));
				total += stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<sint16_t>::maximum()));
				total += stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<uint16_t>::maximum()));
				total += stlsoft::truncation_test<uint16_t>(sint32_t(stlsoft::limit_traits<sint32_t>::maximum()));
			}


			if(0 == (rand() % 4))
			{
				// 4a
				total += stlsoft::truncation_test<uint16_t>(uint8_t(0));
				total += stlsoft::truncation_test<uint16_t>(uint8_t(stlsoft::limit_traits<uint8_t>::maximum()));
			}

			if(0 == (rand() % 4))
			{
				// 4b
				total += stlsoft::truncation_test<uint16_t>(uint16_t(0));
				total += stlsoft::truncation_test<uint16_t>(uint16_t(stlsoft::limit_traits<uint16_t>::maximum()));
			}

				// 4c
			if(0 == (rand() % 4))
			{
				total += stlsoft::truncation_test<uint16_t>(uint32_t(0));
				total += stlsoft::truncation_test<uint16_t>(uint32_t(stlsoft::limit_traits<uint16_t>::maximum()));
				total += stlsoft::truncation_test<uint16_t>(uint32_t(stlsoft::limit_traits<uint32_t>::maximum()));
				total += stlsoft::truncation_test<uint16_t>(uint64_t(stlsoft::limit_traits<uint64_t>::maximum()));
			}
		}}

		counter.stop();
	}}
#if 0
	static_cast<void>(fprintf(stderr, "test_performance: %ldus\n", long(counter.get_microseconds()), total));
#endif /* 0 */
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
