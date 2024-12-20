/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:15:28 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/18 18:39:43 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error_msg("Allocation failure!!!", game);
	ft_check_arguments(ac, av, game);
	ft_init_map(game, av[1]);
	ft_init_vars(game);
	ft_check_map(game);
	check_map(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_render(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify, ButtonPressMask, ft_close_game,
		game);
	mlx_hook(game->win_ptr, Expose, ExposureMask, ft_render, game);
	mlx_loop(game->mlx_ptr);
	ft_free_allocated_memory(game);
}
