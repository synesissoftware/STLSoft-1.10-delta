
/*
 * Created:	
 * Updated:	15th November 2014
 */

#include <stlsoft/stlsoft_1_10.h>

# include <stlsoft/stlsoft.h>

# include <stlsoft/conversion/integer_to_string/integer_to_decimal_string.hpp>

# include <stlsoft/meta/is_character_type.hpp>
# include <stlsoft/meta/is_integral_type.hpp>
# include <stlsoft/meta/is_same_type.hpp>
# include <stlsoft/meta/yesno.hpp>


namespace stlsoft
{


namespace ximpl_stlsoft_string_plural_functions
{

template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
>
inline
R
plural_form_result_(
	I const&	count
,	N const&	noun
)
{
	typedef ss_typename_type_k R::value_type	char_t;

	R					r;
	char_t				num[21];
	ss_size_t			cch;
	char_t const*		s = integer_to_decimal_string(&num[0], STLSOFT_NUM_ELEMENTS(num), count, &cch);

	r.assign(s, cch);
	r.append(1, ' ');
	r.append(c_str_data(noun), c_str_len(noun));

	return r;
}


template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
,	ss_typename_param_k T
>
inline
R
plural_form_result_from_plurals_maybe_sequence_(
	I const&	count
,	N const&	noun
,	T const&	noun_plurals
,	yes_type
)
{
	ss_size_t index;

	switch(count)
	{
		case	0:
			index	=	0;
			break;
		case	1:
			index	=	1;
			break;
		default:
			if(count < I(noun_plurals.size()))
			{
				index	=	ss_size_t(count);
			}
			else
			{
				index	=	2;
			}
			break;
	}

	STLSOFT_ASSERT(index < noun_plurals.size());

	return plural_form_result_<R>(count, noun_plurals[index]);
}

template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
,	ss_typename_param_k T
>
inline
R
plural_form_result_from_plurals_maybe_sequence_(
	I const&	count
,	N const&	noun
,	T const&	noun_plurals
,	no_type
)
{
	ss_typename_type_k T::const_iterator	it = noun_plurals.find(count);

	if(noun_plurals.end() == it)
	{
		return plural_form_result_<R>(count, noun);
	}
	else
	{
		return plural_form_result_<R>(count, (*it).second);
	}
}


template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
,	ss_typename_param_k T
>
inline
R
plural_form_result_from_mapped_maybe_string_(
	I const&	count
,	N const&	noun
,	T const&	noun_plural
,	yes_type
)
{
	if(1 == count)
	{
		return plural_form_result_<R>(count, noun);
	}
	else
	{
		return plural_form_result_<R>(count, noun_plural);
	}
}

template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
,	ss_typename_param_k T
>
inline
R
plural_form_result_from_mapped_maybe_string_(
	I const&	count
,	N const&	noun
,	T const&	noun_plurals
,	no_type
)
{
	// Now we're dealing with noun_plural as an array or as a map, and so
	// discriminate between the two by seeing if the value_type is the
	// same as N

	typedef ss_typename_type_k T::value_type									T_value_t;

	enum { value_type_is_string = stlsoft::is_same_type<N, T_value_t>::value };

	typedef ss_typename_type_k value_to_yesno_type<value_type_is_string>::type	T_is_sequence_t;

	return plural_form_result_from_plurals_maybe_sequence_<R>(count, noun, noun_plurals, T_is_sequence_t());
}

template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
,	ss_typename_param_k M
>
inline
R
plural_3_noun_same_type_as_mappings_key_(
	I const&	count
,	N const&	noun
,	M const&	mappings
,	yes_type
)
{
	ss_typename_type_k M::const_iterator const	it = mappings.find(noun);

	if(mappings.end() == it)
	{
		return plural_form_result_<R>(count, noun);
	}
	else
	{
		typedef ss_typename_type_k M::value_type::second_type	mapped_t;

		// At this point, mapped_t may be a string type or it may be another
		// map
		//
		// We discriminate between the two by determining whether the mapped
		// type's value type is a character, in which case we assume we're
		// dealing with { M : string->string }; otherwise we assume we're
		// dealing with { M : string->{ integer : string } }
		// or with { M : string->[ string ] }.

		typedef ss_typename_type_k mapped_t::value_type								mapped_value_t;

		enum { mapped_is_string = stlsoft::is_character_type<mapped_value_t>::value };

		typedef ss_typename_type_k value_to_yesno_type<mapped_is_string>::type		mapped_is_string_t;

		return plural_form_result_from_mapped_maybe_string_<R>(count, noun, (*it).second, mapped_is_string_t());
	}
}

template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
,	ss_typename_param_k M
>
inline
R
plural_3_noun_same_type_as_mappings_key_(
	I const&	count
,	N const&	noun
,	M const&	mappings
,	no_type
)
{
	typedef ss_typename_type_k M::key_type			key_t;

	return plural_3_noun_same_type_as_mappings_key_<R, I, key_t, M>(count, key_t(c_str_data(noun), c_str_len(noun)), mappings, yes_type());
}


template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
,	ss_typename_param_k M
>
inline
R
plural_3_(
	I const&	count
,	N const&	noun
,	M const&	mappings
)
{
	typedef ss_typename_type_k M::key_type									key_t;

	enum { types_are_same = stlsoft::is_same_type<key_t, N>::value };

	typedef ss_typename_type_k value_to_yesno_type<types_are_same>::type	same_type_t;

	return plural_3_noun_same_type_as_mappings_key_<R, I, N, M>(count, noun, mappings, same_type_t());
}

} /* namespace ximpl_stlsoft_string_plural_functions */



template<
	ss_typename_param_k R
,	ss_typename_param_k I
,	ss_typename_param_k N
,	ss_typename_param_k M
>
inline
R
plural(
	I const&	count
,	N const&	noun
,	M const&	mappings
)
{
	using namespace ximpl_stlsoft_string_plural_functions;

	STLSOFT_STATIC_ASSERT(0 != stlsoft::is_integral_type<I>::value);

	return plural_3_<R, I, N, M>(count, noun, mappings);
}

} /* namespace stlsoft */

/* ///////////////////////////// end of file //////////////////////////// */
