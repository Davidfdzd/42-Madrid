/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:40:33 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 16:56:47 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static int	update_grid_params(t_data *data, char *line, int lines_readed)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (!(ft_isspace(line[j]) || line[j] == '1' || line[j] == '0'
				|| ft_is_player_coord(line[j])))
			return (ft_putendl_fd(BAD_DATA_FORMAT, 2), 1);
		if (ft_is_player_coord(line[j]))
		{
			if (data->player.view)
				return (ft_putendl_fd(DUP_PLAYER, 2), 1);
			data->player.view = line[j];
			data->player.row = lines_readed - data->file_coords_line;
			data->player.col = j;
		}
		j++;
	}
	data->map.height++;
	if (ft_strlen(line) - 1 > (size_t)data->map.width)
		data->map.width = ft_strlen(line) - 1;
	return (0);
}

static int	get_texture_file(char *line, int i, char **texture_file)
{
	if (*texture_file)
		return (ft_putendl_fd(DUP_TEXTURE_FILE, 2), 1);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (ft_putendl_fd(NOT_TEXTURE_FILE_SPEC, 2), 1);
	*texture_file = ft_strdup(&line[i]);
	if ((*texture_file)[ft_strlen(*texture_file) - 1] == '\n')
		(*texture_file)[ft_strlen(*texture_file) - 1] = '\0';
	if (ft_strlen(*texture_file) < 5
		|| ft_strncmp(&(*texture_file)[ft_strlen(*texture_file) - 4], ".xpm",
		4) != 0)
		return (ft_putendl_fd(ERR_FILE_XPM, 2), 1);
	return (0);
}

static int	get_param(t_data *data, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] && line[i + 1] == 'O')
		return (get_texture_file(line, i + 2, &data->no_t_file));
	if (line[i] == 'S' && line[i + 1] && line[i + 1] == 'O')
		return (get_texture_file(line, i + 2, &data->so_t_file));
	if (line[i] == 'W' && line[i + 1] && line[i + 1] == 'E')
		return (get_texture_file(line, i + 2, &data->we_t_file));
	if (line[i] == 'E' && line[i + 1] && line[i + 1] == 'A')
		return (get_texture_file(line, i + 2, &data->ea_t_file));
	if (line[i] == 'F')
		return (get_color_from_line(line, i + 1, &data->f));
	if (line[i] == 'C')
		return (get_color_from_line(line, i + 1, &data->c));
	return (ft_putendl_fd(BAD_DATA_FORMAT, 2), 1);
}

static int	get_data_from_line(t_data *data, char *line, int *is_coords,
		int lines_readed)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i])
	{
		if (*is_coords == READING_COORDS)
			*is_coords = DONE;
		return (0);
	}
	if (*is_coords == READING_PARAMS && (line[i] == '1' || line[i] == '0'))
	{
		*is_coords = READING_COORDS;
		data->file_coords_line = lines_readed;
	}
	if (*is_coords == READING_PARAMS)
		return (get_param(data, line, i));
	if (*is_coords == DONE)
		return (ft_putendl_fd(BAD_DATA_FORMAT, 2), 1);
	return (update_grid_params(data, line, lines_readed));
}

int	parse_file(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		is_coords;
	int		lines_readed;

	is_coords = READING_PARAMS;
	lines_readed = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd(ERR_OPEN_FILE, 2), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (get_data_from_line(data, line, &is_coords, ++lines_readed))
			return (free(line), close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	if (verify_params_complete(data))
		return (close(fd), 1);
	return (close(fd), get_map_grid(data, file));
}
