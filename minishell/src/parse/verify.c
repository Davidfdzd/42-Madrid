/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:39:16 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/12 17:30:25 by carlossalaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_redirection(t_token *token)
{
	return (token->type == IN || token->type == OUT || token->type == HERE_DOC
		|| token->type == APPEND);
}

static int	verify_next_token_to_redirection(t_token *token)
{
	if (!token->next)
	{
		ft_error(UN_TOKEN_NL_ERR);
		return (1);
	}
	if (is_redirection(token->next) || token->next->type == PIPE)
	{
		ft_error_concat(3, "minishell: syntax error near unexpected token `",
			token->next->data, "'");
		return (1);
	}
	return (0);
}

static int	verify_next_token_to_pipe(t_token *token)
{
	if (!token->next)
	{
		ft_error(UN_TOKEN_NL_ERR);
		return (1);
	}
	if (token->next->type == PIPE)
	{
		ft_error(UN_TOKEN_2PIPE_ERR);
		return (1);
	}
	return (0);
}

static void	set_redir_token_data(t_token *token)
{
	t_token	*next_token;

	next_token = token->next;
	free(token->data);
	token->data = next_token->data;
	token->next = next_token->next;
	free(next_token);
}

int	verify_token(t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	if (!tmp)
		return (1);
	if (tmp->type == PIPE && !tmp->next)
	{
		ft_error(UN_TOKEN_PIPE_ERR);
		return (1);
	}
	while (tmp)
	{
		if (tmp->type == PIPE && verify_next_token_to_pipe(tmp))
			return (1);
		if (is_redirection(tmp) && verify_next_token_to_redirection(tmp))
			return (1);
		if (is_redirection(tmp))
			set_redir_token_data(tmp);
		tmp = tmp->next;
	}
	return (0);
}
