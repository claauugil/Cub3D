/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:20:29 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/22 12:44:47 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return;
	char *dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_background(t_img *img, int ceiling, int floor)
{
	for (int y = 0; y < WIN_H / 2; y++)
		for (int x = 0; x < WIN_W; x++)
			put_pixel(img, x, y, ceiling);
	for (int y = WIN_H / 2; y < WIN_H; y++)
		for (int x = 0; x < WIN_W; x++)
			put_pixel(img, x, y, floor);
}

void render_frame(t_game *game)
{
int floor_color = (game->cfg->floor_rgb[0] << 16)
                | (game->cfg->floor_rgb[1] << 8)
                | (game->cfg->floor_rgb[2]);

int ceiling_color = (game->cfg->ceiling_rgb[0] << 16)
                  | (game->cfg->ceiling_rgb[1] << 8)
                  | (game->cfg->ceiling_rgb[2]);

	draw_background(&game->img, ceiling_color, floor_color);

    for (int x = 0; x < WIN_W; x++)
    {
        double camera_x = 2 * x / (double)WIN_W - 1;
        double ray_dir_x = game->dir_x + game->plane_x * camera_x;
        double ray_dir_y = game->dir_y + game->plane_y * camera_x;

        int side;
        double perp_wall_dist = cast_single_ray(game, ray_dir_x, ray_dir_y, &side);

        int line_height = (int)(WIN_H / perp_wall_dist);
        int draw_start = -line_height / 2 + WIN_H / 2;
        if (draw_start < 0)
            draw_start = 0;
        int draw_end = line_height / 2 + WIN_H / 2;
        if (draw_end >= WIN_H)
            draw_end = WIN_H - 1;

        int color;
        if (side == 0) // pared vertical
            color = 0xFF0000; // rojo claro
        else // pared horizontal
            color = 0x800000; // rojo oscuro

        for (int y = draw_start; y <= draw_end; y++)
            put_pixel(&game->img, x, y, color);
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
