/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:43:57 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/20 08:23:27 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static int	check_color_line(char *line)
{
	int	i;
	int	num_com;

	i = 0;
	num_com = 0;
	while (line[i])
	{
		if (!(ft_isspace(line[i]) || ft_isdigit(line[i]) || line[i] == ','))
			return (ft_putendl_fd(INV_COLOR_FORMAT, 2), 1);
		if (line[i] == ',')
			num_com++;
		i++;
	}
	if (num_com != 2)
		return (ft_putendl_fd(INV_COLOR_FORMAT, 2), 1);
	return (0);
}

static int	check_color_values(t_rgb *color)
{
	return (color->r > 255 || color->g > 255 || color->b > 255);
}

int	get_color_from_line(char *line, int i, t_rgb **color)
{
	char	**col_split;

	if (*color)
		return (ft_putendl_fd(DUP_COLOR, 2), 1);
	if (check_color_line(line + 1))
		return (1);
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (ft_putendl_fd(NOT_COLOR_SPEC, 2), 1);
	*color = malloc(sizeof(t_rgb));
	col_split = ft_split(&line[i], ',');
	(*color)->r = ft_atoi(col_split[0]);
	(*color)->g = ft_atoi(col_split[1]);
	(*color)->b = ft_atoi(col_split[2]);
	free_split(col_split);
	if (check_color_values(*color))
		return (ft_putendl_fd(INV_RGB_VALUE, 2), 1);
	return (0);
}
