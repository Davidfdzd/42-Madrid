/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:14:15 by dfernan3          #+#    #+#             */
/*   Updated: 2024/10/21 18:50:39 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
void	ft_putchar(char c, int *i);
void	ft_putnbr(int nbr, int *i);
void	ft_putstr(char *s, int *i);
int		ft_strlen(char *s);
void	ft_putnbr_unsigned(unsigned long long nbr, char *base, int base_len,
			int *i);

#endif