/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:18:02 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 15:45:49 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static float	initial_side(float pos, int map, float delta, int step)
{
	float	base;
	float	value;

	if (step == -1)
	{
		base = pos - map;
		value = base * delta;
		return (value);
	}
	if (step == 1)
	{
		base = map + 1.0f - pos;
		value = base * delta;
		return (value);
	}
	return (1000000.0f);
}

static int	compute_step(float direction)
{
	if (direction < 0.0f)
		return (-1);
	if (direction > 0.0f)
		return (1);
	return (0);
}

void	init_ray(t_data *data, t_ray *ray, float angle)
{
	ray->angle = angle;
	ray->pos_x = data->player.x / BLOCK;
	ray->pos_y = data->player.y / BLOCK;
	ray->dir_x = cosf(angle);
	ray->dir_y = sinf(angle);
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_x = inverse_abs(ray->dir_x);
	ray->delta_y = inverse_abs(ray->dir_y);
	ray->step_x = compute_step(ray->dir_x);
	ray->step_y = compute_step(ray->dir_y);
	ray->side_x = initial_side(ray->pos_x, ray->map_x, ray->delta_x,
			ray->step_x);
	ray->side_y = initial_side(ray->pos_y, ray->map_y, ray->delta_y,
			ray->step_y);
	ray->side = 0;
	ray->perp_dist = 0.0f;
	ray->wall_x = 0.0f;
	ray->tex_step = 0.0f;
	ray->tex_pos = 0.0f;
	ray->tex_x = 0;
	ray->line_height = 0;
	ray->texture = NULL;
}

void	run_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x = ray->side_x + ray->delta_x;
			ray->map_x = ray->map_x + ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y = ray->side_y + ray->delta_y;
			ray->map_y = ray->map_y + ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= data->map.width)
			hit = 1;
		else if (ray->map_y < 0 || ray->map_y >= data->map.height)
			hit = 1;
		else if (data->map.grid[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

void	compute_perp_distance(t_ray *ray)
{
	float	offset;

	if (ray->side == 0)
	{
		offset = ray->map_x - ray->pos_x;
		offset = offset + (1 - ray->step_x) * 0.5f;
		ray->perp_dist = offset / ray->dir_x;
		ray->wall_x = ray->pos_y + ray->perp_dist * ray->dir_y;
	}
	else
	{
		offset = ray->map_y - ray->pos_y;
		offset = offset + (1 - ray->step_y) * 0.5f;
		ray->perp_dist = offset / ray->dir_y;
		ray->wall_x = ray->pos_x + ray->perp_dist * ray->dir_x;
	}
	if (ray->perp_dist < 0.0001f)
		ray->perp_dist = 0.0001f;
	ray->wall_x = ray->wall_x - floorf(ray->wall_x);
}
