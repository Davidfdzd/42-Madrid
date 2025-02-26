/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:25:42 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/09 16:32:47 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotater(t_box *box)
{
	box->put_name = 1;
	ft_rev_rotatea(box);
	ft_rev_rotateb(box);
	ft_printf("rrr\n");
	box->put_name = 0;
}
