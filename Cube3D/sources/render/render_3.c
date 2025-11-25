/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:31:28 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 15:47:25 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static int	sample_texture(const int *texture, int tex_x, float tex_pos,
		int tex_size)
{
	int	tex_y;

	if (!texture)
		return (0x8B4513);
	tex_y = (int)tex_pos;
	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= tex_size)
		tex_y = tex_size - 1;
	return (texture[tex_y * tex_size + tex_x]);
}

static void	update_wall_bounds(int *top, int *bottom, int height)
{
	*top = (HEIGHT / 2) - (height / 2);
	*bottom = *top + height - 1;
	if (*top < 0)
		*top = 0;
	if (*bottom >= HEIGHT)
		*bottom = HEIGHT - 1;
}

void	select_texture(t_data *data, t_ray *ray)
{
	int	tex_size;
	int	tex_x;

	tex_size = data->texture_size;
	if (tex_size <= 0)
		tex_size = 1;
	tex_x = (int)(ray->wall_x * tex_size);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex_size)
		tex_x = tex_size - 1;
	if (ray->side == 0 && ray->dir_x > 0.0f)
		tex_x = tex_size - tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0.0f)
		tex_x = tex_size - tex_x - 1;
	if (ray->side == 0 && ray->dir_x > 0.0f)
		ray->texture = data->ea_texture;
	else if (ray->side == 0)
		ray->texture = data->we_texture;
	else if (ray->dir_y > 0.0f)
		ray->texture = data->so_texture;
	else
		ray->texture = data->no_texture;
	ray->tex_x = tex_x;
}

void	setup_wall(t_data *data, t_ray *ray)
{
	float	corrected_dist;
	int		line_height;
	int		tex_size;

	corrected_dist = ray->perp_dist * cosf(ray->angle - data->player.angle);
	if (corrected_dist < 0.0001f)
		corrected_dist = 0.0001f;
	line_height = (int)(HEIGHT / corrected_dist);
	if (line_height < 1)
		line_height = 1;
	ray->line_height = line_height;
	tex_size = data->texture_size;
	if (tex_size <= 0)
		ray->tex_step = 0.0f;
	else
		ray->tex_step = (float)tex_size / ray->line_height;
	ray->tex_pos = 0.0f;
}

void	render_column(t_data *data, t_ray *ray, int column)
{
	int	top;
	int	bottom;
	int	y;

	update_wall_bounds(&top, &bottom, ray->line_height);
	ray->tex_pos = top - (HEIGHT / 2 - ray->line_height / 2);
	ray->tex_pos = ray->tex_pos * ray->tex_step;
	y = 0;
	while (y < top)
	{
		put_pixel(column, y, data->ceiling_color, data);
		y++;
	}
	while (y <= bottom)
	{
		put_pixel(column, y, sample_texture(ray->texture, ray->tex_x,
				ray->tex_pos, data->texture_size), data);
		ray->tex_pos = ray->tex_pos + ray->tex_step;
		y++;
	}
	while (y < HEIGHT)
	{
		put_pixel(column, y, data->floor_color, data);
		y++;
	}
}
