/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:01:10 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/18 18:19:04 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(char **map, int x, int y)
{
	if (y < 0 || x < 0 || map[y][x] == '-' || map[y][x] == '1'
		|| map[y][x] == 'E')
		return ;
	map[y][x] = '-';
	valid_map(map, x + 1, y);
	valid_map(map, x - 1, y);
	valid_map(map, x, y + 1);
	valid_map(map, x, y - 1);
}

void	check_map(t_game *game)
{
	int	y;
	int	x;
	int	count_c;

	count_c = 0;
	valid_map(game->map.cp_full, game->map.player.x, game->map.player.y);
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.cp_full[y][x] == 'C')
				count_c = 1;
			if (game->map.cp_full[y][x] == '0')
				ft_error_msg("IMPOSSIBLE MAP!!!", game);
			x++;
		}
		y++;
	}
	if (count_c == 1)
		ft_error_msg("IMPOSSIBLE MAP!!!", game);
	ft_free_cpmap(game);
}
