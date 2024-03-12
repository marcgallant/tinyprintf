# tinyprintf
tinyprintf is a project that emulates printf(3).
## Project Description
This project was made after a week on learning in C during my third year (ING1) at EPITA.
Made in 4 hours it has the purpose to reproduce the comportement of printf(3), which is to display a formatted output on stdout and returns the size of the formatted output.
It supports the following directive :
- %%: display the % character.
- %d: display the signed decimal representation of the next argument.
- %u: display the unsigned decimal representation of the next argument.
- %s: display the char * argument corresponding to the string representation and terminated by
the \0 char. The argument of type char * must effectively point to an allocated zone containing
the string. If the argument is NULL, you must display "(null)".
- %c: display the ASCII character form of the next argument.
- %o: display the unsigned octal representation of the next argument.
- %x: display the unsigned hexadecimal representation of the next argument. The [a-f] characters
of the hexadecimal base must be printed in lower case.
## Makefile
- Generates src/tinyprintf.o
```sh
make all 
```
- Runs a Criterion testsuite for your tinyprintf
```sh
make check
```
- Deletes everything produced by make
```sh
make clean
```
## Exported function
```c
int tinyprintf(const char *format, ...);
```
