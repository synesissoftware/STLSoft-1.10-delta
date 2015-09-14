
// Created: 1st January 2004
// Updated: 31st May 2010

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stlsoft/stlsoft_1_10.h> /* Requires STLSoft 1.10 alpha header during alpha phase */
#include <stlsoft/quality/contract.h>
#include <stlsoft/quality/cover.h>

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

namespace stlsoft
{

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
//# define STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Helpers
 */

namespace impl
{

    template <typename C>
    struct method_invoker
    {
    public:
        virtual void invoke(C* instance) = 0;
    };

    template <typename C>
    struct method_invoker_0
        : public method_invoker<C>
    {
    public:
        explicit method_invoker_0(void (C::*method)())
            : m_method(method)
        {}

    public:
        virtual void invoke(C* instance)
        {
            (instance->*m_method)();
        }

    private:
        void    (C::*m_method)();
    };

    template <typename C, typename A0>
    struct method_invoker_1
        : public method_invoker<C>
    {
    public:
        explicit method_invoker_1(void (C::*method)(A0), A0 a0)
            : m_method(method)
            , m_a0(a0)
        {}

    public:
        virtual void invoke(C* instance)
        {
            (instance->*m_method)(m_a0);
        }

    private:
        void    (C::*m_method)(A0);
        A0      m_a0;
    };

#ifndef STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT

    template <typename C, typename A0, typename A1>
    struct method_invoker_2
        : public method_invoker<C>
    {
    public:
        explicit method_invoker_2(void (C::*method)(A0, A1), A0 a0, A1 a1)
            : m_method(method)
            , m_a0(a0)
            , m_a1(a1)
        {}

    public:
        virtual void invoke(C* instance)
        {
            (instance->*m_method)(m_a0, m_a1);
        }

    private:
        void    (C::*m_method)(A0, A1);
        A0      m_a0;
        A1      m_a1;
    };

#endif /* !STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT */

    template <typename C>
    inline method_invoker<C>* make_invoker(void (C::*method)())
    {
        return new method_invoker_0<C>(method);
    }

    template <typename C, typename A0>
    inline method_invoker<C>* make_invoker(void (C::*method)(A0), A0 a0)
    {
        return new method_invoker_1<C, A0>(method, a0);
    }

#ifndef STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT

    template <typename C, typename A0, typename A1>
    inline method_invoker<C>* make_invoker(void (C::*method)(A0, A1), A0 a0, A1 a1)
    {
        return new method_invoker_2<C, A0, A1>(method, a0, a1);
    }

#endif /* !STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT */


} // namespace impl

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

template <typename C>
class scoped_method
{
public: // Member Types
    /// This type
    typedef scoped_method<C>            class_type;
private:
    /// The invoker type
    typedef impl::method_invoker<C>     invoker_type;

public: // Construction
    scoped_method(C* instance, void (C::*method)())
        : m_instance(instance)
        , m_invoker(impl::make_invoker<C>(method))
    {}
    scoped_method(C& instance, void (C::*method)())
        : m_instance(&instance)
        , m_invoker(impl::make_invoker<C>(method))
    {}

    template <typename A0>
    scoped_method(C* instance, void (C::*method)(A0), A0 a0)
        : m_instance(instance)
        , m_invoker(impl::make_invoker<C>(method, a0))
    {}
    template <typename A0>
    scoped_method(C& instance, void (C::*method)(A0), A0 a0)
        : m_instance(&instance)
        , m_invoker(impl::make_invoker<C>(method, a0))
    {}

#ifndef STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT

    template <typename A0, typename A1>
    scoped_method(C* instance, void (C::*method)(A0, A1), A0 a0, A1 a1)
        : m_instance(instance)
        , m_invoker(impl::make_invoker<C>(method, a0, a1))
    {}
    template <typename A0, typename A1>
    scoped_method(C& instance, void (C::*method)(A0, A1), A0 a0, A1 a1)
        : m_instance(&instance)
        , m_invoker(impl::make_invoker<C>(method, a0, a1))
    {}

#endif /* !STLSOFT_SCOPED_METHOD_0_OR_1_PARAM_SUPPORT */

    ~scoped_method() stlsoft_throw_0()
    {
        if(NULL != m_instance)
        {
            m_invoker->invoke(m_instance);
        }

        delete m_invoker;
    }
private:
    scoped_method(class_type const&);
    class_type& operator= (class_type const&);

private: // Member Variables
    C*              m_instance;
    invoker_type*   m_invoker;
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

} // namespace stlsoft

/* ///////////////////////////// end of file //////////////////////////// */
