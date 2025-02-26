/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:25:26 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/09 19:22:00 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotatea(t_box *box)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = box->stack_a[0];
	while (++i < box->len_a - 1)
		box->stack_a[i] = box->stack_a[i + 1];
	box->stack_a[i] = tmp;
	if (box->put_name == 0)
		ft_printf("ra\n");
}

void	ft_rotateb(t_box *box)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = box->stack_b[0];
	while (++i < box->len_b - 1)
		box->stack_b[i] = box->stack_b[i + 1];
	box->stack_b[i] = tmp;
	if (box->put_name == 0)
		ft_printf("rb\n");
}

void	ft_rotater(t_box *box)
{
	box->put_name = 1;
	ft_rotatea(box);
	ft_rotateb(box);
	ft_printf("rr\n");
	box->put_name = 0;
}

void	ft_rev_rotatea(t_box *box)
{
	int	tmp;
	int	a;

	a = box->len_a - 1;
	tmp = box->stack_a[a];
	while (a > 0)
	{
		box->stack_a[a] = box->stack_a[a - 1];
		a--;
	}
	box->stack_a[0] = tmp;
	if (box->put_name == 0)
		ft_printf("rra\n");
}

void	ft_rev_rotateb(t_box *box)
{
	int	tmp;
	int	b;

	b = box->len_b - 1;
	tmp = box->stack_b[b];
	while (b > 0)
	{
		box->stack_b[b] = box->stack_b[b - 1];
		b--;
	}
	box->stack_b[0] = tmp;
	if (box->put_name == 0)
		ft_printf("rrb\n");
}
