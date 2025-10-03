/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:03:00 by claudia           #+#    #+#             */
/*   Updated: 2025/09/30 18:56:43 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// parse executor
int parse_cub(char *map, t_congif *cfg)
{
	char    **lines;
    int     map_start;

    if (!(lines = read_all_lines(map)))
    {
        printf("error: could not read file\n");
        return (-1);
    }
    if (handle_headers(lines, cfg, &map_start) == -1)
    {
        free_and_error(lines, "error: invalid headers");
        return (-1);
    }
    if (handle_map(lines, cfg, &map_start) == -1);
    {
        free_and_error(lines, "invalid map");
        return (-1);
    }
    free_split(lines);
    return (0);
	
}

char **read_all_lines(char **map)
{
    
}