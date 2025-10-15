/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:14:40 by claudia           #+#    #+#             */
/*   Updated: 2025/10/15 15:38:47 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static int validate_map_chars(char **map_lines);
//static int validate_single_player(char **lines);

int handle_map(char **lines, t_config*cfg, int map_start)
{
	int height = 0;
	int width = 0;

	// Contar filas del mapa y ancho máximo
	while (lines[map_start + height])
	{
		int len = ft_strlen(lines[map_start + height]);
		if (len > width)
			width = len;
		height++;
	}

	cfg->map_height = height;
	cfg->map_width = width;

	// Reservar memoria para el mapa
	cfg->map = malloc(sizeof(char*) * (height + 1));
	if (!cfg->map)
		return (ft_print_error("Memory allocation failed"));

	for (int i = 0; i < height; i++)
	{
		cfg->map[i] = ft_strdup(lines[map_start + i]);
		if (!cfg->map[i])
			return (ft_print_error("Memory allocation failed"));
	}
	cfg->map[height] = NULL;

	// Validar caracteres y detectar jugador
	int player_found = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < (int)ft_strlen(cfg->map[y]); x++)
		{
			char c = cfg->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (player_found)
					return (ft_print_error("More than one player detected"));
				cfg->player_x = x + 0.5;
				cfg->player_y = y + 0.5;
				cfg->player_dir = c;
				cfg->map[y][x] = '0'; // convertir a suelo
				player_found = 1;
			}
			else if (c != '0' && c != '1')
				return (ft_print_error("Invalid character in map"));
		}
	}
	if (!player_found)
		return (ft_print_error("No player found"));

	return (0);
}

/*static int validate_single_player(char **lines)
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
}*/
/*
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
*/