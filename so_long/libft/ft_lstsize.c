/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:42:53 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/27 11:44:20 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int main()
{
	t_list *list = NULL;
	int		i = 20;
	int u = 15;
	int e = 6;
	
	list = NULL;
    ft_lstadd_back(&list, ft_lstnew(&i));
	ft_lstadd_back(&list, ft_lstnew(&u));
    ft_lstadd_back(&list, ft_lstnew(&e));
	printf("Size:%d\n: ", ft_lstsize(list));
	while (list)
	{
		printf("%d\n", *(int *)list->content);
		list = list->next;
	}
}
*/