/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:54:27 by cgil              #+#    #+#             */
/*   Updated: 2025/10/15 13:26:52 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int save_textures(t_config *cfg, char *coord, char *path)
{
    if (ft_strncmp(coord, "NO", 3) == 0)
    {
        if (cfg->tex_no)
            return (-1);
        cfg -> tex_no = ft_strdup(path);
    }
    else if (ft_strncmp(coord, "SO", 3) == 0)
    {
        if (cfg->tex_so)
            return (-1);
        cfg -> tex_so = ft_strdup(path);
    }
    else if (ft_strncmp(coord, "WE", 3) == 0)
    {
        if (cfg->tex_we)
            return (-1);
        cfg -> tex_we = ft_strdup(path);
    }
    else if (ft_strncmp(coord, "EA", 3) == 0)
    {
        if (cfg->tex_ea)
            return (-1);
        cfg -> tex_ea = ft_strdup(path);
    }
    else
        return (-1);
    return (0);
}

int check_texture(char *line, t_config *cfg)
{

	char	**split;
	int		fd;
	int		ret;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1] || split[2])
		return(free_split(split), -1);
    if (validate_file(split[1]) == -1)
    {
        free_split(split);
        return(ft_print_error("Error: invalid texture file extension"));
    }
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
	{
		free_split(split);
		return(ft_print_error("Error: invalid texture"));
	}
	close(fd);
	ret = save_textures(cfg, split[0], split[1]);
	free_split(split);
	return ((ret));
}
