```css
13/05/2025 - 0.0.1 - Meta/Void.hpp
```


## Concepts

### Lacia::Meta::Void

```cpp
namespace Lacia::Meta
{
	template<class T> concept Void;
}
```

Satisfied if ``T`` is the ``void`` type (possibly const or volatile qualified).


## Example

```cpp
#include <print>
#include <Meta/Void.hpp>

int main()
{
	std::println("Is int a void type? {}", Lacia::Meta::Void<int>);
	std::println("Is void a void type? {}", Lacia::Meta::Void<void>);
	std::println("Is volatile void a void type? {}", Lacia::Meta::Void<volatile void>);
	std::println("Is const void a void type? {}", Lacia::Meta::Void<const void>);
	std::println("Is volatile const void a void type? {}", Lacia::Meta::Void<volatile const void>);
}
```