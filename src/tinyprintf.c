#include "tinyprintf.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 16

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

void str_revert(char *s)
{
    size_t n = 0;
    while (s[n] != '\0')
    {
        n++;
    }

    for (size_t i = 0; i < n / 2; i++)
    {
        char tmp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = tmp;
    }
}

int my_itoa(int value)
{
    if (value == 0)
    {
        putchar('0');
        return 1;
    }

    char *s = malloc(BUFF_SIZE);

    int neg = value < 0;
    if (neg)
        value = -value;

    size_t j = 0;
    while (value != 0)
    {
        s[j++] = value % 10 + '0';
        value /= 10;
    }

    if (neg)
        s[j++] = '-';

    s[j] = '\0';

    str_revert(s);
    int len = disp_str(s);
    free(s);

    return len;
}

int my_itoa_base(unsigned int value, const char *base, size_t i)
{
    if (value == 0)
    {
        putchar(*base);
        return 1;
    }

    char *s = malloc(BUFF_SIZE);

    size_t j = 0;
    while (value != 0)
    {
        s[j++] = base[value % i];
        value /= i;
    }

    s[j] = '\0';

    str_revert(s);
    int len = disp_str(s);
    free(s);

    return len;
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
