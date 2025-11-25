/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:59:12 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/21 10:46:28 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == W)
		data->player.key_up = true;
	if (keycode == S)
		data->player.key_down = true;
	if (keycode == A)
		data->player.key_left = true;
	if (keycode == D)
		data->player.key_right = true;
	if (keycode == LEFT)
		data->player.rot_left = true;
	if (keycode == RIGHT)
		data->player.rot_right = true;
	if (keycode == ESC)
		close_app(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->player.key_up = false;
	if (keycode == S)
		data->player.key_down = false;
	if (keycode == A)
		data->player.key_left = false;
	if (keycode == D)
		data->player.key_right = false;
	if (keycode == LEFT)
		data->player.rot_left = false;
	if (keycode == RIGHT)
		data->player.rot_right = false;
	return (0);
}

int	close_window(t_data *data)
{
	close_app(data);
	return (0);
}
