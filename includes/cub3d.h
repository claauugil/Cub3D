/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:13:59 by claudia           #+#    #+#             */
/*   Updated: 2025/10/20 14:05:58 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 600
#endif

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
	/*int		player_x;
	int		player_y;
	char	player_dir;*/
}	t_congif;

int		validate_map(char *map);
int		validate_file(char *filename);
int		check_open(char *path);
int		parse_cub(char *map, t_congif *cfg);
void	free_split(char **array);
int 	ft_print_error(char *error);
int		free_and_error(char **lines, const char *msg);
char	**read_all_lines(char *map);
int		handle_headers(char **lines, t_congif *cfg, int *map_start);
int		check_texture(char *line, t_congif *cfg);
int		handle_headers(char **lines, t_congif *cfg, int *map_start);
void	free_cfg(t_congif *cfg);
int		check_color(char *line, t_congif *cfg);
int		handle_map(char **lines, t_congif *cfg, int map_start);
int 	check_headers(char *line, t_congif *cfg, int *headers);
///////////////gnl///////////////////////////////////////////////////
char	*get_next_line(int fd);
char	*concat_line(char **store, char *buffer);
char	*tidy_lines(char **store);
int		handle_errors(char **store, char *buffer, ssize_t bytes_read);
///////////////gnl///////////////////////////////////////////////////
/////////////////// map /////////////////////////////
int	allocate_map(t_congif *cfg);
int	count_map_size(char **lines, t_congif *cfg);
int	validate_single_player(char **lines);
int	validate_map_chars(char **map_lines);
int	fill_map(char **map_lines, t_congif *cfg);
int	check_map(t_congif *cfg);
int check_up(char **map, int i, int j);
int check_down(char **map, int i, int j);
int check_left(char **map, int i, int j);
int check_right(char **map, int i, int j);
#endif