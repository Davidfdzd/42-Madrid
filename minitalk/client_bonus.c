/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:08:05 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/13 17:31:09 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack_recived = 0;

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_recived = 1;
	if (sig == SIGUSR2)
		g_ack_recived = 3;
}

void	send_len(t_mini *client)
{
	int	i;
	int error;

	i = -1;
	if (g_ack_recived == 3)
		return ;
	while (++i < 32)
	{
		g_ack_recived = 0;
		if (client->len & 0x01)
			error = kill(client->pid, SIGUSR2);
		else
			error = kill(client->pid, SIGUSR1);
		if (error == -1)
			return (ft_printf("El id %d no existe", client->pid), exit(0));
		client->len = client->len >> 1;
		while (!g_ack_recived)
			usleep(WAIT_TIME);
	}
}

void	send_char(int pid, char c)
{
	int	i;
	int error;

	i = -1;
	if (g_ack_recived == 3)
		return ;
	while (++i < 8)
	{
		g_ack_recived = 0;
		if (c & 0x01)
			error = kill(pid, SIGUSR2);
		else
			error = kill(pid, SIGUSR1);
		if (error == -1)
			return (ft_printf("El id %d no existe", pid), exit(0));
		c = c >> 1;
		while (!g_ack_recived)
			usleep(WAIT_TIME);
	}
}

void	init(t_mini *client, char **av)
{
	int	i;

	client->pid = 0;
	client->str_to_send = NULL;
	client->len = 0;
	if (check_error(client, av) == -1)
		return ;
	client->str_to_send = av[2];
	client->len = ft_strlen(client->str_to_send);
	send_len(client);
	g_ack_recived = 0;
	i = -1;
	while (client->str_to_send[++i])
	{
		send_char(client->pid, client->str_to_send[i]);
		g_ack_recived = 0;
	}
}

int	main(int ac, char **av)
{
	t_mini				client;
	struct sigaction	signal;

	if (ac != 3)
	{
		ft_printf("ERROR number of arguments");
		exit(EXIT_FAILURE);
	}
	signal.sa_handler = sig_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = 0;
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
	init(&client, av);
	return (0);
}
