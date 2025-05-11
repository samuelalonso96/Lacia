```css
11/05/2025 - 0.0.1 - Core/Trait.hpp
```


## Macros

### $interface

```cpp
#define $interface
```

Used to define an interface. Interfaces declares the member functions an implementor of such interface must define.


### $trait

```cpp
#define $trait
```

Used to define a trait. A trait is the high-order predicate that makes sure that the interfaces are isomethodic (the same member functions) to the implementations of such interfaces


### $with

```cpp
#define $with
```

Used to specify the interface and the implementor, with additional constraints.


### $implements

```cpp
#define $implements
```

Used to specify the interface being implemented.


### $required

```cpp
#define $required
```

Used to specify a required member function in the boundaries of the interface.


### $elf

```cpp
#define $elf
```

Used to define the ``Self`` class inside the template parameter list.


### $self

```cpp
#define $self
```

Used to specify the explicit ``this`` instance inside the function parameter list.


## Example

```cpp
#include <print>
#include <Core/Trait.hpp>

template<$elf> $interface IPrint
{
	auto print($self const&) noexcept -> void $required;
};

template<$elf> $trait Print $with <IPrint<Self>, Self>;

template<$elf, class Rhs = Self> $interface IAdd
{
	[[nodiscard]] constexpr auto add($self const& self, const Self& rhs) noexcept -> Self $required;
};

template<$elf, class Rhs = Self> $trait Add $with <IAdd<Self, Rhs>, Self> and Print<Self>;

struct meow : $implements IAdd<meow>, $implements IPrint<meow>
{
	int x;

	auto print($self const& self) noexcept -> void
	{
		std::println("The value of x is: {}", self.x);
	}

	[[nodiscard]] constexpr auto add($self const& self, const meow& rhs) noexcept -> meow
	{
		return meow{.x = self.x + rhs.x};
	}
};

auto adder(Add auto const& lhs, const meow& rhs) -> void
{
	const meow result = lhs.add(rhs);
	result.print();
}

int main()
{
	const meow lhs{.x = 32}, rhs{.x = 10};
	adder(lhs, rhs);
}
```