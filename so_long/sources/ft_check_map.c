/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:13:05 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/19 19:43:13 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_colums(game);
	ft_count_parameters(game);
	ft_verify_parameters(game);
}

void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error_msg(E_FIRST_ROW, game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error_msg(E_LAST_ROW, game);
		i++;
	}
}

void	ft_check_colums(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error_msg(E_FIRST_COLUM, game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error_msg(E_LAST_COLUM, game);
		i++;
	}
}

void	ft_count_parameters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error_msg("Invalid Map. Not expected map parameters", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COINS)
				game->map.coins++;
			else if (game->map.full[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_verify_parameters(t_game *game)
{
	if (game->map.coins == 0)
		ft_error_msg("Invalid Map. There are not coins!!!", game);
	else if (game->map.players > 1)
		ft_error_msg("Invalid Map. Only can be 1 player", game);
	else if (game->map.players < 1)
		ft_error_msg("Invalid Map. A player is necessary", game);
	else if (game->map.exit != 1)
		ft_error_msg("Invalid Map. There is not exit", game);
}
