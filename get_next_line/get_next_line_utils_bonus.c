/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:42:13 by dfernan3          #+#    #+#             */
/*   Updated: 2025/07/16 17:56:07 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	char	*buffer;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	buffer = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < ft_strlen(s) && s[i])
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < len && s[i])
	{
		buffer[i] = s[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strtrim(char *s1)
{
	char	*tmp;

	if (!s1)
		return (NULL);
	while (*s1 && *s1 != '\n')
		s1++;
	if (*s1 == '\n')
	{
		tmp = ft_substr(s1, 1, ft_strlen(s1) - 1);
		return (tmp);
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	buffer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		buffer[i] = *s2;
		i++;
		s2++;
	}
	buffer[i] = '\0';
	return (buffer);
}
