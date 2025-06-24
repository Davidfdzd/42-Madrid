/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:32:31 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/22 17:17:17 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_last_cmdarg(char **cmdarg)
{
	int	i;

	if (!cmdarg || !cmdarg[0])
		return (NULL);
	i = 0;
	while (cmdarg[i] && cmdarg[i + 1])
		i++;
	return (cmdarg[i]);
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	size_t	len1;
	size_t	len2;
	size_t	len3;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	result = malloc(len1 + len2 + len3 + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	ft_strlcat(result, s3, len1 + len2 + len3 + 1);
	return (result);
}

static void	copy_env_to_array(char **env_array, t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env->name)
		{
			if (env->value)
				env_array[i] = ft_strjoin3(env->name, "=", env->value);
			else
				env_array[i] = ft_strdup(env->name);
			i++;
		}
		env = env->next;
	}
	env_array[i] = NULL;
}

char	**env_to_array(t_env *env)
{
	int		len;
	t_env	*tmp;
	char	**env_array;

	if (!env)
		return (NULL);
	tmp = env;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	env_array = ft_calloc(len + 1, sizeof(char *));
	if (!env_array)
		return (NULL);
	copy_env_to_array(env_array, env);
	return (env_array);
}

int	len_2d_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (*arr)
	{
		arr++;
		i++;
	}
	return (i);
}
