/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:31:18 by cgil              #+#    #+#             */
/*   Updated: 2025/10/21 18:29:22 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_map(char **lines, t_congif *cfg, int map_start)
{
	if (validate_map_chars(lines + map_start) == -1)
		return (ft_print_error("Error\ninvalid chars found in map"));
	if (validate_single_player(lines + map_start) == -1)
		return (-1);
	if (count_map_size(lines + map_start, cfg) == -1)
		return (-1);
	if (allocate_map(cfg) == -1)
		return (-1);
	if (fill_map(lines + map_start, cfg) == -1)
		return (-1);
	if (check_map(cfg) == -1)
		return (-1);
	return (0);
}
