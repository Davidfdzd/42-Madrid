/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:56:26 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/26 19:22:26 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
/*
int main()
{
	t_list *list = NULL;
	int		i;

	i = 5;
	ft_lstnew(&i);
	printf("%d", *(int *)list->content);
	ft_lstdelone(&list, del);
	return 0;
}
*/