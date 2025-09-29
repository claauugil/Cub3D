/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:17:54 by claudia           #+#    #+#             */
/*   Updated: 2025/09/29 16:38:09 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int validate_file(char *filename)
{
    int len;

    len = ft_strlen(filename);
    
    if (len < 4)
        return (-1);
    if (ft_strncmp(filename + len - 4, ".cub", 4) == 0) // filename apunta a .
        return (0);
    return (-1);
}

int validate_map(char *map)
{
    int fd;

    fd = open(map, O_RDONLY);

    if (validate_file(map) == -1)
        return (-1);
    if (fd < 0)
    {
        printf("Error al abrir el archivo\n");
        return (-1);
    }
    close(fd);
    return (0);    
}