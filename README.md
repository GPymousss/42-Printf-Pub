*This project has been created as part of the 42 curriculum by guletill.*

# ft_printf

## Description

ft_printf is a project of the 42 common core. The goal is to recode the
`printf()` function of the libc and to deliver it as a static library,
`libftprintf.a`.

The main lesson of the project is the use of **variadic functions** in C
(`va_start`, `va_arg`, `va_end`): a function that receives a variable number of
arguments whose types are only known by reading the format string.

The function has the same prototype as the original:

```c
int	ft_printf(const char *, ...);
```

It writes the formatted output on the standard output and returns the number
of characters printed, exactly like `printf()`. As required by the subject,
it does not reproduce the buffer management of the original `printf()`: every
character is written directly with `write`.

### Supported conversions

| Conversion | Argument type | Output |
|---|---|---|
| `%c` | `int` (cast to `char`) | A single character. |
| `%s` | `char *` | A string; `(null)` if the pointer is `NULL`. |
| `%p` | `void *` | The address in lowercase hexadecimal prefixed by `0x`; `(nil)` if `NULL`. |
| `%d` | `int` | A signed decimal number. |
| `%i` | `int` | A signed decimal number (same as `%d`). |
| `%u` | `unsigned int` | An unsigned decimal number. |
| `%x` | `unsigned int` | A number in lowercase hexadecimal. |
| `%X` | `unsigned int` | A number in uppercase hexadecimal. |
| `%%` | — | A percent sign. |

Only the mandatory part is implemented (no flags, width or precision).

## Instructions

### Requirements

- `cc` (gcc or clang)
- `make`
- `ar`

### Compilation

At the root of the repository:

```sh
make        # builds libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and libftprintf.a
make re     # fclean + all
```

Every source file is compiled with `-Wall -Wextra -Werror`, and the library is
created with `ar rcs`.

### Using the library in a project

Include the header in your sources:

```c
#include "ft_printf.h"
```

Then link against the library when compiling:

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
```

### Testing

`ft_printf.c` ends with a test `main` that is commented out so it does not
interfere with the library build. It calls `ft_printf` and the real `printf`
with the same arguments for every conversion (including edge cases such as
`INT_MIN`, `UINT_MAX`, `NULL` strings and pointers, `%c` with `'\0'`), then
prints both return values.

1. Remove the `/*` and `*/` around the block at the bottom of `ft_printf.c`.
2. Build and run it:

   ```sh
   cc -Wall -Wextra -Werror *.c -o test && ./test
   ```

3. Comment the block again before committing.

Example of output:

```
ft : [0] [2147483647] [-2147483648]
pf : [0] [2147483647] [-2147483648]
ret ft : 36 | ret pf : 36
```

## Algorithm and data structure

### Parsing the format string

`ft_printf` reads the format string once, from left to right, with an index:

- an ordinary character is written with `ft_putchar`;
- a `%` makes the index move to the next character, the conversion specifier,
  which is passed to `ft_handle_format`.

`ft_handle_format` selects the right helper with a chain of `if / else if`
on the specifier, fetches the next argument with `va_arg` using the type
expected by that conversion, and prints it.

Every helper returns the number of characters it wrote. These values are
added up along the way, so the total returned by `ft_printf` is always the
exact number of characters printed, without counting them a second time.

### Printing numbers

Numbers are printed **recursively**: the function first calls itself on
`n / base` to print the most significant digits, then prints the last digit,
`n % base`. This prints the digits in the right order without storing them in
a temporary buffer and without any memory allocation.

- `ft_putnbr` (`%d`, `%i`) prints the `-` sign for negative numbers, then
  works on the opposite value. `INT_MIN` is handled as a special case, since
  `-INT_MIN` does not fit in an `int`.
- `ft_putnbr_unsigned` (`%u`) works in base 10 on an `unsigned int`.
- `ft_puthex` (`%x`, `%X`) works in base 16 and chooses the digit set,
  `"0123456789abcdef"` or `"0123456789ABCDEF"`, with its `upc` parameter.
- `ft_putptr` (`%p`) casts the pointer to an `unsigned long` so the whole
  64-bit address fits, prints `0x`, then the address in lowercase hexadecimal.

### Why this design

- **No data structure, no allocation**: every character is written as soon as
  it is known, which follows the subject (no buffer management) and removes any
  risk of memory leaks.
- **One small function per conversion**: each helper is short, easy to test
  on its own and compliant with the Norm. Adding a new conversion only takes
  one new helper and one new branch in `ft_handle_format`.
- **Recursion for numbers**: the depth is at most 20 calls (a 64-bit value in
  base 10), so it stays cheap while keeping the code very short.

## Resources

### References

- `printf(3)` man page: <https://man7.org/linux/man-pages/man3/printf.3.html>
- `stdarg(3)` man page (variadic functions):
  <https://man7.org/linux/man-pages/man3/stdarg.3.html>
- C reference, variadic arguments:
  <https://en.cppreference.com/w/c/variadic>
- 42 Norm (`fr.norm.pdf`) and the ft_printf subject (version 12.1)
- `norminette`, the official 42 Norm checker: <https://github.com/42School/norminette>

### Use of AI

AI (Claude, by Anthropic) was used for:

- **Test main**: writing the commented-out `main` at the bottom of
  `ft_printf.c`, used to compare `ft_printf` against the real `printf`.
- **Documentation**: writing this README from the subject's requirements.

The library functions themselves (`ft_*.c`, `ft_printf.h`) and the `Makefile`
were written without AI, to keep the learning focus of the project.
