/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:03:18 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 15:47:50 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static void	clear_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, data);
			x++;
		}
		y++;
	}
}

static void	draw_line(t_data *data, float start_x, int column)
{
	t_ray	ray;

	init_ray(data, &ray, start_x);
	run_dda(data, &ray);
	compute_perp_distance(&ray);
	select_texture(data, &ray);
	setup_wall(data, &ray);
	render_column(data, &ray, column);
}

void	put_pixel(int x, int y, int color, t_data *data)
{
	int	index;

	if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
		return ;
	index = (y * data->line_length) + (x * (data->bpp / 8));
	data->addr[index] = color & 0xFF;
	data->addr[index + 1] = (color >> 8) & 0xFF;
	data->addr[index + 2] = (color >> 16) & 0xFF;
}

void	draw_scene(t_data *data)
{
	float		fraction;
	float		start_x;
	int			i;
	t_player	*player;

	player = &data->player;
	clear_image(data);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - (PI / 6);
	i = 0;
	while (i < WIDTH)
	{
		draw_line(data, start_x, i);
		start_x = start_x + fraction;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	draw_loop(t_data *data)
{
	t_player	*player;

	player = &data->player;
	if (move_player(player))
		draw_scene(data);
	return (0);
}
