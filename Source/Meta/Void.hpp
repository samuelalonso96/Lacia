#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_void
#define lacia_guard_meta_void

namespace Lacia::Meta
{
    namespace Detail
    {
        template<class> struct Void
        {
            static consteval bool value() noexcept
            {
                return false;
            }
        };

        template<> struct Void<void>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };

        template<> struct Void<volatile void>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };

        template<> struct Void<const void>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };

        template<> struct Void<volatile const void>
        {
            static consteval bool value() noexcept
            {
                return true;
            }
        };
    }

    template<class T> concept Void = Detail::Void<T>::value();
}

#endif
#endif