/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:17:54 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/18 19:17:39 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arguments(int ac, char **av, t_game *game)
{
	int	map_parameter_len;

	game->map_alloc = false;
	if (ac != 2)
		ft_error_msg("Number of arguments must be 2 (./so_long map.ber)", game);
	map_parameter_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Map file extention is wrong (It should be .ber)", game);
}

void	ft_init_map(t_game *game, char *av)
{
	int		map_fd;
	char	*map_tmp;
	char	*line_tmp;

	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
		ft_error_msg("Error to open the map", game);
	map_tmp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_tmp = get_next_line(map_fd);
		if (!line_tmp)
			break ;
		map_tmp = ft_strappend(&map_tmp, line_tmp);
		free(line_tmp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_tmp, game);
	game->map.full = ft_split(map_tmp, '\n');
	game->map.cp_full = ft_split(map_tmp, '\n');
	game->map_alloc = true;
	free(map_tmp);
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg(E_BEGINNING, game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error_msg(E_END, game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg(E_MIDDLE, game);
		}
		i++;
	}
}
