/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:41:28 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/06 15:40:04 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    char **map;
    int i;
    t_map data;

    i = 0;

    data = get_data("map.ber");
    map = get_map(data);
    while (map[i] != NULL)
    {
        i++;
        printf("row[%d] = %s\n", i, map[i]);
    }
}

