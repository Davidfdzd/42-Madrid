/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:26:20 by dfernan3          #+#    #+#             */
/*   Updated: 2024/10/04 17:08:13 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	cdest = (unsigned char *)dest;
	csrc = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int main ()
{
	char src[] = "Hola mundo";
	size_t n = 4;
	char *result = ft_memmove(&src[6], src, n);
	printf("%s", result);
}
*/
