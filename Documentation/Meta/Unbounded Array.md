```css
13/05/2025 - 0.0.1 - Meta/Unbounded Array.hpp
```


## Concepts

### Lacia::Meta::UnboundedArray

```cpp
namespace Lacia::Meta
{
	template<class T> concept UnboundedArray;
}
```

Satisfied if ``T`` is an array type of unknown boundaries.


## Example

```cpp
#include <print>
#include <Meta/Unbounded Array.hpp>

int main()
{
	std::println("Is int[5] an unbounded array type? {}", Lacia::Meta::UnboundedArray<int[5]>);
	std::println("Is int[1][1] an unbounded array type? {}", Lacia::Meta::UnboundedArray<int[1][1]>);
	std::println("Is int[] an unbounded array type? {}", Lacia::Meta::UnboundedArray<int[]>);
	std::println("Is int[][5] an unbounded array type? {}", Lacia::Meta::UnboundedArray<int[][5]>);
}
```