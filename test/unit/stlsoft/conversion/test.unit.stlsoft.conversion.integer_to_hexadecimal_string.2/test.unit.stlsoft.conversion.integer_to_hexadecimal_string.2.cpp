/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.stlsoft.conversion.integer_to_hexadecimal_string.2.cpp
 *
 * Purpose:     Implementation file for the test.unit.stlsoft.conversion.integer_to_hexadecimal_string.2 project.
 *
 * Created:     12th July 2012
 * Updated:     16th July 2012
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
 * Feature selection
 */

//#define _CRT_SECURE_NO_WARNINGS

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <stlsoft/conversion/integer_to_string/integer_to_hexadecimal_string.hpp>
//#include <stlsoft/conversion/integer_to_string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/string/snprintf.h>

/* Standard C Header Files */
#include <stdlib.h>

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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	if(XTESTS_START_RUNNER("test.unit.stlsoft.conversion.integer_to_hexadecimal_string.2", verbosity))
	{
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

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
	}

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

# include <stlsoft/meta/is_signed_type.hpp>
# include <stlsoft/limits/integral_format_width_limits.hpp>
# include <stlsoft/limits/integral_limits.hpp>

namespace stlsoft
{

inline
char const*
integer_to_HEXADECIMAL_string(
	char*		buf
,	ss_size_t	cchBuf
,	int			value
);


template<
	ss_typename_param_k C
>
inline
C*
integer_to_hexadecimal_string_with_prefix_worker_apply_prefix_(
	no_type
,	C*			s
,	C const*	prefix
,	ss_size_t	cchPrefix
)
{
	s -= cchPrefix;
	::memcpy(s, prefix, sizeof(C) * cchPrefix);

	return s;
}

template<
	ss_typename_param_k C
>
inline
C*
integer_to_hexadecimal_string_with_prefix_worker_apply_prefix_(
	yes_type
,	C*			s
,	C const*	prefix
,	ss_size_t	cchPrefix
)
{
	if('-' == *s)
	{
		s -= cchPrefix - 1;
		::memcpy(s, prefix, sizeof(C) * cchPrefix);
		*--s = '-';

		return s;
	}

	return integer_to_hexadecimal_string_with_prefix_worker_apply_prefix_(no_type(), s, prefix, cchPrefix);
}

template<
	ss_typename_param_k C
,	ss_typename_param_k I
>
inline
C const*
integer_to_hexadecimal_string_with_prefix_worker_6_(
	C const*  (*pfn)(C*, ss_size_t, I const&)
,	C*			buf
,	ss_size_t	cchBuf
,	I const&	value
,	C const*	prefix
,	ss_size_t	cchPrefix
)
{
    STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<I>::value);

    STLSOFT_COVER_MARK_LINE();

    typedef integral_format_width_limits<I>     width_traits_t;

    typedef ss_typename_type_k is_signed_type<I>::type signed_yesno_t;

    STLSOFT_ASSERT(cchBuf >= 1 + cchPrefix + width_traits_t::maxHexadecimalWidth);

	C* s = const_cast<C*>(pfn(buf, cchBuf, value));

	s = integer_to_hexadecimal_string_with_prefix_worker_apply_prefix_(signed_yesno_t(), s, prefix, cchPrefix);

	return s;
}

template<
	ss_typename_param_k C
,	ss_typename_param_k I
>
inline
C const*
integer_to_hexadecimal_string_with_prefix_worker_7_(
	C const*  (*pfn)(C*, ss_size_t, I const&/* , ss_size_t* */)
,	C*			buf
,	ss_size_t	cchBuf
,	I const&	value
,	ss_size_t*	numWritten
,	C const*	prefix
,	ss_size_t	cchPrefix
)
{
#if 0
    STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<I>::value);

	STLSOFT_ASSERT(NULL != numWritten);

    STLSOFT_COVER_MARK_LINE();

    typedef integral_format_width_limits<I>     width_traits_t;

    STLSOFT_ASSERT(cchBuf >= 1 + cchPrefix + width_traits_t::maxHexadecimalWidth);

	C* s = const_cast<C*>(pfn(buf, cchBuf, value, numWritten));

	if('-' == *s)
	{
		s -= cchPrefix - 1;
		::memcpy(s, prefix, sizeof(C) * cchPrefix);
		*--s = '-';
	}
	else
	{
		s -= cchPrefix;
		::memcpy(s, prefix, sizeof(C) * cchPrefix);
	}
	*numWritten += cchPrefix;

	return s;
