/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:22:35 by csalazar          #+#    #+#             */
/*   Updated: 2025/10/29 17:24:42 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define WIDTH 800
# define HEIGHT 600
# define BLOCK 64

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# define PI 3.14159265359

# define ERR_MALLOC "Error allocating memory"
# define ERR_NUM_ARGS "Invalid number of arguments"
# define ERR_FILE_CUB "Invalid file. Expected *.cub"
# define ERR_OPEN_FILE "Error opening file"
# define BAD_DATA_FORMAT "Invalid format on data file"
# define DUP_TEXTURE_FILE "Duplicated texture assignment on data file"
# define NOT_TEXTURE_FILE_SPEC "Not texture file specified"
# define ERR_FILE_XPM "Invalid texture file. Expected *.xpm"
# define DUP_COLOR "Duplicated color assignment on data file"
# define NOT_COLOR_SPEC "Not color specified"
# define INV_COLOR_FORMAT "Invalid color format on data file"
# define INV_RGB_VALUE "RGB values must be between 0-255"
# define DUP_PLAYER "Invalid map, must be only one player"
# define BAD_MAP_DIMS "Invalid map dimmensions"
# define NO_PLAYER "Invalid map, there is no player"
# define OPEN_MAP "Invalid map, the map must be surrounded by walls"
# define MISSING_TEXTURES_ERR "Error: Missing textures or colors in data file"
# define TEXTURE_FILE_ERR "Error: Could not load texture file"
# define NO_MAP_DATA "Error: No map grid data found in file"
# define MAP_FEW_LINES "Error: map has fewer lines than expected"
# define EXTRA_MAP_CONTENT "Error: extra content after map"

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

enum				e_line_reading_status
{
	READING_PARAMS = 0,
	READING_COORDS = 1,
	DONE = 2
};

typedef struct s_ray
{
	float			angle;
	float			pos_x;
	float			pos_y;
	float			dir_x;
	float			dir_y;
	float			delta_x;
	float			delta_y;
	float			side_x;
	float			side_y;
	float			perp_dist;
	float			wall_x;
	float			tex_step;
	float			tex_pos;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				tex_x;
	int				line_height;
	int				*texture;
}					t_ray;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct s_map
{
	int				width;
	int				height;
	char			**grid;
}					t_map;

typedef struct s_player
{
	float			x;
	float			y;
	float			angle;
	char			view;
	int				row;
	int				col;
	bool			key_up;
	bool			key_down;
	bool			key_left;
	bool			key_right;
	bool			rot_left;
	bool			rot_right;
}					t_player;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				file_coords_line;
	char			*no_t_file;
	char			*so_t_file;
	char			*we_t_file;
	char			*ea_t_file;
	int				texture_size;
	int				*no_texture;
	int				*so_texture;
	int				*we_texture;
	int				*ea_texture;
	t_rgb			*f;
	t_rgb			*c;
	int				floor_color;
	int				ceiling_color;
	t_map			map;
	t_player		player;
}					t_data;

int					key_press(int keycode, t_data *data);
int					key_release(int keycode, t_data *data);
int					move_player(t_player *player);
int					draw_loop(t_data *data);
int					init_data(t_data *data, char *file);
int					verify_args(int argc, char **argv);
int					ft_isspace(char c);
int					ft_is_player_coord(char c);
void				free_split(char **split);
int					parse_file(t_data *data, char *file);
int					get_color_from_line(char *line, int i, t_rgb **color);
int					get_map_grid(t_data *data, char *file);
int					rgb_to_hex(t_rgb *color);
int					load_textures(t_data *data);
void				reset_data_img(t_data *data);
void				close_app(t_data *data);
int					close_window(t_data *data);
void				draw_scene(t_data *data);
void				init_ray(t_data *data, t_ray *ray, float angle);
float				inverse_abs(float value);
void				run_dda(t_data *data, t_ray *ray);
void				render_column(t_data *data, t_ray *ray, int column);
void				put_pixel(int x, int y, int color, t_data *data);
void				compute_perp_distance(t_ray *ray);
void				select_texture(t_data *data, t_ray *ray);
void				setup_wall(t_data *data, t_ray *ray);
void				set_player_start(t_data *data);
int					normalize_map_grid(t_map *map);
int					verify_params_complete(t_data *data);
void				free_map_grid_partial(t_map *map, int rows_copied);

#endif
