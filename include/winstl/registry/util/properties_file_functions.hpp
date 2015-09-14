
/*
 *
 * Updated: 15th September 2014
 */

#ifndef WINSTL_INCL_WINSTL_REGISTRY_util_HPP_properties_file_functions
#define WINSTL_INCL_WINSTL_REGISTRY_util_HPP_properties_file_functions


# include <winstl/registry/util/key_functions.hpp>

# include <winstl/registry/reg_value_sequence.hpp>

# include <stlsoft/meta/is_same_type.hpp>

# include <stlsoft/smartptr/scoped_handle.hpp>

# include <stlsoft/string/replace_functions.hpp>


namespace stlsoft
{
namespace winstl_project
{


namespace ximpl_properties_file_functions
{

	template<
		ss_typename_param_k S
	>
	void
	append_maybe_same_(
		::stlsoft::yes_type
	,	S&			dest
	,	S const&	src
	)
	{
		dest.append(src);
	}

	template<
		ss_typename_param_k S1
	,	ss_typename_param_k S2
	>
	void
	append_maybe_same_(
		::stlsoft::no_type
	,	S1&			dest
	,	S2 const&	src
	)
	{
		dest.append(src.data(), src.size());
	}

	template<
		ss_typename_param_k S1
	,	ss_typename_param_k S2
	>
	S1&
	append_name(
		S1&			dest
	,	S2 const&	src
	)
	{
		// TODO: handle following:
		//
		// - \ - escape it
		// - = - escape it
		// - : - escape it
		// - whitespace - escape it

		S2 t;

		{ for(size_t i = 0; i != src.size(); ++i)
		{
			ss_typename_type_k S1::value_type const ch = src[i];

			switch(ch)
			{
				case	'\\':
				case	'=':
				case	':':
				case	' ':
					if( t.empty() &&
						0 != i)
					{
						t.assign(src.substr(0, i));
					}
					t.append(1, '\\');
					t.append(1, ch);
					break;
				case	'\n':
					if( t.empty() &&
						0 != i)
					{
						t.assign(src.substr(0, i));
					}
					t.append(1, '\\');
					t.append(1, 'n');
					break;
				default:
					if(!t.empty())
					{
						t.append(1, ch);
					}
			}
		}}

		typedef ss_typename_type_k ::stlsoft::is_same_type<S1, S2>::type	same_type_type_;

		if(!t.empty())
		{
			append_maybe_same_(same_type_type_(), dest, t);
		}
		else
		{
			append_maybe_same_(same_type_type_(), dest, src);
		}

		return dest;
	}

	template<
		ss_typename_param_k S1
	,	ss_typename_param_k S2
	>
	S1&
	append_value(
		S1&			dest
	,	S2 const&	src
	)
	{
		// TODO: handle following:
		//
		// - \ - escape it
		// - = - escape it
		// - : - escape it
		// - whitespace - escape it

		S2 t;

		{ for(size_t i = 0; i != src.size(); ++i)
		{
			ss_typename_type_k S1::value_type const ch = src[i];

			switch(ch)
			{
				case	'\\':
					if( t.empty() &&
						0 != i)
					{
						t.assign(src.substr(0, i));
					}
					t.append(1, '\\');
					t.append(1, ch);
					break;
				default:
					if(!t.empty())
					{
						t.append(1, ch);
					}
			}
		}}

		typedef ss_typename_type_k ::stlsoft::is_same_type<S1, S2>::type	same_type_type_;

		if(!t.empty())
		{
			append_maybe_same_(same_type_type_(), dest, t);
		}
		else
		{
			append_maybe_same_(same_type_type_(), dest, src);
		}

		return dest;
	}


} /* namespace ximpl_properties_file_functions */





template <ss_typename_param_k S>
inline
LONG
reg_key_values_to_property_file_contents(
	HKEY		hkeyRoot
,	LPCSTR		subkeyName
,	S&			results
)
{
	WINSTL_ASSERT(NULL != hkeyRoot);

	if(	NULL != subkeyName &&
		'\0' != subkeyName[0])
	{
		HKEY		hkeySub;
		LONG const	r = key_open(hkeyRoot, subkeyName, &hkeySub);

		if(ERROR_SUCCESS == r)
		{
			stlsoft::scoped_handle<HKEY> scoper1(hkeySub, ::RegCloseKey);

			return reg_key_values_to_property_file_contents(hkeySub, NULL, results);
		}

		return r;
	}
	else
	{
		LONG	r = ERROR_SUCCESS;
		S		t;

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("do this in terms of new API"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

		reg_value_sequence values(hkeyRoot, NULL);

// NOTE: inelegant mix of return codes and exceptions (thrown if data type wrong or if contents changed)

		{ for(reg_value_sequence::iterator it = values.begin(); values.end() != it; ++it)
		{
			reg_value const			val		=	*it;
			reg_value::string_type	name	=	val.name();
			char					buff[21];

			// handle 

			ximpl_properties_file_functions::append_name(t, name);
			t.append(": ");

			switch(val.type())
			{
				case	REG_SZ:
				case	REG_EXPAND_SZ:
					ximpl_properties_file_functions::append_value(t, val.value_sz());
					break;
				case	REG_DWORD:
					t.append(stlsoft::integer_to_decimal_string(buff, STLSOFT_NUM_ELEMENTS(buff), val.value_dword(), NULL));
					break;
				case	REG_MULTI_SZ:
					{
						reg_value::strings_type const strings = val.value_multi_sz();

						t.append("\\\n");
						{ for(reg_value::strings_type::const_iterator it2 = strings.begin(); strings.end() != it2; ++it2)
						{
							t.append(4, ' ');
							ximpl_properties_file_functions::append_value(t, (*it2));
							t.append("\\n\\\n");
						}}
					}
					break;
				default:
					throw std::domain_error("invalid registry value type");
			}

			t.append(1, '\n');
		}}

		if(ERROR_SUCCESS == r)
		{
			t.swap(results);
		}

		return r;
	}
}


} /* namespace winstl_project */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_REGISTRY_util_HPP_properties_file_functions */

/* ///////////////////////////// end of file //////////////////////////// */
