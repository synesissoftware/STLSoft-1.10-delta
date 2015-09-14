
/*
 * Created: 20th May 2012
 * Updated: 17th November 2013
 */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <platformstl/filesystem/directory_functions.hpp>
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */
#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/path.hpp>

#ifdef WIN32
# include <winstl/filesystem/file_creation_functions.h>
# include <winstl/filesystem/file_size_functions.h>
#endif /* WIN32 */

#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#include <stlsoft/smartptr/scoped_handle.hpp>

#include <string>
#include <stack>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{
namespace platformstl_project
{

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

class temporary_directory_contents
{
public: // Member Types
	typedef temporary_directory_contents	class_type;
	typedef char							char_type;
	typedef size_t							size_type;
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
	typedef ss_uint64_t						file_size_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
	typedef size_t							file_size_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
private:
	typedef filesystem_traits<char_type>	traits_type_;
	typedef basic_path<char_type>			path_type_;

public: // Construction
	template <ss_typename_param_k S>
	explicit temporary_directory_contents(
		S const&	directory
	)
		: m_directory()
		, m_remove(false)
		, m_directories()
		, m_files()
	{
		init_(stlsoft_ns_qual(c_str_ptr_null)(directory), NULL);
	}
	template<
		ss_typename_param_k S0
	,	ss_typename_param_k S1
	>
	temporary_directory_contents(
		S0 const&	directory
	,	S1 const&	subDirectory
	)
		: m_directory()
		, m_remove(false)
		, m_directories()
		, m_files()
	{
		init_(stlsoft_ns_qual(c_str_ptr_null)(directory), stlsoft_ns_qual(c_str_ptr_null)(subDirectory));
	}

	~temporary_directory_contents() stlsoft_throw_0()
	{
		cleanup_(false);
	}

public: // Operations
	template <ss_typename_param_k S>
	class_type&
	create_directory(
		S const& name
	)
	{
		path_type_ path(m_directory);

		path /= name;

		create_directory_(stlsoft_ns_qual(c_str_ptr)(path));

		return *this;
	}

	template <ss_typename_param_k S>
	class_type&
	create_file(
		S const&		name
	,	file_size_type	size = 0
	)
	{
		path_type_ path(m_directory);

		path /= name;

		create_file_(stlsoft_ns_qual(c_str_ptr)(path), size);

		return *this;
	}

	void cleanup()
	{
		cleanup_(true);
	}

public: // 
	char_type const*	c_str() const
	{
		return m_directory.c_str();
	}

private: // 
	typedef std::string					string_type_;
	typedef std::stack<string_type_>	stack_type_;

private: // Implementation
	void init_(
		char_type const*	directory
	,	char_type const*	subDirectory
	)
	{
		path_type_	path(directory);

		if(NULL != subDirectory)
		{
			path /= subDirectory;

			m_remove = true;
		}

		if(!platformstl::create_directory_recurse(path.c_str()))
		{
//			throw
		}

		m_directory = path.c_str();
	}

	void
	create_directory_(
		char_type const*	path
	)
	{
	}

	void
	create_file_(
		char_type const*	path
	,	file_size_type		size
	)
	{
#ifdef WIN32
		traits_type_::file_handle_type hFile = winstl::file_create_always(path, GENERIC_WRITE, 0, 0);
#else /* WIN32 */
		traits_type_::file_handle_type hFile = traits_type_::open_file(path, O_CREAT, 0);
#endif /* WIN32 */

		if(traits_type_::invalid_file_handle_value() == hFile)
		{
//			throw;
		}
		else
		{
			stlsoft::scoped_handle<traits_type_::file_handle_type> scoper(hFile, traits_type_::close_file);

			if(0 != size)
			{
#ifdef WIN32
				if(!winstl::file_set_size_by_handle_64(hFile, size))
#else /* WIN32 */
//				if(!unixstl::file_set_size_by_handle_64(hFile, size))
#endif /* WIN32 */
				{
//					throw;
				}
			}

			m_files.push(string_type_(path));
		}
	}

	void cleanup_(bool throwOnFailure)
	{
		// Files

		for(; !m_files.empty(); m_files.pop())
		{
			stack_type_::value_type const& top = m_files.top();

			if(!traits_type_::unlink_file(top.c_str()))
			{
				if(throwOnFailure)
				{
//					throw
				}
			}
		}

		STLSOFT_ASSERT(m_files.empty());

		// Directories


		// Directory
		if(	!m_directory.empty() &&
			m_remove)
		{
			if(!traits_type_::remove_directory(m_directory.c_str()))
			{
#ifdef WIN32
				::GetLastError();
#endif /* WIN32 */


//				throw
			}
			else
			{
				m_directory.erase();
			}
		}
	}

private: // Fields
	string_type_	m_directory;
	bool			m_remove;
	stack_type_		m_directories;
	stack_type_		m_files;
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace platformstl_project */
} /* namespace stlsoft */

/* ////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////// end of file //////////////////////////// */
