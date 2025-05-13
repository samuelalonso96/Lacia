#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_unbounded_array
#define lacia_guard_meta_unbounded_array

namespace Lacia::Meta
{
    namespace Detail
    {
        template<class> struct UnboundedArray
        {
            static consteval bool value() noexcept
            {
                return false;
            }
        };

        template<class T> struct UnboundedArray<T[]>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };
    }

    template<class T> concept UnboundedArray = Detail::UnboundedArray<T>::value();
}

#endif
#endif