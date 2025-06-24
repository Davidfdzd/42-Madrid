/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:50:05 by csalazar          #+#    #+#             */
/*   Updated: 2025/04/21 17:30:28 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_expanded_variable(int start, int end, char *word,
		t_shell *shell)
{
	char	*tmp1;
	char	*tmp2;

	if (end - start > 1)
	{
		tmp1 = ft_substr(word, start + 1, end - start - 1);
		tmp2 = get_env_value(shell->env, tmp1);
		if (ft_strcmp(tmp1, "PWD") == 0 && !tmp2)
		{
			if (!shell->pwd_unset)
				tmp2 = shell->pwd;
			else
				tmp2 = "";
		}
		free(tmp1);
		if (tmp2)
			return (ft_strdup(tmp2));
		else
			return (NULL);
	}
	else
		return (NULL);
}

static char	*expand_code(int *i, int *end, int start, t_shell *shell)
{
	char	*exp_var;

	exp_var = ft_itoa(shell->last_exit_status);
	*i += 2;
	*end = start + 2;
	return (exp_var);
}

static char	*expand_env_var(int *end, int start, char *word, t_shell *shell)
{
	char	*exp_var;

	*end = start + 1;
	while (word[*end] && (ft_isalnum(word[*end]) || word[*end] == '_'))
		*end += 1;
	exp_var = get_expanded_variable(start, *end, word, shell);
	return (exp_var);
}

char	*add_expanded_variable(char *data, char *word, int *i, t_shell *shell)
{
	char	*exp_var;
	int		start;
	int		end;

	start = *i;
	if (word[start + 1] == '?')
		exp_var = expand_code(i, &end, start, shell);
	else if (word[start + 1] == '_')
	{
		exp_var = ft_strdup(shell->_);
		*i += 2;
		end = start + 2;
	}
	else
		exp_var = expand_env_var(&end, start, word, shell);
	*i = end;
	if (exp_var)
	{
		data = append_word_segment(data, exp_var, 0, ft_strlen(exp_var));
		free(exp_var);
	}
	return (data);
}
