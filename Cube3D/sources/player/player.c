/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:04:39 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 15:59:52 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static void	translate_player(t_player *player, float cos_angle, float sin_angle,
		int speed)
{
	if (player->key_up)
	{
		player->x += cos_angle * speed;
		player->y += sin_angle * speed;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * speed;
		player->y -= sin_angle * speed;
	}
	if (player->key_left)
	{
		player->x += sin_angle * speed;
		player->y -= cos_angle * speed;
	}
	if (player->key_right)
	{
		player->x -= sin_angle * speed;
		player->y += cos_angle * speed;
	}
}

static void	rotate_player(t_player *player, float angle_speed)
{
	if (player->rot_left)
		player->angle -= angle_speed;
	if (player->rot_right)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

int	move_player(t_player *player)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 3;
	angle_speed = 0.03;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	rotate_player(player, angle_speed);
	translate_player(player, cos_angle, sin_angle, speed);
	return (player->rot_left || player->rot_right || player->key_up
		|| player->key_down || player->key_left || player->key_right);
}

static void	set_angle_from_view(t_player *player)
{
	if (player->view == 'E')
		player->angle = 0;
	else if (player->view == 'S')
		player->angle = PI / 2;
	else if (player->view == 'W')
		player->angle = PI;
	else
		player->angle = (3 * PI) / 2;
}

void	set_player_start(t_data *data)
{
	int		row;
	int		col;
	float	center;

	row = data->player.row;
	col = data->player.col;
	center = 0.5f;
	data->player.x = ((float)col + center) * BLOCK;
	data->player.y = ((float)row + center) * BLOCK;
	data->map.grid[row][col] = '0';
	set_angle_from_view(&data->player);
}
