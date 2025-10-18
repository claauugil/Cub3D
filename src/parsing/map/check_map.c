/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:47:09 by claudia           #+#    #+#             */
/*   Updated: 2025/10/18 18:20:38 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_surrounded(char **map, int i, int j)
{
	if (i == 0 || j == 0 || !map[i + 1] || !map[i -1])
		return (0);
	if (j >= (int)ft_strlen(map[i -1]) || j >= (int)ft_strlen(map[i +1]))
		return (0);
}
int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]))
			{
				if (!is_surrounded(map, i, j))
					return (print_err("map not closed"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}