/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:16:57 by claudia           #+#    #+#             */
/*   Updated: 2025/09/29 13:31:13 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("error: use: ./cub3d <mapa.cub>\n");
        return (1);
    }
    if (validate_map(av[1]) == -1)
    {
        printf("error: invalid map\n");
        return (1);
    }
    
}