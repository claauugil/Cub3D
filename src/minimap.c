/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:58:58 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/22 10:02:34 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void mini_put_pixel(t_img *img, int x, int y, int color)
{
    if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
        put_pixel(img, x, y, color);
}

void draw_minimap(t_game *game)
{
    int map_x, map_y;
    int color;

    int offset_x = 30;
    int offset_y = WIN_H - MINIMAP_SIZE - 30;
    int center_x = offset_x + MINIMAP_RADIUS;
    int center_y = offset_y + MINIMAP_RADIUS;

    for (int y = -MINIMAP_RADIUS; y < MINIMAP_RADIUS; y++)
    {
        for (int x = -MINIMAP_RADIUS; x < MINIMAP_RADIUS; x++)
        {
            if ((x * x + y * y) < (MINIMAP_RADIUS * MINIMAP_RADIUS))
            {
                double world_x = game->pos_x + (double)x / TILE_SIZE;
                double world_y = game->pos_y + (double)y / TILE_SIZE;

                map_x = (int)world_x;
                map_y = (int)world_y;

                if (map_x >= 0 && map_y >= 0 &&
                    map_y < game->cfg->map_height &&
                    map_x < game->cfg->map_width)
                {
                    char cell = game->cfg->map[map_y][map_x];
                    if (cell == '1')
                        color = 0x555555;
                    else if (cell == 'D')
                        color = 0x00FF00;
                    else
                        color = 0xCCCCCC;
                }
                else
                    color = 0x000000;

                mini_put_pixel(&game->img, center_x + x, center_y + y, color);
            }
        }
    }
    for (int py = -PLAYER_SIZE / 2; py < PLAYER_SIZE / 2; py++)
    {
        for (int px = -PLAYER_SIZE / 2; px < PLAYER_SIZE / 2; px++)
        {
            mini_put_pixel(&game->img, center_x + px, center_y + py, 0xFF0000);
        }
    }
    int end_x = center_x + (int)(game->dir_x * 15);
    int end_y = center_y + (int)(game->dir_y * 15);
    int dx = abs(end_x - center_x);
    int dy = abs(end_y - center_y);
    int sx, sy;
    if (center_x < end_x) sx = 1; else sx = -1;
    if (center_y < end_y) sy = 1; else sy = -1;
    int err = dx - dy;
    int x0 = center_x;
    int y0 = center_y;
    while (1)
    {
        mini_put_pixel(&game->img, x0, y0, 0xFF0000);
        if (x0 == end_x && y0 == end_y)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
