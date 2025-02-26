/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:26:37 by dfernan3          #+#    #+#             */
/*   Updated: 2025/01/10 19:53:26 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define RED "\033[31m"
# define GREY "\033[37m"
# define RESET "\033[0m"

typedef struct s_box
{
	char	**args;
	int		*stack_a;
	int		*stack_b;
	int		*tmp;
	int		len_a;
	int		len_b;
	int		min;
	int		put_name;
	int		small_i;
	int		big_i;
}			t_box;

void		check_num(char *num);
void		ft_error(char *message);
void		two_args(t_box *box, char **av);
void		create_stacks(t_box *box);
void		check_limits(char *num);
void		multi_args(t_box *box, int ac, char **av);
void		check_dup_args(int *stack, int len);
void		ft_index(t_box *box);
void		init_tmp(t_box *box);
int			check_order(t_box *box);
void		free_stacks(t_box *box);
void		algorithms(t_box *box);
void		ft_swapa(t_box *box);
void		ft_swapb(t_box *box);
void		ft_swaps(t_box *box);
void		ft_pusha(t_box *box);
void		ft_pushb(t_box *box);
void		ft_rotatea(t_box *box);
void		ft_rotateb(t_box *box);
void		ft_rotater(t_box *box);
void		ft_rev_rotatea(t_box *box);
void		ft_rev_rotateb(t_box *box);
void		ft_rev_rotater(t_box *box);
void		three_nums_help(t_box *box);
void		find_smallest(t_box *box);
void		push_up(t_box *box);
void		push_upb(t_box *box);
void		find_biggest(t_box *box);
void		two_nums(t_box *box);
void		three_nums(t_box *box);
void		four_nums(t_box *box);
void		five_nums(t_box *box);
void		big_algorithm(t_box *box);
int			ft_sqrt(int nb);

#endif