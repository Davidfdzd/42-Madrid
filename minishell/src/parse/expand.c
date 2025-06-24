/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:36:10 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/05/06 16:04:45 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*expand_here_doc(char *line, int has_quotes, t_shell *shell)
{
	char	*data;
	int		i;
	int		start;

	if (has_quotes)
		return (ft_strdup(line));
	data = NULL;
	i = 0;
	while (line[i])
	{
		start = i;
		while (line[i] && line[i] != '$')
			i++;
		data = append_word_segment(data, line, start, i);
		if (line[i] == '$')
			data = add_expanded_variable(data, line, &i, shell);
	}
	return (data);
}

char	*append_word_segment(char *data, char *word, int start, int end)
{
	char	*tmp;
	char	*new_data;

	tmp = ft_substr(word, start, end - start);
	if (!tmp)
		return (data);
	if (!data)
		data = ft_strdup("");
	new_data = ft_strjoin(data, tmp);
	free(tmp);
	if (!new_data)
		return (data);
	free(data);
	return (new_data);
}

char	*expand_line(char *line, t_shell *shell)
{
	char	*data;
	char	s_quote;
	char	d_quote;
	int		start;
	int		i;

	data = NULL;
	s_quote = '\0';
	d_quote = '\0';
	i = 0;
	while (line[i])
	{
		start = i;
		while (line[i] && ((line[i] != '$') || (line[i] == '$' && s_quote)))
		{
			if ((line[i] == '\'' && !d_quote) || (line[i] == '"' && !s_quote))
				toggle_quote(line[i], &s_quote, &d_quote);
			i++;
		}
		data = append_word_segment(data, line, start, i);
		if (line[i] == '$' && !s_quote)
			data = add_expanded_variable(data, line, &i, shell);
	}
	return (data);
}
