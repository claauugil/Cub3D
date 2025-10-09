/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:59:05 by claudia           #+#    #+#             */
/*   Updated: 2025/10/09 11:24:15 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int free_and_error(char **lines, const char *msg)
{
    if(lines)
        free_split(lines);
    printf("%s\n", msg);
    return (-1);
}

int ft_print_error(char *error)
{
    printf("%s\n", error);
    return (1);
}

void free_split(char **array)
{
    int i;

    i = 0;
    if (!array)
        return;
    while(array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}