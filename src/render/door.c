/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:57:06 by gmaccha-          #+#    #+#             */
/*   Updated: 2025/10/25 11:39:11 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_front_cell(t_game *game, int *map_x, int *map_y)
{
	double	look_x;
	double	look_y;

	look_x = game->pos_x + game->dir_x;
	look_y = game->pos_y + game->dir_y;
	*map_x = (int)look_x;
	*map_y = (int)look_y;
}

void	toggle_door(t_game *game)
{
	int		mx;
	int		my;
	char	*cell;

	get_front_cell(game, &mx, &my);
	if (my < 0 || my >= game->cfg->map_height
		|| mx < 0 || mx >= game->cfg->map_width)
		return ;
	cell = &game->cfg->map[my][mx];
	if (*cell == 'D')
		*cell = 'O';
	else if (*cell == 'O')
		*cell = 'D';
}
