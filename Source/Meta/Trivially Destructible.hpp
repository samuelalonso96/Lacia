#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_trivially_destructible
#define lacia_guard_meta_trivially_destructible

namespace Lacia::Meta
{
    template<class T> concept TriviallyDestructible = __is_trivially_destructible(T);
}

#endif
#endif