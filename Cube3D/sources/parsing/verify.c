/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:59:16 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/22 17:40:42 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cube3D.h"

int	verify_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putendl_fd(ERR_NUM_ARGS, 2), 1);
	if (ft_strlen(argv[1]) < 5 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4],
		".cub", 4) != 0)
		return (ft_putendl_fd(ERR_FILE_CUB, 2), 1);
	return (0);
}

int	verify_params_complete(t_data *data)
{
	if (!data->no_t_file || !data->so_t_file || !data->we_t_file
		|| !data->ea_t_file || !data->f || !data->c)
		return (ft_putendl_fd(MISSING_TEXTURES_ERR, 2), 1);
	if (data->map.height == 0 || data->map.width == 0)
		return (ft_putendl_fd(NO_MAP_DATA, 2), 1);
	if (data->map.height < 3 || data->map.width < 3)
		return (ft_putendl_fd(BAD_MAP_DIMS, 2), 1);
	if (data->player.view == '\0')
		return (ft_putendl_fd(NO_PLAYER, 2), 1);
	return (0);
}
