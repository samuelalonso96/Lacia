```css
11/05/2025 - 0.0.1 - Core/Safety.hpp
```


## Macros

### $reliable

```cpp
#define $reliable(...)
```

Used to specify a reliable/safe function.


### $unreliable

```cpp
#define $unreliable(...)
```

Used to specify a unreliable/unsafe function.


### $

```cpp
#define $(...)
```

Used to call reliable or unreliable functions.


### $safe

```cpp
#define $safe
```

Used to specify a safe block. When this header is included, it's safe implicitly.


### $unsafe

```cpp
#define $unsafe
```

Used to specify an unsafe block.


## Example

```cpp
#include <print>
#include <Core/Safety.hpp>

auto meow() noexcept -> void
{
	std::println("meow");
}

auto meow $unreliable() noexcept -> void
{
	std::println("unsafe meow");
}

auto meow $reliable() noexcept -> void
{
	std::println("safe meow");
}

int main()
{
	meow(); // normal meow
	meow $(); // safe meow by default
	$unsafe meow $(); // unsafe meow
	$unsafe
	{
		meow $(); // unsafe meow
		$safe meow $(); // safe meow
		$safe
		{
			meow $(); // safe meow
		}
	}
}
```