/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 09:59:05 by claudia           #+#    #+#             */
/*   Updated: 2025/10/07 12:33:37 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_open(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error: couldn't open file\n");
        return (-1);
    }
    close(fd);
    return (0);  
}

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