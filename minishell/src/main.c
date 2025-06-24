/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 08:38:43 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/06 16:22:08 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	process_line(char *line, t_shell *shell)
{
	add_history(line);
	g_interactive = NON_INTERACTIVE;
	get_token(line, shell);
	free(line);
	pipeline(shell);
	free_token(shell->token);
	shell->hd = NULL;
	shell->token = NULL;
	shell->pipes = NULL;
	shell->pids = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;
	char	*line;

	(void)argc;
	(void)argv;
	set_signal();
	init_minishell(&shell, envp);
	while (1)
	{
		g_interactive = INTERACTIVE;
		line = readline("minishell> ");
		if (!line)
		{
			ft_putendl_fd("exit", STDERR_FILENO);
			free_shell(shell);
			exit(0);
		}
		else if (!*line)
			free(line);
		else
			process_line(line, shell);
	}
	return (free_shell(shell), 0);
}
