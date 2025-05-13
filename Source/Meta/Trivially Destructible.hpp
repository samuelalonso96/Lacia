#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_trivially_destructible
#define lacia_guard_meta_trivially_destructible
#include "Void.hpp"
#include "Function.hpp"
#include "Reference.hpp"
#include "Remove Extents.hpp"
#include "Unbounded Array.hpp"

namespace Lacia::Meta
{
    namespace Detail
    {
        template<class T> struct TriviallyDestructible
        {
            static consteval bool value() noexcept
            {
                using U = RemoveExtents<T>;
                return requires(U u)
                {
                    u.~U();
                } and __is_trivially_destructible(U);
            }
        };

        template<::Lacia::Meta::Reference T> struct TriviallyDestructible<T>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };

        template<class T> requires(::Lacia::Meta::Void<T> or ::Lacia::Meta::Function<T> or ::Lacia
        ::Meta::UnboundedArray<T>) struct TriviallyDestructible<T>
        {
            static consteval bool value() noexcept
            {
                return false;
            }
        };
    }

    template<class T> concept TriviallyDestructible = Detail::TriviallyDestructible<T>::value();
}

#endif
#endif