/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:16:57 by claudia           #+#    #+#             */
/*   Updated: 2025/10/21 13:28:09 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_congif cfg;
    
    ft_bzero(&cfg, sizeof(t_congif));
    if (ac != 2)
        return (ft_print_error("Error\nUse as: ./cub3d <mapa.cub>"));
    if (validate_map(av[1]) == -1)
        return (ft_print_error("Error\nFile must have .cub extension"));
    if (parse_cub(av[1], &cfg) == -1)
    {   
        free_cfg(&cfg);
        return (-1);
    }
    free_cfg(&cfg);
    return (0);
}
