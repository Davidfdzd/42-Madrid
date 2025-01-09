/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:56:00 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/26 15:35:06 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sig;
	int	num;

	sig = 1;
	num = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sig = -sig;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num * sig);
}

/*
int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	else
		printf("%d", ft_atoi(argv[1]));
	return 0;
}
*/
