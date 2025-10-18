/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:48:44 by gmaccha-          #+#    #+#             */
<<<<<<< HEAD:src/render/raycasting.c
<<<<<<< HEAD:src/render/raycasting.c
/*   Updated: 2025/10/22 12:45:11 by claudia          ###   ########.fr       */
=======
/*   Updated: 2025/10/16 12:39:15 by gmaccha-         ###   ########.fr       */
>>>>>>> 9844dba (update render_frame):src/raycasting.c
=======
/*   Updated: 2025/10/19 01:33:32 by gmaccha-         ###   ########.fr       */
>>>>>>> 13a1263 (update minimap):src/raycasting.c
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

<<<<<<< HEAD:src/render/raycasting.c
double cast_single_ray(t_game *game, double ray_dir_x, double ray_dir_y, int *side_hit)
=======
// Calcula la distancia a la pared con el algoritmo DDA
t_ray cast_single_ray(t_game *game, double ray_dir_x, double ray_dir_y)
>>>>>>> 13a1263 (update minimap):src/raycasting.c
{
    int map_x = (int)game->pos_x;
    int map_y = (int)game->pos_y;

    double delta_dist_x;
    double delta_dist_y;

    if (ray_dir_x == 0)
        delta_dist_x = 1e30;
    else
        delta_dist_x = fabs(1 / ray_dir_x);

    if (ray_dir_y == 0)
        delta_dist_y = 1e30;
    else
        delta_dist_y = fabs(1 / ray_dir_y);

    double side_dist_x;
    double side_dist_y;
    int step_x;
    int step_y;
    int hit = 0;
    int side_local = 0;
    int is_door = 0;

    if (ray_dir_x < 0)
    {
        step_x = -1;
        side_dist_x = (game->pos_x - map_x) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - game->pos_x) * delta_dist_x;
    }

    if (ray_dir_y < 0)
    {
        step_y = -1;
        side_dist_y = (game->pos_y - map_y) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - game->pos_y) * delta_dist_y;
    }

    int map_height = 0;
    while (game->cfg->map[map_height])
        map_height++;
    int map_width = ft_strlen(game->cfg->map[0]);

    while (!hit)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side_local = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side_local = 1;
        }

        if (map_y < 0 || map_y >= map_height || map_x < 0 || map_x >= map_width)
        {
            hit = 1;
            break;
        }

        char cell = game->cfg->map[map_y][map_x];
        if (cell == '1')
        {
            hit = 1;
            is_door = 0;
        }
        else if (cell == 'D')
        {
            hit = 1;
            is_door = 1;
        }
    }

    double perp_wall_dist;
    if (side_local == 0)
        perp_wall_dist = (map_x - game->pos_x + (1 - step_x) / 2.0) / ray_dir_x;
    else
        perp_wall_dist = (map_y - game->pos_y + (1 - step_y) / 2.0) / ray_dir_y;

    if (perp_wall_dist <= 0)
        perp_wall_dist = 0.0001;

    t_ray ray;
    ray.perp_dist = perp_wall_dist;
    ray.side_hit = side_local;
    ray.is_door = is_door;
    return ray;
}