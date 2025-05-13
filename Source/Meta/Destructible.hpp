#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_destructible
#define lacia_guard_meta_destructible
#include "Void.hpp"
#include "Function.hpp"
#include "Reference.hpp"
#include "Remove Extents.hpp"
#include "Unbounded Array.hpp"

namespace Lacia::Meta
{
    namespace Detail
    {
        template<class T> struct Destructible
        {
            static consteval bool value() noexcept
            {
                using U = RemoveExtents<T>;
                return requires(U u)
                {
                    u.~U();
                };
            }
        };

        template<::Lacia::Meta::Reference T> struct Destructible<T>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };

        template<class T> requires(::Lacia::Meta::Void<T> or ::Lacia::Meta::Function<T> or ::Lacia
        ::Meta::UnboundedArray<T>) struct Destructible<T>
        {
            static consteval bool value() noexcept
            {
                return false;
            }
        };
    }

    template<class T> concept Destructible = Detail::Destructible<T>::value();
}

#endif
#endif