/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:28:55 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/21 09:02:25 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static void	init_textures(t_data *data)
{
	data->no_t_file = NULL;
	data->so_t_file = NULL;
	data->we_t_file = NULL;
	data->ea_t_file = NULL;
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->f = NULL;
	data->c = NULL;
}

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->angle = 0;
	player->view = '\0';
	player->row = 0;
	player->col = 0;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->rot_left = false;
	player->rot_right = false;
}

static void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
}

int	init_data(t_data *data, char *file)
{
	init_player(&data->player);
	init_map(&data->map);
	init_textures(data);
	data->file_coords_line = 0;
	data->texture_size = 0;
	data->img = NULL;
	data->addr = NULL;
	data->bpp = 0;
	data->line_length = 0;
	data->endian = 0;
	if (parse_file(data, file))
		return (1);
	data->mlx = mlx_init();
	if (load_textures(data))
		return (1);
	reset_data_img(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Game");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
