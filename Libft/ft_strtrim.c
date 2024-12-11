/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:27:15 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/30 15:17:45 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[end]) && end > 0)
		end--;
	if (end < start)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, (unsigned int)start, end - start + 1));
}
/*
int	main(void)
{
	char	s[] = "abcdba";
	char	set[] = "acb";
	
	char	*result;

	result = ft_strtrim(s, set);
	printf("%s",  result);
}
*/