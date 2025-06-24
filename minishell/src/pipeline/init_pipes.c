/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:14:50 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/11 11:00:07 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	get_number_of_pipes(t_token *token)
{
	int		nb_pipes;
	t_token	*tmp;

	nb_pipes = 0;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == PIPE)
			nb_pipes++;
		tmp = tmp->next;
	}
	return (nb_pipes);
}

t_pipe	*init_pipes(t_token *token)
{
	t_pipe	*pipes;
	int		i;

	pipes = ft_calloc(1, sizeof(t_pipe));
	if (!pipes)
		return (NULL);
	pipes->nb_pipes = get_number_of_pipes(token);
	pipes->pipes = ft_calloc(pipes->nb_pipes, sizeof(int *));
	if (!pipes->pipes)
		return (NULL);
	i = 0;
	while (i < pipes->nb_pipes)
	{
		pipes->pipes[i] = ft_calloc(2, sizeof(int));
		if (!pipes->pipes[i])
			return (NULL);
		if (pipe(pipes->pipes[i]) == -1)
		{
			perror("pipe");
			return (NULL);
		}
		i++;
	}
	return (pipes);
}
