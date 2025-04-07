/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:02:58 by dfernan3          #+#    #+#             */
/*   Updated: 2025/04/01 16:48:29 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	contains_only_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	char_integer(char *str)
{
	unsigned long long int	nb;
	int						i;

	nb = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

bool	is_valid(int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	while (i < ac)
	{
		if (!contains_only_digits(av[i]))
		{
			if (i == 1)
				return (ft_error(NEGATIVE_NUMBER, false));
			else
				return (ft_error(RANGE_NUM, false));
		}
		num = char_integer(av[i]);
		if (i == 1 && (num <= 0 || num > MAX_PHILOS))
			return (ft_error(NUM_PHILOS, false));
		if (i != 1 && num == -1)
			return (ft_error(RANGE_NUM2, false));
		i++;
	}
	return (true);
}
