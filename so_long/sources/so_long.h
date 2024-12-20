/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernan3 <dfernan3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:13:52 by dfernan3          #+#    #+#             */
/*   Updated: 2024/12/19 16:42:48 by dfernan3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <fcntl.h>

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define IMG_HEIGHT 32
# define IMG_WIDTH 32

# define E_FIRST_ROW "Invalid map for the first row. The map must \
be surrounded by walls!!!"
# define E_LAST_ROW "Invalid map for the last row. The map must \
be surrounded by walls!!!"
# define E_FIRST_COLUM "Invalid map for the first column. The map must \
be surrounded by walls!!!"
# define E_LAST_COLUM "Invalid map for the last column. The map must \
be surrounded by walls!!!"
# define E_BEGINNING "Invalid map. The map have an empty line \
at the beginning"
# define E_MIDDLE "Invalid map. The map have an empty line \
in the middle"
# define E_END "Invalid map. The map have an empty line at the end"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define WALL_XPM "resources/sprites/wall.xpm"
# define FLOOR_XPM "resources/sprites/floor.xpm"
# define COINS_XPM "resources/sprites/coin.xpm"
# define PLAYER_XPM "resources/sprites/player.xpm"
# define OPEN_EXIT_XPM "resources/sprites/open_exit.xpm"
# define EXIT_CLOSED_XPM "resources/sprites/closed_exit.xpm"

# define GREY "\033[0;90m"
# define RED "\033[1;31m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define GREEN "\033[0;32m"

typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_image
{
	void		*xpm_ptr;
	int			x;
	int			y;
}				t_image;

typedef struct s_map
{
	char		**full;
	char		**cp_full;
	int			rows;
	int			coins;
	int			columns;
	int			exit;
	int			players;
	t_position	player;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coin;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player;
}				t_game;

void			ft_check_arguments(int ac, char **av, t_game *game);
char			*ft_strappend(char **s1, const char *s2);
void			ft_init_map(t_game *game, char *av);
void			ft_check_for_empty_line(char *map, t_game *game);
void			ft_free_map(t_game *game);
void			ft_destoy_images(t_game *game);
void			ft_free_allocated_memory(t_game *game);
void			ft_init_vars(t_game *game);
void			ft_check_map(t_game *game);
void			ft_check_rows(t_game *game);
void			ft_check_colums(t_game *game);
void			ft_count_parameters(t_game *game);
void			ft_verify_parameters(t_game *game);
void			ft_count_parameters(t_game *game);
void			ft_verify_parameters(t_game *game);
void			ft_init_mlx(t_game *game);
int				ft_error_msg(char *message, t_game *game);
t_image			ft_new_sprite(void *mlx, char *path, t_game *game);
void			ft_init_sprites(t_game *game);
int				ft_render(t_game *game);
void			ft_identify_sprites(t_game *game, int y, int x);
void			ft_render_sprites(t_game *game, int y, int x, t_image sprite);
void			ft_print_movements(t_game *game);
int				ft_handle_input(int keysym, t_game *game);
void			ft_player_move(t_game *game, int new_x, int new_y);
int				ft_victory(t_game *game);
int				ft_close_game(t_game *game);
void			valid_map(char **map, int x, int y);
void			check_map(t_game *game);
void			ft_free_cpmap(t_game *game);

#endif