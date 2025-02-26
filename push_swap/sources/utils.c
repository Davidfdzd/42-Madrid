/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:27:08 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 20:05:37 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest(t_box *box)
{
	int	i;

	i = 0;
	box->small_i = 0;
	box->min = box->stack_a[0];
	while (i < box->len_a)
	{
		if (box->stack_a[i] < box->min)
		{
			box->min = box->stack_a[i];
			box->small_i = i;
		}
		i++;
	}
}

void	push_up(t_box *box)
{
	int	i;

	if (box->small_i < (box->len_a / 2))
	{
		i = 0;
		while (i < box->small_i)
		{
			ft_rotatea(box);
			i++;
		}
	}
	else
	{
		i = box->len_a;
		while (i > box->small_i)
		{
			ft_rev_rotatea(box);
			i--;
		}
	}
}

void	push_upb(t_box *box)
{
	int	i;

	if (box->big_i < (box->len_b / 2))
	{
		i = 0;
		while (i < box->big_i)
		{
			ft_rotateb(box);
			i++;
		}
	}
	else
	{
		i = box->len_b;
		while (i > box->big_i)
		{
			ft_rev_rotateb(box);
			i--;
		}
	}
}

void	find_biggest(t_box *box)
{
	int	i;

	i = 0;
	box->big_i = 0;
	box->min = box->stack_b[0];
	while (i < box->len_b)
	{
		if (box->stack_b[i] > box->min)
		{
			box->min = box->stack_b[i];
			box->big_i = i;
		}
		i++;
	}
}

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt * sqrt < nb)
		++sqrt;
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (sqrt);
}
