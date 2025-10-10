/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:16:57 by claudia           #+#    #+#             */
/*   Updated: 2025/10/09 13:44:55 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_congif cfg;
    
    if (ac != 2)
        return (ft_print_error("error: use as: ./cub3d <mapa.cub>\n"));
    ft_bzero(&cfg, sizeof(t_congif));
    if (validate_map(av[1]) == -1)
        return (ft_print_error("error: invalid map\n"));
    if (parse_cub(av[1], &cfg) == -1)
        return (ft_print_error("error: parsing failed :(((("));
    return (0);
}