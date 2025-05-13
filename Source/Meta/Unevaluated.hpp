#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_unevaluated
#define lacia_guard_meta_unevaluated

namespace Lacia::Meta
{
    template<class T> [[nodiscard]] consteval auto Unevaluated() noexcept -> T&&;
}

#endif
#endif