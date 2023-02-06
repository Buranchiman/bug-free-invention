/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:43:29 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/03 17:52:18 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map get_data(char *name)
{
    char *ret;
    int i;
    t_map data;

    i = 0;
    data.fd = open(name, O_RDONLY);
    ret = get_next_line(data.fd);
    data.sizelines = ft_strlen(ret);
    free(ret);
    while (ret != NULL)
    {
        i++;
        ret = get_next_line(data.fd);
        free(ret);
    }
    data.NBlines = i;
    //printf ("fd is = %d\n", data.fd);
    //printf ("nbLines is = %d\n", data.NBlines);
    //printf ("sizeLine is = %d\n", data.sizelines);
    return (data);
}

char    **get_map(t_map data)
{
    char *buffer;
    char **map;
    unsigned int total;

    //printf ("In map function :\nfd is = %d\n", data.fd);
    //printf ("nbLines is = %d\n", data.NBlines);
    //printf ("sizeLine is = %d\n", data.sizelines);
    total = data.sizelines * data.NBlines;
    //printf("total is %d\n ", total);
    buffer = calloc(total + 1, sizeof(char));
    data.fd = open("map.ber", O_RDONLY);
    read(data.fd, buffer, total);
    //printf("map is = %s", buffer);
    map = ft_split(buffer, '\n');
    free(buffer);
    return (map);
}
