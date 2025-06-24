/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:09:52 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/21 15:14:09 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit_error(char *message, int status, t_shell *shell)
{
	if (shell)
		free_shell(shell);
	if (message)
		ft_putendl_fd(message, 2);
	exit(status);
}

void	ft_error(char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
}

void	ft_error_concat(int count, ...)
{
	int		i;
	char	*msg;
	va_list	args;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		msg = va_arg(args, char *);
		ft_putstr_fd(msg, 2);
		i++;
	}
	ft_putstr_fd("\n", 2);
	va_end(args);
}

void	ft_error_cd_not_file(char *file)
{
	ft_error_concat(3, "minishell: cd: ", file, ": No such file or directory");
}
