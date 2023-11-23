# C - printf

Group _printf project


## Description
Our goal is to create our own _printf function in groups that works like the original _printf function.
In C language, printf() function is used to print formatted output to the standard output stdout.  The printf function is a part of the C standard library <stdio.h> and it can allow formatting the output in numerous ways. The printf in C also contains a format specifier that is replaced by the actual value during execution.
## The compilation command
```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
## Requirements
- Permitted text editors include Vi, Vim, and Emacs.
- Ensure that code adheres to the Betty style.
- Avoid the use of global variables.
- Restrict the number of functions in a file to no more than 5.
- Include the prototypes of all functions in your header file, named main.h. 
- Employ include guards for all your header files.
We were allowed to edit files in Vi, Vim or Emacs. Code should pass Betty style
## Authorized functions and macros

- write (man 2 write)
- malloc (man 3 malloc)
- free (man 3 free)
- va_start (man 3 va_start)
- va_end (man 3 va_end)
- va_copy (man 3 va_copy)
- va_arg (man 3 va_arg)
## Tasks to be accomplished
1. Write a function that produces output according to a format (GitHub repository: holbertonschool-printf).
Prototype: int _printf(const char *format, ...).
Function must return the number of characters printed (excluding the null byte used to end output to strings).
Handle the following conversion specifiers:
- c
- s
- %
- d
- i

2. Create a man page for your function (file: man_3_printf).
## Examples of usage (with screenshots)
## Man page

| Format     | Description                |
| :------- | :------------------------- |
| c | Print char |
| s | If argument is a string function will print a string. |
| % | Print a percent |
| d | If argument is a decimal function will print a integer (decimal) |
| i | If argument is a interger function will print integer |
##  Flowchart
![image](https://github.com/AudreyLican/holbertonschool-printf/assets/97944947/03f4ad1c-0c52-41e4-a846-ad6b4c7d205f)
https://drive.google.com/file/d/1DVVdVqpP1le8nlpMq34fCXRTZmhpz9js/view?usp=drive_link
## Authors

- [@Audrey Lican](https://github.com/AudreyLican)
- [@Alexey Chernov](https://github.com/alexeychern0v?tab=repositories)
