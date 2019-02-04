# ft_printf
A re-implementation of the "printf" function implemented in C.

## Description
The goal of this project is to recreate the highly useful printf function found in many languages, including the ease of formatting, and the support of diverse types in variable numbers.

The implemented functionality closely mocks the behaviour found in `man printf`.

For a more thorough description and list of requirements (such as allowed functions) look at "ft_printf.en.pdf".

### Functionality
The function has the following usage:
`ft_printf [arguments ...]`

#### Supported conversions:
`c` : Char.

`s` : String.

`p` : Pointer.

`d` : Decimal.

`i` : Integer.

`o` : Octal.

`u` : Unsigned Integer.

`x` : Hexadecimal.

`f` : Float.

`j` : Maximum Integer.

`z` : Size_t.

`%` : Percentage Sign.

#### Supported flags (varies per conversion. See documentation for printf):
`l`  : Converts to long.

`ll` : Converts to long long.

`h`  : Converts to Char.

`hh` : Converts to short int.

`#`  : Add '0x' to hexideximal.

`0`  : Pad width with zeros.

`-`  : Left justify.

`+`  : If positive add positive sign.

`_`  : Space.

#### Supported modifications (varies per conversion. See documentation printf):
`[value].` : Minimum width.

`.[value]` : Maximum precision.

### Usage
```
$ make
```
Paste on top of your program.
```
#include "ft_printf.h"
```
Use in your program.
```
ft_printf [arguments ...];
```
Compile your program with executable.
```
gcc [yourprogram] libftprintf.a
```
