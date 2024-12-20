/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:17:27 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/18 18:43:06 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->map.exit = 0;
	game->map.players = 0;
	game->movements = 0;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("mlx pointer not found!!", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("Couldn't create the Window", game);
	}
}

void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(mlx, FLOOR_XPM, game);
	game->coin = ft_new_sprite(mlx, COINS_XPM, game);
	game->player = ft_new_sprite(mlx, PLAYER_XPM, game);
	game->open_exit = ft_new_sprite(mlx, OPEN_EXIT_XPM, game);
	game->exit_closed = ft_new_sprite(mlx, EXIT_CLOSED_XPM, game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Could not find a sprite", game);
	return (sprite);
}
