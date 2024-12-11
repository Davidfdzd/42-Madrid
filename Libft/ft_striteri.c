/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:32:17 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/27 17:43:01 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
void	f(unsigned int indice, char *s)
{
	*s = indice + 97;
}
int	main(void)
{
	char	s[] = "aaaaa";

	ft_striteri(s, f);
	printf("%s", s);
	return (0);
}
*/
