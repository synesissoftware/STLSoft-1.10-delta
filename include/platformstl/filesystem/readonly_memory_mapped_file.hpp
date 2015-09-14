
#include <platformstl/platformstl_1_10.h>



/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{
namespace platformstl_project
{


class readonly_memory_mapped_file
{
private: // Types
    /// The character type
    typedef char                                char_type;
    /// The traits type
    typedef filesystem_traits<char_type>        traits_type;
public:
    /// This type
    typedef readonly_memory_mapped_file         class_type;
    /// \brief The size type
#ifdef STLSOFT_CF_64BIT_INT_SUPPORT
    typedef ss_uint64_t                         size_type;
#else /* ? STLSOFT_CF_64BIT_INT_SUPPORT */
    typedef ss_uint32_t                         size_type;
#endif /* STLSOFT_CF_64BIT_INT_SUPPORT */
    /// The result code type
    typedef traits_type::error_code_type        result_code_type;
    /// \brief The offset type
    CreateFileMapping
    typedef off_t                           offset_type;
    /// The boolean type
    typedef ss_bool_t                       bool_type;

public: // Construction
    template <ss_typename_param_k S>
    ss_explicit_k readonly_memory_mapped_file(S const& path)
    {
    }

private:
    memory_mapped_file(class_type const&);
    class_type& operator =(class_type const&);

};




/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} /* namespace platformstl_project */
} /* namespace stlsoft */

/* ///////////////////////////// end of file //////////////////////////// */
