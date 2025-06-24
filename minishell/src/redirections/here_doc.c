/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:08:37 by csalazar          #+#    #+#             */
/*   Updated: 2025/05/06 14:18:14 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	write_expanded_line_and_free(char *line, int has_quotes,
		int write_fd, t_shell *shell)
{
	char	*expanded_line;

	expanded_line = expand_here_doc(line, has_quotes, shell);
	if (!expanded_line)
		return (free(line), 1);
	write(write_fd, expanded_line, ft_strlen(expanded_line));
	write(write_fd, "\n", 1);
	free(expanded_line);
	free(line);
	return (0);
}

static int	check_and_print_nl(char *line, int write_fd)
{
	if (ft_strcmp(line, "\n") == 0)
	{
		write(write_fd, "\n", 1);
		free(line);
		return (1);
	}
	return (0);
}

static void	run_here_doc_loop(int write_fd, char *delimiter, int has_quotes,
		t_shell *shell)
{
	char	*line;
	size_t	len;

	while (1)
	{
		write(1, "> ", 2);
		line = ft_get_next_line();
		if (!line)
			break ;
		if (check_and_print_nl(line, write_fd))
			continue ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		if (write_expanded_line_and_free(line, has_quotes, write_fd, shell))
			break ;
	}
	close(write_fd);
}

static void	run_here_doc(int *fd, char *delimiter, t_shell *shell)
{
	char	*trimmed_delimiter;
	int		has_quotes;

	has_quotes = 0;
	if (ft_strchr(delimiter, '\'') || ft_strchr(delimiter, '"'))
		has_quotes = 1;
	trimmed_delimiter = trim_line_quotes(delimiter);
	signal(SIGINT, SIG_DFL);
	close(fd[0]);
	run_here_doc_loop(fd[1], trimmed_delimiter, has_quotes, shell);
	free(trimmed_delimiter);
	free_shell(shell);
	exit(EXIT_SUCCESS);
}

int	process_here_doc(char *delimiter, t_shell *shell)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
		return (perror("pipe"), -1);
	pid = fork();
	if (pid < 0)
		return (perror("fork"), -1);
	if (pid == 0)
		run_here_doc(fd, delimiter, shell);
	waitpid(pid, &status, 0);
	close(fd[1]);
	if (WIFSIGNALED(status))
	{
		close(fd[0]);
		shell->last_exit_status = 128 + WTERMSIG(status);
		g_interactive = NON_INTERACTIVE;
		return (-1);
	}
	return (fd[0]);
}
