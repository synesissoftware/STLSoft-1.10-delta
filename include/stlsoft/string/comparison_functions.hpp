

namespace stlsoft
{

#if 0
  int string_compare(char const* s1, char const* s2)
  {
    return ::strcmp(s1, s2);
  }

  int string_compare(wchar_t const* s1, wchar_t const* s2)
  {
    return ::wcscmp(s1, s2);
  }

  int string_compare(char const* s1, char const* s2, size_t n1, size_t n2)
  {
    return ::strncmp(s1, s2, n);
  }

  int string_compare(wchar_t const* s1, wchar_t const* s2, size_t n1, size_t n2)
  {
    return ::wcsncmp(s1, s2, n);
  }
#else /* ? 0 */

  bool string_equal(char const* s1, char const* s2, size_t n1, size_t n2)
  {
    return n1 == n2 && 0 == ::strncmp(s1, s2, n1);
  }
  bool string_equal(wchar_t const* s1, wchar_t const* s2, size_t n1, size_t n2)
  {
    return n1 == n2 && 0 == ::wcsncmp(s1, s2, n1);
  }

  bool string_equal(char const* s1, char const* s2)
  {
    return 0 == ::strcmp(s1, s2);
  }
  bool string_equal(wchar_t const* s1, wchar_t const* s2)
  {
    return 0 == ::wcscmp(s1, s2);
  }

  template<
    typename S1
  , typename S2
  >
  bool string_equal(S1 const& s1, S1 const& s2)
  {
    return string_equal(c_str_data(s1), c_str_data(s2), c_str_len(s1), c_str_len(s2));
  }

#endif /* 0 */


} /* namespace stlsoft */


#if 0
  template<
    typename S1
  , typename S2
  >
  inline S1 null_if(S1 const& s1, S2 const& s2)
  {
    if(stlsoft::string_equal(s1, s2))
    {
      return S1();
    }

    return s1;
  }
#endif /* 0 */

