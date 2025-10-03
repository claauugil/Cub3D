/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:03:00 by claudia           #+#    #+#             */
/*   Updated: 2025/10/03 13:32:36 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// parse organizer

int	parse_cub(char *map, t_congif *cfg)
{
	char	**lines; // array de lineas almacenadas
	int		map_start;
		
	if (!(lines = read_all_lines(map))) // read lines gnl
		return (free_and_error(NULL, "error: incorrect map\n"));
	if (handle_headers(lines, cfg, &map_start) == -1) // parse headers textures/colors
		return (free_and_error(lines, "error: invalid headers"));
	if (handle_map(lines, cfg, &map_start) == -1) // parse and check map from map_start
		return (free_and_error(lines, "invalid map"));
	free_split(lines);
	return (0);
}

static int count_lines(const char *file)
{
	int		fd;
	char 	*line;
	int 	cont;

	cont = 0;
	if (fd = open(file, O_RDONLY) < 0)
		return(-1);
	while ((line = get_next_line(fd)))
	{
		free(line);
		cont++;
	}
	close(fd);
	return (cont);
}

char **read_all_lines(char *map)
{
    int 	fd;
	int		num_lines;
	char	*line;
	char	**lines;

	num_lines = count_lines(map);
	if (num_lines <= 0)
		return (NULL);
		
	lines = malloc(sizeof(char *) * (num_lines + 1));
	if (!lines)
		return (NULL);
		
	if (fd = open(map, O_RDONLY) < 0)
		return (NULL);
	
	close(fd);
}