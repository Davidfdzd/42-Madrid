/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:40:47 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/27 09:30:48 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/*
int main()
{
	t_list *list = NULL;
	int		i;

	i = 5;
	ft_lstadd_back(&list, ft_lstnew(&i));
    ft_lstadd_back(&list, ft_lstnew(&i));
    ft_lstadd_back(&list, ft_lstnew(&i));
	printf("%d", *(int *)list->content);
	ft_lstclear(&list, del);
	return 0;
}
*/