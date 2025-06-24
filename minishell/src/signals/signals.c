/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 09:53:39 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/06 16:30:29 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_interactive	g_interactive = INTERACTIVE;

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		if (g_interactive == INTERACTIVE)
		{
			write(STDOUT_FILENO, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
		}
		else
			write(STDOUT_FILENO, "\n", 1);
	}
}

void	set_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		ft_exit_error(SIGINT_ERR, EXIT_FAILURE, NULL);
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		ft_exit_error(SIGQUIT_ERR, EXIT_FAILURE, NULL);
}
