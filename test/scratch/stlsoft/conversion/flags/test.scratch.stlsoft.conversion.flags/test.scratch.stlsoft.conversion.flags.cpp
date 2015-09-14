/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.stlsoft.conversion.flags.cpp
 *
 * Purpose:     Implementation file for the test.scratch.stlsoft.conversion.flags project.
 *
 * Created:     21st July 2012
 * Updated:     2nd September 2012
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
 * Includes
 */

/* STLSoft Header Files */
#include <stlsoft/conversion/conversion_flags.hpp>
//#include <stlsoft/conversion/integer_to_string/integer_to_binary_string.hpp>
#include <stlsoft/conversion/integer_to_string/integer_to_octal_string.hpp>
#include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>
#include <stlsoft/conversion/integer_to_string/integer_to_hexadecimal_string.hpp>
#include <stlsoft/conversion/integer_to_string/integer_to_lc_string.hpp>
#include <stlsoft/error/error_desc.hpp>
#include <stlsoft/util/dimensionof.h>

/* Standard C++ Header Files */
#include <exception>
#include <stdexcept>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */


/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

# include <stlsoft/meta/n_types.hpp>
# include <stlsoft/meta/yesno.hpp>

# include <locale.h>

namespace stlsoft
{
namespace ximpl_conversion
{

	/* /////////////////////////////////////////////////////
	 * Workers
	 */

	/* general */



	/* OCTAL */
	template<
		typename	C
	>
	inline
	void
	integer_to_octal_string_formatted_worker_showBasePrefix_(
		no_type		/* showBasePrefix */
	,	C*&	/* s */
	)
	{}

	template<
		typename	C
	>
	inline
	void
	integer_to_octal_string_formatted_worker_showBasePrefix_(
		yes_type	/* showBasePrefix */
	,	C*&	s
	)
	{
		if('-' == *s)
		{
			*s   = '0';
			*--s = '-';
		}
		else
		{
			*--s = '0';
		}
	}

	template<
		typename	C
	>
	inline
	void
	integer_to_octal_string_formatted_worker_showPlusSign_(
		no_type		/* showPlusSign */
	,	C*&	/* s */
	)
	{}

	template<
		typename	C
	>
	inline
	void
	integer_to_octal_string_formatted_worker_showPlusSign_(
		yes_type	/* showPlusSign */
	,	C*&	s
	)
	{
		// NOTE: this assert relies on the fact that base prefixing
		// always occurs before plus-sign prefixing.

		STLSOFT_ASSERT('0' != *s || ('\0' != *s && '\0' != *(s + 1)));

		if('-' != *s)
		{
			*--s = '+';
		}
	}

	template<
		typename	C
	,	typename	I
	,	typename	T_ShowPlusSign
	,	typename	T_ShowBasePrefix
	>
	inline
	C const*
	integer_to_octal_string_formatted_worker_5_(
		T_ShowPlusSign		showPlusSign
	,	T_ShowBasePrefix	showBasePrefix
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	value
	)
	{
		C* s = const_cast<C*>(::stlsoft::integer_to_octal_string<I, C>(buf, cchBuf, value));

#ifdef _DEBUG
#else /* ? _DEBUG */
# error Ensure that it polices the size (taking into account the + prefix)
#endif /* _DEBUG */

		if(0 != value)
		{
			integer_to_octal_string_formatted_worker_showBasePrefix_<C>(showBasePrefix, s);
			integer_to_octal_string_formatted_worker_showPlusSign_<C>(showPlusSign, s);
		}

		return s;
	}


	/* DECIMAL */
	template<
		typename	C
	>
	inline
	void
	integer_to_decimal_string_formatted_worker_showPlusSign_(
		no_type		/* showPlusSign */
	,	C*&	/* s */
	)
	{}

	template<
		typename	C
	>
	inline
	void
	integer_to_decimal_string_formatted_worker_showPlusSign_(
		yes_type	/* showPlusSign */
	,	C*&	s
	)
	{
		STLSOFT_ASSERT('0' != *s);

		if('-' != *s)
		{
			*--s = '+';
		}
	}

	template<
		typename	C
	,	typename	I
	>
	inline
	C const*
	integer_to_decimal_string_formatted_worker_withLocaleSeparators_(
		no_type		/* withLocaleSeparators */
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	value
	)
	{
		return ::stlsoft::integer_to_decimal_string<I, C>(buf, cchBuf, value);
	}

