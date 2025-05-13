```css
13/05/2025 - 0.0.1 - Meta/Trivially Destructible.hpp
```

Depends on: ``Meta/Void.hpp``, ``Meta/Function.hpp``, ``Meta/Reference.hpp``, ``Meta/Remove Extents.hpp``, ``Meta/Unbounded Array.hpp``.


## Concepts

### Lacia::Meta::TriviallyDestructible

```cpp
namespace Lacia::Meta
{
	template<class T> concept TriviallyDestructible;
}
```

Satisfied if ``T`` isn't a void, function, nor unbounded array type, and is a reference type or an object type with an implicit or explicit default non-deleted & non-virtual default/trivial destructor and all of its base classes and sub-objects are also trivially destructible.


## Example

```cpp
#include <print>
#include <Meta/TriviallyDestructible.hpp>

template<Lacia::Meta::TriviallyDestructible T> auto print_and_destroy(T& object) noexcept -> void
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