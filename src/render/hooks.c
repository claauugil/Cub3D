/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:48:13 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/23 12:06:32 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int close_window(t_game *game)
{
   if (!game) exit(0);
    if (game->img.img)
        mlx_destroy_image(game->mlx, game->img.img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    free_cfg(game->cfg);
    exit(0);
    return (0);
}

int handle_key_press(int keycode, t_game *game)
{

    if (!game || !game->cfg || !game->cfg->map)
    return (0);
    if (keycode == XK_Escape)
    {
        printf("escape\n");
        close_window(game);   
    }
    if (keycode == XK_w)
    {
        printf("w\n");
        move_forward(game);
    }
    else if (keycode == XK_s)
    {
        printf("s\n");
        move_backward(game);
    }
    else if (keycode == XK_a)
    {
        printf("a\n");
        strafe_left(game);
    }
    else if (keycode == XK_d)
    {
        printf("d\n");
        strafe_right(game);
    }
    else if (keycode == XK_Left)
    {
        printf("<-\n");
        rotate_left(game);
    }
    else if (keycode == XK_Right)
    {
        printf("->\n");
        rotate_right(game);
    }
    else if (keycode == XK_space)
        toggle_door(game);
    render_frame(game);
    return (0);
}
