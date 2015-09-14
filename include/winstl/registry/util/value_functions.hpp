
# include <winstl/registry/util/value_functions.h>

# include <stlsoft/memory/auto_buffer.hpp>

namespace stlsoft
{
namespace winstl_project
{
	using ::winstl_C_registry_value_read_DWORD_a;
	using ::winstl_C_registry_value_read_string_a;

inline
LONG
value_read(
	HKEY		hkey
,	LPCTSTR		valueName
,	DWORD*		dwordValue
)
{
	return winstl_C_registry_value_read_DWORD_a(hkey, valueName, dwordValue);
}

template <ss_typename_type_k S>
inline
LONG
value_read(
	HKEY		hkey
,	LPCTSTR		valueName
,	S&			str
)
{
	DWORD	cchValue	=	0;
	LONG	r			=	winstl_C_registry_value_read_string_a(hkey, valueName, NULL, &cchValue);

	if(ERROR_SUCCESS == r)
	{
		S().swap(str);
	}
	else
	if(ERROR_MORE_DATA == r)
	{
		stlsoft::auto_buffer<TCHAR> buff(0);

		do
		{
			if(!buff.resize(cchValue))
			{
				return ERROR_OUTOFMEMORY;
			}

			cchValue = static_cast<DWORD>(buff.size());
			r = winstl_C_registry_value_read_string_a(hkey, valueName, &buff[0], &cchValue);

		} while(ERROR_MORE_DATA == r);

		if(ERROR_SUCCESS == r)
		{
			S(buff.data(), cchValue - 1).swap(str);
		}
	}

	return r;
}

} /* namespace winstl_project */
} /* namespace stlsoft */

/* ///////////////////////////// end of file //////////////////////////// */
