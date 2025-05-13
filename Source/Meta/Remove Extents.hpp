#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_remove_extents
#define lacia_guard_meta_remove_extents
#include "../Core/Size.hpp"

namespace Lacia::Meta
{
    namespace Detail
    {
        template<class T> struct RemoveExtents
        {
            using type = T;
        };

        template<class T> struct RemoveExtents<T[]>
        {
            using type = typename RemoveExtents<T>::type;
        };

        template<class T, Size size> struct RemoveExtents<T[size]>
        {
            using type = typename RemoveExtents<T>::type;
        };
    }

    template<class T> using RemoveExtents = Detail::RemoveExtents<T>::type;
}

#endif
#endif