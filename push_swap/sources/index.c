/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:36 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 20:04:41 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_box *box)
{
	int	i;
	int	j;
	int	count;

	init_tmp(box);
	i = -1;
	while (++i < box->len_a)
	{
		j = -1;
		count = -1;
		while (++j < box->len_a)
		{
			if (box->tmp[i] < box->tmp[j])
				count++;
		}
		box->stack_a[i] = ((box->len_a - 1) - count);
	}
	free(box->tmp);
}

void	algorithms(t_box *box)
{
	if (box->len_a == 2)
		two_nums(box);
	else if (box->len_a == 3)
		three_nums(box);
	else if (box->len_a == 4)
		four_nums(box);
	else if (box->len_a == 5)
		five_nums(box);
	else if (box->len_a >= 6)
		big_algorithm(box);
}
