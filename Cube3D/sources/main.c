/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:45:25 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/28 17:44:36 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cube3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (verify_args(argc, argv))
		return (1);
	if (init_data(&data, argv[1]))
		return (close_app(&data), 1);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	draw_scene(&data);
	mlx_loop_hook(data.mlx, draw_loop, &data);
	mlx_loop(data.mlx);
}
