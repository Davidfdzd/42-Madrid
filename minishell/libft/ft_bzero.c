/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:44:30 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/26 16:07:29 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int main()
{
	char s[5];
	size_t i = 4;
	int c = 'y';

	ft_memset(s, c, i);
	printf("%s\n", s);
	ft_bzero(s, i);
	printf("%s", s);
}
*/