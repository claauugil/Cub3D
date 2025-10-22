/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:15:12 by gmaccha-          #+#    #+#             */
<<<<<<< HEAD:src/render/init_game.c
<<<<<<< HEAD:src/render/init_game.c
<<<<<<< HEAD:src/render/init_game.c
<<<<<<< HEAD:src/render/init_game.c
/*   Updated: 2025/10/22 12:50:22 by claudia          ###   ########.fr       */
=======
/*   Updated: 2025/10/16 12:36:57 by gmaccha-         ###   ########.fr       */
>>>>>>> 9844dba (update render_frame):src/init_game.c
=======
/*   Updated: 2025/10/18 15:49:24 by gmaccha-         ###   ########.fr       */
>>>>>>> 5bb93e5 (update key_press, minimap):src/init_game.c
=======
/*   Updated: 2025/10/19 00:28:05 by gmaccha-         ###   ########.fr       */
>>>>>>> 89c2067 (update movement, hooks, minimap):src/init_game.c
=======
/*   Updated: 2025/10/22 10:01:04 by claudia          ###   ########.fr       */
>>>>>>> 43d9859 (clean):src/init_game.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_player_direction(t_game *game, char dir)
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
}

void load_textures(t_game *game)
{
    t_config *cfg = game->cfg;

    char *paths[5] = {
        cfg->tex_no,
        cfg->tex_so,
        cfg->tex_we,
        cfg->tex_ea,
        "./textures/door.xpm"
    };

    for (int i = 0; i < 5; i++)
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
    }
}

<<<<<<< HEAD:src/render/init_game.c


void load_textures(t_game *game)
{
    t_config *cfg = game->cfg;

    char *paths[4] = {
        cfg->tex_no,
        cfg->tex_so,
        cfg->tex_we,
        cfg->tex_ea,
        //"./textures/door.xpm"
    };

    for (int i = 0; i < 4; i++)
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
    }
}

=======
>>>>>>> 43d9859 (clean):src/init_game.c
int init_game(t_game *game, t_config *cfg)
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
<<<<<<< HEAD:src/render/init_game.c
<<<<<<< HEAD:src/render/init_game.c
    mlx_hook(game->win, KeyPress, KeyPressMask, handle_key_press, game);
    mlx_hook(game->win, 17, 0, close_window, game);
    load_textures(game);
=======
	
    mlx_hook(game->win, KeyPress, KeyPressMask, handle_key_press, game);
    mlx_hook(game->win, 17, 0, close_window, game); // Para cerrar con la X
    // Cargar las texturas
    load_textures(game); // 👈 aquí
        
	// Opcional: velocidades de movimiento/rotación
   // game->move_speed = 0.05;
    //game->rot_speed = 0.03;
>>>>>>> 9844dba (update render_frame):src/init_game.c
=======
    mlx_hook(game->win, KeyPress, KeyPressMask, handle_key_press, game);
    mlx_hook(game->win, 17, 0, close_window, game);
    load_textures(game);
>>>>>>> 43d9859 (clean):src/init_game.c
	return (0);
}
