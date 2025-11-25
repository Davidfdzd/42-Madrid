/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:12:41 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 15:27:50 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_is_player_coord(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	rgb_to_hex(t_rgb *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}

float	inverse_abs(float value)
{
	float	result;

	if (value == 0.0f)
		return (1000000.0f);
	result = 1.0f / value;
	if (result < 0.0f)
		result = -result;
	return (result);
}
