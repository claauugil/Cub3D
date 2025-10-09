/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:03:00 by claudia           #+#    #+#             */
/*   Updated: 2025/10/09 12:52:59 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void rm_empty_lines(char **lines);

// parse organizer

int	parse_cub(char *map, t_congif *cfg)
{
	char	**lines;
	int		map_start;
		
	if (!(lines = read_all_lines(map))) // read lines gnl
		return (free_and_error(NULL, "error: incorrect map\n"));
	rm_empty_lines(lines);
	if (handle_headers(lines, cfg, &map_start) == -1) // parse headers textures/colors
	{
		printf("no texture files provided\n");
		return (free_and_error(lines, "error: invalid headers"));
	}
	/*if (handle_map(lines, cfg, &map_start) == -1) // parse and check map from map_start
		return (free_and_error(lines, "invalid map"));*/
	free_split(lines);
	return (0);
}

static int is_line_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0); // -> not empty
		i++;
	}
	return (1);
}

static void rm_empty_lines(char **lines)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (lines[i])
	{
		if (!is_line_empty(lines[i])) // line is not empty
			lines[j++] = lines[i]; // copy line
		else
			free(lines[i]);
		i++;
	}
	lines[j] = NULL;
}

static int count_lines(const char *file)
{
	int		fd;
	char 	*line;
	int 	cont;

	cont = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
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
	int		i;
	int		num_lines;
	char	*line;
	char	**lines;

	num_lines = count_lines(map);
	if (num_lines <= 0)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * (num_lines + 1));
	if (!lines)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)))
		lines[i++] = line;
	lines[i++] = NULL;
	close(fd);
	return (lines);
}
