/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:43:02 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/15 16:50:08 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_n(char *str)
{
	int	i;

	if (str[0] == '-' && str[1] == 'n')
	{
		i = 2;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_echo(char **cmdargs, int out)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (cmdargs[i] && check_n(cmdargs[i]))
	{
		n = 1;
		i++;
	}
	while (cmdargs[i])
	{
		ft_putstr_fd(cmdargs[i], out);
		if (cmdargs[i + 1])
			write(out, " ", 1);
		i++;
	}
	if (n == 0)
		write(out, "\n", 1);
	return (0);
}
