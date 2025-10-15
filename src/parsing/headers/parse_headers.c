/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_headers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:30:27 by claudia           #+#    #+#             */
/*   Updated: 2025/10/15 13:27:06 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_map_line(char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	return (line[j] == '1' || line[j] == '0');
}
static int is_texture_line(char *line)
{
    while (*line == ' ')
        line++;
    if (!ft_strncmp(line, "NO", 2) && line[2] == ' ')
        return (1);
    if (!ft_strncmp(line, "SO", 2) && line[2] == ' ')
        return (1);
    if (!ft_strncmp(line, "WE", 2) && line[2] == ' ')
        return (1);
    if (!ft_strncmp(line, "EA", 2) && line[2] == ' ')
        return (1);
    return (0);
}

static int is_color_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if ((*line == 'F' || *line == 'C')
		&& (line[1] == ' ' || line[1] == '\t'))
		return(1);
	return (0);
}

int	handle_headers(char **lines, t_config *cfg, int *map_start)
{
    int	i;
	int	headers;
	
	i = 0;
	headers = 0;
	while(lines[i])
	{
		if (is_map_line(lines[i]))
		{
			*map_start = i;
			break;
		}
		else if (is_texture_line(lines[i]))
		{
			if (check_texture(lines[i], cfg) == -1)
				return (-1);
			headers++;
		}
		else if (is_color_line(lines[i]))
		{
			if (check_color(lines[i], cfg) == -1)
				return (-1);
			headers++;
		}
		else
			return(ft_print_error("Error: Invalid Identifier"));
		i++;
	}
	if (headers != 6)
		return (ft_print_error("Error: Textures missing"));
	return (0);
}

