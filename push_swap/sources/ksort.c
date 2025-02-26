/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:49:35 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 20:04:26 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algopart2(t_box *box)
{
	while (box->len_b > 0)
	{
		find_biggest(box);
		push_upb(box);
		ft_pusha(box);
	}
}

void	big_algorithm(t_box *box)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(box->len_a);
	while (box->len_a > 0)
	{
		if (box->stack_a[0] <= i)
		{
			ft_pushb(box);
			ft_rotateb(box);
			i++;
		}
		else if (box->stack_a[0] <= i + range)
		{
			ft_pushb(box);
			i++;
		}
		else
			ft_rotatea(box);
	}
	algopart2(box);
}
