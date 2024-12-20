/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closed_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:23:14 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/19 16:02:59 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_victory(t_game *game)
{
	ft_printf(BLUE "Movements: %d\n" RESET, game->movements + 1);
	ft_free_allocated_memory(game);
	ft_printf(GREEN " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠚⣷⠀⠀⣀⣤⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⣟⢀⡴⠋⠀⠀⣿⠖⠋⢀⡏⠀⠀⠀⡀⡀⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⠀⠀⠀⢀⡀⡼⠀⢸⡟⡸⠀⠀⠀⠃⠀⠀⢸⡧⠜⠛⠛⣻⠃⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⠀⠀⠀⢺⢾⡃⠀⠈⣴⠁⢻⡀⠀⠀⢀⡠⠀⠀⠀⠀⢸⣇⣤⡀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⠀⠀⠀⠸⡜⠂⠀⠀⣟⠀⢸⠑⠀⠰⠁⠀⠀⠀⠀⠀⠛⠉⡼⠁⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⠀⠀⠀⠈⣷⣾⣿⣿⣿⣿⣾⣶⣶⣤⣀⡀⢰⠕⠋⠀⠀⠸⠧⣤⡄\n");
	ft_printf(GREEN "⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣔⠈⣤⣶⡚⠁⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⣠⣶⡀⢸⡟⠿⡿⠿⡟⠻⠿⣿⣿⣿⣿⣿⣿⣿⠿⣿⠋⠁⠀⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⢰⢧⡷⡿⢘⡎⠀⠀⠐⣶⢶⣲⠈⠙⠋⠉⠉⠁⡘⡯⣿⡶⣆⡀⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⢾⢈⣼⣿⣤⣿⣶⣶⣶⣿⣿⣧⣤⣄⣀⣀⣤⣾⣿⣿⢯⢇⣿⢳⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠈⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣌⣷⣬⠏⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⠀⠀⠀⠉⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠻⠟⠋⠁⠀⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⢀⣀⣀⡀⣰⣿⣿⣿⣿⣿⣿⣿⡿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(GREEN "⢀⣤⣶⣴⣿⣿⣿⡧⠀⠉⠙⢿⣿⣿⣿⣿⣾⣶⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(GREEN "⠀⠉⠛⠛⠿⣿⣿⡇⠀⠀⠀⠀⠻⣿⣿⣿⡿⠿⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(GREEN "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠸⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(GREEN "        WINNER!!!              \n" RESET);
	exit(EXIT_SUCCESS);
}

int	ft_close_game(t_game *game)
{
	ft_printf(BLUE "Movements : %d\n" RESET, game->movements);
	ft_free_allocated_memory(game);
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠀⠀⠀⡶⡄⣸⢷⣀⣴⣆⠀⣠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⠙⠃⠀⠛⠁⠸⠟⢛⣧⡴⠚⡇⣀⡀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠏⢹⣇⡤⣤⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⣠⠿⢴⡆⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠠⠾⢤⣤\n");
	ft_printf(RED "⠀⠀⠀⠀⣠⢾⡯⣍⣉⢳⡀⠀⣀⣠⢤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠁\n");
	ft_printf(RED "⠀⠀⢠⡾⠛⠻⣿⠲⢮⣕⣽⣻⣿⣿⣖⡦⣉⢣⡀⠀⠀⠀⠀⠀⠀⣠⠋⠀⠀\n");
	ft_printf(RED "⠀⢠⠏⠀⠀⠀⠀⠀⠀⡽⠋⠁⠀⠀⠨⣿⣮⡳⣣⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀\n");
	ft_printf(RED "⠀⢸⡀⠀⠀⠀⠀⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⢹⣿⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⢱⢤⠞⠉⠉⠒⢧⠀⠀⠀⠀⠀⠀⠀⠀⣸⠇⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⢠⠏⠘⠦⣀⣀⠀⠈⠣⣀⠀⠀⠀⠀⣀⡴⠋⠀⠀⠀⢠⠏⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⢠⠏⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠀⠀⠀⠀⣀⣀⡎⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠸⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠩⣯⣍⣹⠆⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠈⢹⡒⠒⣶⡒⠲⣤⠤⣀⣀⠀⠀⠀⠀⠀⠲⣄⣸⣧⡿⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠉⠉⠀⠙⡏⢻⣶⣾⣿⣽⣶⡀⠀⠀⠀⣸⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠀⢹⡨⣿⣿⣿⣿⣿⣿⣆⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠀⢠⠇⣿⣿⣿⣿⣿⣿⣿⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⡴⠋⢰⣿⣿⡿⠿⢟⢿⡃⠀⢀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠳⠤⣬⡉⠓⢣⠀⠈⠃⢹⡤⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠤⣼⣇⠀⠀⢠⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf(RED "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣄⣀⡞⠁\n\n");
	ft_printf(RED "           CLOSED         \n" RESET);
	exit(EXIT_FAILURE);
}

int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
	{
		ft_free_map(game);
		ft_free_cpmap(game);
	}
	free(game);
	ft_printf(RED "Error\n" GREY "%s\n" RESET, message);
	exit(EXIT_FAILURE);
}