#else /* ? 0 */
    STLSOFT_COVER_MARK_LINE();

	C const* r = integer_to_hexadecimal_string_with_prefix_worker_6_<C, I>(pfn, buf, cchBuf, value, prefix, cchPrefix);

    STLSOFT_COVER_MARK_LINE();

	if(NULL != numWritten)
	{
	    STLSOFT_COVER_MARK_LINE();

        *numWritten = cchBuf - (r - (buf - 1));
	}

    STLSOFT_COVER_MARK_LINE();

	return r;
#endif /* 0 */
}

template<
	ss_typename_param_k C
,	ss_typename_param_k I
>
inline
C const*
integer_to_hexadecimal_string_with_prefix(
	C*			buf
,	ss_size_t	cchBuf
,	I const&	value
)
{
	static C const s_prefix[] = { '0', 'x' };

	C const* (*pfn)(C*,	ss_size_t, I const&) = &stlsoft::integer_to_hexadecimal_string;

	return integer_to_hexadecimal_string_with_prefix_worker_6_<C, I>(pfn, buf, cchBuf, value, s_prefix, STLSOFT_NUM_ELEMENTS(s_prefix));
}

template<
	ss_typename_param_k C
,	ss_typename_param_k I
>
inline
C const*
integer_to_hexadecimal_string_with_prefix(
	C*			buf
,	ss_size_t	cchBuf
,	I const&	value
,	ss_size_t*	numWritten
)
{
	static C const s_prefix[] = { '0', 'x' };

	C const* (*pfn)(C*,	ss_size_t, I const&/* , ss_size_t* */) = &stlsoft::integer_to_hexadecimal_string;

	return integer_to_hexadecimal_string_with_prefix_worker_7_<C, I>(pfn, buf, cchBuf, value, numWritten, s_prefix, STLSOFT_NUM_ELEMENTS(s_prefix));
}














template<
	ss_typename_param_k C
,	ss_size_t			N
>
inline
C*
integer_to_hexadecimal_string_with_fixed_pad_worker_apply_pad_(
	no_type
,	C*			s
,	ss_size_t	len
)
{
	{ for(ss_size_t n = len; n != N; ++n)
	{
		*--s = '0';
	}}

	return s;
}

template<
	ss_typename_param_k C
,	ss_size_t			N
>
inline
C*
integer_to_hexadecimal_string_with_fixed_pad_worker_apply_pad_(
	yes_type
,	C*			s
,	ss_size_t	len
)
{
	if('-' == *s)
	{
		s = integer_to_hexadecimal_string_with_fixed_pad_worker_apply_pad_<C, N>(no_type(), ++s, len - 1);

		*--s = '-';

		return s;
	}

	return integer_to_hexadecimal_string_with_fixed_pad_worker_apply_pad_<C, N>(no_type(), s, len);
}

template<
	ss_typename_param_k C
,	ss_typename_param_k I
>
inline
C const*
integer_to_hexadecimal_string_with_fixed_pad_worker_4_(
	C const*  (*pfn)(C*, ss_size_t, I const&, ss_size_t*)
,	C*			buf
,	ss_size_t	cchBuf
,	I const&	value
)
{
    STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<I>::value);

    STLSOFT_COVER_MARK_LINE();

    typedef integral_format_width_limits<I>     width_traits_t;

    typedef ss_typename_type_k is_signed_type<I>::type signed_yesno_t;

    STLSOFT_ASSERT(cchBuf >= 1 + width_traits_t::maxHexadecimalWidth);

	ss_size_t	n;
	C*			s = const_cast<C*>(pfn(buf, cchBuf, value, &n));

	s = integer_to_hexadecimal_string_with_fixed_pad_worker_apply_pad_<C, width_traits_t::maxHexadecimalWidthWithoutSign>(signed_yesno_t(), s, n);

	return s;
}

