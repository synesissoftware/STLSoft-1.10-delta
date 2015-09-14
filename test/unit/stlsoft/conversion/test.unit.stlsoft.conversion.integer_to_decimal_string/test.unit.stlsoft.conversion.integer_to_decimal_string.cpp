/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.conversion.integer_to_decimal_string.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.conversion.integer_to_decimal_string project.
 *
 * Created:     5th July 2012
 * Updated:     11th July 2012
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2012, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

//#define INT64_BY_WORDS_INNER
#define INT64_BY_WORDS_OUTER


#ifdef _MSC_VER
//# pragma warning(disable : 4996)
# define _CRT_SECURE_NO_WARNINGS
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define STLSOFT_ALLOW_OBSOLETE_1_9_IN_1_10
#include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <platformstl/performance/performance_counter.hpp>

#include <stlsoft/traits/integral_printf_format_traits.hpp>
#include <stlsoft/util/rand.hpp>
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

#if 0
/* /////////////////////////////////////////////////////////////////////////
 * STLSoft
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#include <stlsoft/meta/is_integral_type.hpp>
#include <stlsoft/meta/is_signed_type.hpp>
#include <stlsoft/meta/yesno.hpp>
#include <stlsoft/limits/integral_format_width_limits.hpp>
#include <stlsoft/limits/integral_limits.hpp>
#include <stlsoft/util/sign_traits.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Worker functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

	STLSOFT_OPEN_WORKER_NS_(ximpl_I2S)

#ifdef STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS
# define STLSOFT_I2S_D2S_GET_DIGIT_CHARACTER(C)		get_digit_character(static_cast<C*>(0))
#else /* ? STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */
# define STLSOFT_I2S_D2S_GET_DIGIT_CHARACTER(C)		get_digit_character<C>()
#endif /* STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS */

	/* selector traits class for remainder type */
	template <ss_typename_param_k T_Integer>
	struct i2s_remainder_traits_t
	{
#if 0
        typedef T_Integer       remainder_type;
#else
		typedef unsigned int	remainder_type;
#endif
	};

	/* main conversion function (unsigned) */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	unsigned_integer_to_decimal_string(
		C*			buf
	,	ss_size_t	cchBuf
	,	I /* const& */	i
	)
	{
		STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<I>::value);
		STLSOFT_STATIC_ASSERT(0 == stlsoft::is_signed_type<I>::value);

		typedef integral_format_width_limits<I>	    width_traits_t;
		typedef i2s_remainder_traits_t<I>	        remainder_traits_t;

		STLSOFT_ASSERT(cchBuf >= 1 + width_traits_t::maxDecimalWidth);

		C* end = buf + (cchBuf - 1);

		// Whichever we do it, we write the nul-terminator (and move down
		// one)
		*end-- = '\0';

        STLSOFT_COVER_MARK_LINE();

		if(0 == i)
		{
            STLSOFT_COVER_MARK_LINE();

			*end = '0';

			return end;
		}
		else
		{
		    STLSOFT_COVER_MARK_LINE();

#if 1
        C const* const dchars = STLSOFT_I2S_D2S_GET_DIGIT_CHARACTER(C);
#endif /* 0 */

            C* p = end;

			for(;;)
			{
			    STLSOFT_COVER_MARK_LINE();

				ss_typename_type_k remainder_traits_t::remainder_type const rem = i % 10;

#if 1
	            *p = dchars[rem];
#else /* ? 0 */
				*p = STLSOFT_I2S_D2S_GET_DIGIT_CHARACTER(C)[rem];
#endif /* 0 */

				i /= 10;

				if(0 == i)
				{
				    STLSOFT_COVER_MARK_LINE();

					break;
				}
				else
				{
				    STLSOFT_COVER_MARK_LINE();

					--p;
				}
			}

			STLSOFT_COVER_MARK_LINE();

			return p;
		}
	}

	/* secondary conversion function (unsigned) that calculates numWritten */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	unsigned_integer_to_decimal_string(
		C*			buf
	,	ss_size_t	cchBuf
	,	I const&	i
	,	ss_size_t*	numWritten
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		C const* const r = unsigned_integer_to_decimal_string<I, C>(buf, cchBuf, i);

		if(NULL != numWritten)
		{
		    STLSOFT_COVER_MARK_LINE();

			*numWritten = cchBuf - (r - (buf - 1));
		}

	    STLSOFT_COVER_MARK_LINE();

		return r;
	}

