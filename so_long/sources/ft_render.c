/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:39:42 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/19 15:58:48 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprites(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_identify_sprites(t_game *game, int y, int x)
{
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == WALL)
		ft_render_sprites(game, y, x, game->wall);
	else if (parameter == COINS)
		ft_render_sprites(game, y, x, game->coin);
	else if (parameter == FLOOR)
		ft_render_sprites(game, y, x, game->floor);
	else if (parameter == PLAYER)
		ft_render_sprites(game, y, x, game->player);
	else if (parameter == EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprites(game, y, x, game->open_exit);
		else
			ft_render_sprites(game, y, x, game->exit_closed);
	}
}

void	ft_render_sprites(t_game *game, int y, int x, t_image sprite)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, x
		* sprite.x, y * sprite.y);
}

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movements);
	phrase = ft_strjoin("Movement : ", movements);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 0xFFFFFF, phrase);
	free(movements);
	free(phrase);
}
