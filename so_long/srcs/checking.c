/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:41:28 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 16:23:47 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkformat(char *name, char *format)
{
	size_t	i;
	size_t	size;
	int		j;

	size = ft_strlen(name);
	i = size - 1;
	j = 0;
	while (name[i] != format[0] && i > 0)
		i--;
	if (i == 0)
		return (0);
	while (name[i + j] == format[j] && name[i + j] != '\0')
		j ++;
	if (name[i + j] == '\0')
	{
		if (size - ft_strlen(format) == i)
			return (1);
	}
	ft_printf("Error\nThe chosen map isn't in the .ber format\n");
	return (0);
}

int	checkelem(char c, char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			count += 1;
		s++;
	}
	return (count);
}

int	countelem(t_map *data)
{
	int	j;
	int	e;
	int	p;
	int	c;

	j = 0;
	e = 0;
	p = 0;
	c = 0;
	while (data->map[j] != NULL)
	{
		e += checkelem('E', data->map[j]);
		p += checkelem('P', data->map[j]);
		c += checkelem('C', data->map[j]);
		j++;
	}
	if (e != 1 || p != 1 || c < 1)
	{
		free(data->buffer);
		ft_clear((void **)data->map);
		return (-1);
	}
	data->items = c + e;
	return (1);
}

int	testmap(unsigned int x, unsigned int y, t_map *data)
{
	if (data->map[y][x] == 'C' || data->map[y][x] == 'E')
		data->count += 1;
	if (data->count == data->items)
		return (1);
	if (data->map[y][x] == '1' || data->map[y][x] == 'X')
		return (0);
	if (y > data->nb || x > data->size)
		return (0);
	data->map[y][x] = '1';
	if (testmap(x + 1, y, data) == 1)
		return (1);
	if (testmap(x - 1, y, data) == 1)
		return (1);
	if (testmap(x, y + 1, data) == 1)
		return (1);
	if (testmap(x, y - 1, data) == 1)
		return (1);
	return (0);
}

int	checking(t_map *data)
{
	data->count = 0;
	gps(data, &data->x, &data->y, 'P');
	if (testmap(data->x, data->y, data) == 0)
	{
		ft_clear((void **)data->map);
		free(data->buffer);
		ft_printf("Error\nCollectible or exit not reachable\n");
		return (0);
	}
	return (1);
}
