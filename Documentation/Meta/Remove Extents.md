```css
13/05/2025 - 0.0.1 - Meta/Remove Extents.hpp
```

Depends on: ``Core/Size.hpp``.


## Aliases

```cpp
namespace Lacia::Meta
{
	template<class T> using RemoveExtents;
}
```

Removes all the array extents of ``T``, if any.


## Example

```cpp
#include <print>
#include <Meta/Remove Extents.hpp>

int main()
{
	std::println("{}", Lacia::Meta::RemoveExtents<int>(42));
	std::println("{}", Lacia::Meta::RemoveExtents<int[3]>(42));
	std::println("{}", Lacia::Meta::RemoveExtents<int[10][3]>(42));
}
```