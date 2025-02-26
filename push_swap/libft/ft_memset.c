/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:34:13 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/26 15:25:25 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (char)c;
		i++;
	}
	return (s);
}
/*
#include <string.h>
int	main(void)
{
	int		array[] = {1, 77, -88};
	int		c;
	size_t	n;
	int		*result;

	c = 0;
	n = 5;
	result = ft_memset(array, c, n);
	printf("esto es el resultado: %d\n", result[1]);
	return (0);
}
*/
