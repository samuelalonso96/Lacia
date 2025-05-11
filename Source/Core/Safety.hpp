#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_core_safety
#define lacia_guard_core_safety
#define $reliable(...) (::Lucy::Detail::Safe<> __VA_OPT__(,) __VA_ARGS__)
#define $unreliable(...) (::Lucy::Detail::Safe<false> __VA_OPT__(,) __VA_ARGS__)
#define $(...) (do_not_use_safe_object_private_and_secret __VA_OPT__(,) __VA_ARGS__)
#define $unsafe if constexpr([[maybe_unused]] constexpr ::Lucy::Detail::Safe<false> \
do_not_use_safe_object_private_and_secret; true)
#define $safe if constexpr([[maybe_unused]] constexpr ::Lucy::Detail::Safe<> \
do_not_use_safe_object_private_and_secret; true)

namespace Lacia::Detail
{
    template<bool safe = true> struct Safe final
    {
        constexpr ~Safe() noexcept = default;

        explicit constexpr Safe() noexcept = default;

        constexpr Safe(const Safe&) noexcept = default;

        explicit constexpr Safe(Safe&&) noexcept = delete;

        constexpr auto operator=(const Safe&) noexcept -> Safe& = delete;

        constexpr auto operator=(Safe&&) noexcept -> Safe& = delete;

        [[nodiscard]] constexpr auto operator==(const Safe&) const noexcept -> bool = delete;

        [[nodiscard]] constexpr auto operator not_eq(const Safe&) const noexcept -> bool = delete;

        [[nodiscard]] static consteval auto safety() noexcept -> bool
        {
            return safe;
        }
    };
}

inline constexpr ::Lacia::Detail::Safe<> do_not_use_safe_object_private_and_secret;

#endif
#endif