	template<
		typename	C
	,	typename	I
	>
	inline
	C const*
	integer_to_decimal_string_formatted_worker_withLocaleSeparators_(
		yes_type	/* withLocaleSeparators */
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	value
	)
	{
		struct lconv const* lc = ::localeconv();

		return ::stlsoft::integer_to_lc_string(lc->grouping, *lc->thousands_sep, buf, cchBuf, value);
	}

	template<
		typename	C
	,	typename	I
	,	typename	T_ShowPlusSign
	,	typename	T_WithLocaleSeparators
	>
	inline
	C const*
	integer_to_decimal_string_formatted_worker_5_(
		T_ShowPlusSign			showPlusSign
	,	T_WithLocaleSeparators	withLocaleSeparators
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	value
	)
	{
		C* s = const_cast<C*>(integer_to_decimal_string_formatted_worker_withLocaleSeparators_<C, I>(withLocaleSeparators, buf, cchBuf, value));

#ifdef _DEBUG
#else /* ? _DEBUG */
# error Ensure that it polices the size (taking into account the + prefix)
#endif /* _DEBUG */

		// TODO: either separate this function into no_type overload that doesn't do
		// this check, or pass value into worker (which will be ignored in the no_type
		// overload).
		if(0 != value)
		{
			integer_to_decimal_string_formatted_worker_showPlusSign_<C>(showPlusSign, s);
		}

		return s;
	}


	/* HEXADECIMAL */
	template<
		typename	C
	>
	inline
	void
	integer_to_hexadecimal_string_formatted_worker_showBasePrefix_(
		no_type		/* showBasePrefix */
	,	C*&	/* s */
	)
	{}

	template<
		typename	C
	>
	inline
	void
	integer_to_hexadecimal_string_formatted_worker_showBasePrefix_(
		yes_type	/* showBasePrefix */
	,	C*&	s
	)
	{
		if('-' == *s)
		{
			*s   = 'x';
			*--s = '0';
			*--s = '-';
		}
		else
		{
			*--s = 'x';
			*--s = '0';
		}
	}

	template<
		typename	C
	>
	inline
	void
	integer_to_hexadecimal_string_formatted_worker_showPlusSign_(
		no_type		/* showPlusSign */
	,	C*&	/* s */
	)
	{}

	template<
		typename	C
	>
	inline
	void
	integer_to_hexadecimal_string_formatted_worker_showPlusSign_(
		yes_type	/* showPlusSign */
	,	C*&	s
	)
	{
		// NOTE: this assert relies on the fact that base prefixing
		// always occurs before plus-sign prefixing.

		STLSOFT_ASSERT('0' != *s || ('\0' != *s && '\0' != *(s + 1)));

		if('-' != *s)
		{
			*--s = '+';
		}
	}

	template<
		typename	C
	>
	inline
	void
	integer_to_hexadecimal_string_formatted_worker_uppercaseAlpha_(
		no_type		/* uppercaseAlpha */
	,	C*	/* s */
	)
	{}

	template<
		typename	C
	>
	inline
	void
	integer_to_hexadecimal_string_formatted_worker_uppercaseAlpha_(
		yes_type	/* uppercaseAlpha */
	,	C*	s
	)
	{
		{ for(; *s; ++s)
		{
			switch(*s)
			{
				case	'a':	*s	=	'A';	break;
				case	'b':	*s	=	'B';	break;
				case	'c':	*s	=	'C';	break;
				case	'd':	*s	=	'D';	break;
				case	'e':	*s	=	'E';	break;
				case	'f':	*s	=	'F';	break;
				case	'x':	*s	=	'X';	break;
			}
		}}
	}

	template<
		typename	C
	,	typename	I
	,	typename	T_ShowBasePrefix
	,	typename	T_ShowPlusSign
	,	typename	T_UppercaseAlpha
	>
	inline
	C const*
	integer_to_hexadecimal_string_formatted_worker_6_(
		T_ShowPlusSign		showPlusSign
	,	T_ShowBasePrefix	showBasePrefix
	,	T_UppercaseAlpha	uppercaseAlpha
	,	C*			buf
	,	ss_size_t	cchBuf
	,	I const&	value
	)
	{
		C* s = const_cast<C*>(::stlsoft::integer_to_hexadecimal_string<I, C>(buf, cchBuf, value));

#ifdef _DEBUG
#else /* ? _DEBUG */
# error Ensure that it polices the size (taking into account the + prefix)
#endif /* _DEBUG */

		integer_to_hexadecimal_string_formatted_worker_showBasePrefix_<C>(showBasePrefix, s);
		if(0 != value)
		{
			integer_to_hexadecimal_string_formatted_worker_showPlusSign_<C>(showPlusSign, s);
		}
		integer_to_hexadecimal_string_formatted_worker_uppercaseAlpha_<C>(uppercaseAlpha, s);

		return s;
	}



