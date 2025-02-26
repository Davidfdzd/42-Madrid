/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:56:55 by dfernan3          #+#    #+#             */
/*   Updated: 2024/11/15 11:47:31 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_g(char *s)
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

char	*ft_substr_g(char *s, unsigned int start, size_t len)
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

char	*ft_unitrim(char *s1)
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

char	*ft_strjoin_g(char *s1, char *s2)
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
