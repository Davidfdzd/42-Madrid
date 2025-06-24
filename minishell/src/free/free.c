/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:24:50 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/06 14:57:03 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_env(t_env **env)
{
	t_env	*tmp;

	while (*env)
	{
		if ((*env)->name)
			free((*env)->name);
		if ((*env)->value)
			free((*env)->value);
		tmp = *env;
		*env = (*env)->next;
		free(tmp);
	}
	free(env);
}

void	free_shell(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->env)
		free_env(shell->env);
	if (shell->export)
		free_env(shell->export);
	if (shell->pwd)
		free(shell->pwd);
	if (shell->oldpwd)
		free(shell->oldpwd);
	if (shell->_)
		free(shell->_);
	if (shell->token)
		free_token(shell->token);
	if (shell->pipes)
		free_pipes(shell->pipes);
	if (shell->pids)
		free(shell->pids);
	if (shell->hd)
		free(shell->hd);
	free(shell);
	rl_clear_history();
}

void	free_token(t_token **token)
{
	t_token	*tmp;

	if (!token)
		return ;
	if (!*token)
	{
		free (token);
		return ;
	}
	while (*token)
	{
		if ((*token)->data)
			free((*token)->data);
		tmp = *token;
		*token = (*token)->next;
		free(tmp);
	}
	free(token);
}

void	free_pipes(t_pipe *pipes)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (i < pipes->nb_pipes)
	{
		free(pipes->pipes[i]);
		i++;
	}
	free(pipes->pipes);
	free(pipes);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
