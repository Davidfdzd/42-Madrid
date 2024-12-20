/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:19:27 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/18 18:21:29 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		ft_player_move(game, game->map.player.x, game->map.player.y - 1);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		ft_player_move(game, game->map.player.x, game->map.player.y + 1);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		ft_player_move(game, game->map.player.x + 1, game->map.player.y);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		ft_player_move(game, game->map.player.x - 1, game->map.player.y);
	if (keysym == KEY_ESC || keysym == KEY_Q)
		ft_close_game(game);
	return (0);
}

void	ft_player_move(t_game *game, int new_x, int new_y)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == EXIT && game->map.coins == 0)
		ft_victory(game);
	else if ((game->map.full[new_y][new_x] == FLOOR)
		|| (game->map.full[new_y][new_x] == COINS))
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[new_y][new_x] == COINS)
			game->map.coins--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->movements++;
		ft_printf(GREY "Movements : %d\n" RESET, game->movements);
		ft_render(game);
	}
}
