/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:00:53 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 16:53:34 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

static void	replace_spaces_with_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == ' ')
				map->grid[i][j] = '1';
			j++;
		}
		i++;
	}
}

static int	set_new_row(t_map *map, int i, size_t copy_len)
{
	size_t	index;
	char	*new_row;

	new_row = malloc((size_t)map->width + 2);
	if (!new_row)
		return (ft_putendl_fd(ERR_MALLOC, 2), 1);
	index = -1;
	while (++index < copy_len)
		new_row[index] = map->grid[i][index];
	while (index < (size_t)map->width)
		new_row[index++] = '1';
	new_row[index] = '\n';
	index++;
	new_row[index] = '\0';
	free(map->grid[i]);
	map->grid[i] = new_row;
	return (0);
}

int	normalize_map_grid(t_map *map)
{
	int		i;
	size_t	len;
	size_t	content_len;

	replace_spaces_with_walls(map);
	i = 0;
	while (map->grid[i])
	{
		len = ft_strlen(map->grid[i]);
		if (len > 0 && map->grid[i][len - 1] == '\n')
			content_len = len - 1;
		else
			content_len = len;
		if (!(content_len == (size_t)map->width && len > 0 && map->grid[i][len
				- 1] == '\n'))
		{
			if (content_len > (size_t)map->width)
				content_len = (size_t)map->width;
			if (set_new_row(map, i, content_len))
				return (1);
		}
		i++;
	}
	return (0);
}
