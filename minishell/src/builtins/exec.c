/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:22:53 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/22 17:17:43 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cmd_is_builtin(char *com)
{
	return (ft_strcmp("pwd", com) == 0 || ft_strcmp("cd", com) == 0
		|| ft_strcmp("echo", com) == 0 || ft_strcmp("exit", com) == 0
		|| ft_strcmp("env", com) == 0 || ft_strcmp("export", com) == 0
		|| ft_strcmp("unset", com) == 0);
}

int	exec_built_in(t_shell *shell, char **cmdargs, t_io *io)
{
	int	code;
	int	out;

	out = STDOUT_FILENO;
	if (io)
		out = io->out;
	if (ft_strcmp("pwd", cmdargs[0]) == 0)
		code = ft_pwd(shell, out);
	else if (ft_strcmp("cd", cmdargs[0]) == 0)
		code = ft_cd(shell, cmdargs, out);
	else if (ft_strcmp("echo", cmdargs[0]) == 0)
		code = ft_echo(cmdargs, out);
	else if (ft_strcmp("exit", cmdargs[0]) == 0)
		code = ft_exit(shell, cmdargs, io);
	else if (ft_strcmp("env", cmdargs[0]) == 0)
		code = ft_env(shell, out);
	else if (ft_strcmp("export", cmdargs[0]) == 0)
		code = ft_export(shell, cmdargs, out);
	else if (ft_strcmp("unset", cmdargs[0]) == 0)
		code = ft_unset(shell, cmdargs);
	if (shell->pipes->nb_pipes > 0)
		exit(code);
	shell->last_exit_status = code;
	return (code);
}
