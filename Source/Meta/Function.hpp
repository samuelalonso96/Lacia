#if lacia_major >= 0 and lacia_middle >= 0 and lacia_minor >= 1
#ifndef lacia_guard_meta_function
#define lacia_guard_meta_function

namespace Lacia::Meta
{
    template<class T> concept Function = __is_function(T);
}

#endif
#endif