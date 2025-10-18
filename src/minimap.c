/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:58:58 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/18 16:08:03 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_minimap(t_game *game)
{
    int y, x;
    int color;

    // --- DIBUJAR EL MAPA ---
    for (y = 0; y < game->cfg->map_height; y++)
    {
        for (x = 0; x < game->cfg->map_width; x++)
        {
            if (game->cfg->map[y][x] == '1')
                color = 0x444444;  // gris oscuro = muro
            else
                color = 0xCCCCCC;  // gris claro = espacio libre

            for (int py = 0; py < TILE_SIZE; py++)
            {
                for (int px = 0; px < TILE_SIZE; px++)
                {
                    int draw_x = x * TILE_SIZE + px;
                    int draw_y = y * TILE_SIZE + py;
                    if (draw_x < WIN_W && draw_y < WIN_H)
                        put_pixel(&game->img, draw_x, draw_y, color);
                }
            }
        }
    }

    // --- DIBUJAR EL JUGADOR ---
    int player_x = (int)(game->pos_x * TILE_SIZE);
    int player_y = (int)(game->pos_y * TILE_SIZE);

    for (int py = -PLAYER_SIZE / 2; py < PLAYER_SIZE / 2; py++)
    {
        for (int px = -PLAYER_SIZE / 2; px < PLAYER_SIZE / 2; px++)
        {
            int draw_x = player_x + px;
            int draw_y = player_y + py;
            if (draw_x >= 0 && draw_y >= 0 && draw_x < WIN_W && draw_y < WIN_H)
                put_pixel(&game->img, draw_x, draw_y, 0xFF0000);
        }
    }

    // --- DIBUJAR LA DIRECCIÓN DEL JUGADOR (FLECHA) ---
    int end_x = player_x + (int)(game->dir_x * LINE_LENGTH);
    int end_y = player_y + (int)(game->dir_y * LINE_LENGTH);

    int dx = abs(end_x - player_x);
    int dy = abs(end_y - player_y);
    int sx = (player_x < end_x) ? 1 : -1;
    int sy = (player_y < end_y) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        if (player_x >= 0 && player_y >= 0 && player_x < WIN_W && player_y < WIN_H)
            put_pixel(&game->img, player_x, player_y, 0xFF0000);

        if (player_x == end_x && player_y == end_y)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; player_x += sx; }
        if (e2 < dx) { err += dx; player_y += sy; }
    }
}