/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:13:59 by claudia           #+#    #+#             */
/*   Updated: 2025/10/15 15:20:27 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 600
#endif

#define WIN_W 640
#define WIN_H 480

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
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_config;

typedef struct s_img
{
	void    *img;              // Puntero a la imagen creada con mlx_new_image()
	char    *addr;             // Dirección de memoria donde están los píxeles
	int     bits_per_pixel;    // Cantidad de bits por píxel (normalmente 32)
	int     line_length;       // Cuántos bytes ocupa una línea horizontal
	int     endian;            // Endianness (forma en que se guardan los bytes)
}   t_img;

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
} t_game;

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
int handle_map(char **lines, t_config *cfg, int map_start);
///////////////gnl///////////////////////////////////////////////////
char	*get_next_line(int fd);
char	*concat_line(char **store, char *buffer);
char	*tidy_lines(char **store);
int		handle_errors(char **store, char *buffer, ssize_t bytes_read);
///////////////gnl///////////////////////////////////////////////////

int		init_game(t_game *game, t_config *cfg);
void render_frame(t_game *game);
void draw_background(t_img *img, int ceiling, int floor);
void put_pixel(t_img *img, int x, int y, int color);
double cast_single_ray(t_game *game, double ray_dir_x, double ray_dir_y, int *side_hit);

#endif