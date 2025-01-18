#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

static void ft_putstr(const char *s, int *count)
{
    if (!s)
        s = "(null)";
    while (*s)
        *count += write(1, s++, 1);
}

static void ft_putnbr(int nbr, int *count)
{
    char c;

    if (nbr == -2147483648)
    {
        ft_putstr("-2147483648", count);
        return;
    }
    if (nbr < 0)
    {
        *count += write(1, "-", 1);
        nbr = -nbr;
    }
    if (nbr > 9)
        ft_putnbr(nbr / 10, count);
    c = (nbr % 10) + '0';
    *count += write(1, &c, 1);
}

static void ft_puthex(unsigned int n, int *count)
{
    char *hex = "0123456789abcdef";

    if (n >= 16)
        ft_puthex((n / 16), count);
    *count += write(1, &hex[n % 16], 1);
}

int ft_printf(const char *format, ... )
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(args, char *), &count);
            else if (*format == 'd')
                ft_putnbr(va_arg(args, int), &count);
            else if (*format == 'x')
                ft_puthex(va_arg(args, unsigned int), &count);
            else
                count += write(1, format, 1);
        }
        else
            count += write(1, format, 1);
        format++;
    }
    va_end(args);
    return(count);
}