/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:57:06 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/22 09:59:12 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void get_front_cell(t_game *game, int *map_x, int *map_y)
{
    double look_x = game->pos_x + game->dir_x;
    double look_y = game->pos_y + game->dir_y;

    *map_x = (int)look_x;
    *map_y = (int)look_y;
}

void toggle_door(t_game *game)
{
    int mx, my;

    get_front_cell(game, &mx, &my);
    if (my < 0 || my >= game->cfg->map_height ||
        mx < 0 || mx >= game->cfg->map_width)
        return;

    char *cell = &game->cfg->map[my][mx];
    if (*cell == 'D')
        *cell = 'O';
    else if (*cell == 'O')
        *cell = 'D';
}