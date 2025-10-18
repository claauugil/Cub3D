/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:13:59 by claudia           #+#    #+#             */
/*   Updated: 2025/10/22 13:27:45 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 600
#endif

#define WIN_W 640
#define WIN_H 480

#define MOVE_SPEED 0.08
#define ROT_SPEED 0.03

#define TILE_SIZE 8
#define MINIMAP_SIZE 150
#define MINIMAP_RADIUS (MINIMAP_SIZE / 2)
#define PLAYER_SIZE 4


# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_config
{
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	**map;
	int		map_width;
	int		map_height;
	double	player_x;
	double	player_y;
	char	player_dir;
}	t_config;

typedef struct s_img
{
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}   t_img;

typedef struct s_tex
{
	void    *img;
	char    *addr;
	int     width;
	int     height;
	int     bpp;
	int     line_len;
	int     endian;
}   t_tex;

typedef struct s_game
{
	void    *mlx;
	void    *win;
	t_img   img;

	t_config *cfg;

	double  pos_x;
	double  pos_y;
	double  dir_x;
	double  dir_y;
	double  plane_x;
	double  plane_y;
	t_tex   tex[5];
} t_game;

typedef struct s_ray
{
    double perp_dist;
    int side_hit;
    int is_door;
} t_ray;

int		validate_map(char *map);
int		validate_file(char *filename);
int		check_open(char *path);
int		parse_cub(char *map, t_config *cfg);
void	free_split(char **array);
int 	ft_print_error(char *error);
int		free_and_error(char **lines, const char *msg);
char	**read_all_lines(char *map);
int		handle_headers(char **lines, t_config *cfg, int *map_start);
int		check_texture(char *line, t_config *cfg);
int		handle_headers(char **lines, t_config *cfg, int *map_start);
void	free_cfg(t_config *cfg);
int		check_color(char *line, t_config *cfg);
int		handle_map(char **lines, t_config *cfg, int map_start);
int 	check_headers(char *line, t_config *cfg, int *headers);
///////////////gnl///////////////////////////////////////////////////
char	*get_next_line(int fd);
char	*concat_line(char **store, char *buffer);
char	*tidy_lines(char **store);
int		handle_errors(char **store, char *buffer, ssize_t bytes_read);
///////////////gnl///////////////////////////////////////////////////
/////////////////// map /////////////////////////////
int	allocate_map(t_config *cfg);
int	count_map_size(char **lines, t_config *cfg);
int	validate_single_player(char **lines);
int	validate_map_chars(char **map_lines);
int	fill_map(char **map_lines, t_config *cfg);
int	check_map(t_config *cfg);
int check_up(char **map, int i, int j);
int check_down(char **map, int i, int j);
int check_left(char **map, int i, int j);
int check_right(char **map, int i, int j);
int	init_game(t_game *game, t_config *cfg);
void render_frame(t_game *game);
void draw_background(t_img *img, int ceiling, int floor);
void put_pixel(t_img *img, int x, int y, int color);
double cast_single_ray(t_game *game, double ray_dir_x, double ray_dir_y, int *side_hit);
void load_textures(t_game *game);
void move_forward(t_game *game);
void move_backward(t_game *game);
void strafe_left(t_game *game);
void strafe_right(t_game *game);
void rotate_left(t_game *game);
void rotate_right(t_game *game);
int handle_key_press(int keycode, t_game *game);
int close_window(t_game *game);
void draw_minimap(t_game *game);
void toggle_door(t_game *game);

#endif