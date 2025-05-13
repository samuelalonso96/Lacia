```css
13/05/2025 - 0.0.1 - Meta/Function.hpp
```


## Concepts

### Lacia::Meta::Function

```cpp
namespace Lacia::Meta
{
	template<class T> concept Function;
}
```

Satisfied if ``T`` is a free function type.


## Example

```cpp
#include <print>
#include <Meta/Function.hpp>

auto lambda = []{};

void function(){}

struct meow
{
	void function(){}
};

int main()
{
	std::println("Is a lambda a function type? {}", Lacia::Meta::Function<decltype(lambda)>);
	std::println("Is a free function a function type? {}", Lacia::Meta::Function<decltype(function)>);
	std::println("Is a free function pointer a function type? {}", Lacia::Meta::Function<decltype(&function)>);
	std::println("Is a member function pointer a function type? {}", Lacia::Meta::Function<decltype(&meow::function)>);
}
```