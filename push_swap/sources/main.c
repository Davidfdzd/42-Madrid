/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:24:52 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 20:06:35 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_args(t_box *box, char **av)
{
	int	i;

	i = 0;
	box->args = ft_split(av[1], ' ');
	if (!box->args)
		ft_error("Error in split function!!");
	while (box->args[box->len_a])
	{
		box->put_name = 0;
		check_num(box->args[box->len_a]);
		box->len_a++;
	}
	create_stacks(box);
	while (box->args[i])
	{
		check_limits(box->args[i]);
		box->stack_a[i] = ft_atoi(box->args[i]);
		free(box->args[i]);
		i++;
	}
	free(box->args);
}

void	multi_args(t_box *box, int ac, char **av)
{
	int	i;

	i = 0;
	box->len_a = ac - 1;
	box->put_name = 0;
	create_stacks(box);
	while (i < box->len_a)
	{
		check_num(av[i + 1]);
		check_limits(av[i + 1]);
		box->stack_a[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_box	box;

	box.len_a = 0;
	box.len_b = 0;
	if (ac < 2)
		ft_error("Arguments must be 2 or more");
	if (ac == 2)
		two_args(&box, av);
	if (ac > 2)
		multi_args(&box, ac, av);
	check_dup_args(box.stack_a, box.len_a);
	if (check_order(&box))
		free_stacks(&box);
	else
	{
		ft_index(&box);
		algorithms(&box);
	}
	free_stacks(&box);
}
