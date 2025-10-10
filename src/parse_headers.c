/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_headers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:30:27 by claudia           #+#    #+#             */
/*   Updated: 2025/10/09 14:44:17 by claudia          ###   ########.fr       */
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
	return (!ft_strncmp(line, "NO", 3) || !ft_strncmp(line, "SO", 3)
		|| !ft_strncmp(line, "WE", 3) || !ft_strncmp(line, "EA", 3));
}

/*static int is_color_line(char *line)
{
	return (!ft_strncmp(line, "F", 2) || !ft_strncmp(line, "C", 2));
}*/

int	handle_headers(char **lines, t_congif *cfg, int *map_start)
{
    int	i;
	int	headers;
	
	i = 0;
	headers = 0;
	while(lines[i])
	{
		printf("Line %d: '%s'\n", i, lines[i]);
		if (is_map_line(lines[i]))
		{
			*map_start = i;
			break;
		}
		if (is_texture_line(lines[i]))
		{
			if (check_texture(lines[i], cfg) == -1)
				return (-1);
			headers++;
		}
		/*else if (is_color_line(lines[i]))
		{
			if (check_color(lines[i], cfg) == -1)
				return (-1);
			headers++;
		}*/
		else if (lines[i][0] != '\0')
			return (-1);
		i++;
	}
	/*if (headers != 6)
		return (-1);*/
	return (0);
}

