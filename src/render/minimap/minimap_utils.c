/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 02:15:09 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/24 02:15:12 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mini_put_pixel(t_img *img, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
		put_pixel(img, x, y, color);
}

int	get_cell_color(t_game *game, int map_x, int map_y)
{
	char	cell;

	if (map_x < 0 || map_y < 0
		|| map_y >= game->cfg->map_height
		|| map_x >= game->cfg->map_width)
		return (0x000000);
	cell = game->cfg->map[map_y][map_x];
	if (cell == '1')
		return (0x555555);
	if (cell == 'D')
		return (0x00FF00);
	return (0xCCCCCC);
}
