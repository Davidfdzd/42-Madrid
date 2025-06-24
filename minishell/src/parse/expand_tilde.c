/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:43:36 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/21 15:20:34 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_exp_tilde_from_getenv(void)
{
	char	*env_home;

	env_home = getenv("HOME");
	if (env_home)
		return (ft_strdup(env_home));
	else
		return (NULL);
}

static char	*append_expanded_tilde(char *exp_data, char *data, int i,
		t_shell *shell)
{
	t_env	*home;
	char	*exp_tilde;
	char	*exp_tilde_data;

	if ((i > 0 && !ft_isspace(data[i - 1])) || (data[i + 1] != '\0'
			&& data[i + 1] != '/' && !ft_isspace(data[i + 1])))
	{
		exp_tilde_data = append_word_segment(exp_data, "~", 0, 1);
		return (exp_tilde_data);
	}
	home = find_env_var_by_name(shell->env, "HOME");
	if (home && home->value)
		exp_tilde = ft_strdup(home->value);
	else if (home)
		exp_tilde = ft_strdup("");
	else
		exp_tilde = get_exp_tilde_from_getenv();
	if (!exp_tilde)
		exp_tilde = ft_strdup("");
	exp_tilde_data = append_word_segment(exp_data, exp_tilde, 0,
			ft_strlen(exp_tilde));
	free(exp_tilde);
	return (exp_tilde_data);
}

char	*expand_tilde(char *data, t_shell *shell)
{
	char	*exp_data;
	int		i;
	int		start;

	if (!ft_strchr(data, '~') || ft_strchr(data, '"') || ft_strchr(data, '\''))
		return (ft_strdup(data));
	i = 0;
	exp_data = NULL;
	while (data[i])
	{
		start = i;
		while (data[i] && data[i] != '~')
			i++;
		exp_data = append_word_segment(exp_data, data, start, i);
		if (data[i] == '~')
		{
			exp_data = append_expanded_tilde(exp_data, data, i, shell);
			i++;
		}
	}
	return (exp_data);
}