template<
	ss_typename_param_k C
,	ss_typename_param_k I
>
inline
C const*
integer_to_hexadecimal_string_with_fixed_pad_worker_5_(
	C const*  (*pfn)(C*, ss_size_t, I const&, ss_size_t*)
,	C*			buf
,	ss_size_t	cchBuf
,	I const&	value
,	ss_size_t*	numWritten
)
{
    STLSOFT_COVER_MARK_LINE();

	C const* r = integer_to_hexadecimal_string_with_fixed_pad_worker_4_<C, I>(pfn, buf, cchBuf, value);

    STLSOFT_COVER_MARK_LINE();

	if(NULL != numWritten)
	{
	    STLSOFT_COVER_MARK_LINE();

        *numWritten = cchBuf - (r - (buf - 1));
	}

    STLSOFT_COVER_MARK_LINE();

	return r;
}

template<
	ss_typename_param_k C
,	ss_typename_param_k I
>
inline
C const*
integer_to_hexadecimal_string_with_fixed_pad(
	C*			buf
,	ss_size_t	cchBuf
,	I const&	value
)
{
	C const* (*pfn)(C*,	ss_size_t, I const&, ss_size_t*) = &stlsoft::integer_to_hexadecimal_string;

	return integer_to_hexadecimal_string_with_fixed_pad_worker_4_<C, I>(pfn, buf, cchBuf, value);
}

template<
	ss_typename_param_k C
,	ss_typename_param_k I
>
inline
C const*
integer_to_hexadecimal_string_with_fixed_pad(
	C*			buf
,	ss_size_t	cchBuf
,	I const&	value
,	ss_size_t*	numWritten
)
{
	C const* (*pfn)(C*,	ss_size_t, I const&, ss_size_t*) = &stlsoft::integer_to_hexadecimal_string;

	return integer_to_hexadecimal_string_with_fixed_pad_worker_5_<C, I>(pfn, buf, cchBuf, value, numWritten);
}


} /* namespace stlsoft */



namespace
{

	using stlsoft::uint16_t;
	using stlsoft::sint32_t;
	using stlsoft::uint32_t;

static void test_1_0()
{
	int const v = 0;

	{
		char				sz[17];
		size_t				n;
		char const* const	s	=	stlsoft::integer_to_hexadecimal_string(sz, STLSOFT_NUM_ELEMENTS(sz), v, &n);

		XTESTS_TEST_INTEGER_EQUAL(1u, n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0", s);
	}

	{
		wchar_t					sz[17];
		size_t					n;
		wchar_t const* const	s	=	stlsoft::integer_to_hexadecimal_string(sz, STLSOFT_NUM_ELEMENTS(sz), v, &n);

		XTESTS_TEST_INTEGER_EQUAL(1u, n);
		XTESTS_TEST_WIDE_STRING_EQUAL(L"0", s);
	}
}

static void test_1_1()
{
	int const v = 0;

	{
		char				sz[19];
		size_t				n;
		char const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_prefix(sz, STLSOFT_NUM_ELEMENTS(sz), v, &n);

		XTESTS_TEST_INTEGER_EQUAL(3u, n);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL("0x0", s);
	}

	{
		wchar_t					sz[19];
		size_t					n;
		wchar_t const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_prefix(sz, STLSOFT_NUM_ELEMENTS(sz), v, &n);

		XTESTS_TEST_INTEGER_EQUAL(3u, n);
		XTESTS_TEST_WIDE_STRING_EQUAL(L"0x0", s);
	}
}

static void test_1_2()
{
	{ for(uint32_t i = 0; ; ++i)
	{
		char				sz1[19];
		char				sz2[19];
		size_t				n1;
		size_t				n2;

		n1 = static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "0x%lx", static_cast<unsigned long>(i)));

		char const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_prefix(sz2, STLSOFT_NUM_ELEMENTS(sz2), i, &n2);

		XTESTS_TEST_INTEGER_EQUAL(n2, n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, s);

		if(stlsoft::integral_limits<uint32_t>::maximum() / 4096 == i)
		{
			break;
		}
	}}
}

