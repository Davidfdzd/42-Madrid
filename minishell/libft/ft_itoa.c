/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:25:31 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/28 12:01:52 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_write(char *s, int n)
{
	int	i;

	i = ft_digits(n);
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		len;

	len = ft_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';
	return (ft_write(buffer, n));
}

/*
int main()
{
	int n = 2147483649;
	
	printf("%s", ft_itoa(n));
}
*/