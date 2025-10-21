/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:14:40 by claudia           #+#    #+#             */
/*   Updated: 2025/10/21 18:59:31 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_single_player(char **lines)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (lines[i])
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
	if (player < 1)
		return (ft_print_error("Error: no player found"));
	else if (player > 1)
		return (ft_print_error("Error: more than one player found"));
	return (0);
}

int	validate_map_chars(char **map_lines)
{
	int	i;
	int	j;

	i = 0;
	while (map_lines[i])
	{
		j = 0;
		while (map_lines[i][j])
		{
			if (map_lines[i][j] != '0' && map_lines[i][j] != '1' &&
				map_lines[i][j] != 'N' && map_lines[i][j] != 'S' &&
				map_lines[i][j] != 'W' && map_lines[i][j] != 'E' &&
				map_lines[i][j] != ' ' && map_lines[i][j] != '\t')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	*allocate_row(int width)
{
	int		j;
	char	*row;

	row = malloc(width + 1);
	if (!row)
		return (NULL);
	j = 0;
	while (j < width)
	{
		row[j] = ' ';
		j++;
	}
	row[width] = '\0';
	return (row);
}

static void	free_map_partial(char **map, int rows)
{
	while (rows-- > 0)
		free(map[rows]);
	free(map);
}

int	count_map_size(char **lines, t_congif *cfg)
{
	int	i;
	int	len;

	if (!lines || !cfg)
		return (-1);
	i = 0;
	cfg->map_width = 0;
	cfg->map_height = 0;
	while (lines[i])
	{
		len = 0;
		while (lines[i][len])
			len++;
		if (len > cfg->map_width)
			cfg->map_width = len;
		cfg->map_height++;
		i++;
	}
	if (cfg->map_height == 0 || cfg->map_width == 0)
		return (-1);
	return (0);
}
