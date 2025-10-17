/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:31:18 by cgil              #+#    #+#             */
/*   Updated: 2025/10/17 19:34:04 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void print_arr(t_congif *cfg);

int handle_map(char **lines, t_congif *cfg, int map_start)
{
    if (validate_map_chars(lines + map_start) == -1)
		return (ft_print_error("Error: invalid chars"));
    if (validate_single_player(lines + map_start) == -1)
		return (ft_print_error("More than a single player detected"));
	if (count_map_size(lines + map_start, cfg) == -1)
		return (-1);
	if (allocate_map(cfg) == -1)
		return (-1);
	if (fill_map(lines + map_start, cfg) == -1)
		return (-1);
	/*if (check_map(cfg) == -1)
		return (-1);
	normalize_map(cfg);*/
	print_arr(cfg);
    return (0);
}

static void print_arr(t_congif *cfg)
{
	int i = 0;
	int	j;

	while (cfg->map[i])
	{
		j = 0;
		while (cfg->map[i][j])
		{
			if (cfg->map[i][j] == ' ')
				printf(".");
			else
				printf("%c", cfg->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}