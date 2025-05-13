#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_reference
#define lacia_guard_meta_reference

namespace Lacia::Meta
{
    namespace Detail
    {
        template<class> struct Reference
        {
            static consteval bool value() noexcept
            {
                return false;
            }
        };

        template<class T> struct Reference<T&>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };

        template<class T> struct Reference<T&&>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };
    }

    template<class T> concept Reference = Detail::Reference<T>::value();
}

#endif
#endif