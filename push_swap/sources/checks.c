/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:22:59 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 20:04:53 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_limits(char *num)
{
	int	len;

	len = ft_strlen(num);
	if (num[0] == '-')
	{
		if ((len > 11) || (len == 11 && ft_strncmp("-2147483648", num, 11) < 0))
			ft_error("One number exceed what is allowed!!!");
	}
	else
	{
		if (num[0] == '+')
		{
			if ((len > 11) || (len == 11 && ft_strncmp("+2147483647", num,
						11) < 0))
				ft_error("One number exceed what is allowed!!!");
		}
		else
		{
			if ((len > 10) || (len == 10 && ft_strncmp("2147483647", num,
						10) < 0))
				ft_error("One number exceed what is allowed!!!");
		}
	}
}

void	check_num(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (num[i] == '\0')
		ft_error("Arguments must be only digits!!");
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			ft_error("Arguments must be only digits!!");
		i++;
	}
}

void	check_dup_args(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
				ft_error("There are dup numbers!!");
			j++;
		}
		i++;
	}
}

int	check_order(t_box *box)
{
	int	i;

	i = 0;
	while (i < box->len_a - 1)
	{
		if (box->stack_a[i] > box->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
