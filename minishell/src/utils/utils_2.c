/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:44:57 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/06 13:26:44 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	sort_env(char **env)
{
	int		count;
	int		i;
	int		j;
	char	*temp;

	count = 0;
	i = 0;
	while (env[count] != NULL)
		count++;
	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strcmp(env[j], env[j + 1]) > 0)
			{
				temp = env[j];
				env[j] = env[j + 1];
				env[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	print_char_var(char *str, int out)
{
	char	*tmp;

	ft_putstr_fd("declare -x ", out);
	if (!ft_strchr(str, '='))
		return (ft_putendl_fd(str, out), 0);
	else if ((ft_strchr(str, '=') + 1)[0] == '\0')
	{
		ft_putstr_fd(str, out);
		return (ft_putendl_fd("\"\"", out), 0);
	}
	else
	{
		tmp = ft_substr(str, 0, ft_strchr(str, '=') - str + 1);
		ft_putstr_fd(tmp, out);
		free(tmp);
		tmp = ft_strjoin3("\"", ft_strchr(str, '=') + 1, "\"");
		return (ft_putendl_fd(tmp, out), free(tmp), 0);
	}
}

void	print_sorted_env(t_env **env, int out)
{
	char	**env_arr;
	int		i;

	if (!env || !*env)
		return ;
	env_arr = env_to_array(*env);
	sort_env(env_arr);
	i = 0;
	while (env_arr[i])
	{
		print_char_var(env_arr[i], out);
		i++;
	}
	free_split(env_arr);
}

char	*ft_get_next_line(void)
{
	char	buffer[2];
	int		ret;
	char	*tmp;
	char	*line;

	line = ft_strdup("");
	ret = 1;
	buffer[0] = '\0';
	while (buffer[0] != '\n' && ret > 0)
	{
		ret = read(STDIN_FILENO, buffer, 1);
		buffer[1] = '\0';
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
	}
	return (line);
}
