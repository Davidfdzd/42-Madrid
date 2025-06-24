/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:16:33 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/22 17:15:31 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_free_exit(t_shell *shell, char **cmdargs, t_io *io, int code)
{
	free_shell(shell);
	free(cmdargs);
	free(io);
	exit(code);
}

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-' && str[1] == '-')
		{
			if (str[2] != '\0')
				return (0);
			return (1);
		}
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_exit_pipes(char **cmdargs)
{
	if (cmdargs[1] && !is_numeric(cmdargs[1]))
	{
		ft_error_concat(4, "exit\n", "minishell: exit: ", cmdargs[1],
			": numeric argument required");
		return (2);
	}
	if (cmdargs[1] && cmdargs[2])
		ft_error("minishell: exit: too many arguments");
	return (0);
}

static void	ft_exit_no_pipes(t_shell *shell, char **cmdargs, t_io *io)
{
	int	exit_num;

	if (cmdargs[1] && !is_numeric(cmdargs[1]))
	{
		ft_error_concat(4, "exit\n", "minishell: exit: ", cmdargs[1],
			": numeric argument required");
		ft_free_exit(shell, cmdargs, io, 2);
	}
	if (cmdargs[1] && cmdargs[2])
	{
		ft_error("exit\nminishell: exit: too many arguments");
		return ;
	}
	if (cmdargs[1])
	{
		exit_num = atoi(cmdargs[1]) % 256;
		printf("exit\n");
		ft_free_exit(shell, cmdargs, io, exit_num);
	}
	printf("exit\n");
	ft_free_exit(shell, cmdargs, io, 0);
}

int	ft_exit(t_shell *minishell, char **cmdargs, t_io *io)
{
	if (minishell->pipes->nb_pipes > 0)
		return (ft_exit_pipes(cmdargs));
	else
		ft_exit_no_pipes(minishell, cmdargs, io);
	return (0);
}
