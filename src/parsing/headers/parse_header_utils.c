/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:09:38 by claudia           #+#    #+#             */
/*   Updated: 2025/10/15 13:26:42 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int save_color(char id, t_config *cfg, int rgb[3])
{
	int	i;
	
	i = 0;
	if (id == 'F')
	{	while (i < 3)
		{
			cfg->floor_rgb[i] = rgb[i];
			i++;
		}
	}
	else if (id == 'C')
	{
		while (i < 3)
		{
			cfg->ceiling_rgb[i] = rgb[i];
			i++;
		}
	}
	else
		return(ft_print_error("Error: Invalid color identifier"));
	return (0);
}

static int	validate_rgb_range(int rgb[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ft_print_error("Error: RGB out of range"));
		i++;
	}
	return (0);
}

static int	parse_color_line(char *line, int rgb[3])
{
	char	**split;
	int		i;

	i = 0;
	line++;
	while (*line == ' ')
		line++;
	split = ft_split(line, ',');
	if (!split)
		return(ft_print_error("Error: malloc failed"));
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
	{
		free_split(split);
		return (ft_print_error("Error: Invalid RGB format"));
	}
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
	return (0);
}

int check_color(char *line, t_config *cfg)
{
	char	id;
	int		rgb[3];

	id = *line;
	if (parse_color_line(line, rgb) == -1)
		return (-1);
	if (validate_rgb_range(rgb) == -1)
		return (-1);
	if (save_color(id, cfg, rgb) == -1)
		return (-1);
	return (0);
}