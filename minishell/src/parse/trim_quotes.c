/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:36:20 by carlossalaz       #+#    #+#             */
/*   Updated: 2025/04/21 15:26:29 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	toggle_quote(char quote, char *s_quote, char *d_quote)
{
	if (quote == '\'')
	{
		if (*s_quote)
			*s_quote = '\0';
		else
			*s_quote = quote;
	}
	else if (quote == '"')
	{
		if (*d_quote)
			*d_quote = '\0';
		else
			*d_quote = quote;
	}
}

char	*trim_line_quotes(char *line)
{
	char	*trimmed_line;
	char	s_quote;
	char	d_quote;
	int		i;
	int		start;

	trimmed_line = NULL;
	s_quote = '\0';
	d_quote = '\0';
	i = 0;
	while (line[i])
	{
		start = i;
		while (line[i] && ((line[i] != '\'' && line[i] != '"')
				|| (line[i] == '\'' && d_quote) || (line[i] == '"'
					&& s_quote)))
			i++;
		trimmed_line = append_word_segment(trimmed_line, line, start, i);
		if ((line[i] == '\'' && !d_quote) || (line[i] == '"' && !s_quote))
			toggle_quote(line[i++], &s_quote, &d_quote);
	}
	return (trimmed_line);
}
