/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:15:12 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/15 15:19:50 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_player_direction(t_game *game, char dir)
{
    if (dir == 'N') // mirando hacia arriba
    {
        game->dir_x = 0;
        game->dir_y = -1;
        game->plane_x = 0.66;
        game->plane_y = 0;
    }
    else if (dir == 'S') // mirando hacia abajo
    {
        game->dir_x = 0;
        game->dir_y = 1;
        game->plane_x = -0.66;
        game->plane_y = 0;
    }
    else if (dir == 'E') // mirando derecha
    {
        game->dir_x = 1;
        game->dir_y = 0;
        game->plane_x = 0;
        game->plane_y = 0.66;
    }
    else if (dir == 'W') // mirando izquierda
    {
        game->dir_x = -1;
        game->dir_y = 0;
        game->plane_x = 0;
        game->plane_y = -0.66;
    }
}

int init_game(t_game *game, t_config *cfg)
{
	game->cfg = cfg;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_print_error("mlx init failed"));

	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "Cub3D");
	if (!game->win)
		return (ft_print_error("window creation failed"));

	// Crear una imagen para dibujar
	game->img.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->img.addr = mlx_get_data_addr(game->img.img,
		&game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);

	// Posición inicial del jugador (por ejemplo, desde el mapa)
	game->pos_x = cfg->player_x;
	game->pos_y = cfg->player_y;
	set_player_direction(game, cfg->player_dir);
		
	    // Opcional: velocidades de movimiento/rotación
   // game->move_speed = 0.05;
    //game->rot_speed = 0.03;
	return (0);
}