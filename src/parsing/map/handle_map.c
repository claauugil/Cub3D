/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:14:40 by claudia           #+#    #+#             */
/*   Updated: 2025/10/15 11:04:53 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int validate_map_chars(char **map_lines);
static int validate_single_player(char **lines);

int handle_map(char **lines, t_congif *cfg, int map_start)
{
    (void)cfg;
    if (validate_map_chars(lines + map_start) == -1)
        return (ft_print_error("Error: invalid chars"));
    if (validate_single_player(lines + map_start) == -1)
        return (ft_print_error("More than a single player detected"));
    return (0);
}

static int validate_single_player(char **lines)
{
	int i;
	int j;
	int player;

	i = 0;
	player = 0;
	while(lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == 'N' || lines[i][j] == 'S'
			|| lines[i][j] == 'W' || lines[i][j] == 'E')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (-1);
	printf("only 1 player detected!\n");
	return (0);
}

static int validate_map_chars(char **map_lines)
{
	int	i;
	int	j;

	i = 0;
	while (map_lines[i])
	{
		j = 0;
		while (map_lines[i][j])
		{
			if (map_lines[i][j] != '0' && map_lines[i][j] != '1'&&
				map_lines[i][j] != 'N' && map_lines[i][j] != 'S' &&
				map_lines[i][j] != 'W' && map_lines[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	printf("Valid map chars!\n");
	return (0);
}