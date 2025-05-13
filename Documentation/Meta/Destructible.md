```css
13/05/2025 - 0.0.1 - Meta/Destructible.hpp
```

Depends on: ``Meta/Void.hpp``, ``Meta/Function.hpp``, ``Meta/Reference.hpp``, ``Meta/Remove Extents.hpp``, ``Meta/Unbounded Array.hpp``.


## Concepts

```cpp
namespace Lacia::Meta
{
	template<class T> concept Destructible;
}
```

Satisfied if ``T`` isn't a void, function, nor unbounded array type, and is a reference type or an object type with a non-deleted destructor.


## Example

```cpp
#include <print>
#include <Meta/Destructible.hpp>

template<Lacia::Meta::Destructible T> auto print_and_destroy(T& object) noexcept -> void
{
	std::println("{}", object);
	object.~T();
}

int main()
{
	int x = 42;
	print_and_destroy(x);
}
```