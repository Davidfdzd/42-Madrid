/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:25:11 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/09 19:22:22 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapa(t_box *box)
{
	int	tmp;

	if (box->len_a > 1)
	{
		tmp = box->stack_a[0];
		box->stack_a[0] = box->stack_a[1];
		box->stack_a[1] = tmp;
		if (box->put_name == 0)
			ft_printf("sa\n");
	}
}

void	ft_swapb(t_box *box)
{
	int	tmp;

	if (box->len_b > 1)
	{
		tmp = box->stack_b[0];
		box->stack_b[0] = box->stack_b[1];
		box->stack_b[1] = tmp;
		if (box->put_name == 0)
			ft_printf("sb\n");
	}
}

void	ft_swaps(t_box *box)
{
	box->put_name = 1;
	ft_swapa(box);
	ft_swapb(box);
	ft_printf("ss\n");
	box->put_name = 0;
}

void	ft_pusha(t_box *box)
{
	int	a;
	int	b;

	if (box->len_b > 0)
	{
		box->len_a++;
		a = box->len_a;
		while (--a > 0)
			box->stack_a[a] = box->stack_a[a - 1];
		box->stack_a[a] = box->stack_b[0];
		box->len_b--;
		b = box->len_b;
		while (a < b)
		{
			box->stack_b[a] = box->stack_b[a + 1];
			a++;
		}
		box->stack_b[a] = 0;
		ft_printf("pa\n");
	}
}

void	ft_pushb(t_box *box)
{
	int	a;
	int	b;

	if (box->len_a > 0)
	{
		box->len_b++;
		b = box->len_b;
		while (--b > 0)
			box->stack_b[b] = box->stack_b[b - 1];
		box->stack_b[b] = box->stack_a[0];
		box->len_a--;
		a = box->len_a;
		while (b < a)
		{
			box->stack_a[b] = box->stack_a[b + 1];
			b++;
		}
		box->stack_a[b] = 0;
		ft_printf("pb\n");
	}
}
