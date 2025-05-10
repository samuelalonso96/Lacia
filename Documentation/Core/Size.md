```css
07/05/2025 - 0.0.1 - Core/Size.hpp
```


## Lacia::Size

```cpp
namespace Lacia
{
	using Size;
}
```

A 64-bits unsigned integer type capable of representing the size of any object.


### Example

```cpp
#include <print>
#include <Core/Size.hpp>

struct meow
{
	int a, b;
};

int main()
{
	constexpr ::Lacia::Size meow_size = sizeof(meow);
	std::println("Size of meow: {}", meow_size);
}
```