	/* /////////////////////////////////////////////////////
	 * Size selectors
	 */

	/* OCTAL */
	template<
		stlsoft::ximpl_conversion::conversion_decorations_t	D
	,	ss_typename_param_k									I
	,	ss_typename_param_k									C
	>
	inline
	C const*
	format_by_size_(
		stlsoft::ximpl_conversion::conversion_flag<cb_octal, D>	/* flags */
	,	C*			buf
	,	size_t		cchBuf
	,	I const&	value
	)
	{
		// Possible options:
		//
		// - showPlusSign
		// - showBasePrefix

		// Does not support any option except showPlusSign and
		// showBasePrefix (and octal, of course)
		STLSOFT_STATIC_ASSERT(0 == (~(int(cd_showPlusSign) | int(cd_showBasePrefix)) & D));

		enum { showPlusSign		=	(0 != (stlsoft::ximpl_conversion::cd_showPlusSign & D))	};
		enum { showBasePrefix	=	(0 != (stlsoft::ximpl_conversion::cd_showBasePrefix & D))	};

		typedef ss_typename_type_k stlsoft::value_to_yesno_type<showPlusSign>::type		showPlusSign_yesno_t;
		typedef ss_typename_type_k stlsoft::value_to_yesno_type<showBasePrefix>::type	showBasePrefix_yesno_t;

		return integer_to_octal_string_formatted_worker_5_(showPlusSign_yesno_t(), showBasePrefix_yesno_t(), buf, cchBuf, value);
	}

	/* DECIMAL */
	template<
		stlsoft::ximpl_conversion::conversion_decorations_t	D
	,	ss_typename_param_k									I
	,	ss_typename_param_k									C
	>
	inline
	C const*
	format_by_size_(
		stlsoft::ximpl_conversion::conversion_flag<cb_decimal, D>	/* flags */
	,	C*			buf
	,	size_t		cchBuf
	,	I const&	value
	)
	{
		// Possible options:
		//
		// - showPlusSign
		// - withLocaleSeparators

		// Does not support any option except showPlusSign (and decimal, of course)
		STLSOFT_STATIC_ASSERT(0 == (~(int(cd_showPlusSign) | int(cd_withLocaleSeparators)) & D));

		enum { showPlusSign			=	(0 != (stlsoft::ximpl_conversion::cd_showPlusSign & D))			};
		enum { withLocaleSeparators	=	(0 != (stlsoft::ximpl_conversion::cd_withLocaleSeparators & D))	};

		typedef ss_typename_type_k stlsoft::value_to_yesno_type<showPlusSign>::type	showPlusSign_yesno_t;
		typedef ss_typename_type_k stlsoft::value_to_yesno_type<withLocaleSeparators>::type	withLocaleSeparators_yesno_t;

		return integer_to_decimal_string_formatted_worker_5_(showPlusSign_yesno_t(), withLocaleSeparators_yesno_t(), buf, cchBuf, value);
	}

	/* HEXADECIMAL */
	template<
		stlsoft::ximpl_conversion::conversion_decorations_t	D
	,	ss_typename_param_k									I
	,	ss_typename_param_k									C
	>
	inline
	C const*
	format_by_size_(
		stlsoft::ximpl_conversion::conversion_flag<cb_hexadecimal, D>	/* flags */
	,	C*			buf
	,	size_t		cchBuf
	,	I const&	value
	)
	{
		// Possible options:
		//
		// - showBasePrefix
		// - showPlusSign
		// - uppercaseAlpha

		// Does not support any option except uppercaseAlpha, showPlusSign
		// and showBasePrefix (and hexadecimal, of course)
		STLSOFT_STATIC_ASSERT(0 == (~(int(cd_showPlusSign) | int(cd_showBasePrefix) | int(cd_uppercaseAlpha)) & D));

		enum { showBasePrefix	=	(0 != (stlsoft::ximpl_conversion::cd_showBasePrefix & D))	};
		enum { showPlusSign		=	(0 != (stlsoft::ximpl_conversion::cd_showPlusSign & D))	};
		enum { uppercaseAlpha		=	(0 != (stlsoft::ximpl_conversion::cd_uppercaseAlpha & D))	};

		typedef ss_typename_type_k stlsoft::value_to_yesno_type<showPlusSign>::type		showPlusSign_yesno_t;
		typedef ss_typename_type_k stlsoft::value_to_yesno_type<showBasePrefix>::type	showBasePrefix_yesno_t;
		typedef ss_typename_type_k stlsoft::value_to_yesno_type<uppercaseAlpha>::type	uppercaseAlpha_yesno_t;

		return integer_to_hexadecimal_string_formatted_worker_6_(showBasePrefix_yesno_t(), showPlusSign_yesno_t(), uppercaseAlpha_yesno_t(), buf, cchBuf, value);
	}


