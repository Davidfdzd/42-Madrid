/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:11:58 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/05 18:01:57 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_len_recieved = 0;

void	get_len(int sig, int *len, char **str, siginfo_t *info)
{
	static int	curr_bit;

	if (sig == SIGUSR2)
		*len |= (1 << curr_bit);
	curr_bit++;
	if (curr_bit == 32)
	{
		*str = ft_calloc((*len + 1), sizeof(char));
		if (!*str)
			return ;
		curr_bit = 0;
		g_len_recieved = 1;
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	kill(info->si_pid, SIGUSR1);
}

void	get_char(int sig, int *len, char **str, siginfo_t *info)
{
	static int	curr_bit;
	static int	char_value;
	static int	i = 0;

	if (sig == SIGUSR2)
		char_value |= (1 << curr_bit);
	curr_bit++;
	if (curr_bit == 8)
	{
		(*str)[i++] = (char)char_value;
		curr_bit = 0;
		char_value = 0;
		if (i == *len)
		{
			ft_printf("%s\n", *str);
			g_len_recieved = 0;
			i = 0;
			if (*str)
				free(*str);
			*str = NULL;
			*len = 0;
			kill(info->si_pid, SIGUSR2);
		}
	}
	kill(info->si_pid, SIGUSR1);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	len = 0;
	static char	*str = NULL;

	(void)context;
	if (g_len_recieved == 0)
		get_len(sig, &len, &str, info);
	else
		get_char(sig, &len, &str, info);
}

int	main(void)
{
	struct sigaction	signal;

	ft_printf("Welcome to dfernan3's server!!! :)\n");
	ft_printf("Server´s PID : %d\n", getpid());
	signal.sa_sigaction = signal_handler;
	signal.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &signal, NULL) == -1)
	{
		perror("ERROR registering SIGUSR1 handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
	{
		perror("ERROR registering SIGUSR2 handler");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