#ifdef INT64_BY_WORDS_INNER
	inline
	char const*
	unsigned_integer_to_decimal_string(
		char*		buf
	,	ss_size_t	cchBuf
	,	uint64_t	i
	)
	{
		uint32_t const	high	=	static_cast<uint32_t>(i >> 32);
		uint32_t const	low		=	static_cast<uint32_t>(i >> 0);

		ss_size_t	n;
		char*		s	=	const_cast<char*>(unsigned_integer_to_decimal_string(buf, cchBuf, low, &n));

		if(0 == high)
		{
			return s;
		}
		else
		{
			for(; 8 != n; ++n)
			{
				*--s = '0';
			}

			STLSOFT_ASSERT(8u == n);

			char const	ch = *s;
			ss_size_t	n2;
			char const*	s2 = unsigned_integer_to_decimal_string(buf, cchBuf - 8, high, &n2);

			*s = ch;

			return s2;
		}
	}

	inline
	char const*
	unsigned_integer_to_decimal_string(
		char*		buf
	,	ss_size_t	cchBuf
	,	uint64_t	i
	,	ss_size_t*	numWritten
	)
	{
		uint32_t const	high	=	static_cast<uint32_t>(i >> 32);
		uint32_t const	low		=	static_cast<uint32_t>(i >> 0);

		ss_size_t	n;
		char*		s	=	const_cast<char*>(unsigned_integer_to_decimal_string(buf, cchBuf, low, &n));

		if(0 == high)
		{
			*numWritten = n;

			return s;
		}
		else
		{
#if 0
			switch(n)
			{
				case	1:	*--s = '0';
				case	2:	*--s = '0';
				case	3:	*--s = '0';
				case	4:	*--s = '0';
				case	5:	*--s = '0';
				case	6:	*--s = '0';
				case	7:	*--s = '0';
				case	8:
				break;
			}
			n = 8;
#else
			for(; 8 != n; ++n)
			{
				*--s = '0';
			}
#endif

			STLSOFT_ASSERT(8u == n);

			char const	ch = *s;
			ss_size_t	n2;
			char const*	s2 = unsigned_integer_to_decimal_string(buf, cchBuf - 8, high, &n2);

			*s = ch;

			*numWritten = 8 + n2;

			return s2;
		}
	}
#endif /* INT64_BY_WORDS */

	/* (invalid) generic form of signed-minimum-handler */
	template<
		ss_typename_param_k C
	>
	void
	i2s_handle_signed_minimum_in_decimal_(
		C*			buf
	,	ss_size_t	cchBuf
	,	...
	);

	/* 8-bit form of signed-minimum-handler */
	template<
		ss_typename_param_k C
	>
	inline
	C const*
	i2s_handle_signed_minimum_in_decimal_(
		C*			buf
	,	ss_size_t	cchBuf
	,	ss_sint8_t	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		static C const	s_minimum[] = { '-', '1', '2', '8', '\0' };

		STLSOFT_ASSERT(cchBuf >= STLSOFT_NUM_ELEMENTS(s_minimum));

		C* end	=	buf + cchBuf;
		C* r	=	end - STLSOFT_NUM_ELEMENTS(s_minimum);

		::memcpy(r, s_minimum, sizeof(C) * STLSOFT_NUM_ELEMENTS(s_minimum));

	    STLSOFT_COVER_MARK_LINE();

		return r;
	}

	/* 16-bit form of signed-minimum-handler */
	template<
		ss_typename_param_k C
	>
	inline
	C const*
	i2s_handle_signed_minimum_in_decimal_(
		C*			buf
	,	ss_size_t	cchBuf
	,	ss_sint16_t	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		static C const	s_minimum[] = { '-', '3', '2', '7', '6', '8', '\0' };

		STLSOFT_ASSERT(cchBuf >= STLSOFT_NUM_ELEMENTS(s_minimum));

		C* end	=	buf + cchBuf;
		C* r	=	end - STLSOFT_NUM_ELEMENTS(s_minimum);

		::memcpy(r, s_minimum, sizeof(C) * STLSOFT_NUM_ELEMENTS(s_minimum));

	    STLSOFT_COVER_MARK_LINE();

		return r;
	}

	/* 32-bit form of signed-minimum-handler */
	template<
		ss_typename_param_k C
	>
	inline
	C const*
	i2s_handle_signed_minimum_in_decimal_(
		C*			buf
	,	ss_size_t	cchBuf
	,	ss_sint32_t	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		static C const	s_minimum[] = { '-', '2', '1', '4', '7', '4', '8', '3', '6', '4', '8', '\0' };

		STLSOFT_ASSERT(cchBuf >= STLSOFT_NUM_ELEMENTS(s_minimum));

		C* end	=	buf + cchBuf;
		C* r	=	end - STLSOFT_NUM_ELEMENTS(s_minimum);

		::memcpy(r, s_minimum, sizeof(C) * STLSOFT_NUM_ELEMENTS(s_minimum));

	    STLSOFT_COVER_MARK_LINE();

		return r;
	}

	/* 64-bit form of signed-minimum-handler */
	template<
		ss_typename_param_k C
	>
	inline
	C const*
	i2s_handle_signed_minimum_in_decimal_(
		C*			buf
	,	ss_size_t	cchBuf
	,	ss_sint64_t	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		static C const	s_minimum[] = { '-', '9', '2', '2', '3', '3', '7', '2', '0', '3', '6', '8', '5', '4', '7', '7', '5', '8', '0', '8', '\0' };

		STLSOFT_ASSERT(cchBuf >= STLSOFT_NUM_ELEMENTS(s_minimum));

		C* end	=	buf + cchBuf;
		C* r	=	end - STLSOFT_NUM_ELEMENTS(s_minimum);

		::memcpy(r, s_minimum, sizeof(C) * STLSOFT_NUM_ELEMENTS(s_minimum));

	    STLSOFT_COVER_MARK_LINE();

		return r;
	}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
	/* distinct 'int' form of signed-minimum-handler */
	template<
		ss_typename_param_k C
	>
	inline
	C const*
	i2s_handle_signed_minimum_in_decimal_(
		C*			buf
	,	ss_size_t	cchBuf
	,	int			i
	)
	{
		typedef ss_typename_type_k sign_traits<int>::signed_type	signed_t;

	    STLSOFT_COVER_MARK_LINE();

		return i2s_handle_signed_minimum_in_decimal_(buf, cchBuf, signed_t(i));
	}
