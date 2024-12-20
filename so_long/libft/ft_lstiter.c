/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:45:44 by dfernan3          #+#    #+#             */
/*   Updated: 2024/09/27 11:30:47 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	*f(void *p)
{
	(*(int *)p) += 5;
	return (p);
}

int	main(void)
{
	t_list	*x;

	x = NULL;
	int i= 5;
	ft_lstadd_front(&x, ft_lstnew(&i));
	ft_lstiter(x, (void *)f);
	printf("%d", *(int *)x->content);
}
*/
