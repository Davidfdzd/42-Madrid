/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:24:10 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/27 17:52:50 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (slen);
	if (size <= dlen)
		return (size + slen);
	while (((dlen + i) < size - 1) && src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}
/*
int main()
{
	char dest[] = "Viva";
	char s[] = " la vida";
	size_t i  = 3;
	printf("%zu", ft_strlcat(dest, s, i));
	printf("%s", dest);
}
*/