	template<
		stlsoft::ximpl_conversion::conversion_base_t		B
	,	stlsoft::ximpl_conversion::conversion_decorations_t	D
	,	ss_typename_param_k									I
	,	ss_typename_param_k									C
	>
	inline
	C const*
	format_4_(
		stlsoft::ximpl_conversion::conversion_flag<B, D>	flags
	,	C*			buf
	,	size_t		cchBuf
	,	I const&	value
	)
	{
		enum { base = B };

		STLSOFT_STATIC_ASSERT(0 != base);

		typedef stlsoft::size_type<base>	base_size_t;

		// NOTE: if the compiler cannot resolve the following function, it is
		// likely that an unrecognised base has been specified.
		return stlsoft::ximpl_conversion::format_by_size_<D, I, C>(flags, buf, cchBuf, value);
	}



} /* namespace ximpl_conversion */
} /* namespace stlsoft */

template<
	stlsoft::ximpl_conversion::conversion_base_t		B
,	stlsoft::ximpl_conversion::conversion_decorations_t	D
,	ss_typename_param_k									I
,	ss_typename_param_k									C
>
inline
C const*
format(
	stlsoft::ximpl_conversion::conversion_flag<B, D>	flags
,	C*			buf
,	size_t		cchBuf
,	I const&	value
)
{
	return stlsoft::ximpl_conversion::format_4_<B, D, I, C>(flags, buf, cchBuf, value);
}

template<
	stlsoft::ximpl_conversion::conversion_base_t		B
