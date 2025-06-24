/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:30:04 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/13 18:48:56 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	buffer = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, ft_strlen(s1) + 1);
	ft_strlcat(buffer, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (buffer);
}
/*
int main()
{
	char s1[] = "Viva";
	char s2[] = "la vida";

	char *result = ft_strjoin(s1, s2);
	printf("%s", result);
}
*/