/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:16:57 by claudia           #+#    #+#             */
/*   Updated: 2025/10/15 13:19:44 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_config cfg;
	t_game game;

	ft_bzero(&cfg, sizeof(t_config));
	ft_bzero(&game, sizeof(t_game));

	if (ac != 2)
		return (ft_print_error("error: use as: ./cub3d <mapa.cub>"));
	if (validate_map(av[1]) == -1)
		return (ft_print_error("error: invalid map"));
	if (parse_cub(av[1], &cfg) == -1)
		return (ft_print_error("error: invalid map file"));

	if (init_game(&game, &cfg) == -1)
		return (-1);

	render_frame(&game); // 👈 aquí llamas a tu función del render.c

	mlx_loop(game.mlx); // mantiene la ventana abierta
	free_cfg(&cfg);
	return (0);
}
