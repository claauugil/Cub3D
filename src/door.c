/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:57:06 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/18 23:57:41 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calcula la celda frente al jugador
static void get_front_cell(t_game *game, int *map_x, int *map_y)
{
    double look_x = game->pos_x + game->dir_x;
    double look_y = game->pos_y + game->dir_y;

    *map_x = (int)look_x;
    *map_y = (int)look_y;
}

// Alterna entre 'D' (cerrada) y 'O' (abierta)
void toggle_door(t_game *game)
{
    int mx, my;

    get_front_cell(game, &mx, &my);

    // Verifica que esté dentro del mapa
    if (my < 0 || my >= game->cfg->map_height ||
        mx < 0 || mx >= game->cfg->map_width)
        return;

    char *cell = &game->cfg->map[my][mx];

    if (*cell == 'D')       // si está cerrada, abrir
        *cell = 'O';
    else if (*cell == 'O')  // si está abierta, cerrar
        *cell = 'D';
}