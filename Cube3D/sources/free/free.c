/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 08:21:05 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/28 17:39:06 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

void	free_map_grid_partial(t_map *map, int rows_copied)
{
	int	i;

	i = 0;
	while (i < rows_copied)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	close_app(t_data *data)
{
	int	i;

	i = 0;
	if (data->no_texture)
		free(data->no_texture);
	if (data->so_texture)
		free(data->so_texture);
	if (data->we_texture)
		free(data->we_texture);
	if (data->ea_texture)
		free(data->ea_texture);
	while (data->map.grid && data->map.grid[i])
	{
		free(data->map.grid[i]);
		i++;
	}
	if (data->map.grid)
		free(data->map.grid);
	reset_data_img(data);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	reset_data_img(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
	data->addr = NULL;
	data->bpp = 0;
	data->line_length = 0;
	data->endian = 0;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
