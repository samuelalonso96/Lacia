```css
13/05/2025 - 0.0.1 - Meta/Reference.hpp
```


## Concepts

### Lacia::Meta::Reference

```cpp
namespace Lacia::Meta
{
	template<class T> concept Reference;
}
```

Satisfied if ``T`` is an l-value or r-value reference type.


## Example

```cpp
#include <print>
#include <Meta/Reference.hpp>

int main()
{
	std::println("Is int a reference type? {}", Lacia::Meta::Reference<int>);
	std::println("Is int& a reference type? {}", Lacia::Meta::Reference<int&>);
	std::println("Is int&& a reference type? {}", Lacia::Meta::Reference<int&&>);
}
```