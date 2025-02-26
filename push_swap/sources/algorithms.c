/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:22:26 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 19:50:35 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nums_help(t_box *box)
{
	ft_rotatea(box);
	ft_swapa(box);
	ft_rev_rotatea(box);
}

void	two_nums(t_box *box)
{
	if (box->stack_a[0] > box->stack_a[1])
		ft_swapa(box);
}

void	three_nums(t_box *box)
{
	if (box->stack_a[0] > box->stack_a[1])
	{
		if (box->stack_a[1] > box->stack_a[2])
		{
			ft_swapa(box);
			ft_rev_rotatea(box);
		}
		else
		{
			if (box->stack_a[0] > box->stack_a[2])
				ft_rotatea(box);
			else
				ft_swapa(box);
		}
	}
	else
	{
		if (box->stack_a[0] > box->stack_a[2])
			ft_rev_rotatea(box);
		else
			three_nums_help(box);
	}
}

void	four_nums(t_box *box)
{
	find_smallest(box);
	push_up(box);
	if (!check_order(box))
	{
		ft_pushb(box);
		three_nums(box);
		ft_pusha(box);
	}
}

void	five_nums(t_box *box)
{
	find_smallest(box);
	push_up(box);
	if (!check_order(box))
	{
		ft_pushb(box);
		four_nums(box);
		ft_pusha(box);
	}
}
