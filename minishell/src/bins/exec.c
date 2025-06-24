/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:28:14 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/22 17:15:20 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**get_paths(t_env **env)
{
	t_env	*tmp;
	char	**paths;

	tmp = *env;
	while (tmp && ft_strncmp(tmp->name, "PATH", 4))
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	paths = ft_split(tmp->value, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

static char	*get_path(char *cmd, t_env **env)
{
	int		i;
	char	**paths;
	char	*partial_path;
	char	*path_cmd;

	paths = get_paths(env);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		partial_path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(partial_path, cmd);
		free(partial_path);
		if (access(path_cmd, F_OK) == 0)
		{
			free_split(paths);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	free_split(paths);
	return (NULL);
}

void	exec_bin(t_shell *shell, char **cmdargs)
{
	char	*path;
	char	**envp;

	envp = env_to_array(*shell->env);
	if (ft_strchr(cmdargs[0], '/') || get_env_value(shell->env, "PATH") == NULL)
		path = ft_strdup(cmdargs[0]);
	else
		path = get_path(cmdargs[0], shell->env);
	if (path == NULL)
	{
		ft_error_concat(3, "minishell: ", cmdargs[0], ": command not found");
		free_split(envp);
		free_shell(shell);
		free(cmdargs);
		exit(127);
	}
	if (execve(path, cmdargs, envp) == -1)
	{
		ft_error_concat(4, "minishell: ", cmdargs[0], ": ", strerror(errno));
		free(path);
		free_split(envp);
		free_shell(shell);
		free(cmdargs);
		exit(127);
	}
}
