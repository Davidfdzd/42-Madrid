/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:34:06 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/26 18:24:26 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int main()
{
  t_list *lst = NULL;
  int i = 15;
  int u = 1;

    ft_lstadd_front(&lst, ft_lstnew(&i));
    ft_lstadd_front(&lst, ft_lstnew(&i));
    ft_lstadd_front(&lst, ft_lstnew(&u));

	printf("%d", *(int *)lst->content);
}
*/
