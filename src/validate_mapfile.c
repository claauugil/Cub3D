/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mapfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:17:54 by claudia           #+#    #+#             */
/*   Updated: 2025/10/10 15:43:58 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// revisa que termine en .cub

int	validate_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (-1);
	 if (ft_strncmp(filename + len - 4, ".cub", 4) == 0
        || ft_strncmp(filename + len - 4, ".xpm", 4) == 0)
        return (0);
	return (-1);
}

int check_open(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error: couldn't open file\n");
        return (-1);
    }
    close(fd);
    return (0);  
}

int validate_map(char *map)
{
	if (validate_file(map) == -1)
		return (-1);
	if (check_open(map) == -1)
	{
		printf("error: could not open file\n");
		return (-1);
	}
	return (0);
}
