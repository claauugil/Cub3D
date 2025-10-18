/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:37:37 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/18 15:46:28 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 🧱 Verifica si la celda está dentro del mapa y no es un muro
static int is_valid_cell(t_game *game, double x, double y)
{
    int map_x = (int)x;
    int map_y = (int)y;

    if (map_x < 0 || map_y < 0
        || map_y >= game->cfg->map_height
        || map_x >= game->cfg->map_width)
        return (0); // fuera de rango → bloqueado

    if (game->cfg->map[map_y][map_x] == '1')
        return (0); // muro → bloqueado

    return (1);
}

//para avanzar
void move_forward(t_game *game)
{
    double new_x = game->pos_x + game->dir_x * MOVE_SPEED;
    double new_y = game->pos_y + game->dir_y * MOVE_SPEED;

    if (is_valid_cell(game, new_x, game->pos_y))
        game->pos_x = new_x;
    if (is_valid_cell(game, game->pos_x, new_y))
        game->pos_y = new_y;
}

//retroceder

void move_backward(t_game *game)
{
     double new_x = game->pos_x - game->dir_x * MOVE_SPEED;
    double new_y = game->pos_y - game->dir_y * MOVE_SPEED;

    if (is_valid_cell(game, new_x, game->pos_y))
        game->pos_x = new_x;
    if (is_valid_cell(game, game->pos_x, new_y))
        game->pos_y = new_y;
}

//izquierda

void strafe_left(t_game *game)
{
    double new_x = game->pos_x - game->plane_x * MOVE_SPEED;
    double new_y = game->pos_y - game->plane_y * MOVE_SPEED;

    if (is_valid_cell(game, new_x, game->pos_y))
        game->pos_x = new_x;
    if (is_valid_cell(game, game->pos_x, new_y))
        game->pos_y = new_y;
}

void strafe_right(t_game *game)
{
    double new_x = game->pos_x + game->plane_x * MOVE_SPEED;
    double new_y = game->pos_y + game->plane_y * MOVE_SPEED;

    if (is_valid_cell(game, new_x, game->pos_y))
        game->pos_x = new_x;
    if (is_valid_cell(game, game->pos_x, new_y))
        game->pos_y = new_y;
}

void rotate_left(t_game *game)
{
    double old_dir_x = game->dir_x;
    game->dir_x = game->dir_x * cos(ROT_SPEED) - game->dir_y * sin(ROT_SPEED);
    game->dir_y = old_dir_x * sin(ROT_SPEED) + game->dir_y * cos(ROT_SPEED);

    double old_plane_x = game->plane_x;
    game->plane_x = game->plane_x * cos(ROT_SPEED) - game->plane_y * sin(ROT_SPEED);
    game->plane_y = old_plane_x * sin(ROT_SPEED) + game->plane_y * cos(ROT_SPEED);
}

void rotate_right(t_game *game)
{
    double old_dir_x = game->dir_x;
    game->dir_x = game->dir_x * cos(-ROT_SPEED) - game->dir_y * sin(-ROT_SPEED);
    game->dir_y = old_dir_x * sin(-ROT_SPEED) + game->dir_y * cos(-ROT_SPEED);

    double old_plane_x = game->plane_x;
    game->plane_x = game->plane_x * cos(-ROT_SPEED) - game->plane_y * sin(-ROT_SPEED);
    game->plane_y = old_plane_x * sin(-ROT_SPEED) + game->plane_y * cos(-ROT_SPEED);
}
