/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:14:40 by claudia           #+#    #+#             */
/*   Updated: 2025/10/17 11:44:28 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int count_map_size(char **lines, t_congif *cfg)
{
	int i;
	int len;

	if (!lines || !cfg)
		return (-1);
	i = 0;
	cfg->map_width = 0;
	cfg->map_height = 0;
	while(lines[i])
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

// prepare array and initialize
/*static int allocate_map(t_congif *cfg)
{
	int i;
	int	j;

	i = 0;
	if (!cfg || cfg->map_height <= 0 || cfg->map_width <= 0)
		return (-1);
	cfg->map = malloc(sizeof(char *) * cfg->map_height);
	if (!cfg->map)
		return (-1);
	while (i < cfg->map_height)
	{
		cfg->map[i] = malloc(cfg->map_width + 1);
		if (!cfg->map[i])
		{
			while (i-- > 0)
				free(cfg->map[i]);
			free(cfg->map);
			cfg->map = NULL;
			return (-1);
		}
		j = 0;
		while (j < cfg->map_width)
		{
			cfg->map[i][j] = ' ';
			j++;
		}
		cfg->map[i][cfg->map_width] = '\0';
		i++;
	}
	return (0);
}*/

static int	allocate_map(t_congif *cfg)
{
	int	i;
	int	j;

	if (!cfg || cfg->map_height <= 0 || cfg->map_width <= 0)
		return (-1);
	cfg->map = malloc(sizeof(char *) * (cfg->map_height + 1));
	if (!cfg->map)
		return (-1);
	i = 0;
	while (i < cfg->map_height)
	{
		cfg->map[i] = malloc(cfg->map_width + 1); // +1 para '\0'
		if (!cfg->map[i])
		{
			while (i-- > 0)
				free(cfg->map[i]);
			free(cfg->map);
			cfg->map = NULL;
			return (-1);
		}
		j = 0;
		while (j < cfg->map_width)
		{
			cfg->map[i][j] = ' ';
			j++;
		}
		cfg->map[i][cfg->map_width] = '\0';
		i++;
	}
	cfg->map[cfg->map_height] = NULL; // Fin del array de punteros
	return (0);
}


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
	if (copy_map(lines + map_start) == -1)
		return (-1);
	/*if (check_map(cfg) == -1)
		return (-1);
	normalize_map(cfg);*/
    return (0);
}
