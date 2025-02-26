/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:19:46 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/30 11:11:44 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buffer;
	size_t	i;

	i = 0;
	if (!*f)
		return (NULL);
	buffer = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < ft_strlen(s))
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
/*

char	f(unsigned int h, char p)
{
	return (p + h);
}
int	main(void)
{
	char const	*s;

	s = "";
	printf("%s",(char*) ft_strmapi(s, f));
}
*/
