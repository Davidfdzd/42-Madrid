/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:13:46 by dfernan3          #+#    #+#             */
/*   Updated: 2024/11/15 11:37:52 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *i)
{
	*i += write(1, &c, 1);
}

void	ft_putstr(char *s, int *i)
{
	if (!s)
	{
		*i += write(1, "(null)", 6);
		return ;
	}
	*i += write(1, s, (int)ft_strlen(s));
}

void	ft_putnbr(int nbr, int *i)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", i);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', i);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, i);
	ft_putchar((nbr % 10) + '0', i);
}

void	ft_putnbr_unsigned(unsigned long long nbr, char *base, int base_len,
		int *i)
{
	if (nbr > ((unsigned int)base_len - 1))
		ft_putnbr_unsigned(nbr / base_len, base, base_len, i);
	ft_putchar(base[(nbr % base_len)], i);
}
