/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:20:29 by gmaccha-          #+#    #+#             */
<<<<<<< HEAD:src/render/render.c
<<<<<<< HEAD:src/render/render.c
<<<<<<< HEAD:src/render/render.c
/*   Updated: 2025/10/22 12:44:47 by claudia          ###   ########.fr       */
=======
/*   Updated: 2025/10/15 20:11:27 by gmaccha-         ###   ########.fr       */
>>>>>>> 9844dba (update render_frame):src/render.c
=======
/*   Updated: 2025/10/18 16:00:21 by gmaccha-         ###   ########.fr       */
>>>>>>> 5bb93e5 (update key_press, minimap):src/render.c
=======
/*   Updated: 2025/10/19 00:23:09 by gmaccha-         ###   ########.fr       */
>>>>>>> 89c2067 (update movement, hooks, minimap):src/render.c
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
    int x;

    draw_background(&game->img,
        (game->cfg->ceiling_rgb[0] << 16) | (game->cfg->ceiling_rgb[1] << 8) | game->cfg->ceiling_rgb[2],
        (game->cfg->floor_rgb[0] << 16) | (game->cfg->floor_rgb[1] << 8) | game->cfg->floor_rgb[2]);

    for (x = 0; x < WIN_W; x++)
    {
        // dirección del rayo
        double camera_x = 2 * x / (double)WIN_W - 1;
        double ray_dir_x = game->dir_x + game->plane_x * camera_x;
        double ray_dir_y = game->dir_y + game->plane_y * camera_x;

        int side_hit;
        double perp_wall_dist = cast_single_ray(game, ray_dir_x, ray_dir_y, &side_hit);

        int line_height = (int)(WIN_H / perp_wall_dist);
        int draw_start = -line_height / 2 + WIN_H / 2;
        int draw_end = line_height / 2 + WIN_H / 2;
        if (draw_start < 0) draw_start = 0;
        if (draw_end >= WIN_H) draw_end = WIN_H - 1;

        // seleccionar textura según el lado
       // seleccionar textura según el lado o si es puerta
int tex_num;
char cell = game->cfg->map[(int)(game->pos_y + perp_wall_dist * ray_dir_y)]
                        [(int)(game->pos_x + perp_wall_dist * ray_dir_x)];
if (cell == 'D')          // puerta cerrada
    tex_num = 4;          // textura de puerta
else if (side_hit == 0)
{
    if (ray_dir_x > 0)
        tex_num = 0; // North
    else
        tex_num = 1; // South
}
else
{
    if (ray_dir_y > 0)
        tex_num = 2; // West
    else
        tex_num = 3; // East
}

        // posición exacta donde golpea la pared
        double wall_x;
        if (side_hit == 0)
            wall_x = game->pos_y + perp_wall_dist * ray_dir_y;
        else
            wall_x = game->pos_x + perp_wall_dist * ray_dir_x;
        wall_x -= floor(wall_x);

        int tex_x = (int)(wall_x * (double)game->tex[tex_num].width);
        if ((side_hit == 0 && ray_dir_x > 0) || (side_hit == 1 && ray_dir_y < 0))
            tex_x = game->tex[tex_num].width - tex_x - 1;

        // dibujar la columna
        int y;
        for (y = draw_start; y < draw_end; y++)
        {
            int d = y * 256 - WIN_H * 128 + line_height * 128;
            int tex_y = (d * game->tex[tex_num].height) / line_height / 256;

            char *pixel = game->tex[tex_num].addr +
                          (tex_y * game->tex[tex_num].line_len + tex_x * (game->tex[tex_num].bpp / 8));
            int color = *(int *)pixel;

            put_pixel(&game->img, x, y, color);
        }
    }
<<<<<<< HEAD:src/render/render.c
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
<<<<<<< HEAD:src/render/render.c
}
=======
    draw_minimap(game);
}
>>>>>>> 5bb93e5 (update key_press, minimap):src/render.c
=======
    draw_minimap(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
    
}
>>>>>>> 89c2067 (update movement, hooks, minimap):src/render.c
