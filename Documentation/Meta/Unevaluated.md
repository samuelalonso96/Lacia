```css
13/05/2025 - 0.0.1 - Meta/Unevaluated.hpp
```


## Functions

```cpp
namespace Lacia::Meta
{
	template<class T> [[nodiscard]] consteval auto Unevaluated() noexcept -> T&&;
}
```

Gives an instance of ``T`` meant to be used in unevaluated contexts (such as inside a ``decltype``).


## Example

```cpp
#include <print>
#include <Meta/Unevaluated.hpp>

int foo(int x, float y)
{
	return x * y;
}

int foo(int x, int y)
{
	return x + y;
}

int main()
{
	std::println("{}", foo(42, decltype(::Lacia::Meta::Unevaluated<int>())(3)));
	std::println("{}", foo(42, decltype(::Lacia::Meta::Unevaluated<float>())(3.f)));
}
```