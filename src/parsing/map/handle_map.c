/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:14:40 by claudia           #+#    #+#             */
/*   Updated: 2025/10/22 16:16:57 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_map(char **lines, t_config *cfg, int map_start)
{
	if (validate_map_chars(lines + map_start) == -1)
		return (ft_print_error("Error\ninvalid chars found in map"));
	if (validate_single_player(lines + map_start, cfg) == -1)
		return (-1);
	if (count_map_size(lines + map_start, cfg) == -1)
		return (-1);
	if (allocate_map(cfg) == -1)
		return (-1);
	if (fill_map(lines + map_start, cfg) == -1)
		return (-1);
	if (check_map(cfg) == -1)
		return (-1);
	return (0);
}

/*int handle_map(char **lines, t_config *cfg, int map_start)
{
    int height = 0;
    int width = 0;

    while (lines[map_start + height])
    {
        int len = ft_strlen(lines[map_start + height]);
        if (len > width)
            width = len;
        height++;
    }
    cfg->map_height = height;
    cfg->map_width = width;
    cfg->map = malloc(sizeof(char*) * (height + 1));
    if (!cfg->map)
        return (ft_print_error("Memory allocation failed"));

    for (int i = 0; i < height; i++)
    {
        int len = ft_strlen(lines[map_start + i]);
        cfg->map[i] = malloc(sizeof(char) * (width + 1));
        if (!cfg->map[i])
            return (ft_print_error("Memory allocation failed"));
        ft_memcpy(cfg->map[i], lines[map_start + i], len);
        for (int j = len; j < width; j++)
            cfg->map[i][j] = ' ';
        cfg->map[i][width] = '\0';
    }
    cfg->map[height] = NULL;
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
            else if (c == '0' || c == '1' || c == 'D')
            {
                continue;
            }
            else
            {
                return (ft_print_error("Invalid character in map"));
            }
        }
    }

    if (!player_found)
        return (ft_print_error("No player found"));

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
	return (0);
}*/