#endif /* !STLSOFT_CF_INT_DISTINCT_INT_TYPE */

	/* secondary conversion function (signed), implemented in terms of unsigned version */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	signed_integer_to_decimal_string(
		C*			buf
	,	ss_size_t	cchBuf
	,	I /* const& */	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<I>::value);
		STLSOFT_STATIC_ASSERT(0 != stlsoft::is_signed_type<I>::value);

		typedef integral_format_width_limits<I>	    width_traits_t;
		typedef i2s_remainder_traits_t<I>	        remainder_traits_t;
	    typedef limit_traits<I>						limit_traits_t;

		STLSOFT_ASSERT(cchBuf >= 1 + width_traits_t::maxDecimalWidth);

		typedef sign_traits<I>::unsigned_type	unsigned_t;

		if(i < 0)
		{
		    STLSOFT_COVER_MARK_LINE();

			if(i == limit_traits_t::minimum())
			{
			    STLSOFT_COVER_MARK_LINE();

				return i2s_handle_signed_minimum_in_decimal_(buf, cchBuf, i);
			}
			else
			{
			    STLSOFT_COVER_MARK_LINE();

				C const* r2 = unsigned_integer_to_decimal_string(buf, cchBuf, unsigned_t(-i));

		        *const_cast<C*>(--r2) = C('-');

			    STLSOFT_COVER_MARK_LINE();

				return r2;
			}
		}
		else
		{
		    STLSOFT_COVER_MARK_LINE();

			return unsigned_integer_to_decimal_string(buf, cchBuf, unsigned_t(i));
		}
	}

	/* secondary conversion function (signed) that calculates numWritten */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	signed_integer_to_decimal_string(
		C*			buf
	,	ss_size_t	cchBuf
	,	I const&	i
	,	ss_size_t*	numWritten
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		C const* const r = signed_integer_to_decimal_string<I, C>(buf, cchBuf, i);

		if(NULL != numWritten)
		{
		    STLSOFT_COVER_MARK_LINE();

			*numWritten = cchBuf - (r - (buf - 1));
		}

	    STLSOFT_COVER_MARK_LINE();

		return r;
	}

	/* TMP compile-time selector of unsigned/signed work function */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	integer_to_decimal_string_if_signed_(
		yes_type
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	i
	,	ss_size_t*	numWritten
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		return signed_integer_to_decimal_string(buf, cchBuf, i, numWritten);
	}

	/* TMP compile-time selector of unsigned/signed work function */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	integer_to_decimal_string_if_signed_(
		no_type
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	i
	,	ss_size_t*	numWritten
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		return unsigned_integer_to_decimal_string(buf, cchBuf, i, numWritten);
	}

	/* TMP compile-time selector of unsigned/signed work function */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	integer_to_decimal_string_if_signed_(
		yes_type
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		return signed_integer_to_decimal_string(buf, cchBuf, i);
	}

	/* TMP compile-time selector of unsigned/signed work function */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	integer_to_decimal_string_if_signed_(
		no_type
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		return unsigned_integer_to_decimal_string(buf, cchBuf, i);
	}

	STLSOFT_CLOSE_WORKER_NS_(ximpl_I2S)

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    /* /////////////////////////////////////////////////////////////////////////
     * API functions
     */

/** Converts an integer value into a decimal string representation in the
 * given character buffer.
 *
 */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	integer_to_decimal_string(
		C*			buf
	,	ss_size_t	cchBuf
	,	I const&	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		typedef ss_typename_type_k is_signed_type<I>::type	signed_yesno_t;

		return STLSOFT_WORKER_NS_QUAL_(ximpl_I2S, integer_to_decimal_string_if_signed_)(signed_yesno_t(), buf, cchBuf, i);
	}

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
/** Converts an integer value into a decimal string representation in the
 * given character buffer.
 *
 */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
    ,   ss_size_t           N
	>
	inline
	C const*
	integer_to_decimal_string(
		C			(&ar)[N]
	,	I const&	i
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		typedef integral_format_width_limits<I> width_traits_t;

		STLSOFT_STATIC_ASSERT(N >= 1 + width_traits_t::maxDecimalWidth);

	    STLSOFT_COVER_MARK_LINE();

        return integer_to_decimal_string(&ar[0], N, i);
    }
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

/** Converts an integer value into a decimal string representation in the
 * given character buffer, assigning the number of characters (excluding
 * the nul-terminator) written into the given size variable.
 *
 */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
	>
	inline
	C const*
	integer_to_decimal_string(
		C*			buf
	,	ss_size_t	cchBuf
	,	I const&	i
	,	ss_size_t*	numWritten
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		typedef ss_typename_type_k is_signed_type<I>::type	signed_yesno_t;

		return STLSOFT_WORKER_NS_QUAL_(ximpl_I2S, integer_to_decimal_string_if_signed_)(signed_yesno_t(), buf, cchBuf, i, numWritten);
	}

#ifdef INT64_BY_WORDS_OUTER
	inline
	char const*
	integer_to_decimal_string(
		char*		buf
	,	ss_size_t	cchBuf
	,	uint64_t	i
	,	ss_size_t*	numWritten
	)
	{
        STLSOFT_COVER_MARK_LINE();

		uint32_t const high = static_cast<uint32_t>(i >> 32);

		if(0 == high)
		{
            STLSOFT_COVER_MARK_LINE();

    		uint32_t const low = static_cast<uint32_t>(i >> 0);

	        return STLSOFT_WORKER_NS_QUAL_(ximpl_I2S, unsigned_integer_to_decimal_string)(buf, cchBuf, low, numWritten);
		}
		else
		{
	        STLSOFT_COVER_MARK_LINE();

	        return STLSOFT_WORKER_NS_QUAL_(ximpl_I2S, unsigned_integer_to_decimal_string)(buf, cchBuf, i, numWritten);
		}
	}
