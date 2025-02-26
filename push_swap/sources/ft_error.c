/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:23:44 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 19:51:28 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *message)
{
	ft_putendl_fd("Error", 2);
	ft_printf(GREY "%s\n" RESET, message);
	exit(EXIT_FAILURE);
}
