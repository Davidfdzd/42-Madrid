/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:15:59 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 16:58:30 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static void	get_texture_pixels(t_data *data, int **texture, int bytes_per_pixel)
{
	int				x;
	int				y;
	int				alpha;
	unsigned char	*src;

	y = 0;
	while (y < data->texture_size)
	{
		x = 0;
		while (x < data->texture_size)
		{
			src = (unsigned char *)(data->addr + y * data->line_length + x
					* bytes_per_pixel);
			if (bytes_per_pixel == 4)
				alpha = src[3] << 24;
			else
				alpha = 0;
			(*texture)[y * data->texture_size
				+ x] = src[0] | (src[1] << 8) | (src[2] << 16) | alpha;
			x++;
		}
		y++;
	}
}

static int	get_texture(t_data *data, char *file, int **texture)
{
	int	bytes_per_pixel;

	reset_data_img(data);
	data->img = mlx_xpm_file_to_image(data->mlx, file, &data->texture_size,
			&data->texture_size);
	if (!data->img)
		return (ft_putendl_fd(TEXTURE_FILE_ERR, 2), 1);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	bytes_per_pixel = data->bpp / 8;
	if (bytes_per_pixel <= 0)
		bytes_per_pixel = 4;
	*texture = ft_calloc(data->texture_size * data->texture_size, sizeof(int));
	if (!*texture)
		return (reset_data_img(data), ft_putendl_fd(ERR_MALLOC, 2), 1);
	get_texture_pixels(data, texture, bytes_per_pixel);
	return (0);
}

int	load_textures(t_data *data)
{
	data->ceiling_color = rgb_to_hex(data->c);
	data->floor_color = rgb_to_hex(data->f);
	data->texture_size = 0;
	if (get_texture(data, data->no_t_file, &data->no_texture)
		|| get_texture(data, data->so_t_file, &data->so_texture)
		|| get_texture(data, data->we_t_file, &data->we_texture)
		|| get_texture(data, data->ea_t_file, &data->ea_texture))
		return (1);
	return (0);
}
