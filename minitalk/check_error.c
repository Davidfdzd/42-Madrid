/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:55:45 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/02 19:01:47 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_error(t_mini *client, char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
		{
			ft_printf("PID need to be only digits!!!");
			return (-1);
		}
		i++;
	}
	client->pid = ft_atoi(av[1]);
	return (0);
}
