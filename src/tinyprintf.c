#include "tinyprintf.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int disp_str(char *s)
{
    if (!s)
        return disp_str("(null)");

    size_t i = 0;
    while (s[i] != '\0')
    {
        putchar(s[i++]);
    }

    return i;
}

int my_itoa_base(unsigned int nb, const char *base, size_t i)
{
    int len = 0;
    if (nb >= i)
        len += my_itoa_base(nb / i, base, i);

    putchar(base[nb % i]);
    return len + 1;
}

int my_itoa(int nb)
{
    int len = 0;
    if (nb < 0)
    {
        putchar('-');
        nb *= -1;
        len++;
    }
    return len + my_itoa_base(nb, "0123456789", 10);
}

int parser(char c, va_list ap)
{
    switch (c)
    {
    case 's':
        return disp_str(va_arg(ap, char *));
    case 'c':
        putchar(va_arg(ap, int));
        return 1;
    case 'd':
        return my_itoa(va_arg(ap, int));
    case 'u':
        return my_itoa_base(va_arg(ap, unsigned int), "0123456789", 10);
    case 'o':
        return my_itoa_base(va_arg(ap, unsigned int), "01234567", 8);
    case 'x':
        return my_itoa_base(va_arg(ap, unsigned int), "0123456789abcdef", 16);
    default: {
        int len = 0;
        if (c != '%')
        {
            putchar('%');
            len++;
        }
        putchar(c);
        len++;
        return len;
    }
    }
}

int tinyprintf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);

    int len = 0;
    size_t i = 0;

    while (format[i] != '\0')
    {
        switch (format[i])
        {
        case '%':
            i++;
            len += parser(format[i], ap);
            break;
        default:
            putchar(format[i]);
            len++;
            break;
        }
        i++;
    }
    va_end(ap);
    return len;
}