#endif /* INT64_BY_WORDS */

#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
/** Converts an integer value into a decimal string representation in the
 * given character buffer, assigning the number of characters (excluding
 * the nul-terminator) written into the given size variable.
 *
 */
	template<
		ss_typename_param_k	I
	,	ss_typename_param_k C
    ,   ss_size_t           N
	>
	inline
	C const*
	integer_to_decimal_string(
		C			(&ar)[N]
	,	I const&	i
	,	ss_size_t*	numWritten
	)
	{
	    STLSOFT_COVER_MARK_LINE();

		typedef integral_format_width_limits<I> width_traits_t;

		STLSOFT_STATIC_ASSERT(N >= 1 + width_traits_t::maxDecimalWidth);

        return integer_to_decimal_string(&ar[0], N, i, numWritten);
    }
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* _STLSOFT_NO_NAMESPACE */

#endif /* 0 */
/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

	static void test_1_0(void);
	static void test_1_1(void);
	static void test_1_2(void);
	static void test_1_3(void);
	static void test_1_4(void);
	static void test_1_5(void);
	static void test_1_6(void);
	static void test_1_7(void);
	static void test_1_8(void);
	static void test_1_9(void);
	static void test_1_10(void);
	static void test_1_11(void);
	static void test_1_12(void);
	static void test_1_13(void);
	static void test_1_14(void);
	static void test_1_15(void);
	static void test_1_16(void);
	static void test_1_17(void);
	static void test_1_18(void);
	static void test_1_19(void);
	static void test_1_20(void);
	static void test_1_21(void);
	static void test_1_22(void);
	static void test_1_23(void);
	static void test_1_24(void);
	static void test_1_25(void);
	static void test_1_26(void);
	static void test_1_27(void);
	static void test_1_28(void);
	static void test_1_29(void);
	static void test_1_30(void);
	static void test_1_31(void);
	static void test_1_32(void);
	static void test_1_33(void);
	static void test_1_34(void);
	static void test_1_35(void);
	static void test_1_36(void);
	static void test_1_37(void);
	static void test_1_38(void);
	static void test_1_39(void);
	static void test_1_40(void);
	static void test_1_41(void);
	static void test_1_42(void);
	static void test_1_43(void);
	static void test_1_44(void);
	static void test_1_45(void);
	static void test_1_46(void);
	static void test_1_47(void);
	static void test_1_48(void);
	static void test_1_49(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    platformstl::performance_counter    timer;

    timer.start();

	if(XTESTS_START_RUNNER("test.unit.stlsoft.conversion.integer_to_decimal_string", verbosity))
	{
#ifdef _DEBUG
		XTESTS_RUN_CASE(test_1_48);
#endif /* _DEBUG */

		XTESTS_RUN_CASE(test_1_0);
		XTESTS_RUN_CASE(test_1_1);
		XTESTS_RUN_CASE(test_1_2);
		XTESTS_RUN_CASE(test_1_3);
		XTESTS_RUN_CASE(test_1_4);
		XTESTS_RUN_CASE(test_1_5);
		XTESTS_RUN_CASE(test_1_6);
		XTESTS_RUN_CASE(test_1_7);
		XTESTS_RUN_CASE(test_1_8);
		XTESTS_RUN_CASE(test_1_9);
		XTESTS_RUN_CASE(test_1_10);
		XTESTS_RUN_CASE(test_1_11);
		XTESTS_RUN_CASE(test_1_12);
		XTESTS_RUN_CASE(test_1_13);
		XTESTS_RUN_CASE(test_1_14);
		XTESTS_RUN_CASE(test_1_15);
		XTESTS_RUN_CASE(test_1_16);
		XTESTS_RUN_CASE(test_1_17);
		XTESTS_RUN_CASE(test_1_18);
		XTESTS_RUN_CASE(test_1_19);
		XTESTS_RUN_CASE(test_1_20);
		XTESTS_RUN_CASE(test_1_21);
		XTESTS_RUN_CASE(test_1_22);
		XTESTS_RUN_CASE(test_1_23);
		XTESTS_RUN_CASE(test_1_24);
		XTESTS_RUN_CASE(test_1_25);
		XTESTS_RUN_CASE(test_1_26);
		XTESTS_RUN_CASE(test_1_27);
		XTESTS_RUN_CASE(test_1_28);
		XTESTS_RUN_CASE(test_1_29);
		XTESTS_RUN_CASE(test_1_30);
		XTESTS_RUN_CASE(test_1_31);
		XTESTS_RUN_CASE(test_1_32);
		XTESTS_RUN_CASE(test_1_33);
		XTESTS_RUN_CASE(test_1_34);
		XTESTS_RUN_CASE(test_1_35);
		XTESTS_RUN_CASE(test_1_36);
		XTESTS_RUN_CASE(test_1_37);
		XTESTS_RUN_CASE(test_1_38);
		XTESTS_RUN_CASE(test_1_39);
		XTESTS_RUN_CASE(test_1_40);
		XTESTS_RUN_CASE(test_1_41);
		XTESTS_RUN_CASE(test_1_42);
		XTESTS_RUN_CASE(test_1_43);
		XTESTS_RUN_CASE(test_1_44);
		XTESTS_RUN_CASE(test_1_45);
		XTESTS_RUN_CASE(test_1_46);
		XTESTS_RUN_CASE(test_1_47);
		XTESTS_RUN_CASE(test_1_48);
		XTESTS_RUN_CASE(test_1_49);

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
	}

    timer.stop();

    platformstl::performance_counter::interval_type t = timer.get_microseconds();

    printf("T: %I64d us\n", t);

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{

	template <typename I>
	struct item
	{
		I			value;
		char const*	result;
	};


static void test_1_0()
{
	char		buf[21];
	char const*	s;
	int			v = 0;
	size_t		n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(1u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", s);
}

static void test_1_1()
{
	char		buf[21];
	char const*	s;
	int			v = 012;
	size_t		n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(2u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("10", s);
}

static void test_1_2()
{
	char		buf[21];
	char const*	s;
	int			v = 0177;
	size_t		n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(3u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("127", s);
}

static void test_1_3()
{
	char		buf[21];
	char const*	s;
	int			v = 077;
	size_t		n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(2u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("63", s);
}

static void test_1_4()
{
#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
	char		buf[21];
	char const*	s;
	int			v = 077;
	size_t		n;

	s = stlsoft::integer_to_decimal_string(buf, v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(2u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("63", s);
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
}

static void test_1_5()
{
	char				buf[4];
	char const*			s;
	stlsoft::uint8_t	v = 077;
	size_t				n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(2u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("63", s);
}

static void test_1_6()
{
	char				buf[5];
	char const*			s;
	stlsoft::sint8_t	v = -07;
	size_t				n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(2u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-7", s);
}

static void test_1_7()
{
	char				buf[7];
	char const*			s;
	stlsoft::sint16_t	v = -07;
	size_t				n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(2u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-7", s);
}

static void test_1_8()
{
	char				buf[12];
	char const*			s;
	stlsoft::sint32_t	v = -07;
	size_t				n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(2u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-7", s);
}

static void test_1_9()
{
	char				buf[21];
	char const*			s;
	stlsoft::sint64_t	v = -07;
	size_t				n;

	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), v, &n);

	XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
	XTESTS_TEST_INTEGER_EQUAL(2u, n);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("-7", s);
}

static void test_1_10()
{
	static item<stlsoft::uint8_t> const	items[] =
	{
		{	0,			"0"					},
		{	1,			"1"					},
		{	10,			"10"				},
		{	0177,		"127"				},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		buf[4];
		size_t		n;
		char const*	s = stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), items[i].value, &n);

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(items[i].result), n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_11()
{
	static item<stlsoft::sint8_t> const	items[] =
	{
		{	(stlsoft::sint8_t)0x80, "-128"  },
		{	-100,			        "-100"	},
		{	-1,				        "-1"	},
		{	0,				        "0"		},
		{	01,				        "1"		},
		{	10,			            "10"	},
		{	0177,		            "127"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		buf[5];
		size_t		n;
		char const*	s = stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), items[i].value, &n);

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(items[i].result), n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_12()
{
	static item<stlsoft::uint16_t> const	items[] =
	{
		{	0,				"0"					},
		{	01,				"1"					},
		{	10,				"10"				},
		{	0177,			"127"				},
		{	017777,			"8191"				},
		{	64000,			"64000"				},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		buf[6];
		size_t		n;
		char const*	s = stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), items[i].value, &n);

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(items[i].result), n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_13()
{
	static item<stlsoft::sint16_t> const	items[] =
	{
		{	(stlsoft::sint16_t)0x8000,  "-32768"	},
		{	-10000,			            "-10000"	},
		{	-100,			            "-100"	    },
		{	-1,							"-1"		},
		{	0,							"0"			},
		{	01,							"1"			},
		{	10,							"10"		},
		{	0177,						"127"		},
		{	017777,						"8191"		},
		{	32000,						"32000"		},
        {   (stlsoft::sint16_t)0x7fff,	"32767"		},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		buf[7];
		size_t		n;
		char const*	s = stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), items[i].value, &n);

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(items[i].result), n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_14()
{
	static item<stlsoft::uint32_t> const	items[] =
	{
		{	0,				"0"				},
		{	01,				"1"				},
		{	10,				"10"			},
		{	0177,			"127"			},
		{	017777,			"8191"			},
		{	64000,			"64000"			},
		{	1000000000,		"1000000000"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		buf[11];
		size_t		n;
		char const*	s = stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), items[i].value, &n);

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(items[i].result), n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_15()
{
	static item<stlsoft::sint32_t> const	items[] =
	{
        {   (stlsoft::sint32_t)0x80000000,	"-2147483648"	},
		{	-100000000,						"-100000000"	},
		{	-1000000,						"-1000000"		},
		{	-10000,							"-10000"		},
		{	-100,							"-100"			},
		{	-1,								"-1"			},
		{	0,								"0"				},
		{	01,								"1"				},
		{	10,								"10"			},
		{	0177,							"127"			},
		{	017777,							"8191"			},
		{	32000,							"32000"			},
		{	64000,							"64000"			},
		{	1000000000,						"1000000000"	},
        {   (stlsoft::sint32_t)0x7fffffff,	"2147483647",	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		buf[12];
		size_t		n;
		char const*	s = stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), items[i].value, &n);

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(items[i].result), n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_16()
{
	static item<stlsoft::uint64_t> const	items[] =
	{
		{	0,										"0"						},
		{	01,										"1"						},
		{	10,										"10"					},
		{	0177,									"127"					},
		{	017777,									"8191"					},
		{	64000,									"64000"					},
		{	1000000000,								"1000000000"			},
        {   (stlsoft::uint64_t)0x7fffffffffffffff,	"9223372036854775807"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		buf[21];
		size_t		n;
		char const*	s = stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), items[i].value, &n);

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(items[i].result), n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_17()
{
	static item<stlsoft::sint64_t> const	items[] =
	{
        {   (stlsoft::sint64_t)0x8000000000000000,	"-9223372036854775808", },
		{	-100000000,								"-100000000"			},
		{	-1000000,								"-1000000"				},
		{	-10000,									"-10000"				},
		{	-100,									"-100"					},
		{	-1,										"-1"					},
		{	0,										"0"						},
		{	01,										"1"						},
		{	10,										"10"					},
		{	0177,									"127"					},
		{	017777,									"8191"					},
		{	32000,									"32000"					},
		{	64000,									"64000"					},
		{	1000000000,								"1000000000"			},
        {   (stlsoft::sint64_t)0x7fffffffffffffff,	"9223372036854775807"	},
	};

	{ for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(items); ++i)
	{
		char		buf[21];
		size_t		n;
		char const*	s = stlsoft::integer_to_decimal_string(buf, STLSOFT_NUM_ELEMENTS(buf), items[i].value, &n);

		XTESTS_TEST_POINTER_NOT_EQUAL(NULL, s);
		XTESTS_TEST_INTEGER_EQUAL(::strlen(items[i].result), n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(items[i].result, s);
	}}
}

static void test_1_18()
{
}

static void test_1_19()
{
}

static void test_1_20()
{
	//typedef int integer_t;

	//char const* const	fmt = stlsoft::integral_printf_format_traits<integer_t>::decimal_format_a();

	//::srand(1);

	//{ for(size_t i = 0; i != 1000000; ++i)
	//{
	//	char			buf0[21];
	//	char			buf1[21];

	//	integer_t const	v	=	stlsoft::rand<integer_t>();

	//	int const		n0	=	::sprintf(buf0, fmt, v);

	//	size_t			n1;
	//	char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

	//	XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
	//	XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	//}}
}

static void test_1_21()
{
	typedef unsigned int integer_t;

	char const* const	fmt = stlsoft::integral_printf_format_traits<integer_t>::decimal_format_a();

	::srand(1);

	{ for(size_t i = 0; i != 1000000; ++i)
	{
		char			buf0[21];
		char			buf1[21];

		integer_t const	v	=	stlsoft::rand<integer_t>();

		int const		n0	=	::sprintf(buf0, fmt, v);

		size_t			n1;
		char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

		XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	}}
}

static void test_1_22()
{
	//typedef stlsoft::sint64_t integer_t;

	//char const* const	fmt = stlsoft::integral_printf_format_traits<integer_t>::decimal_format_a();

	//::srand(1);

	//{ for(size_t i = 0; i != 1000000; ++i)
	//{
	//	char			buf0[21];
	//	char			buf1[21];

	//	integer_t const	v	=	stlsoft::rand<integer_t>();

	//	int const		n0	=	::sprintf(buf0, fmt, v);

	//	size_t			n1;
	//	char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

	//	XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
	//	XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	//}}
}

static void test_1_23()
{
	typedef stlsoft::uint64_t integer_t;

	char const* const	fmt = stlsoft::integral_printf_format_traits<integer_t>::decimal_format_a();

	::srand(1);

	{ for(size_t i = 0; i != 1000000; ++i)
	{
		char			buf0[21];
		char			buf1[21];

		integer_t const	v	=	stlsoft::rand<integer_t>();

		int const		n0	=	::sprintf(buf0, fmt, v);

		size_t			n1;
		char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

		XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	}}
}

static void test_1_24()
{
}

static void test_1_25()
{
	typedef stlsoft::uint32_t integer_t;

	char const* const	fmt = stlsoft::integral_printf_format_traits<integer_t>::decimal_format_a();

	::srand(1);

	{ for(size_t i = 0; i != 1000000; ++i)
	{
		char			buf0[21];
		char			buf1[21];

		integer_t const	v	=	stlsoft::rand<integer_t>();

		int const		n0	=	::sprintf(buf0, fmt, v);

		size_t			n1;
		char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

		XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	}}
}

static void test_1_26()
{
}

static void test_1_27()
{
	typedef stlsoft::uint16_t integer_t;

	char const* const	fmt = stlsoft::integral_printf_format_traits<integer_t>::decimal_format_a();

	::srand(1);

	{ for(size_t i = 0; i != 100000; ++i)
	{
		char			buf0[21];
		char			buf1[21];

		integer_t const	v	=	stlsoft::rand<integer_t>();

		int const		n0	=	::sprintf(buf0, fmt, v);

		size_t			n1;
		char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

		XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	}}

	{ for(size_t i = 0; i != 100000; ++i)
	{
		char			buf0[21];
		char			buf1[21];

		integer_t const	v	=	static_cast<integer_t>(i);

		int const		n0	=	::sprintf(buf0, fmt, v);

		size_t			n1;
		char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

		XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	}}
}

static void test_1_28()
{
}

static void test_1_29()
{
	typedef stlsoft::uint8_t integer_t;

	char const* const	fmt = stlsoft::integral_printf_format_traits<integer_t>::decimal_format_a();

	::srand(1);

	{ for(size_t i = 0; i != 10000; ++i)
	{
		char			buf0[21];
		char			buf1[21];

		integer_t const	v	=	stlsoft::rand<integer_t>();

		int const		n0	=	::sprintf(buf0, fmt, v);

		size_t			n1;
		char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

		XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	}}

	{ for(size_t i = 0; i != 100000; ++i)
	{
		char			buf0[21];
		char			buf1[21];

		integer_t const	v	=	static_cast<integer_t>(i);

		int const		n0	=	::sprintf(buf0, fmt, v);

		size_t			n1;
		char const*		s	=	stlsoft::integer_to_decimal_string(&buf1[0], STLSOFT_NUM_ELEMENTS(buf1), v, &n1);

		XTESTS_TEST_INTEGER_EQUAL(size_t(n0), n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(buf0, s);
	}}
}

static void test_1_30()
{
}

static void test_1_31()
{
}

static void test_1_32()
{
}

static void test_1_33()
{
}

static void test_1_34()
{
}

static void test_1_35()
{
}

static void test_1_36()
{
}

static void test_1_37()
{
}

static void test_1_38()
{
}

static void test_1_39()
{
}

static void test_1_40()
{
    typedef int                         integer_t;

	platformstl::performance_counter	timer;

#ifdef _DEBUG
	size_t const N = 1;
#else /* ? _DEBUG */
	size_t const N = 1000000;
#endif /* _DEBUG */

	// 1. int - 1 million random

	fprintf(
		stderr
	,	"%s:\n"
    ,   typeid(integer_t).name()
	);

	size_t r = 0;

	// rand

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::rand<integer_t>(), &n);

			if(NULL != s)
			{
                r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu random in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0 - 999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i + 1000000000

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i) + 1000000000, &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (1000000000 - 1000999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// 0

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(0), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// min<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (min<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// max<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::maximum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (max<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);

    fputs("\n", stderr);
}

static void test_1_41()
{
    typedef unsigned                    integer_t;

	platformstl::performance_counter	timer;

#ifdef _DEBUG
	size_t const N = 1;
#else /* ? _DEBUG */
	size_t const N = 1000000;
#endif /* _DEBUG */

	// 1. int - 1 million random

	fprintf(
		stderr
	,	"%s:\n"
    ,   typeid(integer_t).name()
	);

	size_t r = 0;

	// rand

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::rand<integer_t>(), &n);

			if(NULL != s)
			{
                r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu random in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0 - 999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i + 1000000000

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i) + 1000000000, &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (1000000000 - 1000999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// 0

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(0), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// min<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (min<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// max<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::maximum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (max<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);

    fputs("\n", stderr);
}

static void test_1_42()
{
    typedef stlsoft::uint64_t           integer_t;

	platformstl::performance_counter	timer;

#ifdef _DEBUG
	size_t const N = 1;
#else /* ? _DEBUG */
	size_t const N = 1000000;
#endif /* _DEBUG */

	// 1. int - 1 million random

	fprintf(
		stderr
	,	"%s:\n"
    ,   typeid(integer_t).name()
	);

	size_t r = 0;

	// rand

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::rand<integer_t>(), &n);

			if(NULL != s)
			{
                r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu random in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0 - 999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i + 1000000000

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i) + 1000000000, &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (1000000000 - 1000999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// 0

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(0), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// min<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (min<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// max<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::maximum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (max<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);

    fputs("\n", stderr);
}

static void test_1_43()
{
    typedef stlsoft::uint16_t           integer_t;

	platformstl::performance_counter	timer;

#ifdef _DEBUG
	size_t const N = 1;
#else /* ? _DEBUG */
	size_t const N = 1000000;
#endif /* _DEBUG */

	// 1. int - 1 million random

	fprintf(
		stderr
	,	"%s:\n"
    ,   typeid(integer_t).name()
	);

	size_t r = 0;

	// rand

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::rand<integer_t>(), &n);

			if(NULL != s)
			{
                r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu random in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0 - 999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i + 1000000000

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i) + 1000000000, &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (1000000000 - 1000999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// 0

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(0), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// min<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (min<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// max<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::maximum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (max<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);

    fputs("\n", stderr);
}

static void test_1_44()
{
    typedef stlsoft::uint8_t            integer_t;

	platformstl::performance_counter	timer;

#ifdef _DEBUG
	size_t const N = 1;
#else /* ? _DEBUG */
	size_t const N = 1000000;
#endif /* _DEBUG */

	// 1. int - 1 million random

	fprintf(
		stderr
	,	"%s:\n"
    ,   typeid(integer_t).name()
	);

	size_t r = 0;

	// rand

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::rand<integer_t>(), &n);

			if(NULL != s)
			{
                r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu random in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0 - 999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i + 1000000000

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i) + 1000000000, &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (1000000000 - 1000999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// 0

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(0), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// min<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (min<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// max<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::maximum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (max<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);

    fputs("\n", stderr);
}

static void test_1_45()
{
    typedef stlsoft::sint8_t            integer_t;

	platformstl::performance_counter	timer;

#ifdef _DEBUG
	size_t const N = 1;
#else /* ? _DEBUG */
	size_t const N = 1000000;
#endif /* _DEBUG */

	// 1. int - 1 million random

	fprintf(
		stderr
	,	"%s:\n"
    ,   typeid(integer_t).name()
	);

	size_t r = 0;

	// rand

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::rand<integer_t>(), &n);

			if(NULL != s)
			{
                r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu random in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0 - 999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i + 1000000000

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i) + 1000000000, &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (1000000000 - 1000999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// 0

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(0), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// min<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (min<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// max<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::maximum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (max<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);

    fputs("\n", stderr);
}

static void test_1_46()
{
    typedef stlsoft::uint16_t           integer_t;

	platformstl::performance_counter	timer;

#ifdef _DEBUG
	size_t const N = 1;
#else /* ? _DEBUG */
	size_t const N = 1000000;
#endif /* _DEBUG */

	// 1. int - 1 million random

	fprintf(
		stderr
	,	"%s:\n"
    ,   typeid(integer_t).name()
	);

	size_t r = 0;

	// rand

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::rand<integer_t>(), &n);

			if(NULL != s)
			{
                r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu random in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0 - 999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// i + 1000000000

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(i) + 1000000000, &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (1000000000 - 1000999999) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// 0

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), integer_t(0), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (0) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// min<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (min<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);


	// max<integer_t>

	{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
	{
		::srand(123);

		timer.start();

		{ for(size_t i = 0; i != N; ++i)
		{
			char		buf[21];
			size_t		n;
			char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::maximum(), &n);

			if(NULL != s)
			{
				r += n;
				r ^= n;
                r ^= s[0];
                if(n > 1)
                {
                    r ^= s[1];
                }
			}
		}}

		timer.stop();
	}}

	fprintf(
		stderr
	,	"\t%lu (max<%s>) in %lu ms (%lu)\n"
    ,   static_cast<unsigned long>(N)
    ,   typeid(integer_t).name()
	,	static_cast<unsigned long>(timer.get_milliseconds())
	,	static_cast<unsigned long>(r)
	);

    fputs("\n", stderr);
}

static void test_1_47()
{
}

static void test_1_48()
{
#ifdef _DEBUG
	size_t const N = 1;
#else /* ? _DEBUG */
	size_t const N = 10000000;
#endif /* _DEBUG */

	fputs("signed minima\n", stderr);

	platformstl::performance_counter	timer;

	size_t r = 0;

	{
		typedef stlsoft::sint8_t integer_t;

		{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
		{
			timer.start();

			{ for(size_t i = 0; i != N; ++i)
			{
				char		buf[21];
				size_t		n;
				char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

				if(NULL != s)
				{
					r += n;
					r ^= n;
					r ^= s[0];
					if(n > 1)
					{
						r ^= s[1];
					}
				}
			}}

			timer.stop();
		}}

		fprintf(
			stderr
		,	"\t%lu (min<%s>) in %lu us (%lu)\n"
		,	static_cast<unsigned long>(N)
		,   typeid(integer_t).name()
		,	static_cast<unsigned long>(timer.get_microseconds())
		,	static_cast<unsigned long>(r)
		);
	}

	{
		typedef stlsoft::sint16_t integer_t;

		{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
		{
			timer.start();

			{ for(size_t i = 0; i != N; ++i)
			{
				char		buf[21];
				size_t		n;
				char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

				if(NULL != s)
				{
					r += n;
					r ^= n;
					r ^= s[0];
					if(n > 1)
					{
						r ^= s[1];
					}
				}
			}}

			timer.stop();
		}}

		fprintf(
			stderr
		,	"\t%lu (min<%s>) in %lu us (%lu)\n"
		,	static_cast<unsigned long>(N)
		,   typeid(integer_t).name()
		,	static_cast<unsigned long>(timer.get_microseconds())
		,	static_cast<unsigned long>(r)
		);
	}

	{
		typedef stlsoft::sint32_t integer_t;

		{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
		{
			timer.start();

			{ for(size_t i = 0; i != N; ++i)
			{
				char		buf[21];
				size_t		n;
				char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

				if(NULL != s)
				{
					r += n;
					r ^= n;
					r ^= s[0];
					if(n > 1)
					{
						r ^= s[1];
					}
				}
			}}

			timer.stop();
		}}

		fprintf(
			stderr
		,	"\t%lu (min<%s>) in %lu us (%lu)\n"
		,	static_cast<unsigned long>(N)
		,   typeid(integer_t).name()
		,	static_cast<unsigned long>(timer.get_microseconds())
		,	static_cast<unsigned long>(r)
		);
	}

	{
		typedef stlsoft::sint64_t integer_t;

		{ for(size_t WARMUPS = 2; 0 != WARMUPS; --WARMUPS)
		{
			timer.start();

			{ for(size_t i = 0; i != N; ++i)
			{
				char		buf[21];
				size_t		n;
				char const*	s = stlsoft::integer_to_decimal_string(&buf[0], STLSOFT_NUM_ELEMENTS(buf), stlsoft::limit_traits<integer_t>::minimum(), &n);

				if(NULL != s)
				{
					r += n;
					r ^= n;
					r ^= s[0];
					if(n > 1)
					{
						r ^= s[1];
					}
				}
			}}

			timer.stop();
		}}

		fprintf(
			stderr
		,	"\t%lu (min<%s>) in %lu us (%lu)\n"
		,	static_cast<unsigned long>(N)
		,   typeid(integer_t).name()
		,	static_cast<unsigned long>(timer.get_microseconds())
		,	static_cast<unsigned long>(r)
		);
	}

	fputs("\n", stderr);
}

static void test_1_49()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
