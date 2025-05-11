```css
11/05/2025 - 0.0.1 - Meta/TriviallyDestructible.hpp
```


## Concepts

### Lacia::Meta::TriviallyDestructible

```cpp
namespace Lacia::Meta
{
	template<class T> concept TriviallyDestructible;
}
```

Satisfied when ``T`` has an implicit or explicit default non-deleted & non-virtual destructor and all of its base classes and sub-objects are also trivially destructible.


## Example

```cpp
#include <print>
#include <Meta/TriviallyDestructible.hpp>

struct meow{};

int main()
{
	std::println("Is meow trivially destructible? {}", Lacia::Meta::TriviallyDestructible<meow>);
}
```