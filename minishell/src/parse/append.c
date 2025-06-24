/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:53:40 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/22 17:16:47 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	tokenize_expansion(char *data, char *expanded, t_shell *shell)
{
	int		i;
	char	**split;
	char	*trimmed;

	if (ft_strchr(data, '\'') || ft_strchr(data, '"'))
	{
		trimmed = trim_line_quotes(expanded);
		append_token(trimmed, WORD, shell, 1);
		return (0);
	}
	split = ft_split(expanded, ' ');
	i = 0;
	while (split[i])
	{
		append_token(ft_strdup(split[i]), WORD, shell, 1);
		i++;
	}
	free_split(split);
	return (0);
}

static t_token	*append_token_no_exp(char *data, t_shell *shell, int is_exp)
{
	t_token	*new_token;
	char	*tmp;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	tmp = expand_tilde(data, shell);
	if (!is_exp)
		new_token->data = trim_line_quotes(tmp);
	else
		new_token->data = ft_strdup(tmp);
	free(data);
	free(tmp);
	return (new_token);
}

static void	set_token_type_next(t_token *new_token, t_token_type type,
		t_token *last_token, t_shell *shell)
{
	new_token->type = type;
	new_token->next = NULL;
	if (!last_token)
		*(shell->token) = new_token;
	else
		last_token->next = new_token;
}

static t_token	*append_to_here_doc(char *data)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->data = data;
	return (new_token);
}

void	append_token(char *data, t_token_type type, t_shell *shell, int is_exp)
{
	t_token	*curr_token;
	t_token	*last_token;
	t_token	*new_token;
	char	*expanded;

	new_token = NULL;
	curr_token = *(shell->token);
	last_token = get_last_token(curr_token);
	if (last_token && last_token->type == HERE_DOC)
		new_token = append_to_here_doc(data);
	else if (ft_strchr(data, '$') && !is_exp)
	{
		expanded = expand_line(data, shell);
		tokenize_expansion(data, expanded, shell);
		free(expanded);
		free(data);
	}
	else
		new_token = append_token_no_exp(data, shell, is_exp);
	if (new_token)
		set_token_type_next(new_token, type, last_token, shell);
}
