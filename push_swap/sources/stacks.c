/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:54 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 20:04:48 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacks(t_box *box)
{
	box->stack_a = malloc(box->len_a * sizeof(int));
	if (!box->stack_a)
		ft_error("Error to create malloc for stack_a!!");
	box->stack_b = malloc(box->len_a * sizeof(int));
	if (!box->stack_b)
		ft_error("Error to create malloc for stack_b!!");
}

void	init_tmp(t_box *box)
{
	int	i;

	box->tmp = malloc(box->len_a * sizeof(long));
	if (!box->tmp)
		ft_error("To create malloc!!");
	i = -1;
	while (++i < box->len_a)
		box->tmp[i] = box->stack_a[i];
}

void	free_stacks(t_box *box)
{
	free(box->stack_a);
	free(box->stack_b);
	exit(0);
}
