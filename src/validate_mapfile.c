/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mapfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:17:54 by claudia           #+#    #+#             */
/*   Updated: 2025/09/30 15:03:56 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_file(char *filename)
{
	int	len;
	
	len = ft_strlen(filename);
	
	if (len < 4)
		return (-1);
	if (ft_strncmp(filename + len - 4, ".cub", 4) == 0) // filename apunta a .
		return (0);
	return (-1);
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
