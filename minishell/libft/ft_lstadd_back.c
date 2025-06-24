/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:03:13 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/27 11:31:57 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
int main()
{
	t_list *list;
	int		i;

	i = 5;
	list = NULL;
	ft_lstadd_back(&list, ft_lstnew(&i));
    ft_lstadd_back(&list, ft_lstnew(&i));
    ft_lstadd_back(&list, ft_lstnew(&i));

	printf("%d", *(int *)list->content);
}
*/
