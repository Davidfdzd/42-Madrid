/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:12:30 by dfernan3          #+#    #+#             */
/*   Updated: 2024/10/22 17:54:42 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	extract_char(char const *format, va_list args, int *i)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), i);
}

static void	extract_pointer(char const *format, va_list args, int *i)
{
	unsigned long long	adress;

	if (*format == 'p')
	{
		adress = (va_arg(args, unsigned long long));
		if (!adress)
		{
			*i += write(1, "(nil)", 5);
			return ;
		}
		*i += write(1, "0x", 2);
		ft_putnbr_unsigned(adress, "0123456789abcdef", 16, i);
	}
}

static void	extract_number(char const *format, va_list args, int *i)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), i);
	if (*format == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), "0123456789", 10, i);
	if (*format == 'x')
		ft_putnbr_unsigned(va_arg(args, unsigned int), "0123456789abcdef", 16,
			i);
	if (*format == 'X')
		ft_putnbr_unsigned(va_arg(args, unsigned int), "0123456789ABCDEF", 16,
			i);
}

static void	ft_type_format(char const *format, va_list args, int *i)
{
	if (*format == 'c' || *format == 's')
		extract_char(format, args, i);
	if (*format == 'p')
		extract_pointer(format, args, i);
	if (*format == 'd' || *format == 'i' || *format == 'u' || *format == 'x'
		|| *format == 'X')
		extract_number(format, args, i);
	if (*format == '%')
		ft_putchar('%', i);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1))
				ft_type_format(++format, args, &i);
		}
		else
			i += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}
