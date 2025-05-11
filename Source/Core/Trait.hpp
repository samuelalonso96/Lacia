#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_core_trait
#define lacia_guard_core_trait
#define $interface struct
#define $trait concept
#define $with = ::Lacia::Detail::Isomethodic
#define $implements public
#define $required = delete("required")
#define $elf class Self
#define $self this auto

namespace Lacia::Detail
{
    template<class Interface, class Implementor> [[nodiscard]] consteval auto IsomethodicHelper()
    noexcept -> bool
    {
        // TODO: improve with static reflection
        return __is_base_of(Interface, Implementor);
    }

    template<class Interface, class Implementor> concept Isomethodic = IsomethodicHelper<Interface,
    Implementor>();
}

#endif
#endif