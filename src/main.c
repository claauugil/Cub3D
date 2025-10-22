/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:16:57 by claudia           #+#    #+#             */
/*   Updated: 2025/10/22 11:29:08 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
    t_game game;
    t_config cfg;
    
    ft_bzero(&cfg, sizeof(t_config));
    ft_bzero(&game, sizeof(t_game));
    if (ac != 2)
        return (ft_print_error("Error\nUse as: ./cub3d <map.cub>"));
    if (validate_map(av[1]) == -1)
        return (ft_print_error("Error\nFile must have .cub extension"));
    if (parse_cub(av[1], &cfg) == -1)
	{
		free_cfg(&cfg);
		return (-1);
	}
    if (init_game(&game, &cfg) == -1)
		return (-1);
	render_frame(&game);
	mlx_loop(game.mlx);
	free_cfg(&cfg);
	return (0);
}
