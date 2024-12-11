/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:07:48 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/27 10:32:59 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*map;

	map = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, node);
		lst = lst->next;
	}
	return (map);
}
/*
void	*del(void *m)
{
	free(m);
}

void	*f(void *p)
{
	(*(int *)p) += 5;
	return (p);
}

int main()
{
	t_list *list = NULL;
	t_list *m;
	int		i = 5;
	int u = 15;
	int e = 6;
	
	list = NULL;
	ft_lstadd_back(&list, ft_lstnew(&u));
    ft_lstadd_back(&list, ft_lstnew(&i));
    ft_lstadd_back(&list, ft_lstnew(&e));
	m = ft_lstmap(list, f, (void *)del);
	printf("%d", *(int *)m->content);
}
*/
