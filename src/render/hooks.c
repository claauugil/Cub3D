/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:48:13 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/23 19:59:44 by claudia          ###   ########.fr       */
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

/*int handle_key_press(int keycode, t_game *game)
{
    if (!game || !game->cfg || !game->cfg->map)
    return (0);
    if (keycode == XK_Escape)
        close_window(game);   
    if (keycode == XK_w)
        move_forward(game);
    else if (keycode == XK_s)
        move_backward(game);
    else if (keycode == XK_a)
        strafe_left(game);
    else if (keycode == XK_d)
        strafe_right(game);
    else if (keycode == XK_Left)
        rotate_left(game);
    else if (keycode == XK_Right)
        rotate_right(game);
    else if (keycode == XK_space)
        toggle_door(game);
    render_frame(game);
    return (0);
}*/

int	handle_key_press(int keycode, t_game *game)
{
	if (!game || !game->cfg || !game->cfg->map)
		return (0);
	if (keycode == XK_w) 
		game->keys.w = 1;
	else if (keycode == XK_a) 
		game->keys.a = 1;
	else if (keycode == XK_s) 
		game->keys.s = 1;
	else if (keycode == XK_d) 
		game->keys.d = 1;
	else if (keycode == XK_Left) 
		game->keys.left = 1;
	else if (keycode == XK_Right) 
		game->keys.right = 1;
	else if (keycode == XK_Escape)
		close_window(game);
	return (0);
}

int	handle_key_release(int keycode, t_game * game)
{
	if (!game || !game->cfg || !game->cfg->map)
		return (0);
	if (keycode == XK_w)
		game->keys.w = 0;
	else if (keycode == XK_a)
		game->keys.a = 0;
	else if (keycode == XK_s)
		game->keys.s = 0;
	else if (keycode == XK_d)
		game->keys.d = 0;
	else if (keycode == XK_Left)
		game->keys.left = 0;
	else if (keycode == XK_Right)
		game->keys.right = 0;
	return (0);
}

int ft_update(t_game *game)
{
	if (!game || !game->cfg || !game->cfg->map)
        return (0);
	if (game->keys.w)
		move_forward(game);
	if (game->keys.s)
		move_backward(game);
	if (game->keys.a)
        strafe_left(game);
    if (game->keys.d)
        strafe_right(game);
    if (game->keys.left)
        rotate_left(game);
    if (game->keys.right)
		rotate_right(game);

	render_frame(game);
	return (0);
}