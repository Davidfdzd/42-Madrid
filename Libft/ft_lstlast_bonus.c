/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:53:43 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/27 15:15:12 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
	t_list *list;
	t_list	*last;
	int		i;
	int u = 15;
	i = 5;
	list = NULL;
	
	ft_lstadd_back(&list, ft_lstnew(&u));
    ft_lstadd_back(&list, ft_lstnew(&i));
    ft_lstadd_back(&list, ft_lstnew(&i));
	last = ft_lstlast(list);
	printf("%d", *(int *)last->content);
}
*/