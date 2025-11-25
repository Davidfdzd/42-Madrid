/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 08:44:22 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/28 17:55:29 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static int	verify_map_borders(t_map *map)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map->grid[++i])
	{
		j = -1;
		while (map->grid[i][++j])
		{
			if (map->grid[i][j] == '0' || ft_is_player_coord(map->grid[i][j]))
			{
				if (i == 0 || i == (size_t)map->height - 1)
					return (1);
				if (j == 0 || j == ft_strlen(map->grid[i]) - 2)
					return (1);
				if (j >= ft_strlen(map->grid[i - 1]) - 1
					|| j >= ft_strlen(map->grid[i + 1]) - 1)
					return (1);
				if (map->grid[i][j - 1] == ' ' || map->grid[i][j + 1] == ' '
					|| map->grid[i - 1][j] == ' ' || map->grid[i + 1][j] == ' ')
					return (1);
			}
		}
	}
	return (0);
}

static int	check_extra_content(t_data *data, char *line, int row)
{
	if (line)
	{
		free(line);
		free_map_grid_partial(&data->map, row);
		return (ft_putendl_fd(EXTRA_MAP_CONTENT, 2), 1);
	}
	return (0);
}

static int	copy_map_grid(t_data *data, int fd)
{
	char	*line;
	int		row;

	row = 0;
	while (row < data->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_putendl_fd(MAP_FEW_LINES, 2), 1);
		data->map.grid[row] = ft_strdup(line);
		free(line);
		if (!data->map.grid[row])
		{
			free_map_grid_partial(&data->map, row);
			return (ft_putendl_fd(ERR_MALLOC, 2), 1);
		}
		row++;
	}
	line = get_next_line(fd);
	if (check_extra_content(data, line, row))
		return (1);
	data->map.grid[row] = NULL;
	return (0);
}

int	get_map_grid(t_data *data, char *file)
{
	int		fd;
	char	*tmp;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd(ERR_OPEN_FILE, 2), 1);
	i = 0;
	while (++i < data->file_coords_line)
	{
		tmp = get_next_line(fd);
		free(tmp);
	}
	data->map.grid = malloc((data->map.height + 1) * sizeof(char *));
	if (!data->map.grid)
		return (ft_putendl_fd(ERR_MALLOC, 2), close(fd), 1);
	if (copy_map_grid(data, fd))
		return (close(fd), 1);
	if (verify_map_borders(&data->map))
		return (ft_putendl_fd(OPEN_MAP, 2), (free_map_grid_partial(&data->map,
					data->map.height), close(fd)), 1);
	if (normalize_map_grid(&data->map))
		return (close(fd), 1);
	set_player_start(data);
	return (close(fd), 0);
}