static void test_1_3()
{
	{ for(uint32_t i = 0; ; ++i)
	{
		char				sz1[19];
		char				sz2[19];

		static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "0x%lx", static_cast<unsigned long>(i)));

		char const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_prefix(sz2, STLSOFT_NUM_ELEMENTS(sz2), i);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, s);

		if(stlsoft::integral_limits<uint32_t>::maximum() / 4096 == i)
		{
			break;
		}
	}}
}

static void test_1_4()
{
	{ for(uint16_t i = 0; ; ++i)
	{
		sint32_t const		v = -static_cast<sint32_t>(i);
		char				sz1[19];
		char				sz2[19];
		size_t				n1;
		size_t				n2;

		if(0 >= i)
		{
			n1 = static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "0x%lx", static_cast<unsigned long>(i)));
		}
		else
		{
			n1 = static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "-0x%lx", static_cast<unsigned long>(i)));
		}

		char const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_prefix(sz2, STLSOFT_NUM_ELEMENTS(sz2), v, &n2);

		XTESTS_TEST_INTEGER_EQUAL(n2, n1);
		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, s);

		if(stlsoft::integral_limits<uint16_t>::maximum() == i)
		{
			break;
		}
	}}
}

static void test_1_5()
{
	{ for(uint16_t i = 0; ; ++i)
	{
		sint32_t const		v = -static_cast<sint32_t>(i);
		char				sz1[19];
		char				sz2[19];

		if(0 >= i)
		{
			static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "0x%lx", static_cast<unsigned long>(i)));
		}
		else
		{
			static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "-0x%lx", static_cast<unsigned long>(i)));
		}

		char const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_prefix(sz2, STLSOFT_NUM_ELEMENTS(sz2), v);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, s);

		if(stlsoft::integral_limits<uint16_t>::maximum() == i)
		{
			break;
		}
	}}
}

static void test_1_6()
{
}

static void test_1_7()
{
	{ for(uint16_t i = 0; ; ++i)
	{
		uint16_t const		v = static_cast<uint16_t>(i);
		char				sz1[19];
		char				sz2[19];

		if(0 >= i)
		{
			static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "%04lx", static_cast<unsigned long>(i)));
		}
		else
		{
			static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "-%04lx", static_cast<unsigned long>(i)));
		}

		char const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_fixed_pad(sz2, STLSOFT_NUM_ELEMENTS(sz2), v);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, s);

		if(stlsoft::integral_limits<uint16_t>::maximum() == i)
		{
			break;
		}
	}}
}

static void test_1_8()
{
	{ for(uint16_t i = 0; ; ++i)
	{
		sint32_t const		v = -static_cast<sint32_t>(i);
		char				sz1[19];
		char				sz2[19];

		if(0 >= i)
		{
			static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "%08lx", static_cast<unsigned long>(i)));
		}
		else
		{
			static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "-%08lx", static_cast<unsigned long>(i)));
		}

		char const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_fixed_pad(sz2, STLSOFT_NUM_ELEMENTS(sz2), v);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, s);

		if(stlsoft::integral_limits<uint16_t>::maximum() == i)
		{
			break;
		}
	}}

	{ for(uint16_t i = 0; ; ++i)
	{
		sint32_t const		v = -static_cast<sint32_t>(i);
		char				sz1[19];
		char				sz2[19];

		if(0 >= i)
		{
			static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "%08lx", static_cast<unsigned long>(i)));
		}
		else
		{
			static_cast<size_t>(stlsoft::snprintf(sz1, STLSOFT_NUM_ELEMENTS(sz1), "-%08lx", static_cast<unsigned long>(i)));
		}

		size_t				n;
		char const* const	s	=	stlsoft::integer_to_hexadecimal_string_with_fixed_pad(sz2, STLSOFT_NUM_ELEMENTS(sz2), v, &n);

		XTESTS_TEST_MULTIBYTE_STRING_EQUAL(sz1, s);

		if(stlsoft::integral_limits<uint16_t>::maximum() == i)
		{
			break;
		}
	}}
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

static void test_1_12()
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
