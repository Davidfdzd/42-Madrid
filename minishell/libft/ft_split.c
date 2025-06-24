/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:07:50 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/18 17:30:13 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getword(char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (!word)
	{
		free (word);
		return (NULL);
	}
	ft_strlcpy(word, s, i + 1);
	return (word);
}

static int	ft_count_word(char const *s, char c)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				n++;
			i++;
		}
	}
	return (n);
}

static void	ft_freesplit(char **m)
{
	size_t	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**buffer;

	buffer = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!s || !buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		buffer[j] = ft_getword(s + i, c);
		if (!buffer[j])
		{
			ft_freesplit(buffer);
			return (NULL);
		}
		i += ft_strlen(buffer[j]);
		j++;
	}
	buffer[j] = NULL;
	return (buffer);
}
/*
int	main(void)
{
	int		i;
	char	*s;
	char	**p;

	i = 0;
	s = "";
	p = ft_split(s, 'a');
	while (p[i])
	{
		printf("%s\n", p[i]);
		i++;
	}
}
*/
