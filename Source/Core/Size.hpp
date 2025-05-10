#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_core_size
#define lacia_guard_core_size

namespace Lacia
{
    using Size = decltype(sizeof false);
}

static_assert(alignof(::Lacia::Size) == 8uz and sizeof(::Lacia::Size) == 8uz);

#endif
#endif