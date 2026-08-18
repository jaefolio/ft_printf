*This project has been created as part
of the 42 curriculum by jifoo.*

# Description

A custom re-implementation of the C standard library's `printf` function, built for the 42 curriculum. `ft_printf` parses a format string, walks a variadic argument list, and reproduces the behavior of the real `printf` for a defined subset of conversions.

## Supported conversions

| Specifier | Meaning                        | Example                          |
|-----------|---------------------------------|-----------------------------------|
| `%c`      | Single character                | `ft_printf("%c", 'A');`          |
| `%s`      | String (prints `(null)` for NULL) | `ft_printf("%s", "hi");`       |
| `%p`      | Pointer address in hex (prints `(nil)` for NULL) | `ft_printf("%p", ptr);` |
| `%d` / `%i` | Signed decimal integer        | `ft_printf("%d", -42);`          |
| `%u`      | Unsigned decimal integer        | `ft_printf("%u", 42u);`          |
| `%x`      | Unsigned hex, lowercase         | `ft_printf("%x", 255);` → `ff`   |
| `%X`      | Unsigned hex, uppercase         | `ft_printf("%X", 255);` → `FF`   |
| `%%`      | Literal percent sign            | `ft_printf("%%");` → `%`         |

Like the original `printf`, `ft_printf` returns the total number of characters written (or a negative value on failure), so its return value can be used the same way.

## Project structure

```
.
├── Makefile
├── ft_printf.h          # public header — declarations for ft_printf and helpers
├── ft_printf.c           # format string parsing, va_list handling, dispatch
├── conversion_alnum.c     # %c, %s, %d/%i, %u
├── conversion_hex.c       # %p, %x, %X
└── README.md
```

### File responsibilities

- **`ft_printf.c`** — the entry point. Walks the format string character by character, writes literal text directly, and hands off `%`-prefixed segments to the conversion dispatcher. Tracks the running character count for the return value.
- **`conversion_alnum.c`** — handles character, string, and decimal (signed/unsigned) conversions.
- **`conversion_hex.c`** — handles pointer and hexadecimal conversions. Hex-to-string conversion is done recursively: each call peels off one digit via `n % 16`, recurses on `n / 16` for the remaining digits, then writes its own digit *after* the recursive call returns — which naturally prints the most-significant digit first.

### Parsing

`ft_printf` scans the format string looking for `%`. On a literal character, it writes it straight to `stdout` and increments a counter. On `%`, control passes to a helper that:

1. Checks whether the next character is another `%` (a literal `%%`), and if so writes a single `%`.
2. Otherwise, scans forward for a recognized conversion letter (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`), pulls the correctly-typed argument off the `va_list` with `va_arg`, and calls the matching `print_*` function.

### Return value

Every `print_*` function returns the number of characters *it* wrote. Since the pointer/hex conversions are recursive, each recursive call reports its own count upward, and the caller adds its own digit to that running total — the same pattern the real `printf` uses internally to build up the total character count it returns.

# Instructions

## Building

```sh
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and the library
make re       # fclean + all
```

This produces a static library, `libftprintf.a`, that you link against:

```sh
cc your_program libftprintf.a
```

## Usage example

```c
#include "ft_printf.h"

int main(void)
{
	int len;

	len = ft_printf("Hello, %s! You are %d years old (0x%x in hex).\n",
			"Anon", 25, 25);
	ft_printf("Characters written: %d\n", len);
	return (0);
}
```

## Resources

- `man` pages for each reimplemented function
- 42 Norminette documentation for style compliance
- https://www.geeksforgeeks.org/c/format-specifiers-in-c/
- https://www.geeksforgeeks.org/c/variadic-functions-in-c/

**AI usage:** Claude was used to explain concepts, and point out bugs. It was not used to write
or generate function implementations directly.