,	stlsoft::ximpl_conversion::conversion_decorations_t	D
,	ss_typename_param_k									I
,	ss_typename_param_k									C
>
inline
C const*
format(
	stlsoft::ximpl_conversion::conversion_flag<B, D>	flags
,	C*			buf
,	size_t		cchBuf
,	I const&	value
,	size_t*		numWritten
)
{
	C const* r = stlsoft::ximpl_conversion::format_4_<B, D, I, C>(flags, buf, cchBuf, value);

	if(NULL != numWritten)
	{
		*numWritten = cchBuf - (r - (buf - 1));
	}

	return r;
}

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int /* argc */, char** /*argv*/)
{
	////////////////////////////////////////////////////////
	// Decimal

    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::decimal
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}

    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::decimal
		|	stlsoft::conversion::showPlusSign
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}


	////////////////////////////////////////////////////////
	// Locale-specific

    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::decimal
		|	stlsoft::conversion::withLocaleSeparators
		,	&sz[0]
		,	dimensionof(sz)
		,	1000000000
		);

		puts(s);
	}

    {
        char const* const   locales[] =
        {
                "C"
            ,   "Afrikaans_South Africa"
            ,   "Arabic_Lebanon"
            ,   "Basque_Spain"
            ,   "Belarusian_Belarus"
            ,   "Bulgarian_Bulgaria"
//            ,   "dz_BT" // "Bhutanese"
            ,   "Chinese_Singapore"
            ,   "Danish"
            ,   "Dutch"
            ,   "English_Australia"
            ,   "English_Britain"
            ,   "English_UK"
            ,   "English_USA"
            ,   "Estonian_Estonia"
            ,   "Finnish"
            ,   "French_Belgium"
            ,   "French_Canada"
            ,   "French_France"
            ,   "German_Austria"
            ,   "German_Germany"
            ,   "German"
            ,   "Greek"
            ,   "Hungarian"
            ,   "Icelandic"
            ,   "Italian"
            ,   "Luxembourgish_Luxembourg"
            ,   "Norwegian"
            ,   "Polish"
            ,   "Portuguese_Brazil"
            ,   "Portuguese_Portugal"
            ,   "Romanian_Romania"
            ,   "Russian"
            ,   "Spanish_Argentina"
            ,   "Spanish_Spain"
            ,   "Swedish_Sweden"
            ,   "Swedish_Finlan"
            ,   "Turkish"
            ,   "Ukranian"
        };

        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(locales); ++i)
        {
            char const* const locale = locales[i];

		    if(NULL == ::setlocale(LC_NUMERIC, locale))
            {
                int const e = errno;

                fprintf(stderr, "%s: could not change to locale: %s\n", locale, stlsoft::error_desc(e).c_str());

                ::setlocale(LC_NUMERIC, "");
            }
            else
            {
		        char		sz[42];
		        char const*	s;

                memset(sz, '~', sizeof(sz));

		        s = 
		        format(
			        stlsoft::conversion::decimal
		        |	stlsoft::conversion::withLocaleSeparators
		        ,	&sz[0]
		        ,	dimensionof(sz)
		        ,	1000000000
		        );

		        fprintf(stdout, "%-20s:\t%s\n", locale, s);
            }
        }}
	}


	////////////////////////////////////////////////////////
	// Octal

    {
		char		sz[24];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::octal
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}

    {
		char		sz[24];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::octal
		,	&sz[0]
		,	dimensionof(sz)
		,	-123
		);

		puts(s);
	}

    {
		char		sz[24];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::octal
		|	stlsoft::conversion::showBasePrefix
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}

    {
		char		sz[24];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::octal
		|	stlsoft::conversion::showBasePrefix
		,	&sz[0]
		,	dimensionof(sz)
		,	-123
		);

		puts(s);
	}

    {
		char		sz[24];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::octal
		|	stlsoft::conversion::showPlusSign
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}

    {
		char		sz[24];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::octal
		|	stlsoft::conversion::showPlusSign
		,	&sz[0]
		,	dimensionof(sz)
		,	-123
		);

		puts(s);
	}

    {
		char		sz[24];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::octal
		|	stlsoft::conversion::showPlusSign
		|	stlsoft::conversion::showBasePrefix
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}

    {
		char		sz[24];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::octal
		|	stlsoft::conversion::showPlusSign
		|	stlsoft::conversion::showBasePrefix
		,	&sz[0]
		,	dimensionof(sz)
		,	-123
		);

		puts(s);
	}


	////////////////////////////////////////////////////////
	// Hexadecimal

    {
		char		sz[21];
		char const*	s;
		size_t		n;

		s = 
		format(
			stlsoft::conversion::hexadecimal
		|	stlsoft::conversion::showPlusSign
		|	stlsoft::conversion::showBasePrefix
		|	stlsoft::conversion::uppercaseAlpha
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		s = 
		format(
			stlsoft::conversion::hexadecimal
		|	stlsoft::conversion::showPlusSign
		|	stlsoft::conversion::showBasePrefix
		|	stlsoft::conversion::uppercaseAlpha
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		,	&n
		);

		puts(s);
	}

    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::hexadecimal
		|	stlsoft::conversion::showPlusSign
		|	stlsoft::conversion::showBasePrefix
		|	stlsoft::conversion::uppercaseAlpha
		,	&sz[0]
		,	dimensionof(sz)
		,	-123
		);

		puts(s);
	}

    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::hexadecimal
		|	stlsoft::conversion::showPlusSign
		|	stlsoft::conversion::showBasePrefix
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}

    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::hexadecimal
		|	stlsoft::conversion::showPlusSign
		|	stlsoft::conversion::showBasePrefix
		,	&sz[0]
		,	dimensionof(sz)
		,	-123
		);

		puts(s);
	}

    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::hexadecimal
		|	stlsoft::conversion::showPlusSign
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}

    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::hexadecimal
		|	stlsoft::conversion::showPlusSign
		,	&sz[0]
		,	dimensionof(sz)
		,	-123
		);

		puts(s);
	}

#if 0
    {
		char		sz[21];
		char const*	s;

		s = 
		format(
			stlsoft::conversion::hexadecimal
		|	stlsoft::conversion::decimal
		,	&sz[0]
		,	dimensionof(sz)
		,	123
		);

		puts(s);
	}
#endif /* 0 */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
#endif /* debug */

        return main_(argc, argv);
    }
    catch(std::bad_alloc&)
    {
    }
    catch(std::exception& /* x */)
    {
    }
    catch(...)
    {
    }

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
