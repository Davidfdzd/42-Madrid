/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:24:45 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/26 14:46:43 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	tokenize_word(char *line, int *i, t_shell *shell)
{
	char	quote;
	int		start;
	char	*token_data;

	start = *i;
	quote = '\0';
	while (line[*i] && (quote || (!quote && !isseparator(line[*i])
				&& !ft_isspace(line[*i]))))
	{
		if ((line[*i] == '\'' || line[*i] == '"') && !quote)
			quote = line[*i];
		else if (line[*i] == quote)
			quote = '\0';
		(*i)++;
	}
	if (quote == '\'')
		return (ft_error_concat(2, UN_TOKEN_ERR, "`''"), 1);
	if (quote == '"')
		return (ft_error_concat(2, UN_TOKEN_ERR, "`\"'"), 1);
	token_data = ft_substr(line, start, *i - start);
	append_token(token_data, WORD, shell, 0);
	return (0);
}

static int	tokenize_separator(char *line, int *i, t_shell *shell)
{
	if (line[*i] == '|')
		append_token(ft_substr(line, *i, 1), PIPE, shell, 0);
	else if (line[*i] == '<')
	{
		if (line[*i + 1] == '<')
			append_token(ft_substr(line, (*i)++, 2), HERE_DOC, shell, 0);
		else
			append_token(ft_substr(line, *i, 1), IN, shell, 0);
	}
	else if (line[*i] == '>')
	{
		if (line[*i + 1] == '>')
			append_token(ft_substr(line, (*i)++, 2), APPEND, shell, 0);
		else
			append_token(ft_substr(line, *i, 1), OUT, shell, 0);
	}
	else
		return (1);
	(*i)++;
	return (0);
}

static int	tokenize(char *line, t_shell *shell)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			i++;
		else if (!isseparator(line[i]))
		{
			if (tokenize_word(line, &i, shell))
				return (1);
		}
		else
		{
			if (tokenize_separator(line, &i, shell))
				return (1);
		}
	}
	return (0);
}

void	get_token(char *line, t_shell *shell)
{
	shell->token = (t_token **)malloc(sizeof(t_token *));
	if (!shell->token)
		shell->token = NULL;
	*(shell->token) = NULL;
	if (tokenize(line, shell))
	{
		free_token(shell->token);
		shell->token = NULL;
		return ;
	}
	if (verify_token(shell->token))
	{
		free_token(shell->token);
		shell->token = NULL;
		return ;
	}
}
