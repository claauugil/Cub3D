/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:15:12 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/25 12:48:09 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	set_player_direction(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
	else if (dir == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}*/

static void set_player_dir_values(t_game *game, t_dir_vals values)
{
	game->dir_x = values.dir_x;
	game->dir_y = values.dir_y;
	game->plane_x = values.plane_x;
	game->plane_y = values.plane_y;
}

void	set_player_direction(t_game *game, char dir)
{
	t_dir_vals values;
	
	if (dir == 'N')
		values = (t_dir_vals){0, -1, 0.66, 0};
	else if (dir == 'S')
		values = (t_dir_vals){0, 1, -0.66, 0};
	else if (dir == 'W')
		values = (t_dir_vals){1, 0, 0, 0.66};
	else if (dir == 'E')
		values = (t_dir_vals){-1, 0, 0, -0.66};
	else
	{
		values.dir_x = 0;
		values.dir_y = 0;
		values.plane_x = 0;
		values.plane_y = 0;
	}
	set_player_dir_values(game, values);
}

void	load_textures(t_game *game)
{
	t_config	*cfg;
	int			i;

	cfg = game->cfg;
	i = 0;
	char *paths[5] = {
		cfg->tex_no,
		cfg->tex_so,
		cfg->tex_we,
		cfg->tex_ea,
		"./textures/door.xpm"
	};
	while (i < 5)
	{
		game->tex[i].img = mlx_xpm_file_to_image(game->mlx, paths[i],
			&game->tex[i].width, &game->tex[i].height);
		if (!game->tex[i].img)
		{
			ft_print_error("Error: texture load failed");
			exit(1);
		}
		game->tex[i].addr = mlx_get_data_addr(game->tex[i].img,
			&game->tex[i].bpp, &game->tex[i].line_len, &game->tex[i].endian);
		i++;
	}
}

int	init_game(t_game *game, t_config *cfg)
{
	game->cfg = cfg;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_print_error("Error\nMlx init failed"));
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "Cub3D");
	if (!game->win)
		return (ft_print_error("Error\nWindow creation failed"));
	game->img.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->img.addr = mlx_get_data_addr(game->img.img,
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->pos_x = cfg->player_x;
	game->pos_y = cfg->player_y;
	set_player_direction(game, cfg->player_dir);
	mlx_hook(game->win, KeyPress, KeyPressMask, handle_key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, handle_key_release, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	load_textures(game);
	return (0);
}
